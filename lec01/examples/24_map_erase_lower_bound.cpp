#include <iostream>
#include <map>
#include <chrono>
#include <vector>
/*
Shows map erase by iterator and using lower_bound to erase a range.
Also useful to show that iterator-based erasure is safe while iterating.
*/
using namespace std;
using clk = chrono::high_resolution_clock;

static map<int,int> generateMap(size_t n) {
  map<int,int> mp;
  for (size_t i = 0; i < n; ++i) mp[(int)i] = (int)(i * 2);
  return mp;
}

int main() {
  const size_t N = 300000;
  {
    auto mp = generateMap(N);
    auto t0 = clk::now();
    // erase every 3rd key via iterator while iterating
    for (auto it = mp.begin(); it != mp.end(); ) {
      if (it->first % 3 == 0) it = mp.erase(it); else ++it;
    }
    auto t1 = clk::now();
    cout << "erase by iterator time=" << chrono::duration<double>(t1 - t0).count() << "s\n";
  }

  {
    auto mp = generateMap(N);
    auto t0 = clk::now();
    // erase all keys < threshold using lower_bound range
    int threshold = (int)(N / 2);
    auto itEnd = mp.lower_bound(threshold);
    mp.erase(mp.begin(), itEnd);
    auto t1 = clk::now();
    cout << "erase range [begin, lower_bound) time=" << chrono::duration<double>(t1 - t0).count() << "s\n";
  }

  {
    // Erase by lower_bound for a vector of queries: erase found iterator if not end
    auto mp = generateMap(N);
    vector<int> queries;
    queries.reserve(N / 2);
    for (size_t i = 0; i < N; i += 2) queries.push_back((int)i); // even keys exist

    auto t0 = clk::now();
    size_t erased = 0;
    for (int q : queries) {
      auto it = mp.lower_bound(q);
      if (it != mp.end()) { mp.erase(it); ++erased; }
    }
    auto t1 = clk::now();
    cout << "erase by lower_bound queries=" << queries.size()
         << " erased=" << erased
         << " time=" << chrono::duration<double>(t1 - t0).count() << "s\n";
  }

  return 0;
}


