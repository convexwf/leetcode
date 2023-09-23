/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */

// @lc code=start
// 1. 排序+双指针
// 2023-09-21 submission
// 72/72 cases passed
// Runtime: 237 ms, faster than 57.85% of cpp online submissions.
// Memory Usage: 10.8 MB, less than 32.8% of cpp online submissions.
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res = 0, n = A.size(), M = 1e9 + 7;
        sort(A.begin(), A.end());
        for (int i = 0; i < n - 2; ++i) {
            int sum = target - A[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (A[j] + A[k] < sum) {
                    ++j;
                }
                else if (A[j] + A[k] > sum) {
                    --k;
                }
                else {
                    int left = 1, right = 1;
                    while (j + left < k && A[j + left] == A[j]) ++left;
                    while (j + left <= k - right && A[k - right] == A[k]) ++right;
                    res += A[j] == A[k] ? (k - j + 1) * (k - j) / 2 : left * right;
                    j += left;
                    k -= right;
                }
            }
        }
        return res % M;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-09-22 submission
// 72/72 cases passed
// Runtime: 920 ms, faster than 19.73% of cpp online submissions.
// Memory Usage: 323.2 MB, less than 5.13% of cpp online submissions.
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), M = 1e9 + 7;
        vector<vector<vector<long>>> dp(n + 1,
                                        vector<vector<long>>(target + 1, vector<long>(4, 0)));
        for (int i = 0; i <= n; ++i) {
            dp[i][0][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k] % M;
                    if (j >= arr[i - 1]) {
                        dp[i][j][k] += dp[i - 1][j - arr[i - 1]][k - 1] % M;
                    }
                }
            }
        }
        return dp[n][target][3];
    }
};
// @lc code=end

// @lc code=start
// 3. 哈希表
// 2023-09-22 submission
// 72/72 cases passed
// Runtime: 8 ms, faster than 92.7% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 23.67% of cpp online submissions.
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res = 0, M = 1e9 + 7;
        unordered_map<int, long> numCnt;
        for (int num : A) ++numCnt[num];
        for (auto a : numCnt) {
            for (auto b : numCnt) {
                int i = a.first, j = b.first, k = target - i - j;
                if (!numCnt.count(k)) continue;
                if (i == j && j == k) {
                    res += numCnt[i] * (numCnt[i] - 1) * (numCnt[i] - 2) / 6;
                }
                else if (i == j && j != k) {
                    res += numCnt[i] * (numCnt[i] - 1) / 2 * numCnt[k];
                }
                else if (i < j && j < k) {
                    res += numCnt[i] * numCnt[j] * numCnt[k];
                }
            }
        }
        return res % M;
    }
};
// @lc code=end

// @lc code=start
// 4. 哈希表优化
// 2023-09-22 submission
// 72/72 cases passed
// Runtime: 629 ms, faster than 42.8% of cpp online submissions.
// Memory Usage: 11.1 MB, less than 20.71% of cpp online submissions.
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int res = 0, n = A.size(), M = 1e9 + 7;
        unordered_map<int, int> numCnt;
        for (int i = 0; i < n; ++i) {
            res = (res + numCnt[target - A[i]]) % M;
            for (int j = 0; j < i; ++j) {
                int sum = A[i] + A[j];
                ++numCnt[sum];
            }
        }
        return res;
    }
};
// @lc code=end
