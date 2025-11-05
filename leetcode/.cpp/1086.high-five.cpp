/*
 * @lc app=leetcode id=1086 lang=cpp
 *
 * [1086] High Five
 */

// @lc code=start
// 1. 排序
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // Sort items by ID and then by score in descending order
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Sort by score in descending order
            }
            return a[0] < b[0]; // Sort by ID in ascending order
        });

        vector<vector<int>> result;
        int count = 0, sum = 0, prevID = -1;
        for (const vector<int>& item : items) {
            int id = item[0];
            int score = item[1];

            // If we encounter a new ID, reset count and sum
            if (id != prevID) {
                count = 0;
                sum = 0;
                prevID = id;
            }

            // Add the score to the sum and increment the count
            sum += score;
            count++;

            // If we have 5 scores, calculate the average and add to result
            if (count == 5) {
                result.push_back({id, sum / 5});
            }
        }
        return result;
    }
};
// @lc code=end
