/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start
// 1. 二分搜索
// 2023-12-25 submission
// 98/98 cases passed
// Runtime: 217 ms, faster than 44.87% of cpp online submissions.
// Memory Usage: 103.8 MB, less than % of cpp online submissions.
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        votes.resize(n);
        unordered_map<int, int> m;
        int maxVote = 0;
        for (int i = 0; i < n; ++i) {
            this->times.push_back(times[i]);
            ++m[persons[i]];
            if (m[persons[i]] >= maxVote) {
                maxVote = m[persons[i]];
                votes[i] = persons[i];
            }
            else {
                votes[i] = votes[i - 1];
            }
        }
    }

    int q(int t) {
        int l = 0, r = times.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (times[mid] > t) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        return votes[l];
    }

private:
    vector<int> times;
    vector<int> votes;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
