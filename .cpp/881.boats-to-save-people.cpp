/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
// 1. 双指针
// 2023-07-03 submission
// 78/78 cases passed
// Runtime: 89 ms, faster than 80.3% of cpp online submissions.
// Memory Usage: 41.8 MB, less than 99.8% of cpp online submissions.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ans = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
            }
            --right;
            ++ans;
        }
        return ans;
    }
};
// @lc code=end
