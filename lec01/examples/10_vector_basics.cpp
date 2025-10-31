#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
/*
Demonstrates vector size vs capacity and operations:
reserve (capacity), resize (size + default init), assign (set size/fill),
shrink_to_fit. Use reserve to avoid reallocations in growth loops.
*/
using namespace std;

static void printMeta(const vector<int>& v, const string& label) {
  cout << left << setw(12) << label << " size=" << v.size() << " cap=" << v.capacity() << '\n';
}

int main() {
  vector<int> v;
  printMeta(v, "init");

  v.reserve(10);
  printMeta(v, "reserve 10");

  v.resize(5, 7);
  printMeta(v, "resize 5");

  v.assign(3, 1);
  printMeta(v, "assign 3x1");

  v.shrink_to_fit();
  printMeta(v, "shrink");

  return 0;
}


