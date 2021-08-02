#pragma once
#include <vector>
#include "Movies.h"
class BST {
private:
	vector<Movies> tempSort;
	Movies val;
	BST* left;
	BST* right;
public:
	BST(Movies x);
	// Inserts the Movie obj into the BST with the string as its key
	BST* insert(BST* root, Movies obj);
	// Prints using inorder traversal
	void inorderALL(BST* root);
	// Retrieves string type for genre sort
	void inorderGenre(BST* root, string searchType);
	// Puts information from inorder traversal inside tempSort vector
	void traversBST(BST* root);
	// Determines the type of sort needed for year, genre, and duration.
	void sortByString(BST* root, string newString);
	static bool CompareYear(Movies left, Movies right);
	static bool CompareGenre(Movies left, Movies right);
	static bool CompareDuration(Movies left, Movies right);
};