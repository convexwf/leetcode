/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
// 2022-11-14 submission
// 43/43 cases passed
// Runtime: 48 ms, faster than 37.56% of C++ online submissions.
// Memory Usage: 19.5 MB, less than 92.32% of C++ online submissions.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) candidate = nums[i];
            if (candidate == nums[i]) count++;
            else count--;
        }
        // 第二次遍历，可略去，因为题目已明确一定会存在结果
        // count = 0;
        // for (int num : nums) {
        //     if (num == candidate) ++count;
        // }
        // if (count <= (int)nums.size() / 2) return -1;
        return candidate;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 43/43 cases passed
// Runtime: 81 ms, faster than 5.67% of C++ online submissions.
// Memory Usage: 19.6 MB, less than 60.69% of C++ online submissions.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j]>>i) & 1);
            }
            if (count > nums.size() / 2) res |= (1 << i);
        }
        return res;
    }
};
// @lc code=end