/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (46.73%)
 * Likes:    910
 * Dislikes: 306
 * Total Accepted:    65.9K
 * Total Submissions: 141K
 * Testcase Example:  '1'
 *
 * Given the API rand7() that generates a uniform random integer in the range
 * [1, 7], write a function rand10() that generates a uniform random integer in
 * the range [1, 10]. You can only call the API rand7(), and you shouldn't call
 * any other API. Please do not use a language's built-in random API.
 * 
 * Each test case will have one internal argument n, the number of times that
 * your implemented function rand10() will be called while testing. Note that
 * this is not an argument passed to rand10().
 * 
 * 
 * Example 1:
 * Input: n = 1
 * Output: [2]
 * Example 2:
 * Input: n = 2
 * Output: [2,8]
 * Example 3:
 * Input: n = 3
 * Output: [3,8,10]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 * 
 * 
 */

// @lc code=start
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 70 ms, faster than 78.6% of C++ online submissions.
// Memory Usage: 7.5 MB, less than 17.27% of C++ online submissions.
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num % 10 + 1;
        }
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 136 ms, faster than 6.83% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 17.27% of C++ online submissions.
class Solution {
public:
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        return (num <= 40) ? (num % 10 + 1) : rand10();
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 12/12 cases passed
// Runtime: 103 ms, faster than 37.05% of C++ online submissions.
// Memory Usage: 7.3 MB, less than 86.15% of C++ online submissions.
class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7(), b = rand7();
            int num = (a - 1) * 7 + b;
            if (num <= 40) return num % 10 + 1;
            a = num - 40, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 60) return num % 10 + 1;
            a = num - 60, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 20) return num % 10 + 1;
        }
    }
};
// @lc code=end