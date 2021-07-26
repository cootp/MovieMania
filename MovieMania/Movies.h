#pragma once
using namespace std;
class Movies {
private:
	string title;
	string year;
	string genre;
	string duration;
public:
	Movies();
	Movies(string title_, string year_, string genre_, string duration_);
	string getTitle();
	string getYear();
	string getGenre();
	string getDuration();
};
