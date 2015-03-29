#include <iostream>
#include "a3_binary_search_tree.hpp"

using namespace std;

BinarySearchTree::Node::Node(DataType newval){
	val = newval;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree(){
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree(){

}

unsigned int BinarySearchTree::size() const{
	return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const{
	Node * currNode = root_;
	while (currNode -> right != NULL){ // Update pointed to go right until null is reached
		currNode = currNode -> right;
	}

	return currNode -> val;
}

BinarySearchTree::DataType BinarySearchTree::min() const{
	Node * currNode = root_;
	while (currNode -> left != NULL){ // Update pointed to go left until null is reached
		currNode = currNode -> left;
	}

	return currNode -> val;
}

// Helper function to find max of two DataTypes
BinarySearchTree::DataType max(BinarySearchTree::DataType a, BinarySearchTree::DataType b){
	if (a > b){ // return max of a,b
		return a;
	}
	return b;
}

BinarySearchTree::DataType maxDepth(BinarySearchTree::Node * t_){
	if (t_ == NULL){
		return 0;
	}
	return 1 + max(maxDepth(t_ -> left), maxDepth(t_ -> right));
}

unsigned int BinarySearchTree::depth() const{
	return maxDepth(root_);
}

//Helper function to recursivly print a tree
void inOrderPrint(BinarySearchTree::Node * t_){
	if (t_ == NULL){
		return;
	}
	inOrderPrint(t_ -> left);
	cout << t_ -> val << " ";
	inOrderPrint(t_ -> right);
}

void BinarySearchTree::print() const{
	inOrderPrint(root_);
}

bool BinarySearchTree::exists(DataType val) const{
	Node * currNode = root_;

	do {

		if (val == currNode -> val){
			return true;
		}

		if (val > currNode -> val){
			currNode = currNode -> right;
		} else {
			currNode = currNode -> left;
		}
	} while ((currNode -> right != NULL) && (currNode -> left != NULL));
	return false;
}

//Helper function to check for leaf node
bool leafNode(BinarySearchTree::Node * currNode){
	if ((currNode -> right == NULL) && (currNode -> left == NULL)){
		return true;
    } else {
        return false;
    }
}

//Helper function to check for node with single child
bool singleChild(BinarySearchTree::Node * currNode){
	if (((currNode -> right != NULL) && (currNode -> left == NULL)) || ((currNode -> right == NULL) && (currNode -> left != NULL))){
		return true;
	} else {
		return false;	
	}
}

//Helper function to check for node with two children
bool doubleChild(BinarySearchTree::Node * currNode){
	if ((currNode -> left != NULL) && (currNode -> right != NULL)){
		return true;
	} else {
		return false;
	}
}

bool BinarySearchTree::insert(DataType val){
	Node * nodeToInsert = new Node(val);
	Node * currNode = root_;
    Node * parent;
    
	//Empty tree
	if (size_ == 0){
		root_ = nodeToInsert;
		size_++;
		return true;
	}

	//Find the appropriate leaf node
	while (currNode){
        parent = currNode;
		if (currNode -> val == val){
			return false;
		}

		if (val > currNode -> val){
			currNode = currNode -> right;
		} else {
			currNode = currNode -> left;
		}
	}

	//Insert the node
	if (val > parent -> val){
		parent -> right = nodeToInsert;
		size_++;
		return true;
	} else {
		parent -> left = nodeToInsert;
		size_++;
		return true;
	}

	return false;
}

bool BinarySearchTree::remove(DataType val){
	Node * currNode = root_;
	Node * parent;
	bool foundVal = false;

	while (currNode!=NULL){
		if (currNode -> val == val){ // Found the node of interest
			foundVal = true;
			break;
		} else {
			parent = currNode;
			currNode = val > currNode -> val ? currNode -> right : currNode -> left;
		}
	}

	//Value not found
	if (!foundVal){
		return false;
	}

	//Deleteing a leaf node
	if (currNode -> left == NULL && currNode -> right == NULL){
		if (parent -> left == currNode){
			parent -> left = NULL;
		} else {
			parent -> right = NULL;
		}
        return true;
		delete currNode;
	}

	//Deleteing a node with single child
	if (::singleChild(currNode)){
		//Deleting single child root
		if (currNode == root_){
			if (currNode -> left != NULL){
				root_ = currNode -> left;
				size_--;
				return true;
			} else {
				root_ = currNode -> right;
				size_--;
				return true;
			}
		}

		if ((currNode -> left == NULL) && (currNode -> right != NULL)) {
			if (parent -> left == currNode){
				parent -> left = currNode -> right;
				size_--;
				return true;
			} else {
				parent -> right = currNode -> right;
				size_--;
				return true;
			}
		} else {
			if (parent -> left == currNode){
				parent -> left = currNode -> left;
				size_--;
				return true;
			} else {
				parent -> right = currNode -> left;
				size_--;
				return true;
			}			
		}
	}

	//Deleting a node with two children
	if (::doubleChild(currNode))
	{
		//Replace currNode with smallest inorder sucessor
		Node * checker = currNode -> right;
		if (checker -> left == NULL && checker -> right == NULL){
            currNode -> val = checker -> val;
            currNode -> right = checker -> right;
            delete checker;
			size_--;
			return true;
		} else { // right node (checker) has at least one child
			if (checker -> left != NULL){
				Node * checkerp = checker;
				Node * checker = currNode -> right -> left;
				while (checker -> left != NULL){
					checkerp = checker;
					checker = checker -> left;
				}
				currNode -> val = checker -> val;
				delete checker;
				size_--;
				checkerp -> left = NULL;
				return true;
			} else {
				Node * rtemp = currNode -> right;
				currNode -> val = rtemp -> val;
				currNode -> right = rtemp -> right;
				delete rtemp;
				size_--;
				return true;
			}
		}
	}
    return false;
}

