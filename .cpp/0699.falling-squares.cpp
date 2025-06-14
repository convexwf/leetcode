/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 */

// @lc code=start
// 1. 线段树
// 2025-02-18 submission
// 48/48 cases passed
// Runtime: 465 ms, faster than 5.12% of cpp online submissions.
// Memory Usage: 299.9 MB, less than 5.12% of cpp online submissions.
struct SegmentTreeNode
{
    int start, end, mid;
    int value;
    int lazy;
    std::shared_ptr<SegmentTreeNode> left, right;

    SegmentTreeNode(int start, int end, int value) : start(start), end(end), value(value) {
        lazy = 0;
        mid = start + (end - start) / 2;
    }
};

class SegmentTree {
private:
    std::shared_ptr<SegmentTreeNode> root;

    void push_down(std::shared_ptr<SegmentTreeNode> node) {
        if (!node->left) {
            node->left = std::make_shared<SegmentTreeNode>(node->start, node->mid, 0);
        }
        if (!node->right) {
            node->right = std::make_shared<SegmentTreeNode>(node->mid + 1, node->end, 0);
        }
        if (node->lazy != 0) {
            node->left->value = node->lazy;
            node->left->lazy = node->lazy;
            node->right->value = node->lazy;
            node->right->lazy = node->lazy;
            node->lazy = 0;
        }
    }

    int query(std::shared_ptr<SegmentTreeNode> node, int ql, int qr) {
        if (ql > qr) {
            return 0;
        }
        if (ql <= node->start && node->end <= qr) {
            return node->value;
        }
        push_down(node);

        int result = 0;
        if (ql <= node->mid) {
            result = std::max(result, query(node->left, ql, qr));
        }
        if (qr > node->mid) {
            result = std::max(result, query(node->right, ql, qr));
        }
        return result;
    }

    void update(std::shared_ptr<SegmentTreeNode> node, int ql, int qr, int value) {
        if (ql > qr) {
            return;
        }
        if (ql <= node->start && node->end <= qr) {
            node->value = value;
            node->lazy = value;
            return;
        }
        push_down(node);
        if (ql <= node->mid) {
            update(node->left, ql, qr, value);
        }
        if (qr > node->mid) {
            update(node->right, ql, qr, value);
        }
        node->value = std::max(node->left->value, node->right->value);
    }

public:
    SegmentTree(int start, int end) {
        root = make_unique<SegmentTreeNode>(start, end, 0);
    }

    int query(int ql, int qr) {
        return query(root, ql, qr);
    }

    void update(int ql, int qr, int value) {
        update(root, ql, qr, value);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        std::unique_ptr<SegmentTree> tree = std::make_unique<SegmentTree>(0, 1e8);
        vector<int> result;
        int maxHeight = 0;
        for (const vector<int>& position : positions) {
            int left = position[0];
            int right = position[0] + position[1] - 1;
            int height = position[1] + tree->query(left, right);
            tree->update(left, right, height);
            maxHeight = std::max(maxHeight, height);
            result.push_back(maxHeight);
        }
        return result;
    }
};
// @lc code=end

// @lc code=start
// 2. 有序字典
// 2025-06-09 submission
// 48/48 cases passed
// Runtime: 15 ms, faster than 100% of cpp online submissions.
// Memory Usage: 19.3 MB, less than 29.29% of cpp online submissions.
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> res;
        map<pair<int, int>, int> m;
        int maxHeight = 0;
        for (const vector<int>& position : positions) {
            int left = position[0], len = position[1];
            int right = left + len;
            auto it = m.upper_bound({left, left});
            if (it != m.begin() && (--it)->first.second <= left) {
                ++it;
            }

            int height = 0;
            vector<vector<int>> toAdd;
            while (it != m.end() && it->first.first < right) {
                if (left > it->first.first) {
                    toAdd.push_back({it->first.first, left, it->second});
                }
                if (right < it->first.second) {
                    toAdd.push_back({right, it->first.second, it->second});
                }
                height = max(height, it->second);
                it = m.erase(it);
            }
            m[{left, right}] = height + len;
            for (const vector<int>& a : toAdd) {
                m[{a[0], a[1]}] = a[2];
            }
            maxHeight = max(maxHeight, height + len);
            res.push_back(maxHeight);
        }
        return res;
    }
};
// @lc code=end
