#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*
lower_bound (first >= x), upper_bound (first > x) on sorted vectors and sets,
and binary_search for existence. Use bounds to find positions/ranges quickly.
*/
using namespace std;

int main() {
  vector<int> v = {1, 2, 2, 2, 3, 5};
  cout << *lower_bound(v.begin(), v.end(), 2) << '\n';    // first >= 2
  cout << *upper_bound(v.begin(), v.end(), 2) << '\n';    // first > 2
  cout << boolalpha << binary_search(v.begin(), v.end(), 4) << '\n';

  set<int> s = {1,2,4,5};
  auto it = s.lower_bound(3); // iterator to first >= 3
  if (it != s.end()) cout << *it << '\n';
  else cout << "end\n";
  return 0;
}


