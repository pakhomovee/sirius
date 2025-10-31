#include <iostream>
#include <set>
#include <utility>
/*
set with custom comparator passed as second template parameter.
Defines ordering by second then first. Useful for tailored ordering.
*/
using namespace std;

struct BySecondThenFirst {
  bool operator()(const pair<int,int>& x, const pair<int,int>& y) const {
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
  }
};

int main() {
  set<pair<int,int>, BySecondThenFirst> st;
  st.insert({3, 10});
  st.insert({1, 20});
  st.insert({2, 20});
  for (auto [a,b] : st) cout << '(' << a << ',' << b << ") ";
  cout << '\n';
  return 0;
}


