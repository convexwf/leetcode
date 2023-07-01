/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
// 1. 哈希表
// 2023-06-26 submission
// 137/137 cases passed
// Runtime: 79 ms, faster than 95.53% of cpp online submissions.
// Memory Usage:  MB, less than 34.16% of cpp online submissions.
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> dict;
        for (int i = 0; i < list1.size(); ++i) {
            dict[list1[i]] = i;
        }
        int min_sum = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (dict.count(list2[i])) {
                int sum = i + dict[list2[i]];
                if (sum < min_sum) {
                    min_sum = sum;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (sum == min_sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
