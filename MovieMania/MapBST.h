#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Movies.h"

class MapBST {

private:

	Movies m;
	MapBST* left;
	MapBST* right;
	vector<Movies> moviesList;

public:

	//Constructors
	MapBST();
	MapBST(Movies _m);

	MapBST* insert(Movies movie, MapBST* root);

	//Traversals
	void getInorder(MapBST* root);
	void getInorderGenre(MapBST* root, string genre);

	//Sorters
	void sortGenre(MapBST* root, string genre);
	static bool sortByYear(Movies a, Movies b);
	static bool sortByGenre(Movies a, Movies b);
	static bool sortByDuration(Movies a, Movies b);

	//Printers
	void printInorder(MapBST* root); //Prints inorder traversal
	void printInfo(Movies _m);		 //Prints info of movie object
	void printList();				 //Prints moviesList

	void clearList();
};