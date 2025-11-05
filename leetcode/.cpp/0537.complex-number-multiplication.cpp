/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start
// 1. 字符串处理
// 2023-06-14 submission
// 55/55 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 94.59% of cpp online submissions.
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        parse(num1, a1, b1);
        parse(num2, a2, b2);
        int a = a1 * a2 - b1 * b2;
        int b = a1 * b2 + a2 * b1;
        return to_string(a) + "+" + to_string(b) + "i";
    }

private:
    void parse(string& num, int& a, int& b) {
        int i = 0;
        while (num[i] != '+') ++i;
        a = stoi(num.substr(0, i));
        b = stoi(num.substr(i + 1, num.size() - i - 2));
    }
};
// @lc code=end

// @lc code=start
// 2. 字符串处理优化：find_last_of
// 2023-06-14 submission
// 55/55 cases passed
// Runtime: 3 ms, faster than 38.91% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 94.59% of cpp online submissions.
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        auto p1 = a.find_last_of("+"), p2 = b.find_last_of("+");
        int a1 = stoi(a.substr(0, p1)), b1 = stoi(b.substr(0, p2));
        int a2 = stoi(a.substr(p1 + 1, n1 - p1 - 2));
        int b2 = stoi(b.substr(p2 + 1, n2 - p2 - 2));
        int r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
// @lc code=end

// @lc code=start
// 3. 字符串处理优化：istringstream
// 2023-06-14 submission
// 55/55 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 94.59% of cpp online submissions.
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream is1(a), is2(b);
        int a1, a2, b1, b2, r1, r2;
        char plus;
        is1 >> a1 >> plus >> a2;
        is2 >> b1 >> plus >> b2;
        r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
// @lc code=end
