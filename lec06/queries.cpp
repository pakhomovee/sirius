#include <iostream>
#include <vector>

using namespace std;

const int K = 475;
const int MAXN = 100057;

int a[MAXN];
long long pref[MAXN];
struct Query {
    char type;
    int l, r;
    Query(char type, int l, int r): type(type), l(l), r(r) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<Query> queries;
    for (int i = 0; i < q; ++i) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        queries.push_back(Query(c, l, r));
    }
    for (int i = 0; i < q; i += K) {
        fill(a, a + n, 0);
        for (int j = 0; j < i; ++j) {
            if (queries[j].type == 'A') {
                a[queries[j].l - 1] = queries[j].r;
            }
        }
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + a[i];
        }
        for (int j = 0; i + j < q && j < K; ++j) {
            if (queries[i + j].type == 'Q') {
                int l = queries[i + j].l;
                int r = queries[i + j].r;
                long long sum = pref[r] - pref[l - 1];
                vector<pair<int, int>> changes;
                for (int t = 0; t < j; ++t) {
                    if (queries[i + t].type == 'A') {
                        int ind = queries[i + t].l - 1;
                        int value = queries[i + t].r;
                        if (l - 1 <= ind && ind < r) {
                            changes.push_back({ind, a[ind]});
                            sum -= a[ind];
                            a[ind] = value;
                            sum += value;
                        }
                    }
                }
                cout << sum << '\n';
                reverse(changes.begin(), changes.end());
                for (auto [i, x] : changes) {
                    a[i] = x;
                }
            }
        }
    }
}
