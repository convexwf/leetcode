/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */

// @lc code=start
// 1. 递归
// 2025-06-04 submission
// 77/77 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.4 MB, less than 47.08% of cpp online submissions.
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, res);
        return res;
    }

    void dfs(vector<int> nums, int start, int& res) {
        if (start >= nums.size()) {
            ++res;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            if (start == 0 || (start > 0 && isSquare(nums[start] + nums[start - 1]))) {
                dfs(nums, start + 1, res);
            }
        }
    }

    bool isSquare(int num) {
        int r = sqrt(num);
        return r * r == num;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+递归
// 2025-06-04 submission
// 77/77 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.3 MB, less than 58.77% of cpp online submissions.
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int, int> numCnt;
        unordered_map<int, unordered_set<int>> numMap;
        int res = 0, n = nums.size();
        for (int num : nums) {
            ++numCnt[num];
        }
        for (auto& a : numCnt) {
            for (auto& b : numCnt) {
                int x = a.first, y = b.first, r = sqrt(x + y);
                if (r * r == x + y) {
                    numMap[x].insert(y);
                }
            }
        }
        function<void(int, int)> dfs = [&](int x, int left) {
            if (left == 0) {
                ++res;
                return;
            }
            --numCnt[x];
            for (int y : numMap[x]) {
                if (numCnt[y] > 0) {
                    dfs(y, left - 1);
                }
            }
            ++numCnt[x];
        };
        for (auto& a : numCnt) {
            dfs(a.first, n - 1);
        }
        return res;
    }
};
// @lc code=end
