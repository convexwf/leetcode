/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
// 1. 贪心算法
// 2023-10-06 submission
// 101/101 cases passed
// Runtime: 109 ms, faster than 42.42% of cpp online submissions.
// Memory Usage: 28.1 MB, less than 62.12% of cpp online submissions.
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> sub1 = maxSubArray(nums1, i);
            vector<int> sub2 = maxSubArray(nums2, k - i);
            vector<int> cur = merge(sub1, sub2);
            res = max(res, cur);
        }
        return res;
    }

private:
    vector<int> maxSubArray(vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        while (!nums1.empty() || !nums2.empty()) {
            vector<int>& tmp = (nums1 > nums2) ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
// @lc code=end
