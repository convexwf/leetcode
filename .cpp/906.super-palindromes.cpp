/*
 * @lc app=leetcode id=906 lang=cpp
 *
 * [906] Super Palindromes
 */

// @lc code=start
// general solution
// TLE
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            dfs(to_string(i), left, right, ans);
        }
        dfs("", left, right, ans);
        return ans;
    }

    void dfs(string s, string& l, string& r, int& ans) {
        if (s.size() > r.size() / 2 + 1) return;
        if (!s.empty() && s[0] != '0' && s.size() >= l.size() / 2 + 1) {
            string ss = square(s);
            if (str_greater(r, ss) && str_greater(ss, l) && isPalindrome(ss)) ans++;
            // cout << s << " " << ss << " " << ans << endl;
        }
        for (int i = 0; i <= 9; i++) {
            string t = to_string(i) + s + to_string(i);
            dfs(t, l, r, ans);
        }
    }

private:
    bool str_greater(string& a, string& b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a >= b;
    }

    string square(string& s) {
        int n = s.size();
        string ans(n * 2, '0');
        for (int i = n - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int tmp = (s[i] - '0') * (s[j] - '0') + (ans[i + j + 1] - '0') + carry;
                ans[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            ans[i] += carry;
        }
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        return i == ans.size() ? "0" : ans.substr(i);
    }

    bool isPalindrome(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 枚举+数字计算
// 2023-07-14 submission
// 49/49 cases passed
// Runtime: 710 ms, faster than 34.61% of cpp online submissions.
// Memory Usage: 35.6 MB, less than 35.9% of cpp online submissions.
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int res = 0;
        long left = stol(L), right = stol(R);
        helper("", left, right, res);
        for (char c = '0'; c <= '9'; ++c) {
            helper(string(1, c), left, right, res);
        }
        return res;
    }
    void helper(string cur, long& left, long& right, int& res) {
        if (cur.size() > 9) return;
        if (!cur.empty() && cur[0] != '0') {
            long num = stol(cur);
            num *= num;
            if (num > right) return;
            if (num >= left && isPalindrome(to_string(num))) ++res;
        }
        for (char c = '0'; c <= '9'; ++c) {
            helper(string(1, c) + cur + string(1, c), left, right, res);
        }
    }
    bool isPalindrome(string str) {
        int left = 0, right = (int)str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
};
// @lc code=end
