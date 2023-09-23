/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
// 1. 累计和数组
// 2023-09-18 submission
// 57/57 cases passed
// Runtime: 58 ms, faster than 97.96% of cpp online submissions.
// Memory Usage: 40.4 MB, less than 29.02% of cpp online submissions.
class Solution {
public:
    Solution(vector<int>& w) {
        sum = w;
        for (int i = 1; i < w.size(); ++i) {
            sum[i] += sum[i - 1];
        }
    }

    int pickIndex() {
        int target = rand() % sum.back() + 1;
        int left = 0, right = sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
