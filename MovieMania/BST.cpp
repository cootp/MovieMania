#include <iostream>
#include <algorithm> 
#include "BST.h"
BST::BST(Movies x) {
	val = x;
	left = NULL;
	right = NULL;
}
BST* BST::insert(BST* root, Movies obj) {
	if (root == NULL) {
		return new BST(obj);
	}
	if (obj.getTitle() < root->val.getTitle()) {
		root->left = insert(root->left, obj);
	}
	else {
		root->right = insert(root->right, obj);
	}
	return root;
}

void BST::inorderALL(BST* root) {
	if (root == NULL) {
		cout << "";
	}
	else {
		inorderALL(root->left);
		cout << root->val.getTitle() << endl;
		inorderALL(root->right);
	}
}

void BST::traversBST(BST* root) {
	if (root == NULL) {
		cout << "";
	}
	else {
		traversBST(root->left);
		tempSort.push_back(root->val);
		traversBST(root->right);
	}
}

void BST::sortByString(BST* root, string newString){
	if (newString == "YEAR") {
		traversBST(root);
		cout << "We are now sorting the BST by year." << endl;
		sort(tempSort.begin(), tempSort.end(), CompareYear);
	}else if (newString == "GENRE") {

	}
	else if (newString == "DURATION") {

	}
	for (auto it : tempSort) {
		cout << it.getYear() << endl;
	}
}
bool BST::CompareYear(Movies left, Movies right)
{
	return left.getYear() < right.getYear();
}


