/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
// 一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

// 注意：不允许旋转信封。

// Follow up是信封可以旋转，怎么的最长序列？答案是<3,4>加入，然后<4,3>也加入，再找最长序列。
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        envelopes.insert(envelopes.begin(), vector<int>{0, 0});

        vector<int> dp(envelopes.size(), 0);
        int res = 0;
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

