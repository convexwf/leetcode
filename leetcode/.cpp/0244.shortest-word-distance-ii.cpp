/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 */

// @lc code=start
// 1. 哈希表+双指针
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            wordIndex[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& index1 = wordIndex[word1];
        vector<int>& index2 = wordIndex[word2];
        int i = 0, j = 0;
        int minDistance = INT_MAX;
        while (i < index1.size() && j < index2.size()) {
            minDistance = min(minDistance, abs(index1[i] - index2[j]));
            if (index1[i] < index2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return minDistance;
    }

private:
    unordered_map<string, vector<int>> wordIndex;
};
// @lc code=end
