/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for (int i = 0; i < times.size(); ++i) {
            m[times[i]] += persons[i];
        }
    }

    int q(int t) {
        auto it = m.lower_bound(t);
    }

private:
    map<int, int> m;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

