/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (29.93%)
 * Likes:    2517
 * Dislikes: 5674
 * Total Accepted:    335.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer num to its English words representation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
// 2023-01-14 submission
// 601/601 cases passed
// Runtime: 3 ms, faster than 81.91% of C++ online submissions.
// Memory Usage: 7.4 MB, less than 22.04% of C++ online submissions.
class Solution {
public:
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = (num % 1000 > 0) ? (convertHundred(num % 1000) + " " + v[i] + " " + res) : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};
// @lc code=end