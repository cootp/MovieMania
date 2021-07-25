#include <iostream>
using namespace std;
#include "Movies.h"
Movies::Movies(string title_, int year_, string genre_, int duration_) {
	title = title_;
	year = year_;
	genre = genre_;
	duration = duration_;
}
string Movies::getTitle() {
	return title;
}
int Movies::getYear() {
	return year;
}
string Movies::getGenre() {
	return genre;
}
int Movies::getDuration() {
	return duration;
}
