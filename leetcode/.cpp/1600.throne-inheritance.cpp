/*
 * @lc app=leetcode id=1600 lang=cpp
 *
 * [1600] Throne Inheritance
 */

// @lc code=start
// 1. 多叉树前序遍历
// 2024-01-24 submission
// 49/49 cases passed
// Runtime: 354 ms, faster than 94.98% of cpp online submissions.
// Memory Usage:  MB, less than 61.64% of cpp online submissions.
struct Node
{
    string name;
    bool alive;
    vector<Node*> children;
    Node(string name) : name(name), alive(true) {
    }
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        hash[kingName] = root;
    }

    void birth(string parentName, string childName) {
        Node* parent = hash[parentName];
        Node* child = new Node(childName);
        parent->children.push_back(child);
        hash[childName] = child;
    }

    void death(string name) {
        hash[name]->alive = false;
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        preorder(root, res);
        return res;
    }

    void preorder(Node* node, vector<string>& res) {
        if (node->alive) {
            res.push_back(node->name);
        }
        for (Node* child : node->children) {
            preorder(child, res);
        }
    }

private:
    unordered_map<string, Node*> hash;
    Node* root;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end
