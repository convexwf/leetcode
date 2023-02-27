## 646. Maximum Length of Pair Chain

给定一些链对，规定了如果后面链对的首元素大于前链对的末元素，那么这两个链对就可以链起来，问最大能链多少个。

1. 排序 + 贪心算法
   - 按链对的尾元素进行排序，小的放前面。
   - 用一个变量 end 来记录当前比较到的尾元素的值，初始化为最小值，然后遍历的时候，如果当前链对的首元素大于 end，那么结果 res 自增 1，end 更新为当前链对的尾元素

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};
```

## 785. Is Graph Bipartite?

存在一个无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给定一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。

该无向图同时具有以下属性：
(1) 不存在自环（graph[u] 不包含 u）。
(2) 不存在平行边（graph[u] 不包含重复值）。
(3) 如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）。
(4) 这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。

二分图：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

1. 并查集
   - 连接的两个节点不能在同一集合中
   - 同一节点的邻接节点必须在同一集合中
2. DFS 染色
   - 使用两种颜色，分别用 1 和 -1 来表示
   - 初始时每个顶点用 0 表示未染色，然后遍历每一个顶点，如果该顶点未被访问过，则调用递归函数
   - 在递归函数中，如果当前顶点已经染色，如果该顶点的颜色和将要染的颜色相同，则返回 true，否则返回 false。如果没被染色，则将当前顶点染色，然后再遍历与该顶点相连的所有的顶点
3. BFS 染色
   - 遍历所有顶点，如果未被染色，则先染色为 1，然后使用 BFS 进行遍历，将当前顶点放入队列 queue 中
   - while 循环：queue 不为空，取出队首元素，遍历其所有相邻的顶点，如果相邻顶点未被染色，则染成和当前顶点相反的颜色，然后把相邻顶点加入 queue 中，否则如果当前顶点和相邻顶点颜色相同，直接返回 false，循环退出后返回 true

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for (int i = 0; i < graph.size(); ++i) root[i] = i;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }
    int find(vector<int>& root, int i) {
        return root[i] == i ? i : find(root, root[i]);
    }
};
```

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0 && !valid(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<int>>& graph, int color, int cur, vector<int>& colors) {
        if (colors[cur] != 0) return colors[cur] == color;
        colors[cur] = color;
        for (int i : graph[cur]) {
            if (!valid(graph, -1 * color, i, colors)) {
                return false;
            }
        }
        return true;
    }
};
```

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty()) {
                int t = q.front(); q.pop();
                for (auto a : graph[t]) {
                    if (colors[a] == colors[t]) return false;
                    if (colors[a] == 0) {
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
};
```

## 395. Longest Substring with At Least K Repeating Characters

给定一个字符串 s 和一个整数 k，找出 s 中的最长子串，要求该子串中的每一字符出现次数都不少于 k。

1. 滑动窗口
   - 字符串中只有字母，这意味着最多不同的字母数只有 26 个，最后满足题意的子串中的不同字母数一定是在 [1, 26] 的范围
   - 每次只找不同字母个数为 cnt，且每个字母至少重复 k 次的子串，来更新最终结果 res。
   - cnt 从 1 遍历到 26，对于每个 cnt 都新建一个大小为 26 的数组 charCnt 来记录每个字母的出现次数
   - 用两个变量 start 和 i 来分别标记窗口的左右边界，当右边界小于 n 时，进行 while 循环，需要一个变量 valid 来表示当前子串是否满足题意
   - 需要一个变量 uniqueCnt 来记录子串中不同字母的个数。此时若 s[i] 这个字母在 charCnt 中的出现次数为 0，说明遇到新字母了，uniqueCnt 自增1，同时把该字母的映射值加 1。
   - 由于 uniqueCnt 变大，有可能会超过 cnt，所以这里用一个 while 循环，条件是当 uniqueCnt 大于 cnt ，此时应该收缩滑动窗口的左边界
   - 当 uniqueCnt 没超过 cnt 的时候，此时还要看当前窗口中的每个字母的出现次数是否都大于等于 k，遇到小于 k 的字母，则直接 valid 标记为 false 即可

TODO

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        for (int cnt = 1; cnt <= 26; ++cnt) {
            int start = 0, i = 0, uniqueCnt = 0;
            vector<int> charCnt(26);
            while (i < n) {
                bool valid = true;
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = max(res, i - start);
            }
        }
        return res;
    }
};
```

## 820 Short Encoding of Words

给定一个单词列表，将这个列表编码成一个索引字符串 S 与一个索引列表 A。例如，如果这个列表是 ["time", "me", "bell"]，可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。对于每一个索引，可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复之前的单词列表。返回成功对给定单词列表进行编码的最小字符串长度。

题目本质是计算单词后缀，当一个单词是另外一个单词的后缀时，需要将当前单词去掉。

1. 后缀匹配变前缀匹配
   - 对每个单词都做反转处理
   - 判断前一个字符串是否是后一个字符串的前缀，是的话长度加0，不是的话要加上当前单词的长度并再加 1，多加的 1 是 # 号。
   - 最后记得加上最后一个单词的长度
2. HashSet
   - 将所有的单词先放到 HashSet 中
   - 对于每个单词，我们遍历其所有的后缀，比如time，那么就遍历ime，me，e，然后看HashSet中是否存在这些后缀，有的话就删掉，那么HashSet中的me就会被删掉，这样保证了留下来的单词不可能再合并了，最后再加上每个单词的长度到结果res

**边界条件**

1. ["aba", "a"]

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string str = "";
        sort(words.begin(), words.end(), [](string& a, string& b){return a.size() > b.size();});
        for (string word : words) {
            int found = str.find(word);
            if (found == string::npos || str[found + word.size()] != '#') {
                str += word + "#";
            }
        }
        return str.size();
    }
};
```

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0, n = words.size();
        for (int i = 0; i < n; ++i) reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end());
        for (int i = 0; i < n - 1; ++i) {
            res += (words[i] == words[i + 1].substr(0, words[i].size())) ? 0  : words[i].size() + 1;
        }
        return res + words.back().size() + 1;
    }
};
```

## 336. Palindrome Pairs

给定一组 互不相同 的单词，找出所有 不同 的索引对 (i, j)，使得列表中的两个单词，words[i] + words[j] ，可拼接成回文串。

1. HashMap
   - 建立每个单词和其位置的映射，和一个 set 来保存出现过的单词的长度
   - 遍历单词集，对于遍历到的单词，对其翻转一下，然后在哈希表查找翻转后的字符串是否存在，注意不能和原字符串的坐标位置相同，因为有可能一个单词翻转后和原单词相等
   - 由于set是自动排序的，可以找到当前单词长度在set中的iterator，然后从开头开始遍历set，遍历比当前单词小的长度，比如abcdd翻转后为ddcba，发现set中有长度为3的单词，然后查看 dd 是否为回文串，若是，再看 cba 是否存在于哈希表，若存在，则说明 abcdd 和cba是回文对，存入结果中
   - 要在set里找的字符串要在遍历到的字符串的左边和右边分别尝试，看是否是回文对，这样遍历完单词集，就能得到所有的回文对

```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isPalindrome(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
                if (isPalindrome(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        return res;
    }

    bool isPalindrome(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};
```
