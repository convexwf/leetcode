/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
// 2022-11-15 submission
// 206/206 cases passed
// Runtime: 637 ms, faster than 43.94% of C++ online submissions.
// Memory Usage: 116.1 MB, less than 50.03% of C++ online submissions.
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (int candy : candies) s.insert(candy);
        return min(s.size(), candies.size() / 2);
    }
};
// @lc code=end