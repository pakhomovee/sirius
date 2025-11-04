#include <iostream>
#include <vector>

using namespace std;

string dec(string number) {
    int j = number.size() - 1;
    while (number[j] == '0') {
        --j;
    }
    --number[j];
    for (int k = j + 1; k < number.size(); ++k) {
        number[k] = '9';
    }
    return number;
}

template<int mod>
class ModInt {
public:
    ModInt() {}
    ModInt(int value): value_(value) {}

    int val() const {
        return value_;
    }

    ModInt operator-(const ModInt& other) const {
        if (value_ - other.value_ < 0) {
            return ModInt(value_ - other.value_ + mod);
        }
        return ModInt(value_ - other.value_);
    }

    ModInt& operator+=(const ModInt& other) {
        value_ = (value_ + other.value_) % mod;
        return *this;
    }
private:
    int value_ = 0;
};

typedef ModInt<1000000007> Int;

Int solve(string r) {
    Int dp[101][2][10] = {};
    for (int i = 0; i < r[0] - '0'; ++i) {
        dp[0][1][i] = 1;
    }
    dp[0][0][r[0] - '0'] = 1;
    for (int i = 1; i < r.size(); ++i) {
        for (int d = 0; d < 10; ++d) {
            for (int prev_d = 0; prev_d <= d; ++prev_d) {
                dp[i][1][d] += dp[i - 1][1][prev_d];
                if (d < r[i] - '0') {
                    dp[i][1][d] += dp[i - 1][0][prev_d];
                } else if (d == r[i] - '0') {
                    dp[i][0][d] += dp[i - 1][0][prev_d];
                }
            }
        }
    }
    Int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += dp[r.size() - 1][0][i];
        ans += dp[r.size() - 1][1][i];
    }
    return ans;
}

int main() {
    string l, r;
    cin >> l >> r;
    cout << (solve(r) - solve(dec(l))).val() << endl;
}
