#include test.h

using namespace std;

void assertTrue(bool b, sting description) {
  if (!b) {
    cout << "FAILED: " << description << endl;
  } else {
    cout << "PASSED: " << description << endl;
  }
}
