#include "/public/read.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void die() {
	cout << "You dun goofed.\n";
	exit(0);
}

int main() {
	//This is equivalent to string filename; cout << "Please enter a filename\n"; cin >> filename;
	//But on one line instead of three, because I'm cool like that
	string filename = read("Please enter a filename:\n");
	ifstream ins(filename);
	if (!ins) {
		die();
	}

	vector<int> vec;

	while (true) {
		int moneyCase = read(ins);
		if (!ins) {
			break;
		}
		vec.push_back(moneyCase);
	}

	int x = 1;
	int y = 0;
	int Totalcases = vec.at(0);
	int count = Totalcases;
	int walkAway = 0;
	vec.erase(vec.begin());

	if (Totalcases < 2) {
		die();
	}

	vector<int> openedCases;
	while (true) {
		int sum = 0;
		int average = 0;
		count--;
		int caseNum = read("Please enter a briefcase to open:\n");
		if (caseNum < -1 or caseNum >= Totalcases) {
			die();
		}

		if (caseNum == -1 and walkAway == 0) {
			for (int i = 0; i < vec.size(); i++) {
				sum += vec.at(i);
			}
			average = sum / vec.size();
			cout << "You won " << average << " dollars!" << endl;
			break;
		} 	else if (caseNum == -1) {
			cout << "You won " << walkAway << " dollars!" << endl;
			break;
		}

		for (int i = 0; i < openedCases.size(); i++) {
			if (openedCases.at(i) == caseNum) {
				die();
			}
		}

		y += vec.at(caseNum);
		for (int i = 0; i < vec.size(); i++) {
			sum += vec.at(i);
		}
		average = (sum - y) / (vec.size() - x);

		cout << "That briefcase held " << vec.at(caseNum) << " dollars" << endl;

		if (count == 1) {
			cout << "You won " << average << " dollars!" << endl;
			break;
		} else {
			cout << "I will offer you " << average << " dollars to walk away." << endl;
		}
		openedCases.push_back(caseNum);
		walkAway = average;
		x++;
	}


	//Next...
	//Do you remember how to open a file?
	//How to check to see if the file opened successfully?
	//How do you store data in a vector?
	//How do you average values across a vector?
}
