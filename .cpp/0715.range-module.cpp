/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
// 1. 线段树
class RangeModule {
public:
    RangeModule() {
        root = std::make_shared<SegmentTreeNode>(0, 1e9, 0);
    }

    void addRange(int left, int right) {
        update(root, left, right - 1, 1);
    }

    bool queryRange(int left, int right) {
        return query(root, left, right - 1) > 0;
    }

    void removeRange(int left, int right) {
        update(root, left, right - 1, -1);
    }

private:
    struct SegmentTreeNode
    {
        int start, end, value, lazy;
        std::shared_ptr<SegmentTreeNode> left, right;
        SegmentTreeNode(int s, int e, int v)
            : start(s),
              end(e),
              value(v),
              lazy(0),
              left(nullptr),
              right(nullptr) {
        }
    };

    std::shared_ptr<SegmentTreeNode> root;

    void push_down(std::shared_ptr<SegmentTreeNode> node) {
        if (!node->left) {
            node->left = std::make_shared<SegmentTreeNode>(
                node->start, node->start + (node->end - node->start) / 2, 0);
        }
        if (!node->right) {
            node->right = std::make_shared<SegmentTreeNode>(
                node->start + (node->end - node->start) / 2 + 1, node->end, 0);
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
        if (ql <= node->start + (node->end - node->start) / 2) {
            result = std::max(result, query(node->left, ql, qr));
        }
        if (qr > node->start + (node->end - node->start) / 2) {
            result = std::max(result, query(node->right, ql, qr));
        }
        return result;
    }

    /**
     * Your RangeModule object will be instantiated and called as such:
     * RangeModule* obj = new RangeModule();
     * obj->addRange(left,right);
     * bool param_2 = obj->queryRange(left,right);
     * obj->removeRange(left,right);
     */
    // @lc code=end
