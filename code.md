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

## 22. Generate Parentheses

给定一个数字 n，让生成共有 n 个括号的所有正确的形式。

1. 递归：

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
            res.push_back(cur + string(rp-lp, ')'));
            return;
        }
        helper(res, cur + "(", lp-1, rp);
        if (lp < rp) helper(res, cur + ")", lp, rp-1);
    }
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

## 149. Max Points on a Line

给了一堆二维点，求最大的共线点的个数。

判断三点共线的方法：A(ax,ay), B(bx,by), C(cx,cy)

1. 斜率解法：判断 `(ay-by)/(ax-bx) == (cy-by)/(cx-bx)`
   - 当 `ax == bx` 或 `cx == bx` 时需要特殊判断，注意使用 gcd 化简分子分母比较，不要使用浮点结果比较，可能会有误差
2. 周长判断解法：排序周长 `AC > AB > BC`，判断 `AC == AB + BC`
   - 由于 sqrt 开方运算会导致结果不准确，不稳定，在三角形接近扁平时，结果有误差。
3. 最优解法：面积判断，判断 `area(ABC) == 0`
   - `area(ABC) = 1/2 * ( AC X BC )  = 1/2 *((ax-cx)*(by-cy)-(bx-cx)*(ay-cy))`
   - 判断 `(ax-cx)*(by-cy) == (bx-cx)*(ay-cy)` 即可

4. 暴力解法 O(n^3)：

**边界条件**

1. 当两个点重合时，无法确定一条直线，但这也是共线的情况
2. 斜率不存在的情况，由于两个点 (x1, y1) 和 (x2, y2) 的斜率k表示为 (y2 - y1) / (x2 - x1)，那么当 x1 = x2 时斜率不存在。

```cpp
// 2020-07-19 submission
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
```

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {++duplicate; continue;}
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
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

## 103. Binary Tree Zigzag Level Order Traversal

二叉树的之字形层序遍历

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        pushOrder(root, vec, 0);
        for(int i = 1; i < vec.size(); i+=2) {
            reverse(vec[i].begin(), vec[i].end());
        }
        return vec;
    }

    void pushOrder(TreeNode*root, vector<vector<int>>& vec, int depth) {
        if(root == NULL) return;
        if(vec.size() - depth <= 0) vec.resize(depth+1);
        vec[depth].push_back(root->val);
        pushOrder(root->left, vec, depth+1);
        pushOrder(root->right, vec, depth+1);
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

## 111. Minimum Depth of Binary Tree

二叉树的最小深度。

```cpp

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

给定正整数候选数集合 candidates 和目标和 target，找出 candidates 中所有可以使数字和为 target 的组合，candidates 中的数字可以无限制重复被选取。

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

## 216. Combination Sum III

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

## 97. Interleaving String

给定字符串 s1，s2 和 s3，问 s3 是不是由 s1 和 s2 的交织字符串组成

1. 动态规划
   - 前提：字符串 s1 和 s2 的长度和必须等于 s3 的长度
   - 初始化：若 s1 和 s2 其中的一个为空串的话，那么另一个肯定和 s3 的长度相等，则按位比较
   - 在任意非边缘位置 `dp[i][j]` 时，它的左边或上边有可能为 True 或是 False，两边都可以更新过来，只要有一条路通着，那么这个点就可以为 True
   - 转移方程：`dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i])`;

**边界条件**

1. s1 或者 s2 为空

```cpp
// 2020-09-14 submission
// ?/? cases passed
// Runtime: 8 ms, faster than 47.16% of C++ online submissions.
// Memory Usage: 6.4 MB, less than 70.29% of C++ online submissions.
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

## 91. Decode Ways

编码的可能性，比如 "12" 可以解码为 "AB" 或 "L"。

1. 动态规划

## 10. Regular Expression Matching

正则匹配：`.` 匹配任意单个字符，`*` 匹配 0 个或多个前置字符。

1. 正则匹配
   - sp 和 pp 都到了末尾，表示匹配结束
   - 如果 p[pp+1] 为 *，

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

## 4. Median of Two Sorted Arrays

求两个有序数组的中位数，限制时间复杂度为 O(log (m+n))

1. 二分法+递归:
   - 假设两个有序数组的长度分别为 m 和 n，找第 $(m+n+1) / 2$ 个，和 $(m+n+2) / 2$ 个，然后求其平均值即可
   - 在两个有序数组中找到第 $K$ 个元素，分别在 nums1 和 nums2 中查找第 $K/2$ 个元素，由于两个数组的长度不定，所以有可能某个数组没有第 $K/2$ 个数字
   - 如果不存在第 K/2 个数字，赋值上一个整型最大值
   - 如果第一个数组的第 K/2 个数字小的话，那么说明要找的数字肯定不在 nums1 中的前 K/2 个数字，可以将其淘汰
   - 当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了
   - 如果 $K=1$ 的话，只要比较 nums1 和 nums2 的起始位置 i 和 j 上的数字即可
2. 二分法+迭代
   - 中位数其实就是把一个有序数组分为长度相等的两段，然后取前半段的最大值和后半段的最小值的平均数
   - 使用 L 表示分割点左边的数字，R 表示分割点右边的数字，则对于 [1 3 5 7] 来说，L=3，R=5。对于 [1 3 4 5 7] 来说，L=4，R=4
   - $idx(L)= (N-1)/2$，$idx(R) = N/2$，idx 表示 Index of，对应下标。中位数可以表示为 $(L + R) / 2 = (A[(N - 1) / 2] + A[N / 2]) / 2$
   - 为了统一数组长度为奇数和偶数的情况，在每个数字的两边都加上一个特殊字符 `#`

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};
```

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
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

## 85. Maximal Rectangle

解题思路

1. 参见 `##84` 思路，同样是要先确定高度和宽度再得到最大面积
2. 维护三个数组（左连续序列长度、右连续序列长度、高度）
   左连续序列长度：指从左边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
   右连续序列长度：指从右边开始计数到当前位置，连续的高于当前高度的序列长度（包括当前位置）
3. 进行行遍历
    + 若当前位置为“1”，要考虑上一侧行遍历序列长度是否大于 0。如果大于0说明正上面位置为“1”，则取连续的行“1”长度和上一次序列遍历长度的最小值，否则，直接认为序列长度为连续的行“1”长度。
    + 若当前位置为“0”，序列长度直接置0

边界条件

1. 矩阵为空

```cpp
// 2020-09-15 submission
// ?/? cases passed
// Runtime: 48 ms, faster than 93.31% of C++ online submissions.
// Memory Usage: 11.1 MB, less than 87.63% of C++ online submissions.
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

## 87. Scramble String

解题思路

1. s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。
2. 递归方法是将字符串按照不同长度进行切割，然后让子递归函数判断是否成立。
注意一个词和它自身是 scramble 的。
3. 为了减少复杂度，每次切割前可以采用排序或者统计字母频率等。

```cpp
// 2020-07-16 submission
// ?/? cases passed
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
```

## 57. Insert Interval

解题思路：从最左边遍历待插入区间，如果遍历区间右边界小于新区间左边界，将遍历区间加入结果，否则跳出循环。然后正式对交叉的区间进行处理，注意每次处理前都要判断是否重叠（因为有可能出现新区建在最左边和最右边的情况），然后取左边界最小值和右边界最大值作为新区间。不重叠时候跳出循环，将新区间加入结果，最后把剩下的待插入区间遍历完即可，所以有三个阶段。
边界条件：待插列表为空；新区间在最左边或者最右边；插入区间为空（标准程序没有注意到）

// 2020-07-14 submission
// ?/? cases passed
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

## 123. Best Time to Buy and Sell Stock III

股票交易，买进前必须卖出手头已有的，允许最多两次交易

1. 在数组中间画条线，在左边进行第一次交易，在右边进行第二次交易，来计算两次交易的最大收益和。这样，就将问题简化为只进行一次交易的问题了。维护两个数组，分别存储截止到第 $x$ 日交易的最大利润和第 $x$ 日之后交易的最大利润。

```cpp
// 2020-07-23 submission
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int days = prices.size();
        vector<int> front(days, 0), latter(days, 0);

        int min_price = prices[0], max_price = prices[days-1];
        for (int i = 1; i < days; i++) {
            min_price = min(min_price, prices[i]);
            front[i] = max(front[i-1], prices[i]-min_price);
            // cout << "front " << prices[i] << " " << front[i] << endl;
        }
        for (int i = days - 2; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            latter[i] = max(latter[i+1], max_price-prices[i]);
            // cout << "latter " << prices[i] << " " << latter[i] << endl;
        }

        int max_profit = 0;
        for (int pivot = 0; pivot < days; pivot++) {
            max_profit = max(max_profit, front[pivot]+latter[pivot]);
        }
        return max_profit;

    }
};
```

## 306. Additive Number

给定字符串能否拆成斐波那契数列

## 228. Summary Ranges

总结有序数组的区间

1. 每次检查下一个数是不是递增的，如果是，则继续往下遍历，如果不是，还要判断此时是一个数还是一个序列，一个数直接存入结果，序列的话要存入首尾数字和箭头“->"。

**边界条件**

1. $b - a <= 1$ 应写成 $a - 1 >= b$，防止溢出

```C++
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
2. DFS：在一个函数内完成

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

算数表达式计算，表达式中只有加减号，数字，括号和空格，没有乘除。

## 227. Basic Calculator II

## 146. LRU Cache

## 131. Palindrome Partitioning

拆分回文子字符串，求出所有的拆分组合。

## 132. Palindrome Partitioning II
