# Lock

## 156. Binary Tree Upside Down

题目描述：把一棵二叉树上下颠倒一下，而且限制了右节点要么为空要么一定会有对应的左节点。

## 157. Read N Characters Given Read4

题目描述：给定一个 Read4 函数，每次可以从一个文件中最多读出 4 个字符，如果文件中的字符不足 4 个字符时，返回准确的当前剩余的字符数。要求实现一个最多能读取n个字符的函数。

1. 迭代：思路是每4个读一次，然后把读出的结果判断一下，如果为0的话，说明此时的 buf 已经被读完，跳出循环，直接返回 res 和n之中的较小值。否则一直读入，直到读完n个字符，循环结束，最后再返回 res 和n之中的较小值

```C++
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};
```

## 158. Read N Characters Given read4 II - Call Multiple Times

## 159. Longest Substring with At Most Two Distinct Characters

题目描述：给定一个字符串，求最多有两个不同字符的最长子串。



## 161. One Edit Distance

题目描述：判断两个字符串的编辑距离是否为 1。

1. 需要对比两个字符串对应位置上的字符，如果遇到不同的时候，这时看两个字符串的长度关系，如果相等，则比较当前位置后的字串是否相同，如果 s 的长度大，那么比较 s 的下一个位置开始的子串，和 t 的当前位置开始的子串是否相同，反之如果 t 的长度大，则比较 t 的下一个位置开始的子串，和 s 的当前位置开始的子串是否相同。如果循环结束，都没有找到不同的字符，那么此时看两个字符串的长度是否相差1。

```C++
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
                if (s.size() < t.size()) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
            }
        }
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};
```

## 163. Missing Ranges

题目描述：求缺失区间。给了一个空间的范围 [lower upper]，缺失的区间的范围需要在给定的区间范围内。

1. 遍历 nums 数组，假如当前数字 num 大于 lower，说明此时已经有缺失区间，至少缺失一个 lower 数字，此时若 num-1 大于 lower，说明缺失的是一个区间 [lower, num-1]，否则就只加入一个数字即可。由于 OJ 之后加入了许多 tricky 的 test cases，使得论坛上很多解法都 fail 了。其实很多是跪在了整型溢出，当数组中有整型最大值时，此时 lower 更新为 num+1 时就会溢出，所以在更新之前要先判断一下，若 num 已经是整型最大值了，直接返回结果 res 即可；否则才更新 lower 继续循环。for 循环退出后，此时可能还存在缺失区间，就是此时 lower 还小于等于 upper 时，可以会缺失 lower 这个数字，或者 [lower, upper] 区间。

```C++
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (int num : nums) {
            if (num > lower) res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
            if (num == upper) return res;
            lower = num + 1;
        }
        if (lower <= upper) res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
        return res;
    }
};
```

## 170. Two Sum III - Data structure design

## 186. Reverse Words in a String II

题目描述：翻转一个字符串中的单词。

1. 使用 C++ STL 中自带的 reverse 函数来做，先把整个字符串翻转一下，然后再来扫描每个字符，用两个指针，一个指向开头，另一个开始遍历，遇到空格停止，这样两个指针之间就确定了一个单词的范围，直接调用 reverse 函数翻转，然后移动头指针到下一个位置，在用另一个指针继续扫描，重复上述步骤即可

```C++
class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        for (int i = 0, j = 0; i < str.size(); i = j + 1) {
            for (j = i; j < str.size(); ++j) {
                if (str[j] == ' ') break;
            }
            reverse(str.begin() + i, str.begin() + j);
        }
    }
};
```

## 243. Shortest Word Distance

题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，限定了两个单词不同，而且都在数组中。

1. 用一个辅助变量 idx，初始化为 -1，然后遍历数组，如果遇到等于两个单词中的任意一个单词，再看 idx 是否为 -1，若不为 -1，且指向的单词和当前遍历到的单词不同，更新结果

```cpp
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[idx] != words[i]) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
```

## 244. Shortest Word Distance II

题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，限定了两个单词不同，而且都在数组中。函数需要多次调用。

1. 用 HashMap 来建立每个单词和其所有出现的位置的映射，然后在找最短单词距离时，只需要取出该单词在 HashMap 中映射的位置数组进行两两比较即可。进一步优化：用两个指针i和j来指向位置数组中的某个位置，开始初始化都为0，然后比较位置数组中的数字，将较小的一个的指针向后移动一位，直至其中一个数组遍历完成即可。

```C++
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }
        return res;
    }

private:
    unordered_map<string, vector<int> > m;
};
```

## 245. Shortest Word Distance III

题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，两个单词可能相同。

1. 用一个变量 idx，这个 idx 的作用是记录上一次的位置，当前 idx 不等于 -1 时，说明当前 i 和 idx 不同，然后在 word1 和 word2 相同或者 words[i] 和 words[idx] 相同的情况下更新结果，最后将 idx 赋为 i。

```C++
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && (word1 == word2 || words[i] != words[idx])) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
```

## 246. Strobogrammatic Number

题目描述：判断给定数字是否为对称数，即一个数字旋转 180 度和原来一样，也就是倒过来看一样，比如 609，倒过来还是 609。

1. 满足这种条件的数字其实没有几个，只有 0,1,8,6,9。这道题其实可以看做求回文数的一种特殊情况，还是用双指针来检测，首尾两个数字如果相等的话，只有它们是 0,1,8 中间的一个才行，如果它们不相等的话，必须一个是 6 一个是 9，或者一个是 9 一个是 6。

```C++
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};
```

## 247. Strobogrammatic Number II

题目描述：找出长度为 n 的所有的对称数。

1. 递归：每个数字都在之前数字的左右增加了 [0 0]，[1 1], [6 9], [8 8], [9 6]。需要注意当加到了n层的时候，左右两边不能加 [0 0]，因为0不能出现在两位数及多位数的开头。
2. 迭代：思路一样，加入了奇偶考虑。

```C++
// 递归
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n), res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> one{"0", "1", "8"}, two{""}, res = two;
        if (n % 2 == 1) res = one;
        for (int i = (n % 2) + 2; i <= n; i += 2) {
            vector<string> t;
            for (auto a : res) {
                if (i != n) t.push_back("0" + a + "0");
                t.push_back("1" + a + "1");
                t.push_back("6" + a + "9");
                t.push_back("8" + a + "8");
                t.push_back("9" + a + "6");
            }
            res = t;
        }
        return res;
    }
};
```

## 248. Strobogrammatic Number III

题目描述：让找给定范围内的对称数的个数。

1. 参见 <247. Strobogrammatic Number II>，在递归中直接计数
   - 需要初始化 n=0 和 n=1 的情况，然后在其基础上进行递归
   - 递归的长度 len 从 low 到 high 之间遍历，然后看当前单词长度有没有达到 len，如果达到了，首先要去掉开头是 0 的多位数，然后去掉长度和 low 相同但小于 low 的数，和长度和 high 相同但大于 high 的数，然后结果自增 1
   - 然后分别给当前单词左右加上那五对对称数，继续递归调用

```cpp
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        find(low, high, "", res);
        find(low, high, "0", res);
        find(low, high, "1", res);
        find(low, high, "8", res);
        return res;
    }
    void find(string low, string high, string w, int &res) {
        if (w.length() >= low.length() && w.length() <= high.length()) {
            if (w.length() == high.length() && w.compare(high) > 0) {
                return;
            }
            if (!(w.length() > 1 && w[0] == '0') && !(w.length() == low.length() && w.compare(low) < 0)) {
                ++res;
            }
        }
        if (w.length() + 2 > high.length()) return;
        find(low, high, "0" + w + "0", res);
        find(low, high, "1" + w + "1", res);
        find(low, high, "6" + w + "9", res);
        find(low, high, "8" + w + "8", res);
        find(low, high, "9" + w + "6", res);
    }
};
```

## 249. Group Shifted Strings
## 250. Count Univalue Subtrees
## 251. Flatten 2D Vector

## 252. Meeting Rooms

题目描述：给了一些会议的开始时间和结束时间，问能不能同时参见所有的会议，这实际上就是求区间是否有交集的问题。

1. 排序
   - 给所有区间排个序，用起始时间的先后来排
   - 然后从第二个区间开始，如果开始时间早于前一个区间的结束时间，则说明会议时间有冲突，返回 false
   - 遍历完成后没有冲突，则返回 true

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};
```

## 253. Meeting Rooms II

题目描述：给了一些会议的开始时间和结束时间，最少需要安排几个会议室，有时间冲突的会议需要安排在不同的会议室。

1. 两个一维数组，分别保存起始时间和结束时间，然后各自排个序，定义结果变量 res 和结束时间指针 endpos，然后开始遍历，如果当前起始时间小于结束时间指针的时间，则结果自增1，反之结束时间指针自增1，这样可以找出重叠的时间段，从而安排新的会议室。
2. 最小堆
   - 先把所有的时间区间按照起始时间排序，然后新建一个最小堆
   - 开始遍历时间区间，如果堆不为空，且首元素小于等于当前区间的起始时间，去掉堆中的首元素，把当前区间的结束时间压入堆，由于最小堆是小的在前面，那么假如首元素小于等于起始时间，说明上一个会议已经结束，可以用该会议室开始下一个会议了，所以不用分配新的会议室
   - 遍历完成后堆中元素的个数即为需要的会议室的个数

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto a : intervals) {
            starts.push_back(a[0]);
            ends.push_back(a[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) ++res;
            else ++endpos;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto interval : intervals) {
            if (!q.empty() && q.top() <= interval[0]) q.pop();
            q.push(interval[1]);
        }
        return q.size();
    }
};
```

## 254. Factor Combinations
## 255. Verify Preorder Sequence in Binary Search Tree

## 256. Paint House

题目描述：有 n 个房子，每个房子可以用红绿蓝三种颜色刷，每个房子的用每种颜色刷的花费都不同，限制条件是相邻的房子不能用相同的颜色来刷，求刷完所有的房子的最低花费是多少。

1. 动态规划： `dp[i][j]` 表示刷到房子 i 子用颜色 j 的最小花费，状态转移方程为: `dp[i][j] = dp[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3])`，当前房子用红色刷的最小花费就等于当前房子用红色刷的钱加上刷到上一个房子用绿色和刷到上一个房子用蓝色中的较小值。

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] += min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
                // dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
                // dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
                // dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};
```

## 259. 3Sum Smaller
## 261. Graph Valid Tree

## 265. Paint House II

题目描述：有 n 个房子，每个房子可以用 k 种颜色刷，每个房子的用每种颜色刷的花费都不同，限制条件是相邻的房子不能用相同的颜色来刷，求刷完所有的房子的最低花费是多少。

1. 动态规划：参见 <256. Paint House>，刷房子 i 时，只需要保留花费最低的两种颜色。

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int min1 = 0, min2 = 0, idx1 = -1;
        for (int i = 0; i < costs.size(); ++i) {
            int m1 = INT_MAX, m2 = m1, id1 = -1;
            for (int j = 0; j < costs[i].size(); ++j) {
                int cost = costs[i][j] + (j == idx1 ? min2 : min1);
                if (cost < m1) {
                    m2 = m1; m1 = cost; id1 = j;
                } else if (cost < m2) {
                    m2 = cost;
                }
            }
            min1 = m1; min2 = m2; idx1 = id1;
        }
        return min1;
    }
};
```

## 266. Palindrome Permutation
## 267. Palindrome Permutation II
## 269. Alien Dictionary
## 270. Closest Binary Search Tree Value
## 271. Encode and Decode Strings
## 272. Closest Binary Search Tree Value II

## 276. Paint Fence

题目描述：粉刷篱笆，有 n 个部分需要刷，有 k 种颜色的油漆，规定了不能有超过连续两根柱子是一个颜色，也就意味着第三根柱子要么和第一个柱子不是一个颜色，要么和第二根柱子不是一个颜色，问总共有多少种刷法。

1. 找规律
   - n = 0，没有刷的部分，返回 0
   - n = 1，有几种颜色，就有几种刷法，所以应该返回 k
   - n > 1，分两种情况讨论，一种是相邻部分没有相同的，一种相同部分有相同的颜色，相邻部分不同情况中，对于下一个相邻的格子，由于不能相同，所以只有 k-1 种填法；相邻部分相同情况中，刷法和上一个格子的不同颜色刷法相同。

```cpp
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int same = 0, diff = k, res = same + diff;
        for (int i = 2; i <= n; ++i) {
            same = diff;
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
    }
};
```

## 277. Find the Celebrity

题目描述：在一群人中寻找名人，所谓名人就是每个人都认识他，他却不认识任何人，限定了只有 1 个或 0 个名人，给定了一个 API 函数，输入 a 和 b，用来判断 a 是否认识 b ，尽可能少调用这个函数来找出人群中的名人。

1. 先遍历一遍，对于遍历到的人i，若候选人 res 认识i，则将候选人 res 设为i，完成一遍遍历后，来检测候选人 res 是否真正是名人，如果判断不是名人，则返回 -1，如果并没有冲突，返回 res。
2. 还可以进一步减少 API 的调用量，在验证的时候分为两段，先验证候选者前面的所有人，若候选者认识任何人，或者任何人不认识候选者，直接返回 -1。再验证候选者后面的人，这时候只需要验证是否有人不认识候选者就可以了，因为在最开始找候选者的时候就已经保证了候选者不会认识后面的任何人。

```cpp
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};
```

```cpp
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < res; ++i) {
            if (knows(res, i) || !knows(i, res)) return -1;
        }
        for (int i = res + 1; i < n; ++i) {
            if (!knows(i, res)) return -1;
        }
        return res;
    }
};
```

## 280. Wiggle Sort
## 281. Zigzag Iterator
## 285. Inorder Successor in BST

## 286. Walls and Gates

题目描述：二维迷宫，规定了 -1 表示墙，0表示门，让求每个点到门的最近的曼哈顿距离。

1. DFS：搜索0的位置，每找到一个0，以其周围四个相邻点为起点，开始 DFS 遍历，并带入深度值1，如果遇到的值大于当前深度值，将位置值赋为当前深度值，并对当前点的四个相邻点开始DFS遍历，注意此时深度值需要加1，这样遍历完成后，所有的位置就被正确地更新了。
2. BFS：首先把门的位置都排入 queue 中，然后开始循环，对于门位置的四个相邻点，判断其是否在矩阵范围内，并且位置值是否大于上一位置的值加 1，如果满足这些条件，将当前位置赋为上一位置加 1，并将次位置排入 queue 中，这样等 queue 中的元素遍历完了，所有位置的值就被正确地更新了。

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) dfs(rooms, i, j, 0);
            }
        }
    }
    void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] < val) return;
        rooms[i][j] = val;
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i, j + 1, val + 1);
        dfs(rooms, i, j - 1, val + 1);
    }
};
```

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second; q.pop();
            for (int k = 0; k < dirs.size(); ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};
```

## 288. Unique Word Abbreviation

题目描述：给定字典（字符串列表）和单词，求单词是否有唯一缩写形式。缩写定义为：除了首尾字母保留，计算剩下字母的个数。

1. Hashmap：建立缩写形式和其对应的单词的映射
   - 在遇到 HashMap 中没有当前缩写形式的时候，将该缩写形式和当前单词建立映射，如果该缩写形式应经存在，那么看如果映射的单词不是当前单词，将映射单词改为空字符串。

**边界条件**

1. 字典中有重复单词
2. 目标单词不在字典中
3. 只有两个字母的单词缩写为自己本身。

```cpp
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto a : dictionary) {
            string k = a;
            if (a.length() > 2) k = a[0] + to_string(a.length() - 2) + a.back();
            if (m.find(k) != m.end() && m[k] != a) m[k] = "";
            else m[k] = a;
        }
    }
    bool isUnique(string word) {
        string k = word;
        if (word.length() > 2) k = word[0] + to_string(word.length() - 2) + word.back();
        return m.find(k) == m.end() || m[k] == word;
    }

private:
    unordered_map<string, string> m;
};
```

## 291. Word Pattern II

## 293. Flip Game

题目描述：给定只有 '+' 和 '-' 的字符串，一次操作后 '++' 可以转化 '--'，求一次操作后所有可能的结果。

1. 从第二个字母开始遍历，每次判断当前字母是否为 '+'，和之前那个字母是否为 '+'，如果都为 '+'，则将翻转后的字符串存入结果中即可。

```cpp
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        return res;
    }
};
```

## 294. Flip Game II

题目描述：给定只有 '+' 和 '-' 的字符串，一次操作后 '++' 可以转化 '--'，两个玩家先后进行操作，如果某个玩家无法再操作则游戏结束，对方取胜。给定字符串，判断先手玩家是否能赢。




## 296. Best Meeting Point

题目描述：求最佳的开会地点，该地点需要到每个为1的点的曼哈顿距离之和最小。

1. 先从一维情况讨论：
   - A_____P_______B_，只要开会为位置P在 [A, B] 区间内，不管在哪，距离之和都是A和B之间的距离，如果P不在 [A, B] 之间，那么距离之和就会大于 A 和 B 之间的距离
   - C_____A_____P_______B______D，P 点的最佳位置就是在 [A, B] 区间内，这样和四个点的距离之和为 AB 距离加上 CD 距离，在其他任意一点的距离都会大于这个距离
   - 只要给位置排好序，然后用最后一个坐标减去第一个坐标，即 CD 距离，倒数第二个坐标减去第二个坐标，即 AB 距离，以此类推，直到最中间停止
   - 二维的情况就是两个一维相加即可

```cpp
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int res = 0, i = 0, j = rows.size() - 1;
        while (i < j) res += (rows[j] - rows[i]) + (cols[j--] - cols[i++]);
        return res;
    }
};
```

## 298. Binary Tree Longest Consecutive Sequence
## 302. Smallest Rectangle Enclosing Black Pixels
## 305. Number of Islands II
## 308. Range Sum Query 2D - Mutable

## 311. Sparse Matrix Multiplication

题目描述：稀疏矩阵相乘。稀疏矩阵的特点是矩阵中绝大多数的元素为 0，而相乘的结果是还应该是稀疏矩阵，即还是大多数元素为 0，那么使用传统的矩阵相乘的算法肯定会处理大量的 0 乘 0 的无用功，所以需要适当的优化算法

1. 一个 i x k 的矩阵 A 乘以一个 k x j 的矩阵 B 会得到一个 i x j 大小的矩阵 C，`C[i][j] =  A[i][0]*B[0][j] + A[i][1]*B[1][j] + ... + A[i][k]*B[k][j]`，那么为了不重复计算 0 乘 0，首先遍历A数组，要确保 `A[i][k]` 不为0，才继续计算，然后遍历 B 矩阵的第 k 行，如果 `B[k][j]` 不为0，累加结果矩阵 `res[i][j] += A[i][k] * B[k][j]`，这样就能高效的算出稀疏矩阵的乘法。

```cpp
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < A[0].size(); ++k) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < B[0].size(); ++j) {
                        if (B[k][j] != 0) res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};
```

## 314. Binary Tree Vertical Order Traversal



## 317. Shortest Distance from All Buildings
## 320. Generalized Abbreviation
## 323. Number of Connected Components in an Undirected Graph
## 325. Maximum Size Subarray Sum Equals k
## 333. Largest BST Subtree
## 339. Nested List Weight Sum
## 340. Longest Substring with At Most K Distinct Characters
## 346. Moving Average from Data Stream
## 348. Design Tic-Tac-Toe
## 351. Android Unlock Patterns
## 353. Design Snake Game
## 356. Line Reflection
## 358. Rearrange String k Distance Apart
## 359. Logger Rate Limiter
## 360. Sort Transformed Array
## 361. Bomb Enemy
## 362. Design Hit Counter
## 364. Nested List Weight Sum II
## 366. Find Leaves of Binary Tree
## 369. Plus One Linked List
## 370. Range Addition
## 379. Design Phone Directory
## 408. Valid Word Abbreviation
## 411. Minimum Unique Word Abbreviation
## 418. Sentence Screen Fitting
## 422. Valid Word Square
## 425. Word Squares
## 426. Convert Binary Search Tree to Sorted Doubly Linked List
## 428. Serialize and Deserialize N-ary Tree
## 431. Encode N-ary Tree to Binary Tree
## 439. Ternary Expression Parser
## 444. Sequence Reconstruction
## 465. Optimal Account Balancing
## 469. Convex Polygon
## 471. Encode String with Shortest Length
## 484. Find Permutation
## 487. Max Consecutive Ones II
## 489. Robot Room Cleaner
## 490. The Maze
## 499. The Maze III
## 505. The Maze II
## 510. Inorder Successor in BST II
## 512. Game Play Analysis II
## 527. Word Abbreviation
## 531. Lonely Pixel I
## 533. Lonely Pixel II
## 534. Game Play Analysis III
## 536. Construct Binary Tree from String
## 544. Output Contest Matches
## 545. Boundary of Binary Tree
## 548. Split Array with Equal Sum
## 549. Binary Tree Longest Consecutive Sequence II
## 550. Game Play Analysis IV
## 555. Split Concatenated Strings
## 562. Longest Line of Consecutive One in Matrix
## 568. Maximum Vacation Days
## 569. Median Employee Salary
## 570. Managers with at Least 5 Direct Reports
## 571. Find Median Given Frequency of Numbers
## 573. Squirrel Simulation
## 574. Winning Candidate
## 577. Employee Bonus
## 578. Get Highest Answer Rate Question
## 579. Find Cumulative Salary of an Employee
## 580. Count Student Number in Departments
## 582. Kill Process
## 585. Investments in 2016
## 588. Design In-Memory File System
## 597. Friend Requests I: Overall Acceptance Rate
## 602. Friend Requests II: Who Has the Most Friends
## 603. Consecutive Available Seats
## 604. Design Compressed String Iterator
## 610. Triangle Judgement
## 612. Shortest Distance in a Plane
## 613. Shortest Distance in a Line
## 614. Second Degree Follower
## 615. Average Salary: Departments VS Company
## 616. Add Bold Tag in String
## 618. Students Report By Geography
## 619. Biggest Single Number
## 624. Maximum Distance in Arrays
## 625. Minimum Factorization
## 631. Design Excel Sum Formula
## 634. Find the Derangement of An Array
## 635. Design Log Storage System
## 642. Design Search Autocomplete System
## 644. Maximum Average Subarray II
## 651. 4 Keys Keyboard
## 656. Coin Path
## 660. Remove 9
## 663. Equal Tree Partition
## 666. Path Sum IV
## 681. Next Closest Time
## 683. K Empty Slots
## 694. Number of Distinct Islands
## 702. Search in a Sorted Array of Unknown Size
## 708. Insert into a Sorted Circular Linked List
## 711. Number of Distinct Islands II
## 716. Max Stack












## 702.

在未知大小数组里搜索数字

1. 二分搜索: 假设数组就有整型最大值个数字，在多余的位置上相当于都填上了整型最大值，那么这也是一个有序的数组

```cpp
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int x = reader.get(mid);
            if (x == target) return mid;
            else if (x < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
```
