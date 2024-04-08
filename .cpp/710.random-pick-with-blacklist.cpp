/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
// 2022-08-26 submission
// 68/68 cases passed
// Runtime: 276 ms, faster than 27.67% of cpp online submissions.
// Memory Usage: 71.9 MB, less than 20.93% of cpp online submissions.
class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        unordered_set<int> st;
        len = N - blacklist.size();
        for (int i = len; i < N; ++i) {
            st.insert(i);
        }
        for (int num : blacklist) {
            st.erase(num);
        }
        auto it = st.begin();
        for (int num : blacklist) {
            if (num < len) m[num] = *it++;
        }
    }

    int pick() {
        int k = rand() % len;
        return m.count(k) ? m[k] : k;
    }

private:
    unordered_map<int, int> m;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
