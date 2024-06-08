/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
// 1. dfs
// 2022-07-23 submission
// 60/60 cases passed
// Runtime: 3 ms, faster than 66.91% of cpp online submissions.
// Memory Usage: 10 MB, less than 44.28% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end

// @lc code=start
// 2. bfs+队列
// 2024-04-23 submission
// 66/66 cases passed
// Runtime: 3 ms, faster than 31.43% of cpp online submissions.
// Memory Usage: 11.9 MB, less than 15.69% of cpp online submissions.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) {
                return false;
            }
            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 3. bfs+栈
// 2022-07-23 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 10.1 MB, less than 7% of cpp online submissions.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        st.push(p);
        st.push(q);
        while (!st.empty()) {
            p = st.top();
            st.pop();
            q = st.top();
            st.pop();
            if (!p && !q) continue;
            if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
            st.push(p->right);
            st.push(q->right);
            st.push(p->left);
            st.push(q->left);
        }
        return true;
    }
};
// @lc code=end
