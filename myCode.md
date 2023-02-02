## 327. Count of Range Sum

求数组中，值位于范围 [lower, upper] (包含lower 和upper) 之内的区间和的个数。

1. multiset
   - 首先计算出一个累计和数组 accum，`accum[i]=accum[i-1]+nums[i]` 那问题可以转化为求解所有的区间 (j, i]，满足 `lower <= accum[i]-accum[j] <= upper`，亦可写成 `accum[i]-upper <= accum[j] <= accum[i]-lower`。
   - lower_bound() 是找数组中第一个不小于给定值的数(包括等于情况)，而 upper_bound() 是找数组中第一个大于给定值的数，distance() 方法返回两个迭代器之间的距离。
2. 归并排序(TODO)

**边界条件**

1. 出现 INT_MIN 和 INT_MAX

```cpp
// 2020-11-26 submission
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

```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countAndMergeSort(sums, 0, sums.size(), lower, upper);
    }
    int countAndMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int cnt = countAndMergeSort(sums, start, mid, lower, upper) + countAndMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<int> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            cnt += j - k;
        }
        copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return cnt;
    }
};
```

## 435 Non-overlapping Intervals

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

1. 贪心算法：为了保证总体去掉的区间数最小，去掉 end 值较大的区间。

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, n = intervals.size(), last = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[last][1]) {
                ++res;
                if (intervals[i][1] < intervals[last][1]) last = i;
            } else {
                last = i;
            }
        }
        return res;
    }
};
```

## 543. Diameter of Binary Tree

求二叉树的直径，直径即两点之间的最远距离。

1. 对每一个结点求出其左右子树深度之和，然后再对左右子结点分别调用求直径对递归函数，这三个值相互比较，取最大的值更新结果 res，因为直径不一定会经过根结点，所以才要对左右子结点再分别算一次。为了减少重复计算，用哈希表建立每个结点和其深度之间的映射。
2. TODO 两次 DFS 或树型dp：[树的直径 - OI Wiki](https://oi-wiki.org/graph/tree-diameter/)

```cpp
// 2021-03-17 submission
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        int res = 0;
        maxDepth(root, res, m);
        return res;
    }
    int maxDepth(TreeNode* node, int& res, unordered_map<TreeNode*, int>& m) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int left = maxDepth(node->left, res, m);
        int right = maxDepth(node->right, res, m);
        res = max(res, left + right);
        return m[node] = (max(left, right) + 1);
    }
};
```

## 85. Maximal Rectangle

给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

1. 先确定高度和宽度再得到最大面积
   - 维护三个数组（左连续序列长度、右连续序列长度、高度）
   - 左连续序列长度：指从左边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
   - 右连续序列长度：指从右边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
   - 进行行遍历，若当前位置为 "1"，要考虑上一侧行遍历序列长度是否大于 0。如果大于 0 说明正上面位置为 "1"，则取连续的行 "1" 长度和上一次序列遍历长度的最小值，否则，直接认为序列长度为连续的行 "1" 长度；若当前位置为 "0"，序列长度直接置 0。
2. 统计每一行的连续 1 的个数
   - 使用一个数组 h_max, 其中 `h_max[i][j]` 表示第 i 行，第 j 个位置水平方向连续 1 的个数，若 `matrix[i][j]` 为 0，那对应的 `h_max[i][j]` 也一定为 0。
   - 统计的过程跟建立累加和数组很类似，唯一不同的是遇到 0 了要将 h_max 置 0。
   - 统计完成之后，只需要再次遍历每个位置，首先每个位置的 h_max 值都先用来更新结果 res，因为高度为 1 也可以看作是矩形，然后我们向上方遍历，上方 (i, j-1) 位置也会有 h_max 值，但是用二者之间的较小值才能构成矩形，用新的矩形面积来更新结果 res，这样一直向上遍历，直到遇到 0，或者是越界的时候停止，这样就可以找出所有的矩形

**边界条件**

1. 矩阵为空

```cpp
// 2020-09-15 submission
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

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h_max(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                if (j > 0) h_max[i][j] = h_max[i][j - 1] + 1;
                else h_max[i][0] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (h_max[i][j] == 0) continue;
                int mn = h_max[i][j];
                res = max(res, mn);
                for (int k = i - 1; k >= 0 && h_max[k][j] != 0; --k) {
                    mn = min(mn, h_max[k][j]);
                    res = max(res, mn * (i - k + 1));
                }
            }
        }
        return res;
    }
};
```

## 87. Scramble String

使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：

- 如果字符串的长度为 1 ，算法停止
- 如果字符串的长度 > 1 ，执行下述步骤：
  - 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
  - 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
  - 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
  - 给定两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。

1. 递归
   - 将字符串按照不同长度进行切割，然后让子递归函数判断是否成立。注意一个词和它自身是 scramble 的。
   - 为了减少复杂度，每次切割前可以采用排序或者统计字母频率等。

TODO：https://github.com/grandyang/leetcode/issues/87

```cpp
// 2020-07-16 submission
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
```

## 57. Insert Interval

在列表中插入一个新的区间，需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

1. 从最左边遍历待插入区间，如果遍历区间右边界小于新区间左边界，将遍历区间加入结果，否则跳出循环。然后正式对交叉的区间进行处理，注意每次处理前都要判断是否重叠（因为有可能出现新区建在最左边和最右边的情况），然后取左边界最小值和右边界最大值作为新区间。不重叠时候跳出循环，将新区间加入结果，最后把剩下的待插入区间遍历完即可，所以有三个阶段。
2. 上述方法的进一步简化：合并原列表中所有与新区间交叉重叠的区间，最后再把该区间插入到结果列表中。

**边界条件**

1. 待插列表为空；
2. 新区间在最左边或者最右边；
3. 插入区间为空

```cpp
// 2020-07-14 submission
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) return intervals;
        vector<vector<int>> res;

        int cur = 0;
        int cnt = intervals.size();
        while(cur < cnt) {
            if (intervals[cur][1] < newInterval[0])
                res.push_back(intervals[cur++]);
            else break;
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
```

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};
```

## 111. Minimum Depth of Binary Tree

二叉树的最小深度。

1. 递归：首先判空，若当前结点不存在，直接返回 0。若左子结点不存在，那么对右子结点调用递归函数，并加 1 返回。反之，若右子结点不存在，那么对左子结点调用递归函数，并加 1 返回。最后分别对左右子结点调用递归函数，将二者中的较小值加 1 返回即可。
2. 迭代：层序遍历，记录遍历的层数，一旦遍历到第一个叶结点，就将当前层数返回，即为二叉树的最小深度。

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
```

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                if (!t->left && !t->right) return res;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return -1;
    }
};
```

## 97. Interleaving String

给定字符串 s1，s2 和 s3，问 s3 是不是由 s1 和 s2 交织组成。

1. 动态规划
   - 前提：字符串 s1 和 s2 的长度和必须等于 s3 的长度
   - 初始化：若 s1 和 s2 其中的一个为空串的话，那么另一个肯定和 s3 的长度相等，则按位比较
   - 在任意非边缘位置 `dp[i][j]` 时，它的左边或上边有可能为 True 或是 False，两边都可以更新过来，只要有一条路通着，那么这个点就可以为 True
   - 转移方程：`dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i])`;
2. DFS + HashSet
   - 分别用变量i，j，和k来记录字符串 s1，s2，和 s3 匹配到的位置，初始化的时候都传入0。
   - 在递归函数中，首先根据 i 和 j 算出 key 值，如果 key 已经在集合中，直接返回 false，因为集合中存的是无法匹配的情况。
   - corner case：如果 i 等于 s1 的长度了，说明 s1 的字符都匹配完了，此时 s2 剩下的字符和 s3 剩下的字符可以直接进行匹配。同理，如果 j 等于 s2 的长度了，说明 s2 的字符都匹配完了，此时 s1 剩下的字符和 s3 剩下的字符可以直接进行匹配。
   - 如果 s1 和 s2 都有剩余字符，那么当 s1 的当前字符等于 s3 的当前字符，那么调用递归函数，注意 i 和 k 都加上 1，如果递归函数返回 true，则当前函数也返回 true；还有一种情况是，当 s2 的当前字符等于 s3 的当前字符，那么调用递归函数，注意 j 和 k 都加上 1，如果递归函数返回 true，那么当前函数也返回 true。
   - 如果匹配失败了，则将 key 加入集合中，并返回 false 即可

**边界条件**

1. s1 或者 s2 为空

```cpp
// 2020-09-14 submission
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

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        unordered_set<int> s;
        return helper(s1, 0, s2, 0, s3, 0, s);
    }
    bool helper(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
        int key = i * s3.length() + j;
        if (s.count(key)) return false;
        if (i == s1.length()) return s2.substr(j) == s3.substr(k);
        if (j == s2.length()) return s1.substr(i) == s3.substr(k);
        if ((s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, s)) ||
            (s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, s))) return true;
        s.insert(key);
        return false;
    }
};
```

## 10. Regular Expression Matching

正则匹配：`.` 匹配任意单个字符，`*` 匹配 0 个或多个前置字符。

1. 正则匹配
   - sp 和 pp 都到了末尾，表示匹配结束
   - 如果 p 的后置字符为 *，(1) p 的当前字符为 . (2) p 的当前字符匹配 s 的当前字符，如果满足上述两种情况之一，s 后移一位，继续递归。
   - 如果上述情况返回错误，说明 * 匹配失效，p 后移两位，继续递归。
   - 最后进行普通匹配，(1) p 的当前字符为 . (2) p 的当前字符匹配 s 的当前字符，如果满足上述两种情况之一，s 和 p 均后移一位，继续递归。

TODO 贪婪匹配 VS 非贪婪匹配

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

    bool helper(string& s, string& p, int sp, int pp) {
        if(sp == s.size() && pp == p.size()) return true;
        if(pp+1 < p.size() && p[pp+1] == '*') {
            if(sp < s.size() && (p[pp] == '.' || p[pp]==s[sp])) {
                if(helper(s, p, sp+1, pp)) return true;
            }
            return helper(s, p, sp, pp+2);
        }
        if(sp < s.size() && (p[pp] == '.' || p[pp] == s[sp])) return helper(s, p, sp+1, pp+1);
        else return false;
    }
};
```

## 164. Maximum Gap

给一个乱序的数组，求出数组排序以后的相邻数字的差最大是多少。要求时间复杂度 O(n)。

1. 桶排序
   - 首先找出数组的最大值和最小值以确定每个桶的容量，即为 len = (max - min) / n + 1
   - 区间分别为：`[min,min+len)`, `[min+len,min+2*len)`, `[min+2*len,min+3*len)`, ... `[max-len,max]`
   - 桶的个数为 (max - min) / len + 1
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
        int size = (mx - mn) / n + 1, cnt = (mx - mn) / size + 1;
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

## 91. Decode Ways

一条包含字母 A-Z 的消息通过以下映射进行了编码：'A' -> 1, 'B' -> 2, ..., 'Z' -> 26，要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为："AAJF" 将消息分组为 (1 1 10 6) 或者 "KJF" 将消息分组为 (11 10 6)。

1. 动态规划
   - dp[i] 表示 s 中前 i 个字符组成的子串的解码方法的个数
   - 计算 dp[i] 时，若 s[i] 和 s[i-1] 拼起来的两位数小于等于 26，并且大于等于 10（因为两位数的高位不能是0），那么就可以在之前 dp[i-2] 的每种情况下都加上这个二位数，所以最终 dp[i] = dp[i-1] + dp[i-2]
   - 若当前位置是 0，则一定无法单独拆分出来，即不能加上 dp[i-1]，就只能看否跟前一个数字组成大于等于 10 且小于等于 26 的数，能的话可以加上 dp[i-2]，否则就只能保持为 0
2. 用两个变量 a, b 来分别表示 s[i-1] 和 s[i-2] 的解码方法，然后从字符串的第二个字符开始遍历，判断如果当前字符为 '0'，说明当前字符不能单独拆分出来，只能和前一个字符一起，先将 a 赋为 0，然后看前面的字符，如果前面的字符是 1 或者 2 时，就可以更新 a = a + b，然后 b = a - b，其实 b 赋值为之前的 a，如果不满足这些条件的话，那么 b = a。

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
```

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int a = 1, b = 1, n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') a = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                a = a + b;
                b = a - b;
            } else {
                b = a;
            }
        }
        return a;
    }
};
```

## 233. Number of Digit One

统计比给定数小的所有数中 1 出现的个数。

解题思路

1. 分类讨论
   - 10 以内的数字：看个位数是否大于 1，是就加上 1
   - 100 以内的数字：除了 10-19 之间有 11 个 '1' 之外，其余都只有 1 个。如果不考虑 [10, 19] 区间上那多出来的 10 个 '1'，对任意一个两位数，十位数上的数字(加1)就代表 1 出现的个数，这时候再把多出的 10 个加上即可。比如 56 就有 (5+1)+10=16 个。如何知道是否要加上多出的 10 个，就要看十位上的数字是否大于等于 2，是的话就要加上多余的 10 个 '1'。可以用 (x+8)/10 来判断一个数是否大于等于 2。
   - 1000 以内的数字：除了 [110, 119] 之间多出的10个数之外，共 21 个 '1'，其余的每 10 个数的区间都只有 11 个 '1'，所以 [100, 199] 内共有 21 + 11 * 9 = 120 个 '1'。[0, 999] 区间内 '1' 的个数怎么求？根据前面的结果，[0, 99] 内共有 20 个，[100, 199] 内共有 120 个，而其他每 100 个数内 '1' 的个数也应该符合之前的规律，即也是 20 个，那么总共就有 120 + 20 * 9 = 300 个 '1'。那么还是可以用相同的方法来判断并累加 1 的个数。

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
```

## 188. Best Time to Buy and Sell Stock IV

买进前必须卖出手头已有的；允许最多 k 次交易。

1. 动态规划
   - 维护两个变量：全局最优 global 和局部最优 local。
   - 定义局部最优 `local[i][j]` 为在到达第 i 天时最多可进行 j 次交易并且最后一次交易在最后一天卖出的最大利润。
   - 定义全局最优 `global[i][j]`为在到达第 i 天时最多可进行 j 次交易的最大利润。
   - 递推式为 `local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)`，`global[i][j] = max(local[i][j], global[i - 1][j])`
   - 局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值。前者是加上了 (i-1, i) 这笔交易，后者是修改最后一次交易的结束日为 i。
   - 而全局最优比较局部最优和前一天的全局最优。
   - 上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是 O(n*k)，如果是最多进行两次交易，那么复杂度还是 O(n)。空间上只需要维护当天数据皆可以，所以是 O(k)，当k=2，则是 O(1)。
   - 为了减少运算次数，当 k 远大于天数时，按照 <122. Best Time to Buy and Sell Stock II> 中无限次数交易的方法求解。

```cpp
// 2020-07-24 submission
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k > prices.size()) return maxProfit_largetrades(prices);
        vector<int> local(k+1, 0), global(k+1, 0);
        for (int day = 1; day < prices.size(); day++) {
            int diff = prices[day] - prices[day-1];
            for (int j = k; j >= 1; j--) { // 为什么要 j 从 k 遍历到 1，而不是 1 遍历到 k
                local[j] = max(global[j-1]+max(diff, 0), local[j]+diff);
                global[j] = max(local[j], global[j]);
                // cout << "day:" << day << " j:" << j << " local:"<<local[j] << " global:" << global[j] << endl;
            }
        }
        return global[k];
    }

    int maxProfit_largetrades(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                maxValue += (prices[i]-prices[i-1]);
        }
        return maxValue;
    }
};
```
