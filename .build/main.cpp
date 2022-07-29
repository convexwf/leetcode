#include "define.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        int carry = 0;
        int idx = res.length() - 1;
        for (int i = 0; i < m + n - 1; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j >= m || i - j >= n) continue;
                carry += (num1[(m - 1) - j] - '0') * (num2[(n - 1) - (i - j)] - '0');
            }
            cout << i << " " << carry << endl;
            if (carry > 0) {
                idx = res.length() - i - 1;
                res[idx] = carry % 10 + '0';
            }
            carry /= 10;
        }
        res[0] = carry + '0';
        return carry > 0 ? res : res.substr(idx);
    }
};

int main()
{
    Solution solution = Solution();
    cout << solution.multiply("123", "456") << endl;;
}
