/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

// @lc code=start
// 2023-02-19 submission
// 11/11 cases passed
// Runtime: 4 ms, faster than 82.04% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 6.94% of cpp online submissions.
class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) : encoding(encoding), i(0), j(0) {
    }

    int next(int n) {
        while (i < encoding.size()) {
            if (encoding[i] - j >= n) {
                j += n;
                return encoding[i + 1];
            }
            else {
                n -= encoding[i] - j;
                i += 2;
                j = 0;
            }
        }
        return -1;
    }

private:
    vector<int> encoding;
    int i, j;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
// @lc code=end
