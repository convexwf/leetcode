/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// 1. 位操作
// 2020-10-28 submission
// 58/58 cases passed
// Runtime: 220 ms, faster than 29.66% of cpp online submissions.
// Memory Usage: 61.4 MB, less than 34.96% of cpp online submissions.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k) {
                if ((k & bit) > 0) ++cnt1;
                if ((nums[k] & bit) > 0) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2024-10-11 submission
// 59/59 cases passed
// Runtime: 82 ms, faster than 52.41% of cpp online submissions.
// Memory Usage: 63.9 MB, less than 52.66% of cpp online submissions.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int& v : nums) {
                cnt += v <= mid;
            }
            if (cnt > mid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

// @lc code=start
// 3. 快慢指针
// 2020-10-28 submission
// 58/58 cases passed
// Runtime: 106 ms, faster than 93.04% of cpp online submissions.
// Memory Usage: 61.3 MB, less than 68.19% of cpp online submissions.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                while (true) {
                    slow = nums[slow];
                    t = nums[t];
                    if (slow == t) return slow;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
