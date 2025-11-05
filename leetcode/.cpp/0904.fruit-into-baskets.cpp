/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
// 1. 滑动窗口+哈希表
// 2023-08-31 submission
// 91/91 cases passed
// Runtime: 129 ms, faster than 76.89% of cpp online submissions.
// Memory Usage: 71.1 MB, less than 61.36% of cpp online submissions.
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                cnt[fruits[left]]--;
                if (cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 滑动窗口+候选数
// 2023-08-31 submission
// 91/91 cases passed
// Runtime: 75 ms, faster than 99.21% of cpp online submissions.
// Memory Usage: 66.1 MB, less than 98.68% of cpp online submissions.
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, cur = 0, cntB = 0, a = 0, b = 0;
        for (int fruit : tree) {
            cur = (fruit == a || fruit == b) ? cur + 1 : cntB + 1;
            cntB = (fruit == b) ? cntB + 1 : 1;
            if (b != fruit) {
                a = b;
                b = fruit;
            }
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end
