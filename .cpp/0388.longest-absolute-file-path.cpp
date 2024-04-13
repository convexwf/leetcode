/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
// 1. 栈
// 2023-06-05 submission
// 26/26 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 20.37% of cpp online submissions.
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> paths = split(input, '\n');
        stack<int> st;
        int maxLen = 0;
        for (string path : paths) {
            int level = getLevel(path);
            while (st.size() > level) {
                st.pop();
            }
            // -level + 1 means remove all '\t' and add '/'
            int len = (st.empty() ? 0 : st.top()) + (path.size() - level + 1);
            st.push(len);
            // make sure it is a file
            if (path.find('.') != string::npos) {
                maxLen = max(maxLen, len - 1);
            }
        }
        return maxLen;
    }

    vector<string> split(const string& input, char c) {
        vector<string> res;
        int start = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == c) {
                res.push_back(input.substr(start, i - start));
                start = i + 1;
            }
        }
        res.push_back(input.substr(start));
        return res;
    }

    int getLevel(const string& path) {
        int level = 0;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '\t') {
                level++;
            }
            else {
                break;
            }
        }
        return level;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表
// 2023-06-05 submission
// 26/26 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 41.85% of cpp online submissions.
class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> m;
        m[0] = 0;
        int res = 0;
        for (string s : split(input, '\n')) {
            int level = s.find_last_of('\t') + 1;
            int len = s.substr(level).size();
            if (s.find('.') != string::npos) {
                res = max(res, m[level] + len);
            }
            else {
                m[level + 1] = m[level] + len + 1;
            }
        }
        return res;
    }

private:
    vector<string> split(string s, char c) {
        vector<string> res;
        string tmp;
        istringstream iss(s);
        while (getline(iss, tmp, c)) {
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end