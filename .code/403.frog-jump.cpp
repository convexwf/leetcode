/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
// 2023-03-12 submission
// 52/52 cases passed
// Runtime: 161 ms, faster than 67.85% of C++ online submissions.
// Memory Usage: 24.8 MB, less than 79.23% of C++ online submissions.
class Solution {
public:
    unordered_map<string, bool> m;

    bool canCross(vector<int>& stones) {
        return DFS(stones, 0, 0);
    }

    bool DFS(vector<int>& stones, int pos, int step) {
        // cout << "pos: " << pos << " step: " << step << endl;
        if (pos == stones.back()) return true;

        string key = to_string(pos) + "_" + to_string(step);
        if (m.count(key)) return m[key];

        for (int nextStep : vector<int>{step - 1, step, step + 1}) {
            if (nextStep <= 0) continue;
            int nextPos = pos + nextStep;
            if (findPos(stones, nextPos) > 0 && DFS(stones, nextPos, nextStep)) {
                return m[key] = true;
            }
        }
        return m[key] = false;
    }

    int findPos(vector<int>& stones, int target) {
        int l = 0, r = stones.size(), mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (stones[mid] == target)
                return mid;
            else if (stones[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }
};
// @lc code=end