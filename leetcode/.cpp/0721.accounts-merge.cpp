/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
// 1. 并查集
// 2023-07-04 submission
// 50/50 cases passed
// Runtime: 89 ms, faster than 78.87% of cpp online submissions.
// Memory Usage: 39.3 MB, less than 22.26% of cpp online submissions.
class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }

    void unite(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailToIndex;
        int emailsCount = 0;
        for (const vector<string>& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); i++) {
                const string& email = account[i];
                if (!emailToName.count(email)) {
                    emailToName[email] = name;
                    emailToIndex[email] = emailsCount++;
                }
            }
        }

        // Merge emails
        UnionFind uf(emailsCount);
        for (const vector<string>& account : accounts) {
            const string& firstEmail = account[1];
            for (int i = 2; i < account.size(); i++) {
                const string& nextEmail = account[i];
                uf.unite(emailToIndex[firstEmail], emailToIndex[nextEmail]);
            }
        }
        // Collect emails
        unordered_map<int, vector<string>> indexToEmails;
        for (const auto& [email, _] : emailToName) {
            int index = uf.find(emailToIndex[email]);

            indexToEmails[index].emplace_back(email);
        }
        // Format output
        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.emplace_back(emailToName[emails[0]]);
            account.insert(account.end(), emails.begin(), emails.end());
            merged.emplace_back(account);
        }
        return merged;
    }
};
// @lc code=end

// @lc code=start
// 2. bfs
// 2023-07-05 submission
// 50/50 cases passed
// Runtime: 128 ms, faster than 25.73% of cpp online submissions.
// Memory Usage: 39.8 MB, less than 20.91% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        unordered_map<string, vector<int>> m;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                m[accounts[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] != 0) continue;
            queue<int> q{{i}};
            set<string> s;
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                visited[t] = 1;
                vector<string> mails(accounts[t].begin() + 1, accounts[t].end());
                for (string mail : mails) {
                    s.insert(mail);
                    for (int user : m[mail]) {
                        if (visited[user] != 0) continue;
                        q.push(user);
                        visited[user] = 1;
                    }
                }
            }
            vector<string> out(s.begin(), s.end());
            out.insert(out.begin(), accounts[i][0]);
            res.push_back(out);
        }
        return res;
    }
};
// @lc code=end
