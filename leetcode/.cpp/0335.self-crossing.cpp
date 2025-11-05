/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 */

// @lc code=start
// 1. 计算几何
// 2023-10-05 submission
// 30/30 cases passed
// Runtime: 13 ms, faster than 82.81% of cpp online submissions.
// Memory Usage: 19.1 MB, less than 11.98% of cpp online submissions.
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int len = distance.size();
        if (len < 4) return false;
        for (int i = 3; i < len; ++i) {
            // 第四条边和第一条边相交
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }
            // 第五条边和第一条边相交
            if (i >= 4 && distance[i - 1] == distance[i - 3] &&
                distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            // 第六条边和第一条边相交
            if (i >= 5 && distance[i - 2] >= distance[i - 4] &&
                distance[i - 1] <= distance[i - 3] &&
                distance[i - 1] + distance[i - 5] >= distance[i - 3] &&
                distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 计算几何-另外一种思路
// 2023-10-05 submission
// 30/30 cases passed
// Runtime: 14 ms, faster than 81.25% of cpp online submissions.
// Memory Usage: 19.1 MB, less than 18.75% of cpp online submissions.
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if (n < 4) {
            return false;
        }
        // 持续外卷
        int i = 2;
        while (i < n && distance[i] > distance[i - 2]) {
            i++;
        }
        // 外卷就走完所有步，直接就可以返回不相交
        if (i == n) {
            return false;
        }

        // 如果外卷转为内卷，i-1 的长度减 i-3 的长度
        if (distance[i] >= distance[i - 2] - (i < 4 ? 0 : distance[i - 4])) {
            distance[i - 1] -= i < 3 ? 0 : distance[i - 3];
        }

        // 持续外卷
        int j = i + 1;
        while (j < n && distance[j] < distance[j - 2]) {
            j++;
        }
        // 内卷走完最后一步
        if (j == n) {
            return false;
        }
        return true;
    }
};
// @lc code=end
