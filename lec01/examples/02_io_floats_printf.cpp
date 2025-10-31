#include <cstdio>
/*
Shows formatting floating-point output with printf and precision specifiers
like %.3f / %.6f. Useful for exact control over formatting and speed.
*/

int main() {
  double x = 3.1415926535;
  std::printf("%.3f %.6f\n", x, x);
  return 0;
}


