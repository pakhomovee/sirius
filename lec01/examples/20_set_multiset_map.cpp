#include <iostream>
#include <set>
#include <map>
#include <string>
/*
Basics of set/multiset/map operations: find (O(log n)), multiset::count,
and careful erase of a single iterator. Shows map insertion via operator[]
and insert. Use tree containers for ordered data and range queries.
*/
using namespace std;

int main() {
  set<int> s = {3, 1, 4, 1, 5};
  auto it = s.find(3);
  if (it != s.end()) cout << "found 3\n";

  multiset<int> ms = {1, 2, 2, 2, 3};
  cout << "count(2)=" << ms.count(2) << '\n';
  auto it2 = ms.find(2); // O(log n)
  if (it2 != ms.end()) ms.erase(it2); // erase single

  map<string, int> mp;
  mp["alice"] = 10;        // inserts
  mp.insert({"bob", 20});  // inserts
  cout << mp["alice"] + mp["bob"] << '\n';
  return 0;
}


