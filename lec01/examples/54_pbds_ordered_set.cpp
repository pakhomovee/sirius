#include <iostream>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ordered_set<int> os;
  for (int x : {5, 1, 7, 3}) os.insert(x);

  cout << *os.find_by_order(1) << '\n';     // 2nd smallest (0-indexed)
  cout << os.order_of_key(6) << '\n';       // count of elements < 6
  return 0;
}


