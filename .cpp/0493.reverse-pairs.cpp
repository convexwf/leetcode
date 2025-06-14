/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
// 1. 归并排序
// 2025-06-09 submission
// 140/140 cases passed
// Runtime: 232 ms, faster than 82.87% of cpp online submissions.
// Memory Usage: 114.8 MB, less than 80.11% of cpp online submissions.
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        function<int(int, int)> mergeSort = [&](int left, int right) {
            if (left >= right) {
                return 0;
            }
            int mid = left + (right - left) / 2;
            int res = mergeSort(left, mid) + mergeSort(mid + 1, right);

            vector<int> cache(right - left + 1);
            int i = left, j = mid + 1, k = 0, p = mid + 1;
            while (i <= mid) {
                while (p <= right && nums[i] > 2LL * nums[p]) {
                    p++;
                }
                res += p - mid - 1;
                while (j <= right && nums[i] >= nums[j]) {
                    cache[k++] = nums[j++];
                }
                cache[k++] = nums[i++];
            }
            while (j <= right) {
                cache[k++] = nums[j++];
            }
            copy(cache.begin(), cache.begin() + k, nums.begin() + left);
            return res;
        };
        return mergeSort(0, nums.size() - 1);
    }
};
// @lc code=end

// @lc code=start
// 2. 树状数组
// 2025-06-09 submission
// 140/140 cases passed
// Runtime: 237 ms, faster than 82.26% of cpp online submissions.
// Memory Usage: 94.6 MB, less than 93.23% of cpp online submissions.
class Solution {
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

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        set<long> uniqueNums;
        for (int num : nums) {
            uniqueNums.insert(num);
            uniqueNums.insert(2L * num);
        }
        unordered_map<long, int> indexMap;
        int idx = 1;
        for (long num : uniqueNums) {
            indexMap[num] = idx++;
        }

        vector<int> tree(idx + 1, 0);
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            long num = nums[i];
            res += query(tree, indexMap[num] - 1);
            update(tree, indexMap[2L * num], 1);
        }
        return res;
    }
};
// @lc code=end
