/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (69.16%)
 * Likes:    1136
 * Dislikes: 1004
 * Total Accepted:    169.9K
 * Total Submissions: 245.7K
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

// @lc code=start
// 2022-11-17 submission
// 22/22 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7 MB, less than 34.32% of C++ online submissions.
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3{'z','x','c','v','b','n','m'};
        for (string word : words) {
            int one = 0, two = 0, three = 0;
            for (char c : word) {
                c = tolower(c);
                if (row1.count(c)) one = 1;
                if (row2.count(c)) two = 1;
                if (row3.count(c)) three = 1;
                if (one + two + three > 1) break;
            }
            if (one + two + three == 1) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end