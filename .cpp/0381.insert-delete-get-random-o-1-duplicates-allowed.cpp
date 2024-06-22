/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
// 1. 哈希表+一维数组
// 2022-08-19 submission
// 32/32 cases passed
// Runtime: 431 ms, faster than 40.35% of cpp online submissions.
// Memory Usage: 107.7 MB, less than 36.55% of cpp online submissions.
class RandomizedCollection {
public:
    RandomizedCollection() {
    }
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        // 题目要求: 如果插入时有重复值，返回 false
        return m[val].size() == 1;
    }
    bool remove(int val) {
        if (m[val].empty()) return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if (nums.size() - 1 != idx) { // 仅当不是末位置才需要替换
            nums[idx] = nums.back();
            m[nums.back()].erase(nums.size() - 1);
            m[nums.back()].insert(idx);
        }
        nums.pop_back();
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

// @lc code=start
// 2. 哈希表+二维数组
// 2022-08-19 submission
// 32/32 cases passed
// Runtime: 286 ms, faster than 83.68% of cpp online submissions.
// Memory Usage: 104 MB, less than 75.26% of cpp online submissions.
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain
     * the specified element. */
    bool insert(int val) {
        bool result = !m[val].empty();

        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified
     * element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if (result) {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if (m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return result;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }

private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};
// @lc code=end
