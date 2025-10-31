#include <iostream>
#include <vector>
/*
vector<bool> is a specialized bit-packed container; elements are proxies,
not real bool references. Beware: taking addresses, certain APIs behave
unexpectedly. Consider vector<unsigned char>/bitset for alternatives.
*/
using namespace std;

// vector<bool> is a space-optimized specialization. Elements are proxy objects.
// Some operations you expect on bool& won't work with vector<bool>::reference.
static void printBits(const vector<bool>& vb) {
  for (bool b : vb) cout << (b ? '1' : '0');
  cout << '\n';
}

int main() {
  vector<bool> vb(5);
  vb[0] = true;
  vb[3] = true;
  printBits(vb);

  // Note: Taking the address of vb[0] is ill-formed (it's not a real bool&).
  // bool* ptr = &vb[0]; // would fail to compile

  return 0;
}


