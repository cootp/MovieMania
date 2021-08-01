#include "MapBST.h"

MapBST::MapBST() {

	m = nullptr;
	left = nullptr;
	right = nullptr;
}

MapBST::MapBST(Movies* _m) {

	m = _m;
	left = nullptr;
	right = nullptr;
}

MapBST* MapBST::insert(Movies* movie, MapBST* root) {		//Inserts movies based on their title

	if (root == nullptr) {
		return new MapBST(movie);
	}

	if (movie->getTitle() < root->m->getTitle()) {
		root->left = insert(movie, root->left);
	}

	else {
		root->right = insert(movie, root->right);
	}

	return root;
}

void MapBST::getInorder(MapBST* root) {		//Gets every movie in alphabetical order

	if (root == nullptr) {
		return;
	}

	else {

		getInorder(root->left);
		moviesList.push_back(root->m);
		getInorder(root->right);
	}
}

void MapBST::getInorderGenre(MapBST* root, string genre) {	//Gets every movie in alphabetical order
															//With the specific genre
	if (root == nullptr) {
		return;
	}

	else {

		getInorder(root->left);
		if (root->m->getGenre() == genre) {
			printInfo(root->m);
		}
		getInorder(root->right);
	}
}

void MapBST::sortGenre(MapBST* root, string genre) {

	getInorder(root);
	if (genre == "Year") {

		cout << "We are now sorting the BST by year." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByYear);
	}

	else if (genre == "Genre") {

		cout << "We are now sorting the BST by genre." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByGenre);
	}

	else if (genre == "Duration") {

		cout << "We are now sorting the BST by duration." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByDuration);
	}

	printList();
}

bool MapBST::sortByYear(Movies* a, Movies* b) {
	return (a->getYear() < b->getYear());
}

bool MapBST::sortByGenre(Movies* a, Movies* b) {
	return (a->getGenre() < b->getGenre());
}

bool MapBST::sortByDuration(Movies* a, Movies* b) {
	return (a->getDuration() < b->getDuration());
}

void MapBST::printInorder(MapBST* root) {

	if (root == nullptr) {
		return;
	}

	else {

		printInorder(root->left);
		printInfo(root->m);
		printInorder(root->right);
	}
}

void MapBST::printInfo(Movies* _m) {

	cout << "Title: " << _m->getTitle() << endl;
	cout << "Year: " << _m->getYear() << endl;
	cout << "Genre: " << _m->getGenre() << endl;
	cout << "Duration: " << _m->getDuration() << endl;
	cout << endl;
}

void MapBST::printList() {

	for (int i = 0; i < moviesList.size(); i++) {
		printInfo(moviesList[i]);
	}
}

void MapBST::clearList() {
	moviesList.clear();
}
