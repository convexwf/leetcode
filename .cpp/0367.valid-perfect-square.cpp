/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
// 1. 穷举法
// 2020-09-22 submission
// 70/70 cases passed
// Runtime: 4 ms, faster than 20.34% of cpp online submissions.
// Memory Usage: 6 MB, less than 39.61% of cpp online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        for (int i = 2; i <= int(sqrt(num)); i++) {
            if (num % i == 0 && num / i == i) return true;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 43.85% of cpp online submissions.
// Memory Usage: 6 MB, less than 39.61% of cpp online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            if (t < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6 MB, less than 39.61% of cpp online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
// @lc code=end

// @lc code=start
// 4. 牛顿迭代法
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 43.85% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 39.61% of cpp online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};
// @lc code=end

// @lc code=start
// 5. Q_rsqrt 算法
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 5.9 MB, less than 39.61% of cpp online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int root = floorSqrt(num);
        return root * root == num;
    }

    int32_t floorSqrt(int32_t x) {
        double y = x;
        int64_t i = 0x5fe6eb50c7b537a9;
        y = *(double*)&(i = i - (*(int64_t*)&y) / 2);
        y = y * (3 - x * y * y) * 0.5;
        y = y * (3 - x * y * y) * 0.5;
        i = x * y + 1;
        return i - (i * i > x);
    }
};
// @lc code=end
