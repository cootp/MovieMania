#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>
#include <string>
#include "BST.h"
#include "Movies.h"
#include "MapBST.h"
using namespace std;
void mainMenu(BST* root, MapBST* mapRoot);
void BSTLooper(string searchType, BST* root, string genreType);
void mapLooper(string searchType, MapBST* root, string genreType);
int main()
{
	// Code that inputs all information for the BST and maps in alphabetical order
	BST* root = NULL;
	MapBST* mapRoot = nullptr;
	ifstream movieInfo("IMDb_movies.csv");
	int i = 0;
	string title, year, genre, duration;
	cout << "Importing Data. Please Wait." << endl;
	while (!movieInfo.eof()) {
		// Used to skip the first row of the csv file that contains the column info
		if (i == 0) {
			string temp;
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp);
			i++;
		}
		// Retrieves the information for title, year, genre, duration and inserts into BST
		getline(movieInfo, title, ',');
		getline(movieInfo, year, ',');
		getline(movieInfo, genre, ',');
		getline(movieInfo, duration);
		// Creates Movie obj with gathered information
		Movies obj(title, year, genre, duration);
		// Inserts into BST
		root = root->insert(root, obj);
		//Insert into Maps
		mapRoot = mapRoot->insert(obj, mapRoot);
	}
	system("cls");
	cout << "Hello Stranger! Welcome to Movie Mania." << endl << endl;
	cout << "Movie Mania contains over 80,000 movies for you to search from." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "	   Let's find your movie" << endl << endl;
	mainMenu(root);
}
// Main menu function to display type of search options
void mainMenu(BST* root, MapBST* mapRoot) {
	bool checkMaps = false;
	bool checkBST = false;
	bool checkALL = false;
	bool checkYear = false;
	bool checkGenre = false;
	bool checkDuration = false;
	bool checkGenreSearch = false;
	int firstOption;
	int secondOption;
	string searchType;
	cout << "Choose an Algorithm or Data Structure:" << endl;
	cout << "1. Maps		2. BST" << endl;
	cin >> firstOption;
	cout << endl;
	// Checks to see what option the user chose for the first set of options
	if (firstOption == 1) {
		checkMaps = true;
	}
	else if (firstOption == 2) {
		checkBST = true;
	}
	else {
		cout << "This is not a valid option. Let's try again from the beginning." << endl;
		cout << endl;
		mainMenu(root);
	}
	cout << "Choose a Search Type:" << endl;
	cout << "1. All			2. Year" << endl;
	cout << "3. Genre		4. Duration" << endl;
	cout << "5. Search Genre" << endl;
	cin >> secondOption;
	// Checks to see what option the user chose for the second set of options
	string genreType = "";
	switch (secondOption) {
	case 1:
		checkALL = true;
		break;
	case 2:
		checkYear = true;
		break;
	case 3:
		checkGenre = true;
		break;
	case 4:
		checkDuration = true;
		break;
	case 5:
		checkGenreSearch = true;
		cout << endl;
		cout << "The dataset contains these Genres: Action, Adult, Adventure, Animation, Biography, Comedy, Crime, Documentary, Drama" << endl;
		cout << "Family, Fantasy, Film-Noir, History, Horror, Music, Musical, Mystery, Romance, Sci-Fi, Sport, Thriller, War, Western. " << endl;
		cout << endl << "Please enter a genre of your choice (Case-Sensitive): " << endl;
		cin >> genreType;
		break;
	default:
		cout << "This is not a valid option. Let's try again from the beginning." << endl;
		cout << endl;
		mainMenu(root, mapRoot);
		break;
	}
	system("cls");
	
	//Maps
	if (checkMaps == true && checkALL == true) {
		searchType = "All";
		mapLooper(searchType, mapRoot, genreType);
	}
	else if (checkMaps == true && checkYear == true) {
		searchType = "Year";
		mapLooper(searchType, mapRoot, genreType);
	}
	else if (checkMaps == true && checkGenre == true) {
		searchType = "Genre";
		mapLooper(searchType, mapRoot, genreType);
	}
	else if (checkMaps == true && checkDuration == true) {
		searchType = "Duration";
		mapLooper(searchType, mapRoot, genreType);
	}
	else if (checkMaps == true && checkGenreSearch == true) {
		searchType = "Genre Search";
		mapLooper(searchType, mapRoot, genreType);
	}
	
	//BSTs
	else if (checkBST == true && checkALL == true) {
		searchType = "All";
		BSTLooper(searchType, root, genreType);
	}
	else if (checkBST == true && checkYear == true) {
		searchType = "Year";
		BSTLooper(searchType, root, genreType);
	}
	else if (checkBST == true && checkGenre == true) {
		searchType = "Genre";
		BSTLooper(searchType, root, genreType);
	}
	else if (checkBST == true && checkDuration == true) {
		searchType = "Duration";
		BSTLooper(searchType, root, genreType);
	}
	else if (checkBST == true && checkGenreSearch == true) {
		searchType = "Genre Search";
		BSTLooper(searchType, root, genreType);
	}
}

void BSTLooper(string searchType, BST* root, string genreType){
	// Timer code function taken from https://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	if (searchType == "All") {
		root->inorderALL(root);
	}
	else if (searchType == "Year") {
		root->sortByString(root, searchType);
	}
	else if (searchType == "Genre") {
		root->sortByString(root, searchType);
	}
	else if (searchType == "Duration") {
		root->sortByString(root, searchType);
	}
	else if (searchType == "Genre Search") {
		root->inorderGenre(root, genreType);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "Searching and Displaying all of the information using a BST and sorting by " << searchType << " took " << time_span.count() << " seconds." << endl;
	system("pause");
	cout << endl;
	system("cls");
	mainMenu(root);
}

void mapLooper(string searchType, MapBST* root, string genreType) {
	// Timer code function taken from https://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	if (searchType == "All") {
		root->printInorder(root);
	}
	
	else if (searchType == "Year" || searchType == "Genre" || searchType == "Duration") {
		root->sortGenre(root, searchType);
	}
	
	else if (searchType == "Genre Search") {
		root->getInorderGenre(root, genreType);
	}
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "Searching and Displaying all of the information using a Map and sorting by " << searchType << " took " << time_span.count() << " seconds." << endl;
	
	system("pause");
	cout << endl;
	system("cls");
	mainMenu(root);	
}
