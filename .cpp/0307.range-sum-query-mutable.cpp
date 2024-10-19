/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
// 1. 树状数组
// 2024-10-18 submission
// 16/16 cases passed
// Runtime: 44 ms, faster than 100% of cpp online submissions.
// Memory Usage: 177.8 MB, less than 70.08% of cpp online submissions.
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) : tree(n + 1, 0) {
    }

    void update(int i, int delta) {
        while (i < tree.size()) {
            tree[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    vector<int> tree;

    int lowbit(int x) {
        return x & -x;
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), bit(n) {
        for (int i = 0; i < n; ++i) {
            bit.update(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        bit.update(index + 1, val - bit.query(index + 1) + bit.query(index));
    }

    int sumRange(int left, int right) {
        return bit.query(right + 1) - bit.query(left);
    }

private:
    int n;
    BinaryIndexedTree bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
