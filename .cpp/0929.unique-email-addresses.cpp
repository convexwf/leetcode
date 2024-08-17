/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
// 1. 字符串处理+哈希表
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string email : emails) {
            string localName = email.substr(0, email.find('@'));
            string domainName = email.substr(email.find('@'));
            localName = localName.substr(0, localName.find('+'));
            localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());
            s.insert(localName + domainName);
        }
        return s.size();
    }
};
// @lc code=end
