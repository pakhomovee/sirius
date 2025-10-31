#include <iostream>
#include <string>
#include <algorithm>
/*
GCC extension __int128 for wide integer arithmetic and a helper to print it.
Use when 64-bit may overflow (e.g., big products); note: non-portable.
*/
using namespace std;

static void print_i128(__int128 x) {
  if (x == 0) { cout << 0; return; }
  if (x < 0) { cout << '-'; x = -x; }
  string s;
  while (x > 0) { s.push_back('0' + (int)(x % 10)); x /= 10; }
  reverse(s.begin(), s.end());
  cout << s;
}

int main() {
  __int128 a = (__int128)1e18; // 1e18 fits into 64-bit; demo multiply
  __int128 b = 123456789;
  __int128 c = a * b; // requires 128-bit to hold the product
  print_i128(c);
  cout << '\n';
  return 0;
}


