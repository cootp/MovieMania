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
		cout << "Title: " << root->val.getTitle() << endl;
		cout << "Year: " << root->val.getYear() << endl;
		cout << "Genre: " << root->val.getGenre() << endl;
		cout << "Duration: " << root->val.getDuration() << endl;
		cout << endl;
		inorderALL(root->right);
	}
}

void BST::inorderGenre(BST* root, string searchType) {
	if (root == NULL) {
		cout << "";
	}
	else {
		inorderGenre(root->left, searchType);
		if (root->val.getGenre() == searchType) {
			cout << "Title: " << root->val.getTitle() << endl;
			cout << "Year: " << root->val.getYear() << endl;
			cout << "Genre: " << root->val.getGenre() << endl;
			cout << "Duration: " << root->val.getDuration() << endl;
			cout << endl;
		}
		inorderGenre(root->right, searchType);
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
	traversBST(root);
	if (newString == "Year") {
		cout << "We are now sorting the BST by year." << endl;
		sort(tempSort.begin(), tempSort.end(), CompareYear);
	}else if (newString == "Genre") {
		cout << "We are now sorting the BST by genre." << endl;
		sort(tempSort.begin(), tempSort.end(), CompareGenre);
	}
	else if (newString == "Duration") {
		cout << "We are now sorting the BST by duration." << endl;
		sort(tempSort.begin(), tempSort.end(), CompareDuration);
	}
	for (auto it : tempSort) {
		cout << "Title: " << it.getTitle() << endl;
		cout << "Year: " << it.getYear() << endl;
		cout << "Genre: " << it.getGenre() << endl;
		cout << "Duration: " << it.getDuration() << endl;
		cout << endl;
	}
}
bool BST::CompareYear(Movies left, Movies right)
{
	return left.getYear() < right.getYear();
}

bool BST::CompareGenre(Movies left, Movies right)
{
	return left.getGenre() < right.getGenre();
}

bool BST::CompareDuration(Movies left, Movies right)
{
	return left.getDuration() < right.getDuration();
}


