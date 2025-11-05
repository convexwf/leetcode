/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
// 1. 找规律
// 2023-10-12 submission
// 24/24 cases passed
// Runtime: 7 ms, faster than 97.75% of cpp online submissions.
// Memory Usage: 9.9 MB, less than 13.74% of cpp online submissions.
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        vector<int> nums(10, 0);
        nums[0] = count['z' - 'a'];
        nums[2] = count['w' - 'a'];
        nums[4] = count['u' - 'a'];
        nums[6] = count['x' - 'a'];
        nums[8] = count['g' - 'a'];
        nums[3] = count['h' - 'a'] - nums[8];
        nums[5] = count['f' - 'a'] - nums[4];
        nums[7] = count['s' - 'a'] - nums[6];
        nums[9] = count['i' - 'a'] - nums[5] - nums[6] - nums[8];
        nums[1] = count['o' - 'a'] - nums[0] - nums[2] - nums[4];
        string res;
        for (int i = 0; i < 10; i++) {
            res += string(nums[i], i + '0');
        }
        return res;
    }
};
// @lc code=end
