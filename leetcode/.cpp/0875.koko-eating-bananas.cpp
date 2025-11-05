/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
// 1. 二分查找
// 2023-08-07 submission
// 125/125 cases passed
// Runtime: 31 ms, faster than 97.28% of cpp online submissions.
// Memory Usage:  MB, less than 38.69% of cpp online submissions.
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(vector<int>& piles, int speed, int h) {
        int time = 0;
        for (int n : piles) {
            time += (n - 1) / speed + 1;
        }
        return time <= h;
    }
};
// @lc code=end
