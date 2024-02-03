/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
// 2020-07-06 submission
// 178/178 cases passed
// Runtime: 200 ms, faster than 73.28% of C++ online submissions.
// Memory Usage: 16.9 MB, less than 90.37% of C++ online submissions.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.length() == 0 || words.empty()) return {};

        int count = words.size(); // Count of words
        int len = words[0].size(); // Length of word
        unordered_map<string, int> word_freq;
        for (string word : words) {
            word_freq[word]++;
        }

        vector<int> ret_vec;
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> check_freq;
            int left_pivot = i;
            for (int pivot = i; pivot < s.size(); pivot += len) {
                string to_compare = s.substr(pivot, len);
                if(word_freq.count(to_compare)) {
                    check_freq[to_compare]++;
                    while (check_freq[to_compare] > word_freq[to_compare]) {
                        check_freq[s.substr(left_pivot, len)]--;
                        left_pivot += len;
                    }
                    if (pivot + len - left_pivot == count * len) {
                        ret_vec.push_back(left_pivot);
                        check_freq[s.substr(left_pivot, len)]--;
                        left_pivot += len;
                    }
                }
                else {
                    check_freq.clear();
                    left_pivot = pivot + len;
                }
                cout << i << " " << pivot << " " << left_pivot << endl;
            }
        }
        return ret_vec;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 178/178 cases passed
// Runtime: 276 ms, faster than 64.36% of C++ online submissions.
// Memory Usage: 24.6 MB, less than 70.8% of C++ online submissions.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for (auto &word : words) ++wordCnt[word];
        for (int i = 0; i <= (int)s.size() - n * len; ++i) {
            unordered_map<string, int> strCnt;
            int j = 0;
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
