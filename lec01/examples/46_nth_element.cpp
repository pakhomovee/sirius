#include <iostream>
#include <vector>
#include <algorithm>
/*
nth_element partially reorders so that nth is the element in sorted order.
Average linear time; useful for k-th statistics like median without full sort.
*/
using namespace std;

int main() {
  vector<int> v = {9, 1, 5, 3, 7, 2};
  size_t k = v.size() / 2; // median index
  nth_element(v.begin(), v.begin() + k, v.end());
  cout << "median ~ " << v[k] << '\n';
  return 0;
}


