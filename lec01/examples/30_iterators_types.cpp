#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <list>
#include <forward_list>
/*
Iterator categories demo: input iterator with istream_iterator to sum input,
output iterator with ostream_iterator to print, and random access indexing.
Use the right iterator category for algorithms and custom containers.
*/
using namespace std;

int main() {
  // input iterator example: read ints and sum
  istream_iterator<int> it(cin), end;
  long long sum = accumulate(it, end, 0LL);
  cout << sum << '\n';

  // output iterator example: write spaced values
  vector<int> v = {1, 2, 3};
  ostream_iterator<int> out(cout, " ");
  copy(v.begin(), v.end(), out);
  cout << '\n';

  // Random access iterator (vector): constant-time indexing and pointer-like ops
  cout << v[2] << '\n';                    // operator[] O(1)
  cout << (v.end() - v.begin()) << '\n';   // iterator subtraction O(1)

  // Bidirectional iterator (list): no random access; distance is linear
  list<int> lst = {10, 20, 30, 40};
  cout << distance(lst.begin(), lst.end()) << '\n'; // O(n)
  // ++ and -- allowed; but lst.end() - lst.begin() does not compile

  // Forward iterator (forward_list): only ++; erase uses erase_after
  forward_list<int> fl = {7, 8, 9, 10};
  auto prev = fl.before_begin();
  for (auto itf = fl.begin(); itf != fl.end(); ) {
    if (*itf % 2 == 0) {
      itf = fl.erase_after(prev); // remove even, returns next after erased
    } else {
      prev = itf++;
    }
  }
  for (int x : fl) cout << x << ' '; // prints odd elements
  cout << '\n';
  return 0;
}


