#pragma once
using namespace std;
class Movies {
private:
	string title;
	string year;
	string genre;
	int duration;
public:
	Movies();
	Movies(string title_, string year_, string genre_, int duration_);
	string getTitle();
	string getYear();
	string getGenre();
	int getDuration();
};
