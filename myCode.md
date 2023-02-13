## 328. Odd Even Linked List

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。所有奇节点在前，偶节点在后。

1. 双指针
   - pre 指向奇节点，cur 指向偶节点
   - 偶节点 cur 后面的那个奇节点提前到 pre 的后面，然后 pre 和 cur 各自前进一步，此时 cur 又指向偶节点，pre 指向当前奇节点的末尾
   - 以此类推直至把所有的偶节点都提前即可
2. 奇偶指针
   - 奇偶指针分别指向奇偶节点的起始位置，另外需要一个单独的指针 even_head 来保存偶节点的起点位置
   - 把奇节点的指向偶节点的下一个(一定是奇节点)，此奇节点后移一步
   - 再把偶节点指向下一个奇节点的下一个(一定是偶节点)，此偶节点后移一步

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};
```

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
```

## 334. Increasing Triplet Subsequence

判断数组中是否存在长度为 3 的递增子序列。要求 O(n) 时间复杂度和 O(1) 的空间复杂度。

1. 使用两个指针 m1 和 m2，初始化为整型最大值，m1 表示最小值，m2 表示次小值。
   - 遍历数组，如果 m1 大于等于当前数字，将当前数字赋给 m1
   - 如果 m1 小于当前数字且 m2 大于等于当前数字，将当前数字赋给 m2，一旦 m2 被更新了，说明成功组成了一个长度为 2 的递增子序列
   - 接下来一旦遍历到比 m2 还大的数，直接返回ture。
   - 如果遇到比 m1 小的数还是要更新 m1，有可能的话也要更新 m2 为更小的值
2. 建立两个数组，forward 数组和 backward 数组
   - forward[i] 表示 [0, i] 之间最小的数
   - backward[i] 表示 [i, n-1] 之间最大的数
   - 对于任意一个位置 i，如果满足 forward[i] < nums[i] < backward[i]，表示这个递增三元子序列存在
   - 空间复杂度为 O(n)

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};
```

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int n = nums.size();
        vector<int> f(n, nums[0]), b(n, nums.back());
        for (int i = 1; i < n; ++i) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > f[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};
```

## 365. Water and Jug Problem

有两个容量分别为 x 升 和 y 升 的水壶以及无限多的水，能否通过这两个水壶得到恰好 z 升的水？

问题其实可以转换为有一个很大的容器，有两个杯子，容量分别为 x 和 y，问通过用两个杯子往里倒水，和往出舀水，问能不能使容器中的水刚好为z升。那么这里可以用一个公式来表达：

$$z = m * x + n * y$$

其中 m，n 为舀水和倒水的次数，正数表示往里舀水，负数表示往外倒水。

根据裴蜀定理，等式 $ax + by = d$ 中的 x 和 y 有解的 d 最小正值为 `gcd(x, y)`，当 d 为 gcd(x, y) 的倍数时，也是有解的。所以只要 `z % gcd(x, y) == 0`，上面的等式就有解。

除此还有个限制条件 `x + y >= z`，因为 x 和 y 不可能称出比它们之和还多的水。

1. 计算 `z % gcd(x, y) == 0` 即可。

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};
```

## 378. Kth Smallest Element in a Sorted Matrix

一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。

1. 二分查找
   - 由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，从而得到搜索范围
   - 在每一行都查找第一个大于 mid 的数字，如果目标数在比该行的尾元素大，返回该行元素的个数，如果目标数比该行首元素小，返回 0
   - 遍历完所有的行可以找出中间数是第几小的数，然后和 k 比较，进行二分查找，left 和 right 最终会相等，并且会变成数组中第 k 小的数字。
   - 时间复杂度为 O(nlgn*lgX)，其中 X 为最大值和最小值的差值
2. 二分查找进一步优化，利用每列有序的性质
   - 从数组的左下角开始查找，如果比目标值小，就向右移一位，而且当前列的当前位置的上面所有的数字都小于目标值，那么 cnt += (i + 1)，反之则向上移一位，这样也能算出 cnt 的值
   - 时间复杂度为 O(nlgX)，其中 X 为最大值和最小值的差值

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                // 使用 upper_bound 函数可以查找第一个大于目标数的元素
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
```

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};
```

## 394. Decode String

解码字符串，字符串形如 "2[abc]3[cd]ef"，解码后得到 "abcabccdcdcdef"

1. 迭代+栈
   - 两个栈，分别存储数字和当前字符串。当遇到 ']' 时，不断让字符串弹出直至遇到 '['，然后拼接这些字符串，并重复数字栈最顶端数字的次数。
   - 为了方便处理，对于初始字符串左右两边做了下处理变成 "1[s]" 的形式。

```cpp
// 2020-11-20 submission
class Solution {
public:
    string decodeString(string s) {
        s = "1[" + s + "]";
        int len = s.length(), cur = 0;
        stack<int> nums;
        stack<string> stk;
        while(cur < len) {
            if (isdigit(s[cur])) {
                int tail = cur;
                while(isdigit(s[++tail]));
                nums.push(stoi(s.substr(cur, tail - cur)));
                cur = tail;
            }
            else if (s[cur] == ']') {
                string tmp = "", res = "";
                while (stk.top() != "[") {
                    tmp.insert(0, stk.top());
                    stk.pop();
                }
                for (int i = 0; i < nums.top(); i++)
                    res += tmp;
                nums.pop(); stk.pop();
                stk.push(res);
                cur++; // 不能够在判断语句 s[cur++] == ']'，这样即使不满足条件也会 cur++
            }
            else stk.push(string(1, s[cur++]));
        }
        return stk.top();
    }
};
```

## 416. Partition Equal Subset Sum

给定一个只包含正整数的非空数组 nums，判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

1. 动态规划
   - dp[i] 表示原数组是否可以取出若干个数字，其和为 i，dp[0] 为 true
   - 状态转移方程 `dp[j] = dp[j] || dp[j - nums[i]]  (nums[i] <= j <= target)`
2. bitset
   - 第 i 位表示数组中是否能取出若干个数字，其和为 i
   - 数组的长度和每个数字的大小都不会超过 100，最大的和为 10000，一半就是 5000，bitset 长度最多不会超过 5001
   - 对于遍历到的数字 num，把 bits 向左平移 num 位，然后再或上原来的 bits，这样所有的可能出现的和位置上都为 1
   - 遍历完整个数组后，查看 bits[sum >> 1] 是否为 1

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
```

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
```

## 445. Add Two Numbers II

两个非空链表代表两个非负整数，数字最高位位于链表开始位置，它们的每个节点只存储一位数字，将这两数相加会返回一个新的链表。除了数字 0 之外，这两个数字都不会以零开头。

1. 栈：利用栈来保存所有的元素，然后利用栈的后进先出的特点就可以从后往前取数字。建立一个值为0的 res 节点，然后开始循环，如果栈不为空，则将栈顶数字加入 sum 中，然后将 res 节点值赋为 sum%10，然后新建一个进位节点 head，赋值为 sum/10，如果没有进位，那么就是0，然后在 head 后面连上 res，将 res 指向 head，这样循环退出后，我们只要看 res 的值是否为 0，为 0 返回 res->next，不为 0 则返回 res 即可。
2. 递归：首先统计出两个链表长度，然后根据长度来调用递归函数，需要传一个参数差值，递归函数参数中的 l1 链表长度长于 l2。

```cpp
// 2020-11-08 submission (栈)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};
```

```cpp
// 2020-11-08 submission (递归)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *head = new ListNode(1);
        head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
        if (head->next->val > 9) {
            head->next->val %= 10;
            return head;
        }
        return head->next;
    }
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
        if (!l1) return NULL;
        ListNode *res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode *post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            ++res->val;
        }
        res->next = post;
        return res;
    }
};
```

## 547. Friend Circles

班上有 N 名学生，其中有些人是朋友，有些则不是。他们的友谊具有传递性，如果已知 A 是 B 的朋友，B 是 C 的朋友，可以认为 A 也是 C 的朋友。朋友圈指所有朋友的集合。给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系，如果 `M[i][j] = 1`，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。输出所有学生中的已知的朋友圈总数。

1. 并查集：并查集的特点是孩子结点指向父亲结点，两个结点连接在一起即它们有相同的根结点。
   - 初始时给每一个对象都赋上不同的标签，然后对于属于同一类的对象，在 root 中查找其标签，如果不同，那么将其中一个对象的标签赋值给另一个对象
   - 初始设置朋友圈个数为 n，每次发现两个对象标签不一致时，朋友圈个数减 1

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = getRoot(root, i);
                    int p2 = getRoot(root, j);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};
```

## 611. Valid Triangle Number

给定非负数组，能组成多少个正确的三角形。

三角形任意两条边之和要大于第三边，问题其实就变成了找出所有这样的三个数字，使得任意两个数字之和都大于第三个数字。如果三个数字中如果较小的两个数字之和大于第三个数字，那么任意两个数字之和都大于第三个数字。

1. 排序 + 二分查找
   - 先确定前两个数，将这两个数之和 sum 作为目标值，然后用二分查找法快速确定第一个大于等于目标值的下标，下标减一为最后一格小于目标值的数字。
   - 时间复杂度为 O(n^2logn)
2. 排序 + 双指针
   - left 指向首数字，从右往左固定最长边，开始循环
   - 如果 left 小于 right 就进行循环，循环里面判断如果 left 指向的数加上 right 指向的数大于当长边，那么 right 到 left之间的数字都可以组成三角形
   - 时间复杂度为 O(n^2)

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j], left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid;
                }
                res += right - 1 - j;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};
```

## 718. Maximum Length of Repeated Subarray

最长公共子数组。

1. 动态规划
   - dp[i][j] 表示数组 A 的前 i 个数字和数组 B 的前 j 个数字在尾部匹配的最长子数组的长度
   - 如果 dp[i][j] 不为0，则 A 中第 i 个数组和 B 中第 j 个数字必须相等，且 dp[i][j] 的值就是往前推分别相等的个数。

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0, m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
```

## 1143. Longest Common Subsequence

最长公共子序列。

1. 动态规划
   - dp[i][j] 表示 text1 的前 i 个字符和 text2 的前 j 个字符的最长相同的子序列的字符个数
   - 若二者对应位置的字符相同，表示当前的 LCS 又增加了一位，所以 `dp[i][j] = dp[i-1][j-1] + 1`。
   - 若对应位置的字符不相同，由于是子序列，还可以错位比较，可以分别从 text1 或者 text2 去掉一个当前字符，`dp[i][j] = max( dp[i-1][j], dp[i][j-1])`。

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
```
