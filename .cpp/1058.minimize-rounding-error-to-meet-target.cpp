/*
 * @lc app=leetcode id=1058 lang=cpp
 *
 * [1058] Minimize Rounding Error to Meet Target
 */

// @lc code=start
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        vector<int> int_part(n), dec_part(n);
        int sum_int = 0, sum_dec = 0;
        for (int i = 0; i < n; ++i) {
            int pos = prices[i].find('.');
            int_part[i] = stoi(prices[i].substr(0, pos));
            dec_part[i] = stoi(prices[i].substr(pos + 1));
            sum_int += int_part[i];
            sum_dec += dec_part[i];
        }
        if (target < sum_int || target > sum_int + n) {
            return "-1";
        }
        sort(dec_part.begin(), dec_part.end());
        int sum_selected = 0;
        for (int i = 0; i < target - sum_int; ++i) {
            sum_selected += dec_part[i];
        }
        int res = n - (target - sum_int) + 2 * sum_selected - sum_dec;
        stringstream ss;
        ss << res / 1000 << ".";
        ss << setw(3) << setfill('0') << res % 1000;
        return ss.str();
    }
};
// @lc code=end
