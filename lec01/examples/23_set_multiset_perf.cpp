#include <iostream>
#include <set>
#include <chrono>
/*
Demonstrates:
- multiset::count is linear in the number of equal elements (k)
- Erasing by value removes all equal elements at once; erasing by iterator removes one at a time

Notes
- Timings depend on your machine; increase N/REPEATS to ensure >1s if needed.
*/
using namespace std;
using clk = chrono::high_resolution_clock;

static multiset<int> generateMultisetDuplicates(size_t n, int a = 0, int b = 1) {
  multiset<int> ms;
  for (size_t i = 0; i < n / 2; ++i) ms.insert(a);
  for (size_t i = n / 2; i < n; ++i) ms.insert(b);
  return ms;
}

int main() {
  const size_t N = 200000;       // number of elements
  const int TARGET = 0;          // value with many duplicates
  const int REPEATS = 100;       // repeat to amplify timing

  {
    auto ms = generateMultisetDuplicates(N);
    auto t0 = clk::now();
    size_t total = 0;
    for (int i = 0; i < REPEATS * 10; ++i) {
      total += ms.count(TARGET); // O(log N + k), where k is number of TARGETs
    }
    auto t1 = clk::now();
    chrono::duration<double> dt = t1 - t0;
    cout << "multiset::count repeats=" << REPEATS << " total=" << total
         << " time=" << dt.count() << "s\n";
  }

  {
    // Erase by iterator: removes one by one
    auto ms = generateMultisetDuplicates(N, 5, 6);
    auto t0 = clk::now();
    size_t removed = 0;
    for (auto it = ms.lower_bound(5); it != ms.end() && *it == 5; ) {
      it = ms.erase(it); // O(log N) per erased element
      ++removed;
    }
    auto t1 = clk::now();
    chrono::duration<double> dt = t1 - t0;
    cout << "erase by iterator removed=" << removed << " time=" << dt.count() << "s\n";
  }

  {
    // Erase by value: removes all equal keys in one call
    auto ms = generateMultisetDuplicates(N, 5, 6);
    auto t0 = clk::now();
    size_t removed = ms.erase(5); // O(log N + k)
    auto t1 = clk::now();
    chrono::duration<double> dt = t1 - t0;
    cout << "erase by value removed=" << removed << " time=" << dt.count() << "s\n";
  }

  return 0;
}


