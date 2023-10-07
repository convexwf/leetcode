/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
// 2023-01-14 submission
// 16/16 cases passed
// Runtime: 16 ms, faster than 42.8% of C++ online submissions.
// Memory Usage: 12 MB, less than 38.16% of C++ online submissions.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 16/16 cases passed
// Runtime: 12 ms, faster than 63.91% of C++ online submissions.
// Memory Usage: 11.9 MB, less than 62.48% of C++ online submissions.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 16/16 cases passed
// Runtime: 8 ms, faster than 83.1% of C++ online submissions.
// Memory Usage: 11.7 MB, less than 82.95% of C++ online submissions.
// Direct arrangement
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        int len = pow(2, n);
        for (int i = 1; i < len; ++i) {
            int pre = res.back();
            if (i % 2 == 1) {
                pre = (pre & (len - 2)) | ((~pre) & 1);
            } else {
                int cnt = 1, t = pre;
                while ((t & 1) != 1) {
                    ++cnt;
                    t >>= 1;
                }
                if ((pre & (1 << cnt)) == 0) pre |= (1 << cnt);
                else pre &= ~(1 << cnt);
            }
            res.push_back(pre);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 16/16 cases passed
// Runtime: 60 ms, faster than 12.7% of C++ online submissions.
// Memory Usage: 20.7 MB, less than 14.69% of C++ online submissions.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        unordered_set<int> s;
        stack<int> st;
        st.push(0);
        s.insert(0);
        while (!st.empty()) {
            int t = st.top(); st.pop();
            for (int i = 0; i < n; ++i) {
                int k = t;
                if ((k & (1 << i)) == 0) k |= (1 << i);
                else k &= ~(1 << i);
                if (s.count(k)) continue;
                s.insert(k);
                st.push(k);
                res.push_back(k);
                break;
            }
        }
        return res;
    }

    // 递归形式
    // vector<int> grayCode(int n) {
    //     vector<int> res;
    //     unordered_set<int> s;
    //     helper(n, s, 0, res);
    //     return res;
    // }
    // void helper(int n, unordered_set<int>& s, int out, vector<int>& res) {
    //     if (!s.count(out)) {
    //         s.insert(out);
    //         res.push_back(out);
    //     }
    //     for (int i = 0; i < n; ++i) {
    //         int t = out;
    //         if ((t & (1 << i)) == 0) t |= (1 << i);
    //         else t &= ~(1 << i);
    //         if (s.count(t)) continue;
    //         helper(n, s, t, res);
    //         break;
    //     }
    // }
};
// @lc code=end