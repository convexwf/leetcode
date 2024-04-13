/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */

// @lc code=start
// 1. 哈希表
// 2024-04-11 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 85.38% of cpp online submissions.
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }
            freq[i]--;
            if (checkTwoDiff(freq)) {
                return true;
            }
            freq[i]++;
        }
        return false;
    }

    // 判断数组中是否只有 0 和 X 两种数字，O(n) 复杂度
    // 如果全 0 也满足要求
    bool checkTwoDiff(vector<int>& nums) {
        int X = 0;
        for (int num : nums) {
            if (num == 0) {
                continue;
            }
            if (X == 0) {
                X = num;
            }
            else if (X != num) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
