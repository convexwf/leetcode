/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
// 1. 哈希集合
// 2023-06-29 submission
// 49/49 cases passed
// Runtime: 71 ms, faster than 31.29% of cpp online submissions.
// Memory Usage: 30.8 MB, less than 29.33% of cpp online submissions.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int dup = -1, missing = 1;
        for (int num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            }
            else {
                dup = num;
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (s.find(i) == s.end()) {
                missing = i;
            }
        }
        return {dup, missing};
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希集合+数学方法
// 2023-06-29 submission
// 49/49 cases passed
// Runtime: 79 ms, faster than 23.86% of cpp online submissions.
// Memory Usage: 30.8 MB, less than 29.33% of cpp online submissions.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int actualSum = 0;
        unordered_set<int> s;
        int duplicate = 0;
        for (int i = 0; i < n; ++i) {
            actualSum += nums[i];
            if (s.count(nums[i])) {
                duplicate = nums[i];
            }
            else {
                s.insert(nums[i]);
            }
        }
        return {duplicate, sum - actualSum + duplicate};
    }
};
// @lc code=end

// @lc code=start
// 3. 原地交换
// 2023-06-29 submission
// 49/49 cases passed
// Runtime: 28 ms, faster than 89.77% of cpp online submissions.
// Memory Usage: 21.2 MB, less than % of cpp online submissions.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }
        return {};
    }
};
// @lc code=end

// @lc code=start
// 4. 原地修改
// 2023-06-29 submission
// 49/49 cases passed
// Runtime: 29 ms, faster than 87.42% of cpp online submissions.
// Memory Usage: 21.4 MB, less than 75.36% of cpp online submissions.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2);
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                res[0] = index + 1;
            }
            else {
                nums[index] *= -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end