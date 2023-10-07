/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
// 2022-07-19 submission
// 92/92 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 50.82% of C++ online submissions.
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
            else if(s[i] == ')') {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            }
            else if(s[i] == ']') {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
            }
            else if(s[i] == '}') {
                if(!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-19 submission
// 92/92 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 95.98% of C++ online submissions.
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else {
                if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};
// @lc code=end