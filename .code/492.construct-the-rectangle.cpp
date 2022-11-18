/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 *
 * https://leetcode.com/problems/construct-the-rectangle/description/
 *
 * algorithms
 * Easy (53.72%)
 * Likes:    497
 * Dislikes: 340
 * Total Accepted:    88.1K
 * Total Submissions: 164K
 * Testcase Example:  '4'
 *
 * A web developer needs to know how to design a web page's size. So, given a
 * specific rectangular web page’s area, your job by now is to design a
 * rectangular web page, whose length L and width W satisfy the following
 * requirements:
 * 
 * 
 * The area of the rectangular web page you designed must equal to the given
 * target area.
 * The width W should not be larger than the length L, which means L >= W.
 * The difference between length L and width W should be as small as
 * possible.
 * 
 * 
 * Return an array [L, W] where L and W are the length and width of the web
 * page you designed in sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: area = 4
 * Output: [2,2]
 * Explanation: The target area is 4, and all the possible ways to construct it
 * are [1,4], [2,2], [4,1]. 
 * But according to requirement 2, [1,4] is illegal; according to requirement
 * 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the
 * width W is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: area = 37
 * Output: [37,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: area = 122122
 * Output: [427,286]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= area <= 10^7
 * 
 * 
 */

// @lc code=start
// 2022-11-17 submission
// 52/52 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 90.96% of C++ online submissions.
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int W = (int)sqrt(area); W > 1; W--) {
            if (area % W == 0) {
                return {area / W, W};
            }
        }
        return {area, 1};
    }
};
// @lc code=end