#include <iostream>
using namespace std;
#include "Movies.h"
Movies::Movies() {
	title = "";
	year = "";
	genre = "";
	duration = "";

}
Movies::Movies(string title_, string year_, string genre_, string duration_) {
	title = title_;
	year = year_;
	genre = genre_;
	duration = duration_;
}
string Movies::getTitle() {
	return title;
}
string Movies::getYear() {
	return year;
}
string Movies::getGenre() {
	return genre;
}
string Movies::getDuration() {
	return duration;
}
