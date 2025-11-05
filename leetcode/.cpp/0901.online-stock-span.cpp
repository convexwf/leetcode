/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
// 1. 单调递减栈
// 2023-08-11 submission
// 99/99 cases passed
// Runtime: 187 ms, faster than 92.04% of cpp online submissions.
// Memory Usage: 84.1 MB, less than 82.94% of cpp online submissions.
class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        int res = 1;
        while (!prices.empty() && prices.top().first <= price) {
            res += prices.top().second;
            prices.pop();
        }
        prices.push({price, res});
        return res;
    }

private:
    stack<pair<int, int>> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

// @lc code=start
// 2. 数组记录
// 2023-08-11 submission
// 99/99 cases passed
// Runtime: 189 ms, faster than 90.91% of cpp online submissions.
// Memory Usage: 88.1 MB, less than 6.26% of cpp online submissions.
class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        nums.push_back(price);
        int i = (int)nums.size() - 2;
        while (!pre.empty() && i >= 0 && nums[i] <= price) {
            i = pre[i];
        }
        pre.push_back(i);
        return (int)pre.size() - 1 - i;
    }

private:
    vector<int> nums, pre;
};
// @lc code=end
