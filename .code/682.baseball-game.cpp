/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 *
 * https://leetcode.com/problems/baseball-game/description/
 *
 * algorithms
 * Easy (73.49%)
 * Likes:    1822
 * Dislikes: 1694
 * Total Accepted:    209K
 * Total Submissions: 284.3K
 * Testcase Example:  '["5","2","C","D","+"]'
 *
 * You are keeping score for a baseball game with strange rules. The game
 * consists of several rounds, where the scores of past rounds may affect
 * future rounds' scores.
 *
 * At the beginning of the game, you start with an empty record. You are given
 * a list of strings ops, where ops[i] is the i^th operation you must apply to
 * the record and is one of the following:
 *
 *
 * An integer x - Record a new score of x.
 * "+" - Record a new score that is the sum of the previous two scores. It is
 * guaranteed there will always be two previous scores.
 * "D" - Record a new score that is double the previous score. It is guaranteed
 * there will always be a previous score.
 * "C" - Invalidate the previous score, removing it from the record. It is
 * guaranteed there will always be a previous score.
 *
 *
 * Return the sum of all the scores on the record. The test cases are generated
 * so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: ops = ["5","2","C","D","+"]
 * Output: 30
 * Explanation:
 * "5" - Add 5 to the record, record is now [5].
 * "2" - Add 2 to the record, record is now [5, 2].
 * "C" - Invalidate and remove the previous score, record is now [5].
 * "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
 * "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
 * The total sum is 5 + 10 + 15 = 30.
 *
 *
 * Example 2:
 *
 *
 * Input: ops = ["5","-2","4","C","D","9","+","+"]
 * Output: 27
 * Explanation:
 * "5" - Add 5 to the record, record is now [5].
 * "-2" - Add -2 to the record, record is now [5, -2].
 * "4" - Add 4 to the record, record is now [5, -2, 4].
 * "C" - Invalidate and remove the previous score, record is now [5, -2].
 * "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
 * "9" - Add 9 to the record, record is now [5, -2, -4, 9].
 * "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
 * "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
 * The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
 *
 *
 * Example 3:
 *
 *
 * Input: ops = ["1","C"]
 * Output: 0
 * Explanation:
 * "1" - Add 1 to the record, record is now [1].
 * "C" - Invalidate and remove the previous score, record is now [].
 * Since the record is empty, the total sum is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= ops.length <= 1000
 * ops[i] is "C", "D", "+", or a string representing an integer in the range
 * [-3 * 10^4, 3 * 10^4].
 * For operation "+", there will always be at least two previous scores on the
 * record.
 * For operations "C" and "D", there will always be at least one previous score
 * on the record.
 *
 *
 */

// @lc code=start
// 2022-08-20 submission
// 39/39 cases passed
// Runtime: 8 ms, faster than 44.66% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 99.8% of C++ online submissions.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vec;
        int sum = 0;
        for (string op : ops) {
            int n = vec.size();
            if (op == "+") {
                vec.push_back(vec[n - 1] + vec[n - 2]);
                sum += vec.back();
            }
            else if (op == "D") {
                vec.push_back(vec[n - 1] * 2);
                sum += vec.back();
            }
            else if (op == "C") {
                sum -= vec.back();
                vec.pop_back();
            }
            else {
                vec.push_back(stoi(op));
                sum += vec.back();
            }
        }
        return sum;
    }
};
// @lc code=end
