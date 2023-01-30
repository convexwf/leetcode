## 22. Generate Parentheses

给定一个数字 n，让生成共有 n 个括号的所有正确的形式。

1. 递归
   - 定义两个变量 left 和 right 分别表示剩余左右括号的个数
   - 左括号为 0 时，将剩余右括号全部填入返回结果。
   - 左括号不为 0 时，添加左括号进入递归
   - 左括号个数少于右括号时，添加右括号进入递归。
2. 每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个 ()，就形成了所有的情况，需要注意的是，有时候会出现重复的情况，所以用 set 数据结构进行存储。

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        int lp = n, rp = n;
        helper(res, cur, lp, rp);
        return res;
    }

    void helper(vector<string>& res, string cur, int lp, int rp) {
        if (lp == 0) {
            res.push_back(cur + string(rp - lp, ')'));
            return;
        }
        helper(res, cur + "(", lp - 1, rp);
        if (lp < rp) helper(res, cur + ")", lp, rp - 1);
    }
};
```

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if (n == 0) st.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (string a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        string tmp = a.substr(0, i + 1) + "()" + a.substr(i + 1)
                        st.insert(tmp);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};
```

## 164. Maximum Gap

给一个乱序的数组，求出数组排序以后的相邻数字的差最大是多少。要求时间复杂度 O(n)。

1. 桶排序
   - 首先找出数组的最大值和最小值以确定每个桶的容量，即为 len = (max - min) / (n - 1)
   - 区间分别为：`[min,min+len)`, `[min+len,min+2*len)`, `[min+2*len,min+3*len)`, ... `[max-len,max]`
   - 桶的个数为 n - 1
   - 最大间距的两个数不会在同一个桶中，而是一个桶的最小值和另一个桶的最大值

**边界条件**

1. 可能存在空桶

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = nums.size(), pre = 0, res = 0;
        for (int num : nums) {
            mx = max(mx, num);
            mn = min(mn, num);
        }
        int size = (mx - mn) / (n - 1), cnt = n - 1;
        vector<int> bucket_min(cnt, INT_MAX), bucket_max(cnt, INT_MIN);
        for (int num : nums) {
            int idx = (num - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }
        for (int i = 1; i < cnt; ++i) {
            if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};
```

## 260. Single Number III

非空数组，其中只有两个元素只出现过一次，其余元素都出现了两次。找到只出现了一次的两个元素。要求 O(n) 时间复杂度，O(1) 空间复杂度。

1. 位操作
   - 把原数组逐一做异或操作，会得到一个数字，这个数字是两个结果数字异或的结果。
   - 用 `a & -a` 取出 a 最右边的 1，该位置为两个结果数字不同的位，从而区分出两个不同的数字。

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for (int &a : nums) {
            if (a & diff) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};
```

## 274. H-Index

求 H 指数，该指数用来衡量研究人员的学术水平的质数，定义为一个人的学术文章有 n 篇分别被引用了 n 次，那么 H 指数就是 n。

可以按照如下方法确定某人的 H 指数：1、将其发表的所有SCI论文按被引次数从高到低排序；2、从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。所得序号减一即为 H 指数。

1. 降序排序
2. 计数排序：定义 n+1 个桶(0 \~ n)，引用次数大于等于 n 的放入序号为 n 的桶。然后从大到小遍历桶，累加计数，当累计值大于等于当前桶序号时，返回当前桶序号。

```C++
// 2020-11-11 submission
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

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for(int c : citations) {
            if(c >= n) {
                buckets[n]++;
            } else {
                buckets[c]++;
            }
        }
        int count = 0;
        for(int i = n; i >= 0; i--) {
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }
        return 0;
    }
```

## 275. H-Index II

求 H 指数，输入数组是有序的，要求 O(log n) 时间复杂度。

1. 二分查找：问题转化为查找第一个 `citations[i] > n - 1 - i` 的元素。

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] <= n - 1 - mid) left = mid + 1;
            else right = mid;
        }

        return n - right;
    }
};
```

## 284. Peeking Iterator

给迭代器增加一个 peek 方法，查看下一个元素，且不能移动迭代器指针。

1. 局部变量：创建一个副本，然后让副本移动到下一个，并返回，由于是局部变量，副本在调用结束后也会被销毁
2. cache：定义一个变量专门来保存下一个值，再用一个bool型变量标记是否保存了下一个值。

```cpp
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

    int peek() {
        return Iterator(*this).next();
    }

    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};
```

```cpp
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _flag = false;
    }

    int peek() {
        if (!_flag) _value = Iterator::next();
        _flag = true;
        return _value;
    }

    int next() {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }

    bool hasNext() const {
        return _flag || Iterator::hasNext();
    }

private:
    int _value;
    bool _flag;
};
```

## 329. Longest Increasing Path in a Matrix

求矩阵中最长的递增路径，规定只能上下左右行走。

1. DFS+记忆数组：`dp[i][j]` 表示数组中以 (i,j) 为起点的最长递增路径的长度
   - 初始将 dp 数组都赋为0，递归调用时遇到某个位置 (x, y), 如果 `dp[x][y]` 不为0的话，直接返回 dp[x][y] 即可
   - 以数组中每个位置都为起点调用递归来做，比较找出最大值。在以一个位置为起点用 DFS 搜索时，对其四个相邻位置进行判断，如果相邻位置的值大于上一个位置，则对相邻位置继续调用递归，并更新一个最大值，搜素完成后返回即可。
2. BFS+记忆数组：`dp[i][j]` 表示数组中以 (i,j) 为起点的最长递增路径的长度
   - 初始将 dp 数组都赋为0，递归调用时遇到某个位置 (x, y), 如果 `dp[x][y]` 不为0的话，直接返回 dp[x][y] 即可
   - 新建一个 queue，然后把当前点的坐标加进去，再用一个变量 cnt 初始化为 1，表示当前点为起点的递增长度，然后进入 while 循环。
   - 取出 queue 中的首元素，对周围四个点进行遍历，计算出相邻点的坐标后，要进行合法性检查，横纵坐标不能越界，且相邻点的值要大于当前点的值，并且相邻点的 dp 值要小于 cnt，才有更新的必要。用 cnt 来更新 `dp[x][y]`，并用 cnt 来更新结果 res，然后把相邻点排入 queue 中继续循环即可。

```cpp
class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (vector<int> dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            mx = max(mx, 1 + dfs(matrix, dp, x, y));
        }
        dp[i][j] = mx;
        return mx;
    }
};
```

```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j ) {
                if (dp[i][j] > 0) continue;
                queue<vector<int>> q{{i, j}};
                int cnt = 1;
                while (!q.empty()) {
                    ++cnt;
                    int len = q.size();
                    for (int k = 0; k < len; ++k) {
                        auto t = q.front(); q.pop();
                        for (vector<int> dir : dirs) {
                            int x = t[0] + dir[0], y = t[1] + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[t[0]][t[1]] || cnt <= dp[x][y]) continue;
                            dp[x][y] = cnt;
                            res = max(res, cnt);
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};
```

## 696. Count Binary Substrings

给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。

1. 动态规划：dp[i] 表示截止到 i 位置且包含 i 位置的有效字符长度，分两种情况讨论。s[i] == s[i-1] 时，就要将 dp[i-1] 视为内字符串，在内字符串的两边加上 s[i] 和 s[i-dp[i-1]-1]，要求这两个字符不能相同；s[i] != s[i-1] 时，就可以直接视作长度为 2 的有效字符串。

```cpp
// 2021-12-22 submission
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                dp[i] = 2;
                res += 1;
            }
            else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]!=s[i]) {
                dp[i] = dp[i-1] + 2;
                res += 1;
            }
        }
        return res;
    }
};
```

## 409. Longest Palindrome

给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

1. 问题转化为求偶数个字符的个数。

```cpp
// 2021-12-23 submission
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        int odd_cnt = 0, even_cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2 == 0) even_cnt += it->second;
            else {
                even_cnt += (it->second - 1);
                odd_cnt = 1;
            }
        }
        return odd_cnt + even_cnt;
    }
};
```

## 146. LRU Cache

实现一个 LRU 缓存器，要求 `get` 和 `put` 方法为 O(1) 时间复杂度。

1. 双向链表+哈希表
   - 双向链表实现：dummy node，减少边界处理复杂度，并实现三个辅助函数
   - put 实现
     - 如果哈希表中中存在，移动至链表开头
     - 如果哈希表中不存在，新建节点并移动至链表开头，更新哈希表。
     - 如果新加入的节点导致超过了最大容量，更新哈希表，删除链表结尾节点。
   - get 实现
     - 如果哈希表中不存在，返回错误
     - 将命中的节点移动至链表开头，返回结果

```cpp
// 2020-09-18 submission
struct ListNode
{
    int key;
    int value;
    struct ListNode* next;
    struct ListNode* prev;
    explicit ListNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr){}
};

class LRUCache {
public:

    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->dummyHead = new ListNode(0);
        this->dummyTail = new ListNode(0);
        this->dummyHead->next = this->dummyTail;
        this->dummyTail->prev = this->dummyHead;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        else {
            ListNode* node = m[key];
            this->moveNodeToHead(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (m.count(key)) {
            this->moveNodeToHead(m[key]);
        }
        else {
            ListNode* node = new ListNode(key, value);
            this->addNodeToHead(node);
            m[key] = node;
            ++size;
            while (capacity < size) {
                ListNode* tailNode = this->dummyTail->prev;
                m.erase(tailNode->key);
                this->removeNodeFromList(tailNode);
                --size;
            }
        }
    }

private:
    int addNodeToHead(ListNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next = this->dummyHead->next;
        this->dummyHead->next = node;
        node->prev = this->dummyHead;
        node->next->prev = node;
        return 0;
    }

    int moveNodeToHead(ListNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return addNodeToHead(node);
    }

    int removeNodeFromList(ListNode* node) {
        if (node == nullptr) {
            return -1;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
        return 0;
    }

private:
    uint32_t size;
    uint32_t capacity;
    struct ListNode* dummyHead;
    struct ListNode* dummyTail;
    std::unordered_map<int, struct ListNode*> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
