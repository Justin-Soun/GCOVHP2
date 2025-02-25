#include <iostream>
#include "/public/read.h"
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
using namespace std;

void die(string s = "INVALID INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

//Holds info for a single species of Pokemon, such as Pikachu
class Pokemon {
  public:
	int index = -1;
	string name = "NoName";
	string type1 = "";
	string type2 = "";
	int hp = -1;
	int attack = -1;
	int defense = -1;
	int specialAttack = -1;
	int specialDefense = -1;
	int speed = -1;
	int generation = -1;
	bool legendary = false;
	//YOU: Add member variable ints for each of the following:
	//index - what index it is in the pokedex
	//name (this is a string not an int)
	//hp - how much damage it takes before dying fainting
	//attack - this number gets multiplied by the move's power to determine damage
	//defense - incoming damage gets divided by this number
	//special attack - like attack but for special moves
	//special defense - like defense but for special moves
	//speed - whichever pokemon has the highest speed attacks first, flip a coin on a tie
	//generation - when the pokemon was released
	//legendary - if it is a legendary or not
	//YOU: Add member variables of type string for type1 and type2
};

void print(const Pokemon &mon, int index) {
	if (index == mon.index) {
		cout << "Name: " << mon.name << endl;
		cout << "Index: " << mon.index << endl;
		cout << "HP: " << mon.hp << endl;
		cout << "Attack: " << mon.attack << endl;
		cout << "Defense: " << mon.defense << endl;
		cout << "Speed: " << mon.speed << endl;
		cout << "Special Attack: " << mon.specialAttack << endl;
		cout << "Special Defense: " << mon.specialDefense << endl;
		cout << "Type1: " << mon.type1 << endl;
		cout << "Type2: " << mon.type2 << endl;
		cout << "Gen: " << mon.generation << endl;
		cout << "Legendary: " << boolalpha << mon.legendary << endl;
	} else if (index <= 0) {
		die();
	}
}
void printName(const Pokemon &mon, string pokeName) {
	if (pokeName == mon.name) {
		cout << "Name: " << mon.name << endl;
		cout << "Index: " << mon.index << endl;
		cout << "HP: " << mon.hp << endl;
		cout << "Attack: " << mon.attack << endl;
		cout << "Defense: " << mon.defense << endl;
		cout << "Speed: " << mon.speed << endl;
		cout << "Special Attack: " << mon.specialAttack << endl;
		cout << "Special Defense: " << mon.specialDefense << endl;
		cout << "Type1: " << mon.type1 << endl;
		cout << "Type2: " << mon.type2 << endl;
		cout << "Gen: " << mon.generation << endl;
		cout << "Legendary: " << boolalpha << mon.legendary << endl;
	}
}

//This class holds a record for each move in the game
class Move {
  public:
	//YOU: Add member variable for each of these:
	//int index, string name, string type, string category, int PP, int power, int accuracy
	int index = -1;
	string name = "NoName";
	string type = "";
	string category = "NoCategory";
	int PP = -1;
	int power = -1;
	int accuracy = -1;

};

void printMov(const Move &mov, int index) {
	if (index == mov.index) {
		cout << "Move Index " << mov.index << ": " << mov.name << "  type: " << mov.type << " category: " << mov.category << " PP: " << mov.PP << " power: " << mov.power << " accuracy: " << mov.accuracy << "%" << endl;
	}
}

void attack_function(const Pokemon &p1, const Pokemon &p2, const Move &m) {
	float damage;
	float specialDamage;
	float STAB = 1;
	float typeMod = 1;
	Pokemon attacker = (p1.speed >= p2.speed) ? p1 : p2;
	Pokemon defender = (p1.speed < p2.speed) ? p1 : p2;
	// cout << attacker.name << "'s speed: " << attacker.speed << " - " << defender.name << "'s speed: " << defender.speed << endl;

	if (attacker.type1 == m.type or attacker.type2 == m.type) {
		STAB = 1.5;
	} else {
		STAB = 1;
	}
	/*
	if (m.type == "Poison") {
		if (defender.type1 == "Grass" or defender.type2 == "Grass") {
			typeMod = 2;
			if (defender.type1 == "Fairy" or defender.type2 == "Fairy") {
				typeMod += 2;
			}
		}
	} else if (m.type == "Bug") {
		if (defender.type1 == "Flying" or defender.type2 == "Flying") {
			typeMod = 0.5;
		}
	} else if (m.type == "Grass") {
		if (defender.type1 == "Water" or defender.type2 == "Water") {
			typeMod = 2;
			if (defender.type1 == "Ground" or defender.type2 == "Ground") {
				typeMod += 2;
			}
		} else if (defender.type1 == "Grass" or defender.type2 == "Grass") {
			typeMod = 0.5;
			if (defender.type1 == "Poison" or defender.type2 == "Poison") {
				typeMod *= 0.5;
			}
		}
	}
	*/

	// cout << typeMod << endl;

	if (m.category == "Physical") {
		if (defender.defense == 0) {
			damage = 9999;
		} else {
			damage = (float(attacker.attack) / float(defender.defense)) * STAB * typeMod * m.power; //equation for normal moves;
		}
		cout << attacker.name << " used " << m.name << " and dealt " << round(damage) << " to " << defender.name << endl;
		// return damage;
	} else if (m.category == "Special") {
		if (defender.defense == 0) {
			specialDamage = 9999;
		} else {
			specialDamage = (float(attacker.specialAttack) / float(defender.specialDefense)) * STAB * typeMod * m.power; //equation for special moves;
		}
		cout << attacker.name << " used " << m.name << " and dealt " << round(specialDamage) << " to " << defender.name << endl;
		// return specialDamage;
	} else {
		cout << "error" << endl;
		// return -9999;
	}


}


int main() {
	system("figlet POKEMON");
	system("figlet ++ and \\#");
	cout << "Do you want to use the default files? (Type \"NO\" for no, anything else for yes.)\n";

	//YOU: Load files for all pokemon and moves, and put them into these vectors:
	vector<Pokemon> pokemon_db; //Holds all pokemon known
	vector<Move> move_db; //Holds all the moves we know
	Pokemon PokeDex;
	Move MoveDex;

	int lastIndex = 0;

	string userDefault;
	string userPokeFile;
	string userMoveFile;
	getline(cin, userDefault);
	if (userDefault == "no" or userDefault == "NO") {
		cout << "Please enter the file containing the Pokémon CSV file:" << endl;
		getline(cin, userPokeFile);
		cout << "Please enter the file containing the moves for your Pokémon." << endl;
		getline(cin, userMoveFile);
	} else {
		userPokeFile = "/public/pokemon.csv";
		userMoveFile = "/public/moves.txt";
	}

	ifstream ins(userPokeFile);
	ifstream iff(userMoveFile);
	if (!ins) {
		die();
	}
	if (!iff) {
		die();
	}

	string line = readline(ins);
	while (ins) {
		if (!ins) break;
		line = readline(ins);
		if (!ins) break;
		istringstream iss(line);
		while (iss) {
			// cout << readline(iss, ',');
			// break;
			string lower;
			int checkIndex;
			checkIndex = stoi(readline(iss, ','));
			if (checkIndex == PokeDex.index) {
				break;
			} else {
				PokeDex.index = checkIndex;
			}
			PokeDex.name = readline(iss, ',');
			PokeDex.type1 = readline(iss, ',');
			PokeDex.type2 = readline(iss, ',');
			readline(iss, ',');
			PokeDex.hp = stoi(readline(iss, ','));
			PokeDex.attack = stoi(readline(iss, ','));
			PokeDex.defense = stoi(readline(iss, ','));
			PokeDex.specialAttack = stoi(readline(iss, ','));
			PokeDex.specialDefense = stoi(readline(iss, ','));
			PokeDex.speed = stoi(readline(iss, ','));
			PokeDex.generation = stoi(readline(iss, ','));
			string ifBool = readline(iss, ',');
			if (ifBool == "True") {
				PokeDex.legendary = true;
			} else {
				PokeDex.legendary = false;
			}
			pokemon_db.push_back(PokeDex);
			break;
		}
		lastIndex = PokeDex.index;
	}
	while (iff) {
		if (!iff) break;
		string moveLine = readline(iff);
		if (!iff) break;
		// cout << moveLine << endl;
		istringstream inf(moveLine);
		while (inf) {
			string check;
			// cout << readline(inf, '\t') << endl;
			// break;
			MoveDex.index = stoi(readline(inf, '\t'));
			MoveDex.name = readline(inf, '\t');
			MoveDex.type = readline(inf, '\t');
			check = readline(inf, '\t');
			if (check == "Status") {
				break;
			} else {
				MoveDex.category = check;
			}
			MoveDex.PP = stoi(readline(inf, '\t'));
			check = readline(inf, '\t');
			if (check == "—") {
				break;
			} else {
				MoveDex.power = stoi(check);
			}
			check = readline(inf, '\t');
			if (check == "—") {
				break;
			} else {
				MoveDex.accuracy = stoi(check);
			}
			move_db.push_back(MoveDex);
			break;
		}
	}
	/*
	for (const Pokemon &mon : pokemon_db) {
		print(mon);
	}
	*/
	/*
	for (const Move &mov : move_db) {
		printMov(mov);
	}
	*/
	//YOU: Ask the user if they want to look up a Pokemon or a Move
	cout << "Do you want to" << endl;
	cout << "1) Print Pokémon Data?" << endl;
	cout << "2) Print Move Data?" << endl;
	cout << "3) Pokemon Battle (1v1)" << endl;
	cout << "4) Explore the World?" << endl;

	//YOU: Print the info on the chosen Pokemon or Move
	int userInput;
	cin >> userInput;
	if (userInput == 1) {
		int userIndex;
		cout << "Please enter the Pokedex number of the Pokémon whose data you want to print:" << endl;
		cin >> userIndex;
		if (userIndex > lastIndex) {
			die();
		}
		for (const Pokemon &mon : pokemon_db) {
			print(mon, userIndex);
		}
	} else if (userInput == 2) {
		int userMoveIndex;
		cout << "Please enter the move number of the move whose data you want to print:" << endl;
		cin >> userMoveIndex;
		for (const Move &mov : move_db) {
			printMov(mov, userMoveIndex);
		}
	} else if (userInput == 3) {
		Pokemon p1;
		Pokemon p2;
		cout << "Please enter the name or ID of Pokemon 1:" << endl;
		string player1 = readline();
		bool index = true;
		for (char c : player1) {
			if (!isdigit(c)) {
				index = false;
			}
		}
		if (index) {
			if (stoi(player1) > lastIndex) {
				die();
			}
		}
		for (const Pokemon &p : pokemon_db) {
			if (index) {
				if (p.index == stoi(player1)) {
					// print(p, stoi(player1));
					p1 = p;
				}
			} else if (p.name == player1) {
				// printName(p, player1);
				p1 = p;
			}
		}
		if (!index) {
			if (p1.name != player1) {
				die();
			}
		}
		cout << "Please enter the name or ID of Pokemon 2:" << endl;
		string player2 = readline();
		index = true;
		for (char c : player2) {
			if (!isdigit(c)) {
				index = false;
			}
		}
		if (index) {
			if (stoi(player2) > lastIndex) {
				die();
			}
		}
		for (const Pokemon &p : pokemon_db) {
			if (index) {
				if (p.index == stoi(player2)) {
					// print(p, stoi(player2));
					p2 = p;
				}
			} else if (p.name == player2) {
				// printName(p, player2);
				p2 = p;
			}
		}
		if (!index) {
			if (p2.name != player2) {
				die();
			}
		}
		// cout << p1.name << ": " << p1.index << endl;
		// cout << p2.name << ": " << p2.index << endl;
		Move m1;
		cout << "Please enter the name or ID of the move to use:" << endl;
		string pokeMove = readline();
		index = true;
		for (char c : pokeMove) {
			if (!isdigit(c)) {
				index = false;
			}
		}
		if (index) {
			if (stoi(pokeMove) > lastIndex) {
				die();
			}
		}
		for (const Move &m : move_db) {
			if (index) {
				if (m.index == stoi(pokeMove)) {
					m1 = m;
				}
			} else if (m.name == pokeMove) {
				m1 = m;
			}
		}
		if (!index) {
			if (m1.name != pokeMove) {
				die();
			}
		}
		// cout << m1.name << ": " << m1.index << endl;

		attack_function(p1, p2, m1);

	} else {
		die();
	}

}
