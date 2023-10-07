/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
// 2020-11-20 submission
// 34/34 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.8 MB, less than 20.47% of C++ online submissions.
class Solution {
public:
    string decodeString(string s) {
        s = "1[" + s + "]";
        int len = s.length(), cur = 0;
        stack<int> nums;
        stack<string> stk;
        while(cur < len) {
            if (isdigit(s[cur])) {
                int tail = cur;
                while(isdigit(s[++tail]));
                nums.push(stoi(s.substr(cur, tail - cur)));
                cur = tail;
            }
            else if (s[cur] == ']') {
                string tmp = "", res = "";
                while (stk.top() != "[") {
                    tmp.insert(0, stk.top());
                    stk.pop();
                }
                for (int i = 0; i < nums.top(); i++)
                    res += tmp;
                nums.pop(); stk.pop();
                stk.push(res);
                cur++; // 不能够在判断语句 s[cur++] == ']'，这样即使不满足条件也会 cur++
            }
            else stk.push(string(1, s[cur++]));
        }
        return stk.top();
    }
};
// @lc code=end
