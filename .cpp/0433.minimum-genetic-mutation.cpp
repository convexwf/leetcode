/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
// 1. BFS
// 2023-11-03 submission
// 18/18 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.9 MB, less than 56.03% of cpp online submissions.
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) {
            return -1;
        }
        queue<string> q;
        q.push(startGene);
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                string gene = q.front();
                q.pop();
                if (gene == endGene) {
                    return step;
                }
                for (int j = 0; j < gene.size(); ++j) {
                    string new_gene = gene;
                    for (char c : "ACGT") {
                        new_gene[j] = c;
                        if (bankSet.count(new_gene) && new_gene != gene) {
                            q.push(new_gene);
                            bankSet.erase(new_gene);
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end
