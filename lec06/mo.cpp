#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int k = 475;

struct query {
    int l, r, i;
    query(int l, int r, int i): l(l), r(r), i(i) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    vector<int> vec = a;
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int& i : a) {
        i = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
    }
    vector<query> queries;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back(query(l - 1, r, i));
    }
    sort(queries.begin(), queries.end(), [](const query& lhs, const query& rhs) {
        if (lhs.l / k == rhs.l / k) {
            return lhs.r < rhs.r;
        }
        return lhs.l < rhs.l;
    });
    int L = 0, R = 0;
    vector<int> ans(q);
    vector<int> cnt(vec.size(), 0);
    int cnt_diff = 0;
    auto add = [&](int i) {
        if (cnt[a[i]]++ == 0) {
            ++cnt_diff;
        }
    };
    auto del = [&](int i) {
        if (--cnt[a[i]] == 0) {
            --cnt_diff;
        }
    };
    for (query q : queries) {
        while (L > q.l) {
            add(--L);
        }
        while (R < q.r) {
            add(R++);
        }
        while (L < q.l) {
            del(L++);
        }
        while (R > q.r) {
            del(--R);
        }
        ans[q.i] = cnt_diff;
    }
    for (int i : ans) {
        cout << i << '\n';
    }
}
