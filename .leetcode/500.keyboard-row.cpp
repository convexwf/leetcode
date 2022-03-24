/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (67.18%)
 * Likes:    788
 * Dislikes: 844
 * Total Accepted:    140.9K
 * Total Submissions: 209.5K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given an array of strings words, return the words that can be typed using
 * letters of the alphabet on only one row of American keyboard like the image
 * below.
 * 
 * In the American keyboard:
 * 
 * 
 * the first row consists of the characters "qwertyuiop",
 * the second row consists of the characters "asdfghjkl", and
 * the third row consists of the characters "zxcvbnm".
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["Hello","Alaska","Dad","Peace"]
 * Output: ["Alaska","Dad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["omk"]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["adsdf","sfd"]
 * Output: ["adsdf","sfd"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] consists of English letters (both lowercase and uppercase). 
 * 
 * 
 */

// @lc solution=start
边界条件

1. `CapsLock` 在第二行，`shift` 在第三行 (在最新题目已经取消该条件，有点奇怪)
2. 出现非法字符
// @lc solution=end

// @lc code=start
// 2021-12-19 submission
// 22/22 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7 MB, less than 12.05% of C++ online submissions.
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> letters{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> m;
        for (int i = 0; i < 3; i++) {
            for (char c : letters[i]) {
                m[c] = m[toupper(c)] = i;
            }
        }

        vector<string> res;
        for (string word : words) {
            int idx = m.count(word[0]) ? 1 : 0;
            if (idx > 0) {
                for (; idx < word.length(); idx++) {
                    if (!m.count(word[idx]) || m[word[idx-1]] != m[word[idx]])
                        break;
                }
            }
            if (idx == word.length()) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

