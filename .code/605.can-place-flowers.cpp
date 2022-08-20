/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (33.07%)
 * Likes:    3109
 * Dislikes: 675
 * Total Accepted:    314.4K
 * Total Submissions: 950.6K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule.
 * 
 * 
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 * 
 * 
 */

// @lc code=start
// 2022-08-19 submission
// 124/124 cases passed
// Runtime: 25 ms, faster than 64.34% of C++ online submissions.
// Memory Usage: 20.3 MB, less than 69.14% of C++ online submissions.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) return false;
        if (flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if (flowerbed.back() == 0) flowerbed.push_back(0);
        int len = flowerbed.size(), cnt = 0, sum = 0;
        for (int i = 0; i <= len; ++i) {
            if (i < len && flowerbed[i] == 0) ++cnt;
            else {
                sum += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        return sum >= n;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 124/124 cases passed
// Runtime: 29 ms, faster than 49.42% of C++ online submissions.
// Memory Usage: 20.4 MB, less than 22.03% of C++ online submissions.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (n == 0) return true;
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};
// @lc code=end