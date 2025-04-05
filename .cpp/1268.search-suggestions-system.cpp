/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
// 1. 排序+前缀树
// 2025-04-05 submission
// 43/43 cases passed
// Runtime: 99 ms, faster than 40.33% of cpp online submissions.
// Memory Usage: 110.2 MB, less than 31.04% of cpp online submissions.
class Solution {
private:
    struct TrieNode
    {
        vector<TrieNode*> children;
        vector<string> products;
        TrieNode() {
            children.resize(26, nullptr);
        }
    };

    void insert(TrieNode* root, const string& product) {
        TrieNode* node = root;
        for (char c : product) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
            if (node->products.size() < 3) {
                node->products.push_back(product);
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        for (const string& product : products) {
            insert(root, product);
        }

        vector<vector<string>> result;
        TrieNode* node = root;
        for (char c : searchWord) {
            if (!node->children[c - 'a']) {
                break;
            }
            node = node->children[c - 'a'];
            result.push_back(node->products);
        }

        while (result.size() < searchWord.size()) {
            result.push_back({});
        }

        return result;
    }
};
// @lc code=end
