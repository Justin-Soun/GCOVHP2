#include "/public/read.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <time.h>
using namespace boost::multiprecision;
using namespace std;

//YOU: Maybe write a function to see if a number is prime here?
// (Or not, I'm not your boss.)
//The Boost Multiprecision Miller-Rabin primality test is installed somewhere on the server.
//If you can find it, you can use it
const array<cpp_int, 21> cache = {
	0,
	4,
	25,
	168,
	1'229,
	9'592,
	78'498,
	664'579,
	5'761'455,
	50'847'534,
	455'052'511,
	4'118'054'813,
	37'607'912'018,
	346'065'536'839,
	3'204'941'750'802,
	29'844'570'422'669,
	279'238'341'033'925,
	2'623'557'157'654'233,
	24'739'954'287'740'860,
	234'057'667'276'344'607,
	2'220'819'602'560'918'840
};

void die() {
	cout << "BAD INPUT!" << endl;
	exit(EXIT_FAILURE);
}

bool isPrime(cpp_int x) {
	if (x <= 1) {
		return false;
	}
	return miller_rabin_test(x, 1);
}


cpp_int calculate(cpp_int minOfUser, cpp_int max, vector<cpp_int> primeNumbers, int min, cpp_int primeAmount, cpp_int printOrNot){
	cpp_int sum = 0;
	for (cpp_int i = minOfUser - 1; i >= 2; i--) {
		if (isPrime(i) == true) {
			primeNumbers.push_back(i);
		}
	}

	for (cpp_int i = minOfUser; i <= max; i++) {
		if (isPrime(i) == true) {
			primeNumbers.push_back(i);

		}
	}


	for (cpp_int i = min; i <= max; i++) {
		auto it = find(primeNumbers.begin(), primeNumbers.end(), i);
		if (it == primeNumbers.end()) {
			primeAmount += 0;
		} else {
			primeAmount++;
		}
		if (i >= minOfUser and i <= max) {
			sum += primeAmount;
			if (printOrNot <= 10) {
				cout << "pi(" << i << ") = " << primeAmount << endl;
			}
		}
	}
	return sum;
}





TEST(Prime, GoodTests) {
	EXPECT_EQ(isPrime(2), true);
	EXPECT_EQ(isPrime(1231), true);
	EXPECT_EQ(isPrime(97), true);
	EXPECT_EQ(isPrime(401), true);
	EXPECT_EQ(isPrime(859), true);
}
TEST(Prime, BadTests) {
	EXPECT_EQ(isPrime(12), false);
	EXPECT_EQ(isPrime(126), false);
	EXPECT_EQ(isPrime(-256), false);
	EXPECT_EQ(isPrime(-1231231), false);
	EXPECT_EQ(isPrime(10000000), false);
}
TEST(Prime, EdgeTests) {
	EXPECT_EQ(isPrime(1), false);
	EXPECT_EQ(isPrime(0), false);
	EXPECT_EQ(isPrime(2), true);
	EXPECT_EQ(isPrime(3), true);
	EXPECT_EQ(isPrime(4), false);
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	cpp_int primeAmount = 0;
	int min = 2;

	int user = 0;
	cout << "1) For GTest" << endl;
	cout << "2) For Zeta" << endl; 
	cin >> user;

	if (user == 1) {
		cout << RUN_ALL_TESTS() << endl;
	} 
	else if (user == 2) {

		cpp_int primeAmount = 0;
		int min = 2;

		cout << "Welcome to Zeta World!\nWe will compute the sum of all pi(x) from x = i to j\n";

		vector<cpp_int> primeNumbers;
		cpp_int minOfUser = read("Please enter i:\n");
		cpp_int max = read("Please enter j:\n");
		cpp_int printOrNot = max - minOfUser;

		vector<cpp_int> pNumbers;

		if (minOfUser < 2 or max < 2) {
			die();
		} else if (max < minOfUser) {
			die();
		}
		clock_t start_time = clock();


		cpp_int sum = calculate(minOfUser, max, primeNumbers, min, primeAmount, printOrNot);
		cout << "The answer is: " << sum << endl;
		cout << ((clock() - start_time)/1000) << "ms has elapsed\n";


	}
}


