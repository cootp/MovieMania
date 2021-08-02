#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "BST.h"
#include "Movies.h"
#include "Map.h"
using namespace std;
static BST* root = nullptr;
static Map<string, Movies> mapRoot;
static int insertVar = 0;
void asciCodeDisplay();
void insertFunction();
void mainMenu(BST* root, Map<string, Movies> mapRoot);
void BSTLooper(string searchType, BST* root, Map<string, Movies> mapRoot, string genreType);
void mapLooper(string searchType, BST* root, Map<string, Movies> mapRoot, string genreType);
int main()
{
	// Code that inputs all information for the BST and maps in alphabetical order
	asciCodeDisplay();
	//Inserting BST
	using namespace std::chrono;
	high_resolution_clock::time_point bstTimer = high_resolution_clock::now();
	insertFunction();
	high_resolution_clock::time_point bstTimer2 = high_resolution_clock::now();
	duration<double> bsttime = duration_cast<duration<double>>(bstTimer2 - bstTimer);

	//Inserting Map
	high_resolution_clock::time_point mapTimer = high_resolution_clock::now();
	insertFunction();
	high_resolution_clock::time_point mapTimer2 = high_resolution_clock::now();
	duration<double> maptime = duration_cast<duration<double>>(mapTimer2 - mapTimer);

	cout << "It took our Binary Search Tree " << bsttime.count() << " seconds to insert our dataset." << endl << endl;
	cout << "While it took our Map " << maptime.count() << " seconds to insert our dataset." << endl << endl;
	system("pause");
	system("cls");

	cout << "Hello Stranger! Welcome to Movie Mania." << endl << endl;
	cout << "Movie Mania contains over 80,000 movies for you to search from." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Let's find your movie" << endl << endl;
	mainMenu(root, mapRoot);
}
// Design for our loading screen
void asciCodeDisplay() {
	// Displaying ASCII code for loading screen
	cout << "Please wait while we import our dataset." << endl;
	cout << R"( ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ 
||M |||O |||V |||I |||E |||       |||M |||A |||N |||I |||A ||
||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|)";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("cls");
	cout << "Please wait while we import our dataset." << endl;
	cout << R"(.------..------..------..------..------.     .------..------..------..------..------.
|M.--. ||O.--. ||V.--. ||I.--. ||E.--. |.-.  |M.--. ||A.--. ||N.--. ||I.--. ||A.--. |
| (\/) || :/\: || :(): || (\/) || (\/) ((5)) | (\/) || (\/) || :(): || (\/) || (\/) |
| :\/: || :\/: || ()() || :\/: || :\/: |'-.-.| :\/: || :\/: || ()() || :\/: || :\/: |
| '--'M|| '--'O|| '--'V|| '--'I|| '--'E| ((1)) '--'M|| '--'A|| '--'N|| '--'I|| '--'A|
`------'`------'`------'`------'`------'  '-'`------'`------'`------'`------'`------')";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("cls");
	cout << "Please wait while we import our dataset." << endl;
	cout << R"(  __  __    U  ___ u__     __          U _____ u      __  __      _      _   _                   _      
U|' \/ '|u   \/"_ \/\ \   /"/u  ___    \| ___"|/    U|' \/ '|uU  /"\  u | \ |"|       ___    U  /"\  u  
\| |\/| |/   | | | | \ \ / //  |_"_|    |  _|"      \| |\/| |/ \/ _ \/ <|  \| |>     |_"_|    \/ _ \/   
 | |  | |.-,_| |_| | /\ V /_,-. | |     | |___       | |  | |  / ___ \ U| |\  |u      | |     / ___ \   
 |_|  |_| \_)-\___/ U  \_/-(_/U/| |\u   |_____|      |_|  |_| /_/   \_\ |_| \_|     U/| |\u  /_/   \_\  
<<,-,,-.       \\     //   .-,_|___|_,-.<<   >>     <<,-,,-.   \\    >> ||   \\,-.-,_|___|_,-.\\    >>  
 (./  \.)     (__)   (__)   \_)-' '-(_/(__) (__)     (./  \.) (__)  (__)(_")  (_/ \_)-' '-(_/(__)  (__) )";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("cls");
	cout << "Please wait while we import our dataset." << endl;
	cout << R"(__________________________________________________________________
    _   _                             _   _                       
    /  /|               ,             /  /|                ,      
---/| /-|----__-------------__-------/| /-|----__----__--------__-
  / |/  |  /   ) | /  /   /___)     / |/  |  /   ) /   ) /   /   )
_/__/___|_(___/__|/__/___(___ _____/__/___|_(___(_/___/_/___(___(_)";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("cls");
}
// Inserts depending if it is BST and Map
void insertFunction() {
	ifstream movieInfo("IMDb_movies.csv");
	int i = 0;
	string title, year, genre, duration;
	int mainDuration;

	asciCodeDisplay();
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
		mainDuration = std::stoi(duration);
		// Creates Movie obj with gathered information
		Movies obj(title, year, genre, mainDuration);
		if (insertVar == 0) {
			// Inserts into BST
			root = root->insert(root, obj);
		}
		else {
			// Insert into Maps
			mapRoot.insert(title, obj);
		}
		
	}
	insertVar++;
}
// Main menu function to display type of search options
void mainMenu(BST* root, Map<string, Movies> mapRoot) {
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
	cout << "3. Exit" << endl;
	cin >> firstOption;
	cout << endl;
	// Checks to see what option the user chose for the first set of options
	if (firstOption == 1) {
		checkMaps = true;
	}
	else if (firstOption == 2) {
		checkBST = true;
	}
	else if (firstOption == 3) {
		exit(0);
	}
	else {
		cout << "This is not a valid option. Let's try again from the beginning." << endl;
		cout << endl;
		mainMenu(root, mapRoot);
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
		mapLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkMaps == true && checkYear == true) {
		searchType = "Year";
		mapLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkMaps == true && checkGenre == true) {
		searchType = "Genre";
		mapLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkMaps == true && checkDuration == true) {
		searchType = "Duration";
		mapLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkMaps == true && checkGenreSearch == true) {
		searchType = "Genre Search";
		mapLooper(searchType, root, mapRoot, genreType);
	}

	//BSTs
	else if (checkBST == true && checkALL == true) {
		searchType = "All";
		BSTLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkBST == true && checkYear == true) {
		searchType = "Year";
		BSTLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkBST == true && checkGenre == true) {
		searchType = "Genre";
		BSTLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkBST == true && checkDuration == true) {
		searchType = "Duration";
		BSTLooper(searchType, root, mapRoot, genreType);
	}
	else if (checkBST == true && checkGenreSearch == true) {
		searchType = "Genre Search";
		BSTLooper(searchType, root, mapRoot, genreType);
	}
}
// Checks looper variables to determine proper search results for BST
void BSTLooper(string searchType, BST* root, Map<string, Movies> mapRoot, string genreType) {
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
	mainMenu(root, mapRoot);
}
// Checks looper variables to determine proper search results for Map
void mapLooper(string searchType, BST* root, Map<string, Movies> mapRoot, string genreType) {
	// Timer code function taken from https://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	if (searchType == "All") {
		mapRoot.printInOrder();
	}

	else if (searchType == "Year" || searchType == "Genre" || searchType == "Duration") {
		mapRoot.sortGenre(searchType);
	}

	else if (searchType == "Genre Search") {
		mapRoot.getInorderGenre(genreType);
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	std::cout << "Searching and Displaying all of the information using a Map and sorting by " << searchType << " took " << time_span.count() << " seconds." << endl;

	system("pause");
	cout << endl;
	system("cls");
	mainMenu(root, mapRoot);
}
