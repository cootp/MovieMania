#include <iostream>
#include "BST.h"
BST::BST(int x) {
	val = x;
	left = NULL;
	right = NULL;
}
BST* insert(BST* root, Movies obj) {
	if (root == NULL) {
		return new BST(obj.getYear());
	}
	if (obj.getYear() < root->val) {
		root->left = insert(root->left, obj);
	}
	else {
		root->right = insert(root->right, obj);
	}
	return root;
}