/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (35.04%)
 * Likes:    4131
 * Dislikes: 427
 * Total Accepted:    190.6K
 * Total Submissions: 544K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * You are given a 0-indexed array of unique strings words.
 *
 * A palindrome pair is a pair of integers (i, j) such that:
 *
 *
 * 0 <= i, j < words.length,
 * i != j, and
 * words[i] + words[j] (the concatenation of the two strings) is a
 * palindrome.
 *
 *
 * Return an array of all the palindrome pairs of words.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["a","a"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lowercase English letters.
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 136/136 cases passed
// Runtime: 593 ms, faster than 95.04% of C++ online submissions.
// Memory Usage: 361.6 MB, less than 84.07% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isPalindrome(t, 0, len - d - 1) &&
                    m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
                if (isPalindrome(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        return res;
    }

    bool isPalindrome(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};
// @lc code=end
