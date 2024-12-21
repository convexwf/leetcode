/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
// 1. 前缀树+哈希表
// 2023-11-09 submission
// 35/35 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.9 MB, less than 13.65% of cpp online submissions.
class TrieNode {
public:
    int val;
    vector<TrieNode*> children;
    TrieNode(int val) : val(val), children(26, nullptr) {
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(0);
    }

    void insert(string key, int val) {
        int delta = val - m[key];
        m[key] = val;
        TrieNode* cur = root;
        for (char c : key) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode(0);
            }
            cur = cur->children[c - 'a'];
            cur->val += delta;
        }
    }

    int sum(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->children[c - 'a'] == nullptr) {
                return 0;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->val;
    }

private:
    unordered_map<string, int> m;
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

// @lc code=start
// 2. 哈希表
// 2023-11-09 submission
// 35/35 cases passed
// Runtime: 5 ms, faster than 41.49% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 31.21% of cpp online submissions.
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }

    void insert(string key, int val) {
        int diff = val - m[key].second;
        m[key].second = val;
        for (int i = 1; i <= key.size(); ++i) {
            m[key.substr(0, i)].first += diff;
        }
    }

    int sum(string prefix) {
        return m[prefix].first;
    }

private:
    unordered_map<string, pair<int, int>> m;
};
// @lc code=end

// @lc code=start
// 3. 有序字典+二分查找
// 2023-11-09 submission
// 35/35 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 76.77% of cpp online submissions.
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }

    void insert(string key, int val) {
        m[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        auto it = m.lower_bound(prefix);
        while (it != m.end() && it->first.substr(0, prefix.size()) == prefix) {
            res += it->second;
            ++it;
        }
        return res;
    }

private:
    map<string, int> m;
};
// @lc code=end
