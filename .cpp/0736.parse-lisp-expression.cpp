/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 */

// @lc code=start
class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> m;
        return eval(expression, m);
    }

    int eval(string e, unordered_map<string, int>& m) {
        if (e[0] != '(') {
            if (isdigit(e[0]) || e[0] == '-') {
                return stoi(e);
            }
            return m[e];
        }
        unordered_map<string, int> t(m);
        int i = 1;
        string s = parse(e, i);
        if (s == "let") {
            while (true) {
                string var = parse(e, i);
                if (i > e.size()) return eval(var, t);
                string value = parse(e, i);
                t[var] = eval(value, t);
            }
        }
        else if (s == "add") {
            return eval(parse(e, i), t) + eval(parse(e, i), t);
        }
        else if (s == "mult") {
            return eval(parse(e, i), t) * eval(parse(e, i), t);
        }
        return 0;
    }

    string parse(string& e, int& i) {
        int j = i, n = e.size(), cnt = 0;
        while (i < n) {
            if (e[i] == '(') ++cnt;
            if (e[i] == ')') --cnt;
            if ((e[i] == ' ' && cnt == 0) || cnt == 0) break;
            ++i;
        }
        return e.substr(j, i - j++);
    }
};
// @lc code=end
