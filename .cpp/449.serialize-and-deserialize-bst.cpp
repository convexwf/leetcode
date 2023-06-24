/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
// 1. 先序遍历
// 2023-06-19 submission
// 62/62 cases passed
// Runtime: 33 ms, faster than 70.89% of cpp online submissions.
// Memory Usage: 31.6 MB, less than 17.95% of cpp online submissions.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string node;
        while (ss >> node) nodes.push_back(node);
        int i = 0;
        return deserialize(nodes, i);
    }

private:
    TreeNode* deserialize(vector<string>& nodes, int& i) {
        if (i >= nodes.size() || nodes[i] == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        root->left = deserialize(nodes, ++i);
        root->right = deserialize(nodes, ++i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

// @lc code=start
// 2. 层序遍历
// 2023-06-19 submission
// 62/62 cases passed
// Runtime: 26 ms, faster than 92.61% of cpp online submissions.
// Memory Usage: 25.4 MB, less than 72.4% of cpp online submissions.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                res += "# ";
                continue;
            }
            res += to_string(node->val) + " ";
            q.push(node->left);
            q.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string str;
        ss >> str;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ss >> str;
            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            ss >> str;
            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end