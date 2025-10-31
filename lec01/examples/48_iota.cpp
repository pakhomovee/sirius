#include <iostream>
#include <vector>
#include <numeric>
/*
Fills a range with consecutive values using iota(start). Useful for indexes,
IDs, and quick test data generation.
*/
using namespace std;

int main() {
  vector<int> v(5);
  iota(v.begin(), v.end(), 10); // 10,11,12,13,14
  for (int x : v) cout << x << ' ';
  cout << '\n';
  return 0;
}


