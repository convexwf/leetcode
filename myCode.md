## 28. Implement strStr()

实现 `strStr()` 函数，返回字符串 needle 在字符串 haystack 中的第一次出现位置。

1. 遍历母字符串，这里并不需要遍历整个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。然后对于每一个字符，都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可

**边界条件**

1. 注意 haystack 或者 needle 长度为 0 的情况
2. 注意 haystack 长度比 needle 小的情况

TODO

1. KMP

```cpp
// 2020-06-28 submission
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
```

## 29. Divide Two Integers

求两数相除，规定不能用乘法，除法和取余操作。

1. 位操作
   - 不准使用乘除幂运算的情况下，都要使用位操作。
   - 如果被除数大于或等于除数，则进行如下循环，定义变量 t 等于除数，定义计数 p，当 t 的两倍小于等于被除数时，进行如下循环， t 扩大一倍，p 扩大一倍，然后更新 res 和 m。
   - 去除符号后再做运算，结果再加上符号
   - 运算过程中可能会发生溢出，要用 long 表示
2. 上述方法的递归形式

**边界条件**

1. 被除数是 INT_MAX，除数是 INT_MIN
2. 被除数是 INT_MIN，除数是 -1
3. 被除数是 0

```cpp
// 2020-07-04 submission
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend), n = labs(divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};
```

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        long m = labs(dividend), n = labs(divisor), res = 0;
        if (m < n) return 0;
        long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p + divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};
```

## 30. Substring with Concatenation of All Words

给定一个长字符串，再给定几个长度相同的单词，让找出串联给定所有单词的子串的起始位置。

1. HashMap
   - 先用 check_freq 存储单词表的频率，然后词遍历字符串。
   - 词遍历是先遍历0,4,8,12,...，再遍历1,5,9,13,...，再遍历2,6,10,14...。词遍历过程中要维护一个哈希表 word_freq 表示当前匹配的单词数量，还有维护一个左边界表示当前匹配的最左位置。
   - 当当前位置减去左边界等于总长度而且维护的哈希表满足时，说明左边界为所需要的结果之一。
   - s.substr(pos,n)：若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值。
   - O(n) 时间复杂度。
2. 遍历 s 中所有长度为 n\*len 的子串，当剩余子串的长度小于 n\*len 时，就不用再判断了。对于每个遍历到的长度为 n\*len 的子串，需要验证其是否刚好由 words 中所有的单词构成，检查方法就是每次取长度为 len 的子串，看其是否是 words 中的单词。为了方便比较，建立另一个 HashMap，当取出的单词不在 words 中，直接 break 掉，否则就将其在新的 HashMap 中的映射值加 1，还要检测若其映射值超过原 HashMap 中的映射值，也 break 掉，因为就算当前单词在 words 中，但若其出现的次数超过 words 中的次数，还是不合题意的。在 for 循环外面，若 j 正好等于n ，说明检测的 n 个长度为 len 的子串都是 words 中的单词，并且刚好构成了 words，则将当前位置 i 加入结果 res 即可。

**边界条件**

1. 待选单词可能会重复（两个以上同样的词），建议先用一个hashmap存储单词表的频率
2. 单词表为空
3. 待选单词长度为 0
4. 查找字符串长度为 0

```cpp
// 2020-07-06 submission
```cpp code
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.length() == 0 || words.empty()) return {};
        if(words[0].size() == 0) {
            for(int i = 0; i <= s.size(); i++) {
                ret_vec.push_back(i);
            }
            return ret_vec;
        }
        int count = words.size(); // Count of words
        int len = words[0].size(); // Length of word
        unordered_map<string, int> word_freq;
        for (string word : words) {
            word_freq[word]++;
        }

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> check_freq;
            int left_pivot = i;
            for (int pivot = i; pivot < s.size(); pivot += len) {
                string to_compare = s.substr(pivot, len);
                if(word_freq.count(to_compare)) {
                    check_freq[to_compare]++;
                    while (check_freq[to_compare] > word_freq[to_compare]) {
                        word_freq[s.substr(left_pivot, len)]--;
                        left_pivot += len;
                    }
                    if (pivot + len - left_pivot == count * len) {
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

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for (auto &word : words) ++wordCnt[word];
        for (int i = 0; i <= (int)s.size() - n * len; ++i) {
            unordered_map<string, int> strCnt;
            int j = 0;
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
```

## 109. Convert Sorted List to Binary Search Tree

有序链表转为二叉搜索树。

1. 递归，通过双指针法找到链表中心，然后一切为二，分别建立左子树和右子树。
2. 递归：在一个函数内完成。

```cpp
// 2020-09-14 submission

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

```cpp
class Solution {
public:
    TreeNode *sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *last = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;
        TreeNode *cur = new TreeNode(slow->val);
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};
```

## 110. Balanced Binary Tree

判断平衡二叉树，平衡二叉树是每一个结点的两个子树的深度差不能超过 1。

1. 递归获得左右子树的深度，如果子树是平衡的，则返回真实的深度，若不平衡，直接返回 -1，此方法时间复杂度 O(N)，空间复杂度 O(H)。

```cpp
// 2018-07-22 submission
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
    bool isBalanced(TreeNode *root) {
        return checkDepth(root) != -1
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
};
```

## 115. Distinct Subsequences

给定字符串 S 和 T，从 S 中选择子序列使得刚好和 T 相等，有多少种选法。

1. 动态规划：`dp[i][j]` 表示 s 中范围是 [0, i] 的子串中能组成 t 中范围是 [0, j] 的子串的子序列的个数。状态转移方程为 `dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0)`。
2. 动态规划：简化用一维数组

```txt
  Ø r a b b b i t
Ø 1 1 1 1 1 1 1 1
r 0 1 1 1 1 1 1 1
a 0 0 1 1 1 1 1 1
b 0 0 0 1 2 3 3 3
b 0 0 0 0 1 3 3 3
i 0 0 0 0 0 0 3 3
t 0 0 0 0 0 0 0 3
```

**边界条件**

1. 空串是任意字符串（包括空串）的子串，在本题中空串仅计算1次。
2. 非空串不是空串的子串。
3. 数据类型不能使用 int，因为在运算过程中有可能会出现比最终结果大的数字（比如说rab能够比rabbit匹配更多次）而导致溢出。

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long>> dp(n + 1, vector<long>(m + 1));
        for (int j = 0; j <= m; ++j) dp[0][j] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[n][m];
    }
};
```

```cpp
// 2020-09-15 submission
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

## 147. Insertion Sort List

链表插入排序。

1. 从原链表中逐个取出，然后按顺序插入到新链表中，时间复杂度为 O(n^2)，空间复杂度为 O(1)。

```cpp
// 2020-11-03 submission
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

## 148. Sort List

链表排序，要求 O(nlogn) 时间复杂度。

1. 归并排序：通过快慢指针将链表从中间断开，分成两部分，左右两边再分别调用排序的递归函数 sortList()，得到各自有序的链表后，再进行 merge()。

```cpp
class Solution {
public:

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }

    // merge 递归实现
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    // merge 迭代实现
    ListNode* merge_iterate(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};
```

## 88. Merge Sorted Array

合并两个有序数组。

1. 从后往前插入混合数组
   - 需要三个变量，分别指向 nums1，nums2，和混合数组的末尾。
   - 循环结束后，有可能 i 或者 j 还大于等于 0，若 j 大于 0，那么还需要继续循环，将 nums2 中的数字继续拷入 nums1。
   - 若是 i 大于等于 0，那么就不用管，因为混合数组本身就放在 nums1 中。
2. 将两个 while 循环融合到一起，只要加上 `i >= 0` 且 `nums1[i] > nums2[j]` 的判断条件，就可以从 nums1 中取数，否则就一直从 nums2 中取数。

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
```

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};
```

## 89. Gray Code

格雷码是一种循环二进制单位距离码，主要特点是两个相邻数的代码只有一位二进制数不同的编码。给定正整数 n，返回由 n 个 bit 组成的格雷码系统。

```txt
Int    Gray Code    Binary
 0  　　  000        000
 1  　　  001        001
 2   　 　011        010
 3   　 　010        011
 4   　 　110        100
 5   　 　111        101
 6   　 　101        110
 7   　　 100        111
```

1. 格雷码和二进制相互转换
   - 二进制转格雷码：二进制数右移一位和原来的数按位取异或。
   - 格雷码转二进制：需要使用一个循环来转换，首先最高位不变B[i]=G[i],次高位=二进制的高位与格雷码次高位高位取异或即B[i-1]=B[i]^G[i-1],直到i<0.
2. 镜面排列: n 位元的格雷码可以从 n-1 位元的格雷码以上下镜射后加上新位元的方式快速得到。

   ```txt
   n = 1    n = 2       n = 3
   0        00          000
   1        01          001
            11          011
            10          010
                        100
                        101
                        111
                        110
   ```

3. 直接排列：以二进制为 0 值的格雷码为第零项，第一项改变最右边的位元，第二项改变右起第一个为1的位元的左边位元，第三、四项方法同第一、二项，如此反复，即可排列出n个位元的格雷码。

   ```txt
   0 0 0
   0 0 1
   0 1 1
   0 1 0
   1 1 0
   1 1 1
   1 0 1
   1 0 0
   ```

4. HashSet：从 0 开始，遍历其二进制每一位，对其取反，然后看其是否在 HashSet 中出现过，如果没有，我们将其加入 HashSet 和结果 res 中，然后再对这个数的每一位进行遍历，以此类推就可以找出所有的格雷码了。

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};
```

```cpp
// Direct arrangement
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        int len = pow(2, n);
        for (int i = 1; i < len; ++i) {
            int pre = res.back();
            if (i % 2 == 1) {
                pre = (pre & (len - 2)) | ((~pre) & 1);
            } else {
                int cnt = 1, t = pre;
                while ((t & 1) != 1) {
                    ++cnt;
                    t >>= 1;
                }
                if ((pre & (1 << cnt)) == 0) pre |= (1 << cnt);
                else pre &= ~(1 << cnt);
            }
            res.push_back(pre);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        unordered_set<int> s;
        stack<int> st;
        st.push(0);
        s.insert(0);
        while (!st.empty()) {
            int t = st.top(); st.pop();
            for (int i = 0; i < n; ++i) {
                int k = t;
                if ((k & (1 << i)) == 0) k |= (1 << i);
                else k &= ~(1 << i);
                if (s.count(k)) continue;
                s.insert(k);
                st.push(k);
                res.push_back(k);
                break;
            }
        }
        return res;
    }

    // 递归形式
    // vector<int> grayCode(int n) {
    //     vector<int> res;
    //     unordered_set<int> s;
    //     helper(n, s, 0, res);
    //     return res;
    // }
    // void helper(int n, unordered_set<int>& s, int out, vector<int>& res) {
    //     if (!s.count(out)) {
    //         s.insert(out);
    //         res.push_back(out);
    //     }
    //     for (int i = 0; i < n; ++i) {
    //         int t = out;
    //         if ((t & (1 << i)) == 0) t |= (1 << i);
    //         else t &= ~(1 << i);
    //         if (s.count(t)) continue;
    //         helper(n, s, t, res);
    //         break;
    //     }
    // }
};
```

## 127. Word Ladder

给定一个单词字典，给定一个起始单词和一个结束单词，每次变换只能改变一个字母，并且中间过程的单词都必须是单词字典中的单词，求出最短的变化序列的长度。

1. BFS
   - 使用 HashSet 保存所有的单词。
   - 把起始单词排入队列中，开始队列循环：取出队首词，然后对其每个位置上的字符，用 26 个字母进行替换，如果此时和结尾单词相同，返回当前遍历层数。如果替换词在字典中存在，将替换词排入队列中，并移除字典中的替换词；。如果循环完成则返回 0。

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
```

## 126. Word Ladder II

给定一个单词字典，给定一个起始单词和一个结束单词，每次变换只能改变一个字母，并且中间过程的单词都必须是单词字典中的单词，求出最短的变化序列。

1. BFS
   - 建立一个路径集 paths 用以保存所有路径，和起始路径 p，在p中先把起始单词放进去。
   - 定义两个整型变量 level，和 minLevel，其中 level 是记录循环中当前路径的长度，minLevel 是记录最短路径的长度，如果某条路径的长度超过了已有的最短路径的长度，那么舍弃，这样会提高运行速度，相当于一种剪枝。
   - 定义一个 HashSet 变量 words 用来记录已经循环过的路径中的词，
   - 循环路径集 paths 里的内容，取出队首路径，如果该路径长度大于 level，说明字典中的有些词已经存入路径了，如果在路径中重复出现，则肯定不是最短路径，所以需要在字典中将这些词删去，然后将 words 清空，对循环对剪枝处理。然后取出当前路径的最后一个词，对每个字母进行替换并在字典中查找是否存在替换后的新词，如果替换后的新词在字典中存在，将其加入 words 中，并在原有路径的基础上加上这个新词生成一条新路径，如果这个新词就是结束词，则此新路径为一条完整的路径，加入结果中，并更新 minLevel，若不是结束词，则将新路径加入路径集中继续循环。

```cpp
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};
```

## 162. Find Peak Element

寻找峰值(局部最大值)，峰值就是比周围两个数字都大的数字，如果有多个局部最大值随机返回其中一个即可，要求 O(logn) 复杂度。

1. 二分搜索：折半后选择中间那个元素和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。

```cpp
// 2020-11-11 submission
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

## 165. Compare Version Numbers

比较两个版本号。

1. 每次对应取出相同位置的小数点之前所有的字符，把他们转为数字比较，若不同则可直接得到答案，若相同，再对应往下取。如果一个数字已经没有小数点了，则默认取出为 0，和另一个比较。
2. 借助 stringstream 实现分段和转为整数。

**边界条件**

1. 无效 0，比如 01
2. 前导 0，比如 1.01 和 1.0001
3. 后导 0，比如 1.01.0.0.0

```cpp
// 2021-03-18 submission
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;

        while (p1 < version1.length() || p2 < version2.length()) {

            int x1 = 0, x2 = 0;
            while (p1 < version1.length() && version1[p1] != '.') {
                x1 = x1 * 10 + version1[p1] - '0';
                ++p1;
            }

            while (p2 < version2.length() && version2[p2] != '.') {
                x2 = x2 * 10 + version2[p2] - '0';
                ++p2;
            }

            if (x1 < x2) return -1;
            else if (x1 > x2) return 1;
            ++p1; ++p2;
        }
        return 0;
    }
};
```

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1 + "."), v2(version2 + ".");
        int d1 = 0, d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};
```

## 155. Min Stack

实现最小栈：同时能够返回最小值的栈。

1. 使用两个栈来实现，一个栈来按顺序存储 push 进来的数据，另一个用来存出现过的最小值。
2. 只使用一个栈：需要一个整型变量 min_val 来记录当前最小值，初始化为整型最大值
   - 如果需要进栈的数字小于等于当前最小值 min_val，则将 min_val 压入栈，并且将 min_val 更新为当前数字。
   - 在出栈操作时，先将栈顶元素移出栈，再判断该元素是否和 min_val 相等，相等的话将 min_val 更新为新栈顶元素，再将新栈顶元素移出栈即可

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        base.push(val);
        if (min_s.empty() || min_s.top() >= val) {
            min_s.push(val);
        }
    }

    void pop() {
        if (min_s.top() == base.top()) min_s.pop();
        base.pop();
    }

    int top() {
        return base.top();
    }

    int getMin() {
        return min_s.top();
    }

private:
    stack<int> base;
    stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

```cpp
class MinStack {
public:
    MinStack() {
        min_val = INT_MAX;
    }
    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }
    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return min_val;
    }

private:
    int min_val;
    stack<int> st;
};
```

## 151. Reverse Words in a String

翻转字符串中的单词，如果单词间有多个空格只返回一个，且转换后的字符串首尾不能有空格。

1. 可以认为单词是夹在边界或者空格中间，所以初始将 begin 设为-1（表示开始边界），之后每次遇到空格就更新 begin。同时遇到右边界或者有空格可以认为有单词结束，所以同时还需要加一个 word flag 指示是否当前遍历为单词。
2. 字符串流类 stringstream：先把字符串装载入字符串流中，然后定义一个临时变量tmp，然后把第一个单词赋给s
   - 如果含有非空格字符，那么每次 >> 操作就会提取连在一起的非空格字符，那么每次将其加在 s 前面即可；
   - 如果原字符串为空，那么就不会进入while循环；
   - 如果原字符串为许多空格字符连在一起，那么第一个 >> 操作就会提取出这些空格字符放入 s 中，然后不进入 while 循环，这时候我们只要判断一下 s 的首字符是否为空格字符，是的话就将 s 清空即可。
3. stringstream + getline：getline 第三个参数设定分隔字符为空格字符，每次只能过一个空格字符，如果有多个空格字符连在一起，那么 t 会赋值为空字符串，所以在处理 t 的时候首先要判断其是否为空，是的话直接跳过

**边界条件**

1. 字符串为空
2. 字符串（开始）末尾（没）有空格

```cpp
// 2020-09-19 submission
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

```cpp
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
    }
};
```

```cpp
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
    }
};
```

## 24. Swap Nodes in Pairs

交换链表的相邻节点。

1. 递归：递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换
2. 迭代：建立 dummy 节点

```cpp
// 2020-06-28 submission
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head->next;
        head->next = swapPairs(curr->next);
        curr->next = head;
        return curr;
    }
};
```

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};
```

## 25. Reverse Nodes in k-Group

k 个为一组来翻转链表

1. 迭代：首先遍历整个链表，统计出链表的长度，然后如果长度大于等于k，交换节点，当 k=2 时，每段只需要交换一次，当 k=3 时，每段需要交换2此，所以 i 从 1 开始循环，注意交换一段后更新 pre 指针，然后 num 自减 k，直到 $num < k$ 时循环结束。
2. 递归：用 head 记录每段的开始位置，cur 记录结束位置的下一个节点，然后调用 reverse 函数来将这段翻转，然后得到一个 new_head，原来的 head 就变成了末尾，这时候后面接上递归调用下一段得到的新节点，返回 new_head 即可。

```cpp
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;
        while (cur = cur->next) ++num;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
```

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};
```

## 150. Evaluate Reverse Polish Notation

逆波兰表达式(后缀表达式)求值，逆波兰表达式就是把操作数放前面，把操作符后置的一种写法。

1. 栈：从前往后遍历数组，遇到数字则压入栈中，遇到符号，则把栈顶的两个数字拿出来运算，把结果再压入栈中，直到遍历完整个数组，栈顶数字即为最终答案。
2. 递归：一个有效的逆波兰表达式的末尾必定是操作符，可以从末尾开始处理，如果遇到操作符，向前两个位置调用递归函数，找出前面两个数字，然后进行操作将结果返回，如果遇到的是数字直接返回即可

**边界条件**

1. 当运算对象为负数时候，注意不要和运算符号 `-` 混淆

```cpp
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

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op = (int)tokens.size() - 1;
        return helper(tokens, op);
    }
    int helper(vector<string>& tokens, int& op) {
        string str = tokens[op];
        if (str != "+" && str != "-" && str != "*" && str != "/") return stoi(str);
        int num1 = helper(tokens, --op);
        int num2 = helper(tokens, --op);
        if (str == "+") return num2 + num1;
        if (str == "-") return num2 - num1;
        if (str == "*") return num2 * num1;
        return num2 / num1;
    }
};
```

## 172. Factorial Trailing Zeroes

一个数的阶乘末尾 0 的个数。

1. 其实就是找乘数中 10 的个数，而 10 可分解为 2 和 5，而 2 的数量又远大于 5 的数量，问题转化为找出 5 的个数。需要注意的是，像 25，125 这样的不只含有一个 5 的数字需要考虑进去。
2. 递归写法

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
```

## 173. Binary Search Tree Iterator

实现二叉搜索树 iterator，调用 `next()` 可以返回当前 iterator 的下一个元素。要求 O(1) 时间复杂度，O(h) 空间复杂度。

1. 通过中序遍历将二叉树转化成排序好的数组。空间复杂度为 O(n)。
2. 栈 + 中序遍历

```cpp
// 2020-09-19 submission
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

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *n = s.top();
        s.pop();
        int res = n->val;
        if (n->right) {
            n = n->right;
            while (n) {
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
```

## 166. Fraction to Recurring Decimal

给定被除数和除数，结果用小数表示，将循环部分用括号包裹起来。

1. 组成部分：
   - 正负判断：被除数和除数取符号后相乘。
   - 整数部分：取绝对值后做除法即可。
   - 小数部分的循环部分：哈希表存每个小数位上的数字。每次把余数乘 10，再除以除数，得到的商即为小数的下一位数字。

**边界条件**

1. 对 INT_MIN 取绝对值就会超出范围

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }
};
```

## 199. Binary Tree Right Side View

打印出二叉树每一行最右边的一个数字。

1. 层序遍历: 遍历每层的节点时，把下一层的节点都存入到 queue 中，每当开始新一层节点的遍历之前，先把新一层最后一个节点值存到结果中
2. 前序遍历：利用变形前序访问来求得right view

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        helper(root, 1, ret);
        return ret;
    }

    void helper(TreeNode* node, int level, vector<int>& values){
        if(!node) return;
        if(values.size() < level) values.   push_back(node->val);
        helper(node->right, level+1, values);
        helper(node->left, level+1, values);
    }
};
```

## 209. Minimum Size Subarray Sum

求子数组之和大于等于给定值的最小长度

1. 滑动窗口：用两个指针分别子数组的左右的边界位置，然后让 right 向右移，直到子数组和大于等于给定值，此时将 left 向右移一位，然后在 sum 中减去移去的值，然后重复上面的步骤。O(n) 时间复杂度。
2. 二分搜索：建立一个比原数组长一位的 sums 数组，其中 sums[i] 表示 nums 数组中 [0, i - 1] 的和，然后对于 sums 中每一个值 sums[i]，用二分查找法找到子数组的右边界位置，使该子数组之和大于 sums[i] + s，然后更新最短长度的距离即可。O(nlgn) 时间复杂度。

**边界条件**

1. 数组不存在大于等于指定值的子序列

**Follow up**

1. 去掉所有数字是正数的限制条件

```cpp
// 2020-11-04 submission (滑动窗口)
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

```cpp
// 2020-11-04 submission (二分搜索)
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

## 211. Design Add and Search Words Data Structure

设计一种数据结构支持以下两种操作：`addWord(word)` 添加单词，`search(word)` 搜索单词，并支持通配符 `.`(匹配任意单个字符)。

1. 利用前缀树实现即可。

```cpp
// 2020-12-01 submission
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

## 143. Reorder List

重排链表，($L_{0} \rightarrow L_{n} \rightarrow L_{1} \rightarrow L_{n-1} \rightarrow L_{2} \rightarrow L_{n-2} \rightarrow \ldots$)

1. 问题分解为三个子问题
   - (1) 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。
   - (2) 将第二个链翻转。
   - (3) 将第二个链表的元素间隔地插入第一个链表中。
2. 可以借助栈的后进先出的特性反转链表，最后记得断开栈顶元素后面的结点。

```cpp
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid, *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
```

```cpp
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        stack<ListNode*> st;
        ListNode *cur = head;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }
        int cnt = ((int)st.size() - 1) / 2;
        cur = head;
        while (cnt-- > 0) {
            auto t = st.top(); st.pop();
            ListNode *next = cur->next;
            cur->next = t;
            t->next = next;
            cur = next;
        }
        st.top()->next = NULL;
    }
};
```

## 128. Longest Consecutive Sequence

最长连续序列长度，要求时间复杂度 O(n)。

1. HashSet：存入所有的数字，然后遍历数组中的每个数字
   - 如果其在集合中存在，那么将其移除，这是为了避免大量的重复计算。
   - 然后分别用两个变量 pre 和 next 算出其前一个数跟后一个数，然后在集合中循环查找
   - 结束查找后，next-pre-1 就是当前数字的最长连续序列，更新res即可
2. HashMap：存储值到连续序列长度的映射
   - 遍历所有数字，如果该数字不在 HashMap 中，那么我们分别看其左右两个数字是否在 HashMap 中。
   - 如果在，则返回其哈希表中映射值，若不在，则返回 0。
   - 然后将 left+right+1 作为当前数字的映射，并更新 res 结果，同时更新 num-left 和 num-right 的映射值。

```cpp
// 2020-09-16 submission
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
            max_len = max(max_len, next - pre - 1);
        }
        return max_len;
    }
};
```

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m.count(num)) continue;
            int left = m.count(num - 1) ? m[num - 1] : 0;
            int right = m.count(num + 1) ? m[num + 1] : 0;
            int sum = left + right + 1;
            m[num] = sum;
            res = max(res, sum);
            m[num - left] = sum;
            m[num + right] = sum;
        }
        return res;
    }
};
```

## 104. Maximum Depth of Binary Tree

二叉树的最大深度

1. DFS
2. BFS

```cpp
// 2018-07-21 submission
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
```

## 107. Binary Tree Level Order Traversal II

层序遍历(自底向上)

1. 递归：使用一个变量标记当前深度
2. 迭代

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        pushOrder(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
        // return vector<vector<int>> (res.rbegin(), res.rend());
    }

    void pushOrder(TreeNode*root, vector<vector<int>>& vec, int depth) {
        if(root == nullptr) return;
        if(vec.size() == depth) vec.push_back({});
        vec[depth].push_back(root->val);
        pushOrder(root->left, vec, depth+1);
        pushOrder(root->right, vec, depth+1);
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
```

## 303. Range Sum Query - Immutable

检索一个数组的某个区间的所有数字之和。数组元素不会发生变化。

1. 累计直方图：建立一个累计和的数组 dp，其中 dp[i] 表示 [0, i] 区间的数字之和，那么 [i,j] 就可以表示为 dp[j]-dp[i-1]。

```cpp
class NumArray {
public:
    NumArray(vector<int> &nums) {
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }

private:
    vector<int> dp;
};
```

## 304. Range Sum Query 2D - Immutable

检索一个二维数组的某个区域的所有数字之和。数组元素不会发生变化。

1. 累计区域和：`dp[i][j]` 表示累计区间 (0, 0) 到 (i, j) 这个矩形区间所有的数字之和，(r1, c1) 到 (r2, c2) 的矩形区间和为 `dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]`。

```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }

private:
    vector<vector<int> > dp;
};
```

## 400. Nth Digit

自然数序列看成一个长字符串，求第 N 位上的数字。

1. 定义个变量 cnt 初始化为9，每次循环扩大 10 倍，再用一个变量 len 记录当前循环区间数字的位数，另外再需要一个变量 start 用来记录当前循环区间的第一个数字。当 n 落到某一个确定的区间里了，`(n-1)/len` 就是目标数字在该区间里的坐标，加上 start 就是得到了目标数字，然后将目标数字 start 转为字符串，`(n-1)%len` 就是所要求的目标位。

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
```

## 315. Count of Smaller Numbers After Self

1. 二分搜索法：将给定数组从最后一个开始，用二分法插入到一个新的数组，该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数。时间复杂度 O(nlogn)，空间复杂度 O(n)。
2. 二分搜索树：加一个变量 smaller 来记录比当前结点值小的所有结点的个数，每插入一个结点，会判断其和根结点的大小，如果新的结点值小于根结点值，则其会插入到左子树中，此时要增加根结点的 smaller，并继续递归调用左子结点的 insert。如果结点值大于根结点值，则需要递归调用右子结点的 insert 并加上根结点的 smaller，并加 1。

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node*& root, int val) {
        if (!root) return (root = new Node(val, 0)), 0;
        if (root->val > val) return root->smaller++, insert(root->left, val);
        return insert(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};
```

## 454. 4Sum II

在四个数组中各取一个数字使总和为 0，一共有多少种取法。

1. HashMap: 把 A 和 B 的两两之和都求出来，在 HashMap 中建立两数之和跟其出现次数之间的映射，那么再遍历 C 和 D 中任意两个数之和，再看看哈希表存不存在这两数之和的相反数。时间复杂度为 O(n^2)。

```cpp
// 2020-12-18 submission
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;
        for (int a : A) {
            for (int b : B) {
                ++m[a + b];
            }
        }
        for (int c : C) {
            for (int d : D) {
                if (m.count(-c - d)) res += m[-c - d];
            }
        }
        return res;
    }
};
```

## 387. First Unique Character in a String

返回第一个非重复字符的下标

1. 用一个数组记录每个字母出现的次数。

```cpp
// 2020-11-29 submission
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s)
            count[c - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
```

## 442. Find All Duplicates in an Array

数组范围在 [1, n]，数组中的数字可能出现一次或两次，找出所有出现两次的数字。要求 O(1) 空间复杂度，O(n) 时间复杂度。

1. 取负法：将元素对应的位置取负。在取负的过程中，如果发现要取负的位置已经为负，说明这个元素已经出现过，也即该元素出现了两次。当某个元素不出现的时候，该元素对应的位置始终访问不到，所以还是正值。
2. 将 nums[i] 置换到其对应的位置 nums[nums[i]-1]。最后在对应位置检验，如果 nums[i] 和 i+1 不等，将 nums[i] 存入结果 res 中即可。

```cpp
// 2021-03-19 submission
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int dst = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            dst = nums[i] > 0 ? nums[i] : nums[i] + (n + 1);
            if (nums[dst-1] >= 0) nums[dst-1] -= (n + 1);
            else res.push_back(dst);
        }
        return res;
    }
    // 另一种写法
    // vector<int> findDuplicates(vector<int>& nums) {
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int idx = abs(nums[i]) - 1;
    //         if (nums[idx] < 0) res.push_back(idx + 1);
    //         nums[idx] = -nums[idx];
    //     }
    //     return res;
    // }
};
```

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }
};
```

## 357. Count Numbers with Unique Digits

找一个范围内的各位不相同的数字。

1. 找规律

   ```txt
   k = 1    [0-9] 10
   k = 2    [10-99] 中去掉 [11,22,33,44,55,66,77,88,99] 9 * 9 = 81
   k = 3    [100-999] 9 * 9 * 8 = 648
   ...
   通项公式为 f(k) = 9 * 9 * 8 * ... (9 - k + 2)
   例外情况：k > 10, f(k) = 0
   ```

2. 回溯
   - 需要一个变量 used，其二进制第 i 位为 1 表示数字 i 出现过
   - 刚开始遍历 1 到 9，对于每个遍历到的数字，现在 used 中标记已经出现过，然后再调用递归函数。在递归函数中，如果这个数字小于最大值，则结果 res 自增1，否则返回res。
   - 然后遍历0到9，如果当前数字没有在 used 中出现过，此时在 used 中标记，然后给当前数字乘以10加上i，再继续调用递归函数，这样可以遍历到所有的情况

```cpp
// 2020-11-13 submission
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        int cur = 1;
        for (int i = 1, j = 10; i <= n; i++, j--) {
            cur *= min(9, max(0, j));
            res += cur;
        }
        return res + 1;
    }
    // 另一种写法
    // int countNumbersWithUniqueDigits(int n) {
    //     if (n == 0) return 1;
    //     int res = 10, cnt = 9;
    //     for (int i = 2; i <= n; ++i) {
    //         cnt *= (11 - i);
    //         res += cnt;
    //     }
    //     return res;
    // }
};
```

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1, max = pow(10, n), used = 0;
        for (int i = 1; i < 10; ++i) {
            used |= (1 << i);
            res += search(i, max, used);
            used &= ~(1 << i);
        }
        return res;
    }
    int search(int pre, int max, int used) {
        int res = 0;
        if (pre < max) ++res;
        else return res;
        for (int i = 0; i < 10; ++i) {
            if (!(used & (1 << i))) {
                used |= (1 << i);
                int cur = 10 * pre + i;
                res += search(cur, max, used);
                used &= ~(1 << i);
            }
        }
        return res;
    }
};
```

## 344. Reverse String

反转字符串。

1. 按照题意处理即可。

```cpp
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

判断完全平方数。

1. 穷举：从 1 搜索到 sqrt(num)，看有没有平方正好等于 num 的数。
2. 二分查找
3. 完全平方数是一系列奇数之和。时间复杂度为 O(sqrt(n))。

   ```txt
   1 = 1
   4 = 1 + 3
   9 = 1 + 3 + 5
   16 = 1 + 3 + 5 + 7
   25 = 1 + 3 + 5 + 7 + 9
   36 = 1 + 3 + 5 + 7 + 9 + 11
   ....
   1 + 3 + ... + (2n-1) = (2n - 1 + 1)*n/2 = n * n
   ```

4. 牛顿迭代法
5. Q_rsqrt 算法：O(1) 时间复杂度。

```cpp
// 2020-09-22 submission
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

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
```

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
```

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};
```

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int root = floorSqrt(num);
        return root * root == num;
    }

    int32_t floorSqrt(int32_t x) {
        double y=x; int64_t i=0x5fe6eb50c7b537a9;
        y = *(double*)&(i = i-(*(int64_t*)&y)/2);
        y = y * (3 - x * y * y) * 0.5;
        y = y * (3 - x * y * y) * 0.5;
        i = x * y + 1; return i - (i * i > x);
    }
};
```

## 390. Elimination Game

一个 1-n 的有序数组，从左开始每隔一个数进行删除，然后从最右开始以同样方法进行删除，循环反复后只剩下一个数字，求出该数字。

1. 从左往右删的时候，每次都是删掉第一个数字，而从右往左删的时候，则有可能删掉第一个或者第二个数字（剩下数字是偶数个时，删掉的是第二个数字），而且每删一次，数字之间的距离会变为之前的两倍，所以只需要记录每次删减后数组的第一个数字即可。
2. 递归：第一次从左往右删除的时候，奇数都被删掉了，剩下的都是偶数。如果对所有数都除以 2，那么得到一个 1 到 n/2 的新数列。下一次从右往左删除，那么返回的结果应该是调用递归的结果 lastRemaining(n/2) 在数组 1 到 n/2 之间的镜像。何为镜像，比如 1, 2, 3, 4 这个数字，2 的镜像就是 3, 1 的镜像是 4。

```cpp
// 2020-12-06 submission
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

```cpp
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
```

## 404. Sum of Left Leaves

计算二叉树所有左叶子节点的和

1. 需要传递一个标志位，因为一个节点是否为左节点是由父节点决定的。
2. 直接在原函数中检查当前节点的左子节点是否是左子叶，如果是的话，则返回左子叶的值加上对当前结点的右子节点调用递归的结果；如果不是的话，对左右子节点分别调用递归函数，返回二者之和。

```cpp
// 2020-12-11 submission
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

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```

## 174. Dungeon Game

恶魔抓住了公主并将她关在了地下城的右下角，地下城是由 M x N 个房间组成的二维网格。英勇的骑士最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。为了尽快到达公主，骑士决定每次只向右或向下移动一步。计算确保骑士能够拯救到公主所需的最低初始健康点数。

1. 动态规划
   - `dp[i][j]` 表示当前位置 (i, j) 出发的起始血量(即不考虑当前房间产生的影响)
   - 最先处理公主所在的房间的起始生命值，然后慢慢向第一个房间扩散，不断的得到各个位置的最优的生命值。
   - 状态转移方程 `dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])`。
   - 为了更好的处理边界情况，二维 dp 数组比原数组的行数列数均多 1 个，先都初始化为整型数最大值 INT_MAX，到达公主房间后，骑士火拼完的血量至少为1，那么此时公主房间的右边和下边房间里的数字都设置为 1。
2. 动态规划：使用一维数组

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
```

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
```

## 464. Can I Win

给定两个整数 maxChoosableInteger(整数池中可选择的最大数) 和 desiredTotal(累计和)，两个玩家可以轮流从公共整数池中抽取整数(不放回)，先使得累计整数和达到或超过规定累计和的玩家即为胜者。求先手玩家是否必胜。

1. HashMap + 递归
   - 如果给定的数字范围大于等于目标值的话，直接返回 true。如果给定的数字总和小于目标值的话，说明谁也没法赢，返回 false。
   - 进入递归函数，首先查找当前情况是否在 HashMap 中存在，有的话直接返回即可。
   - 使用一个整型数按位来记录数组中的某个数字是否使用过，遍历所有数字，将该数字对应的 mask 算出来，如果其和 used 相与为 0 的话，说明该数字没有使用过
   - 如果此时的目标值小于等于当前数字，说明已经赢了，或者调用递归函数，如果返回 false，说明也是当前进入递归函数的玩家赢了。

```cpp
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};
```

## 228. Summary Ranges

总结有序数组的区间

1. 每次检查下一个数是不是递增的，如果是，则继续往下遍历，如果不是，还要判断此时是一个数还是一个序列，一个数直接存入结果，序列的话要存入首尾数字和箭头“->"。

**边界条件**

1. $b - a <= 1$ 应写成 $a - 1 >= b$，防止溢出

```cpp
// 2020-10-29 submission
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;
            while (i + j < n && nums[i + j] - j == nums[i]) ++j;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};
```

## 273. Integer to English Words

整型数转为用英文单词描述

1. 枚举
   - 每 3 个 1 组进行处理
   - 输入数字范围为 0 到 2^31 - 1 之间，最高只能到 billion 位
   - 一个三位数 n，百位数表示为 n / 100，后两位数一起表示为 n % 100，十位数表示为 n % 100 / 10，个位数表示为 n % 10
   - 单词数组：需要把 1 到 19 的英文单词都列出来，还要把 20,30，... 到 90 的英文单词列出来放到另一个数组里

**边界条件**

1. 0，返回 Zero

```cpp
class Solution {
public:
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = (num % 1000 > 0) ? (convertHundred(num % 1000) + " " + v[i] + " " + res) : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};
```

## 257. Binary Tree Paths

返回二叉树所有根到叶节点的路径

1. DFS：当遇到叶结点的时候，此时一条完整的路径已经形成了，加上当前的叶结点后存入结果 res 中。
2. DFS：在一个函数内完成。

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) helper(root, "", res);
        return res;
    }
    void helper(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) res.push_back(out + to_string(node->val));
        if (node->left) helper(node->left, out + to_string(node->val) + "->", res);
        if (node->right) helper(node->right, out + to_string(node->val) + "->", res);
    }
};
```

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> res;
        for (string str : binaryTreePaths(root->left)) {
            res.push_back(to_string(root->val) + "->" + str);
        }
        for (string str : binaryTreePaths(root->right)) {
            res.push_back(to_string(root->val) + "->" + str);
        }
        return res;
    }
};
```

## 224. Basic Calculator

算术表达式计算，表达式中只有加减号，数字，括号和空格，没有乘除。

1. 栈
   - 用变量 sign 来表示当前的符号
   - 遍历给定的字符串 s，如果遇到了数字，使用了一个变量来保存读入的 num；
   - 如果遇到了加号，则 sign 赋为1，如果遇到了符号，则赋为-1；
   - 如果遇到了左括号，则把当前结果 res 和符号 sign 压入栈，res 重置为 0，sign 重置为 1；
   - 如果遇到了右括号，结果 res 乘以栈顶的符号，栈顶元素出栈，结果 res 加上栈顶的数字，栈顶元素出栈。
2. 递归
   - 用一个变量 cnt，遇到左括号自增 1，遇到右括号自减 1，当 cnt 为0的时候，说明括号正好完全匹配
   - 根据左右括号的位置提取出中间的子字符串调用递归函数，返回值赋给 num

```cpp
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                num = 10 * num + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
```

```cpp
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            } else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (c == '+' || c == '-' || i == n - 1) {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
             }
        }
        return res;
    }
};
```

## 227. Basic Calculator II

算术表达式计算，表达式中有加减乘除号，数字和空格，没有括号。

1. 栈
   - 使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。
   - 如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果
2. num 表示当前的数字，curRes 表示当前的结果，res 为最终的结果，op 为操作符号，初始化为 '+'。根据 op 的值对 num 进行分别的加减乘除的处理，结果保存到 curRes 中。然后再次判断如果 op 是加或减，或者是最后一个位置的字符时，将 curRes 加到结果 res 中，并且 curRes 重置为 0。最后将当前字符 c 赋值给 op（注意这里只有当时最后一个位置的字符时，才有可能不是运算符号，不过也不要紧了，因为遍历已经结束了），num 也要重置为 0。

```cpp
class Solution {
public:
    int calculate(string s) {
        long res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int calculate(string s) {
        long res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+':
                        curRes += num;
                        break;
                    case '-':
                        curRes -= num;
                        break;
                    case '*':
                        curRes *= num;
                        break;
                    case '/':
                        curRes /= num;
                        break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
```

## 90. Subsets II

找出给定集合的所有子集，输入数组允许有重复项。

1. 非递归遍历: 按照子集的长度由少到多全部写出来。用 last 来记录上一个处理的数字，然后判定当前的数字和 last 是否相同，若不同，则循环还是从 0 到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复。
2. DFS：增加去重处理。

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        int size = 1, last = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (last != S[i]) {
                last = S[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

// 添加顺序为
// []
// [1]
// [2]
// [1 2]
// [2 2]
// [1 2 2]
```

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            getSubsets(S, i + 1, out, res);
            out.pop_back();
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
        }
    }
};

// 添加顺序为
// []
// [1]
// [1 2]
// [1 2 2]
// [2]
// [2 2]
```

## 86. Partition List

划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变。

1. 首先找到第一个大于或等于给定值的节点，然后将所有小于给定值的节点置于该节点之前即可。
2. 将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后。

```cpp
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// 链表变化顺序为：
// 1 -> 4 -> 3 -> 2 -> 5 -> 2
// 1 -> 2 -> 4 -> 3 -> 5 -> 2
// 1 -> 2 -> 2 -> 4 -> 3 -> 5
```

```cpp
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};
// 链表变化顺序为：
// Original: 1 -> 4 -> 3 -> 2 -> 5 -> 2
// New:

// Original: 4 -> 3 -> 2 -> 5 -> 2
// New:　  1

// Original: 4 -> 3 -> 5 -> 2
// New:　  1 -> 2

// Original: 4 -> 3 -> 5
// New:　  1 -> 2 -> 2

// Original:
// New:　  1 -> 2 -> 2 -> 4 -> 3 -> 5
```

## 95. Unique Binary Search Trees II

给定一个整数，表示为节点数目，给出所有二叉搜索树的组成。

1. 递归：选定一个pivot后，比pivot小的交给左子树，比pivot大的交给右子树，递归形式是最后回收所有可能的子树形式。
2. 递归+记忆数组：`memo[i][j]` 表示在区间 [i, j] 范围内可以生成的所有 BST 的根结点，这样在递归函数中，就可以去 memo 中查找当前的区间是否已经计算过。

```cpp
// 2020-07-08 submission
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }

    vector<TreeNode*> helper(int left, int right) {
        vector<TreeNode*> res, left_res, right_res;
        for (int pivot = left; pivot <= right; pivot++) {
            if (left == pivot) left_res = vector<TreeNode*>{nullptr};
            else left_res = helper(left, pivot - 1);
            if (right == pivot) right_res = vector<TreeNode*>{nullptr};
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
```

```cpp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) return {nullptr};
        if (!memo[start - 1][end - 1].empty()) return memo[start - 1][end - 1];
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1, memo), right = helper(i + 1, end, memo);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return memo[start - 1][end - 1] = res;
    }
};
```

## 96. Unique Binary Search Trees

给定一个整数，表示为节点数目，有几种二分搜索树的组合。

```txt
n = 0  空树  dp[0] = 0
n = 1  左子树个数乘以右子树的个数，左右子树都是空树  dp[1] = 1 * 1 = 1
n = 2  dp[2] = dp[0] * dp[1]　　(1 为根的情况，则左子树一定不存在，右子树可以有一个数字)
             + dp[1] * dp[0]　　(2 为根的情况，则左子树可以有一个数字，右子树一定不存在)
n = 3  dp[3] = dp[0] * dp[2]　　(1 为根的情况，则左子树一定不存在，右子树可以有两个数字)
             + dp[1] * dp[1]　　(2 为根的情况，则左右子树都可以各有一个数字)
             + dp[2] * dp[0]　　(3 为根的情况，则左子树可以有两个数字，右子树一定不存在)
......
dp[n] = dp[0] * dp[n-1] + dp[1] * dp[n-2] + + ... + dp[n-1] * dp[0]
```

[卡塔兰数 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0)

1. 卡特兰数的递推式：$C_0=1 \quad \text { and } \quad C_{n+1}=\sum_{i=0}^n C_i C_{n-i} \quad \text { for } n \geq 0$
2. 卡特兰数的通项公式： $\frac{C_{2n}^{n}}{n+1}$

**边界条件**

1. 相乘的时候为了防止整型数溢出，要将结果 res 定义为长整型。

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
```

```cpp
class Solution {
public:
    int numTrees(int n) {
        long res = 1;
        for (int i = n + 1; i <= 2 * n; ++i) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};
```

## 234. Palindrome Linked List

检测回文链表

1. 栈：利用栈的后入先出的特性，O(n) 时间复杂度，O(n) 空间复杂度。
2. 递归：在递归函数传入头节点。注意要在递归返回时才处理值比较，所以需要传入需要比较的指针作为引用。
3. 快慢指针+递归：首先通过快慢指针找到中间指针，然后通过递归比较值。
4. 快慢指针+迭代：找到中点后，将后半段的链表翻转。O(n) 时间复杂度，O(1) 空间复杂度。

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        stack<int> st;
        while (cur) {
            st.push(cur->val);
            cur = cur->next;
        }
        while (head) {
            int t = st.top(); st.pop();
            if (head->val != t) return false;
            head = head->next;
        }
        return true;
    }
};
```

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        return helper(head, cur);
    }
    bool helper(ListNode* node, ListNode*& cur) {
        if (!node) return true;
        bool res = helper(node->next, cur) && (cur->val == node->val);
        cur = cur->next;
        return res;
    }
};
```

```cpp
// 2020-12-05 submission
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) return helper(head, slow->next, slow);
        else return helper(head, slow, slow);
    }

    bool helper(ListNode* head, ListNode*& after, ListNode* stop) {
        if (head == stop) return true;
        bool res = helper(head->next, after, stop) && (head->val == after->val);
        after = after->next;
        return res;
    }
};
```

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
```

## 39. Combination Sum

给定正整数候选数集合 candidates 和目标和 target，找出 candidates 中所有可以使数字和为 target 的组合，candidates 中的数字可以无限制重复被选取。候选数集合中不会出现重复数字。

1. 递归：加入三个变量，start 记录当前的递归到的下标，out 为一个解，res 保存所有已经得到的解，每次调用新的递归函数时，此时的 target 要减去当前数组的的数。
2. 迭代：建立一个三维数组 dp，dp[i] 表示目标数为 i+1 的所有解法集合。

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() <= 0) return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }

    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp;
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++i) {
            vector<vector<int>> cur;
            for (int j = 0; j < candidates.size(); ++j) {
                if (candidates[j] > i) break;
                if (candidates[j] == i) {
                    cur.push_back({candidates[j]});
                    break;
                }
                for (auto a : dp[i - candidates[j] - 1]) {
                    if (candidates[j] > a[0]) continue;
                    a.insert(a.begin(), candidates[j]);
                    cur.push_back(a);
                }
            }
            dp.push_back(cur);
        }
        return dp[target - 1];
    }
};
```

## 40. Combination Sum II

给定一个正整数候选数集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。候选数集合中不会出现重复数字。

1. 递归

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(num.begin(), num.end());
        helper(num, target, 0, out, res);
        return res;
    }

    void helper(vector<int>& num, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return; }
        for (int i = start; i < num.size(); ++i) {
            out.push_back(num[i]);
            helper(num, target - num[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
```

## 216. Combination Sum III

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

1. 递归：n 是 k 个数字之和，如果 n 小于 0，则直接返回，如果 n 正好等于 0，而且此时 out 中数字的个数正好为 k，说明此时是一个正确解，将其存入结果 res 中。

```cpp
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> out;
        combinationSum3DFS(k, n, 1, out, res);
        return res;
    }
    void combinationSum3DFS(int k, int n, int level, vector<int> &out, vector<vector<int>> &res) {
        if (n < 0) return;
        if (n == 0 && out.size() == k) res.push_back(out);
        for (int i = level; i <= 9; ++i) {
            out.push_back(i);
            combinationSum3DFS(k, n - i, i + 1, out, res);
            out.pop_back();
        }
    }
};
```

## 215. Kth Largest Element in an Array

求数组中第 k 大的数字。

1. 小顶堆
2. 快速排序：先找一个中枢点 Pivot，然后遍历其他所有的数字，把大于中枢点的数字放到左半边，把小于中枢点的放在右半边，这样中枢点是整个数组中第几大的数字就确定了，虽然左右两部分各自不一定是完全有序的。如果位置正好是 k-1，那么直接返回该位置上的数字；如果大于 k-1，说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；反之则更新右半部分，求中枢点的位置。

```cpp
// 2021-03-18 submission
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() >= k) {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            else q.push(nums[i]);
        }
        return q.top();
    }
};
```

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
```

## 219. Contains Duplicate II

对于数组(array)，判断是否出现重复值，且重复值之间下标距离不大于 k

1. HashMap
   - 存储值到下标的映射。
   - 从左到右遍历数组，如果当前值的当前下标距离当前值的前下标不大于 k, 则认为出现重复。

```cpp
// 2019-09-17 submission
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
```

## 221. Maximal Square

在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

1. brute force
   - 把数组中每一个点都当成正方形的左顶点来向右下方扫描，来寻找最大正方形。
   - 确定了左顶点后，再往下扫的时候，正方形的竖边长度就确定了，只需要找到横边即可，这时候使用直方图的原理，从其累加值能反映出上面的值是否全为 1。
2. 累计和数组
   - 建立好了累加和数组后，我们开始遍历二维数组的每一个位置，对于任意一个位置 (i, j)，从该位置往 (0,0) 点遍历所有的正方形，正方形的个数为 `min(i, j) + 1`，由于累加和矩阵能快速的求出任意一个区域之和，所以能快速得到所有子正方形之和，比较正方形之和跟边长的平方是否相等，相等说明正方形中的数字均为1，更新 res 结果即可。
3. 动态规划：`dp[i][j]` 表示到达 (i, j) 位置所能组成的最大正方形的边长。
   - 当 i 或 j 为 0 时，最多能组成长度为 1 的正方形，条件是当前位置为1。
   - 对于任意一点 `dp[i][j]`，只有当前 (i, j) 位置为 1，`dp[i][j]` 才有可能大于 0。
   - 当 (i, j) 位置为 1，`dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1`
4. 动态规划：一维数组处理

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); ++j) {
                for (int k = 0; k < matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getSquareArea(v, j - i + 1));
            }
        }
        return res;
    }

    int getSquareArea(vector<int> &v, int k) {
        if (v.size() < k) return 0;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != k) count = 0;
            else ++count;
            if (count == k) return k * k;
        }
        return 0;
    }
};
```

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int t = matrix[i][j] - '0';
                if (i > 0) t += sum[i - 1][j];
                if (j > 0) t += sum[i][j - 1];
                if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
                sum[i][j] = t;
                int cnt = 1;
                for (int k = min(i, j); k >= 0; --k) {
                    int d = sum[i][j];
                    if (i - cnt >= 0) d -= sum[i - cnt][j];
                    if (j - cnt >= 0) d -= sum[i][j - cnt];
                    if (i - cnt >= 0 && j - cnt >= 0) d += sum[i - cnt][j - cnt];
                    if (d == cnt * cnt) res = max(res, d);
                    ++cnt;
                }
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
```

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0, pre = 0;
        vector<int> dp(m + 1, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i <= m; ++i) {
                int t = dp[i];
                if (matrix[i - 1][j] == '1') {
                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                    res = max(res, dp[i]);
                } else {
                    dp[i] = 0;
                }
                pre = t;
            }
        }
        return res * res;
    }
};
```

## 222. Count Complete Tree Nodes

完全二叉树节点的个数。

[二叉树 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%8F%89%E6%A0%91)

完全二叉树 (Complete Binary Tree)：对于一颗二叉树，假设其深度为 d(d>1)。除了第 d 层外，其它各层的节点数目均已达最大值，且第 d 层所有节点从左向右连续地紧密排列，这样的二叉树被称为完全二叉树。

完美二叉树 (Perfect Binary Tree)：

1. 完美二叉树的第 \(i\) 层拥有 $2^{i-1}$ 个节点数；深度为 \(k\) 的完美二叉树总共有 $2^{k+1}-1$ 个节点数。
2. 完美二叉树一定是完全二叉树，而完全二叉树不一定是完美二叉树。

完满二叉树 (Full Binary Tree)：所有非叶子结点的度都是2。

1. brute force: 递归统计结点的个数
2. 利用完美二叉树的性质：
   - 由 root 根结点往下，分别找最靠左边和最靠右边的路径长度
   - 如果长度相等，则证明二叉树最后一层节点是满的，是满二叉树，直接返回节点个数(2的h次方减1)
   - 如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)
3. 二分查找(疑似)
   - getHeight 函数用鱼统计当前结点的左子树的最大高度的，若当前结点不存在，返回 -1。
   - 对当前结点调用 getHeight 函数，得到左子树的最大高度 h，若为 -1，则说明当前结点不存在，直接返回 0。
   - 否则就对右子结点调用 getHeight 函数，若返回值为 h-1，说明左子树是一棵完美二叉树，则左子树的结点个数是 $2^h-1$ 个，再加上当前结点，总共是 $2^h$ 个，此时再加上对右子结点调用递归函数的返回值即可。
   - 若对右子结点调用 getHeight 函数的返回值不为 h-1，说明右子树一定是完美树，且高度为 h-1，则总结点个数为 $2^(h-1)-1$，加上当前结点为 $2^(h-1)$，然后再加上对左子结点调用递归函数的返回值即可。

```cpp
// 2020-11-04 submission (brute force)
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

```cpp
// 2020-11-04 submission (完美二叉树)
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

    // 全递归形式
    // int countNodes(TreeNode* root) {
    //     int hLeft = leftHeight(root);
    //     int hRight = rightHeight(root);
    //     if (hLeft == hRight) return pow(2, hLeft) - 1;
    //     return countNodes(root->left) + countNodes(root->right) + 1;
    // }
    // int leftHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + leftHeight(root->left);
    // }
    // int rightHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + rightHeight(root->right);
    // }
};
```

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0, h = getHeight(root);
        if (h < 0) return 0;
        if (getHeight(root->right) == h - 1) return (1 << h) + countNodes(root->right);
        return (1 << (h - 1)) + countNodes(root->left);
    }
    int getHeight(TreeNode* node) {
        return node ? (1 + getHeight(node->left)) : -1;
    }
    // 迭代形式
    // int countNodes(TreeNode* root) {
    //     int res = 0, h = getHeight(root);
    //     if (h < 0) return 0;
    //     while (root) {
    //         if (getHeight(root->right) == h - 1) {
    //             res += 1 << h;
    //             root = root->right;
    //         } else {
    //             res += 1 << (h - 1);
    //             root = root->left;
    //         }
    //         --h;
    //     }
    //     return res;
    // }
    // int getHeight(TreeNode* node) {
    //     return node ? (1 + getHeight(node->left)) : -1;
    // }
};
```

## 139. Word Break

给定单词和字典，判断单词能否被拆分成字典里面的内容。

1. 动态规划
   - 判断“abcd”是否合法，可以通过判断 "a"&&"bcd" || "ab"&&"cd" || "abc"&&"d" || "abcd" 实现。
   - 用两个 for 循环来要遍历所有的子串，用 j 把 [0, i) 范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是 dp[j]，范围 [j, i) 就是 s.substr(j, i-j)，其中 dp[j] 是之前的状态，只需要在字典中查找 s.substr(j, i-j) 是否存在，如果二者均为 true，将 dp[i] 赋为 true，并且跳出循环，此时就不需要再用j去分 [0, i) 范围了，因为 [0, i) 范围已经可以拆分。
2. 分治，方法同上。

```cpp
// 2020-07-18 submission
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

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet, 0, memo);
    }
    bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start + 1; i <= s.size(); ++i) {
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};
```

## 140. Word Break II

给定单词和字典，将单词拆分成字典里的单词，求出所有可以拆分的情况。

1. 递归+记忆数组：
   - 使用一个 HashMap 保存 s 和其所有的拆分的字符串
   - 递归函数中，首先检测当前 s 是否已经有映射结果，有的话直接返回即可
   - 如果 s 为空了，放一个空字符串返回，单词之间是有空格，而最后一个单词后面没有空格，所以这个空字符串旧标记当前单词是最后一个，所以不需要再加空格
   - 遍历 wordDict 数组，如果某个单词是 s 字符串中的开头单词的话，对后面部分调用递归函数，将结果保存到 rem 中，然后遍历里面的所有字符串，和当前的单词拼接起来。for循环结束后，记得返回结果 res 之前建立其和 s 之间的映射，方便下次使用。

```cpp
class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};
```

## 200. Number of Islands

矩阵中连续区域的个数.

1. DFS: 维护一个 visited 数组用来记录某个位置是否被访问过，对于一个为 ‘1’ 且未被访问过的位置，递归进入其上下左右位置上为 ‘1’ 的数，将其 visited 对应值赋为 true，继续进入其所有相连的邻位置，这样可以将这个连通区域所有的数找出来，并将其对应的 visited 中的值赋 true，找完相邻区域后，将结果 res 自增1，然后再继续找下一个为 ‘1’ 且未被访问过的位置。
2. BFS: 借助队列 queue 实现。

```cpp
// 2020-09-20 submission
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                DFS(grid, visited, i, j);
                ++res;
            }
        }
        return res;
    }
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
        visited[x][y] = true;
        DFS(grid, visited, x - 1, y);
        DFS(grid, visited, x + 1, y);
        DFS(grid, visited, x, y - 1);
        DFS(grid, visited, x, y + 1);
    }
};
```

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<int> dirX{-1, 0, 1, 0}, dirY{0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                ++res;
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = t / n + dirX[k], y = t % n + dirY[k];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]) continue;
                        visited[x][y] = true;
                        q.push(x * n + y);
                    }
                }
            }
        }
        return res;
    }
};
```

## 13. Roman to Integer

罗马数字转化成数字。

```txt
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000
```

基本规则：

1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：III = 3；
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：VIII = 8；XII = 12；
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：IV= 4；IX= 9；
4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
5、在一个数的上面画一条横线，表示这个数扩大1000倍。
6、基本数字Ⅰ、X、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
7、不能把基本数字 V、L、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
8、V 和 X 左边的小数字只能用 Ⅰ。
9、L 和C 左边的小数字只能用 X。
10、D 和 M 左边的小数字只能用 C。

1. HashMap：将罗马数字的字母转化为对应的整数值，因为输入的一定是罗马数字，那么只要考虑两种情况即可：
   - 如果当前数字是最后一个数字，或者之后的数字比它小的话，则加上当前数字。
   - 其他情况则减去这个数字。
2. 每次跟前面的数字比较，如果小于等于前面的数字，先加上当前的数字，如果大于前面的数字，加上当前的数字减去二倍前面的数字。

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            int val = m[s[i]];
            if (i == s.size() - 1 || m[s[i+1]] <= m[s[i]]) res += val;
            else res -= val;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || m[s[i]] <= m[s[i - 1]]) res += m[s[i]];
            else res += m[s[i]] - 2 * m[s[i - 1]];
        }
        return res;
    }
};
```

## 310. Minimum Height Trees

找到所有的最小高度树并返回他们的根节点。

1. 基于拓扑排序：遍历所有的叶子节点，然后把这些叶子节点关联的边从图中删去，更新所有节点的度数，重复以上步骤，最后就能得到中心的节点。
2. DFS：问题求解其实可以转化为求图的直径（即图中的最长路径）

```cpp
// 2020-11-05 submission
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > graph(n, vector<int>{});
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        int cnt = n;
        for (int node = 0; node < n; node++) {
            if (degree[node] <= 1) // < 是为了防止独立点(n=1)的情况
                q.push(node);
        }
        while(cnt > 2) {
            int q_size = q.size();
            cnt -= q_size;
            for (int i = 0; i < q_size; i++) {
                int node = q.front(); q.pop();
                for (int adj : graph[node]) {
                    degree[adj]--;
                    if (degree[adj] == 1) q.push(adj);
                }
            }
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
```

## 108. Convert Sorted Array to Binary Search Tree

有序数组转为二叉搜索树。

1. 二分查找：根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组。

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0 , (int)nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = helper(nums, left, mid - 1);
        cur->right = helper(nums, mid + 1, right);
        return cur;
    }
};
```

## 124. Binary Tree Maximum Path Sum

非空二叉树最大路径和，路径至少经过一个节点，路径不一定经过根节点和叶子节点。

1. 递归
   - 如果当前结点不存在，直接返回 0
   - 否则就分别对其左右子节点调用递归函数。由于（左右子节点）路径和有可能为负数，所以要和 0 相比较大值，即要么不加，加就要加正数。
   - 然后通过求和 左路径和 + 右路径和 + 当前节点值 来更新全局最大值结果 res

**Follow up**

1. 返回和最大的路径

```cpp
// 2020-09-09 submission
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
```

## 102. Binary Tree Level Order Traversal

层序遍历

1. 递归
2. 迭代: 队列

```cpp
// 2018-07-12 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 13.3 MB, less than 13.96% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        pushOrder(root, vec, 0);
        return vec;
    }

    void pushOrder(TreeNode*root, vector<vector<int>>& vec, int depth) {
        if(root == NULL) return;
        if (vec.size() == level) vec.push_back({});
        vec[depth].push_back(root->val);
        pushOrder(root->left, vec, depth+1);
        pushOrder(root->right, vec, depth+1);
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};
```

## 617. Merge Two Binary Trees

合并两个二叉树，规则是，都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替。

1. 递归
   - 如果 t1 不存在，则直接返回 t2
   - 如果 t2 不存在，则直接返回 t1
   - 如果上面两种情况都不满足，那么以 t1 和 t2 的结点值之和建立新结点 t，然后对 t1 和 t2 的左子结点调用递归并赋给 t 的左子结点，再对 t1 和 t2 的右子结点调用递归并赋给 t 的右子结点，返回 t 结点即可

```cpp
// 2021-03-10 submission
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode *t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left, t2->left);
        t->right = mergeTrees(t1->right, t2->right);
        return t;
    }
};
```

## 18. 4Sum

四数之和，给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

1. 排序+双指针：两层循环后进行双指针查找，注意去重处理，O(n^3) 时间复杂度。

TODO

1. 时间复杂度更低的做法，比如建立和到两个数的映射

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};
```
