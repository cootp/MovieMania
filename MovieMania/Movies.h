#pragma once
using namespace std;
class Movies {
private:
	string title;
	string year;
	string genre;
	int duration;
public:
	// Default Constructor
	Movies();
	// Constructor
	Movies(string title_, string year_, string genre_, int duration_);
	// Getters
	string getTitle();
	string getYear();
	string getGenre();
	int getDuration();
};
