/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (51.60%)
 * Likes:    1096
 * Dislikes: 2039
 * Total Accepted:    118.2K
 * Total Submissions: 229.1K
 * Testcase Example:  '1'
 *
 * A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6
 * LEDs on the bottom to represent the minutes (0-59). Each LED represents a
 * zero or one, with the least significant bit on the right.
 * 
 * 
 * For example, the below binary watch reads "4:51".
 * 
 * 
 * 
 * 
 * Given an integer turnedOn which represents the number of LEDs that are
 * currently on (ignoring the PM), return all possible times the watch could
 * represent. You may return the answer in any order.
 * 
 * The hour must not contain a leading zero.
 * 
 * 
 * For example, "01:00" is not valid. It should be "1:00".
 * 
 * 
 * The minute must be consist of two digits and may contain a leading
 * zero.
 * 
 * 
 * For example, "10:2" is not valid. It should be "10:02".
 * 
 * 
 * 
 * Example 1:
 * Input: turnedOn = 1
 * Output:
 * ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 * Example 2:
 * Input: turnedOn = 9
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= turnedOn <= 10
 * 
 * 
 */

// @lc code=start
// 2022-11-15 submission
// 11/11 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 89.27% of C++ online submissions.
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};
// @lc code=end