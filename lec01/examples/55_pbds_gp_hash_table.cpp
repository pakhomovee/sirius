#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
  gp_hash_table<int, int> ht;
  ht[10] = 1;
  ht[20] = 2;
  cout << ht[10] + ht[20] << '\n';
  return 0;
}


