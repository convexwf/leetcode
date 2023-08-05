/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */

// @lc code=start
// 1. 哈希表
// 2023-08-03 submission
// 45/45 cases passed
// Runtime: 378 ms, faster than 96.05% of cpp online submissions.
// Memory Usage: 123.3 MB, less than 42.54% of cpp online submissions.
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        this->N = N;
        for (auto& lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            // in case of duplicate lamps
            if (turning_on.insert((long)x * N + y).second) {
                row[x]++, col[y]++, diag[x - y]++, anti_diag[x + y]++;
            }
        }

        vector<int> res;
        for (auto& query : queries) {
            int x = query[0], y = query[1];
            res.push_back(judge(x, y));
            turn_off(x, y);
        }
        return res;
    }

private:
    void turn_off(int x, int y) {
        vector<pair<int, int>> dirs{{0, 0}, {0, 1},  {0, -1}, {1, 0},  {-1, 0},
                                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && turning_on.count((long)nx * N + ny)) {
                row[nx]--, col[ny]--, diag[nx - ny]--, anti_diag[nx + ny]--;
                turning_on.erase((long)nx * N + ny);
            }
        }
    }

    int judge(int x, int y) {
        if (row[x] > 0 || col[y] > 0 || diag[x - y] > 0 || anti_diag[x + y] > 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    unordered_map<int, int> row, col, diag, anti_diag;
    unordered_set<long> turning_on;
    int N;
};
// @lc code=end
