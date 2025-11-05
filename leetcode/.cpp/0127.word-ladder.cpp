/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
// 1. BFS+哈希表
// 2023-01-14 submission
// 50/50 cases passed
// Runtime: 84 ms, faster than 94.02% of cpp online submissions.
// Memory Usage: 13.9 MB, less than 86.67% of cpp online submissions.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front();
                q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
// @lc code=end
