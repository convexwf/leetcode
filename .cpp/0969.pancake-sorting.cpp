/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
// 1. 贪心算法
// 2025-02-28 submission
// 215/215 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 14.1 MB, less than 76.22% of cpp online submissions.
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int number = n; number > 0; number--) {
            if (arr[number - 1] == number) continue;
            int pivot = number - 1;
            while (arr[pivot] != number) pivot--;
            if (pivot != 0) {
                res.push_back(pivot + 1);
                reverse(arr.begin(), arr.begin() + pivot + 1);
            }
            res.push_back(number);
            reverse(arr.begin(), arr.begin() + number);
        }
        return res;
    }
};
// @lc code=end
