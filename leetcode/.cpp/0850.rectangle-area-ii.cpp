/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start
// 1. 离散化+线扫描+线段树
// 2025-06-15 submission
// 78/78 cases passed
// Runtime: 4 ms, faster than 55.27% of cpp online submissions.
// Memory Usage: 13.6 MB, less than 40.51% of cpp online submissions.
struct SegmentTreeNode
{
    // 区间的左端点和右端点，均为闭区间
    int left, right;
    // 区间被完整覆盖的次数
    int count;
    // 区间实际被覆盖的长度
    int length;

    SegmentTreeNode() : left(0), right(0), count(0), length(0) {
    }
};

class SegmentTree {
private:
    vector<SegmentTreeNode*> tree;
    vector<int> nums;

public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size() - 1;
        tree.resize(4 * n);
        for (int i = 0; i < 4 * n; ++i) {
            tree[i] = new SegmentTreeNode();
        }
        build(1, 0, n - 1);
    }

    void build(int node, int start, int end) {
        tree[node]->left = start;
        tree[node]->right = end;
        tree[node]->count = 0;
        tree[node]->length = 0;

        if (start != end) {
            int mid = start + (end - start) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
        }
    }

    void update(int node, int start, int end, int value) {
        if (tree[node]->left >= start && tree[node]->right <= end) {
            tree[node]->count += value;
        }
        else {
            int mid = tree[node]->left + (tree[node]->right - tree[node]->left) / 2;
            if (start <= mid) {
                update(2 * node, start, end, value);
            }
            if (end > mid) {
                update(2 * node + 1, start, end, value);
            }
        }
        pushUp(node);
    }

    void pushUp(int node) {
        // 当前区间被完全覆盖
        if (tree[node]->count > 0) {
            tree[node]->length = nums[tree[node]->right + 1] - nums[tree[node]->left];
        }
        // 叶子节点且没有被覆盖
        else if (tree[node]->left == tree[node]->right) {
            tree[node]->length = 0;
        }
        // 非叶子节点，合并子节点
        else {
            tree[node]->length = tree[2 * node]->length + tree[2 * node + 1]->length;
        }
    }

    int query() {
        return tree[1]->length;
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        int n = rectangles.size();

        vector<vector<int>> segments(2 * n);
        set<int> uniqueY;
        for (int i = 0; i < n; ++i) {
            int x1 = rectangles[i][0], y1 = rectangles[i][1];
            int x2 = rectangles[i][2], y2 = rectangles[i][3];
            segments[i] = {x1, y1, y2, 1};      // left edge
            segments[i + n] = {x2, y1, y2, -1}; // right edge
            uniqueY.insert(y1);
            uniqueY.insert(y2);
        }
        sort(segments.begin(), segments.end());

        unordered_map<int, int> yIndex;
        int idx = 0;
        for (int y : uniqueY) {
            yIndex[y] = idx++;
        }
        vector<int> nums(uniqueY.begin(), uniqueY.end());
        SegmentTree* segTree = new SegmentTree(nums);

        long area = 0;
        for (int i = 0; i < segments.size(); ++i) {
            int x = segments[i][0];
            int y1 = segments[i][1];
            int y2 = segments[i][2];
            int type = segments[i][3];

            if (i > 0) {
                area += (long)(x - segments[i - 1][0]) * segTree->query();
                area %= MOD;
            }

            segTree->update(1, yIndex[y1], yIndex[y2] - 1, type);
        }
        return area;
    }
};
// @lc code=end
