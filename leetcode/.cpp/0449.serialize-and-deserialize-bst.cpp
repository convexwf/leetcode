/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
// 1. 先序遍历+单调栈
// 2024-06-26 submission
// 62/62 cases passed
// Runtime: 27 ms, faster than 33.42% of cpp online submissions.
// Memory Usage: 32.2 MB, less than 23.2% of cpp online submissions.
class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string res = to_string(root->val) + " ";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> arr;
        stringstream ss(data);
        int val;
        while (ss >> val) arr.push_back(val);
        int n = arr.size();
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] < arr[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return build(arr, right, 0, n - 1);
    }

    TreeNode* build(vector<int>& arr, vector<int>& right, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(arr[l]);
        root->left = build(arr, right, l + 1, right[l] - 1);
        root->right = build(arr, right, right[l], r);
        return root;
    }
};
// @lc code=end
