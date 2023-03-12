# 剑指offer

[CodeTop企业题库](https://codetop.cc/home)

## 创建链表

```cpp
ListNode* head = nullptr, *cur = nullptr, *pre = nullptr;
for (int x : vec) {
    cur = new ListNode(x);
    if (head == nullptr) head = cur;
    else pre->next = cur;
    pre = cur;
    cur = cur->next;
}
```

## 队列实现栈/栈实现队列

## atoi

## 链表排序

```C++
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
};
```

## 平衡二叉树

## 链表删除重复节点

```C++
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode* dummy = new ListNode(0);
        dummy->next = pHead;
        ListNode* p = dummy, *q=pHead;
        while(q && q->next) {
            if (q->val != q->next->val) {
                p = q;
                q = q->next;
            }
            else {
                int duplicate = q->val;
                while (q && q->val == duplicate) {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }
        }
        p = dummy->next;
        delete dummy;
        return p;
    }
};
```

## 最长回文子串

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "^#";
        for (char c : s) {
            str.append(1, c);
            str.append(1, '#');
        }
        str.append(1, '$');

        int n = str.length();
        vector<int> vec(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            if (i < R) vec[i] = min(vec[2*C-i], R-i);
            while (str[i+vec[i]+1] == str[i-vec[i]-1])
                ++vec[i];
            if (i + vec[i] > R) {
                C = i;
                R = i + vec[i];
            }
        };

        auto max_it = max_element(vec.begin(), vec.end());
        int idx = (max_it-vec.begin()-*max_it) / 2;
        int len = *max_it;
        string res = s.substr(idx, len);
        return res;
    }
};
```

## 二叉树序列化与反序列化

```C++
class Codec {
public:
    void encode(TreeNode *root, ostringstream& out) {
        if (!root) out << "# ";
        else {
            out << to_string(root->val) << " ";
            encode(root->left, out);
            encode(root->right, out);
        }
    }

    TreeNode *decode(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(in);
        node->right = decode(in);
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
};
```

## 重排链表

($L_{0} \rightarrow L_{n} \rightarrow L_{1} \rightarrow L_{n-1} \rightarrow L_{2} \rightarrow L_{n-2} \rightarrow \ldots$)

```C++
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode** left = &head;
        ListNode** right = left;
        while (*left != NULL && (*left)->next != NULL) {
            while (*right != NULL && (*right)->next != NULL) {
                right = &(*right)->next;
            }
            ListNode* tail = *right;
            *right = NULL;
            tail->next = (*left)->next;
            (*left)->next = tail;
            left = &(*left)->next->next;
            right = left;
        }
        return;
    }
};
```

## 回文链表

```C++
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
        bool flag = helper(head->next, after, stop);
        flag = flag && (head->val == after->val);
        after = after->next;
        return flag;
    }

};
```

## 重建二叉树

```C++
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return helper(pre, 0, pre.size()-1, vin, 0, vin.size() - 1);
    }

    TreeNode* helper(vector<int>& pre, int pre_l, int pre_r,
                    vector<int>& vin, int vin_l, int vin_r) {
        if (pre_r - pre_l < 0) return nullptr;
        TreeNode* root = new TreeNode(pre[pre_l]);
        for (int pivot = vin_l; pivot <= vin_r; ++pivot) {
            if (vin[pivot] == pre[pre_l]) {
                root->left = helper(pre, pre_l+1, pre_l+pivot-vin_l,
                                        vin, vin_l, pivot-1);
                root->right = helper(pre, pre_l+pivot-vin_l+1, pre_r,
                                        vin, pivot+1, vin_r);
                break;
            }
        }
        return root;
    }
};
```

## 洗牌算法 Knuth-Durstenfeld Shuffle

```C++
int randomInt(int l, int r) {
    return (rand() % (r - l)) + l;
}

void shuffle(vector<int>& vec) {
    for (int n = (int)vec.size(); n > 0; n--) {
        int randIdx = randomInt(0, n);
        swap(vec[randIdx], vec[n-1]);
    }
}
```

## 最大公约数

```C++
int gcd(int x, int y) {
    int r;
    while (y != 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
```

## 通配匹配

```C++
// 2020-09-14 submission
// Runtime: 176 ms, faster than 40.96% of C++ online submissions for Wildcard Matching.
// Memory Usage: 6.6 MB, less than 89.86% of C++ online submissions for Wildcard Matching.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
```

## 正则匹配

```C++
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

## 圆圈里剩下的那个数

```C++
class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n == 0 || m== 0) return -1;
        list<int> arr(n, 0);
        iota(arr.begin(), arr.end(), 0);
        int idx = 0;
        list<int>::iterator it = arr.begin();
        while (arr.size() > 1) {
            for (int i = 0; i < (m - 1) % int(arr.size()); i++) { // 不要取余后再做减法
                ++it;
                it = (it == arr.end() ? arr.begin() : it);
            }
            it = arr.erase(it);
            it = (it == arr.end() ? arr.begin() : it);
        }
        return arr.front();
    }
};
```

## 链表中倒数第k个结点

```C++
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        return helper(pHead, k);
    }

    ListNode* helper(ListNode* pHead, int& k) {
        if (!pHead) return nullptr;
        ListNode* node = helper(pHead->next, k);
        if (k == 0) return node;
        if (--k == 0) return pHead;
        return nullptr;
    }

    ListNode* FindKthToTail(ListNode* pHead, int k) {
        int len = 0;
        ListNode* head = pHead;
        while(head) {
            ++len;
            head = head->next;
        }
        if (k > len) return NULL;
        else {
            while(len != k) {
                pHead = pHead->next;
                --len;
            }
            return pHead;
        }
    }
```

## 构建乘积数组

```C++
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty()) return vector<int>{};
        vector<int> res(A.size(), 1);

        int cur = A[0];
        for (int i = 1; i < A.size(); i++) {
            res[i] *= cur;
            cur *= A[i];
        }

        cur = A.back();
        for (int i = (int)A.size()-2; i >= 0; i--) {
            res[i] *= cur;
            cur *= A[i];
        }
        return res;
    }
};
```

## 公共祖先

```C++ 二叉树
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* l_child = lowestCommonAncestor(root->left, p, q);
        TreeNode* r_child = lowestCommonAncestor(root->right, p, q);
        if (l_child && r_child) return root;
        else if (l_child) return l_child;
        else if (r_child) return r_child;
        else return nullptr;
    }
};
```

## 两个栈实现队列

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
}
```

```C++
class CQueue {
public:
    CQueue() {

    }

    void push_back(int value) {
        stk1.push(value);
    }

    int pop_front() {
        if (stk1.empty() && stk2.empty()) return -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int res = stk2.top();
        stk2.pop();
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
```

## 非递归中序遍历

```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>{};
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            TreeNode* right_most = cur->left;
            if (right_most) {
                while (right_most->right != nullptr && right_most->right != cur) {
                    right_most = right_most->right;
                }
                if (right_most->right == nullptr) {
                    right_most->right = cur;
                    cur = cur->left;
                    continue;
                }
                else right_most->right = nullptr;
            }
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
```

## 不使用加减乘除实现加法

```C++
class Solution {
public:
    int Add(int num1, int num2) {
        // 如何判断溢出
        if (num2 == 0) return num1;
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
        return Add(sum, carry);
    }
};
```

## 二叉搜索树的第k大节点

边界条件：k不合法；k数量大于节点数量

```C++
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if (k <= 0) perror("k 不合法");
        int res = helper(root, k);
        if (k > 0) perror("节点数量小于k");
        return res;
    }

    int helper(TreeNode* root, int& k) {
        if (!root) return -1;
        int val = helper(root->right, k);
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return helper(root->left, k);
    }
};
```

## 找出这两个只出现一次的数字 (其他数字都出现了两次)

```C++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (int num : nums)
            x ^= num;
        if (x == 0) perror("输入数据不符合条件");

        int i = 0;
        for (i = 0; i < 32; i++) {
            if ((x >> i) & 1) break;
        }

        int A = 0, B = 0;
        for (int num : nums) {
            if ((num >> i) & 1) A ^= num;
            else B ^= num;
        }
        return A < B ? vector<int>{A, B} : vector<int>{B, A};
    }
};
```

## 输出所有和为 target 的连续正整数序列（至少含有两个数）

```C++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int l = 1, r = 2, sum = 0;
        while (l < r) {
            sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                vector<int> tmp(r-l+1);
                iota(tmp.begin(), tmp.end(), l);
                res.push_back(tmp);
                ++l; ++r;
            }
            else if (sum < target) ++r;
            else if (sum > target) ++l;
        }
        return res;
    }
};
```

## 两个链表的交叉点

```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA, *curB = headB;
        while (curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};
```

## 数独解法

```C++

int32_t[9] flags;

void DFS(vector<vector<char> > matrix, int idx, int &validCnt) {

    if (idx == 81) validCnt++；

    int x = idx / 9;
    int y = idx % 9;
    if (matrix[i][j] != '.') {

        int row = x;
        int col = y;


        DFS(matrix, idx + 1);
    }
    else DFS(matrix, idx + 1);
}
```

## 反转链表

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *t = head->next;
            head->next = newHead;
            newHead = head;
            head = t;
        }
        return newHead;
    }
};
```

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
```

## 第 k 大的数字

```cpp

```

## 打印旋转数组

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> traj;
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (traj.size() < rows * cols) {
            for (int i = left; i <= right; i++) {
                traj.push_back(matrix[top][i]);
            }
            for (int i = top+1; i <= bottom; i++) {
                traj.push_back(matrix[i][right]);
            }
            for (int i = right-1; i >= left && top < bottom; i--) {
                traj.push_back(matrix[bottom][i]);
            }
            for (int i = bottom-1; i > top && left < right; i--) {
                traj.push_back(matrix[i][left]);
            }
            ++left;--right;++top;--bottom;
        }
        return traj;
    }
};
```

```C++
class Solution {
public:

    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> traj;
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        int x = 0, y = -1, di = 0;
        for (int i = 0; i < rows * cols; i++) {
            if (0 > x+direction[di][0] || x+direction[di][0] >= rows ||
                0 > y+direction[di][1] || y+direction[di][1] >= cols ||
                visited[x+direction[di][0]][y+direction[di][1]]) di = (di + 1) % 4;
            x += direction[di][0];
            y += direction[di][1];
            visited[x][y] = true;
            traj.push_back(matrix[x][y]);
        }
        return traj;
    }
};
```

## 包含min函数的栈

```C++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (min_s.empty() || min_s.top() >= x)
            min_s.push(x);
        base.push(x);
    }

    void pop() {
        if (min_s.top() == base.top()) min_s.pop();
        base.pop();
    }

    int top() {
        return base.top();
    }

    int min() {
        return min_s.top();
    }

    stack<int> base;
    stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```

## 第 k 个丑数

```C++
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0) return 0;
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        int cur = 0;
        for (int i = 1; i < index; i++) {
            cur = min(min(res[i2]*2, res[i3]*3), res[i5]*5);
            res.push_back(cur);
            if (cur == res[i2]*2) i2++;
            if (cur == res[i3]*3) i3++;
            if (cur == res[i5]*5) i5++;
        }
        return res.back();
    }
};
```

## 环链表入口

```C++
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *slow, *fast;
        slow = fast = pHead;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) { // find the loop
                ListNode* new_fast = pHead->next, *new_slow = pHead;
                while(slow->next != fast) { // count the nodes in the loop
                    slow = slow->next;
                    new_fast = new_fast->next;
                }
                while(new_slow != new_fast) {
                    new_slow = new_slow->next;
                    new_fast = new_fast->next;
                }
                return new_slow;
            }
        }
        return NULL;
    }
};
```

## 堆排序

```C++
class Solution {
public:
    // 递归实现 siftdown
    void siftDown1(vector<int>& vec, int n, int p) {
        int target = p;
        if (2*p+1 < n && vec[target] < vec[2*p+1]) target = 2*p+1;
        if (2*p+2 < n && vec[target] < vec[2*p+2]) target = 2*p+2;
        if (target != p) {
            swap(vec[target], vec[p]);
            siftDown1(vec, n, target);
        }
    }

    void siftDown(vector<int>& vec, int n, int p) {
        int parent = p;
        int child = 2 * parent + 1;
        int cur = vec[p];
        while (child < n) {
            if (child + 1 < n && vec[child] < vec[child+1]) child = child + 1;
            if (cur < vec[child]) {
                vec[parent] = vec[child];
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
        vec[parent] = cur;
    }

    bool Insert(vector<int>& vec, int value) {
        vec.push_back(value);
        int i = vec.size()-1;
        for (; i > 0 && value > vec[(i-1)/2]; i = (i-1)/2) {
            vec[i] = vec[(i-1)/2];
        }
        vec[i] = value;
        return true;
    }

    bool Delete(vector<int>& vec) {
        vec[0] = vec.back();
        vec.pop_back();
        int parent = 0;
        int child = parent * 2 + 1;
        int tmp = vec[parent];
        while (child < vec.size()) {
            if (child + 1 < vec.size() && vec[child] < vec[child+1]) child = child + 1;
            if (tmp < vec[child]) {
                vec[parent] = vec[child];
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
        vec[parent] = tmp;
        return true;
    }

    void heapSort(vector<int>& vec) {
        int n = vec.size();
        for (int i = n/2-1; i >= 0; i--) {
            siftDown(vec, n, i);
        }

        while (n > 1) {
            swap(vec[0], vec[n-1]);
            n--;
            siftDown(vec, n, 0);
        }

    }
};
```

```cpp
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Heap {

public:
    Heap() {
    }
    ~Heap() {
    }

    void push(T val) {
        vec.push_back(val);
        int i = vec.size() - 1;
        for (; i > 0 && vec[(i - 1) / 2] < val; i = (i - 1) / 2) {
            vec[i] = vec[(i - 1) / 2];
        }
        vec[i] = val;
    }

    T top() {
        return vec[0];
    }

    T pop() {
        vec[0] = vec.back();
        vec.pop_back();
        siftDown(0);
    }

    int size() {
        return (int)vec.size();
    }

    bool empty() {
        return vec.empty();
    }

private:
    void siftDown(int i) {
        int n = vec.size();
        int parent = i;
        int child = i * 2 + 1;
        int cur = vec[parent];
        while (child < n) {
            if (child + 1 < n && vec[child] < vec[child + 1]) child = child + 1;
            if (cur < vec[child]) {
                vec[parent] = vec[child];
                parent = child;
                child = 2 * parent + 1;
            }
            else break;
        }
        vec[parent] = cur;
    }

private:
    vector<int> vec;
};

int main() {
    Heap<int> heap;
    heap.push(2);
    heap.push(3);
    heap.push(7);
    heap.push(1);
    heap.push(-6);
    heap.push(5);
    heap.push(3);

    int n = heap.size();
    for (int i = 0; i < n; ++i) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
}
```

## 快排

```C++
class Solution {
public:

    int partition(vector<int>& vec, int s, int e) {
        if (s >= e) return s;
        int i = s - 1;
        for (int j = s; j < e; j++) {
            if (vec[j] < vec[e]) {
                ++i;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i+1], vec[e]);
        return i + 1;
    }

    int partition(vector<int>& vec, int s, int e) {
        if (s >= e) return s;
        int i = e + 1;
        for (int j = e; j > s; j--) {
            if (vec[j] < vec[s]) {
                --i;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i-1], vec[s]);
        return i - 1;
    }

    void quickSort(vector<int>& vec, int s, int e) {
        if (s >= e) return;
        int pivot = partition(vec, s, e);
        quickSort(vec, s, pivot - 1);
        quickSort(vec, pivot + 1, e);
    }
};
```

## 归并排序

```C++
class Solution {
public:
    vector<int> tmp;

    void mergeSort(vector<int>& vec, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid + 1, r);

        int pl = l, pr = mid + 1, idx = 0;
        int l_val = 0, r_val = 0;
        while (pl <= mid || pr <= r) {
            l_val = pl <= mid ? vec[pl] : INT_MAX;
            r_val = pr <= r ? vec[pr] : INT_MAX;
            if (l_val <= r_val) tmp[idx++] = vec[pl++];
            else tmp[idx++] = vec[pr++];
        }
        for (int i = l; i <= r; i++) {
            vec[i] = tmp[i - l];
        }
    }
};
```

## 逆序对

```C++
class Solution {
public:
    vector<int> tmp;

    void InversePairs(vector<int>& vec, int l, int r, int& res) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        InversePairs(vec, l, mid, res);
        InversePairs(vec, mid + 1, r, res);

        int pl = l, pr = mid + 1, idx = 0;
        long long  l_val = 0, r_val = 0;
        while (pl <= mid || pr <= r) {
            l_val = pl <= mid ? vec[pl] : LLONG_MAX;
            r_val = pr <= r ? vec[pr] : LLONG_MAX;
            if (l_val <= r_val) {
                res += (pr - mid - 1);
                tmp[idx++] = vec[pl++];
            }
            else {
                tmp[idx++] = vec[pr++];
            }
        }
        for (int i = l; i <= r; i++) {
            vec[i] = tmp[i - l];
        }
    }
};
```

## djsktra 算法
