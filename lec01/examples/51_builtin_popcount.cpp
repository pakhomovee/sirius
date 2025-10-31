#include <iostream>
/*
Bit population count builtins: __builtin_popcount (unsigned int) and
__builtin_popcountll (unsigned long long). Choose the correct suffix
for the input type width.

Also demonstrates:
- __builtin_clz / __builtin_clzll: count leading zeros (undefined if x == 0)
- __builtin_ctz / __builtin_ctzll: count trailing zeros (undefined if x == 0)
*/
using namespace std;

int main() {
  unsigned int x = 0b10110100u; // 4 bits set
  cout << "popcount(x)=" << __builtin_popcount(x) << '\n';
  cout << "clz(x)=" << __builtin_clz(x) << " (undefined if x==0)" << '\n';
  cout << "ctz(x)=" << __builtin_ctz(x) << " (undefined if x==0)" << '\n';

  unsigned long long y = 0xFFFFFFFFFFFFFFFFull; // 64 ones
  cout << "popcountll(y)=" << __builtin_popcountll(y) << '\n';
  cout << "clzll(y)=" << __builtin_clzll(y) << " (undefined if y==0)" << '\n';
  cout << "ctzll(y)=" << __builtin_ctzll(y) << " (undefined if y==0)" << '\n';
  return 0;
}


