/*#include "Map.h"
void Map::insert(Movies* movie, string name) {

	m[name] = *movie;
}

void Map::sortMap(string category) {

	if (category == "Title") {
		printAll();
	}

	else {								// Idea from website:
										//https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
		vector<pair<string, Movies>> v;

		for (auto itr = m.begin(); itr != m.end(); itr++) {		//Push map values into vector
			v.push_back(make_pair(itr->first, itr->second));
		}

		if (category == "Year") {
			sort(v.begin(), v.end(), sortByYear);
		}

		else if (category == "Genre") {
			sort(v.begin(), v.end(), sortByGenre);
		}

		else if (category == "Duration") {
			sort(v.begin(), v.end(), sortByDuration);
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << endl;
		}
	}

}

bool Map::sortByYear(pair<string, Movies>& a, pair<string, Movies>& b) {

	return (a.second.getYear() < b.second.getYear());
}

bool Map::sortByGenre(pair<string, Movies>& a, pair<string, Movies>& b) {

	return (a.second.getGenre() < b.second.getGenre());
}

bool Map::sortByDuration(pair<string, Movies>& a, pair<string, Movies>& b) {

	return (a.second.getDuration() < b.second.getDuration());
}

void Map::printAll() {

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		cout << itr->first << endl;
	}
}*/