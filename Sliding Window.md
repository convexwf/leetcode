# Sliding Window

## 3. Longest Substring Without Repeating Characters

解题思路

1. 题目描述：求最长无重复子串
2. 滑动窗口：建立字符到其出现次数或者最后出现位置的映射，并且定义一个变量标记当前滑动窗口的左边界。
3. 对于 char 数据类型的hashmap，可以用 `vector<int> m(256, -1)` 代替。

关联专题

1. **Sliding Window**

```C++
// 2018-04-13 submission
// Runtime: 8 ms, faster than 88.24% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.6 MB, less than 64.19% of C++ online submissions for Longest Substring Without Repeating Characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int l = 0;
        vector<int> m(256, -1); // unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            ++m[s[i]];
            while(m[s[i]] > 1) {
                m[s[l++]]--;
            }
            max_length = max(max_length, i - l + 1);
        }
        return max_length;
    }
};
```

```C++
// 2018-04-13 submission
// Runtime: 12 ms, faster than 76.61% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.5 MB, less than 74.50% of C++ online submissions for Longest Substring Without Repeating Characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int l = -1;
        vector<int> m(256, -1); // unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] >= 0) l = max(l, m[s[i]]);
            m[s[i]] = i;
            max_length = max(max_length, i - l);
        }
        return max_length;
    }
};
```

## 992. Subarrays with K Different Integers