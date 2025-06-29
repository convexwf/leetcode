/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// @lc code=start
// 1. 差分数组
// 2025-06-08 submission
// 44/44 cases passed
// Runtime: 6 ms, faster than 53.69% of cpp online submissions.
// Memory Usage: 78.4 MB, less than 50.34% of cpp online submissions.
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (i >= num) {
                diff[0]++;
                diff[i - num + 1]--;
                diff[i + 1]++;
                diff[n]--;
            }
            else {
                diff[i + 1]++;
                diff[i - num + 1 + n]--;
            }
        }

        int maxScore = 0, score = 0, bestK = 0;
        for (int k = 0; k < n; ++k) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        return bestK;
    }
};
// @lc code=end

// @lc code=start
// 2. 差分数组-改进
// 2025-06-04 submission
// 44/44 cases passed
// Runtime: 4 ms, faster than 71.97% of cpp online submissions.
// Memory Usage: 78.4 MB, less than 51.52% of cpp online submissions.
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++diff[l];
            --diff[r];
        }

        int maxScore = -1, score = 0, bestK = 0;
        for (int k = 0; k < n; ++k) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        return bestK;
    }
};
// @lc code=end
