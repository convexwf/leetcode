/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
// 1. 枚举
// 2024-05-30 submission
// 601/601 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.5 MB, less than 56.93% of cpp online submissions.
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        unordered_map<int, string> num2str = {
            {1, "One"},      {2, "Two"},        {3, "Three"},     {4, "Four"},      {5, "Five"},
            {6, "Six"},      {7, "Seven"},      {8, "Eight"},     {9, "Nine"},      {10, "Ten"},
            {11, "Eleven"},  {12, "Twelve"},    {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
            {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"},
            {30, "Thirty"},  {40, "Forty"},     {50, "Fifty"},    {60, "Sixty"},    {70, "Seventy"},
            {80, "Eighty"},  {90, "Ninety"}};
        vector<string> units = {"", "Thousand ", "Million ", "Billion "};
        string res = "";
        for (int i = 0; num > 0; ++i) {
            int n = num % 1000;
            num /= 1000;
            if (n == 0) {
                continue;
            }
            string s = "";
            if (n / 100 > 0) {
                s += num2str[n / 100] + " Hundred ";
            }
            n %= 100;
            if (n > 0) {
                if (n <= 20) {
                    s += num2str[n] + " ";
                }
                else {
                    s += num2str[n / 10 * 10] + " ";
                    s += n % 10 > 0 ? num2str[n % 10] + " " : "";
                }
            }
            res = s + units[i] + res;
        }
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end
