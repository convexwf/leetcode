/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
// 2023-01-31 submission
// 49/49 cases passed
// Runtime: 210 ms, faster than 74.88% of C++ online submissions.
// Memory Usage: 79.1 MB, less than 43.32% of C++ online submissions.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end