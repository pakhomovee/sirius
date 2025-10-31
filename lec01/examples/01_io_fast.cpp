#include <iostream>
/*
Demonstrates fast C++ I/O: ios::sync_with_stdio(false) and cin.tie(nullptr).
Use when reading/writing many numbers; avoid mixing C stdio (scanf/printf)
with iostreams after disabling sync. Typical in competitive programming.
*/
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  if (!(cin >> a >> b)) return 0;
  cout << (a + b) << '\n';
  return 0;
}


