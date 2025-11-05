/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
// 1. 哈希表
// 2023-06-20 submission
// 162/162 cases passed
// Runtime: 92 ms, faster than 72.47% of cpp online submissions.
// Memory Usage: 35.6 MB, less than 72.47% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (auto& path : paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                int idx = s.find('(');
                string filename = s.substr(0, idx);
                string content = s.substr(idx + 1, s.size() - idx - 2);
                m[content].push_back(root + '/' + filename);
            }
        }
        vector<vector<string>> res;
        for (auto& p : m) {
            if (p.second.size() > 1) {
                res.push_back(p.second);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+istringstream
// 2023-06-20 submission
// 162/162 cases passed
// Runtime: 120 ms, faster than 33.15% of cpp online submissions.
// Memory Usage: 44.6 MB, less than 29.77% of cpp online submissions.
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string path : paths) {
            istringstream is(path);
            string pre = "", t = "";
            is >> pre;
            while (is >> t) {
                int idx = t.find_last_of('(');
                string dir = pre + "/" + t.substr(0, idx);
                string content = t.substr(idx + 1, t.size() - idx - 2);
                m[content].push_back(dir);
            }
        }
        for (auto a : m) {
            if (a.second.size() > 1) res.push_back(a.second);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 哈希表 + MD5
// OJ 不支持 openssl
#include <openssl/md5.h>
class Solution {
public:
    string getFileHash(const string& filePath) {
        ifstream file(filePath, ios::binary);

        if (!file.is_open()) {
            return "";
        }

        MD5_CTX md5Context;
        MD5_Init(&md5Context);

        char buffer[4096];
        while (file.good()) {
            file.read(buffer, sizeof(buffer));
            MD5_Update(&md5Context, buffer, file.gcount());
        }

        unsigned char hash[MD5_DIGEST_LENGTH];
        MD5_Final(hash, &md5Context);

        stringstream ss;
        for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
            ss << hex << static_cast<int>(hash[i]);
        }

        return ss.str();
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hashMap;

        // traverse all paths
        for (const string& path : paths) {
            stringstream ss(path);
            string directory, file;
            string content;

            // get directory
            getline(ss, directory, ' ');

            // extract file name and content
            while (getline(ss, file, ' ')) {
                size_t leftParenthesis = file.find('(');
                size_t rightParenthesis = file.find(')');

                string fileName = file.substr(0, leftParenthesis);
                string fileContent =
                    file.substr(leftParenthesis + 1, rightParenthesis - leftParenthesis - 1);

                // get full path
                string fullPath = directory + '/' + fileName;

                // calculate file hash
                string fileHash = getFileHash(fullPath);

                // store file path
                hashMap[fileHash].push_back(fullPath);
            }
        }

        // 提取重复文件的路径集合
        vector<vector<string>> result;
        for (const auto& entry : hashMap) {
            if (entry.second.size() > 1) {
                result.push_back(entry.second);
            }
        }

        return result;
    }
};
// @lc code=end
