/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
// 1. 数学规律
// 2023-06-08 submission
// 64/64 cases passed
// Runtime: 11 ms, faster than 41.63% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 22.49% of cpp online submissions.
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        nums[1] = 2;
        nums[2] = 2;
        int head = 2, tail = 3, num = 1, result = 1;
        while (tail < n) {
            for (int i = 0; i < nums[head]; ++i) {
                nums[tail] = num;
                if (num == 1 && tail < n) ++result;
                ++tail;
            }
            num ^= 3;
            ++head;
        }
        return result;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学规律+字符串
// 2023-06-08 submission
// 64/64 cases passed
// Runtime: 15 ms, faster than 16.27% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 62.2% of cpp online submissions.
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while (s.size() < n) {
            s += string(s[i++] - '0', s.back() ^ 3);
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};
// @lc code=end