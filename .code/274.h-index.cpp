/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 *
 * https://leetcode.com/problems/h-index/description/
 *
 * algorithms
 * Medium (38.27%)
 * Likes:    1443
 * Dislikes: 2067
 * Total Accepted:    255.3K
 * Total Submissions: 667.2K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of integers citations where citations[i] is the number of
 * citations a researcher received for their i^th paper, return compute the
 * researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: A scientist has an
 * index h if h of their n papers have at least h citations each, and the other
 * n − h papers have no more than h citations each.
 *
 * If there are several possible values for h, the maximum one is taken as the
 * h-index.
 *
 *
 * Example 1:
 *
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining two with no more than 3 citations each, their h-index is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: citations = [1,3,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == citations.length
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
 *
 *
 */

// @lc code=start
// 2020-11-11 submission
// 81/81 cases passed
// Runtime: 3 ms, faster than 75.64% of C++ online submissions.
// Memory Usage: 8.5 MB, less than 98.33% of C++ online submissions.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h_idx = 1;
        for (; h_idx <= citations.size(); h_idx++) {
            if (h_idx > citations[h_idx-1]) break;
        }
        return h_idx - 1;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-30 submission
// 81/81 cases passed
// Runtime: 7 ms, faster than 33.44% of C++ online submissions.
// Memory Usage: 8.9 MB, less than 16.64% of C++ online submissions.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for(int c : citations) {
            if(c >= n) {
                buckets[n]++;
            } else {
                buckets[c]++;
            }
        }
        int count = 0;
        for(int i = n; i >= 0; i--) {
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end