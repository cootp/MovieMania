#pragma once
#include "Movies.h"
class BST {
public:
	Movies val;
	BST* left;
	BST* right;

	BST(Movies x);
	BST* insert(BST* root, Movies obj);
	void inorderALL(BST* root);
};