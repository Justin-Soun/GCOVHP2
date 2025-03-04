#include <array>
#include "/public/read.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <time.h>
using namespace boost::multiprecision;
using namespace std;

#include "functions.h"
#include "test.h"

void testIsPrime1();
void testIsPrime2();
void testIsPrime3();
void testIsPrime4();
void testCalculateSum1();
void testCalculateSum2();
void testCalculateSum3();
void testCalculateSum4();

int main(){
  testIsPrime1();
  testIsPrime2();
  testIsPrime3();
  testIsPrime4();

  testCalculateSum1();
  testCalculateSum2();
  testCalculateSum3();
  testCalculateSum4();

  return 0;
}

void testIsPrime1(){
  assertTrue(isPrime(0) == false,
             "isPrime(0) = false");
}

void testIsPrime2(){
  assertTrue(isPrime(97) == 1,
             "isPrime(97) = 1");
}

void testIsPrime3(){
  assertTrue(isPrime(198722) == 0,
             "isPrime(198722) = 0");
}

void testIsPrime4(){
  assertTrue(isPrime(1987) == 1,
             "isPrime(1987) = 1");
}

void testCalculateSum1(){
  vector<cpp_int> primes;
  assertTrue(calculate(100, 10000, primes, 0) == 6553393,
	     "calculate 100 to 1000 = 6553393");
}

void testCalculateSum2(){
  vector<cpp_int> primes;
  assertTrue(calculate(2, 13, primes, 0) == 43,
             "calculate 2 to 13 = 43");
}

void testCalculateSum3(){
  vector<cpp_int> primes;
  assertTrue(calculate(52, 235, primes, 0) == 6234,
             "calculate 52 to 235 = 6234");
}

void testCalculateSum4(){
  vector<cpp_int> primes;
  assertTrue(calculate(2, 100000, primes, 0) == 504813055,
             "calculate 2 to 100000 = 504813055");
}

