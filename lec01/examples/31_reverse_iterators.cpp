#include <iostream>
#include <vector>
/*
Reversing traversal using reverse iterators (rbegin/rend).
Useful for printing in reverse or reverse-order processing without copying.
*/
using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4};
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';
  return 0;
}


