#include <iostream>
#include <vector>
#include <numeric>
/*
Demonstrates that vector<vector<int>> rows are separate allocations,
so the whole 2D grid is not one contiguous block. For a flat contiguous
matrix, use a single vector and index as row*ncols+col.
*/
using namespace std;

int main() {
  {
    vector<vector<int>> g(2, vector<int>(3));
    iota(g[0].begin(), g[0].end(), 10); // 10,11,12
    iota(g[1].begin(), g[1].end(), 20); // 20,21,22

    cout << &g[0][0] << ' ' << &g[0][1] << ' ' << &g[0][2] << '\n';
    cout << &g[1][0] << ' ' << &g[1][1] << ' ' << &g[1][2] << '\n';
    // Inner rows are separate allocations; overall 2D block is not contiguous
  }
  {
    int g[2][3];
    iota(g[0], g[0] + 3, 10); // 10,11,12
    iota(g[1], g[1] + 3, 20); // 20,21,22

    cout << &g[0][0] << ' ' << &g[0][1] << ' ' << &g[0][2] << '\n';
    cout << &g[1][0] << ' ' << &g[1][1] << ' ' << &g[1][2] << '\n';
  }
  return 0;
}


