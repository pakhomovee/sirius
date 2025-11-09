#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

using namespace std;

const int maxn = 1 << 19;

struct SegmentTree {
    int tree[maxn * 2];
    int get(int l, int r) {
        l += maxn;
        r += maxn;
        int ans = 0;
        while (l < r) {
            if (l & 1) {
                ans += tree[l++];
            }
            if (r & 1) {
                ans += tree[--r];
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    void upd(int i, int value) {
        i += maxn;
        tree[i] += value;
        while (i > 1) {
            i >>= 1;
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    void init() {
        fill(tree, tree + maxn * 2, 0);
    }
};

struct query {
    int l, r, i;
    query(int l, int r, int i): l(l), r(r), i(i) {}
    query() {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    vector<int> xs, ys;
    for (auto [x, y] : points) {
        xs.push_back(x);
        ys.push_back(y);
    }
    int q;
    cin >> q;
    vector<array<int, 4>> queries;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xs.push_back(x1);
        xs.push_back(x2);
        ys.push_back(y1);
        ys.push_back(y2);
        queries.push_back({x1, y1, x2, y2});
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    vector<vector<query>> ql(xs.size() + 1);
    vector<vector<query>> qr(xs.size() + 1);
    for (auto& [x, y] : points) {
        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    }
    for (int i = 0; i < q; ++i) {
        auto [x1, y1, x2, y2] = queries[i];
        x1 = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
        y1 = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
        x2 = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();
        y2 = upper_bound(ys.begin(), ys.end(), y2) - ys.begin();
        ql[x1].push_back(query(y1, y2, i));
        qr[x2].push_back(query(y1, y2, i));
    }
    vector<vector<int>> y_by_x(xs.size() + 1);
    for (auto [x, y] : points) {
        y_by_x[x].push_back(y);
    }
    vector<int> ans(q, 0);
    SegmentTree st;
    st.init();
    for (int i = 0; i <= xs.size(); ++i) {
        for (query q : ql[i]) {
            ans[q.i] -= st.get(q.l, q.r);
        }
        for (int y : y_by_x[i]) {
            st.upd(y, 1);
        }
        for (query q : qr[i]) {
            ans[q.i] += st.get(q.l, q.r);
        }
    }
    for (int i : ans) {
        cout << i << '\n';
    }
}
