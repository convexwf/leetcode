/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
// 插入排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
        return nums;
    }
};
// @lc code=end

// @lc code=start
// 冒泡排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bool isSorted = true;
            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    isSorted = false;
                }
            }
            if (isSorted) break;
        }
        return nums;
    }
};
// @lc code=end

// @lc code=start
// 选择排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }
            swap(nums[i], nums[minIdx]);
        }
        return nums;
    }
};
// @lc code=end

// @lc code=start
// 归并排序
// 2023-02-19 submission
// 21/21 cases passed
// Runtime: 249 ms, faster than 50.19% of cpp online submissions.
// Memory Usage: 147.9 MB, less than 36.02% of cpp online submissions.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();

        function<void(int, int)> mergeSort = [&](int left, int right) {
            if (left >= right) {
                return;
            }
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);

            vector<int> cache(right - left + 1);
            int t = mid + 1;
            for (int l = left, r = 0; l <= mid; ++l, ++r) {
                while (t <= right && nums[t] < nums[l]) {
                    cache[r++] = nums[t++];
                }
                cache[r] = nums[l];
            }
            copy(cache.begin(), cache.begin() + t - left, nums.begin() + left);
        };
        mergeSort(0, n - 1);
        return nums;
    }
};
// @lc code=end

// @lc code=start
// 堆排序
// 2023-02-18 submission
// 21/21 cases passed
// Runtime: 44 ms, faster than 75.22% of cpp online submissions.
// Memory Usage:  MB, less than 83.45% of cpp online submissions.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        // Build heap
        for (int i = n / 2 - 1; i >= 0; --i) {
            siftDown(nums, n, i);
        }
        // Heap sort
        for (int i = n - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
        return nums;
    }

    void siftDown(vector<int>& nums, int n, int i) {
        int parent = i;
        int child = 2 * parent + 1;
        int pval = nums[i];
        while (child < n) {
            if (child + 1 < n && nums[child] < nums[child + 1]) {
                child = child + 1;
            }
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
// 快速排序
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
