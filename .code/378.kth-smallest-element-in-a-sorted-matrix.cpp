/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (61.74%)
 * Likes:    8700
 * Dislikes: 305
 * Total Accepted:    520.7K
 * Total Submissions: 843.3K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns is sorted in
 * ascending order, return the k^th smallest element in the matrix.
 * 
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 * 
 * You must find a solution with a memory complexity better than O(n^2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-decreasing order.
 * 1 <= k <= n^2
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve the problem with a constant memory (i.e., O(1) memory
 * complexity)?
 * Could you solve the problem in O(n) time complexity? The solution may be too
 * advanced for an interview but you may find reading this paper fun.
 * 
 * 
 */

// @lc code=start
// 2023-02-13 submission
// 86/86 cases passed
// Runtime: 25 ms, faster than 95.68% of C++ online submissions.
// Memory Usage: 13.2 MB, less than 83.43% of C++ online submissions.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                // 使用 upper_bound 函数可以查找第一个大于目标数的元素
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-13 submission
// 86/86 cases passed
// Runtime: 30 ms, faster than 86.6% of C++ online submissions.
// Memory Usage: 13.1 MB, less than 83.43% of C++ online submissions.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};
// @lc code=end