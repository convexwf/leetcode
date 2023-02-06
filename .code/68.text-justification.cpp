/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (35.91%)
 * Likes:    1919
 * Dislikes: 3086
 * Total Accepted:    259.3K
 * Total Submissions: 721.9K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of strings words and a width maxWidth, format the text such
 * that each line has exactly maxWidth characters and is fully (left and right)
 * justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line does not divide evenly between words, the
 * empty slots on the left will be assigned more spaces than the slots on the
 * right.
 *
 * For the last line of text, it should be left-justified, and no extra space
 * is inserted between words.
 *
 * Note:
 *
 *
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["This", "is", "an", "example", "of", "text",
 * "justification."], maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 * Example 2:
 *
 *
 * Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth
 * = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be", because the last line must be left-justified instead of
 * fully-justified.
 * Note that the second line is also left-justified because it contains only
 * one word.
 *
 * Example 3:
 *
 *
 * Input: words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] consists of only English letters and symbols.
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 *
 *
 */

// @lc code=start
// 2020-09-29 submission
// 27/27 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 19.1% of C++ online submissions.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        vector<string> cur;
        int cur_len = 0;
        for (int i = 0; i < words.size();) {
            bool flag = (words[i].length() + cur_len <= maxWidth);
            if (flag) {
                cur_len += (words[i].length() + 1);
                cur.push_back(words[i]);
                i++;
            }
            if (!flag && i < words.size()) {
                cur_len = maxWidth-cur_len+cur.size();
                string to_add = cur[0];
                if (cur.size() == 1) to_add.append(cur_len, ' ');
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(cur_len/(cur.size()-1)+(j<=cur_len%(cur.size()-1)), ' ');
                    to_add.append(cur[j]);
                }
                res.push_back(to_add);
                cur_len = 0;
                cur.clear();
            }
            if (i == words.size()) {
                string to_add = cur[0];
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(" ");
                    to_add.append(cur[j]);
                }
                to_add.append(maxWidth-to_add.length(), ' ');
                res.push_back(to_add);
            }
        }
        return res;
    }
};
// @lc code=end
