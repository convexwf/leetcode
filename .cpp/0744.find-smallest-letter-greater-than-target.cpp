/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
// 1. 二分查找
// 2023-08-24 submission
// 167/167 cases passed
// Runtime: 8 ms, faster than 92.56% of cpp online submissions.
// Memory Usage: 15.9 MB, less than 23.25% of cpp online submissions.
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return letters[left % letters.size()];
    }
};
// @lc code=end
