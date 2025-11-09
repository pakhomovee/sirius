#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// avoid using int for T, because cross-product and dot-product may cause int overflow
// change T to the type you need, for example:
// using T = long double; if you need floating point arithmetics
using T = long long;

/*
Реализованы операторы ввода-вывода векторов (точек), а также операторы сложения/вычитания векторов,
умножения на вещественное число и скалярное/векторное произведения

*/

struct vec {
    T x, y;

    T len2() {
        return x * x + y * y;
    }

    long double len() {
        return sqrt((long double) x * x + y * y);
    }

};

ostream &operator<<(ostream &os, const vec &a) {
    return os << a.x << " " << a.y;
}

istream &operator>>(istream &in, vec &a) {
    return in >> a.x >> a.y;
}

vec operator+(const vec &a, const vec &b) {
    return {a.x + b.x, a.y + b.y};
}

vec operator-(const vec &a, const vec &b) {
    return {a.x - b.x, a.y - b.y};
}

T operator*(const vec &a, const vec &b) {
    return a.x * b.x + a.y * b.y;
}

vec operator*(const vec &a, const T &k) {
    return {a.x * k, a.y * k};
}

vec operator*(const T &k, const vec &a) {
    return {a.x * k, a.y * k};
}

T operator%(const vec &a, const vec &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    vec a, b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}
