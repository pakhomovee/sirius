#include <stdio.h>
/*
Reads a full line (including spaces) using fgets into a fixed buffer.
Useful when token-based scanf/cin would split on spaces. Note: buffer keeps
the trailing newline if present; strip it if needed.
*/

int main() {
  char buf[100];
  if (fgets(buf, sizeof(buf), stdin)) {
    printf("Got: %s", buf);
  }
  return 0;
}


