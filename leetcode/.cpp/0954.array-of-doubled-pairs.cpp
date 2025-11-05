/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
// 1. 哈希表+自定义排序
// 2023-08-23 submission
// 102/102 cases passed
// Runtime: 74 ms, faster than 94.23% of cpp online submissions.
// Memory Usage:  MB, less than 70.78% of cpp online submissions.
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int num : arr) {
            cnt[num]++;
        }
        sort(arr.begin(), arr.end(), [](int x, int y) { return abs(x) < abs(y); });
        for (int num : arr) {
            if (cnt[num] == 0) {
                continue;
            }
            if (cnt[num * 2] == 0) {
                return false;
            }
            cnt[num]--;
            cnt[num * 2]--;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 有序字典
// 2023-08-23 submission
// 102/102 cases passed
// Runtime: 69 ms, faster than 95.23% of cpp online submissions.
// Memory Usage: 57.9 MB, less than 70.78% of cpp online submissions.
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;
        for (int i : arr) {
            m[i]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 0) {
                continue;
            }
            if (it->first > 0) {
                if (m[it->first * 2] < it->second) {
                    return false;
                }
                m[it->first * 2] -= it->second;
            }
            else {
                if (it->first % 2 != 0 || m[it->first / 2] < it->second) {
                    return false;
                }
                m[it->first / 2] -= it->second;
            }
        }
        return true;
    }
};
// @lc code=end
