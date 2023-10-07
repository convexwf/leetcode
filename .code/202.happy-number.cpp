/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
// 2022-11-14 submission
// 404/404 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 25.55% of C++ online submissions.
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (st.count(n)) break;
            st.insert(n);
        }
        return n == 1;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 404/404 cases passed
// Runtime: 4 ms, faster than 46.27% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 94.12% of C++ online submissions.
class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 404/404 cases passed
// Runtime: 4 ms, faster than 46.27% of C++ online submissions.
// Memory Usage: 5.8 MB, less than 94.12% of C++ online submissions.
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = findNext(slow);
            fast = findNext(fast);
            fast = findNext(fast);
            if (slow == fast) break;
        }
        return slow == 1;
    }
    int findNext(int n) {
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
// @lc code=end