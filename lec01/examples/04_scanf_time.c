#include <stdio.h>
/*
Parses time formatted as "HH:MM" with scanf("%d:%d", &h, &m).
Always check the return value (should be 2). Handy for structured tokens.
*/

int main() {
  int h, m;
  if (scanf("%d:%d", &h, &m) == 2) {
    printf("%d\n", h * 60 + m);
  }
  return 0;
}


