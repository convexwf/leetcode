/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (59.04%)
 * Likes:    792
 * Dislikes: 41
 * Total Accepted:    108.4K
 * Total Submissions: 183.6K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * You are given an integer array score of size n, where score[i] is the score
 * of the i^th athlete in a competition. All the scores are guaranteed to be
 * unique.
 * 
 * The athletes are placed based on their scores, where the 1^st place athlete
 * has the highest score, the 2^nd place athlete has the 2^nd highest score,
 * and so on. The placement of each athlete determines their rank:
 * 
 * 
 * The 1^st place athlete's rank is "Gold Medal".
 * The 2^nd place athlete's rank is "Silver Medal".
 * The 3^rd place athlete's rank is "Bronze Medal".
 * For the 4^th place to the n^th place athlete, their rank is their placement
 * number (i.e., the x^th place athlete's rank is "x").
 * 
 * 
 * Return an array answer of size n where answer[i] is the rank of the i^th
 * athlete.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: score = [5,4,3,2,1]
 * Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
 * Explanation: The placements are [1^st, 2^nd, 3^rd, 4^th, 5^th].
 * 
 * Example 2:
 * 
 * 
 * Input: score = [10,3,8,9,4]
 * Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
 * Explanation: The placements are [1^st, 5^th, 3^rd, 2^nd, 4^th].
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == score.length
 * 1 <= n <= 10^4
 * 0 <= score[i] <= 10^6
 * All the values in score are unique.
 * 
 * 
 */

// @lc code=start
// 2021-12-16 submission
// 17/17 cases passed
// Runtime: 16 ms, faster than 45.84% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 44.38% of C++ online submissions.
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
            if (i == 0) res[m[score[i]]] = "Gold Medal";
            else if (i == 1) res[m[score[i]]] = "Silver Medal";
            else if (i == 2) res[m[score[i]]] = "Bronze Medal";
            else res[m[score[i]]] = to_string(i+1);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-15 submission
// 17/17 cases passed
// Runtime: 11 ms, faster than 98.18% of C++ online submissions.
// Memory Usage: 10.1 MB, less than 92.53% of C++ online submissions.
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
            int idx = q.top().second; q.pop();
            if (cnt == 1) res[idx] = "Gold Medal";
            else if (cnt == 2) res[idx] = "Silver Medal";
            else if (cnt == 3) res[idx] = "Bronze Medal";
            else res[idx] = to_string(cnt);
            ++cnt;
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2021-12-16 submission
// 17/17 cases passed
// Runtime: 15 ms, faster than 47.98% of C++ online submissions.
// Memory Usage: 10.9 MB, less than 41.8% of C++ online submissions.
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
            if (cnt == 1) res[it->second] = "Gold Medal";
            else if (cnt == 2) res[it->second] = "Silver Medal";
            else if (cnt == 3) res[it->second] = "Bronze Medal";
            else res[it->second] = to_string(cnt);
        }
        return res;
    }
};
// @lc code=end