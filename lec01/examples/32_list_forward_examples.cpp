#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
/*
std::list (bidirectional) and std::forward_list (forward) examples.
Shows insertion and erasing by iterator (list) and erase_after (forward_list).
*/
using namespace std;

int main() {
  // list: bidirectional, efficient insert/erase given iterator
  list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_front(0);
  auto it = find(lst.begin(), lst.end(), 1);
  if (it != lst.end()) it = lst.insert(it, 42); // insert before 1
  // erase the inserted 42 by iterator
  it = lst.erase(it); // returns iterator to element after erased (which is 1)
  for (int x : lst) cout << x << ' ';
  cout << '\n';

  // forward_list: singly-linked; erase uses erase_after
  forward_list<int> fl = {5, 6, 7, 8, 9};
  auto prev = fl.before_begin();
  for (auto cur = fl.begin(); cur != fl.end(); ) {
    if (*cur % 3 == 0) {
      cur = fl.erase_after(prev);
    } else {
      prev = cur++;
    }
  }
  for (int x : fl) cout << x << ' ';
  cout << '\n';
  return 0;
}


