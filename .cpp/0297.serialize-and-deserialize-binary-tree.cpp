/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
// 1. 先序遍历
// 2022-11-14 submission
// 52/52 cases passed
// Runtime: 131 ms, faster than 25.84% of cpp online submissions.
// Memory Usage: 31.2 MB, less than 49.52% of cpp online submissions.
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
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }

private:
    void encode(TreeNode* root, ostringstream& out) {
        if (!root)
            out << "# ";
        else {
            out << to_string(root->val) << " ";
            encode(root->left, out);
            encode(root->right, out);
        }
    }

    TreeNode* decode(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(in);
        node->right = decode(in);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

// @lc code=start
// 2. 层序遍历
// 2022-11-14 submission
// 52/52 cases passed
// Runtime: 75 ms, faster than 77.16% of cpp online submissions.
// Memory Usage: 29.2 MB, less than 67.39% of cpp online submissions.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                res += "# ";
            }
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
            if (!(ss >> str)) break;
            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            if (!(ss >> str)) break;
            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end
