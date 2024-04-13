/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */

// @lc code=start
// 1. 排序+哈希表
// 2023-11-28 submission
// 36/36 cases passed
// Runtime: 8 ms, faster than 47.28% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 77.17% of cpp online submissions.
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for (auto& word : words) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) {
                    even += word[i];
                }
                else {
                    odd += word[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};
// @lc code=end
