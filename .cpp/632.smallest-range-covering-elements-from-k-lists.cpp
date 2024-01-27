/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
// 1. 排序+滑动窗口
// 2024-01-25 submission
// 90/90 cases passed
// Runtime: 27 ms, faster than 99.8% of cpp online submissions.
// Memory Usage: 21.3 MB, less than 20.43% of cpp online submissions.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> sorted;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                sorted.push_back({nums[i][j], i});
            }
        }
        sort(sorted.begin(), sorted.end());
        vector<int> count(nums.size(), 0);
        int countNum = 0;
        int left = 0, right = 0, minRange = INT_MAX;
        vector<int> res(2, 0);
        while (right < sorted.size()) {
            int arrayIndex = sorted[right].second;
            if (count[arrayIndex] == 0) {
                ++countNum;
            }
            ++count[arrayIndex];

            while (countNum == nums.size()) {
                --count[sorted[left].second];
                if (count[sorted[left].second] == 0) {
                    --countNum;
                    if (sorted[right].first - sorted[left].first < minRange) {
                        minRange = sorted[right].first - sorted[left].first;
                        res[0] = sorted[left].first;
                        res[1] = sorted[right].first;
                    }
                }
                ++left;
            }
            ++right;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 最小堆
// 2024-01-26 submission
// 90/90 cases passed
// Runtime: 84 ms, faster than 21.9% of cpp online submissions.
// Memory Usage: 27.1 MB, less than 5.02% of cpp online submissions.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int min_value = INT_MAX, max_value = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], i, 0});
            min_value = min(min_value, nums[i][0]);
            max_value = max(max_value, nums[i][0]);
        }
        vector<int> ans = {min_value, max_value};
        while (true) {
            auto t = pq.top();
            pq.pop();
            int array_index = t[1], index = t[2];
            if (index + 1 == nums[array_index].size()) {
                break;
            }
            pq.push({nums[i][j + 1], i, j + 1});
            min_value = pq.top()[0];
            max_value = max(max_value, nums[i][j + 1]);
            if (max_value - min_value < ans[1] - ans[0]) {
                ans = {min_value, max_value};
            }
        }
        return ans;
    }
};
// @lc code=end
