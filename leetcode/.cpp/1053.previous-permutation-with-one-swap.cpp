/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */

// @lc code=start
// 1. 贪心算法
// 2023-12-11 submission
// 54/54 cases passed
// Runtime: 20 ms, faster than 58.25% of cpp online submissions.
// Memory Usage: 25.1 MB, less than 21.13% of cpp online submissions.
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int index = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return arr;
        }
        for (int i = n - 1; i > index; --i) {
            if (arr[i] < arr[index] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[index]);
                break;
            }
        }
        return arr;
    }
};
// @lc code=end
