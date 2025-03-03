#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

void die();

bool isPrime(cpp_int x);

string calculate(cpp_int minOfUser, cpp_int max, vector<cpp_int> primeNumbers, cpp_int printOrNot);

#endif
