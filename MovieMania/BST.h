#pragma once
#include "Movies.h"
class BST {
public:
	int val;
	BST* left;
	BST* right;

	BST(int x);
	BST* insert(BST* root, Movies obj);
};