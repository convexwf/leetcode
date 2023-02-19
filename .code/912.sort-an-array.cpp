/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (58.47%)
 * Likes:    3296
 * Dislikes: 605
 * Total Accepted:    358.1K
 * Total Submissions: 612.9K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order and
 * return it.
 *
 * You must solve the problem without using any built-in functions in
 * O(nlog(n)) time complexity and with the smallest space complexity
 * possible.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Explanation: After sorting the array, the positions of some numbers are not
 * changed (for example, 2 and 3), while the positions of other numbers are
 * changed (for example, 1 and 5).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * Explanation: Note that the values of nums are not necessairly unique.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start
// 2023-02-19 submission (merge sort)
// 19/19 cases passed
// Runtime: 288 ms, faster than 41.08% of C++ online submissions.
// Memory Usage: 63.2 MB, less than 47.83% of C++ online submissions.
class Solution {
public:
    vector<int> vec;

    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vec.resize(n);
        mergeSort(nums, 0, n - 1);
        return vec;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        int lp = l, rp = mid + 1, idx = l;
        while (lp <= mid && rp <= r) {
            if (nums[lp] <= nums[rp]) {
                vec[idx++] = nums[lp++];
            }
            else {
                vec[idx++] = nums[rp++];
            }
        }
        while (lp <= mid) vec[idx++] = nums[lp++];
        while (rp <= r) vec[idx++] = nums[rp++];
        for (int i = l; i <= r; i++) {
            nums[i] = vec[i];
        }
    }
};
// @lc code=end

// @lc code=start
// 2023-02-18 submission (heap sort)
// 19/19 cases passed
// Runtime: 224 ms, faster than 52.41% of C++ online submissions.
// Memory Usage: 61.3 MB, less than 53.71% of C++ online submissions.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            siftDown(nums, n, i);
        }
        while(--n > 0) {
            swap(nums[0], nums[n]);
            siftDown(nums, n, 0);
        }
        return nums;
    }

    void siftDown(vector<int>& nums, int n, int i) {
        int parent = i;
        int child = 2 * parent + 1;
        int pval = nums[i];
        while (child < n) {
            if (child + 1 < n && nums[child] < nums[child + 1])
                child = child + 1;
            if (pval > nums[child]) break;
            nums[parent] = nums[child];
            parent = child;
            child = 2 * parent + 1;
        }
        nums[parent] = pval;
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, r);
    }

    int partition(vector<int>& nums, int s, int e) {
        if (s >= e) return s;

        // avoid TLE
        // 折半选择基准点
        int key = s + (e - s) / 2;
        swap(nums[key], nums[e]);

        int i = s - 1;
        for (int j = s; j < e; ++j) {
            if (nums[j] <= nums[e]) {
                ++i;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[++i], nums[e]);
        return i;
    }
};
// @lc code=end
