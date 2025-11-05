/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
// 1. 规律观察
// 2025-06-07 submission
// 49/49 cases passed
// Runtime: 75 ms, faster than 15.56% of cpp online submissions.
// Memory Usage: 43.9 MB, less than 8.93% of cpp online submissions.
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> m;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, cnt = 0;
        long area = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (long)(rect[2] - rect[0]) * (rect[3] - rect[1]);
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[1]), 1)) { // bottom-left
                return false;
            }
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[3]), 2)) { // top-left
                return false;
            }
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[3]), 4)) { // top-right
                return false;
            }
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[1]), 8)) { // bottom-right
                return false;
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            int t = it->second;
            if (t != 15 && t != 12 && t != 10 && t != 9 && t != 6 && t != 5 && t != 3) {
                ++cnt;
            }
        }
        return cnt == 4 && area == (long)(max_x - min_x) * (max_y - min_y);
    }

    bool isValid(unordered_map<string, int>& m, string corner, int type) {
        int& val = m[corner];
        if (val & type) {
            return false;
        }
        val |= type;
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 规律观察+哈希表
// 2025-06-07 submission
// 49/49 cases passed
// Runtime: 79 ms, faster than 13.27% of cpp online submissions.
// Memory Usage: 38.8 MB, less than 26.28% of cpp online submissions.
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> st;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        long area = 0;
        for (const vector<int>& rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (long)(rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + "_" + to_string(rect[1]); // bottom-left
            string s2 = to_string(rect[0]) + "_" + to_string(rect[3]); // top-left
            string s3 = to_string(rect[2]) + "_" + to_string(rect[3]); // top-right
            string s4 = to_string(rect[2]) + "_" + to_string(rect[1]); // bottom-right
            if (st.count(s1)) {
                st.erase(s1);
            }
            else {
                st.insert(s1);
            }
            if (st.count(s2)) {
                st.erase(s2);
            }
            else {
                st.insert(s2);
            }
            if (st.count(s3)) {
                st.erase(s3);
            }
            else {
                st.insert(s3);
            }
            if (st.count(s4)) {
                st.erase(s4);
            }
            else {
                st.insert(s4);
            }
        }
        string t1 = to_string(min_x) + "_" + to_string(min_y);
        string t2 = to_string(min_x) + "_" + to_string(max_y);
        string t3 = to_string(max_x) + "_" + to_string(max_y);
        string t4 = to_string(max_x) + "_" + to_string(min_y);
        if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4) {
            return false;
        }
        return area == (long)(max_x - min_x) * (max_y - min_y);
    }
};
// @lc code=end
