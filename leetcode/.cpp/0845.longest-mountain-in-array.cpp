/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
// 1. 两次遍历
// 2023-09-14 submission
// 75/75 cases passed
// Runtime: 20 ms, faster than 37.68% of cpp online submissions.
// Memory Usage: 19.9 MB, less than 8.14% of cpp online submissions.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 一次遍历
// 2023-09-14 submission
// 75/75 cases passed
// Runtime: 8 ms, faster than 96.89% of cpp online submissions.
// Memory Usage: 18.9 MB, less than 35.83% of cpp online submissions.
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int up = 0, down = 0;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                up = down = 0;
            }
            else if (arr[i] > arr[i - 1]) {
                if (down > 0) {
                    up = 1;
                    down = 0;
                }
                else {
                    up++;
                }
            }
            else {
                ++down;
            }
            if (up > 0 && down > 0) {
                ans = max(ans, up + down + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 3. 找山峰向两侧扩展
// 2023-09-14 submission
// 75/75 cases passed
// Runtime: 8 ms, faster than 96.89% of cpp online submissions.
// Memory Usage: 18.8 MB, less than 36.2% of cpp online submissions.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0, n = A.size();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
                int left = i - 1, right = i + 1;
                while (left > 0 && A[left - 1] < A[left]) --left;
                while (right < n - 1 && A[right] > A[right + 1]) ++right;
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};
// @lc code=end
