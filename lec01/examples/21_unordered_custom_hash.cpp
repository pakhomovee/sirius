#include <iostream>
#include <unordered_set>
#include <utility>
#include <functional>
/*
unordered_set with a custom hash for pair<int,int>. Hash must be consistent
with equality: equal keys must hash equal. Average O(1) lookups; good for
fast membership tests without ordering.
*/
using namespace std;

struct PairHash {
  size_t operator()(const pair<int, int>& p) const {
    // Simple hash combine
    return std::hash<long long>{}((static_cast<long long>(p.first) << 32) ^ (p.second & 0xffffffffLL));
  }
};

int main() {
  unordered_set<pair<int, int>, PairHash> us;
  us.insert({1, 2});
  us.insert({1, 2}); // duplicate, ignored
  us.insert({2, 1});

  cout << us.size() << '\n';
  cout << (us.count({1, 2}) ? "yes" : "no") << '\n';
  return 0;
}


