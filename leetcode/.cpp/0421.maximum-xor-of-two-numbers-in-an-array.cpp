/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
// 1. 位操作+前缀树
// 2023-05-31 submission
// 43/43 cases passed
// Runtime: 817 ms, faster than 81.62% of cpp online submissions.
// Memory Usage: 180.2 MB, less than 89.64% of cpp online submissions.
class Solution {
public:
    struct TrieNode
    {
        TrieNode* next[2];
        TrieNode() {
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };

    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->next[bit] == nullptr) {
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            insert(root, num);
        }

        int res = 0;
        for (int num : nums) {
            TrieNode* node = root;
            int cur = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (node->next[bit ^ 1] != nullptr) {
                    cur += (1 << i);
                    node = node->next[bit ^ 1];
                }
                else {
                    node = node->next[bit];
                }
            }
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作+哈希表
// 2023-05-31 submission
// 43/43 cases passed
// Runtime: 1686 ms, faster than 17.03% of cpp online submissions.
// Memory Usage:  MB, less than 22.05% of cpp online submissions.
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int L = bitset<32>(maxNum).to_string().find('1');
        if (L == -1) {
            return 0;
        }

        int res = 0, mask = 0;
        for (int i = 31 - L; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end