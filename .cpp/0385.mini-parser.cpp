/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
// 1. 栈
// 2023-06-05 submission
// 58/58 cases passed
// Runtime: 12 ms, faster than 65.67% of cpp online submissions.
// Memory Usage: 11.9 MB, less than 78.36% of cpp online submissions.
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        NestedInteger res;
        int start = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                st.push(NestedInteger());
                start = i + 1;
            }
            else if (s[i] == ',' || s[i] == ']') {
                if (i > start) {
                    st.top().add(NestedInteger(stoi(s.substr(start, i - start))));
                }
                start = i + 1;
                if (s[i] == ']') {
                    if (!st.empty()) {
                        NestedInteger t = st.top();
                        st.pop();
                        if (!st.empty()) {
                            st.top().add(t);
                        }
                        else {
                            res = t;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-06-05 submission
// 58/58 cases passed
// Runtime: 3 ms, faster than 100% of cpp online submissions.
// Memory Usage: 12.2 MB, less than 55.97% of cpp online submissions.
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size() <= 2) return NestedInteger();
        NestedInteger res;
        int start = 1, cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
                res.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            }
            else if (s[i] == '[')
                ++cnt;
            else if (s[i] == ']')
                --cnt;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 递归+istringstream
// 2023-06-05 submission
// 58/58 cases passed
// Runtime: 8 ms, faster than 85.82% of cpp online submissions.
// Memory Usage:  MB, less than 78.36% of cpp online submissions.
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }
    NestedInteger deserialize(istringstream& in) {
        int num;
        if (in >> num) return NestedInteger(num);
        in.clear();
        in.get();
        NestedInteger list;
        while (in.peek() != ']') {
            list.add(deserialize(in));
            if (in.peek() == ',') {
                in.get();
            }
        }
        in.get();
        return list;
    }
};
// @lc code=end