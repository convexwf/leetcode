/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (40.22%)
 * Likes:    4495
 * Dislikes: 310
 * Total Accepted:    272.7K
 * Total Submissions: 677.9K
 * Testcase Example:  '[1,0,2]'
 *
 * There are n children standing in a line. Each child is assigned a rating
 * value given in the integer array ratings.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 *
 * Return the minimum number of candies you need to have to distribute the
 * candies to the children.
 *
 *
 * Example 1:
 *
 *
 * Input: ratings = [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: ratings = [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two
 * conditions.
 *
 *
 *
 * Constraints:
 *
 *
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 *
 *
 */

// @lc code=start
// 2022-07-30 submission
// 48/48 cases passed
// Runtime: 37 ms, faster than 46.94% of C++ online submissions.
// Memory Usage: 17.7 MB, less than 59.74% of C++ online submissions.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) {
                nums[i + 1] = nums[i] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) {
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
            }
        }
        for (int num : nums) {
            res += num;
        }
        return res;
    }
};
// @lc code=end