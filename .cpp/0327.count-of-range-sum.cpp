/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
// 1. 前缀和+归并排序
// 2025-02-20 submission
// 67/67 cases passed
// Runtime: 348 ms, faster than 56.43% of cpp online submissions.
// Memory Usage: 209.7 MB, less than % of cpp online submissions.
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return mergeSort(sums, 0, n, lower, upper);
    }

    int mergeSort(vector<long>& sums, int left, int right, int lower, int upper) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int count = mergeSort(sums, left, mid, lower, upper) +
                    mergeSort(sums, mid + 1, right, lower, upper);

        vector<long> cache(right - left + 1, 0);
        int j = mid + 1, k = mid + 1, t = mid + 1;
        for (int i = left, r = 0; i <= mid; ++i, ++r) {
            while (j <= right && sums[j] - sums[i] < lower) {
                ++j;
            }
            while (k <= right && sums[k] - sums[i] <= upper) {
                ++k;
            }
            while (t <= right && sums[t] < sums[i]) {
                cache[r++] = sums[t++];
            }
            cache[r] = sums[i];
            count += k - j;
        }
        copy(cache.begin(), cache.begin() + t - left, sums.begin() + left);
        return count;
    }
};
// @lc code=end

// @lc code=start
// 2. 前缀和+树状数组
// 2025-06-09 submission
// 67/67 cases passed
// Runtime: 1022 ms, faster than 22.35% of cpp online submissions.
// Memory Usage: 307.3 MB, less than 27.06% of cpp online submissions.
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        set<long> uniqueSums;
        for (long sum : sums) {
            uniqueSums.insert(sum - lower);
            uniqueSums.insert(sum);
            uniqueSums.insert(sum - upper);
        }

        unordered_map<long, int> indexMap;
        int index = 1;
        for (long sum : uniqueSums) {
            indexMap[sum] = index++;
        }

        int res = 0;
        vector<int> tree(index + 1, 0);
        for (long sum : sums) {
            int left = indexMap[sum - upper];
            int right = indexMap[sum - lower];
            res += query(tree, right) - query(tree, left - 1);
            update(tree, indexMap[sum], 1);
        }
        return res;
    }

private:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(vector<int>& tree, int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += lowbit(index);
        }
    }

    int query(vector<int>& tree, int index) {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= lowbit(index);
        }
        return res;
    }
};
// @lc code=end
// @lc code=end
