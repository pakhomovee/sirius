#include <iostream>
#include <string>
#include <algorithm>
/*
Enumerates permutations in lexicographic order using next_permutation.
Sort first to start from the smallest permutation.
*/
using namespace std;

int main() {
  string s = "abc";
  sort(s.begin(), s.end());
  do {
    cout << s << '\n';
  } while (next_permutation(s.begin(), s.end()));
  return 0;
}


