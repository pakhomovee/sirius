#include <iostream>
#include <vector>
#include <algorithm>
/*
Compares sort vs stable_sort and demonstrates comparator forms:
function, functor, and lambda. Ensure strict weak ordering and compare all
significant fields to avoid undefined behavior.
*/
using namespace std;

struct Item { int a; int b; };

bool cmpFn(const Item& x, const Item& y) {
  if (x.a != y.a) return x.a < y.a;
  return x.b < y.b;
}

struct CmpFunctor {
  bool operator()(const Item& x, const Item& y) const {
    if (x.b != y.b) return x.b < y.b;
    return x.a < y.a;
  }
};

int main() {
  vector<Item> v = {{2,3},{1,5},{1,2},{2,1}};

  vector<Item> v1 = v, v2 = v, v3 = v;

  sort(v1.begin(), v1.end(), cmpFn);
  sort(v2.begin(), v2.end(), CmpFunctor{});
  stable_sort(v3.begin(), v3.end(), [](const Item& x, const Item& y){
    return x.a < y.a;
  });

  auto print = [](const vector<Item>& t){ for (auto [a,b] : t) cout << '(' << a << ',' << b << ") "; cout << '\n'; };
  print(v1);
  print(v2);
  print(v3);
  return 0;
}


