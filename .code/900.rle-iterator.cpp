/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

// @lc code=start
// 2023-02-19 submission
// 11/11 cases passed
// Runtime: 4 ms, faster than 82.04% of C++ online submissions.
// Memory Usage: 8.7 MB, less than 6.94% of C++ online submissions.
class RLEIterator {
public:
    RLEIterator(vector<int>& A): nums(A), cur(0) {}

    int next(int n) {
        while (cur < nums.size() && n > nums[cur]) {
            n -= nums[cur];
            cur += 2;
        }
        if (cur >= nums.size()) return -1;
        nums[cur] -= n;
        return nums[cur + 1];
    }

private:
    int cur;
    vector<int> nums;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
// @lc code=end