#include <iostream>
#include <set>
#include <utility>
/*
Safe erase while iterating a set: use it = s.erase(it) which returns next.
Also shows structured bindings in range-for for pairs. Avoid invalidating
iterators by following this pattern.
*/
using namespace std;

int main() {
  set<int> s = {1, 2, 3, 4, 5, 6};
  for (auto it = s.begin(); it != s.end();) {
    if (*it % 2 == 0) {
      it = s.erase(it); // returns next valid iterator
    } else {
      ++it;
    }
  }
  for (int x : s) cout << x << ' ';
  cout << '\n';

  set<pair<int, int>> sp = {{1, 10}, {2, 20}};
  for (auto [a, b] : sp) {
    cout << a << ':' << b << ' ';
  }
  cout << '\n';
  return 0;
}


