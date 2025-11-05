/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
// 1. 有序字典
// 2025-06-09 submission
// 56/56 cases passed
// Runtime: 25 ms, faster than 79.97% of cpp online submissions.
// Memory Usage: 77.7 MB, less than 78.55% of cpp online submissions.
class RangeModule {
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto x = find(left, right);
        m[x.first] = x.second;
    }

    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        return it != m.begin() && (--it)->second >= right;
    }

    void removeRange(int left, int right) {
        auto x = find(left, right);
        if (left > x.first) {
            m[x.first] = left;
        }
        if (x.second > right) {
            m[right] = x.second;
        }
    }

private:
    map<int, int> m;

    pair<int, int> find(int left, int right) {
        auto l = m.upper_bound(left), r = m.upper_bound(right);
        if (l != m.begin() && (--l)->second < left) {
            ++l;
        }
        if (l == r) {
            return {left, right};
        }
        int i = min(left, l->first), j = max(right, (--r)->second);
        m.erase(l, ++r);
        return {i, j};
    }
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

// @lc code=start
// 2. 线段树+懒标记
// 2025-06-09 submission
// 56/56 cases passed
// Runtime: 622 ms, faster than 13.82% of cpp online submissions.
// Memory Usage: 367.6 MB, less than 14.08% of cpp online submissions.
class Node {
public:
    bool included;
    Node* left_node;
    Node* right_node;
    int left;
    int right;
    Node(int left, int right, bool included) {
        this->left = left;
        this->right = right;
        this->included = included;
        this->left_node = nullptr;
        this->right_node = nullptr;
    }
};

class SegmentTree {
public:
    Node* root;

    SegmentTree(int left, int right, bool included) {
        root = new Node(left, right, included);
    }

    void updateTree(Node* root, int left, int right, bool include) {
        // base case: exact match
        if (root->left == left && root->right == right) {
            root->left_node = nullptr;
            root->right_node = nullptr;
            root->included = include;
            return;
        }

        int mid = root->left + (root->right - root->left) / 2;

        // Lazy creation
        if (!root->left_node) {
            root->left_node = new Node(root->left, mid, root->included);
            root->right_node = new Node(mid + 1, root->right, root->included);
        }

        if (right <= mid) {
            updateTree(root->left_node, left, right, include);
        }
        else if (left > mid) {
            updateTree(root->right_node, left, right, include);
        }
        else {
            updateTree(root->left_node, left, mid, include);
            updateTree(root->right_node, mid + 1, right, include);
        }

        // Recalculate inclusion
        root->included = root->left_node->included && root->right_node->included;
    }

    bool queryTree(Node* root, int left, int right) {
        // leaf node: no further children
        if (!root->left_node) {
            return root->included;
        }

        // exact match
        if (root->left == left && root->right == right) {
            return root->included;
        }

        int mid = root->left + (root->right - root->left) / 2;
        bool a = false;
        if (right <= mid) {
            a = a || queryTree(root->left_node, left, right);
        }
        else if (left > mid) {
            a = a || queryTree(root->right_node, left, right);
        }
        else {
            a = a || (queryTree(root->left_node, left, mid) &&
                      queryTree(root->right_node, mid + 1, right));
        }
        return a;
    }
};

class RangeModule {
public:
    SegmentTree seg;

    RangeModule() : seg(0, 1e9, false) {
    }

    void addRange(int left, int right) {
        seg.updateTree(seg.root, left, right - 1, true);
    }

    bool queryRange(int left, int right) {
        return seg.queryTree(seg.root, left, right - 1);
    }

    void removeRange(int left, int right) {
        seg.updateTree(seg.root, left, right - 1, false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end
