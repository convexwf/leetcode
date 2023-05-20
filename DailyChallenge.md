# Daily Challenge

## 799. Champagne Tower (2020-10-27)

解题思路

1. 动态规划：dp[i][j]表示第i行第j列的杯子将要接住的酒量（可能大于1，因为此时还没有进行多余往下流的处理），逐个遍历即可，将多余的酒量均分加入下一行的两个酒杯中即可。

```C++
// 2020-10-27 submission
// Runtime: 4 ms, faster than 94.89% of C++ online submissions for Champagne Tower.
// Memory Usage: 6.9 MB, less than 5.11% of C++ online submissions for Champagne Tower.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 1, 0.);
        dp[0] = poured;
        for (int i = 0; i < query_row; i++) {
            double last = 0.;
            for (int j = 0; j <= i; j++) {
                if (dp[j] > 1.) {
                    double temp = last + (dp[j]-1.) / 2;
                    last = (dp[j]-1.) / 2;
                    dp[j] = temp;
                }
                else {
                    dp[j] = last;
                    last = 0.;
                }
            }
            dp[i+1] = last;
        }
        return dp[query_glass] >= 1. ? 1. : dp[query_glass]; // 注意最后不能返回大于1的数
    }
};
```

## 228. Summary Ranges (2020-10-29)

解题思路

1. 用一个 nx2 的数组维护范围，若新数大于范围数组最后一个的右边界，就开辟新范围。

边界条件

1. $b - a <= 1$ 应写成 $a + 1 >= b$，防止溢出

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

## 673. Number of Longest Increasing Subsequence (2020-10-31)

解题思路

1. 题目描述：求最长递增序列的个数
2. 动态规划：用两个数组 len[i] 和 nums[i] 分别维护以当前位置为最末端的最长序列长度和最长序列长度的个数，因为一个数的长度为1，所以数组初始化为 1。遍历数组，对于每个遍历到的数字 nums[i]，再遍历其之前的所有数字 nums[j]，当 nums[i] 小于等于 nums[j] 时，不做任何处理，因为不是递增序列；反之，则判断 len[i] 和 len[j] 的关系，如果 len[i] 等于 len[j] + 1，说明 nums[i] 这个数字可以加在以 nums[j] 结尾的递增序列后面，并且以 nums[j] 结尾的递增序列个数可以直接加到以 nums[i] 结尾的递增序列个数上。如果 len[i] 小于 len[j] + 1，说明找到了一条长度更长的递增序列，那么此时将 len[i] 更新为 len[j]+1，并且原本的递增序列都不能用了，直接用 cnt[j] 来代替。在更新完 len[i] 和 cnt[i] 之后，要更新 mx 和结果 res，如果 mx 等于 len[i]，则把 cnt[i] 加到结果 res 之上；如果 mx 小于 len[i]，则更新 mx 为 len[i]，更新结果 res 为 cnt[i]。

边界条件

1. 序列为空
2. 序列只有一个数字

```C++
// 2020-10-31 submission
// Runtime: 132 ms, faster than 17.64% of C++ online submissions for Number of Longest Increasing Subsequence.
// Memory Usage: 13.5 MB, less than 8.09% of C++ online submissions for Number of Longest Increasing Subsequence.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> count(nums.size(), 1);
        vector<int> max_length(nums.size(), 1);
        int res_count = 0;
        int res_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (max_length[j] + 1 > max_length[i]) {
                    max_length[i] = max_length[j] + 1;
                    count[i] = 0;
                }
                if (max_length[j] + 1 == max_length[i]) {
                    count[i] += count[j];
                }
            }
            res_length = max(max_length[i], res_length);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (max_length[i] == res_length)
                res_count += count[i];
        }
        return res_count;
    }
};
```

## 179. Largest Number (2020-11-01)

解题思路

1. 排序：自定义排序方法，对于两个数字 a 和 b，将其都转为字符串，如果 ab > ba，则a排在前面。

边界条件

1. 数组全部为 0

```C++
// 2020-11-01 submission
// Runtime: 12 ms, faster than 60.80% of C++ online submissions for Largest Number.
// Memory Usage: 11.3 MB, less than 6.39% of C++ online submissions for Largest Number.
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};
```

## 1290. Convert Binary Number in a Linked List to Integer (2020-11-02)

```C++
// 2020-11-02 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
// Memory Usage: 8.7 MB, less than 57.06% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head) {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};
```

## 147. Insertion Sort List (2020-11-03)

```C++
// 2020-11-03 submission
// Runtime: 48 ms, faster than 72.31% of C++ online submissions for Insertion Sort List.
// Memory Usage: 10.2 MB, less than 6.04% of C++ online submissions for Insertion Sort List.
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            ListNode *t = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};
```

## 1446. Consecutive Characters (2020-11-04)

```C++
// 2020-11-04 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Consecutive Characters.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Consecutive Characters.
class Solution {
public:
    int maxPower(string s) {
        if (s.length() <= 0) return 0;
        int res = 1;
        int cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) cur++;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }
        return max(res, cur);
    }
};
```

## 1217. Minimum Cost to Move Chips to The Same Position (2020-11-06)

```C++
// 2020-11-06 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
// Memory Usage: 7.8 MB, less than 77.54% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) even++;
            else odd++;
        }
        return min(odd, even);
    }
};
```

## 1283. Find the Smallest Divisor Given a Threshold (2020-11-07)

解题思路

1. 二分搜索：除数越小商越大，所以在 sum 小于等于 threshold 的前提下，进行二分搜索找到最大的除数。

```C++
// 2020-11-07 submission
// Runtime: 60 ms, faster than 91.69% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
// Memory Usage: 20.4 MB, less than 5.65% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int middle = 0, sum = 0;
        while (left < right) {
            middle = left + (right - left) / 2;
            sum = 0;
            for (int num : nums)
                sum += (num+middle-1) / middle;
            if (sum > threshold) left = middle + 1;
            else right = middle;
        }
        return left;
    }
};
```

## 1026. Maximum Difference Between Node and Ancestor (2020-11-10)

解题思路

1. 前序遍历：在递归函数中传递两个值，分别存储当前分支的最小值和最大值。

```C++
// 2020-11-10 submission
// Runtime: 4 ms, faster than 96.88% of C++ online submissions for Maximum Difference Between Node and Ancestor.
// Memory Usage: 11.4 MB, less than 5.86% of C++ online submissions for Maximum Difference Between Node and Ancestor.
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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        if(root) maxAncestorDiff(root, root->val, root->val, res);
        return res;
    }

    void maxAncestorDiff(TreeNode* root, int min_val, int max_val, int& res) {
        if (!root) return;
        res = max(max(abs(root->val-min_val), abs(max_val-root->val)), res);
        maxAncestorDiff(root->left, min(min_val, root->val), max(max_val, root->val), res);
        maxAncestorDiff(root->right, min(min_val, root->val), max(max_val, root->val), res);
    }
};
```

## 832. Flipping an Image (2020-11-11)

解题思路

1. 新建一个跟 A 一样长的二维数组，里面的各行是空的。然后我们遍历 A 数组的各行，但在遍历各行上的数字时，我们采用从后往前的遍历顺序，然后对于每个数字取反在加入结果 res 中，这样直接将翻转和取反同时完成。

```C++
// 2020-11-11 submission
// Runtime: 4 ms, faster than 98.93% of C++ online submissions for Flipping an Image.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Flipping an Image.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = (int)A[i].size() - 1; j >= 0; --j) {
                res[i].push_back(!A[i][j]);
            }
        }
        return res;
    }
};
```

## 938. Range Sum of BST (2020-11-16)

```C++
// 2020-11-16 submission
// Runtime: 160 ms, faster than 97.72% of C++ online submissions for Range Sum of BST.
// Memory Usage: 65.3 MB, less than 35.01% of C++ online submissions for Range Sum of BST.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val < low) return rangeSumBST(root->right, low, high);
        if (root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, root->val-1) + rangeSumBST(root->right, root->val+1, high);
    }
};
```

## 858. Mirror Reflection (2020-11-18)

解题思路

1. 题目描述：激光被镜面反射，最终会被哪个接收器接收。
2. 题目必定有解，即令 $nq / p = c $，其中 $n,q,p,c$ 均是大于 0 的正整数。
3. 分类讨论 \(n\) 和 \(c\):
   + \(n\) 为奇数，\(c\) 为奇数：返回 1
   + \(n\) 为奇数，\(c\) 为偶数：返回 0
   + \(n\) 为偶数，\(c\) 为奇数：返回 2
   + \(n\) 为偶数，\(c\) 为偶数：\(n\) 和 \(c\) 都除以 2 直至上面三种情况。
4. 继而讨论 \(p\) 和 \(q\):
   + \(p\) 为奇数，\(q\) 为奇数时: 到达接收器1。
   + \(p\) 为奇数，\(q\) 为偶数时: 到达接收器0。
   + \(p\) 为偶数，\(q\) 为奇数时: 到达接收器2。

```C++
// 2020-11-18 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Mirror Reflection.
// Memory Usage: 6.3 MB, less than 14.95% of C++ online submissions for Mirror Reflection.
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2; q /= 2;
        }
        return 1 - p % 2 + q % 2;
    }
};
```

## 229. Majority Element II (2020-11-19)

解题思路

1. 题目描述：求出现次数大于 n/3 的数字，而且限定空间复杂度为 O(1)。
2. 任意一个数组出现次数大于 n/3 的数最多有两个。证明：如果有超过两个，也就是至少三个数字满足“出现的次数大于 n/3”，那么就意味着数组里总共有超过 3*(n/3) = n 个数字，这与已知的数组大小矛盾
3. 多数投票法：找出两个候选数进行投票，需要两遍遍历，第一遍历找出两个候选数，第二遍遍历重新投票验证这两个候选数是否符合题意

```C++
// 2020-11-19 submission
// Runtime: 28 ms, faster than 76.33% of C++ online submissions for Majority Element II.
// Memory Usage: 16.2 MB, less than 7.61% of C++ online submissions for Majority Element II.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
            else if (cnt1 == 0) { a = num; cnt1 = 1; }
            else if (cnt2 == 0) { b = num; cnt2 = 1; }
            else { --cnt1; --cnt2; }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
        }
        if (cnt1 > n / 3) res.push_back(a);
        if (cnt2 > n / 3) res.push_back(b);
        return res;
    }
};
```

## 415. Add Strings (2020-11-21)

解题思路

1. 题目描述：字符串加法

Follow up

1. 字符串减法
2. 字符串中有小数点和负号如何做加法

```C++
// 2020-11-21 submission
// Runtime: 4 ms, faster than 82.85% of C++ online submissions for Add Strings.
// Memory Usage: 6.9 MB, less than 79.86% of C++ online submissions for Add Strings.
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string res = "";
        int max_len = max(num1.length(), num2.length());
        for (int i = 1; i <= max_len; i++) {
            if (i <= num1.length()) carry += (num1[num1.length()-i] - '0');
            if (i <= num2.length()) carry += (num2[num2.length()-i] - '0');
            res.append(1, '0' + carry % 10);
            carry /= 10;
        }
        if (carry) res.append(1, '0' + carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 396. Rotate Function (2020-11-22)

解题思路

1. 找规律：先把具体的数字抽象为A,B,C,D，则有
   F(0) = 0A + 1B + 2C +3D
   F(1) = 0D + 1A + 2B +3C
   F(2) = 0C + 1D + 2A +3B
   F(3) = 0B + 1C + 2D +3A
   对应得到以下规律：
   得出下面的规律：
   sum = 1A + 1B + 1C + 1D
   F(1) = F(0) + sum - 4D
   F(2) = F(1) + sum - 4C
   F(3) = F(2) + sum - 4B
   综上可得 $F(i) = F(i-1) + \text{sum} - n*A[n-i]$

边界条件

1. [2147483647,2147483647]

```C++
// 2020-11-22 submission
// Runtime: 12 ms, faster than 89.46% of C++ online submissions for Rotate Function.
// Memory Usage: 11.2 MB, less than 67.17% of C++ online submissions for Rotate Function.
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 2) return *max_element(A.begin(), A.end());
        int cur = 0, sum = 0;
        for (int i = 0; i < A.size(); i++) {
            cur += (i * A[i]);
            sum += A[i];
        }
        int res = cur;
        for (int i = 1; i < A.size(); i++) {
            cur = cur + sum - A.size() * A[A.size()-i];
            res = max(res, cur);
        }
        return res;
    }
};
```

## 337. House Robber III (2020-11-23)

解题思路

1. 题目描述：抢劫树状房屋，相邻屋子不可以同时抢，求抢劫最大收获
2. 树形dp：dp[i][0]表示不选这个节点子树的最大价值，dp[i][1]表示选这个节点的子树最大价值，不选时儿子节点可以选或者不选，选时儿子节点必须不选。状态转移方程为
   $$
   \begin{aligned}
   dp[x, 0] &=\sum_{s \in \operatorname{Son}(x)} \max (dp[s, 0], d p[s, 1]) \\
   dp[x, 1] &=h[x]+\sum_{s \in \operatorname{Son}(x)} d p[s, 0]
   \end{aligned}
   $$
3. helper 函数返回当前结点为根结点的最大 rob 的钱数，里面的两个参数 l 和 r 表示分别从左子结点和右子结点开始 rob，分别能获得的最大钱数。在递归函数里面，如果当前结点不存在，直接返回0。否则对左右子结点分别调用递归函数，得到l和r。另外还得到四个变量，ll 和 lr 表示左子结点的左右子结点的最大 rob 钱数，rl 和 rr 表示右子结点的最大 rob 钱数。那么最后返回的值其实是两部分的值比较，其中一部分的值是当前的结点值加上 ll, lr, rl, 和 rr 这四个值，因为抢了当前的房屋，则左右两个子结点就不能再抢了，但是再下一层的四个子结点都是可以抢的；另一部分是不抢当前房屋，而是抢其左右两个子结点，即 l+r 的值，返回两个部分的值中的较大值即可

```C++
// 2020-11-23 submission
// Runtime: 24 ms, faster than 57.71% of C++ online submissions for House Robber III.
// Memory Usage: 26.9 MB, less than 25.93% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        vector<vector<int>> dp;
        if (root) helper(root, dp);
        else return 0;
        return max(dp.back()[0], dp.back()[1]);
    }

    void helper(TreeNode* root, vector<vector<int>>& dp) {
        int do_rob = 0, not_rob = 0;
        if (root->left) {
            helper(root->left, dp);
            do_rob += dp.back()[1];
            not_rob +=max(dp.back()[0], dp.back()[1]);
        }
        if (root->right) {
            helper(root->right, dp);
            do_rob += dp.back()[1];
            not_rob += max(dp.back()[0], dp.back()[1]);
        }
        // cout << root->val << " " << do_rob + root->val << " " << not_rob << endl;
        dp.push_back(vector<int>{do_rob + root->val, not_rob});
    }
};
```

```C++
// 2020-11-23 submission
// Runtime: 12 ms, faster than 94.84% of C++ online submissions for House Robber III.
// Memory Usage: 22.7 MB, less than 58.85% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int x = 0, y = 0;
        helper(root, x, y);
        return max(x, y);
    }

    void helper(TreeNode* root, int& do_rob, int& not_rob) {
        int cur_do_rob = 0, cur_not_rob = 0;
        if (root->left) {
            helper(root->left, do_rob, not_rob);
            cur_do_rob += not_rob;
            cur_not_rob += max(do_rob, not_rob);
        }
        if (root->right) {
            helper(root->right, do_rob, not_rob);
            cur_do_rob += not_rob;
            cur_not_rob += max(do_rob, not_rob);
        }
        do_rob = cur_do_rob + root->val;
        not_rob = cur_not_rob;
    }
};
```

```C++
// 2020-11-23 submission
// Runtime: 12 ms, faster than 94.84% of C++ online submissions for House Robber III.
// Memory Usage: 22.6 MB, less than 84.04% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }
    int helper(TreeNode* node, int& l, int& r) {
        if (!node) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};
```

## 804. Unique Morse Code Words (2020-11-24)

```C++
// 2020-11-24 submission
// Runtime: 4 ms, faster than 91.90% of C++ online submissions for Unique Morse Code Words.
// Memory Usage: 9 MB, less than 37.21% of C++ online submissions for Unique Morse Code Words.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encode_map{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> hash_set;
        int res = 0;
        for (string word : words) {
            string tmp = "";
            for (char c : word) {
                tmp += encode_map[c - 'a'];
            }
            if (!hash_set.count(tmp)) {
                res++;
                hash_set.insert(tmp);
            }
        }
        return res;
    }
};
```

## 1015. Smallest Integer Divisible by K (2020-11-27)

解题思路

1. 题目描述：给定正整数 K，求最小的能整除 K 的正整数 n，n只包含1，形如 1,11,111
2. 枚举：不需要每次都使用 n 位的 1 对 K 取余，只需要取上次运算得到结果*10+1再对K取余。其次，运算截止到 K 次，因为对 K 的余数不包括 0 的话有 K-1 个，根据抽屉原理其中必有两个相等的，即是说到达第K次时一定开始了重复循环。

```C++
// 2020-11-27 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
// Memory Usage: 6.2 MB, less than 54.12% of C++ online submissions for Smallest Integer Divisible by K.
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int last = 0;
        for (int i = 1; i <= K; i++) {
            last = (last * 10 + 1) % K;
            if (last == 0) return i;
        }
        return -1;
    }
};
```

## 211. Design Add and Search Words Data Structure (2020-12-01)

解题思路

1. 前缀树+BFS/DFS：前缀树实现参见 ## 208. Implement Trie (Prefix Tree)。由于加入了 '.'（代替任意字符），就需要查找所有的子树，可以用 DFS 或者 BFS 实现。

Follow up

1. 如果使用 '*'（代替任意多个字符）

```C++
// 2020-12-01 submission (前缀树+BFS)
// Runtime: 132 ms, faster than 53.20% of C++ online submissions for Design Add and Search Words Data Structure.
// Memory Usage: 60.7 MB, less than 32.16% of C++ online submissions for Design Add and Search Words Data Structure.
class Trie_Node{
public:
    Trie_Node* child[26];
    bool is_word;
    Trie_Node() {
        is_word = false;
        for (auto& ptr : child) {
            ptr = NULL;
        }
    }
};

class WordDictionary {
public:
    Trie_Node* root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie_Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie_Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) {
                cur->child[word[i]-'a'] = new Trie_Node();
            }
            cur = cur->child[word[i]-'a'];
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<Trie_Node*> q;
        q.push(root);
        int cur_size = 0;
        for (int i = 0; i < word.length(); i++) {
            if (q.empty()) return false;
            cur_size = q.size();
            for (int j = 0; j < cur_size; j++) {
                Trie_Node* cur = q.front(); q.pop();
                if (word[i] == '.') {
                    for (auto ptr : cur->child) {
                        if (ptr) q.push(ptr);
                    }
                }
                else if (cur->child[word[i]-'a']) q.push(cur->child[word[i]-'a']);
            }
        }
        while (!q.empty()) {
            if (q.front()->is_word) return true;
            q.pop();
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

```C++
// 2020-12-01 submission (前缀树+DFS)
// Runtime: 84 ms, faster than 95.74% of C++ online submissions for Design Add and Search Words Data Structure.
// Memory Usage: 46.6 MB, less than 39.48% of C++ online submissions for Design Add and Search Words Data Structure.
class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }

private:
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
```

### 382. Linked List Random Node (2020-12-03)

解题思路

1. 水塘抽样：首先让返回值等于 head 的值，并记录当前遍历过的节点数量 cnt。每遍历到一个新的节点时，就从 [0, cnt] 中取随机数 k，如果 k 为 0 就让返回值为当前节点值。

```C++
// 2020-12-03 submission
// Runtime: 32 ms, faster than 75.61% of C++ online submissions for Linked List Random Node.
// Memory Usage: 16.9 MB, less than 66.08% of C++ online submissions for Linked List Random Node.
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
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head->next;
        int res = head->val, cnt = 1;
        while(cur) {
            if (rand() % (cnt + 1) == 0) res = cur->val;
            ++cnt;
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

## 897. Increasing Order Search Tree (2020-12-04)

解题思路

1. 当 root 为空时，直接返回空，当 root 没有左右子结点时，也是直接返回 root。当 root 只有一个左子结点时，我们此时要把其左子结点变为根结点，将原来的根结点变成其原来的左子结点的右子结点。但是如果 root 只有一个右子结点，还是保持原来的顺序不变，而若 root 同时具有左右子结点的话，还是要将左子结点变为根结点，然后把之前的根结点连到右子结点上，之前的右子结点还连在之前的根结点上，这个不用改变。我们可以发现，最麻烦的就是左子结点了，需要和其根结点交换位置，所以对于每个结点，我们需要知道其父结点的位置，那么就在递归函数的参数中传入一个 pre 结点，再对左右子结点调用递归函数时，都将其下一个要连接的结点传入，这个 pre 结点可能是当前结点或者当前结点的父结点。
   在递归函数中，首先判空，若当前结点为空的话，直接返回 pre 结点，因为到空结点的时候，说明已经遍历到叶结点的下方了，那么 pre 就是这个叶结点了。由于是中序遍历，所以要先对左子结点调用递归函数，将返回值保存到一个新的结点 res 中，表示的意义是此时 node 的左子树已经全部捋直了，而且根结点就是 res，而且 node 结点本身也被连到了捋直后的左子树下，即此时左子结点和根结点已经完成了交换位子，当然要断开原来的连接，所以将 node->left 赋值为 nullptr。然后再对 node 的右子结点调用递归函数，注意此时的 pre 不能传入 node 本身，而是要传 node 结点的 pre 结点，这是因为右子结点后面要连接的是 node 的父结点，比如兑入下面这例子：

```C++
// 2020-12-04 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Increasing Order Search Tree.
// Memory Usage: 8 MB, less than 67.99% of C++ online submissions for Increasing Order Search Tree.
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
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, nullptr);
    }

    TreeNode* helper(TreeNode* node, TreeNode* pre) {
        if (!node) return pre;
        TreeNode* res = helper(node->left, node);
        node->left = nullptr;
        node->right = helper(node->right, pre);
        return res;
    }
};
```

## 401. Binary Watch (2020-12-05)

解题思路

1. bitset：问题实质求十进制数如果用二进制表示有多少个 ‘1’ 的问题。bitset 类可以将任意进制数转为二进制，而且又用到了count函数，用来统计1的个数。那么时针从0遍历到11，分针从0遍历到59，然后把时针的数组左移6位加上分针的数值，然后统计1的个数，即为亮灯的个数。

```C++
// 2020-12-05 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Watch.
// Memory Usage: 6.8 MB, less than 47.89% of C++ online submissions for Binary Watch.
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};
```

## 605. Can Place Flowers (2020-12-06)

解题思路

1. 长度为 n 的 0 序列最多能放下 (n - 1) / 2 盆花。注意首尾处理。

```C++
// 2020-12-06 submission
// Runtime: 36 ms, faster than 47.15% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.6 MB, less than 67.29% of C++ online submissions for Can Place Flowers.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cur = 1;
        int max_f = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                max_f += (cur - 1) / 2;
                cur = 0;
            }
            else cur++;
        }
        max_f += cur / 2;
        return max_f >= n;
    }
};
```

## 372. Super Pow (2020-12-07)

解题思路

1. 需要自行实现一个求幂函数以防溢出。可以发现 $2^{23} = (2^{2})^{10} * 2^{3}$，所以可以从 b 的最高位开始，算出结果存入res，然后到下一位时，res的十次方再乘以 a 的该位次方再对 1337 取余。
2. 取余规则：
   （1）$ (a \pm b) \% p = (a \% p \pm b \% p) \% p $
   （2）$ (a *b) \% p = (a \% p* b \% p) \% p $
   （3）$ a ^ b \% p = ((a \% p)^b) \% p $
   （4）结合律：$ ((a+b) \% p + c) \% p = (a + (b+c) \% p) \% p $
   （5）$ ((a*b) \% p* c) \% p = (a *(b*c) \% p) \% p $
   （6）交换律：$ (a + b) \% p = (b+a) \% p $
   （7）$ (a *b) \% p = (b* a) \% p $
   （8）分配律：$ ((a +b)\% p *c) \% p = ((a* c) \% p + (b * c) \% p) \% p $

```C++
// 2020-12-07 submission
// Runtime: 32 ms, faster than 15.03% of C++ online submissions for Super Pow.
// Memory Usage: 12 MB, less than 72.73% of C++ online submissions for Super Pow.
class Solution {
public:

    int pow_n(int x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x % 1337;
        return pow_n(x % 1337, y / 2) * pow_n(x % 1337, y - y / 2) % 1337;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); i++) {
            res = (pow_n(res, 10) * pow_n(a % 1337, b[i])) % 1337;
        }
        return res;
    }
};
```

## 393. UTF-8 Validation (2020-12-08)

解题思路

1. 位操作：验证一个数字某几位的方法可以用 !(a & mask ^ target)。用一个指示变量记录当前 UTF-8 所需要记录的字节数，如果指示变量为 0，表示进入了新的一轮识别，需要通过验证判断当前字节数；如果大于0，说明是次字节或次次字节或次次次字节，需要判断是否合法。

```C++
// 2020-12-08 submission
// Runtime: 16 ms, faster than 97.04% of C++ online submissions for UTF-8 Validation.
// Memory Usage: 14.3 MB, less than 80.47% of C++ online submissions for UTF-8 Validation.
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (flag == 0) {
                if (!(data[i] & 0b10000000 ^ 0b00000000)) flag = 0;
                else if (!(data[i] & 0b11100000 ^ 0b11000000)) flag = 1;
                else if (!(data[i] & 0b11110000 ^ 0b11100000)) flag = 2;
                else if (!(data[i] & 0b11111000 ^ 0b11110000)) flag = 3;
                else return false;
            }
            else {
                if (!(data[i] & 0b11000000 ^ 0b10000000)) flag--;
                else return false;
            }
        }
        return flag == 0;
    }
};
```

## 885. Spiral Matrix III (2020-12-09)

解题思路

1. 顺时针走法是按照 [ '→', '↓', '←', '↑', ] 的顺序转向，注意转向时行走步数是按照 $1, 1, 2, 2, 3, 3, 4, 4 ......$ 的规律进行，所以每当遇到 '→' 和 '←' 就需要将行走步数+1。即使走出边缘也无所谓，判断当前位置是否合法，如果不合法继续行走，合法就将当前位置输出，直至走完所有合法位置。

```C++
// 2020-12-09 submission
// Runtime: 20 ms, faster than 97.35% of C++ online submissions for Spiral Matrix III.
// Memory Usage: 12.7 MB, less than 37.30% of C++ online submissions for Spiral Matrix III.
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        int di = 0;

        int cnt = 0, step = 1;
        while (cnt < R * C) {
            for (int j = 0; j < step; j++) {
                if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C) {
                    ++cnt;
                    res.push_back(vector<int>{r0, c0});
                }
                r0 += direction[di][0]; c0 += direction[di][1];
            }
            if (di % 2) ++step;
            di = (di + 1) % 4;
        }
        return res;
    }
};
```

## 941. Valid Mountain Array (2020-12-10)

解题思路

1. 维护一个标志变量表示当前是递增还是递减。如果是递增情况碰到后数大于前数时候，将标志变量设为递减；如果是符合递增（后数大于前数）和递减（后数小于前数）的情况，就继续循环；其他情况都返回错误。

边界条件

1. 递减数列
2. 数组长度小于3

```C++
// 2020-12-10 submission
// Runtime: 52 ms, faster than 71.27% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 22.8 MB, less than 41.97% of C++ online submissions for Valid Mountain Array.
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] >= arr[1]) return false;
        bool up=true;
        for (int i = 1; i < arr.size(); i++) {
            // if (up && arr[i] > arr[i-1]) continue;
            // else if (up && arr[i] < arr[i-1]) up = false;
            // else if (up && arr[i] == arr[i-1]) return false;
            // else if (!up && arr[i] >= arr[i-1]) return false;
            // else if (!up && arr[i] < arr[i-1]) continue;
            // else return false;
            if (up && arr[i] < arr[i-1]) up = false;
            else if (up && arr[i] > arr[i-1] || !up && arr[i] < arr[i-1]) continue;
            else return false;
        }
        return !up;
    }
};
```

## 402. Remove K Digits (2020-12-11)

解题思路

1. 滑动窗口：维护一个滑窗，初始大小为 k。之后右边界每次往右移动1位，在滑窗中寻找最小数并把左边界定位到最小数的下标（如果同时出现多个最小数则取最左边）。可以用双向队列减少重复运算。

```C++
// 2020-12-11 submission
// Runtime: 16 ms, faster than 29.62% of C++ online submissions for Remove K Digits.
// Memory Usage: 7.1 MB, less than 69.56% of C++ online submissions for Remove K Digits.
class Solution {
public:
    string removeKdigits(string num, int k) {
        int s = 0, e = k;
        string res;
        for (; e < num.length(); s++, e++) {
            s = find_d(num, s, e);
            if (!res.empty() || num[s] != '0')
                res.append(1, num[s]);
        }
        return res.empty() ? "0" : res;
    }

    int find_d(string& num, int s, int e) {
        int min_idx = s;
        for (int i = s + 1; i <= e; i++) {
            if (num[min_idx] > num[i]) min_idx = i;
        }
        return min_idx;
    }
};
```

```C++
// 2020-12-11 submission
// Runtime: 4 ms, faster than 87.95% of C++ online submissions for Remove K Digits.
// Memory Usage: 7.6 MB, less than 27.25% of C++ online submissions for Remove K Digits.
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> q;
        string res;
        for (int i = 0; i < num.length(); i++) {
            while (!q.empty() && num[q.back()] > num[i]) q.pop_back();
            q.push_back(i);
            if (i >= k) {
                if (!res.empty() || num[q.front()] != '0')
                    res.append(1, num[q.front()]);
                q.pop_front();
            }
        }
        return res.empty() ? "0" : res;
    }
};
```

## 312. Burst Balloons (2020-12-14)

解题思路

1. 动态规划：定义 $dp[i, j]$ 为将从第 \(i\) 到 \(j\) 个气球全部扎破后得到的最多硬币数，状态转移方程为

   $$
   dp[i, j] = \max_{i \leq k \leq j}(dp[i, k-1] + dp[k+1, j]+nums[i-1]*nums[k]*nums[j+1])
   $$

   其中 \(k\) 表示在区间 $[i, j]$ 中选择气球 \(k\)，先把除了 \(k\) 以外的气球都打破后，最后再打气球 \(k\)。\(k\) 有可能会等于 \(i\) 或者 \(j\)，这种情况下 $dp[i, k-1]$ 和 $dp[k+1, j]$ 无意义，定义为0。
   为了减少运算，在初始数组首尾各插入 1，动态数组也要对应发生变化。

Follow Up

1. 启发式搜索

```C++
// 2020-12-14 submission (动态规划)
// Runtime: 36 ms, faster than 61.75% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.2 MB, less than 26.39% of C++ online submissions for Burst Balloons.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> src{1};
        src.insert(src.end(), nums.begin(), nums.end());
        src.push_back(1);

        int n = nums.size();
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for (int j = 1; j <= n; j++) {
            for (int i = j; i >= 1; i--) {
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + src[i-1]*src[k]*src[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};
```

```C++
// 2020-12-14 submission (启发式搜索)
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Burst Balloons.
// Memory Usage: 8.6 MB, less than 87.47% of C++ online submissions for Burst Balloons.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int base = applyHeuristic(nums);
        return base + applyDP(nums);
    }

    int applyHeuristic(vector<int>& nums) {
        const int n = nums.size() - 2;
        const int maximum = *std::max_element(nums.begin(), nums.end());
        int result = 0;
        int i = 1;
        int j = 2;
        while (j <= n + 1) {
            int a = nums[i - 1];
            int b = nums[i];
            int c = nums[j];
            if (b <= a && b <= c && (a * c * (b + maximum)) >= (b * maximum * (a + c))) {
                result += a * b * c;
                if (i > 1) {
                    --i;
                } else {
                    nums[i] = nums[j];
                    ++j;
                }
            } else {
                ++i;
                nums[i] = nums[j];
                ++j;
            }
        }
        nums.resize(i + 1);
        return result;
    }

    int applyDP(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> dr(n, 0);
        vector<vector<int>> dp(n, dr);
        for (int k = 2; k < n; ++k){
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

## 500. Keyboard Row (2020-12-15)

```C++
// 2020-12-15 submission
// Runtime: 8 ms, faster than 30.88% of C++ online submissions for Keyboard Row.
// Memory Usage: 7.3 MB, less than 37.56% of C++ online submissions for Keyboard Row.
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string up = "qwertyuiop", mid = "ASDFGHJKLasdfghjkl", bottom = "ZXCVBNMzxcvbnm";
        unordered_map<char, int> m;
        for (char c = 'a'; c <= 'z'; c++) {
            if (up.find(c) != string::npos || up.find(c + ('A'-'a')) != string::npos)
                m[c] = m[c + ('A'-'a')] = 0;
            else if (mid.find(c) != string::npos || mid.find(c + ('A'-'a')) != string::npos)
                m[c] = m[c + ('A'-'a')] = 1;
            else if (bottom.find(c) != string::npos || bottom.find(c + ('A'-'a')) != string::npos)
                m[c] = m[c + ('A'-'a')] = 2;
        }

        vector<string> res;
        int i = 0;
        for (string word : words) {
            for (i = 1; i < word.length(); i++) {
                cout << word[i] << " " << m[word[i]] << " " << m[word[0]] << endl;
                if (m[word[i]] != m[word[0]]) break;
            }
            if (i == word.length()) res.push_back(word);
        }
        return res;
    }
};
```

## 977. Squares of a Sorted Array (2020-12-16)

解题思路

1. 先找到离 0 最近的数的下标，然后从中间向两边扩散，把小数放入数组开头。
2. 从两边向中间遍历，把大数放入数组末尾。

```C++
// 2020-12-16 submission
// Runtime: 36 ms, faster than 99.83% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 27.1 MB, less than 30.05% of C++ online submissions for Squares of a Sorted Array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.empty()) return vector<int>{};

        int pivot = find_closest(nums, 0);
        vector<int> res{nums[pivot] * nums[pivot]};
        int l = pivot - 1, r = pivot + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (r >= nums.size() || l >= 0 && (nums[l]+nums[r] >= 0)) {
                res.push_back(nums[l] * nums[l]);
                l--;
            }
            else {
                res.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        return res;
    }

    int find_closest(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target && target <= nums[mid+1]) {
                l = r = (abs(target-nums[mid]) <= abs(target-nums[mid+1]) ? mid : mid + 1);
            }
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```

```C++
// 2020-12-16 submission
// Runtime: 52 ms, faster than 79.21% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 26.1 MB, less than 85.41% of C++ online submissions for Squares of a Sorted Array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int l = 0, r = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[l] + nums[r] >= 0) {
                res[i] = nums[r] * nums[r];
                --r;
            }
            else {
                res[i] = nums[l] * nums[l];
                ++l;
            }
        }
        return res;
    }
};
```

## 815. Bus Routes

```C++
// 2021-03-08 submission
// Runtime: 184 ms, faster than 74.13% of C++ online submissions for Bus Routes.
// Memory Usage: 63.2 MB, less than 28.95% of C++ online submissions for Bus Routes.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int> > stop;
        for (int i = 0; i < routes.size(); i++) {
            for (int a : routes[i])
                stop[a].push_back(i);
        }

        queue<int> q;
        q.push(source);
        unordered_set<int> visited_s{source};
        unordered_set<int> visited_r{};
        int cur = 0, res = 1;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                cur = q.front(); q.pop();
                for (int way : stop[cur]) {
                    if (!visited_r.insert(way).second) continue;
                    for (int point : routes[way]) {
                        if (point == target) return res;
                        if (visited_s.insert(point).second) q.push(point);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
```

## 1411. Number of Ways to Paint N × 3 Grid

解题思路

1. 可分为两种情况：两边为同一数字(边)和两边不同数字(中)，则 1中=2边+2中，1边=3边+2中

```C++
// 2021-03-08 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
// Memory Usage: 6 MB, less than 74.43% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
class Solution {
public:
    int numOfWays(int n) {
        long long  A = 6, B = 6;
        for (int i = 1 ; i < n; i++) {
            long long new_A = (A * 3) % 1000000007 + (B * 2)  % 1000000007;
            long long new_B = (A * 2) % 1000000007 + (B * 2)  % 1000000007;
            A = new_A % 1000000007;
            B = new_B % 1000000007;
        }
        return (A + B) % 1000000007;

    }
};
```
