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#include <array>
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

void testIsPrime();

int main(){
  testIsPrime();

  return 0;
}

void testIsPrime(){
  assertTrue(isPrime(10) == miller_rabin_test(10,1),
             "isPrime(10)=")
}
