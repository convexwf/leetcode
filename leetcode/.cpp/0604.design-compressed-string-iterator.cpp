/*
 * @lc app=leetcode id=604 lang=cpp
 *
 * [604] Design Compressed String Iterator
 */

// @lc code=start
// 1. 模拟
class StringIterator {
public:
    StringIterator(string compressedString) {
        s = compressedString;
        n = s.size();
        i = 0;
        j = 0;
    }

    char next() {
        if (!hasNext()) return ' ';
        if (j == 0) {
            c = s[i++];
            while (i < n && isdigit(s[i])) {
                j = j * 10 + s[i++] - '0';
            }
        }
        j--;
        return c;
    }

    bool hasNext() {
        return i < n || j > 0;
    }

private:
    string s;
    int n;
    int i;
    int j;
    char c;
};
// @lc code=end
