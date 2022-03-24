/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 *
 * https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
 *
 * algorithms
 * Easy (46.28%)
 * Likes:    638
 * Dislikes: 1631
 * Total Accepted:    98K
 * Total Submissions: 211.8K
 * Testcase Example:  '[1,0,0]'
 *
 * We have two special characters:
 * 
 * 
 * The first character can be represented by one bit 0.
 * The second character can be represented by two bits (10 or 11).
 * 
 * 
 * Given a binary array bits that ends with 0, return true if the last
 * character must be a one-bit character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: bits = [1,0,0]
 * Output: true
 * Explanation: The only way to decode it is two-bit character and one-bit
 * character.
 * So the last character is one-bit character.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bits = [1,1,1,0]
 * Output: false
 * Explanation: The only way to decode it is two-bit character and two-bit
 * character.
 * So the last character is not one-bit character.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= bits.length <= 1000
 * bits[i] is either 0 or 1.
 * 
 * 
 */

 // @lc solution=start
 解题思路
 
 1. 动态规划：从后往前看，最后一位必然有效，倒数第二位如果为 1 必然无效。从第三位开始，当前位为 1 时，说明其能够与后面一位组成有效字符，为 0 时肯定为有效字符。
 // @lc solution=end

// @lc code=start
// 2021-12-16 submission
// 93/93 cases passed
// Runtime: 3 ms, faster than 71.94% of C++ online submissions.
// Memory Usage: 9.7 MB, less than 65.33% of C++ online submissions.
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return true;

        int n = bits.size();
        vector<bool> dp(n, true);
        if (bits[n-2] == 1) dp[n-2] = false;
        for (int i = n-3; i >= 0; i--) {
            if (bits[i] == 1) dp[i] = dp[i+2];
            else dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
// @lc code=end

