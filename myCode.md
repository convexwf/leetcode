
## 710

随机生成一个 N 以内的数字，且该数字不能在黑名单中

1. 首先将超过N - blacklist.size()的数字放入一个HashSet；然后遍历blacklist中的数字，如果在HashSet中的话，就将其删除；遍历黑名单中的数字，如果小于N - blacklist.size()的话，就和和HashSet中的数字建立映射。

```cpp
class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        unordered_set<int> st;
        len = N - blacklist.size();
        for (int i = len; i < N; ++i) {st.insert(i);}
        for (int num : blacklist) {st.erase(num);}
        auto it = st.begin();
        for (int num : blacklist) {
            if (num < len) m[num] = *it++;
        }
    }

    int pick() {
        int k = rand() % len;
        return m.count(k) ? m[k] : k;
    }

private:
    unordered_map<int, int> m;
    int len;
};
```

## 345

翻转字符串中的元音字母

1. 双指针法

**边界条件**

1. 注意大写字母

```cpp
// 2021-12-16 submission
// 480/480 cases passed
// Runtime: 8 ms, faster than 70.15% of C++ online submissions.
// Memory Usage: 8 MB, less than 38.59% of C++ online submissions.
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> m{'a', 'i', 'u', 'e', 'o'};
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !m.count(tolower(s[l]))) ++l;
            while (r >= 0 && !m.count(tolower(s[r]))) --r;
            if (l < r) {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};
```

## 482

对注册码进行格式化，正确的注册码的格式是每四个字符后面跟一个短杠，每一部分的长度为K，第一部分长度可以小于K，另外，字母必须是大写的。

1. 首先计算出有效字符的个数。

**边界条件**

1. k 正好可以整除 n
2. 小写字母需要转为大写字母

```cpp
// 2021-12-17 submission
// 38/38 cases passed
// Runtime: 8 ms, faster than 80.96% of C++ online submissions.
// Memory Usage: 8.3 MB, less than 67.18% of C++ online submissions.
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for (char c : s) {
            if (isalnum(c)) ++cnt;
        }

        string res;
        for (char c : s) {
            if (isalnum(c)) {
                cnt--;
                res.append(1, toupper(c));
                if (cnt % k == 0 && cnt != 0) {
                    res.append(1, '-');
                }
            }
        }
        return res;
    }
};
```

## 434

统计字符串中的单词数量，单词以空格进行分隔

1. 遍历字符串，遇到空格直接跳过，如果不是空格，则计数器加1，然后用个while循环找到下一个空格的位置。
2. 统计单词开头的第一个字符，因为每个单词的第一个字符前面一个字符一定是空格。
3. 利用 C++ 的 getline 函数取出每两个空格符之间的字符串，由于多个空格符可能连在一起，所以有可能取出空字符串，只有取出的是非空字符串才累加计数器。

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            ++res;
            while (i < n && s[i] != ' ') ++i;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++res;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream is(s);
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            ++res;
        }
        return res;
    }
};
```

## 292

Nim 游戏，给定一堆石子，每次可以拿 1~3 个，两个人轮流拿，拿到最后一个石子的人获胜，问先取者是否有必胜法。

1. 尼姆博弈，只有石子数能被 4 整除即可。

```cpp
// 2019-09-15 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.65% of C++ online submissions.
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

## 709

将单词转为小写

1. 小写字母比其对应的大写字母的 ASCII 码大 'a'-'A

```cpp
// 2021-12-16 submission
// 114/114 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 51.19% of C++ online submissions.
class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (char c : s) {
            if ('A' <= c && c <= 'Z') res.append(1, c + ('a' - 'A'));
            else res.append(1, c);
        }
        return res;
    }
};
```

## 628

数组中最大的三个数乘积

1. 排序+分类讨论
   - (1) 全正数：最大的三个数之乘积
   - (2) 全负数：最大的三个数之乘积
   - (3) 正负混合：最大的数和最小两个数的乘积或者最大的三个数之乘积。
2. 在方法 1 的基础上，因为只需要求最大和最小的几个数，可将时间复杂度降低为 O(n)。

```cpp
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 61 ms, faster than 16.89% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val1 = nums[n-1] * nums[n-2] * nums[n-3];
        int val2 = nums[n-1] * nums[0] * nums[1];
        return max(val1, val2);
    }
};
```

```cpp
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 44 ms, faster than 62.61% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int A = INT_MIN, B = INT_MIN, C = INT_MIN;
        int a = INT_MAX, b = INT_MAX;
        for (int num : nums) {
            // max three numbers
            if (num > A) {
                C = B; B = A; A = num;
            }
            else if (A > num && num > B) {
                C = B; B = num;
            }
            else if (B > num && num > C) {
                C = num;
            }
            // min two numbers
            if (num < a) {
                b = a; a = num
            }
            else if (a < num && num < b) {
                b = num;
            }
        }
        return max(A * B * C, a * b * A);
    }
};
```

## 697

数组的度定义为出现最多次数的数字的出现次数，求和原数组度相同的长度最小的子数组。

1. HashMap
   - 统计数组元素的出现次数，以及数组元素的右边界，用 HashMap 进行统计存储
   - 得到最大出现次数后，从左往右遍历，依次计算元素是否符合最大出现次数，如果符合就计算区间长度，并将出现次数减一，防止后续重复计算。
2. 方法 1 的改进，统计数组元素的出现次数，以及数组元素的左边界，这样只需要遍历一次数组，遍历到的当前位置视为尾位置。

```cpp
// 2021-12-15 submission
// 89/89 cases passed
// Runtime: 44 ms, faster than 56.21% of C++ online submissions.
// Memory Usage: 25.5 MB, less than 67.47% of C++ online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;      // 出现次数的映射
        unordered_map<int, int> right;  // 右边界的映射
        int max_val = 0;                // 数组的度, 最多出现次数
        for (int i = 0; i < nums.size(); i++) {
            ++m[nums[i]];
            right[nums[i]] = i;
            max_val = max(max_val, m[nums[i]]);
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == max_val) {
                res = min(res, right[nums[i]] - i + 1);
                --m[nums[i]];
            }
        }
        return res;
    }
};
```

```cpp
// 2022-08-20 submission
// 89/89 cases passed
// Runtime: 51 ms, faster than 81.98% of C++ online submissions.
// Memory Usage: 25.5 MB, less than 68.97% of C++ online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;      // 出现次数的映射
        unordered_map<int, int> left;   // 左边界的映射
        int max_val = 0;                // 数组的度, 最多出现次数
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (!left.count(nums[i])) {
                left[nums[i]] = i;
            }
            ++m[nums[i]];
            if (m[nums[i]] > max_val) { // 更新数组度，需要重新计算 res
                max_val = m[nums[i]];
                res = nums.size();
            }
            if (m[nums[i]] == max_val) {
                res = min(res, i - left[nums[i]] + 1);
            }
        }
        return res;
    }
};
```

## 690

定义了一种员工类，有id，重要度和直接下属，计算某个员工的重要度，注意下属的重要度会向上累积到上级的重要度。

1. 建图+DFS: 首先为需要建立一个id和员工类的映射，从而能够快速通过id来定位到员工类。
2. 建图+BFS

```cpp
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        return DFS(id, m);
    }
    int DFS(int id, unordered_map<int, Employee*>& m) {
        int res = m[id]->importance;
        for (int num : m[id]->subordinates) {
            res += DFS(num, m);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        queue<int> q{{id}};
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            res += m[t]->importance;
            for (int num : m[t]->subordinates) {
                q.push(num);
            }
        }
        return res;
    }
};
```

## 682

棒球比赛计分

1. 按照题意处理即可。

```cpp
// 2022-08-20 submission
// 39/39 cases passed
// Runtime: 8 ms, faster than 44.66% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 99.8% of C++ online submissions.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vec;
        int sum = 0;
        for (string op : ops) {
            int n = vec.size();
            if (op == "+") {
                vec.push_back(vec[n - 1] + vec[n - 2]);
                sum += vec.back();
            }
            else if (op == "D") {
                vec.push_back(vec[n - 1] * 2);
                sum += vec.back();
            }
            else if (op == "C") {
                sum -= vec.back();
                vec.pop_back();
            }
            else {
                vec.push_back(stoi(op));
                sum += vec.back();
            }
        }
        return sum;
    }
};
```

## 263

检测一个数是否为丑数，丑数只含有质因数 (2, 3, 5)

1. 只要对某数不断除以 (2, 3, 5) 直到剩余数字为 1 即可判断为丑数

边界条件

1. 1 也是丑数

```C++
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

## 264

找到第 n 个丑数，丑数只含有质因数 (2, 3, 5)

1. 新的丑数可以认为是从已有的丑数序列生成的。为 (2, 3, 5) 都各自分配一个下标指向丑数序列，其实就可以当做是三个已经生成的序列，每次都从这三个列表中取出当前最小的那个作为新丑数，当有新的丑数加入就把产生效果的下标加1。
2. 和方法 1 类似，使用最小堆来做，首先放进去一个 1，然后循环 n 次，每次取出堆顶元素，为了确保没有重复数字，进行一次 while 循环，将此时和堆顶元素相同的都取出来，然后分别将这个取出的数字乘以 2，3，5，并分别加入最小堆。

```C++
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

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for (long i = 1; i < n; ++i) {
            long t = pq.top(); pq.pop();
            while (!pq.empty() && pq.top() == t) {
                t = pq.top(); pq.pop();
            }
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        return pq.top();
    }
};
```

## 238

给定一个数组，返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度 O(n)，并且不能用除法。

1. 分别从数组的两个方向遍历就可以分别创建出乘积累积数组。
   - 为了进行空间上的优化，由于最终的结果都是要乘到结果 res 中，所以可以不用单独的数组来保存乘积，而是直接累积到结果 res 中。
   - 先从前面遍历一遍，将乘积的累积存入结果 res 中，然后从后面开始遍历，用到一个临时变量 right，初始化为1，然后每次不断累积，最终得到正确结果。

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i = (int)nums.size()-2; i >= 0; i--) {
            right  *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};
```

## 237

删除链表的一个节点，不提供链表的起点，只提供当前节点

解题思路

1. 先把当前节点的值用下一个节点的值覆盖，然后删除下一个节点即可

```C++
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};
```

## 235

公共祖先节点: 二叉搜索树

1. 利用 BST 的特性
   - 二叉搜索树的特点是左<根<右，所以根节点的值一直都是中间值，大于左子树的所有节点值，小于右子树的所有节点值，
   - 如果根节点的值大于p和q之间的较大值，说明p和q都在左子树中
   - 如果根节点小于p和q之间的较小值，说明p和q都在右子树中
   - 如果都不是，则说明当前根节点就是最小共同父节点，直接返回即可
2. 方法 1 的非递归写法

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
```

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val)) root = root->left;
            else if (root->val < min(p->val, q->val)) root = root->right;
            else break;
        }
        return root;
    }
};
```

## 236

公共祖先节点: 普通二叉树

1. 如果当前结点不等于p或q，p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树
   - 若p和q分别位于左右子树中，那么对左右子结点调用递归函数，会分别返回p和q结点的位置，而当前结点正好就是p和q的最小共同父结点，直接返回当前结点即可
   - 若p和q同时位于左子树，这里有两种情况，一种情况是 left 会返回p和q中较高的那个位置，而 right 会返回空，所以最终返回非空的 left 即可; 还有一种情况是会返回p和q的最小父结点，就是说当前结点的左子树中的某个结点才是p和q的最小父结点，会被返回。
   - 若p和q同时位于右子树，同样这里有两种情况，一种情况是 right 会返回p和q中较高的那个位置，而 left 会返回空，所以最终返回非空的 right 即可，还有一种情况是会返回p和q的最小父结点，就是说当前结点的右子树中的某个结点才是p和q的最小父结点，会被返回

**边界条件**

1. p和q不是树中的节点

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p, q);
       if (left && right) return root;
       return left ? left : right;
    }
};
```

## 231

判断一个数是否为 2 的次方，要求时间和空间复杂度都为常数

1. 如果一个数是2的次方数的话，那么它的二进数必然是最高位为1，其它都为0，那么如果此时减1，最高位会降一位，其余为0的位现在都为变为1，此时把两数相与，就会得到0

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};
```

## 313

超级丑数，质因子集合不一定是 (2,3,5)，自由指定。求给定质因子集合的第 n 个超级丑数。

1. 参考 <264. Ugly Number II> 的做法，可以用一个idx数组来保存当前的位置，然后我们从每个子链中取出一个数，找出其中最小值，然后更新idx数组对应位置，注意有可能最小值不止一个，要更新所有最小值的位置。

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 1);
        vector<int> idx(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            int min_val = primes[0];
            for (int j = 1; j < primes.size(); j++) {
                min_val = min(primes[j]*res[idx[j]], min_val);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (min_val == primes[j]*res[idx[j]]) idx[j]++;
            }
            res[i] = min_val;
        }
        return res.back();
    }
};
```

## 289

细胞自动机，每一个位置有两种状态，1为活细胞，0为死细胞，对于每个位置都满足如下的条件：

1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活

计算出细胞自动机的下一个状态，要求 in-place 空间复杂度，要求同时更新所有细胞的状态。

1. 可以通过状态机转换同时知道其未更新和已更新的状态。最后对所有状态对2取余，则状态0和2就变成死细胞，状态1和3就是活细胞
   - 状态0： 死细胞转为死细胞
   - 状态1： 活细胞转为活细胞
   - 状态2： 活细胞转为死细胞
   - 状态3： 死细胞转为活细胞

```c++
class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<int> dx{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy{-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
```

## 268

给定 [0, n] 范围内互不相同的 n 个数字，找出缺失的数字。

1. 利用等差数列的特性，计算出 0\~n 的序列和，然后再遍历数组算出给定数字的累积和，然后做减法，差值就是丢失的那个数字。
2. 位操作: 将这个少了一个数的数组同 0 到 n 之间完整的数组进行异或操作，相同的数字都变为0，剩下的就是少了的那个数字。
3. 二分查找: 如果数组有序，可将时间复杂度降为 O(logn)。如果元素值大于下标值，则说明缺失的数字在左边，此时将 right 赋为 mid，反之则将 left 赋为 mid+1。

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) {
            sum += num;
        }
        return n * (n + 1) / 2 - sum;
    }
};
```

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
```

## 218

## 198

抢劫房屋，相邻的房屋连接了安全系统，如果相邻的房屋被闯入，安全系统会自动联系警察，求不在惊动警察的情况下最多能抢劫到的金钱。问题本质为，在一列数组中取出一个或多个不相邻数，使其和最大。

1. 动态规划
   - 两个被打劫的家中间的间隔可能是1或2（不可能大于2）
   - 维护一个一位数组 dp，其中 dp[i] 表示 [0, i] 区间可以抢夺的最大值（并且 i 位置要抢）。
   - 状态转移方程为 $\text{dp}[i] = \text{max}(\text{dp}[i-2], \text{dp}[i-3]) + \text{nums}[i]$。

```C++
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

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); ++i) {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};
```

## 213. House Robber II

解题思路

1. 动态规划：房子围成环后，可以发现第一家和最后一家不能同时抢，恰好分解为两个子问题：分别计算去掉第一家和最后一家后能抢到的最大值，对两个极大值取最大即为所求。

```C++
// 2020-11-04 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 5.25% of C++ online submissions.
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

## 171

excel 中列标识到数字的转换，即 A 对应 1，B 对应 2，AA 对应 27，本质是二十六进制转十进制的问题。

1. 进制转化

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c : s) {
            res = res * 26 + (c - 'A' + 1);
        }
        return res;
    }
};
```

## 223

二维坐标系中给出两个矩形四个点的坐标，求两个矩形覆盖的总面积。![223. Rectangle Area 矩形坐标](../res/2022-08-24-19-43-58.png)

1. 先找出所有的不相交的情况，只有四种，一个矩形在另一个的上下左右四个位置不重叠，这四种情况下返回两个矩形面积之和。其他情况下需要计算出交集面积。

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C - A) * (D - B), sum2 = (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) {return sum1 + sum2;}
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
    }
};
```

## 461. Hamming Distance

求两个数的汉明距离，汉明距离即二进制数对应位不同的个数。

1. 位操作：异或后求 1 的个数，可以通过 $a & (a - 1)$ 将 a 最右边的 1 转为 0。

```C++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int merge = x ^ y;
        int res = 0;
        while (merge > 0) {
            ++res;
            merge = merge & (merge - 1);
        }
        return res;
    }
};
```

## 477. Total Hamming Distance

计算数字集合中每个两两数字对汉明距离的总和。

1. 位操作：找到每一位上 1 的个数和 0 的个数，然后两个相乘即这一位的总 Hamming Distance

```C++
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j]>>i) & 1);
            }
            res += ((nums.size()-count) * count);
        }
        return res;
    }
};
```

## 448

给定长度为 n 的数组，数值范围为 [1, n]，数字最多重复出现两次，找到所有消失的数字。要求 O(n) 时间复杂度，且不使用额外的空间。

1. 取负法：将元素对应的位置取负。在取负的过程中，如果发现要取负的位置已经为负，说明这个元素已经出现过，也即该元素出现了两次。当某个元素不出现的时候，该元素对应的位置始终访问不到，所以还是正值，通过这种方法我们就可以找到哪些元素没有出现。

```C++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int dst = 0;
        for (int i = 0; i < n; i++) {
            dst = nums[i] >= 0 ? nums[i] : nums[i] + (n + 1);
            if (nums[dst-1] >= 0) nums[dst-1] -= (n + 1);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
```

## 225

用队列实现栈

1. 每次把新加入的数插到队列前头，即在队尾加入了新元素x后，将x前面所有的元素都按顺序取出并加到队列到末尾，这样队列保存的顺序和栈的顺序是相反的，它们的取出方式也是反的。这种方法适用于写少读多的场景。
2. 两个队列，其中一个队列用来放最后加进来的数，模拟栈顶元素，剩下所有的数都按顺序放入另一个队列中。
   - 当 push() 操作时，将新数字先加入模拟栈顶元素的队列中，如果此时队列中有数字，则将原本有的数字放入另一个队中，让新数字在这队中，用来模拟栈顶元素。
   - 当 top() 操作时，如果模拟栈顶的队中有数字则直接返回，如果没有则到另一个队列中通过平移数字取出最后一个数字加入模拟栈顶的队列中。
   - 当 pop() 操作时，先执行下 top() 操作，保证模拟栈顶的队列中有数字，然后再将该数字移除即可。
   - 当 empty() 操作时，当两个队列都为空时，栈为空。
   - 这种方法适用于写多读少的场景。

```cpp
class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; ++i) {
            q.push(q.front()); q.pop();
        }
    }
    int pop() {
        int x = q.front(); q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
```

```cpp
class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front()); q2.pop();
        }
    }
    int pop() {
        int x = top(); q2.pop();
        return x;
    }
    int top() {
        if (q2.empty()) {
            for (int i = 0; i < (int)q1.size() - 1; ++i) {
                q1.push(q1.front()); q1.pop();
            }
            q2.push(q1.front()); q1.pop();
        }
        return q2.front();
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};
```

## 232

用栈实现队列

```C++
class myStack {
    myStack() {

    }

    void push(int val) {
        topVal = val;
        q.push(val);
    }

    void pop() {
        int size = q.size();
        while (size > 2) {
            q.push(q.front());
            q.pop();
            --size;
        }
        topVal = q.front();
        q.push(topVal);
        q.pop();
        q.pop();

    }

    int top() {
        return topVal;
    }

    queue<int> q;
    int topVal;
};
```

```C++
class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
    void push_back(int value) {
        stk1.push(value);
    }

    int deleteHead() {
    int pop_front() {
        if (stk1.empty() && stk2.empty()) return -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
        return res;
    }

    bool empty() {
        return stk1.empty() && stk2.empty()
    }

    int front() {

    }

    stack<int> stk1;
    stack<int> stk2;
};
};
```
