#include <iostream>
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
