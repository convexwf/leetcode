/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
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
// 2025-02-20 submission
// 67/67 cases passed
// Runtime: 933 ms, faster than 26.57% of cpp online submissions.
// Memory Usage: 302.9 MB, less than 14.59% of cpp online submissions.
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        unordered_set<long> alls;
        for (long sum : sums) {
            alls.insert(sum);
            alls.insert(sum - lower);
            alls.insert(sum - upper);
        }
        vector<long> sortedSums(alls.begin(), alls.end());
        sort(sortedSums.begin(), sortedSums.end());

        unordered_map<long, int> m;
        for (int i = 0; i < sortedSums.size(); ++i) {
            m[sortedSums[i]] = i;
        }

        vector<int> tree(m.size() + 5, 0);
        int res = 0;
        for (int i = 0; i < sums.size(); ++i) {
            int left = m[sums[i] - upper], right = m[sums[i] - lower];
            res += query(tree, right + 1) - query(tree, left);
            update(tree, m[sums[i]], 1);
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

// @lc code=start
// 2025-02-20 submission
// 67/67 cases passed
// Runtime: 1000 ms, faster than 25.22% of cpp online submissions.
// Memory Usage: 313.7 MB, less than 14.01% of cpp online submissions.
#define ll long long
class Solution {
public:
    vector<int> tree;
    int n;
    int lowbits(int x) {
        return x & (-x);
    }
    void update(int x) {
        while (x <= n) {
            tree[x] += 1;
            x += lowbits(x);
        }
    }
    int query(int x) {
        int res = 0;
        while (x) {
            res += tree[x];
            x -= lowbits(x);
        }
        return res;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll sums = 0;
        vector<ll> preSum = {0};
        for (int x : nums) {
            sums += x;
            preSum.emplace_back(sums);
        }

        set<ll> st;
        for (auto x : preSum) {
            st.insert(x - lower);
            st.insert(x);
            st.insert(x - upper);
        }

        // 离散化
        unordered_map<ll, int> p;
        int c = 0;
        for (auto x : st) p[x] = c++;

        int res = 0;
        n = p.size();
        tree = vector<int>(n + 5, 0);
        // cout << n << endl;
        for (auto x : preSum) {
            int left = p[x - upper], right = p[x - lower];
            res += query(right + 1) - query(left);
            // cout << x << " " << right << " " << query(right+1) << " " << left << " " <<
            // query(left) << endl;
            update(p[x] + 1);
        }
        return res;
    }
};
// @lc code=end
