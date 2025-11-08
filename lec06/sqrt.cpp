#include <iostream>
#include <vector>

using namespace std;

const int K = 475;
const int MAXN = 100057;

int a[MAXN];
long long sum[MAXN / K + 57];

void change(int i, int delta) {
    sum[i / K] += delta;
}

long long get(int l, int r) {
    if (l / K == r / K) {
        long long ans = 0;
        for (int i = l; i < r; ++i) {
            ans += a[i];
        }
        return ans;
    }
    long long ans = 0;
    while (l % K) {
        ans += a[l++];
    }
    while (r % K) {
        ans += a[--r];
    }
    for (int i = l / K; i < r / K; ++i) {
        ans += sum[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            --i;
            change(i, -a[i]);
            a[i] = x;
            change(i, a[i]);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(l - 1, r) << '\n';
        }
    }
}
