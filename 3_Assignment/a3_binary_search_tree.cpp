#include <iostream>
#include "a3_binary_search_tree.hpp"

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

// unsigned int BinarySearchTree::depth() const{

// }

// void BinarySearchTree::print() const{

// }

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

bool BinarySearchTree::remove(DataType val){
	Node * leftChild = root_; // Instantiate left child holder for largest preorder predecessor
	Node * currNode = root_;
	int childNum = 0;

	while ((currNode -> right != NULL) && (currNode -> left != NULL)){
		
		if (currNode -> right -> val == val){ 
			// Check if current node is a leaf node
			if ((currNode -> right -> right == NULL) && (currNode -> right -> left == NULL)){
				currNode -> right = NULL;
 				return true;

			// Check if current node has one child
			} else if (((currNode -> right -> right != NULL) && (currNode -> right -> left == NULL)) || ((currNode -> right -> right == NULL) && (currNode -> right -> left != NULL))){
				// Node to link to from currNode is on the right
				if ((currNode -> right -> right != NULL) && (currNode -> right -> left == NULL)){
					currNode -> right = currNode -> right -> right;
					return true;
				}
				// Node to link to from currNode is on the left
				if ((currNode -> right -> right == NULL) && (currNode -> right -> left != NULL)){
					currNode -> right = currNode -> right -> left;
					return true;
				}

			//Check if current node has two children
			} else if ((currNode -> right -> right != NULL) && (currNode -> right -> left != NULL)){
				// Delete largest pre-order predecessor
				return true;
			}
		}

		if (currNode -> left -> val == val) {
			// Check if current node is a leaf node
			if ((currNode -> left -> right == NULL) && (currNode -> left -> left == NULL)){
				currNode -> left = NULL;
				return true;

			// Check if current node has one child
			} else if (((currNode -> left -> right != NULL) && (currNode -> left -> left == NULL)) || ((currNode -> left -> right == NULL) && (currNode -> left -> left != NULL))){
				// Node to link to from currNode is on the right
				if ((currNode -> left -> right != NULL) && (currNode -> left -> left == NULL)){
					currNode -> left = currNode -> left -> right;
					return true;
				}
				// Node to link to from currNode is on the left
				if ((currNode -> left -> right == NULL) && (currNode -> left -> left != NULL)){
					currNode -> left = currNode -> left -> left;
					return true;
				}

			//Check if current node has two children
			} else if ((currNode -> left -> right != NULL) && (currNode -> left -> left != NULL)){
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

