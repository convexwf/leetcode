# Leetcode

## 1. Two Sum

解题思路

1. 题目描述：给定无序数组和指定值 target, 返回和为 target 的两个数的下标。
2. HashMap：建立值到下标的映射。复杂度为 O(n)

关联专题

1. **Target Sum**

```C++
// 2020-12-14 submission
// Runtime: 8 ms, faster than 95.31% of C++ online submissions for Two Sum.
// Memory Usage: 9.4 MB, less than 77.01% of C++ online submissions for Two Sum.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) 
                return vector<int>{m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};
```

## 2. Add Two Numbers

解题思路

1. 题目描述：需要相加的两个数字通过链表反向存储，结果也需要通过链表反向存储。
2. dummy节点

关联专题

1. **Arithmetic**

```C++
// 2018-04-12 submission
// Runtime: 28 ms, faster than 90.44% of C++ online submissions for Add Two Numbers.
// Memory Usage: 71.6 MB, less than 33.89% of C++ online submissions for Add Two Numbers.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) carry += l1->val;
            if (l2) carry += l2->val;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
```

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

## 28. Implement strStr()

解题思路

1. 暴力求解即可

边界条件：

1. 注意 haystack 或者 needle 长度为0的情况
2. 注意 haystack 长度比 needle 小的情况  

```C++
// 2020-06-28 submission
// Runtime: 4 ms, faster than 98.77% of C++ online submissions
// Memory Usage: 6.9 MB, less than 53.41% of C++ online submissions
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() <= 0) return 0;
        if(haystack.length() < needle.length()) return -1;
        for(int i = 0; i <= haystack.length()-needle.length(); i++) {
            if(judge(haystack,  needle, i))
                return i;
        }
        return -1;
    }

    bool judge(string& haystack, string& needle, int cur_pivot) {
        int size = needle.length();
        for(int i = 0; i < size; i++) {
            if (cur_pivot + i >= haystack.length()) return false;
        }
        return true;
    }
};
```

1.  Divide Two Integers
（1）不准使用乘除幂运算的情况下，都要使用位操作
（2）去除符号后再做运算，结果再加上符号
（3）运算过程中可能会发生溢出，要用long表示
（3）边界条件：被除数是INT_MAX，除数是INT_MIN
（4）边界条件：被除数是0
// 2020-07-04 submission
// Runtime: 4 ms, faster than 66.28% of C++ online submissions
// Memory Usage: 5.9 MB, less than 75.15% of C++ online submissions
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(INT_MIN == dividend && -1 == divisor) return INT_MAX;
        
        long x = abs(dividend), y = abs(div isor);
        bool minus = (dividend<0 && divisor>0) || (dividend>0 && divisor<0);
        long accum = 0;
        while(x >= y) {
            int i = 1;
            for (; y<<i <= x; i++);
            i--;
            x -= (y<<i);
            accum += (1<<i);
            // cout << x << " " << y << endl;
        }
        if(minus) return -accum;
        return accum;
    }
};

30. Substring with Concatenation of All Words
（1）解题思路：先用check_freq存储单词表的频率，然后词遍历字符串。词遍历是先遍历0,4,8,12,...，再遍历1,5,9,13,...，再遍历2,6,10,14...。词遍历过程中要维护一个哈希表word_freq表示当前匹配的单词数量，还有维护一个左边界表示当前匹配的最左位置。当当前位置减去左边界等于总长度而且维护的哈希表满足时，说明左边界为所需要的结果之一。
s.substr(pos,n)：若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值。
将map改为unordered_map可以有效提高速度
边界条件：待选单词可能会重复（两个以上同样的词），建议先用一个hashmap存储单词表的频率
边界条件：单词表为空
边界条件：待选单词长度为0
边界条件：查找字符串长度为0

// 2020-07-06 submission
// Runtime: 1044 ms, faster than 20.74% of C++ online submissions
// Memory Usage: 16.7 MB, less than 77.82% of C++ online submissions
```C++ code
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret_vec;
        if(words.size() <= 0) return ret_vec;
        if(words[0].size() <= 0) {
            for(int i = 0; i <= s.size(); i++) {
                ret_vec.push_back(i);
            }
            return ret_vec;
        }
        int count = words.size(); // Count of words
        int len = words[0].size(); // Length of word
        unordered_map<string, int> word_freq, check_freq;
        for (int x = 0; x < words.size(); x++) {
            if (check_freq.find(words[x]) == check_freq.end())
                check_freq[words[x]] = 0;
            check_freq[words[x]]++;
        }
                
        
        for (int i = 0; i < len; i++) {
            for (int x = 0; x < words.size(); x++)
                word_freq[words[x]] = 0;
            int left_pivot = i;
            for (int pivot = i; pivot < s.size(); pivot += len) {
                string to_compare = s.substr(pivot, len);
                if (word_freq.find(to_compare) == word_freq.end()) {
                    for (int x = 0; x < words.size(); x++)
                        word_freq[words[x]] = 0;
                    left_pivot = pivot + len;
                }
                else {
                    word_freq[to_compare]++;
                    while (word_freq[to_compare] > check_freq[to_compare]) {
                        word_freq[s.substr(left_pivot, len)]--;
                        left_pivot += len;
                    }
                    if (word_freq[to_compare] == check_freq[to_compare] && pivot+len-left_pivot == count * len) {
                        ret_vec.push_back(left_pivot);
                        word_freq[s.substr(left_pivot, len)]--;
                        left_pivot += len;
                    }
                }
                // cout << i << " " << pivot << " " << left_pivot << endl;
            }
        }
        return ret_vec;
    }
};
```

## 42. Trapping Rain Water
解题思路：每个位置能接的雨水量是：当前位置左边最高的数与右边最高的数的最小值减去当前位置的数（注意不能为负数）。
边界条件：高度列表长度小于3

// 2020-07-14 submission
// Runtime: 8 ms, faster than 92.96% of C++ online submissions
// Memory Usage: 14.2 MB, less than 36.02% of C++ online submissions
class Solution {
public:
    int trap(vector<int>& height) {
        int width = height.size();
        if(width < 3) return 0;
        vector<int> left_max(width, 0);
        vector<int> right_max(width, 0);
        left_max[0] = right_max[0] = height[0];
        left_max[width-1] = right_max[width-1] = height[width-1];
        
        int sum = 0;
        for (int i = width-2; i > 0; i--) {
            right_max[i] = max(height[i+1], right_max[i+1]);
        }
        
        for (int i = 1; i < width-1; i++) {
            left_max[i] = max(height[i-1], left_max[i-1]);
            int rest = min(left_max[i], right_max[i]) - height[i];
            if (rest > 0) sum += rest;
        }
        return sum;
    }
};

## 44. Wildcard Matching

解题思路

1. 动态规划，
    dp[i][j] 表示 p 前 i 个字符 和 s 前 j 个字符是否匹配
    if p[i-1] == s[j-1] or p[i-1] == '?', dp[i][j]=dp[i-1][j-1]
    if p[i-1] == '*', dp[i][j]=dp[i-1][j] or dp[i][j-1]

边界条件：

1. p 和 s 长度均为 0 时，结果为true
2. s 长度为 0，p 为只由 * 组成的字符串，结果为 true

```C++
// 2020-09-14 submission
// Runtime: 176 ms, faster than 40.96% of C++ online submissions for Wildcard Matching.
// Memory Usage: 6.6 MB, less than 89.86% of C++ online submissions for Wildcard Matching.
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.length()+1, false);
        
        dp[0] = true;
        for (int i = 1; i <= p.length(); i++) {
            bool last_valid = dp[0];
            dp[0] = (dp[0] && p[i-1] == '*');
            for (int j = 1; j <= s.length(); j++) {
                bool temp = dp[j];
                if (p[i-1] == '*') dp[j] = dp[j-1] || dp[j];
                else if (p[i-1] == '?') dp[j] = last_valid;
                else dp[j] = (last_valid && s[j-1] == p[i-1]);
                last_valid = temp;
                // cout << s[j-1] << " " << p[i-1] << " " << dp[j] << endl;
            }
        }
        
        return dp[s.length()];
    }
};
```

## 56. Merge Intervals

解题思路

1. 首先给区间集排序，需要定义自己的 comparator，才能用 sort 来排序。（其实直接对二维向量调用sort()函数，二维向量就会按第一列元素排序）。按照 start 的值从小到大来排序，排完序开始合并，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的 end 值更新为结果中最后一个区间的 end 和当前 end 值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果

```C++
// 2019-05-09 submission
// Runtime: 32 ms, faster than 94.27% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.5 MB, less than 76.55% of C++ online submissions for Merge Intervals.
class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        // 自写 sort 函数需要 引用参数 防止大量拷贝 影响效率
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        int i_min=intervals[0][0], i_max=intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(i_max >= intervals[i][0]) i_max = max(i_max, intervals[i][1]);
            else {
                result.push_back(vector<int>{i_min, i_max});
                i_min = intervals[i][0];
                i_max = intervals[i][1];
            }
        }
        result.push_back(vector<int>{i_min, i_max});
        return result;
    }
};
```

```C++
// 2020-11-19 submission
// Runtime: 44 ms, faster than 59.45% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.7 MB, less than 54.25% of C++ online submissions for Merge Intervals.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) 
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
```

## 57. Insert Interval
解题思路：从最左边遍历待插入区间，如果遍历区间右边界小于新区间左边界，将遍历区间加入结果，否则跳出循环。然后正式对交叉的区间进行处理，注意每次处理前都要判断是否重叠（因为有可能出现新区建在最左边和最右边的情况），然后取左边界最小值和右边界最大值作为新区间。不重叠时候跳出循环，将新区间加入结果，最后把剩下的待插入区间遍历完即可，所以有三个阶段。
边界条件：待插列表为空；新区间在最左边或者最右边；插入区间为空（标准程序没有注意到）

// 2020-07-14 submission
// Runtime: 32 ms, faster than 64.68% of C++ online submissions
// Memory Usage: 17.1 MB, less than 63.69% of C++ online submissions
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) return vector<vector<int>>(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int cnt = intervals.size();
        
        int cur = 0;
        while(cur < cnt) {
            if (intervals[cur][1] < newInterval[0])
                res.push_back(intervals[cur++]);
            else
                break;
        }
        
        vector<int> temp_interval(newInterval.begin(), newInterval.end());
        for (; cur < cnt; cur++) {
            if (judge(temp_interval, intervals[cur])) {
                temp_interval[0] = min(temp_interval[0], intervals[cur][0]);
                temp_interval[1] = max(temp_interval[1], intervals[cur][1]);
            }
            else
                break;
            // cout << "interval " << temp_interval[0] << " " << temp_interval[1] << endl;
        }
        res.push_back(temp_interval);
        
        while(cur < cnt) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
    
    bool judge(vector<int>& A, vector<int>& B) {
        return (A[1] >= B[0] && A[0] <= B[1]) || (B[1] >= A[0] && B[0] <= A[1]);
    }
};

## 59. Spiral Matrix II

解题思路

1. 可以发现顺时针走法是按照 [ '→', '↓', '←', '↑', ] 的顺序转向，当走出边缘或者碰到已经填上的数字时候就会转向。注意转向函数的书写，和常识不同。

```C++
// 2020-12-08 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 7.1 MB, less than 7.66% of C++ online submissions for Spiral Matrix II.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int di = 0, x = 0, y = -1;
        for (int i = 1; i <= n * n; i++) {
            if (0 > x + direction[di][0] ||
                x + direction[di][0] >= n ||
                0 > y + direction[di][1] || 
                y + direction[di][1] >= n ||
                res[x+direction[di][0]][y + direction[di][1]] != 0)  di = (di + 1) % 4;
            x += direction[di][0]; y += direction[di][1];
            res[x][y] = i;
        }
        return res;
    }
};
```

## 65. Valid Number
弱智题目（边界条件不说清楚）
解题思路：状态转移。注意要在字符串后面加一个空格表示结束符，从而使得终结符号只有1个。
边界条件 数字字符串中间不能被空格打断；不能出现两个以上数字字符串；
“1.”是合法的；“.1”合法；“.”不合法；
“+.5”合法；
“0000.1e-0000.00”合法；

// 2020-07-14 submission
// Runtime: 4 ms, faster than 76.08% of C++ online submissions for Valid Number.
// Memory Usage: 6.1 MB, less than 44.60% of C++ online submissions for Valid Number.

class Solution {
public:
    bool isNumber(string s) {
        int trans[][4] = {
            {2, -1, 1, 3}, // 0
            {2, -1, -1, 3},// 1
            {2, 5, -1, 4}, // 2
            {4, -1, -1, -1},// 3
            {4, 5, -1, -1},// 4
            {7, -1, 6, -1},// 5
            {7, -1, -1, -1},// 6
            {7, -1, -1, -1},//7
            {-1, -1, -1, -1}};//8
        int accepted[] = {2, 4, 7};
        
        s.append(1, ' ');
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (cur == 0 || cur == 8) continue;
                else if (cur == 2 || cur ==4 || cur == 7) cur = 8;
                else cur = -1;;
            }
            else if (s[i] >= '0' && s[i] <= '9') cur = trans[cur][0];
            else if (s[i] == 'e') cur = trans[cur][1];
            else if (s[i] == '+' || s[i] == '-') cur = trans[cur][2];
            else if (s[i] == '.') cur = trans[cur][3];
            else cur = -1;
            if (cur == -1) return false;
        }
        return cur == 8;
    }
};

## 68. Text Justification

解题思路

1. 遍历单词 list, 并维护一个cur_len表示当前收纳的长度（需包含空格）。每读入一个单词有三种情况：  

   + 加入当前单词后，cur_len <= maxWidth，当前单词记录，遍历下一个单词
   + 加入当前单词后，cur_len >= maxWidth 而且当前单词不是最后一个单词。此时将记录的单词串格式化处理。
   + 当前单词是最后一个单词，将记录的单词串格式化处理。（因为最后一行格式特殊）

```C++
// 2020-09-29 submission
// Runtime: 4 ms, faster than 57.57% of C++ online submissions for Text Justification.
// Memory Usage: 7.6 MB, less than 49.47% of C++ online submissions for Text Justification.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        vector<string> cur;
        int cur_len = 0;
        for (int i = 0; i < words.size();) {
            bool flag = (words[i].length() + cur_len <= maxWidth);
            if (flag) {
                cur_len += (words[i].length() + 1);
                cur.push_back(words[i]);
                i++;
            }
            if (!flag && i < words.size()) {
                cur_len = maxWidth-cur_len+cur.size();
                string to_add = cur[0];
                if (cur.size() == 1) to_add.append(cur_len, ' ');
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(cur_len/(cur.size()-1)+(j<=cur_len%(cur.size()-1)), ' ');
                    to_add.append(cur[j]);
                }
                res.push_back(to_add);
                cur_len = 0;
                cur.clear();
            }
            if (i == words.size()) {
                string to_add = cur[0];
                for (int j = 1; j < cur.size(); j++) {
                    to_add.append(" ");
                    to_add.append(cur[j]);
                }
                to_add.append(maxWidth-to_add.length(), ' ');
                res.push_back(to_add);
            }
        }
        return res;
    }
};
```

1.  Edit Distance

https://www.jianshu.com/p/a617d20162cf

![](res/2020-09-08-14-57-14.png)
![](res/2020-09-08-14-58-00.png)

// 2020-09-08 submission
// Runtime: 12 ms, faster than 83.41% of C++ online submissions for Edit Distance.
// Memory Usage: 6.3 MB, less than 97.74% of C++ online submissions for Edit Distance.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int c1 = word1.length();
        int c2 = word2.length();
        if (c1 == 0 or c2 == 0) return max(c1, c2);
        
        vector<int> dist(c1 + 1, 0);
        for (int i = 1; i <= c1; i++) {
            dist[i] = i;
        }
        for (int i = 1; i <= c2; i++) {
            int last_valid = dist[0];
            dist[0] = i;
            for (int j = 1; j <= c1; j++) {
                int temp = min(min(dist[j - 1], dist[j]) + 1, last_valid + (word1[j-1] != word2[i-1]));
                last_valid = dist[j];
                dist[j] = temp;
            }
        }
        return dist[c1];
    }
};

1.  Minimum Window Substring
解题思路：滑动窗口。注意可以只用一个哈希表，存储t的频率，当右边界遍历到减1，左边界遍历到加1。另外需要一个计数变量，当频率大于0时（因为非法字符最大频率为0，合法字符最小频率为0）计数变量cnt加1，从而可以判断是否已经包含所有合法字符。
边界条件：t长度可能为0（测试样例没有考虑到）

// 2020-07-17 submission
// Runtime: 32 ms, faster than 67.64% of C++ online submissions
// Memory Usage: 55.6 MB, less than 5.05% of C++ online submissions

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() == 0) return "";
        
        unordered_map<char, int> freq;
        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]++;
        }
        
        int left = 0;
        int cnt = 0;
        string res = "";
        int res_cnt = INT_MAX;
        for (int pivot = 0; pivot < s.length(); pivot++) {
            freq[s[pivot]]--;
            if(freq[s[pivot]] >= 0) cnt++;
            if (cnt == t.length()) {
                while(cnt == t.length()) {
                    freq[s[left]]++;
                    if (freq[s[left]] > 0) cnt--;
                    left++;
                }
                string cur_str = s.substr(left-1, pivot-left+2);
                if (cur_str.length() < res_cnt) {
                    res_cnt = cur_str.length();
                    res = cur_str;
                }
            }
        }
        return res;
    }
};

81. Search in Rotated Sorted Array II
边界条件：没有进行旋转处理（因为旋转轴为最后）

## 84. Largest Rectangle in Histogram

解题思路

1. 矩形面积由宽度和高度决定，于是固定高度，从而最大化宽度即可。一个位置上的高度确定，确定最大左宽度和最大右宽度，最大宽度即附近的大于自身的高度的连续序列长度。注意最左边位置的左宽度和最右边位置的右宽度为1.

```C++
// 2020-07-16 submission
// Runtime: 28 ms, faster than 64.06% of C++ online submissions
// Memory Usage: 14.3 MB, less than 47.02% of C++ online submissions
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int max_area = 0;
        int width = heights.size();
        vector<int> left_seq(width, 1);
        vector<int> right_seq(width, 1);

        for (int i = width-1; i >= 0; i--) {
            int pivot = i;
            while (pivot < width) {
                if (heights[i] <= heights[pivot]) pivot += right_seq[pivot];
                else break;
            }
            right_seq[i] = pivot - i;
        }

        for (int i = 0; i < width; i++) {
            int pivot = i;
            while (pivot >= 0) {
                if (heights[i] <= heights[pivot]) pivot -= left_seq[pivot];
                else break;
            }
            left_seq[i] = i - pivot;
            // cout << left_seq[i] << endl;
            max_area = max(max_area, (left_seq[i] + right_seq[i]-1)*heights[i]);
        }

        return max_area;
    }
};
```

## 85. Maximal Rectangle

解题思路

1. 参见 ##84 思路，同样是要先确定高度和宽度再得到最大面积
2. 维护三个数组（左连续序列长度、右连续序列长度、高度）
   左连续序列长度：指从左边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
   右连续序列长度：指从右边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
3. 进行行遍历
    + 若当前位置为“1”，要考虑上一侧行遍历序列长度是否大于 0。如果大于0说明正上面位置为“1”，则取连续的行“1”长度和上一次序列遍历长度的最小值，否则，直接认为序列长度为连续的行“1”长度。
    + 若当前位置为“0”，序列长度直接置0

边界条件

1. 矩阵为空

```C++
// 2020-09-15 submission
// Runtime: 48 ms, faster than 93.31% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 11.1 MB, less than 87.63% of C++ online submissions for Maximal Rectangle.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int max_area = 0;
        vector<int> left_seq(cols, INT_MAX);
        vector<int> right_seq(cols, INT_MAX);
        vector<int> height(cols, 0);
        int continous = 0;

        for (int i = 0; i < rows; i++) {
            continous = 0;
            for (int j = cols-1; j >= 0; j--) {
                if (matrix[i][j] == '1') continous++;
                else continous = 0;
                height[j] = continous == 0 ? 0 : height[j] + 1;
                right_seq[j] = right_seq[j] == 0 ? continous : min(right_seq[j], continous);
            }

            continous = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') continous++;
                else continous = 0;
                left_seq[j] = left_seq[j] == 0 ? continous : min(left_seq[j], continous);
                max_area = max(max_area, height[j]*(left_seq[j]+right_seq[j]-1));
            }
        }

        return max_area;
    }
};
```

### 87. Scramble String
解题思路：s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。
递归方法是将字符串按照不同长度进行切割，然后让子递归函数判断是否成立。
注意一个词和它自身是 scramble 的。
为了减少复杂度，每次切割前可以采用排序或者统计字母频率等。

// 2020-07-16 submission
// Runtime: 12 ms, faster than 79.75% of C++ online submissions
// Memory Usage: 8.9 MB, less than 73.29% of C++ online submissions
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int len = s1.length();
        
        int freq[26] = {0};
        for (int i = 0; i < len; i++) {
            ++freq[s1[i]-'a'];
            --freq[s2[i]-'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }
        
        for (int i = 1; i < len; i++) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            
            s21 = s2.substr(0, len - i);
            s22 = s2.substr(len - i);
            if (isScramble(s11, s22) && isScramble(s12, s21)) return true;
        }
        return false;
    }
};

93. Restore IP Addresses
解题思路：递归，从某一位开始，连续截取1位、2位或者3位数字，然后将后续数字进行递归处理
（1）IP地址要去除前导0
"010010"注意不能转化为"0.1.0.10"
边界条件：长度小于4或者大于12

// 2020-07-07 submission
Runtime: 8 ms, faster than 26.99% of C++ online submissions
Memory Usage: 6.8 MB, less than 41.62% of C++ online submissions
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> candidates;
        vector<string> result;
        helper(s, candidates, result, 0);
        return result;
    }
    
    void helper(string& s, vector<int>& candidates, vector<string>& result, int idx) {
        if (candidates.size() > 4) return;
        if (s.length() == idx) {
            if (candidates.size() == 4) {
                stringstream sstream;
                sstream << candidates[0] << "." << candidates[1] << "." << candidates[2] << "." << candidates[3];
                result.push_back(sstream.str());
            }
            return;
        }
        for (int i = 0; i < 3 && idx + i < s.length(); i++) {
            string c_str = s.substr(idx, i + 1);
            int c = stoi(c_str);
            if(c > 255 || (c_str[0]=='0' && c_str.length()>1)) continue;
            candidates.push_back(c);
            helper(s, candidates, result, idx + i + 1);
            candidates.pop_back();
        }
    }
};

95. Unique Binary Search Trees II
解题思路：递归，注意因为是BST，选定一个pivot后，比pivot小的交给左子树，比pivot大的交给右子树。递归形式是最后回收所有可能的子树形式。

// 2020-07-08 submission
Runtime: 16 ms, faster than 69.66% of C++ online submissions
Memory Usage: 14.8 MB, less than 9.78% of C++ online submissions
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int left, int right) {
        vector<TreeNode*> res, left_res, right_res;
        for (int pivot = left; pivot <= right; pivot++) {
            if (left == pivot) left_res = vector<TreeNode*>{NULL};
            else left_res = helper(left, pivot - 1);
            if (right == pivot) right_res = vector<TreeNode*>{NULL};
            else right_res = helper(pivot + 1, right);
            
            for (int i = 0; i < left_res.size()*right_res.size(); i++) {
                TreeNode* new_node = new TreeNode(pivot);
                new_node->left = left_res[i % left_res.size()];
                new_node->right = right_res[i / left_res.size()];
                res.push_back(new_node);
            }
        }
        return res;
    }
};

## 97. Interleaving String

解题思路

1. 动态规划
   前提：字符串 s1 和 s2 的长度和必须等于 s3 的长度
   初始化：若 s1 和 s2 其中的一个为空串的话，那么另一个肯定和 s3 的长度相等，则按位比较
   在任意非边缘位置 dp[i][j] 时，它的左边或上边有可能为 True 或是 False，两边都可以更新过来，只要有一条路通着，那么这个点就可以为 True
   转移方程：dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);

边界条件

1. s1 或者 s2 为空

```C++
// 2020-09-14 submission
// Runtime: 8 ms, faster than 47.16% of C++ online submissions for Interleaving String.
// Memory Usage: 6.4 MB, less than 70.29% of C++ online submissions for Interleaving String.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int c1 = s1.length(), c2 = s2.length();
        if (c1 + c2 != s3.length()) return false;
        vector<bool> dp(c1 + 1, true);

        for (int i = 1; i <= c1; i++) {
            dp[i] = (s1.substr(0, i) == s3.substr(0, i));
        }
        for (int i = 1; i <= c2; i++) {
            dp[0] = (s2.substr(0, i) == s3.substr(0, i));
            for (int j = 1; j <= c1; j++) {
                dp[j] = (dp[j-1] && s1[j-1]==s3[i+j-1]) || (dp[j] && s2[i-1]==s3[i+j-1]);
                // cout << s1[j-1] << " " << s2[i-1] << endl;
            }
        }

        return dp[c1];
    }
};
```

## 99. Recover Binary Search Tree

解题思路

1. 中序遍历：通过中序遍历拿到BST的升序排列（同时拿到对应的指针），把升序排列重新排序后重新复制。这是O(nlogn)的时间复杂度，但是空间复杂度（O(n)）不满足要求。
2. 中序遍历改进：通过两个指针和两个变量存储左边和右边，然后交换指针和值即可。
3. Morris 遍历：

```C++
// 2020-07-09 submission (中序遍历)
// Runtime: 52 ms, faster than 19.81% of C++ online submissions
// Memory Usage: 54.7 MB, less than 16.38% of C++ online submissions
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> pointers;
        vector<int> vals;
        inorder(root, pointers, vals);

        if(!vals.empty()) sort(vals.begin(), vals.end());
        for(int i =0; i < pointers.size(); i++) {
            pointers[i]->val = vals[i];
        }
    }

    void inorder(TreeNode* root, vector<TreeNode*>& pointers, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, pointers, vals);
        pointers.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, pointers, vals);
    }
};
```

```C++
// 2020-11-01 submission (中序遍历)
// Runtime: 36 ms, faster than 84.19% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 58.3 MB, less than 8.04% of C++ online submissions for Recover Binary Search Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> pointers(2, NULL);
        vector<int> vals(2, 0);
        inorder(root, pointers, vals);
        pointers[0]->val = vals[1];
        pointers[1]->val = vals[0];
    }

    void inorder(TreeNode* root, vector<TreeNode*>& pointers, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, pointers, vals);
        if (pointers[0] && pointers[1] && vals[0] < root->val) return;
        if (!pointers[0] || vals[0] < root->val) {
            pointers[0] = root;
            vals[0] = root->val;
        }
        if (pointers[0] && vals[0] > root->val) {
            pointers[1] = root;
            vals[1] = root->val;
        }
        // cout << root->val << " " << vals[0] << " " << vals[1] << endl;
        inorder(root->right, pointers, vals);
    }
};
```

## 104. Maximum Depth of Binary Tree

```C++
// 2018-07-21 submission
// Runtime: 12 ms, faster than 60.67% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.6 MB, less than 24.21% of C++ online submissions for Maximum Depth of Binary Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};
```

## 109. Convert Sorted List to Binary Search Tree

解题思路

1. 递归，通过双指针法找到链表中心，然后一切为二，分别建立左子树和右子树

```C++
// 2020-09-14 submission
// Runtime: 36 ms, faster than 41.31% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 31.5 MB, less than 15.62% of C++ online submissions for Convert Sorted List to Binary Search Tree.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (start == end) return NULL;
        if (start->next == end) return new TreeNode(start->val);

        // Find the middle point
        ListNode* fast=start, *middle=start;
        while(fast!=end && fast->next!=end) {
            fast = fast->next->next;
            middle = middle->next;
        }

        return new TreeNode(middle->val, helper(start, middle), helper(middle->next, end));
    }
};
```

## 114. Flatten Binary Tree to Linked List

解题思路

1. 递归：利用 DFS 的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。

```C++
// 2020-09-16 submission
// Runtime: 8 ms, faster than 70.80% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 12.9 MB, less than 10.64% of C++ online submissions for Flatten Binary Tree to Linked List.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = right;
    }
};
```

## 115. Distinct Subsequences

解题思路

1. 动态规划，dp[i][j] 表示 s 中范围是 [0, i] 的子串中能组成 t 中范围是 [0, j] 的子串的子序列的个数。
2. 状态转移方程为 dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0)

边界条件

1. 空串是任意字符串（包括空串）的子串，在本题中空串仅计算1次。
2. 非空串不是空串的子串。
3. 数据类型不能使用 int，因为在运算过程中有可能会出现比最终结果大的数字（比如说rab能够比rabbit匹配更多次）而导致溢出。

```C++
// 2020-09-15 submission
// Runtime: 12 ms, faster than 71.06% of C++ online submissions for Distinct Subsequences.
// Memory Usage: 7 MB, less than 83.59% of C++ online submissions for Distinct Subsequences.
class Solution {
public:
    int numDistinct(string s, string t) {
        int c1 = s.length(), c2 = t.length();
        vector<long> dp(c1 + 1, 1); // why long type

        int last_valid = 0;
        for (int i = 1; i <= c2; i++) {
            last_valid = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= c1; j++) {
                int temp = dp[j];
                dp[j] = dp[j-1] + (s[j-1] == t[i-1] ? last_valid : 0);
                last_valid = temp;
            }
        }
        return dp[c1];
    }
};
```

## 116. Populating Next Right Pointers in Each Node

解题思路

1. 前序遍历：每个节点都要负责解决左子节点和右子节点的 next 指针指向。因为是完全二叉树，所以左节点可以直接指向右节点；右子节点的处理方法是，判断其父节点的 next 是否为空，若不为空，则指向其 next 指针指向的节点的左子结点，若为空则指向 NULL

```C++
// 2019-09-03 submission
// Runtime: 12 ms, faster than 98.01% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 17.3 MB, less than 28.18% of C++ online submissions for Populating Next Right Pointers in Each Node.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        helper(root);
        return root;
    }

    void helper(Node* root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        helper(root->left);
        helper(root->right);
    }
};
```

## 117. Populating Next Right Pointers in Each Node II

解题思路

1. 迭代遍历+队列：每层的节点都按顺序加入 queue 中，而每当从 queue 中取出一个元素时，将其 next 指针指向 queue 中下一个节点，对于每层的开头元素开始遍历之前，先统计一下该层的总个数，当 for 循环结束的时候，该层就已经被遍历完了。
2. 递归：由于子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点。

```C++
// 2020-11-09 submission
// Runtime: 12 ms, faster than 88.81% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 18 MB, less than 87.11% of C++ online submissions for Populating Next Right Pointers in Each Node II.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            Node* cur = NULL;
            for (int i = 0; i < q_size; i++) {
                cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                cur->next = (i == q_size-1 ? NULL : q.front());
                cur = cur->next;
            }
        }
        return root;
    }
};
```

```C++
// 2020-11-09 submission
// Runtime: 16 ms, faster than 62.44% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 17.8 MB, less than 87.11% of C++ online submissions for Populating Next Right Pointers in Each Node II.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node *root)
    {
        if(!root) return NULL;

        if(root->left) root->left->next = root->right!= nullptr ? root->right : findNext(root->next);
        if(root->right) root->right->next = findNext(root->next);

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* findNext(Node* curr)
    {
        if(!curr) return NULL;
        if(curr->left) return curr->left;
        if(curr->right) return curr->right;
        return findNext(curr->next);
    }
};
```

## 124. Binary Tree Maximum Path Sum

路径至少经过一个节点
递归函数返回经过当前父节点的的最大路径和。
在递归函数中，如果当前结点不存在，直接返回0，否则就分别对其左右子节点调用递归函数。由于（左右子节点）路径和有可能为负数，所以要和0相比较大值，即要么不加，加就要加正数。然后通过求和 左路径和+右路径和+当前节点值 来更新全局最大值结果 res

// 2020-09-09 submission
// Runtime: 36 ms, faster than 89.91% of C++ online // submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 28.8 MB, less than 25.55% of C++ online submissions for Binary Tree Maximum Path Sum.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        helper(root, maxVal);
        return maxVal;
    }
    
    int helper(TreeNode* root, int& maxVal) {
        if(!root) return 0;
        int left_sum = max(0, helper(root->left, maxVal));
        int right_sum = max(0, helper(root->right, maxVal));
        // cout << "root: " << root->val << " path_sum: " << root->val + left_sum + right_sum << endl;
        maxVal = max(maxVal, root->val + left_sum + right_sum);
        return max(left_sum, right_sum) + root->val;
    }
};

## 128. Longest Consecutive Sequence

解题思路

1. 题目要求 $O(n)$ complexity
2. 使用一个集合HashSet存入所有的数字，然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，然后分别用两个变量pre和next算出其前一个数跟后一个数，然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可
3. 当检测某数字在集合中存在当时候，都要移除数字。这是为了避免大量的重复计算。

```C++
// 2020-09-16 submission
// Runtime: 24 ms, faster than 44.06% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 10.9 MB, less than 74.65% of C++ online submissions for Longest Consecutive Sequence.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> hash_set(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if(!hash_set.count(nums[i])) continue;
            hash_set.erase(nums[i]);
            int pre = nums[i], next = nums[i];
            while(hash_set.count(--pre)) hash_set.erase(pre);
            while(hash_set.count(++next)) hash_set.erase(next);
            max_len = max(max_len, next-pre-1);
        }
        return max_len;
    }
};
```

## 130. Surrounded Regions

解题思路

1. 题目关键在于找到所有与边缘 'O' 接壤的 'O' 位置。
2. DFS: 维护一个 mask 数组，保存所有与边缘 'O' 接壤的 'O' 位置，最后把除了这些位置以外的更新为 'X' 即可。

```C++
// 2020-09-20 submission
// Runtime: 32 ms, faster than 49.65% of C++ online submissions for Surrounded Regions.
// Memory Usage: 10.5 MB, less than 30.21% of C++ online submissions for Surrounded Regions.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int res = 0;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool> > mask(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows-1 || j == 0 || j == cols - 1) 
                    DFS(board, mask, i, j);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!mask[i][j]) board[i][j] = 'X';
            }
        }
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& mask, int i, int j) {
        if (board[i][j] != 'O' || mask[i][j]) return;
        mask[i][j] = true;
        if (i > 0) DFS(board, mask, i-1, j);
        if (i < board.size()-1) DFS(board, mask, i+1, j);
        if (j > 0) DFS(board, mask, i, j-1);
        if (j < board[0].size()-1) DFS(board, mask, i, j+1);
    }
};
```

## 133. Clone Graph

解题思路

1. 哈希+DFS：使用 HashMap 来对应原图中的结点和新生成的克隆图中的结点。在DFS递归函数中，首先判空，然后再看当前的结点是否已经被克隆过了，若在 HashMap 中存在，则直接返回其映射结点,否则就克隆当前结点，并在 HashMap 中建立映射，然后遍历当前结点的所有 neighbor 结点，调用递归函数并且加到克隆结点的 neighbors 数组中即可。

```C++
// 2020-11-11 submission
// Runtime: 12 ms, faster than 52.37% of C++ online submissions for Clone Graph.
// Memory Usage: 9.1 MB, less than 99.27% of C++ online submissions for Clone Graph.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return helper(node, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return node;
        if (m.count(node)) return m[node];
        Node* res = new Node(node->val);
        m[node] = res;
        for (Node* neighbor: node->neighbors) {
            res->neighbors.push_back(helper(neighbor, m));
        }
        return res;
    }
};
```

## 134. Gas Station

解题思路

1. 基本定理：如果一个数组的总和非负，那么一定可以找到一个起始位置，从他开始绕数组一圈，累加和一直都是非负的
2. 题目可转化为求最大连续和
3. $O(n)$ 做法：从位置 i 开始，i+1, i+2 ...，一路开过来一路油箱都没有空。说明从 i 到 i+1, i+2, ...一直是正积累。如果在位置 j 卡住走不下去，没必要从位置 i+1 重新走一遍，因为少了位置 i 的积累从 i+1 肯定走不到 j，所以可以直接从 j+1重新尝试，同时要把从 i 到 j 的负积累（debt）记录下来以便最后查看题目是否有解（详细看 1.定理）

```C++
// 2018-09-19 submission
// Runtime: 12 ms, faster than 67.53% of C++ online submissions for Gas Station.
// Memory Usage: 9.9 MB, less than 70.19% of C++ online submissions for Gas Station.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int debt = 0;
        int profit = 0;
        int res_idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            profit += (gas[i] - cost[i]);
            if (profit < 0) {
                debt += profit;
                profit = 0;
                res_idx = i + 1;
            }
        }
        return profit + debt >= 0 ? res_idx : -1;
    }
};
```

## 136. Single Number

解题思路

1. 题目描述：非空数组，除了 X 只出现一次其他所有元素都出现了两次，找出 X。
2. 位操作：两个相同的数取异或(^)结果为0，所以对所有数取异或，结果即为 X

```C++
// 2018-09-19 submission
// Runtime: 20 ms, faster than 92.90% of C++ online submissions for Single Number.
// Memory Usage: 12 MB, less than 65.67% of C++ online submissions for Single Number.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
```

## 138. Copy List with Random Pointer

解题思路

1. 哈希+递归：建立一个 HashMap 来建立原链表结点和拷贝链表结点之间的映射。在递归函数中，首先判空，若为空，则返回空指针。然后去 HashMap 中查找是否已经在拷贝链表中存在了该结点，是的话直接返回。否则新建一个拷贝结点 res，然后建立原结点和该拷贝结点之间的映射，然后给拷贝结点的 next 和 random 指针赋值。
2. 迭代：不占用额外的空间
   1. 在原链表的每个节点后面拷贝出一个新的节点（新节点随机指针设为空）。e.g. 7(null)->13(0)->11(4)->10(2)->1(0) 变成  7(null)->7(null)->13(0)->13(null)->11(4)->11(null)->10(2)->10(null)->1(0)->1(null)
   2. 依次给新的节点的随机指针赋值 cur->next->random = cur->random->next
   3. 断开链表可得到深度拷贝后的新链表。

```C++
// 2020-11-11 submission (哈希+递归)
// Runtime: 12 ms, faster than 89.42% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 11.9 MB, less than 33.30% of C++ online submissions for Copy List with Random Pointer.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val);
        m[node] = res;
        res->next = helper(node->next, m);
        res->random = helper(node->random, m);
        return res;
    }
};
```

```C++
// 2020-11-11 submission (迭代)
// Runtime: 12 ms, faster than 89.42% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 11.4 MB, less than 33.30% of C++ online submissions for Copy List with Random Pointer.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* cur = head;
        while(cur) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = cur->next->next;
        }

        cur = head;
        while(cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        Node* res = head->next;
        while(cur) {
            Node *t = cur->next;
            cur->next = t->next;
            if (t->next) t->next = t->next->next;
            cur = cur->next;
        }
        return res;
    }
};
```

## 139. Word Break

解题思路

1. 动态规划：判断“abcd”是否合法，可以通过判断 "a"&&"bcd" || "ab"&&"cd" || "abc"&&"d" || "abcd" 实现。用两个 for 循环来要遍历所有的子串，我们用 j 把 [0, i) 范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是 dp[j]，范围 [j, i) 就是 s.substr(j, i-j)，其中 dp[j] 是之前的状态，只需要在字典中查找 s.substr(j, i-j) 是否存在，如果二者均为 true，将 dp[i] 赋为 true，并且跳出循环，此时就不需要再用j去分 [0, i) 范围了，因为 [0, i) 范围已经可以拆分。

```C++
// 2020-07-18 submission
// Runtime: 16 ms, faster than 57.77% of C++ online submissions for Word Break.
// Memory Usage: 13.5 MB, less than 5.36% of C++ online submissions for Word Break.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
```

## 141. Linked List Cycle

解题思路

1. 双指针法：快指针每次走两格，慢指针每次走一格。如果快指针和慢指针相遇，则说明存在环。

```C++
// 2018-07-24 submission
// Runtime: 8 ms, faster than 95.86% of C++ online submissions for Linked List Cycle.
// Memory Usage: 7.8 MB, less than 46.24% of C++ online submissions for Linked List Cycle.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// fast-slow pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
```

## 142. Linked List Cycle II

解题思路

1. 先通过双指针法确定是否存在环，并且获取到环上的某点。
2. 找出这个环一共有几个节点(从重合的节点开始遍历一圈得到环中的节点数)
3. 从头开始设置快慢指针，快指针先移动环的节点数步，然后快慢指针一起移动。当快慢指针重合时，指向的节点就表示环的入口节点。（其实就是就是快慢指针都刚好走了一圈）

```C++
// 2020-09-17 submission
// Runtime: 12 ms, faster than 68.48% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.9 MB, less than 33.42% of C++ online submissions for Linked List Cycle II.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) { // find the loop
                ListNode* new_fast = head->next, *new_slow = head;
                while(slow->next != fast) { // count the nodes in the loop
                    slow = slow->next;
                    new_fast = new_fast->next;
                }
                while(new_slow != new_fast) {
                    new_slow = new_slow->next;
                    new_fast = new_fast->next;
                }
                return new_slow;
            }
        }
        return NULL;
    }
};
```

## 150. Evaluate Reverse Polish Notation

解题思路

1. 利用栈实现后缀表达式求值。

边界条件

1. 当运算对象为负数时候，注意不要和运算符号“-”混淆

```C++
// 2020-09-18 submission
// Runtime: 24 ms, faster than 80.69% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 12.2 MB, less than 17.79% of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() == 1 && tokens[i][0] < '0') { // ASCII中 + - * / 在 0 前面
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (tokens[i] == "+") stk.push(a + b);
                else if (tokens[i] == "-") stk.push(a - b);
                else if (tokens[i] == "*") stk.push(a * b);
                else stk.push(a / b);
                // cout << tokens[i] << " " << stk.top() << endl;
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
```

## 151. Reverse Words in a String

解题思路

1. 细节题目，注意各种边界条件即可
2. 可以认为单词是夹在边界或者空格中间，所以初始将 begin 设为-1（表示开始边界），之后每次遇到空格就更新 begin。同时遇到右边界或者有空格可以认为有单词结束，所以同时还需要加一个 word flag指示是否当前遍历为单词。

边界条件

1. 字符串为空
2. 字符串（开始）末尾（没）有空格

```C++
// 2020-09-19 submission
// Runtime: 16 ms, faster than 86.70% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 8.7 MB, less than 46.08% of C++ online submissions for Reverse Words in a String.
class Solution {
public:
    string reverseWords(string s) {
        string res_s;
        if (s.length() == 0) return res_s;
        vector<string> res;

        bool word = false;
        int begin = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && !word) {
                word = true;
            }
            if (s[i] == ' ') {
                if (word) res.push_back(s.substr(begin+1, i-begin-1));
                begin = i;
                word = false;
            }
        }
        if (s[s.length()-1] != ' ') res.push_back(s.substr(begin+1));

        for (int i = res.size()-1; i >= 0; i--) {
            res_s.append(res[i]);
            res_s.append(" ");
        }
        return res_s.substr(0, res_s.length()-1);
    }
};
```

## 162. Find Peak Element

解题思路

1. 二分搜索：折半后选择中间那个元素和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。对数时间复杂度。

```C++
// 2020-11-11 submission
// Runtime: 4 ms, faster than 97.33% of C++ online submissions for Find Peak Element.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Find Peak Element.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= nums[mid+1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
```

## 173. Binary Search Tree Iterator

解题思路

1. 通过中序遍历将二叉树转化成排序好的数组。

```C++
// 2020-09-19 submission
// Runtime: 76 ms, faster than 95.90% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 28 MB, less than 28.15% of C++ online submissions for Binary Search Tree Iterator.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder_traverse(root);
    }

    /** @return the next smallest number */
    int next() {
        return list[cur++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur < list.size();
    }

    void inorder_traverse(TreeNode* root) {
        if (!root) return;
        inorder_traverse(root->left);
        list.push_back(root->val);
        inorder_traverse(root->right);
    }

private:
    vector<int> list;
    int cur = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

## 187. Repeated DNA Sequences

解题思路

1. 基本做法：hash，将连续的十个字符映射为唯一，出现重复时就加入到结果
2. 同时，为了减少内存使用，可考虑位操作。用两位来表示一个字符，00 表示A，01 表示C，10 表示G，11 表示T，那么总共需要 20 位就可以表示十个字符流。

边界条件

1. 可能会出现多次重复（要去重）

```C++
// 2020-09-18 submission
// Runtime: 68 ms, faster than 93.74% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 14.9 MB, less than 97.44% of C++ online submissions for Repeated DNA Sequences.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res; // 用 set 替代 vector，因为可能出现多次重复
        unordered_set<int> hash_set;
        unordered_map<char, int> dna{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        for (int i = 0; i < 9; i++) {
            cur = cur << 2 | dna[s[i]];
        }
        for (int i = 9; i < s.length(); i++) {
            cur = (cur & 0x0003ffff) << 2 | dna[s[i]]; // 每次只保留 20-2=18 位，再加上后来的2位
            if (hash_set.count(cur)) res.insert(s.substr(i-9, 10));
            else hash_set.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};
```

## 198. House Robber

解题思路

1. 动态规划：首先，两个被打劫的家中间的间隔可能是1或2（不可能大于2）；然后维护一个一位数组 dp，其中 dp[i] 表示 [0, i] 区间可以抢夺的最大值（并且 i 位置要抢）。状态转移方程为 $\text{dp}[i] = \text{max}(\text{dp}[i-2], \text{dp}[i-3]) + \text{nums}[i]$。

```C++
// 2018-07-25 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for House Robber.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> maxSum;
        if(nums.size() >= 1) maxSum.push_back(nums[0]);
        if(nums.size() >= 2) maxSum.push_back(nums[1]);
        if(nums.size() >= 3) maxSum.push_back(nums[0]+nums[2]);
        for(int i = 3; i < nums.size(); i++) {
            auto temp = maxSum[i-2] > maxSum[i-3] ? maxSum[i-2] : maxSum[i-3];
            maxSum.push_back(temp + nums[i]);
        }
        return *max_element(maxSum.begin(), maxSum.end());
    }
};
```

## 200. Number of Islands

解题思路

1. DFS:维护一个 visited 数组用来记录某个位置是否被访问过，对于一个为 ‘1’ 且未被访问过的位置，递归进入其上下左右位置上为 ‘1’ 的数，将其 visited 对应值赋为 true，继续进入其所有相连的邻位置，这样可以将这个连通区域所有的数找出来，并将其对应的 visited 中的值赋 true，找完相邻区域后，将结果 res 自增1，然后再继续找下一个为 ‘1’ 且未被访问过的位置

```C++
// 2020-09-20 submission
// Runtime: 28 ms, faster than 87.82% of C++ online submissions for Number of Islands.
// Memory Usage: 9.9 MB, less than 37.26% of C++ online submissions for Number of Islands.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool> > mask(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (DFS(grid, mask, i, j)) res++;
            }
        }

        return res;
    }

    bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& mask, int i, int j) {
        if (mask[i][j] || grid[i][j]=='0') return false;
        mask[i][j] = true;
        if (i > 0) DFS(grid, mask, i-1, j);
        if (i < grid.size()-1) DFS(grid, mask, i+1, j);
        if (j > 0) DFS(grid, mask, i, j-1);
        if (j < grid[0].size()-1) DFS(grid, mask, i, j+1);
        return true;
    }
};
```

## 201. Bitwise AND of Numbers Range

解题思路

1. 结果数是该数字范围内所有的数的左边共同的 '1' 部分

```C++
// 2020-07-20 submission
// Runtime: 16 ms, faster than 42.97% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 5.9 MB, less than 94.20% of C++ online submissions for Bitwise AND of Numbers Range.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};
```

## 208. Implement Trie (Prefix Tree)

解题思路

1. 前缀树：对每个结点开一个字母集大小的数组，对应的下标是儿子所表示的字母，内容则是这个儿子对应在大数组上的位置，即标号

边界条件

1. 先插入 apple, 再插入 app，所以需要对每一个节点设置 is_word 标志位，不能简单通过是不是叶子节点来判断。

```C++
// 2020-11-04 submission
// Runtime: 80 ms, faster than 79.93% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 45.3 MB, less than 5.00% of C++ online submissions for Implement Trie (Prefix Tree).
class Node{
public:
    Node* child[26];
    bool is_word;
    Node() {
        is_word = false;
        for (auto& ptr : child) {
            ptr = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) {
                cur->child[word[i]-'a'] = new Node();
            }
            cur = cur->child[word[i]-'a'];
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) return false;
            cur = cur->child[word[i]-'a'];
        }
        return cur->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            if(!cur->child[prefix[i]-'a']) return false;
            cur = cur->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

## 209. Minimum Size Subarray Sum

解题思路

1. 滑动窗口：用两个指针分别子数组的左右的边界位置，然后让 right 向右移，直到子数组和大于等于给定值，此时将 left 向右移一位，然后在 sum 中减去移去的值，然后重复上面的步骤。这是 O(n) 的解法。
2. 二分搜索：建立一个比原数组长一位的 sums 数组，其中 sums[i] 表示 nums 数组中 [0, i - 1] 的和，然后对于 sums 中每一个值 sums[i]，用二分查找法找到子数组的右边界位置，使该子数组之和大于 sums[i] + s，然后更新最短长度的距离即可。这是 O(nlgn) 的解法。

边界条件

1. 数组不存在大于等于指定值的子序列

Follow up

1. 去掉所有数字是正数的限制条件

```C++
// 2020-11-04 submission (滑动窗口)
// Runtime: 12 ms, faster than 93.12% of C++ online submissions for Minimum Size Subarray Sum.
//Memory Usage: 10.9 MB, less than 93.00% of C++ online submissions for Minimum Size Subarray Sum.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l_pivot = 0;
        int res = INT_MAX;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            while (cur >= s) {
                res = min(res, i-l_pivot+1);
                cur -= nums[l_pivot];
                ++l_pivot;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

```C++
// 2020-11-04 submission (二分搜索)
// Runtime: 12 ms, faster than 93.12% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 11.2 MB, less than 93.00% of C++ online submissions for Minimum Size Subarray Sum.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n, t = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) left = mid + 1;
                else right = mid - 1;
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

## 212. Word Search II

解题思路

1. 前缀树+DFS

Follow Up:

<https://leetcode.com/problems/word-search-ii/discuss/59780/Java-15ms-Easiest-Solution-(100.00>

```C++
// 2020-12-13 submission
// Runtime: 1016 ms, faster than 18.19% of C++ online submissions for Word Search II.
// Memory Usage: 9 MB, less than 52.69% of C++ online submissions for Word Search II.
class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            word = "";
            for (TrieNode*& ptr : child)
                ptr = NULL;
        }
    };
    
    struct TrieTree {
        TrieNode* root;
        TrieTree() : root(new TrieNode()) {}
        void insert(string word) {
            TrieNode* cur = root;
            for (char c : word) {
                if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }
            cur->word = word;
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return vector<string>{};
        vector<string> res;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        TrieTree* tree = new TrieTree();
        for (string word : words)
            tree->insert(word);
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                DFS(board, visited, res, i, j, tree->root);
            }
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& res, int x, int y, TrieNode* cur) {
        if (0 > x || x >= board.size() || 0 > y || y >= board[0].size() || visited[x][y]) return;
        visited[x][y] = true;
        char c = board[x][y];
        if (cur->child[c-'a']) {
            cur = cur->child[c-'a'];
            if (cur->word != "") {
                res.push_back(cur->word);
                cur->word.clear();
            }
            DFS(board, visited, res, x-1, y, cur);
            DFS(board, visited, res, x+1, y, cur);
            DFS(board, visited, res, x, y-1, cur);
            DFS(board, visited, res, x, y+1, cur);
        }
        visited[x][y] = false;
    }
};
```

## 213. House Robber II

解题思路

1. 动态规划：房子围成环后，可以发现第一家和最后一家不能同时抢，恰好分解为两个子问题：分别计算去掉第一家和最后一家后能抢到的最大值，对两个极大值取最大即为所求。

```C++
// 2020-11-04 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
// Memory Usage: 8.2 MB, less than 5.25% of C++ online submissions for House Robber II.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }

    int helper(vector<int>& nums, int s, int e) {
        vector<int> dp;
        if (e - s >= 1) dp.push_back(nums[s]);
        if (e - s >= 2) dp.push_back(nums[s+1]);
        if (e - s >= 3) dp.push_back(nums[s] + nums[s+2]);
        for (int i = 3; i < e - s; i++) {
            dp.push_back(max(dp[i-2], dp[i-3]) + nums[s+i]);
        }
        // cout << *max_element(dp.begin(), dp.end()) << endl;
        return *max_element(dp.begin(), dp.end());
    }
};
```

## 217. Contains Duplicate

解题思路

1. 题目描述：对于数组(array)，判断是否重复值
2. hashset

```C++
// 2019-09-17 submission
// Runtime: 64 ms, faster than 79.78% of C++ online submissions for Contains Duplicate.
// Memory Usage: 20 MB, less than 69.02% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.count(nums[i])) return true;
            else st.insert(nums[i]);
        }
        return false;
    }
};
```

## 219. Contains Duplicate II

解题思路

1. 对于数组(array)，判断是否出现重复值，且重复值之间下标距离不大于 k
2. hashmap，存储值到下标的映射。从左到右遍历数组，如果当前值的当前下标距离当前值的前下标不大于 k, 则认为出现重复。

```C++
// 2019-09-17 submission
// Runtime: 52 ms, faster than 71.61% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 16.4 MB, less than 74.38% of C++ online submissions for Contains Duplicate II.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) && i-m[nums[i]]<=k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
```

## 222. Count Complete Tree Nodes

解题思路

1. brute force: 递归统计结点的个数
2. 完美二叉树：
   + 完美二叉树的第 \(i\) 层拥有 $2^{i-1}$ 个节点数；深度为 \(k\) 的完美二叉树总共有 $2^{k+1}-1$ 个节点数
   + 完美二叉树一定是完全二叉树，而完全二叉树不一定是完美二叉树
   + 由 root 根结点往下，分别找最靠左边和最靠右边的路径长度，如果长度相等，则证明二叉树最后一层节点是满的，是满二叉树，直接返回节点个数(2的h次方减1);如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)

```C++
// 2020-11-04 submission (brute force)
// Runtime: 44 ms, faster than 59.03% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 31.4 MB, less than 34.25% of C++ online submissions for Count Complete Tree Nodes.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

```C++
// 2020-11-04 submission (完美二叉树)
// Runtime: 36 ms, faster than 94.26% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 31.7 MB, less than 34.25% of C++ online submissions for Count Complete Tree Nodes.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

## 228. Summary Ranges (2020-10-29)

解题思路

1. 用一个 nx2 的数组维护范围，若新数大于范围数组最后一个的右范围，就开辟新范围。

边界条件

1. $b - a <= 1$ 应写成 $a - 1 <= b$，防止溢出

```C++
// 2020-10-29 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Summary Ranges.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        vector<vector<int> > helper{vector<int>{nums[0], nums[0]}};
        for (int i = 1; i < nums.size(); i++) {
            // if (nums[i] - nums[i-1] <= 1) helper[helper.size()-1][1] = nums[i];
            if (nums[i-1] + 1 >= nums[i]) helper[helper.size()-1][1] = nums[i];
            else helper.push_back(vector<int>{nums[i], nums[i]});
        }
        for (int i = 0; i < helper.size(); i++) {
            if(helper[i][0] == helper[i][1]) res.push_back(to_string(helper[i][0]));
            else res.push_back(to_string(helper[i][0]) + "->" + to_string(helper[i][1]));
        }
        return res;
    }
};
```

## 238. Product of Array Except Self

解题思路

1. 创建出这两个数组，分别从数组的两个方向遍历就可以分别创建出乘积累积数组。为了进行空间上的优化，由于最终的结果都是要乘到结果 res 中，所以可以不用单独的数组来保存乘积，而是直接累积到结果 res 中，我们先从前面遍历一遍，将乘积的累积存入结果 res 中，然后从后面开始遍历，用到一个临时变量 right，初始化为1，然后每次不断累积，最终得到正确结果。

```C++
// 2020-10-29 submission
// Runtime: 28 ms, faster than 66.19% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 24.4 MB, less than 43.20% of C++ online submissions for Product of Array Except Self.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i = nums.size()-2; i >= 0; i--) { // notice that nums.size() >= 2
            right  *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};
```

## 239. Sliding Window Maximum

解题思路

1. multiset: multiset是一种基于红黑树的数据结构，可以自动对元素进行排序，允许有重复值。首先遍历每个数字，即窗口右移，若超过了k，则需要把左边界值删除，这里不能直接删除 nums[i-k]，因为集合中可能有重复数字，而 erase 默认是将所有和目标值相同的元素都删掉，所以我们只能提供一个 iterator，代表一个确定的删除位置，先通过 find() 函数找到左边界 nums[i-k] 在集合中的位置再删除。然后将当前数字插入到集合中，此时看若 i >= k-1，说明窗口大小正好是k，就需要将最大值加入结果 res 中，而由于 multiset 是按升序排列的，最大值在最后一个元素，可以通过 rbegin() 来取出。
2. deque: 用双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是 i-k，表示此时窗口向右移了一步，则移除队首元素。然后比较队尾元素和将要进来的值，如果小的话就都移除，这样可以确保队列中为近似降序排列。

```C++
// 2020-11-24 submission (multiset)
// Runtime: 960 ms, faster than 13.14% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 166.7 MB, less than 5.72% of C++ online submissions for Sliding Window Maximum.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if (i + 1 >= k) res.push_back(*st.rbegin());
        }
        return res;
    }
};
```

```C++
// 2020-11-24 submission (deque)
// Runtime: 336 ms, faster than 94.72% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 106.9 MB, less than 58.01% of C++ online submissions for Sliding Window Maximum.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i + 1 >= k) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```

## 263. Ugly Number

解题思路

1. 丑数只含有质因数 (2, 3, 5)，那么只要对某数不断除以 (2, 3, 5) 直到剩余数字为1即可判断为丑数

边界条件

1. 1 也是丑数

```C++
// 2019-09-11 submission
// Runtime: 4 ms, faster than 49.57% of C++ online submissions for Ugly Number.
// Memory Usage: 5.9 MB, less than 87.59% of C++ online submissions for Ugly Number.
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while(num%2 == 0) num /= 2;
        while(num%3 == 0) num /= 3;
        while(num%5 == 0) num /= 5;
        return num == 1;
    }
};
```

## 264. Ugly Number II

解题思路

1. 新的丑数可以认为是从已有的丑数序列生成的。
2. 为 (2, 3, 5) 都各自分配一个下标指向丑数序列，其实就可以当做是三个已经生成的序列，每次都从这三个列表中取出当前最小的那个作为新丑数，当有新的丑数加入就把产生效果的下标加1。

```C++
// 2020-09-21 submission
// Runtime: 12 ms, faster than 67.00% of C++ online submissions for Ugly Number II.
// Memory Usage: 9.6 MB, less than 37.73% of C++ online submissions for Ugly Number II.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        int cur = 0;
        for (int i = 1; i < n; i++) {
            cur = min(min(res[i2]*2, res[i3]*3), res[i5]*5);
            res.push_back(cur);
            if (cur == res[i2]*2) i2++;
            if (cur == res[i3]*3) i3++;
            if (cur == res[i5]*5) i5++;
            // cout << cur << " " << i2 << " " << i3 << " " << i5 <<endl;
        }
        return res[n-1];
    }
};
```

## 274. H-Index

解题思路

1. 降序排序：可以按照如下方法确定某人的 H 指数：1、将其发表的所有SCI论文按被引次数从高到低排序；2、从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。所得序号减一即为H指数。
2. 桶排序： <https://leetcode.com/problems/h-index/discuss/70768/Java-bucket-sort-O(n)-solution-with-detail-explanation>

```C++
// 2020-11-11 submission
// Runtime: 8 ms, faster than 33.71% of C++ online submissions for H-Index.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for H-Index.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h_idx = 1;
        for (; h_idx <= citations.size(); h_idx++) {
            if (h_idx > citations[h_idx-1]) break;
        }
        return h_idx - 1;
    }
};
```

## 279. Perfect Squares

解题思路

1. 动态规划：i 从 0 循环到 n，j 从 1 循环到 $i + j*j <= n$ 的位置，然后每次更新 dp[i+j*j] 的值，动态更新 dp 数组，其中 dp[i] 表示正整数i能少能由多个完全平方数组成。
2. 四平方和定理：每个正整数均可表示为不超过4个完全平方数的和。 因为任何数加上0²都不变。所以对于不够4个完全平方数的可以用0²补齐，于是四平方和定理等价为：任意一个正整数都可以写成4个完全平方数的和。
    规则1：如果这个数对4取余得0，可以把4除去（易知，这个过程可以不断重复），不影响结果；
    规则2：对4取余结束后，如果这个数对8取余得7，则这个数是四个完全平方数的和；
    根据规则1，先对这个数不断除4，然后根据规则2，如果这个数对8取余得7，则结果是4，否则，结果是1，2，3中的一个。显然，1，2很容易验证，若都不是那么就一定是3了。

```C++
// 2020-12-10 submission
// Runtime: 220 ms, faster than 59.84% of C++ online submissions for Perfect Squares.
// Memory Usage: 9.4 MB, less than 58.61% of C++ online submissions for Perfect Squares.
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i){
            for(int j = 1; i + j * j <= n; ++j){
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
```

```C++
// 2020-12-10 submission
// Runtime: 4 ms, faster than 97.60% of C++ online submissions for Perfect Squares.
// Memory Usage: 6.3 MB, less than 87.50% of C++ online submissions for Perfect Squares.
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};
```

## 290. Word Pattern

解题思路

1. 哈希：用两个 HashMap 来完成，分别将字符和单词都映射到当前的位置加1，注意这里需要加1就是为了避免默认映射值0，因为 C++ 中的 HashMap 的机制是若访问一个不存在的 key 值，会默认建立一个映射值为 0 的映射。

边界条件

1. s 和 p 长度不相等。

```C++
// 2020-11-08 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
// Memory Usage: 6.8 MB, less than 71.32% of C++ online submissions for Word Pattern.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.length();
        for (string word; in >> word; ++i) {
            if (i >= n || m1[pattern[i]] != m2[word]) return false; // i>=n 表示 p 长度比 s 短
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n; // s 已经遍历完，如果 i!=n(i<n) 表示 p 长度比 s 长
    }
};
```

## 313. Super Ugly Number

解题思路

1. 参见 ##264 做法，其实就是把 (2, 3, 5) 扩展到多个数字。
2. 使用一个下标数组存储每个质因数的当前下标，然后找到最小值后更新所有下标。

TODO

1. 使用小顶堆或者优先队列

```C++
// 2020-09-21 submission
// Runtime: 96 ms, faster than 75.60% of C++ online submissions for Super Ugly Number.
// Memory Usage: 9 MB, less than 64.69% of C++ online submissions for Super Ugly Number.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 1);
        vector<int> idx(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            int min_val = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                min_val = min(primes[j]*res[idx[j]], min_val);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (min_val == primes[j]*res[idx[j]]) idx[j]++;
            }
            res[i] = min_val;
            // cout << min_val << endl;
        }
        return res[n-1];
    }
};
```

## 326. Power of Three

```C++
// 2019-09-26 submission
// Runtime: 24 ms, faster than 14.94% of C++ online submissions for Power of Three.
// Memory Usage: 6.2 MB, less than 83.11% of C++ online submissions for Power of Three.
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
};
```

## 327. Count of Range Sum

解题思路

1. 首先计算出一个累计和数组 accum，$$\text{accum}[i]=\text{accum}[i-1]+nums[i]$$ 那问题可以转化为求解所有的区间$(j, i]$，满足 $$lower <= \text{accum}[i]-\text{accum}[j] <= upper$$(亦可写成$\text{accum}[i]-\text{upper} <= \text{accum}[j] <= \text{accum}[i]-\text{lower}$)。
 然后利用 STL 里的 multiset 容器，lower_bound() 是找数组中第一个不小于给定值的数(包括等于情况)，而 upper_bound() 是找数组中第一个大于给定值的数，distance() 方法返回两个迭代器之间的距离。

边界条件

1. 出现 INT_MIN 和 INT_MAX

```C++
// 2020-11-26 submission
// Runtime: 68 ms, faster than 48.47% of C++ online submissions for Count of Range Sum.
// Memory Usage: 15.1 MB, less than 61.69% of C++ online submissions for Count of Range Sum.
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        multiset<long long> st{0};
        long long cur_sum = 0; // 后续有减法操作避免溢出
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            res += distance(st.lower_bound(cur_sum-upper), st.upper_bound(cur_sum-lower));
            st.insert(cur_sum); // why this expression after
        }
        return res;
    }
};
```

## 342. Power of Four

解题思路

1. 位操作：通过 $n & (n - 1)$ 可以用来判断一个数是否为2的次方数，在此基础上发现 4 的次方数的最高位的 1 都是奇数位，所以只需要让原数和 `(0x55555555) <==> 1010101010101010101010101010101` 取与验证得到的数还是其本身；或者在确定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除。

```C++
// 2020-12-06 submission
// Runtime: 4 ms, faster than 33.76% of C++ online submissions for Power of Four.
// Memory Usage: 6.1 MB, less than 91.77% of C++ online submissions for Power of Four.
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0;
    }
};
```

## 357. Count Numbers with Unique Digits

解题思路

1. n=5 时，$\text{res} = 1 + 9 + 9*9 + 9*9*8*7 + 9*9*8*7*6 + 9*9*8*7*5$

```C++
// 2020-11-13 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Numbers with Unique Digits.
// Memory Usage: 6.2 MB, less than 35.40% of C++ online submissions for Count Numbers with Unique Digits.
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        int cur = 1;
        for (int i = 1, j = 10; i <= n; i++, j--) {
            cur *= min(9, j);
            res += cur;
        }
        return res + 1;
    }
};
```

## 344. Reverse String

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
```

## 367. Valid Perfect Square

解题思路

1. 从 1 搜索到 sqrt(num)，看有没有平方正好等于 num 的数

TODO

1. [O(1) 做法](https://leetcode.com/problems/valid-perfect-square/discuss/83872/O(1)-time-c%2B%2B-solution-inspired-by-Q_rsqrt)

```C++
// 2020-09-22 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 6.1 MB, less than 10.60% of C++ online submissions for Valid Perfect Square.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        for (int i = 2; i <= int(sqrt(num)); i++) {
            if (num % i == 0 && num / i == i) return true;
        }
        return false;
    }
};
```

## 374. Guess Number Higher or Lower

解题思路

1. 二分搜索

```C++
// 2020-09-22 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess Number Higher or Lower.
// Memory Usage: 6.1 MB, less than 15.75% of C++ online submissions for Guess Number Higher or Lower.
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        int middle = 0, res = 0;
        while(true) {
            middle = start + (end - start) / 2;
            res = guess(middle);
            if (res == 0) return middle;
            else if (res < 0) end = middle-1;
            else start = middle + 1;
        }
    }
};
```

## 383. Ransom Note

```C++
// 2020-11-02 submission
// Runtime: 32 ms, faster than 73.30% of C++ online submissions for Ransom Note.
// Memory Usage: 9.3 MB, less than 99.23% of C++ online submissions for Ransom Note.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (char c : magazine)
            hash[c]++;
        for (char c : ransomNote) {
            hash[c]--;
            if (hash[c] < 0) return false;
        }
        return true;
    }
};
```

## 390. Elimination Game

解题思路

1. 可以发现，从左往右删的时候，每次都是删掉第一个数字，而从右往左删的时候，则有可能删掉第一个或者第二个数字（剩下数字是偶数个时，删掉的是第二个数字），而且每删一次，数字之间的距离会变为之前的两倍，所以只需要记录每次删减后数组的第一个数字即可。

```C++
// 2020-12-06 submission
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Elimination Game.
// Memory Usage: 6.3 MB, less than 44.34% of C++ online submissions for Elimination Game.
class Solution {
public:
    int lastRemaining(int n) {
        bool ltor = true;
        int step = 1, cur = 1;
        while (n > 1) {
            if (ltor || n % 2) cur += step;
            step *= 2;
            ltor = not ltor;
            n /= 2;
        }
        return cur;
    }
};
```

## 391. Perfect Rectangle

解题思路

1. hash: 可以发现所有顶点除了边缘四个角，剩下的要么出现两次要么出现四次。最后还需要计算所有矩形面积是否等于整体矩形面积（避免重叠）
2. 位操作：对于矩形的四个顶点，按照左下，左上，右上，右下的顺序来给顶点标号为1(0001)，2(0010)，4(0100)，8(1000)。判定条件是，当一个点是某一个矩形的左下顶点时，这个点就不能是其他矩形的左下顶点了，这个条件对于这四种顶点都要成立。
   ![391. 不同类型的点](res/2020-12-10-14-19-57.png)
   通过分析，每个点只能是蓝，绿，红三种情况的一种，其中蓝的情况是 mask 的四位中只有一个 1，分别就是 1(0001)，2(0010)，4(0100)，8(1000)，而且蓝点只能有四个；那么对于T型的绿点，mask的四位中有两个1，那么就有六种情况，分别是12(1100), 10(1010), 9(1001), 6(0110), 5(0101), 3(0011)；而对于红点，mask的四位都是1，只有一种情况15(1111)，那么我们可以通过直接找mask是1，2，4，8的个数，也可以间接通过找不是绿点和红点的个数，看是否是四个。最后一个判定条件是每个矩形面积累加和要等于最后的大矩形的面积.。

边缘条件

1. 大矩形中间套两个重叠的小矩形

```C++
// 2020-12-10 submission
// Runtime: 272 ms, faster than 45.91% of C++ online submissions for Perfect Rectangle.
// Memory Usage: 37.5 MB, less than 15.46% of C++ online submissions for Perfect Rectangle.
class Solution { 
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        unordered_map<string, int> m;
        int min_w = INT_MAX, max_w = 0, min_h = INT_MAX, max_h = 0;
        int res_area = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            min_w = min(min_w, rectangles[i][0]);
            max_w = max(max_w, rectangles[i][2]);
            min_h = min(min_h, rectangles[i][1]);
            max_h = max(max_h, rectangles[i][3]);
            m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][1])]++;
            m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][3])]++;
            m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][1])]++;
            m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][3])]++;
            res_area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }
        
        unordered_set<string> angle{to_string(min_w) + "_" + to_string(min_h),
                                    to_string(min_w) + "_" + to_string(max_h),
                                    to_string(max_w) + "_" + to_string(min_h),
                                    to_string(max_w) + "_" + to_string(max_h)};
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (angle.count(it->first)) {
                if (it->second != 1) return false;
            }
            else {
                if (!(it->second == 2 || it->second == 4)) return false;
            }
        }
        return res_area == (max_w-min_w)*(max_h-min_h);
    }
};
```

```C++
// 2020-12-10 submission
// Runtime: 256 ms, faster than 55.00% of C++ online submissions for Perfect Rectangle.
// Memory Usage: 38.6 MB, less than 12.27% of C++ online submissions for Perfect Rectangle.
class Solution { 
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> m;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0, cnt = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[1]), 1)) return false; // bottom-left
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[3]), 2)) return false; // top-left
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[3]), 4)) return false; // top-right
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[1]), 8)) return false; // bottom-right
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            int t = it->second;
            if (t != 15 && t != 12 && t != 10 && t != 9 && t != 6 && t != 5 && t!= 3) {
                ++cnt;
            }
        }
        return cnt == 4 && area == (max_x - min_x) * (max_y - min_y);
    }
    
    bool isValid(unordered_map<string, int>& m, string corner, int type) {
        int& val = m[corner];
        if (val & type) return false;
        val |= type;
        return true;
    }
};
```

## 392. Is Subsequence

```C++
// 2020-12-06 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.6 MB, less than 86.33% of C++ online submissions for Is Subsequence.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i = 0;
        for (int i = 0; i < t.length() && s_i < s.length(); i++) {
            if (t[i] == s[s_i]) s_i++;
        }
        return s_i == s.length();
    }
};
```

## 404. Sum of Left Leaves

解题思路

1. 题目描述：计算二叉树所有左叶子节点的和
2. 需要传递一个标志位，因为一个节点是否为左节点是由父节点决定的。

```C++
// 2020-12-11 submission
// Runtime: 4 ms, faster than 79.99% of C++ online submissions for Sum of Left Leaves.
// Memory Usage: 13.6 MB, less than 95.47% of C++ online submissions for Sum of Left Leaves.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* root, bool is_left) {
        if (!root) return 0;
        if (!root->left && !root->right) return is_left ? root->val : 0;
        return helper(root->left, true) + helper(root->right, false);
    }
};
```

## 414. Third Maximum Number

解题思路

1. 初始化三个数字为最小值，因为有可能出现INT_MIN，所以要用LLONG_MIN。然后根据每次迭代的数字依次更新三个候选数。需要注意的是等于候选数的数字。

边界条件

1. 数组长度小于3
2. 数组中独特数字数量小于3
3. INT_MIN在数组中

```C++
// 2020-12-11 submission
// Runtime: 8 ms, faster than 86.86% of C++ online submissions for Third Maximum Number.
// Memory Usage: 9.3 MB, less than 83.57% of C++ online submissions for Third Maximum Number.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long A = LLONG_MIN, B = LLONG_MIN, C = LLONG_MIN;
        for (int num : nums) {
            if (num > A) {
                C = B; B = A; A = num;
            }
            else if (A > num && num > B) {
                C = B; B = num;
            }
            else if (B > num && num > C) {
                C = num;
            }
            // cout << A << " " << B << " " << C << endl;
        }
        return C > LLONG_MIN ? C : A;
    }
};
```

## 455. Assign Cookies

解题思路

1. 贪心策略：首先对两个数组进行排序。只有满足了当前的小朋友，才会去满足下一个胃口较大的小朋友。

```C++
// 2020-11-02 submission
// Runtime: 60 ms, faster than 98.72% of C++ online submissions for Assign Cookies.
// Memory Usage: 17.8 MB, less than 91.35% of C++ online submissions for Assign Cookies.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i=0, j=0; i<g.size() && j<s.size();) {
            if (s[j] >= g[i]) {
                i++;
                j++;
                res++;
            }
            else j++;
        }
        return res;
    }
};
```

## 492. Construct the Rectangle

```C++
// 2020-12-11 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct the Rectangle.
// Memory Usage: 6.6 MB, less than 31.57% of C++ online submissions for Construct the Rectangle.
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = 1;
        for (int i = 2; i <= int(sqrt(area)); i++) {
            if (area % i == 0) W = i;
        }
        return vector<int>{area / W, W};
    }
};
```

## 507. Perfect Number

解题思路

1. 题目描述：完数 = 他所有正除数（不包括他本身）之和
2. 从 1 计数到 sqrt(n)，然后计数所有 i 和 n/i。

```C++
// 2020-11-13 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect Number.
// Memory Usage: 6 MB, less than 81.46% of C++ online submissions for Perfect Number.
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= int(sqrt(num)); i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) sum += (num / i);
            } 
        }
        return sum == 2 * num;
    }
};
```

## 563. Binary Tree Tilt

解题思路

1. 后续遍历：返回值为当前子树的结点之和，所以需要一个参数来专门记录坡度和。

```C++
// 2019-05-18 submission
// Runtime: 24 ms, faster than 66.39% of C++ online submissions for Binary Tree Tilt.
// Memory Usage: 24.1 MB, less than 6.16% of C++ online submissions for Binary Tree Tilt.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        search(root, result);
        return result;
    }

    int search(TreeNode* root, int& tilt_sum) {
        if (!root) return 0;
        int left = search(root->left, tilt_sum);
        int right = search(root->right, tilt_sum);
        tilt_sum += abs(left-right);
        return root->val + left + right;
    }

};
```

## 700. Search in a Binary Search Tree

```C++
// 2020-12-10 submission
// Runtime: 52 ms, faster than 77.49% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 35.6 MB, less than 41.77% of C++ online submissions for Search in a Binary Search Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        else if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};
```

1.   Binary Tree Postorder Traversal
解题思路：后续遍历-递归或迭代
（迭代）使用栈实现。最开始将根节点压入栈。迭代开始时每次取出栈顶节点，如果当前节点为叶节点或者子树节点为之前弹出节点head，则认为当前节点需要加入输出集，弹出当前节点并标记为head；如果不是则将当前节点右子树和左子树压入栈（注意栈先入后出的特性）。head初始化可以初始化为root，但是绝对不能为空，因为有可能会出现节点只有左子树或者右子树的情况，这样会直接弹出当前节点，这明显不符合情况。

// 2020-07-17 submission
(recursive )
Runtime: 4 ms, faster than 51.58% of C++ online submissions
Memory Usage: 8.7 MB, less than 26.67% of C++ online submissions
(iterative)
Runtime: 0 ms, faster than 100.00% of C++ online submissions
Memory Usage: 8.6 MB, less than 51.02% of C++ online submissions
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        iterate(root, res);
        return res;
        
    }
    
    void iterate(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        TreeNode* head = root;
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            if ((!cur->left && !cur->right) || cur->left==head || cur->right==head) {
                res.push_back(cur->val);
                stk.pop();
                head = cur;
            }
            else {
                if (cur->right) stk.push(cur->right);
                if (cur->left) stk.push(cur->left);
            }
        }
    }
    
    void recursive(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        recursive(root->left, res);
        recursive(root->right, res);
        res.push_back(root->val);
    }
};

1.   Max Points on a Line
解题思路：直线由点和斜率决定，斜率可以通过pair表示，注意正负号的位置。比如斜率1.5可以表示为<3,2>，所以这里要取最大公约数得到互质数防止斜率重复。另外x==0和y==0和x==0&&y==0要单独考虑，尤其是x==0&&y==0的重复点，可以加到任何结果集里面。注意取符号时候不要通过乘法运算防止溢出。整体思路通过双层循环解决，第一层循环决定直线的点，第二层循环建立一个pair到数量的map映射，最后得到最大值。

Runtime: 68 ms, faster than 25.76% of C++ online submissions
Memory Usage: 11.5 MB, less than 44.87% of C++ online submissions
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int max_num = 0;
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> collect;
            int max_cur = 0;
            for (int j = 0; j < points.size(); j++) {
                max_cur = max(max_cur, gcd(points[i][0]-points[j][0], points[i][1]-points[j][1], collect));
            }
            max_num = max(max_num, max_cur + collect[pair<int, int>{0, 0}]);
            // cout << max_num <<endl;
        }
        return max_num;
    }
    
    int gcd(int x, int y, map<pair<int, int>, int>& collect) {
        int cnt = 0;
        if ( x == 0 && y == 0) {
            ++collect[pair<int, int>{0, 0}];
        }
        else if (x == 0) {
            cnt = ++collect[pair<int, int>{0, 1}];
        }
        else if (y == 0) {
            cnt = ++collect[pair<int, int>{1, 0}];
        }
        else {
            int t = 0;
            int a = abs(x), b = abs(y), op = abs(x)/x*abs(y)/y;
            while(b > 0) {
                t = a % b;
                a = b;
                b = t;
            }
            cnt = ++collect[pair<int, int>{abs(x)/a*op, abs(y)/a}];
        }
        return cnt;
    }
};
