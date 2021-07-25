#pragma once
using namespace std;
class Movies {
private:
	std::string title;
	int year;
	std::string genre;
	int duration;
public:
	Movies(string title_, int year_, string genre_, int duration_);
	string getTitle();
	int getYear();
	string getGenre();
	int getDuration();
};
