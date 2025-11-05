/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
// 1. 差分数组
// 2025-02-19 submission
// 97/97 cases passed
// Runtime: 104 ms, faster than 35.83% of cpp online submissions.
// Memory Usage:  MB, less than 64.72% of cpp online submissions.
class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        ++delta[start];
        --delta[end];
        int active = 0;
        for (auto& [time, count] : delta) {
            active += count;
            if (active >= 3) {
                --delta[start];
                ++delta[end];
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> delta;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

// @lc code=start
// 2. 线段树
// 2025-02-18 submission
// 97/97 cases passed
// Runtime: 508 ms, faster than 5.07% of cpp online submissions.
// Memory Usage: 426.6 MB, less than 5.07% of cpp online submissions.
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

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        tree = make_unique<SegmentTree>(0, 1e9);
    }

    bool book(int start, int end) {
        int max_value = tree->query(start, end - 1);
        if (max_value >= 2) {
            return false;
        }
        tree->update(start, end - 1, 1);
        return true;
    }

private:
    std::unique_ptr<SegmentTree> tree;
};
// @lc code=end
