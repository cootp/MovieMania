#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include "BST.h"
#include "Movies.h"
using namespace std;
void mainMenu();
void BSTLooper(string searchType);
int main()
{
	cout << "Hello Stranger! Welcome to Movie Mania." << endl;
	cout << "Movie Mania contains over 80,000 movies for you to search from." << endl;
	cout << endl;
	system("pause");
	system("cls");
	mainMenu();
}
// Main menu function to display type of search options
void mainMenu() {
	bool checkMaps = false;
	bool checkBST = false;
	bool checkALL = false;
	bool checkYear = false;
	bool checkGenre = false;
	bool checkDuration = false;
	int firstOption;
	int secondOption;
	string searchType;
	cout << "-----Choose Your Algorithm or Data Structure-----" << endl;
	cout << "	1. Maps		2. BST" << endl;
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
		mainMenu();
	}
	cout << "----------Choose Your Search Type----------" << endl;
	cout << "	1. All		2. Year" << endl;
	cout << "	3. Genre	4. Duration" << endl;
	cin >> secondOption;
	// Checks to see what option the user chose for the second set of options
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
	default:
		cout << "This is not a valid option. Let's try again from the beginning." << endl;
		cout << endl;
		mainMenu();
		break;
	}
	system("cls");
	if (checkMaps == true && checkALL == true) {
		searchType = "All";
		
	}else if (checkMaps == true && checkYear == true) {

	}
	else if (checkMaps == true && checkGenre == true) {

	}else if (checkMaps == true && checkDuration == true) {

	}
	else if (checkBST == true && checkALL == true) {
		searchType = "ALL";
		BSTLooper(searchType);
	}
	else if (checkBST == true && checkYear == true) {

	}
	else if (checkBST == true && checkGenre == true) {

	}
	else if (checkBST == true && checkDuration == true) {

	}
}

void BSTLooper(string searchType){
	ifstream movieInfo("IMDb_movies.csv");
	int i = 0;
	string title, year, genre, duration;
	while (!movieInfo.eof()) {
		// Used to skip the first row of the csv file
		if (i == 0) {
			string temp;
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp, ',');
			getline(movieInfo, temp);
			i++;
		}
		getline(movieInfo, title, ',');
		getline(movieInfo, year, ',');
		getline(movieInfo, genre, ',');
		getline(movieInfo, duration);
		getline(movieInfo, title, ',');
		cout << title << endl;
		cout << year << endl;
		cout << genre << endl;
		cout << duration << endl;
		cout << endl;
		
	}
}
