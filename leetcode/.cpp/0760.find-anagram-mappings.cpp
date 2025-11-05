/*
 * @lc app=leetcode id=760 lang=cpp
 *
 * [760] Find Anagram Mappings
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    res.push_back(j);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
