/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (35.60%)
 * Likes:    1760
 * Dislikes: 126
 * Total Accepted:    114.4K
 * Total Submissions: 321.4K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n' +
  '[[],[1],[1],[2],[],[1],[]]'
 *
 * RandomizedCollection is a data structure that contains a collection of
 * numbers, possibly duplicates (i.e., a multiset). It should support inserting
 * and removing specific elements and also removing a random element.
 *
 * Implement the RandomizedCollection class:
 *
 *
 * RandomizedCollection() Initializes the empty RandomizedCollection
 * object.
 * bool insert(int val) Inserts an item val into the multiset, even if the item
 * is already present. Returns true if the item is not present, false
 * otherwise.
 * bool remove(int val) Removes an item val from the multiset if present.
 * Returns true if the item is present, false otherwise. Note that if val has
 * multiple occurrences in the multiset, we only remove one of them.
 * int getRandom() Returns a random element from the current multiset of
 * elements. The probability of each element being returned is linearly related
 * to the number of same values the multiset contains.
 *
 *
 * You must implement the functions of the class such that each function works
 * on average O(1) time complexity.
 *
 * Note: The test cases are generated such that getRandom will only be called
 * if there is at least one item in the RandomizedCollection.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RandomizedCollection", "insert", "insert", "insert", "getRandom",
 * "remove", "getRandom"]
 * [[], [1], [1], [2], [], [1], []]
 * Output
 * [null, true, false, true, 2, true, 1]
 *
 * Explanation
 * RandomizedCollection randomizedCollection = new RandomizedCollection();
 * randomizedCollection.insert(1);   // return true since the collection does
 * not contain 1.
 * ⁠                                 // Inserts 1 into the collection.
 * randomizedCollection.insert(1);   // return false since the collection
 * contains 1.
 * ⁠                                 // Inserts another 1 into the collection.
 * Collection now contains [1,1].
 * randomizedCollection.insert(2);   // return true since the collection does
 * not contain 2.
 * ⁠                                 // Inserts 2 into the collection.
 * Collection now contains [1,1,2].
 * randomizedCollection.getRandom(); // getRandom should:
 * ⁠                                 // - return 1 with probability 2/3, or
 * ⁠                                 // - return 2 with probability 1/3.
 * randomizedCollection.remove(1);   // return true since the collection
 * contains 1.
 * ⁠                                 // Removes 1 from the collection.
 * Collection now contains [1,2].
 * randomizedCollection.getRandom(); // getRandom should return 1 or 2, both
 * equally likely.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * At most 2 * 10^5 calls in total will be made to insert, remove, and
 * getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 *
 *
 */

// @lc code=start
// 2022-08-19 submission
// 32/32 cases passed
// Runtime: 431 ms, faster than 40.35% of C++ online submissions.
// Memory Usage: 107.7 MB, less than 36.55% of C++ online submissions.
class RandomizedCollection {
public:
    RandomizedCollection() {}
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
            m[nums.back()].erase(nums.size()-1);
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
// 2022-08-19 submission
// 32/32 cases passed
// Runtime: 286 ms, faster than 83.68% of C++ online submissions.
// Memory Usage: 104 MB, less than 75.26% of C++ online submissions.
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();

        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
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