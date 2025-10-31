#include <iostream>
#include <set>
#include <chrono>
#include <iomanip>
/*
Demonstrates that measuring distance across a set is linear time.
std::set iterators are bidirectional (not random access), so distance(begin,end)
walks the list of nodes. We repeat it many times to amplify runtime.
*/
using namespace std;
using clk = chrono::high_resolution_clock;

static set<int> generateSet(size_t n) {
  set<int> s;
  for (size_t i = 0; i < n; ++i) s.insert((int)i);
  return s;
}

static vector<int> generateVector(size_t n) {
  vector<int> v;
  for (size_t i = 0; i < n; ++i) v.push_back((int)i);
  return v;
}

int main() {
  {
    const size_t N = 300000; // size of set
    const int REPEATS = 10000; // repeat to make it slower
    auto s = generateSet(N);

    auto t0 = clk::now();
    volatile size_t sink = 0; // prevent optimization
    for (int i = 0; i < REPEATS; ++i) {
        sink += (size_t)distance(s.begin(), s.end()); // O(N)
    }
    auto t1 = clk::now();
    cout <<  fixed << setprecision(6) << "distance repeats=" << REPEATS << " total=" << sink
        << " time=" << chrono::duration<double>(t1 - t0).count() << "s\n";
  }
  {
    const size_t N = 300000; // size of set
    const int REPEATS = 10000; // repeat to make it slower
    auto s = generateVector(N);
    auto t0 = clk::now();
    volatile size_t sink = 0; // prevent optimization
    for (int i = 0; i < REPEATS; ++i) {
        sink += (size_t)distance(s.begin(), s.end()); // O(N)
    }
    auto t1 = clk::now();
    cout << fixed << setprecision(6) << "distance repeats=" << REPEATS << " total=" << sink
        << " time=" << chrono::duration<double>(t1 - t0).count() << "s\n";
  }
  return 0;
}


