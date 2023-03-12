/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (27.03%)
 * Likes:    3855
 * Dislikes: 379
 * Total Accepted:    297.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 500
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), len = beginWord.size();
        vector<unordered_map<char, vector<int>>> m(len);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < len; ++j) {
                char c = wordList[i][j];
                m[len][c].push_back(i);
            }
        }

        vector<vector<string>> res;
        vector<bool> visited(n, false);
        queue<vector<string>> paths;
        paths.push({beginWord});
        while (!paths.empty() && res.empty()) {
            int qsize = q.size();
            unordered_set<int> curVisited;
            while (qsize-- > 0) {
                vector<string> last = q.top();
                q.pop();
                string cur = last.back();
                for (int i = 0; i < len; ++i) {
                    string lstr = cur.substr(0, i), rstr = cur.substr(i + 1);
                    for (auto it = m[i].begin(); it != m[i].end(); ++it) {
                        if (it.first == cur[i]) continue;
                        for (int wordIdx : it.second) {
                            if (!visited[wordIdx] && wordList[wordIdx] == lstr + it.first + rstr) {
                                curVisited.insert(wordIdx);
                                last.push_back(wordList[wordIdx]);
                                if (wordList[wordIdx] == endWord) {
                                    res.push_back(last);
                                }
                                paths.push(last);
                                last.pop_back();
                            }
                        }
                    }
                }
            }
            for (int visit : curVisited) {
                visited[visit] = true;
            }
        }
        return res;
    }
};
// @lc code=end
