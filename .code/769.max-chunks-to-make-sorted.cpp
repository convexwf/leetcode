/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted/description/
 *
 * algorithms
 * Medium (58.29%)
 * Likes:    2444
 * Dislikes: 212
 * Total Accepted:    87.4K
 * Total Submissions: 150K
 * Testcase Example:  '[4,3,2,1,0]'
 *
 * You are given an integer array arr of length n that represents a permutation
 * of the integers in the range [0, n - 1].
 *
 * We split arr into some number of chunks (i.e., partitions), and individually
 * sort each chunk. After concatenating them, the result should equal the
 * sorted array.
 *
 * Return the largest number of chunks we can make to sort the array.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [4,3,2,1,0]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1,
 * 2], which isn't sorted.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,0,2,3,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [1, 0], [2, 3, 4].
 * However, splitting into [1, 0], [2], [3], [4] is the highest number of
 * chunks possible.
 *
 *
 *
 * Constraints:
 *
 *
 * n == arr.length
 * 1 <= n <= 10
 * 0 <= arr[i] < n
 * All the elements of arr are unique.
 *
 *
 */

// @lc code=start
// 2023-02-22 submission
// 52/52 cases passed
// Runtime: 4 ms, faster than 29.59% of C++ online submissions.
// Memory Usage: 7.1 MB, less than 81.12% of C++ online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int last = -1, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > last) ++res;
            last = max(last, arr[i]);
        }
        return res;
    }
};
// @lc code=end