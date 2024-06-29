/*
 * @lc app=leetcode id=428 lang=cpp
 *
 * [428] Serialize and Deserialize N-ary Tree
 */

// @lc code=start
// 1. 前序遍历
class Codec {
public:
    string serialize(Node* root) {
        if (!root) return "";
        string res = to_string(root->val) + " ";
        for (Node* child : root->children) {
            res += serialize(child);
        }
        res += "# ";
        return res;
    }

    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        return deserialize(ss);
    }

    Node* deserialize(stringstream& ss) {
        string str;
        ss >> str;
        if (str == "#") return nullptr;
        Node* root = new Node(stoi(str));
        while (ss >> str) {
            if (str == "#") break;
            root->children.push_back(deserialize(ss));
        }
        return root;
    }
};
// @lc code=end

// @lc code=start
// 2. 层序遍历
class Codec {
public:
    string serialize(Node* root) {
        if (!root) return "";
        string res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + " ";
                res += to_string(node->children.size()) + " ";
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
        }
        return res;
    }

    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream in(data);
        queue<Node*> q;
        Node* root = nullptr;
        while (!in.eof()) {
            int val, size;
            in >> val >> size;
            Node* node = new Node(val);
            if (!root) root = node;
            for (int i = 0; i < size; ++i) {
                int childVal;
                in >> childVal;
                Node* child = new Node(childVal);
                node->children.push_back(child);
                q.push(child);
            }
        }
        return root;
    }
};
// @lc code=end
