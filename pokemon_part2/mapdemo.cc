#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//One way to convert from type name to row number in the type_system.txt file
int lookup_type(string s) {
	if (s == "Normal") return 0;
	else if (s == "Fighting") return 1;
	else if (s == "Flying") return 2;
	else if (s == "Poison") return 3;
	else if (s == "Ground") return 4;
	else if (s == "Rock") return 5;
	else if (s == "Bug") return 6;
	else if (s == "Ghost") return 7;
	else if (s == "Steel") return 8;
	else if (s == "Fire") return 9;
	else if (s == "Water") return 10;
	else if (s == "Grass") return 11;
	else if (s == "Electric") return 12;
	else if (s == "Psychic") return 13;
	else if (s == "Ice") return 14;
	else if (s == "Dragon") return 15;
	else if (s == "Dark") return 16;
	else if (s == "Fairy") return 17;
	else
		return -1;
}

int main() {
	//Sets up a mapping between the string holding a type and the row/col of that type in the type_system.txt file
	map<string, int> m;
	m["Normal"] = 0;
	m["Fighting"] = 1;
	m["Flying"] = 2;
	m["Poison"] = 3;
	m["Ground"] = 4;
	m["Rock"] = 5;
	m["Bug"] = 6;
	m["Ghost"] = 7;
	m["Steel"] = 8;
	m["Fire"] = 9;
	m["Water"] = 10;
	m["Grass"] = 11;
	m["Electric"] = 12;
	m["Psychic"] = 13;
	m["Ice"] = 14;
	m["Dragon"] = 15;
	m["Dark"] = 16;
	m["Fairy"] = 17;

	//This is how you look up which row/col the type is
	cout << "Please enter a type:\n";
	string s;
	cin >> s;
	cout << "Its row/col is: " << m[s] << endl;
}
