#include <iostream>
#include <vector>
#include <algorithm>
/*
unique removes consecutive duplicates; usually sort first then unique+erase
to get distinct elements. Common dedup idiom for vectors.
*/
using namespace std;

int main() {
  vector<int> a = {3, 1, 2, 2, 3, 1, 1};

  // unique on non-sorted data only removes consecutive duplicates
  vector<int> b = a;
  auto it1 = unique(b.begin(), b.end());
  b.erase(it1, b.end());
  for (int x : b) cout << x << ' ';
  cout << '\n';

  // canonical dedup: sort then unique+erase
  vector<int> v = a;
  sort(v.begin(), v.end());
  auto it2 = unique(v.begin(), v.end()); // requires sorted range
  v.erase(it2, v.end());
  for (int x : v) cout << x << ' ';
  cout << '\n';
  return 0;
}


