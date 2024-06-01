/*
 * @lc app=leetcode id=246 lang=cpp
 *
 * [246] Strobogrammatic Number
 */

// @lc code=start
// 1. 双指针
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            if (num[left] == num[right]) {
                if (num[left] != '0' && num[left] != '1' && num[left] != '8') {
                    return false;
                }
            }
            else if (!((num[left] == '6' && num[right] == '9') ||
                       (num[left] == '9' && num[right] == '6'))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 1. 双指针-优化
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};
// @lc code=end
