#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movies.h";

using namespace std;

class Map
{
private:

	map<string, Movies> m;

public:

	void insert(Movies* movie, string name);

	void sortMap(string category);
	bool sortByYear(pair<string, Movies>& a, pair<string, Movies>& b);
	bool sortByGenre(pair<string, Movies>& a, pair<string, Movies>& b);
	bool sortByDuration(pair<string, Movies>& a, pair<string, Movies>& b);

	void printAll();
};
