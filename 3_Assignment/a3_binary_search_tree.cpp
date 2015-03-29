#include <iostream>
#include "a3_binary_search_tree.hpp"

using namespace std;

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
	while (currNode -> right != NULL){
		currNode = currNode -> right;
	}

	return currNode -> val;
}

BinarySearchTree::DataType BinarySearchTree::min() const{
	Node * currNode = root_;
	while (currNode -> left != NULL){
		currNode = currNode -> left;
	}

	return currNode -> val;
}

BinarySearchTree::DataType max(BinarySearchTree::DataType a, BinarySearchTree::DataType b){
	if (a > b){
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


void printTree(BinarySearchTree::Node * t_){
	if (t_ == NULL){
		return;
	}
	printTree(t_);
	cout << t_ -> val << " ";
	printTree(t_);
}

void BinarySearchTree::print() const{
	printTree(root_);
}

bool BinarySearchTree::exists(DataType val) const{
	Node * currNode = root_;
	while ((currNode -> right != NULL) && (currNode -> left != NULL)){
		if (val == currNode -> val){
			return true;
		}

		if (val > currNode -> val){
			currNode = currNode -> right;
		} else {
			currNode = currNode -> left;
		}
	}
	return false;
}

bool BinarySearchTree::insert(DataType val){
	Node * nodeToInsert = new Node(val);
	Node * currNode = root_;

	//Find the appropriate leaf node
	while ((currNode -> right != NULL) && (currNode -> left != NULL)){
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
	if (val > currNode -> val){
		currNode -> right = nodeToInsert;
		size_++;
		return true;
	} else {
		currNode -> left = nodeToInsert;
		size_++;
		return true;
	}

	return false;
}

BinarySearchTree::Node * inOrderPredecessor(BinarySearchTree::Node * nodeToDelete){

	BinarySearchTree::Node * prev = nodeToDelete; // Instantiate the previous value
	BinarySearchTree::Node * inOrderPredecessor = nodeToDelete -> left; // Instantiate the return value


	while (inOrderPredecessor -> right != NULL){
		inOrderPredecessor = inOrderPredecessor -> right;
		prev = inOrderPredecessor;
	}

	// Check if the inorder predecessor has no children
	if (prev == nodeToDelete) {
		prev -> left = prev -> left -> left;
		return inOrderPredecessor;
	}

	// inOrderPredecessor has at least one child
	prev -> right = NULL; //remove the inOrderPredecessor from the tree
	return inOrderPredecessor;
}

bool BinarySearchTree::remove(DataType val){
	Node * inOrderPredecessor = root_; // Instantiate left child holder for largest preorder predecessor
	Node * nodeToDelete = root_;
	Node * currNode = root_;
	int childNum = 0;

	while ((currNode -> right != NULL) && (currNode -> left != NULL)){
		
		if (currNode -> right -> val == val){ 
			nodeToDelete = currNode -> right;
			// Check if current node is a leaf node
			if ((nodeToDelete -> right == NULL) && (nodeToDelete -> left == NULL)){
				currNode -> right = NULL;
 				return true;

			// Check if current node has one child
			} else if (((nodeToDelete -> right != NULL) && (nodeToDelete -> left == NULL)) || ((nodeToDelete -> right == NULL) && (nodeToDelete -> left != NULL))){
				// Node to link to from currNode is on the right
				if ((nodeToDelete -> right != NULL) && (nodeToDelete -> left == NULL)){
					currNode -> right = nodeToDelete -> right;
					return true;
				}
				// Node to link to from currNode is on the left
				if ((nodeToDelete -> right == NULL) && (nodeToDelete -> left != NULL)){
					currNode -> right = nodeToDelete -> left;
					return true;
				}

			//Check if current node has two children
			} else if ((nodeToDelete -> right != NULL) && (nodeToDelete -> left != NULL)){
				inOrderPredecessor = ::inOrderPredecessor(nodeToDelete);
				inOrderPredecessor -> right = nodeToDelete -> right;
				inOrderPredecessor -> left = nodeToDelete -> left;
				currNode -> right = inOrderPredecessor;
				// Delete largest pre-order predecessor
				return true;
			}
		}

		if (currNode -> left -> val == val) {
			nodeToDelete = currNode -> left;
			// Check if current node is a leaf node
			if ((nodeToDelete -> right == NULL) && (nodeToDelete -> left == NULL)){
				currNode -> left = NULL;
				return true;

			// Check if current node has one child
			} else if (((nodeToDelete -> right != NULL) && (nodeToDelete -> left == NULL)) || ((nodeToDelete -> right == NULL) && (nodeToDelete -> left != NULL))){
				// Node to link to from currNode is on the right
				if ((nodeToDelete -> right != NULL) && (nodeToDelete -> left == NULL)){
					currNode -> left = nodeToDelete -> right;
					return true;
				}
				// Node to link to from currNode is on the left
				if ((nodeToDelete -> right == NULL) && (nodeToDelete -> left != NULL)){
					currNode -> left = nodeToDelete -> left;
					return true;
				}

			//Check if current node has two children
			} else if ((currNode -> left -> right != NULL) && (currNode -> left -> left != NULL)){
				inOrderPredecessor = ::inOrderPredecessor(nodeToDelete);
				inOrderPredecessor -> right = nodeToDelete -> right;
				inOrderPredecessor -> left = nodeToDelete -> left;
				currNode -> left = inOrderPredecessor;				
				// Delete largest pre-order predecessor
				return true;
			}

		}


		// update currNode
		if (val > currNode -> val){
			currNode = currNode -> right;
		} else {
			currNode = currNode -> left;
		}
	}

	return false; // value was not found

}

