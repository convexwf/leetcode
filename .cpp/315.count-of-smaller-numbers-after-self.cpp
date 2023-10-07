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
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back({nums[i], i});
        }
        mergeSort(vec, 0, nums.size() - 1, res);
        return res;
    }

private:
    void mergeSort(vector<pair<int, int>>& vec, int left, int right, vector<int>& res) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid, res);
        mergeSort(vec, mid + 1, right, res);
        merge(vec, left, mid, right, res);
    }

    void merge(vector<pair<int, int>>& vec, int left, int mid, int right, vector<int>& res) {
        vector<pair<int, int>> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0, cnt = 0;
        while (i <= mid && j <= right) {
            if (vec[i].first <= vec[j].first) {
                res[vec[i].second] += cnt;
                tmp[k++] = vec[i++];
            }
            else {
                cnt++;
                tmp[k++] = vec[j++];
            }
        }
        while (i <= mid) {
            res[vec[i].second] += cnt;
            tmp[k++] = vec[i++];
        }
        while (j <= right) {
            tmp[k++] = vec[j++];
        }
        for (int p = 0; p < tmp.size(); ++p) {
            vec[left + p] = tmp[p];
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 树状数组
// 2023-10-03 submission
// 66/66 cases passed
// Runtime: 231 ms, faster than 86.91% of cpp online submissions.
// Memory Usage: 87.1 MB, less than 93.92% of cpp online submissions.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        vector<int> tree(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            int index =
                lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
            res[i] = query(tree, index);
            update(tree, index + 1, 1);
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
