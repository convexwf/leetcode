/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
// 2021-03-18 submission
// 39/39 cases passed
// Runtime: 120 ms, faster than 79.72% of cpp online submissions.
// Memory Usage: 47.2 MB, less than 45.41% of cpp online submissions.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() >= k) {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            else
                q.push(nums[i]);
        }
        return q.top();
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 39/39 cases passed
// Runtime: 253 ms, faster than 31.73% of cpp online submissions.
// Memory Usage: 45.4 MB, less than 88.84% of cpp online submissions.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
// @lc code=end
