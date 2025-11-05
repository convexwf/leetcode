/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
// 1. 快慢指针
// 2025-02-12 submission
// 45/45 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 37.21% of cpp online submissions.
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i, fast = next(nums, i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow == next(nums, slow)) {
                        break;
                    }
                    return true;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            slow = i;
            while (nums[slow] > 0) {
                int nextSlow = next(nums, slow);
                nums[slow] = 0;
                slow = nextSlow;
            }
        }
        return false;
    }

    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
};
// @lc code=end
