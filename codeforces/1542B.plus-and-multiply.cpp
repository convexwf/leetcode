#include <iostream>
#include <vector>
#include <cmath>
#include <optional>

using namespace std;
using ll = long long;

inline ll _gcd(ll a, ll b) {
    while (b > 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/*
 Returns minimal non-negative k such that n - k*a is a multiple of b.
 If require_nonnegative_remainder==true, also requires n - k*a >= 0 (i.e. k <= n / a).
 If no solution exists under the chosen constraint, returns std::nullopt.

 Preconditions: b > 0, a >= 0, n can be any integer (but typical use n >= 0).
 Complexity: O(log(min(a,b))) for gcd/egcd operations.
*/
optional<ll> solve_linear_congruence(ll a, ll b, ll n, bool require_nonnegative_remainder) {
    ll g = _gcd(a, b);
    if (n % g != 0) {
        return nullopt;
    }

    a /= g;
    b /= g;
    n /= g;

    // Extended Euclidean Algorithm to find x,y such that a*x + b*y = 1
    ll x0 = 1, y0 = 0;
    ll x1 = 0, y1 = 1;
    ll aa = a, bb = b;
    while (bb != 0) {
        ll q = aa / bb;
        tie(x0, x1) = make_pair(x1, x0 - q * x1);
        tie(y0, y1) = make_pair(y1, y0 - q * y1);
        tie(aa, bb) = make_pair(bb, aa - q * bb);
    }

    ll x = x0 * n; // particular solution to a*x ≡ n (mod b)
    ll mod = b;

    // General solution: x + k*(b/g)
    ll k = ((-x % mod) + mod) % mod; // minimal non-negative solution

    if (require_nonnegative_remainder) {
        ll max_k = n / a;
        if (k > max_k) {
            return nullopt;
        }
    }

    return k;
}

bool solution(ll x, ll a, ll b) {
    if ((x - 1LL) % b == 0) {
        return true;
    }
    auto deleteCountOpt = solve_linear_congruence(b, a, x, true);
    if (!deleteCountOpt.has_value()) {
        return false;
    }
    ll deleteCount = deleteCountOpt.value();
    return solution(x - deleteCount * a, a, b) || (x - deleteCount * a == 1LL);
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    while (testcase_count--) {
        ll a, b, n;
        cin >> n >> a >> b;
        optional<ll> result = solve_linear_congruence(a, b, n, true);
        if (result.has_value()) {
            cout << result.value() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}
