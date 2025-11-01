Examples for lecture 1 (C/C++)

Build (GNU++17 assumed):

- Single file:
```bash
g++ -std=gnu++17 -O2 -Wall -Wextra -pedantic examples/01_io_fast.cpp -o 01_io_fast
```

- With PBDS (GNU extensions):
```bash
g++ -std=gnu++17 -O2 -Wall -Wextra -pedantic examples/54_pbds_ordered_set.cpp -o 54_pbds_ordered_set
```

- With debug checks enabled:
```bash
g++ -std=gnu++17 -D_GLIBCXX_DEBUG -O0 -g examples/52_glibcxx_debug.cpp -o 52_glibcxx_debug
```

Run:
```bash
./01_io_fast < input.txt
```

Notes
- macOS/Clang may not ship PBDS; use GCC (e.g., via Homebrew) for PBDS and `<bits/stdc++.h>`.
- Files are small and independent; each demonstrates one idea.

Performance-oriented demos
- 05_hash_constexpr_benchmark.cpp — rolling-hash with constexpr p/mod vs runtime params
- 23_set_multiset_perf.cpp — multiset::count linear in duplicates; erase by iterator vs by value
- 24_map_erase_lower_bound.cpp — map erase by iterator; erase range using lower_bound
- 26_set_distance_linear.cpp — std::distance on set is linear; repeated to amplify time


