/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
// 1. 双哈希表
// 2023-06-27 submission
// 739/739 cases passed
// Runtime: 12 ms, faster than 9.63% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 7.72% of cpp online submissions.
class Solution {
public:
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)) return long2short[longUrl];
        string shortUrl = "http://tinyurl.com/";
        do {
            shortUrl = "http://tinyurl.com/";
            for (int i = 0; i < 6; ++i) {
                shortUrl += dict[rand() % 62];
            }
        } while (short2long.count(shortUrl));
        short2long[shortUrl] = longUrl;
        long2short[longUrl] = shortUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }

private:
    unordered_map<string, string> long2short, short2long;
    string dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
