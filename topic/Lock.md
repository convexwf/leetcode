# Lock

## 156. Binary Tree Upside Down

题目描述：把一棵二叉树上下颠倒一下，而且限制了右节点要么为空要么一定会有对应的左节点。

## 158. Read N Characters Given read4 II - Call Multiple Times

题目描述：给定一个 Read4 函数，每次可以从一个文件中最多读出 4 个字符，如果文件中的字符不足 4 个字符时，返回准确的当前剩余的字符数。要求实现一个最多能读取 n 个字符的函数 Read。Read 可被调用多次。

1. 维护一个本地缓存，存储 Read4 读取的数据，仅在缓存为空的情况下才调用 Read4 继续读取新数据。

```cpp
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
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

压平一个二维向量数组，并且实现一个 iterator 的功能，包括 next 和 hasNext 函数。

1. 维护两个变量 x 和 y，将 x 和 y 初始化为 0
   - 对于 hasNext 函数，检查当前 x 是否小于总行数，y 是否和当前行的列数相同，如果相同，说明要转到下一行，则 x 自增 1，y 初始化为 0，若此时 x 还是小于总行数，说明下一个值可以被取出来，那么在 next 函数就可以直接取出行为 x，列为 y 的数字，并将 y 自增 1
2. C++ iterator：将 x 定义为行的 iterator，再用个 end 指向二维数组的末尾，定义一个整型变量 y 来指向列位置，实现思路和上一种解法完全相同。

**边界条件**

1. 存在空行

```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d): data(vec2d), x(0), y(0) {}

    int next() {
        hasNext();
        return data[x][y++];
    }
    bool hasNext() {
        while (x < data.size() && y == data[x].size()) {
            ++x;
            y = 0;
        }
        return x < data.size();
    }
private:
    vector<vector<int>> data;
    int x, y;
};
```

```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d): x(vec2d.begin()), end(vec2d.end()) {}

    int next() {
        hasNext();
        return (*x)[y++];
    }
    bool hasNext() {
        while (x != end && y == (*x).size()) {
            ++x;
            y = 0;
        }
        return x != end;
    }
private:
    vector<vector<int>>::iterator x, end;
    int y = 0;
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

题目描述：写出正整数 n 所有的因子相乘的形式，规定因子按照从小到大的顺序排列。1 和 n 本身不能算其因子。

1. 回溯
   - 从 2 开始遍历到 sqrt(n)，如果当前的数 i 可以被 n 整除，说明 i 是 n 的一个因子，将其存入一位数组 out 中
   - 然后递归调用 n/i，此时不从 2 开始遍历，而是从 i 遍历到 n/i
   - 停止的条件是当 n 等于 1 时
2. 递归：同样是从 2 开始遍历到 sqrt(n)，每次向递归返回的结果中追加因子。

```cpp
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, 2, {}, res);
        return res;
    }
    void helper(int n, int start, vector<int> out, vector<vector<int>> &res) {
        for (int i = start; i <= sqrt(n); ++i) {
            if (n % i != 0) continue;
            vector<int> new_out = out;
            new_out.push_back(i);
            helper(n / i, i, new_out, res);
            new_out.push_back(n / i);
            res.push_back(new_out);
        }
    }
};
// n = 12
// 2 2 3
// 2 6
// 3 4

// n = 32
// 2 2 2 2 2
// 2 2 2 4
// 2 2 8
// 2 4 4
// 2 16
// 4 8
```

```cpp
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i != 0) continue;
            vector<vector<int>> v = getFactors(n / i);
            vector<int> out{i, n / i};
            res.push_back(out);
            for (auto a : v) {
                if (i <= a[0]) {
                    a.insert(a.begin(), i);
                    res.push_back(a);
                }
            }
        }
        return res;
    }
};
// n = 12
// 2 6
// 2 2 3
// 3 4

// n = 32
// 2 16
// 2 2 8
// 2 2 2 4
// 2 2 2 2 2
// 2 4 4
// 4 8
```

## 255. Verify Preorder Sequence in Binary Search Tree

## 259. 3Sum Smaller

题目描述：给定一个长度为 n 的整数数组和一个目标值 target，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三元组。

1. 排序 + 双指针
   - left 指向首数字，从右往左固定最长边，开始循环
   - 如果 left 小于 right 就进行循环，循环里面判断如果 left 指向的数加上 right 指向的数大于当长边，那么 right 到 left之间的数字都可以组成三角形
   - 时间复杂度为 O(n^2)

```cpp
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    res += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
```

## 261. Graph Valid Tree

## 266. Palindrome Permutation
## 267. Palindrome Permutation II
## 269. Alien Dictionary
## 270. Closest Binary Search Tree Value
## 271. Encode and Decode Strings
## 272. Closest Binary Search Tree Value II


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

## 291. Word Pattern II

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

## 512. Game Play Analysis II

```sql
SELECT a.player_id, a.device_id FROM Activity AS a
INNER JOIN
(SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id
ORDER BY player_id) AS b
ON a.player_id = b.player_id
AND a.event_date = b.first_login
ORDER BY a.player_id;
```

```sql
SELECT player_id, device_id FROM (
    SELECT player_id, device_id,
    RANK() OVER (PARTITION BY player_id ORDER BY event_date) AS rnk
    FROM Activity)
AS tmp
WHERE rnk = 1;
```


## 533. Lonely Pixel II

## 534. Game Play Analysis III

```sql
SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id
ORDER BY player_id;
```

## 536. Construct Binary Tree from String

题目描述：根据一个字符串来创建一个二叉树，其中结点与其左右子树是用括号隔开，每个括号中又是数字后面跟括号的模式。空树用 () 表示。

1. 递归
   - 找第一个左括号的位置，如果找不到，说明当前字符串都是数字，直接转化为整型，然后新建结点返回即可。
   - 否则的话从当前位置开始遍历，因为当前位置是一个左括号，需要找到与之对应的右括号的位置。由于中间还会遇到左右括号，所以用一个变量 cnt 来记录左括号的个数，如果遇到左括号，cnt 自增1，如果遇到右括号，cnt 自减 1，这样当某个时刻 cnt 为 0 的时候，就确定了一个完整的子树的位置
   - 需要一个辅助变量 start，当最开始找到第一个左括号的位置时，将 start 赋值为该位置，那么当 cnt 为0时，如果 start 还是原来的位置，说明这个是左子树，对其调用递归函数，注意此时更新 start 的位置，这样就能区分左右子树了
2. 迭代+栈
   - 遍历字符串 s，用变量 j 记录当前位置 i，然后看当前遍历到的字符是什么
   - 如果遇到的是左括号，什么也不做继续遍历；
   - 如果遇到的是数字或者负号，将连续的数字都找出来，然后转为整型并新建结点
   - 此时看 stack 中是否有结点，如果有的话，当前结点就是栈顶结点的子结点，如果栈顶结点没有左子结点，那么此结点就是其左子结点，反之则为其右子结点。
   - 之后要将此结点压入栈中。如果遍历到的是右括号，说明栈顶元素的子结点已经处理完了，将其移除栈

```cpp
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        auto found = s.find('(');
        int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
        TreeNode *cur = new TreeNode(val);
        if (found == string::npos) return cur;
        int start = found, cnt = 0;
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            if (cnt == 0 && start == found) {
                cur->left = str2tree(s.substr(start + 1, i - start - 1));
                start = i + 1;
            } else if (cnt == 0) {
                cur->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return cur;
    }
};
```

```cpp
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        stack<TreeNode*> st;
        for (int i = 0; i < s.size(); ++i) {
            int j = i;
            if (s[i] == ')') st.pop();
            else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') ++i;
                TreeNode *cur = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!st.empty()) {
                    TreeNode *t = st.top();
                    if (!t->left) t->left = cur;
                    else t->right = cur;
                }
                st.push(cur);
            }
        }
        return st.top();
    }
};
```

## 544. Output Contest Matches
## 545. Boundary of Binary Tree
## 548. Split Array with Equal Sum
## 549. Binary Tree Longest Consecutive Sequence II

## 550. Game Play Analysis IV

```sql
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id), 2) AS fraction FROM Activity AS a
LEFT JOIN
(SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id) AS b
ON a.player_id = b.player_id
AND DATEDIFF(a.event_date, b.first_login) = 1
```

```sql
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id), 2) AS fraction FROM Activity AS a
LEFT JOIN
(SELECT player_id, FIRST_VALUE(event_date) OVER(PARTITION BY player_id ORDER BY event_date) AS first_login FROM Activity) AS b
ON a.player_id = b.player_id
AND DATEDIFF(a.event_date, b.first_login) = 1
```

## 555. Split Concatenated Strings
## 562. Longest Line of Consecutive One in Matrix
## 568. Maximum Vacation Days

## 569. Median Employee Salary

```sql
SELECT
Company,
Salary
FROM (
SELECT
Id,
Company,
Salary,
ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary) AS sal_id,
COUNT(Id) OVER (PARTITION BY Company) AS sal_num
FROM Employee e) T1
WHERE (ROUND(sal_num/2) = sal_id)
OR (ROUND((sal_num+1)/2) = sal_id)
```

## 570. Managers with at Least 5 Direct Reports

```sql
SELECT Name FROM Employee WHERE Id IN
(SELECT ManagerId FROM Employee
 GROUP BY ManagerId
 HAVING COUNT(ManagerId) >=5);
```

```sql
SELECT Name FROM Employee AS t1 JOIN
(SELECT ManagerId FROM Employee
 GROUP BY ManagerId
 HAVING COUNT(ManagerId) >= 5) AS t2
ON t1.Id = t2.ManagerId;
```

## 571. Find Median Given Frequency of Numbers

```sql
SELECT AVG(Number) AS median
FROM
(
select *, SUM(Frequency) OVER (ORDER BY Number) AS cum_sum,
          (SUM(Frequency) OVER ())/2.0  AS mid
FROM Numbers
) AS temp
WHERE mid BETWEEN cum_sum - frequency AND cum_sum;
```

## 573. Squirrel Simulation

## 574. Winning Candidate

```sql
SELECT Name FROM Candidate AS a
JOIN
(SELECT CandidateId FROM Vote
 GROUP BY CandidateId
 ORDER BY COUNT(*) DESC
 LIMIT 1
) AS b
ON a.id = b.CandidateId;
```

```sql
SELECT Name FROM Candidate
WHERE id =
(SELECT CandidateId FROM Vote
 GROUP BY CandidateId
 ORDER BY COUNT(*) DESC
 LIMIT 1
);
```

## 577. Employee Bonus

```sql
SELECT a.name,
b.bonus
FROM Employee AS a
LEFT JOIN Bonus AS b
ON a.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;
```

## 578. Get Highest Answer Rate Question

```sql
SELECT question_id AS survey_log
FROM
(SELECT question_id,
        SUM(case when action="answer" THEN 1 ELSE 0 END) AS num_answer,
        SUM(case when action="show" THEN 1 ELSE 0 END) AS num_show,
    FROM survey_log
    GROUP BY question_id
) AS tbl
ORDER BY (num_answer / num_show) DESC
LIMIT 1
```

```sql
SELECT question_id AS 'survey_log'
FROM survey_log
GROUP BY question_id
ORDER BY COUNT(answer_id) / COUNT(IF(action = 'show', 1, NULL)) DESC
LIMIT 1;
```

## 579. Find Cumulative Salary of an Employee

```sql
SELECT E1.id, E1.month,
(IFNULL(E1.salary, 0) + IFNULL(E2.salary, 0) + IFNULL(E3.salary, 0)) AS Salary
FROM
(
SELECT id, MAX(month) AS month FROM Employee
GROUP BY id
HAVING COUNT(*) > 1
) AS maxmonth
LEFT JOIN Employee AS E1
ON (maxmonth.id = E1.id AND maxmonth.month > E1.month)
LEFT JOIN Employee AS E2
ON (E2.id = E1.id AND E2.month = E1.month - 1)
LEFT JOIN Employee AS E3
ON (E3.id = E1.id AND E3.month = E1.month - 2)
ORDER BY id ASC, month DESC;
```

## 580. Count Student Number in Departments

```sql
SELECT a.dept_name, COUNT(b.student_id) AS student_number FROM department AS a
LEFT JOIN student AS b
ON a.dept_id = b.dept_id
GROUP BY a.dept_name
ORDER BY student_number DESC, a.dept_name;
```

## 582. Kill Process

## 585. Investments in 2016

```sql
SELECT SUM(insurance.TIV_2016) AS TIV_2016
FROM insurance
WHERE insurance.TIV_2015 IN
(SELECT TIV_2015 FROM insurance
 GROUP BY TIV_2015
 HAVING COUNT(*) > 1)
AND CONCAT(LAT, ",", LON) IN
(SELECT CONCAT(LAT, ",", LON) FROM insurance
 GROUP BY LAT , LON
 HAVING COUNT(*) = 1);
```

```sql
SELECT SUM(TIV_2016) TIV_2016
FROM insurance
WHERE TIV_2015 IN
(SELECT TIV_2015 FROM insurance
 GROUP BY TIV_2015
 HAVING COUNT(*) > 1)
AND (lat, lon) IN
(SELECT lat, lon FROM insurance
 GROUP BY lat, lon
 HAVING COUNT(*)=1);
```

## 588. Design In-Memory File System

## 597. Friend Requests I: Overall Acceptance Rate

```sql
SELECT
ROUND(
    IFNULL(
    (SELECT COUNT(*) FROM (SELECT DISTINCT requester_id,
                           accepter_id from request_accepted)
     AS A)
    /
    (SELECT COUNT(*) FROM (SELECT DISTINCT sender_id,
                           send_to_id FROM friend_request)
     AS B), 0)
    , 2)
    AS accept_rate;
```

## 602. Friend Requests II: Who Has the Most Friends

```sql
SELECT c.people as id, SUM(c.cnt) AS num
FROM (
SELECT requester_id AS people, COUNT(DISTINCT accepter_id) AS cnt
FROM request_accepted
GROUP BY requester_id

UNION ALL

SELECT accepter_id AS people, COUNT(DISTINCT requester_id) AS cnt
FROM request_accepted
GROUP BY accepter_id
) AS c

GROUP BY c.people
ORDER BY SUM(c.cnt) DESC
LIMIT 1;
```

```sql
-- Follow Up
-- In the real world, multiple people could have the same most number of friends, can you find all these people in this case?
WITH

ids AS (
SELECT DISTINCT requester_id AS id FROM request_accepted
UNION
SELECT DISTINCT accepter_id AS id FROM request_accepted
),

tmp1 AS (
SELECT requester_id AS id, COUNT(DISTINCT accepter_id) AS fri_num FROM request_accepted
GROUP BY requester_id
),


tmp2 AS (SELECT accepter_id AS id, COUNT(DISTINCT requester_id) AS fri_num FROM request_accepted
GROUP BY accepter_id
),

tmp3 AS (
SELECT a.id,
(IFNULL(b.fri_num,0) + IFNULL(c.fri_num,0)) AS num
FROM ids AS a
LEFT JOIN tmp1 AS b ON a.id = b.id
LEFT JOIN tmp2 AS c ON a.id = c.id
)

SELECT * FROM tmp3
WHERE num >= ALL(SELECT MAX(num) FROM tmp3);
```

## 603. Consecutive Available Seats

```sql
SELECT DISTINCT a.seat_id
FROM cinema AS a JOIN cinema AS b
ON ABS(a.seat_id - b.seat_id) = 1
AND a.free = TRUE AND b.free = TRUE
ORDER BY a.seat_id;
```

## 604. Design Compressed String Iterator

## 610. Triangle Judgement

```sql
SELECT *,
CASE WHEN
(x + y > z) AND (x + z > y) AND (y + z > x) THEN 'Yes'
ELSE 'No' END AS triangle
FROM triangle
```

```sql
select *,
    IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') as triangle
    FROM triangle;
```

## 612. Shortest Distance in a Plane

```sql
SELECT
ROUND(MIN(SQRT(POW(a.x - b.x, 2) + POW(a.y - b.y, 2))),2) AS shortest
FROM point_2d AS a
JOIN point_2d AS b
ON a.x <> b.x OR a.y <> b.y;
```

## 613. Shortest Distance in a Line

```sql
SELECT MIN(ABS(a.x - b.x)) AS shortest
FROM point AS a
JOIN point AS b
ON a.x <> b.x;
```

## 614. Second Degree Follower

```sql
SELECT a.follower, COUNT(DISTINCT b.follower) AS num FROM follow AS a
LEFT JOIN follow AS b
ON a.follower = b.followee
WHERE b.followee IS NOT NULL
GROUP BY a.follower
ORDER BY a.follower;
```

## 615. Average Salary: Departments VS Company

```sql
SELECT pay_month, department_id,
CASE WHEN dep_avg > com_avg THEN 'higher'
WHEN dep_avg < com_avg THEN 'lower'
ELSE 'same' END AS comparison
FROM (
SELECT LEFT(a.pay_date, 7) AS pay_month,
b.department_id, AVG(a.amount) AS dep_avg,
(SELECT AVG(amount) FROM salary AS x
 WHERE LEFT(a.pay_date, 7) = LEFT(x.pay_date, 7)
GROUP BY LEFT(x.pay_date, 7)) AS com_avg
FROM salary AS a
JOIN employee AS b
ON a.employee_id = b.employee_id
GROUP BY pay_month, b.department_id
ORDER BY pay_month DESC ) AS tmp;
```

## 616. Add Bold Tag in String

## 618. Students Report By Geography

```sql
SELECT America, Asia, Europe
FROM
(SELECT @r1 := 0, @r2 := 0, @r3 := 0) AS t,
(
SELECT @r1:= @r1 + 1 AS rowid, name AS America
FROM student
WHERE continent = 'America'
ORDER BY name
) AS t1
LEFT JOIN
(
SELECT @r2:= @r2 + 1 AS rowid, name AS Asia
FROM student
WHERE continent = 'Asia'
ORDER BY name
) AS t2
ON t1.rowid = t2.rowid
LEFT JOIN
(
SELECT @r3:= @r3 + 1 AS rowid, name AS Europe
FROM student
WHERE continent = 'Europe'
ORDER BY name
) AS t3
ON t1.rowid = t3.rowid;
```

## 619. Biggest Single Number

```sql
SELECT MAX(num) AS num FROM
(
SELECT num FROM my_numbers
GROUP BY num
HAVING COUNT(*) = 1
) AS x;
```

## 624. Maximum Distance in Arrays

题目描述：从不同的数组中各取一个数字，使得这两个数字的差的绝对值最大。要求必须来自两个不同的数组。

1. 用两个变量 start 和 end 分别表示当前遍历过的数组中最小的首元素和最大的尾元素，每当遍历到一个新的数组时，只需计算新数组尾元素和 start 绝对差，跟 end 和新数组首元素的绝对差，取二者之间的较大值来更新结果res即可。

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, start = arrays[0][0], end = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - start), abs(end - arrays[i][0])));
            start = min(start, arrays[i][0]);
            end = max(end, arrays[i].back());
        }
        return res;
    }
};
```

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

题目描述：实现一个最大栈，包含一般栈的功能，但是还新加了两个功能 `peekMax()` 和 `popMax()`，随时随地可以查看和弹出最大值。

1. 使用两个栈来模拟，s1 为普通的栈，用来保存所有的数字，s2 为最大栈，用来保存出现的最大的数字。
   - push()：如果 s2 为空，或者 s2 的栈顶元素小于等于 x，将 x 压入 s2 中。然后将数字压入 s1，s1保存所有的数字。
   - pop()：当 s2 的栈顶元素和 s1 的栈顶元素相同时，移除 s2 的栈顶元素。然后取出s1的栈顶元素。
   - top()：直接返回 s1 的 top() 函数即可。
   - peekMax()：直接返回 s2 的 top() 函数即可。
   - popMax()：先将 s2 的栈顶元素保存到一个变量 mx 中，用一个临时栈 t，将 s1 的出栈元素保存到临时栈 t 中，当 s1 的栈顶元素和 s2 的栈顶元素相同时退出while循环，此时在 s1 中找到了 s2 的栈顶元素，分别将 s1 和 s2 的栈顶元素移除，然后将临时栈 t 中的元素加回 s1 中，注意加回过程中需要同时更新 s2，此处直接调用 push() 函数即可。
2. 用一个 list 链表来保存所有的数字，然后建立一个数字和包含所有相同的数字的位置 iterator 的向量容器的映射 map。
   - push()：把新数字加到 list 表头，然后把数字 x 的位置 iterator 加到数字映射的向量容器的末尾。
   - pop()：先得到表头数字，然后把该数字对应的 iterator 向量容器的末尾元素删掉，如果此时向量容器为空了，将这个映射直接删除，移除表头数字，返回该数字即可。
   - top()：直接返回表头数字即可。
   - peekMax()：因为 map 是按 key 值自动排序的，直接返回尾映射的 key 值即可。
   - popMax()：首先保存尾映射的 key 值，也就是最大值到变量 x 中，然后在其对应的向量容器的末尾取出其在 list 中的 iterator。然后删除该向量容器的尾元素，如果此时向量容器为空了，将这个映射直接删除。根据之前取出的 iterator，在 list 中删除对应的数字，返回 x 即可。

```cpp
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        if (s2.empty() || s2.top() <= x) s2.push(x);
        s1.push(x);
    }

    int pop() {
        if (!s2.empty() && s2.top() == s1.top()) s2.pop();
        int t = s1.top(); s1.pop();
        return t;
    }

    int top() {
        return s1.top();
    }

    int peekMax() {
        return s2.top();
    }

    int popMax() {
        int mx = s2.top();
        stack<int> t;
        while (s1.top() != s2.top()) {
            t.push(s1.top()); s1.pop();
        }
        s1.pop(); s2.pop();
        while (!t.empty()) {
            push(t.top()); t.pop();
        }
        return mx;
    }

private:
    stack<int> s1, s2;
};
```

```cpp
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        v.insert(v.begin(), x);
        m[x].push_back(v.begin());
    }

    int pop() {
        int x = *v.begin();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(v.begin());
        return x;
    }

    int top() {
        return *v.begin();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(it);
        return x;
    }

private:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
};
```

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
