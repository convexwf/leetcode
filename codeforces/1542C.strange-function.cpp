#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

const ull MOD = 1e9 + 7;

inline ull _gcd(ull a, ull b) {
    while (b > 0) {
        ull temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

inline ull _lcm(ull a, ull b) {
    return (a / _gcd(a, b)) * b;
}

ull strange_function(ull n) {
    ull result = 0;

    ull factor = 1, contrib = 2;
    ull bucket_size = n;
    while (bucket_size > 0) {
        factor = _lcm(factor, contrib);
        ull satisfy = n / factor;
        result = (result + ((bucket_size - satisfy) % MOD) * (contrib % MOD)) % MOD;
        bucket_size = satisfy;
        contrib++;
    }

    return result;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    while (testcase_count--) {
        ull n;
        cin >> n;
        cout << strange_function(n) << "\n";
    }
}

// 1  2  3  4  5  6  7  8  9 10 11 12
// 2  3  2  3  2  4  2  3  2  3  2  5
