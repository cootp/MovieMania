#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movies.h"
// Map template for making map algorithm look similar to STL
template <class KEY, class VALUE>
class Map {
private:
	KEY key;
	VALUE value;
	Map* right;
	Map* left;
	Map* root;
	vector<VALUE> moviesList;
	void insert(Map** rooted, KEY key, VALUE val);
	void getInorderGenre(Map* rooted, string genre);
	void getInorder(Map* rooted);
	void printInOrder(Map* rooted);
	// Used for comparing for vector sort function
	static bool sortByYear(VALUE a, VALUE b);
	static bool sortByGenre(VALUE a, VALUE b);
	static bool sortByDuration(VALUE a, VALUE b);
public:
	// Default Constructor
	Map();
	Map(KEY key, VALUE val);
	// Method for inserting value into BST
	void insert(KEY key, VALUE val);
	// Method for sorting depending on the genre type
	void sortGenre(string genre);
	// Uses inorder traversal for printing
	void printInOrder();
	void getInorderGenre(string genre);
	// Gets VALUE variable and prints the data
	void printInfo(VALUE value);
	void printList();
	void clearList();

};

template <class KEY, class VALUE>
Map<KEY, VALUE>::Map() {
	root = nullptr;
}
template<class KEY, class VALUE>
Map<KEY, VALUE>::Map(KEY key, VALUE val) {
	this->key = key;
	this->value = val;
	this->left = nullptr;
	this->right = nullptr;
}
template <class KEY, class VALUE>
void Map<KEY, VALUE>::insert(KEY key, VALUE val) {
	insert(&(root), key, val);
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::sortGenre(string genre) {
	getInorder(this->root);
	if (genre == "Year") {

		cout << "We are now sorting the Map by year." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByYear);
	}

	else if (genre == "Genre") {

		cout << "We are now sorting the Map by genre." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByGenre);
	}

	else if (genre == "Duration") {

		cout << "We are now sorting the Map by duration." << endl;
		sort(moviesList.begin(), moviesList.end(), sortByDuration);
	}

	printList();
}

template <class KEY, class VALUE>
void Map<KEY, VALUE>::insert(Map** rooted, KEY key, VALUE val) {
	if (*rooted == nullptr) {
		Map* temp = new Map(key, val);
		*rooted = temp;
	}
	else {
		if (key > (*rooted)->key) {
			insert(&(*rooted)->right, key, val);
		}
		else {
			insert(&(*rooted)->left, key, val);
		}
	}

}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::getInorderGenre(Map* rooted, string genre) {
	if (rooted != nullptr) {
		getInorderGenre(rooted->left, genre);
		if (rooted->value.getGenre() == genre) {
			printInfo(rooted->value);
		}
		getInorderGenre(rooted->right, genre);
	}
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::getInorder(Map* rooted) {
	if (rooted != nullptr) {
		getInorder(rooted->left);
		moviesList.push_back(rooted->value);
		getInorder(rooted->right);
	}
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::getInorderGenre(string genre) {
	getInorderGenre(root, genre);
}

template<class KEY, class VALUE>
inline bool Map<KEY, VALUE>::sortByYear(VALUE a, VALUE b) {
	return (a.getYear() < b.getYear());
}

template<class KEY, class VALUE>
inline bool Map<KEY, VALUE>::sortByGenre(VALUE a, VALUE b) {
	return (a.getGenre() < b.getGenre());
}

template<class KEY, class VALUE>
inline bool Map<KEY, VALUE>::sortByDuration(VALUE a, VALUE b) {
	return (a.getDuration() < b.getDuration());
}

template <class KEY, class VALUE>
void Map<KEY, VALUE>::printInOrder() {
	printInOrder(this->root);
	std::cout << std::endl;
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::printInfo(VALUE value) {
	cout << "x==============================================x" << endl;
	cout << "| Title: " << value.getTitle() << endl;
	cout << "| Year: " << value.getYear() << endl;
	cout << "| Genre: " << value.getGenre() << endl;
	cout << "| Duration: " << value.getDuration() << " minutes" << endl;
	cout << "x==============================================x" << endl;
	cout << endl;
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::printList() {
	for (int i = 0; i < moviesList.size(); i++) {
		printInfo(moviesList[i]);
	}
}

template<class KEY, class VALUE>
inline void Map<KEY, VALUE>::clearList() {
	moviesList.clear();
}

template <class KEY, class VALUE>
void Map<KEY, VALUE>::printInOrder(Map* rooted) {
	if (rooted != nullptr) {
		printInOrder(rooted->left);
		cout << "x==============================================x" << endl;
		cout << "| Title: " << rooted->value.getTitle() << endl;
		cout << "| Year: " << rooted->value.getYear() << endl;
		cout << "| Genre: " << rooted->value.getGenre() << endl;
		cout << "| Duration: " << rooted->value.getDuration() << " minutes" << endl;
		cout << "x==============================================x" << endl;
		cout << endl;
		printInOrder(rooted->right);
	}
}