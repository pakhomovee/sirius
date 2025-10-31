#include <iostream>
#include <unordered_set>
#include <functional>
#include <utility>
#include <vector>
/*
unordered_set hashing variants: struct functor, free function (std::function),
and lambda (decltype + passing instance to constructor). All behave the same
as long as the hash is consistent with equality.
*/
using namespace std;

// 1) Struct functor
struct PairHashStruct {
  size_t operator()(const pair<int,int>& p) const {
    return hash<long long>{}((static_cast<long long>(p.first) << 32) ^ (p.second & 0xffffffffLL));
  }
};

// 2) Free function + std::function as Hash template parameter
static size_t pairHashFn(const pair<int,int>& p) {
  return hash<long long>{}((static_cast<long long>(p.first) << 32) ^ (p.second & 0xffffffffLL));
}

int main() {
  vector<pair<int,int>> data = {{1,2},{2,1},{1,2},{3,3},{0,0}};

  // Struct functor
  unordered_set<pair<int,int>, PairHashStruct> s_struct;

  // Free function via std::function
  using HashFn = function<size_t(const pair<int,int>&)>;
  unordered_set<pair<int,int>, HashFn> s_fn(0, HashFn(pairHashFn));

  // Lambda hasher: use decltype(lambda) as Hash type and pass instance
  auto hashLambda = [](const pair<int,int>& p) {
    return hash<long long>{}((static_cast<long long>(p.first) << 32) ^ (p.second & 0xffffffffLL));
  };
  using HashLambda = decltype(hashLambda);
  unordered_set<pair<int,int>, HashLambda> s_lambda(0, hashLambda);

  for (auto pr : data) {
    s_struct.insert(pr);
    s_fn.insert(pr);
    s_lambda.insert(pr);
  }

  cout << s_struct.size() << ' ' << s_fn.size() << ' ' << s_lambda.size() << '\n';
  cout << boolalpha
       << (s_struct.count({1,2}) == 1) << ' '
       << (s_fn.count({1,2}) == 1) << ' '
       << (s_lambda.count({1,2}) == 1) << '\n';
  return 0;
}


