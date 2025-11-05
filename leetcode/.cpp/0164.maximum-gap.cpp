/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
// 1. 桶排序
// 2023-02-02 submission
// 41/41 cases passed
// Runtime: 183 ms, faster than 94.15% of cpp online submissions.
// Memory Usage: 87 MB, less than 40.16% of cpp online submissions.
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        if (min_val == max_val) {
            return 0;
        }

        int n = nums.size();
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_num = (max_val - min_val) / bucket_size + 1;

        vector<pair<int, int>> buckets(bucket_num, {INT_MAX, INT_MIN});
        for (int num : nums) {
            int index = (num - min_val) / bucket_size;
            buckets[index].first = min(buckets[index].first, num);
            buckets[index].second = max(buckets[index].second, num);
        }

        int max_gap = 0;
        int prev_max = buckets[0].second;
        for (int i = 1; i < bucket_num; ++i) {
            if (buckets[i].first != INT_MAX) {
                max_gap = max(max_gap, buckets[i].first - prev_max);
                prev_max = buckets[i].second;
            }
        }
        return max_gap;
    }
};
// @lc code=end
