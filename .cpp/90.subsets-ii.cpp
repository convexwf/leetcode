/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
// 2023-01-14 submission
// 20/20 cases passed
// Runtime: 6 ms, faster than 51.11% of cpp online submissions.
// Memory Usage: 7.5 MB, less than 87.74% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        int size = 1, last = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (last != S[i]) {
                last = S[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

// 添加顺序为
// []
// [1]
// [2]
// [1 2]
// [2 2]
// [1 2 2]
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 20/20 cases passed
// Runtime: 6 ms, faster than 51.11% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 95.58% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
        }
    }
};

// 添加顺序为
// []
// [1]
// [1 2]
// [1 2 2]
// [2]
// [2 2]
// @lc code=end
