/*
 * @lc app=leetcode id=1429 lang=cpp
 *
 * [1429] First Unique Number
 */

// @lc code=start
// 1. 队列+哈希表
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        while (!q.empty() && mp[q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }

    void add(int value) {
        if (!mp.count(value)) {
            q.push(value);
            mp[value] = 1;
        }
        else {
            mp[value]++;
        }
    }

private:
    queue<int> q;
    unordered_map<int, int> mp;
};
// @lc code=end
