/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
// 1. 哈希表+排序
// 2021-12-16 submission
// 17/17 cases passed
// Runtime: 16 ms, faster than 45.84% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 44.38% of cpp online submissions.
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        unordered_map<int, int> m;
        for (int i = 0; i < score.size(); i++) {
            m[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        for (int i = 0; i < score.size(); i++) {
            if (i == 0) {
                res[m[score[i]]] = "Gold Medal";
            }
            else if (i == 1) {
                res[m[score[i]]] = "Silver Medal";
            }
            else if (i == 2) {
                res[m[score[i]]] = "Bronze Medal";
            }
            else {
                res[m[score[i]]] = to_string(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 最大堆
// 2022-11-15 submission
// 17/17 cases passed
// Runtime: 11 ms, faster than 98.18% of cpp online submissions.
// Memory Usage: 10.1 MB, less than 92.53% of cpp online submissions.
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size(), cnt = 1;
        vector<string> res(n, "");
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({nums[i], i});
        }
        for (int i = 0; i < n; ++i) {
            int idx = q.top().second;
            q.pop();
            if (cnt == 1) {
                res[idx] = "Gold Medal";
            }
            else if (cnt == 2) {
                res[idx] = "Silver Medal";
            }
            else if (cnt == 3) {
                res[idx] = "Bronze Medal";
            }
            else {
                res[idx] = to_string(cnt);
            }
            ++cnt;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 有序字典
// 2021-12-16 submission
// 17/17 cases passed
// Runtime: 15 ms, faster than 47.98% of cpp online submissions.
// Memory Usage: 10.9 MB, less than 41.8% of cpp online submissions.
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> m;
        for (int i = 0; i < score.size(); i++) {
            m[score[i]] = i;
        }

        vector<string> res(score.size());
        int cnt = 0;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            ++cnt;
            if (cnt == 1) {
                res[it->second] = "Gold Medal";
            }
            else if (cnt == 2) {
                res[it->second] = "Silver Medal";
            }
            else if (cnt == 3) {
                res[it->second] = "Bronze Medal";
            }
            else {
                res[it->second] = to_string(cnt);
            }
        }
        return res;
    }
};
// @lc code=end
