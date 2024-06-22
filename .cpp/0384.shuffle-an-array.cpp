/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
// 1. 洗牌算法(Knuth-Durstenfeld Shuffle)
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 80 ms, faster than 80.78% of cpp online submissions.
// Memory Usage: 57 MB, less than 72.52% of cpp online submissions.
class Solution {
public:
    Solution(vector<int> nums) : v(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = v;
        for (int n = res.size(); n > 0; --n) {
            int randIdx = rand() % n;
            swap(res[randIdx], res[n - 1]);
        }
        return res;
    }

private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
