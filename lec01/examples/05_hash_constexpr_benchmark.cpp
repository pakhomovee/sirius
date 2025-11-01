// Compare rolling-hash performance with const/constexpr p/mod vs non-const locals.
// Key point: when p and mod are compile-time constants, compilers can
// strength-reduce modulo and generate faster code than with runtime/unknown values.

#include <bits/stdc++.h>
using namespace std;

// Non-const locals (values supplied at runtime through argv) — compiler
// cannot treat 'mod' as a compile-time constant, so '%' uses general division.
static inline uint64_t hash_nonconst_locals(const string &s,
                                            uint64_t p,
                                            uint64_t mod) {
  uint64_t h = 0;
  for (unsigned char c : s) {
    h = (h * p + c) % mod;
  }
  return h;
}

// Compile-time-constant locals: enables strength reduction for division/modulo.
static inline uint64_t hash_constexpr_locals(const string &s) {
  constexpr uint64_t P = 911382323ull;
  constexpr uint64_t MOD = 972663749ull; // prime-like
  uint64_t h = 0;
  for (unsigned char c : s) {
    h = (h * P + c) % MOD;
  }
  return h;
}

static string make_test_data(size_t n) {
  string s;
  s.resize(n);
  // Pseudo-random but deterministic content to avoid trivial constant folding.
  uint64_t x = 123456789u;
  for (size_t i = 0; i < n; ++i) {
    x ^= x << 7;
    x ^= x >> 9;
    x *= 0x9E3779B185EBCA87ULL;
    s[i] = static_cast<char>('a' + (x % 26));
  }
  return s;
}

static inline long long ns_since(chrono::steady_clock::time_point t0) {
  return chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - t0).count();
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Defaults keep runtime reasonable; can be overridden via argv.
  // argv[1] = n, argv[2] = p (non-const path), argv[3] = mod (non-const path)
  size_t n = 10000000; // 1e7
  if (argc >= 2) n = static_cast<size_t>(stoull(argv[1]));
  uint64_t p_runtime = (argc >= 3 ? stoull(argv[2]) : 911382323ull);
  uint64_t mod_runtime = (argc >= 4 ? stoull(argv[3]) : 972663749ull);

  string s = make_test_data(n);

  // Warmup to stabilize caches/branch predictor.
  volatile uint64_t warm_sink = 0;
  warm_sink ^= hash_nonconst_locals(s, p_runtime, mod_runtime);
  warm_sink ^= hash_constexpr_locals(s);

  // Repeat a few rounds to reduce noise.
  int rounds = 4;
  long long t_nonconst_ns = 0;
  long long t_constexpr_ns = 0;
  uint64_t hr = 0, hc = 0;
  for (int r = 0; r < rounds; ++r) {
    auto t0 = chrono::steady_clock::now();
    hr ^= hash_nonconst_locals(s, p_runtime, mod_runtime);
    t_nonconst_ns += ns_since(t0);

    t0 = chrono::steady_clock::now();
    hc ^= hash_constexpr_locals(s);
    t_constexpr_ns += ns_since(t0);
  }

  // A tiny use of results to keep the compiler honest
  warm_sink ^= hr ^ hc;

  // Prevent dead-code elimination; also print timings.
  cout << "n=" << n << "\n";
  cout << "non-const locals (argv-sourced): hash=" << hr
       << ", time=" << (t_nonconst_ns / 1e6) << " ms (sum over " << rounds << ")\n";
  cout << "const/constexpr locals:          hash=" << hc
       << ", time=" << (t_constexpr_ns / 1e6) << " ms (sum over " << rounds << ")\n";
  cout << "speedup x~" << fixed << setprecision(2)
       << (double)t_nonconst_ns / max(1.0, (double)t_constexpr_ns) << "\n";

  return 0;
}


