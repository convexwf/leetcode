/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
// 2023-01-31 submission
// 56/56 cases passed
// Runtime: 6 ms, faster than 70.8% of cpp online submissions.
// Memory Usage: 10.8 MB, less than 23.38% of cpp online submissions.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int a : nums1) ++m[a];
        for (int a : nums2) {
            if (m[a]-- > 0) res.push_back(a);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 56/56 cases passed
// Runtime: 3 ms, faster than 94.57% of cpp online submissions.
// Memory Usage: 10.1 MB, less than 60.5% of cpp online submissions.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] > nums2[j]) {
                ++j;
            }
            else {
                ++i;
            }
        }
        return res;
    }
};
// @lc code=end
