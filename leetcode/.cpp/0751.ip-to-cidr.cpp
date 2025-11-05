/*
 * @lc app=leetcode id=751 lang=cpp
 *
 * [751] IP to CIDR
 */

// @lc code=start
// 1. 位操作
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        unsigned int x = ip2int(ip);
        while (n > 0) {
            int lowbit = x & -x;
            int k = 32 - log2(lowbit);
            while ((1 << k) > n) {
                k--;
            }
            res.push_back(int2ip(x) + "/" + to_string(32 - k));
            x += 1 << k;
            n -= 1 << k;
        }
        return res;
    }

    unsigned int ip2int(string ip) {
        istringstream is(ip);
        string t;
        unsigned int x = 0;
        while (getline(is, t, '.')) {
            x = x * 256 + stoi(t);
        }
        return x;
    }

    string int2ip(unsigned int x) {
        return to_string(x >> 24) + "." + to_string(x >> 16 & 255) + "." + to_string(x >> 8 & 255) +
               "." + to_string(x & 255);
    }
};
// @lc code=end
