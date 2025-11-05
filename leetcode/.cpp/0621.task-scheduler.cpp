/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
// 1. 哈希表+贪心算法
// 2023-12-28 submission
// 71/71 cases passed
// Runtime: 99 ms, faster than 21.66% of cpp online submissions.
// Memory Usage: 34.7 MB, less than % of cpp online submissions.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != count[0]) {
                break;
            }
            maxCount++;
        }
        return max((int)tasks.size(), (count[0] - 1) * (n + 1) + maxCount);
    }
};
// @lc code=end
