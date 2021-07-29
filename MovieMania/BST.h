#pragma once
#include <vector>
#include "Movies.h"
class BST {
public:
	vector<Movies> tempSort;
	Movies val;
	BST* left;
	BST* right;

	BST(Movies x);
	BST* insert(BST* root, Movies obj);
	void inorderALL(BST* root);
	void inorderGenre(BST* root, string searchType);
	void traversBST(BST* root);
	void sortByString(BST* root, string newString);
	static bool CompareYear(Movies left, Movies right);
	static bool CompareGenre(Movies left, Movies right);
	static bool CompareDuration(Movies left, Movies right);
};