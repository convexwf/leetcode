/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
// 1. 归并排序
// 2023-10-03 submission
// 66/66 cases passed
// Runtime: 548 ms, faster than 49.76% of cpp online submissions.
// Memory Usage: 249.5 MB, less than 29.31% of cpp online submissions.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }
        mergeSort(pairs, 0, pairs.size() - 1, res);
        return res;
    }

    void mergeSort(vector<pair<int, int>>& pairs, int left, int right, vector<int>& res) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(pairs, left, mid, res);
        mergeSort(pairs, mid + 1, right, res);
        merge(pairs, left, mid, right, res);
    }

    void merge(vector<pair<int, int>>& pairs, int left, int mid, int right, vector<int>& res) {
        vector<pair<int, int>> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (pairs[i].first <= pairs[j].first) {
                res[pairs[i].second] += j - mid - 1;
                tmp[k++] = pairs[i++];
            }
            else {
                tmp[k++] = pairs[j++];
            }
        }
        while (i <= mid) {
            res[pairs[i].second] += j - mid - 1;
            tmp[k++] = pairs[i++];
        }
        while (j <= right) {
            tmp[k++] = pairs[j++];
        }
        for (int i = 0; i < tmp.size(); i++) {
            pairs[left + i] = tmp[i];
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+树状数组
// 2023-10-03 submission
// 66/66 cases passed
// Runtime: 231 ms, faster than 86.91% of cpp online submissions.
// Memory Usage: 87.1 MB, less than 93.92% of cpp online submissions.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> sortedNums(s.begin(), s.end());
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> m;
        for (int i = 0; i < sortedNums.size(); i++) {
            m[sortedNums[i]] = i + 1;
        }

        vector<int> res(nums.size());
        vector<int> tree(sortedNums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int index = m[nums[i]];
            res[i] = query(tree, index - 1);
            update(tree, index, 1);
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
