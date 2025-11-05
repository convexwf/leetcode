/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
// 1. 预处理
// 2024-10-16 submission
// 13/13 cases passed
// Runtime: 10 ms, faster than 5.43% of cpp online submissions.
// Memory Usage: 10.5 MB, less than 5.14% of cpp online submissions.
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<vector<int>> match(n, vector<int>(n));
        unordered_map<string, int> wordIndex;
        for (int i = 0; i < n; ++i) {
            wordIndex[words[i]] = i;
            for (int j = i; j < n; ++j) {
                match[i][j] = match[j][i] = getMatch(words[i], words[j]);
            }
        }

        vector<string> newWords = words;
        while (!newWords.empty()) {
            int minMatch = INT_MAX;
            string guessWord;
            for (const string& word : newWords) {
                vector<int> count(7);
                for (const string& w : newWords) {
                    count[match[wordIndex[word]][wordIndex[w]]]++;
                }
                int maxMatch = *max_element(count.begin(), count.end());
                if (maxMatch < minMatch) {
                    minMatch = maxMatch;
                    guessWord = word;
                }
            }
            int matchCount = master.guess(guessWord);
            if (matchCount == 6) {
                return;
            }
            vector<string> temp;
            for (string& word : newWords) {
                if (match[wordIndex[guessWord]][wordIndex[word]] == matchCount) {
                    temp.push_back(word);
                }
            }
            newWords = temp;
        }
    }

    int getMatch(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < 6; ++i) {
            if (a[i] == b[i]) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
