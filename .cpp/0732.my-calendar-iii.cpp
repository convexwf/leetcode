/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
// 1. 差分数组+有序字典
// 2025-02-19 submission
// 98/98 cases passed
// Runtime: 49 ms, faster than 37.58% of cpp online submissions.
// Memory Usage:  MB, less than 56.77% of cpp online submissions.
class MyCalendarThree {
private:
    map<int, int> m;

public:
    MyCalendarThree() {
    }

    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int res = 0, cnt = 0;
        for (auto& [time, val] : m) {
            cnt += val;
            res = max(res, cnt);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end

// @lc code=start
// 2. 线段树
// 2025-02-19 submission
// 98/98 cases passed
// Runtime: 281 ms, faster than 11.13% of cpp online submissions.
// Memory Usage: 297.7 MB, less than 6.45% of cpp online submissions.
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
            node->left->value += node->lazy;
            node->left->lazy += node->lazy;
            node->right->value += node->lazy;
            node->right->lazy += node->lazy;
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

    void update(std::shared_ptr<SegmentTreeNode> node, int ql, int qr, int addValue) {
        if (ql > qr) {
            return;
        }
        if (ql <= node->start && node->end <= qr) {
            node->value += addValue;
            node->lazy += addValue;
            return;
        }
        push_down(node);
        if (ql <= node->mid) {
            update(node->left, ql, qr, addValue);
        }
        if (qr > node->mid) {
            update(node->right, ql, qr, addValue);
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

    void update(int ql, int qr, int addValue) {
        update(root, ql, qr, addValue);
    }
};

class MyCalendarThree {
public:
    MyCalendarThree() {
        tree = make_unique<SegmentTree>(0, 1e9);
    }

    int book(int start, int end) {
        tree->update(start, end - 1, 1);
        return tree->query(0, 1e9);
    }

private:
    std::unique_ptr<SegmentTree> tree;
};
// @lc code=end
