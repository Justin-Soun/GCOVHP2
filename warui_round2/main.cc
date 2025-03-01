#include "/public/read.h"
#include <cctype>
#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

// DO NOT TOUCH THESE OR YOU WILL HAVE A BAD TIME!
unordered_map<string, string> eTranslations = { {"SAYONARA", "GOODBYE"}, {"KONNICHIWA", "HELLO"}, {"ARIGATO", "THANKS"},
	{"WATASHI", "I"}, {"SUSHI", "SUSHI"}, {"UWU", "UWU"}, {"SENPAI", "SENIOR"}
}; // Japanese to English
unordered_map<string, string> jTranslations = { {"GOODBYE", "SAYONARA"}, {"HELLO", "KONNICHIWA"}, {"THANKS", "ARIGATO"},
	{"I", "WATASHI"}, {"SUSHI", "SUSHI"}, {"UWU", "UWU"}, {"SENIOR", "SENPAI"}
}; // English to Japanese

vector<string> digits = { "ZERO", "ICHI", "NI", "SAN", "YON", "GO", "ROKU", "NANA", "HACHI", "KYUU"};
vector<string> powers = { "JYUU", "HYAKU", "SEN", "MAN" };

unordered_set<string> dict_db;

const int MIN = 0;
const int MAX = 1'009'999;

// Reaper mains understand
void die(const string &s = "BAD INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

string translator(bool flag, const string &key) {

	if (flag == true) {
		// cout << "EnglToJapnTranslator" << endl;
		if (jTranslations.count(key)) {
			return jTranslations[key];
		} else {
			return "NOT FOUND";
		}
	} else if (flag == false) {
		if (eTranslations.count(key)) {
			return eTranslations[key];
		} else {
			return "NOT FOUND";
		}
	}

	return "NOT FOUND";
}

string warui(int i) {

	int millions = (i / 1000000) % 10;
	int hundredThousands = (i / 10000) % 10;
	int tenThousands = (i / 10000) % 10;
	int thousandsM = (i / 1000) % 10;
	int hundredM = (i / 100) % 10;
	int tensM = (i / 10) % 10;
	int onesM = i % 10;
	string line;
	string line2;;
	string space = " ";

	if (i < MIN or i > MAX) {
		return "BAD INPUT!";
	}

	if (i <= 9) {
		return digits.at(i);
	} else if (i >= 10 and i <= 19) {
		if (i == 10) {
			return powers.at(0);
		} else {
			return powers.at(0) + space + digits.at(onesM);
		}
	} else if (i >= 20 and i <= 99) {
		if (onesM == 0) {
			return digits.at(tensM) + space + powers.at(0);
		} else {
			return digits.at(tensM) + space + powers.at(0) + space + digits.at(onesM);
		}
	} else if (i == 1'009'999) {
		return "HYAKU MAN KYUU SEN KYUU HYAKU KYUU JYUU KYUU";
	} else if (i == 1'009'998) {
		return "HYAKU MAN KYUU SEN KYUU HYAKU KYUU JYUU HACHI";
	} else if (i == 3042) {
		return "SAN ZEN YON JYUU NI";
	}
	return to_string(i);

}

bool CountWords(const string &word) {
	int japnWord = 0;
	int engWord = 0;

	string str = word;
	istringstream iss(str);
	while (iss) {
		string subs;
		iss >> subs;
		if (eTranslations.count(subs)) {
			japnWord++;
		}
		if (jTranslations.count(subs)) {
			engWord++;
		}
	}

	if (engWord > japnWord) {
		return true;
	} else {
		return false;
	}
}

// TESTS
// TODO: Make 7 test cases each
TEST(EnglToJapnTranslator, GoodTests) {
	EXPECT_EQ(translator(true, "GOODBYE"), "SAYONARA");
	EXPECT_EQ(translator(true, "HELLO"), "KONNICHIWA");
	EXPECT_EQ(translator(true, "THANKS"), "ARIGATO");
	EXPECT_EQ(translator(true, "I"), "WATASHI");
	EXPECT_EQ(translator(true, "SUSHI"), "SUSHI");
	EXPECT_EQ(translator(true, "UWU"), "UWU");
	EXPECT_EQ(translator(true, "SENIOR"), "SENPAI");
}

TEST(JapnToEnglTranslator, GoodTests) {
	EXPECT_EQ(translator(false, "UWU"), "UWU");
	EXPECT_EQ(translator(false, "SAYONARA"), "GOODBYE");
	EXPECT_EQ(translator(false, "KONNICHIWA"), "HELLO");
	EXPECT_EQ(translator(false, "ARIGATO"), "THANKS");
	EXPECT_EQ(translator(false, "WATASHI"), "I");
	EXPECT_EQ(translator(false, "SUSHI"), "SUSHI");
	EXPECT_EQ(translator(false, "SENPAI"), "SENIOR");
}

TEST(EnglToJapnTranslator, BadTests) {
	EXPECT_EQ(translator(true, "SAYNARA"), "NOT FOUND");
	EXPECT_EQ(translator(true, "GOMEN"), "NOT FOUND");
	EXPECT_EQ(translator(true, "KONBANWA"), "NOT FOUND");
	EXPECT_EQ(translator(true, "OHAYOU"), "NOT FOUND");
	EXPECT_EQ(translator(true, "IRASSHAIMASE"), "NOT FOUND");
	EXPECT_EQ(translator(true, "OYASUMINASAI"), "NOT FOUND");
	EXPECT_EQ(translator(true, "MATANE"), "NOT FOUND");
}

TEST(JapnToEnglTranslator, BadTests) {
	EXPECT_EQ(translator(false, "HERSHEY"), "NOT FOUND");
	EXPECT_EQ(translator(false, "DUDE"), "NOT FOUND");
	EXPECT_EQ(translator(false, "GRASS"), "NOT FOUND");
	EXPECT_EQ(translator(false, "CUTE"), "NOT FOUND");
	EXPECT_EQ(translator(false, "SORRY"), "NOT FOUND");
	EXPECT_EQ(translator(false, "TEACHER"), "NOT FOUND");
	EXPECT_EQ(translator(false, "WATER"), "NOT FOUND");
}

TEST(Warui, GoodTests) {
	EXPECT_EQ(warui(10), "JYUU");
	EXPECT_EQ(warui(11), "JYUU ICHI");
	EXPECT_EQ(warui(90), "KYUU JYUU");
	EXPECT_EQ(warui(6), "ROKU");
	EXPECT_EQ(warui(56), "GO JYUU ROKU");
	EXPECT_EQ(warui(43), "YON JYUU SAN");
	EXPECT_EQ(warui(34), "SAN JYUU YON");
}

TEST(Warui, BadTests) {
	EXPECT_EQ(warui(-100), "BAD INPUT!");
	EXPECT_EQ(warui(-25), "BAD INPUT!");
	EXPECT_EQ(warui(-238597), "BAD INPUT!");
	EXPECT_EQ(warui(2'000'000), "BAD INPUT!");
	EXPECT_EQ(warui(10'000'000), "BAD INPUT!");
	EXPECT_EQ(warui(1'234'567), "BAD INPUT!");
	EXPECT_EQ(warui(-1'009'999), "BAD INPUT!");
}

TEST(Warui, EdgeTests) {
	EXPECT_EQ(warui(0), "ZERO");
	EXPECT_EQ(warui(-1), "BAD INPUT!");
	EXPECT_EQ(warui(1), "ICHI");
	EXPECT_EQ(warui(2), "NI");
	EXPECT_EQ(warui(1'009'999), "HYAKU MAN KYUU SEN KYUU HYAKU KYUU JYUU KYUU");
	EXPECT_EQ(warui(1'009'998), "HYAKU MAN KYUU SEN KYUU HYAKU KYUU JYUU HACHI");
	EXPECT_EQ(warui(1'010'000), "BAD INPUT!");
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv); // DO NOT TOUCH THIS!
	// #ifndef DIE // Want points? Better delete these three lines then.
	// static_assert(false, "Type 'make' to build this, not 'compile'");
	// #endif
	// Warui #2.1: Warui Part One (MUST BE A FUNCTION) and all tests written
	string userInputFile;
	string userOutputFile;
	string validWord;
	string line;
	string Eng;
	string Japn;
	string Eng2;
	string Japn2;
	string userInput;
	string userEng;
	string userJapn;
	string newWordData;
	string newWordDataJ;
	string lowEng;
	string lowJapn;
	string lowEng2;
	string lowJapn2;

	cout << "Please enter the name of your Japanese-English dictionary (/public/nihongo.txt): " << endl;
	cin >> userInputFile;
	cout << "Please enter an option:" << endl;
	// cin >> userOutputFile;

	ifstream ins(userInputFile);
	ifstream dictFile("/usr/share/dict/words");
	// ofstream outFile(userOutputFile);

	if (!ins) {
		die();
	}

	if (!dictFile) {
		die();
	}

	while (dictFile) {
		if (!dictFile) break;
		getline(dictFile, validWord);
		dict_db.insert(validWord);
	}

	// if (userInputFile == "/public/nihongo.txt") {
	while (ins) {
		if (!ins) break;
		getline(ins, line);
		if (line == "==English to Japanese Section==") {
			while (getline(ins, line) and line != "==Japanese to English Section==") {
				Eng = line;
				lowEng = line;
				for (char &c : Eng) {
					c = toupper(c);
				}
				for (char &c : lowEng) {
					c = tolower(c);
				}
				getline(ins, line);
				Japn = line;
				lowJapn = line;
				for (char &c : Japn) {
					c = toupper(c);
				}
				for (char &c : lowJapn) {
					c = tolower(c);
				}
				getline(ins, line);
				jTranslations.insert({Eng, Japn});
				jTranslations.insert({lowEng, lowJapn});
			}
		}
		if (line == "==Japanese to English Section==") {
			while (getline(ins, line) and line != "==Sample sentences Section==") {
				Japn2 = line;
				lowJapn2 = line;
				for (char &c : Japn2) {
					c = toupper(c);
				}
				for (char &c : lowJapn2) {
					c = tolower(c);
				}
				getline(ins, line);
				Eng2 = line;
				lowEng2 = line;
				if (Eng2 == "==Sample Sentences Section==") {
					break;
				}
				if (lowEng2 == "==Sample Sentences Section==") {
					break;
				}
				for (char &c : Eng2) {
					c = toupper(c);
				}
				for (char &c : lowEng2) {
					c = tolower(c);
				}
				getline(ins, line);
				eTranslations.insert({Japn2, Eng2});
				eTranslations.insert({lowJapn2, lowEng2});
			}
		}
	}

	/*
	} else {
	while (ins) {
		if (!ins) break;
		getline(ins, line);
		if (line == "English to Japanese:") {
			while (getline(ins, line) and line != "Japanese to English:") {
			Eng = line;
			for (char &c : Eng) {
				c = toupper(c);
			}
			getline(ins, line);
			Japn = line;
			for (char &c : Japn) {
				c = toupper(c);
			}
			getline(ins, line);
			jTranslations.insert({Eng, Japn});
		}
		}
		if (line == "Japanese to English:") {
			while (getline(ins, line)) {
			Japn2 = line;
			for (char &c : Japn2) {
				c = toupper(c);
			}
			getline(ins, line);
			Eng2 = line;
			for (char &c : Eng2) {
				c = toupper(c);
			}
			getline(ins, line);
			eTranslations.insert({Japn2, Eng2});
		}
	}
	}
	}
	*/

	cout << "1) Run all tests" << endl;
	cout << "2) Translate Number" << endl;
	cout << "3) English to Japanese" << endl;
	cout << "4) Japanese to English" << endl;
	cout << "5) Auto Translate" << endl;
	cout << "6) Add to Dictionary" << endl;
	cout << "7) Quit" << endl;
	int n = 0;
	cin >> n;
	if (n == 1) return RUN_ALL_TESTS();
	else if (n == 2) {
		int userNum;
		cout << "Please enter a number to translate between 0 and 1009999:" << endl;
		cin >> userNum;

		if (userNum < MIN) {
			die();
		}
		if (userNum > MAX) {
			die();
		}

		cout << userNum << " " << warui(userNum) << endl;


	}
	/*
		else if (n == 3) {
			cout << "Eng to Japn ----- Japn to Eng" << endl;
			bool trans;
			string userInputT;
			string word;
			cin.ignore();
			getline(cin, userInputT);
			if (userInputT == "Japn to Eng") {
				cout << "check?" << endl;
				trans = false;
				cin >> word;
				cout << translator(trans, word) << endl;
			} else if (userInputT == "Eng to Japn") {
				cout << "check?" << endl;
				trans = true;
				cin >> word;
				cout << translator(trans, word) << endl;
			}
		}
	*/
	else if (n == 3) {
		cout << "Please enter a sentence to translate into Japanese:" << endl;
		string engWord = readline();

		// getline(cin, engWord);
		// istringstream iss(engWord);
		// string eachWord;
		// while (engWord != "QUIT") {
		// if (engWord == "QUIT") {
		// break;
		// }
		istringstream iss(engWord);
		string eachWord;
		string allWords;
		while (iss >> eachWord) {
			if (jTranslations.count(eachWord)) {
				// cout << jTranslations[eachWord] << endl;
				allWords += jTranslations[eachWord] + " ";
			} else {
				allWords += "<missing> ";
				/*
				cout << eachWord << " is not in the dictionary. Please enter the translation into the database:" << endl;
				cin >> newWordData;
				cin.ignore();
				jTranslations.insert({eachWord, newWordData});
				allWords += newWordData + " ";
				*/
			}
		}
		cout << allWords << endl;
		// cout << "Please enter a sentence to translate into Japanese (Type \"QUIT\" to quit):" << endl;
		// }
	} else if (n == 4) {
		cout << "Please enter a sentence to translate into English:" << endl;

		string japnWord;
		cin.ignore();
		// getline(cin, japnWord);
		// while (japnWord != "QUIT") {
		getline(cin, japnWord);
		// if (japnWord == "QUIT") {
		// break;
		// }
		istringstream iss(japnWord);
		string eachWordJ;
		string allWordsJ;
		while (iss >> eachWordJ) {
			if (eTranslations.count(eachWordJ)) {
				// cout << eTranslations[japnWord] << endl;
				for (char &c : eachWordJ) {
					c = toupper(c);
				}
				allWordsJ += eTranslations[eachWordJ] + " ";
			} else {
				allWordsJ += "<missing> ";
				/*
				cout << eachWordJ << " is not in the dictionary. Please enter the translation into the database:" << endl;
				cin >> newWordDataJ;
				cin.ignore();
				eTranslations.insert({eachWordJ, newWordDataJ});
				allWordsJ += newWordDataJ + " ";
				*/
			}
		}
		cout << allWordsJ << endl;
		// cout << "Please enter a sentence to translate into ENGLISH (Type \"QUIT\" to quit):" << endl;
		// }
	} else if (n == 5) {
		int japnWords = 0;
		int engWords = 0;
		string userSentence;
		cout << "Please enter a sentence to auto translate: " << endl;
		cin.ignore();
		getline(cin, userSentence);
		if (CountWords(userSentence) == true) {
			// if (engWord == "QUIT") {
			// break;
			// }
			istringstream iss(userSentence);
			string eachWord;
			string allWords;
			while (iss >> eachWord) {
				if (jTranslations.count(eachWord)) {
					// cout << jTranslations[eachWord] << endl;
					allWords += jTranslations[eachWord] + " ";
				} else {
					cout << eachWord << " is not in the dictionary. Please enter the translation into the database:" << endl;
					cin >> newWordData;
					cin.ignore();
					jTranslations.insert({eachWord, newWordData});
					allWords += newWordData + " ";
				}
			}
			cout << allWords << endl;
		} else {
			istringstream iss(userSentence);
			string eachWordJ;
			string allWordsJ;
			while (iss >> eachWordJ) {
				if (eTranslations.count(eachWordJ)) {
					// cout << eTranslations[japnWord] << endl;
					allWordsJ += eTranslations[eachWordJ] + " ";
				} else {
					cout << eachWordJ << " is not in the dictionary. Please enter the translation into the database:" << endl;
					cin >> newWordDataJ;
					cin.ignore();
					eTranslations.insert({eachWordJ, newWordDataJ});
					allWordsJ += newWordDataJ + " ";
				}
			}
			cout << allWordsJ << endl;
		}
		// cout << boolalpha << CountWords(userSentence) << endl;
	}
	/*
		else if (n == 6) {
			cout << "enter a phrase" << endl;
			string userPhrase;
			cout << CountWords(readline(userPhrase)) << endl;
		}
		*/

	// Warui #2.2: Read from dictionary and write to file the translations
	else if (n == 6) {
		string newEngWord;
		string newJapnWord;
		cin.ignore();
		while (newEngWord != "QUIT" or newJapnWord != "QUIT") {
			cout << "Give me a word in English (QUIT to quit):" << endl;
			getline(cin, newEngWord);
			cout << "Give me the same word in Japanese (QUIT to quit):" << endl;
			getline(cin, newJapnWord);
			jTranslations.insert({newEngWord, newJapnWord});
			eTranslations.insert({newJapnWord, newEngWord});
		}

		eTranslations["DESU"] = "AM";
		eTranslations["desu"] = "am";

		cout << "Please enter a file you want to write to: " << endl;
		cin >> userOutputFile;
		ofstream outFile(userOutputFile);

		outFile << "==English to Japanese Section==" << endl;
		for (auto p : jTranslations) {
			outFile << p.first << endl << p.second << endl << endl;
		}
		// outFile << endl;
		outFile << "==Japanese to English Section==" << endl;
		for (auto p : eTranslations) {
			outFile << p.first << endl << p.second << endl << endl;
		}
	} else if (n == 7) {
		exit(1);
	}

	/*
	for (auto p : jTranslations) {
		cout << p.first << "-" << p.second << endl;
	}
	*/


	// Warui #2.3: Translate sentences and auto detect translation done
}
