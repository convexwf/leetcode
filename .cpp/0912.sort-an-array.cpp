/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
// 2023-02-19 submission (merge sort)
// 19/19 cases passed
// Runtime: 288 ms, faster than 41.08% of cpp online submissions.
// Memory Usage: 63.2 MB, less than 47.83% of cpp online submissions.
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
// merge sort
// 2025-02-20 submission
// 21/21 cases passed
// Runtime: 259 ms, faster than 49.3% of cpp online submissions.
// Memory Usage:  MB, less than 37.41% of cpp online submissions.
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
// 2023-02-18 submission (heap sort)
// 19/19 cases passed
// Runtime: 224 ms, faster than 52.41% of cpp online submissions.
// Memory Usage: 61.3 MB, less than 53.71% of cpp online submissions.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            siftDown(nums, n, i);
        }
        while (--n > 0) {
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
            if (child + 1 < n && nums[child] < nums[child + 1]) child = child + 1;
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
