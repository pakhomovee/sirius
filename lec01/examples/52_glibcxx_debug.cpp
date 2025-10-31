#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdexcept>
/*
Enable libstdc++ debug mode to catch bounds/iterator misuse at runtime.
Compile with -D_GLIBCXX_DEBUG. Slower: use for debugging, not for contests.
*/
using namespace std;

int main() {
  vector<int> v = {1, 2, 3};
  // With -D_GLIBCXX_DEBUG this out-of-bounds access aborts at runtime with a diagnostic
  v[10] = 3;
  return 0;
}


