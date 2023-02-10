## 76. Minimum Window Substring

最小覆盖子串，在字符串 S 里面找出包含 T 所有字母的最小子串。

1. 滑动窗口 + HashMap
   - 只用一个哈希表存储 t 的频率。
   - 另外需要一个计数变量，当频率大于 0 时（因为非法字符最大频率为 0，合法字符最小频率为 0）计数变量 cnt 加 1，从而可以判断是否已经包含所有合法字符。
   - 没有必要每次都计算子串，只要有了起始位置和长度，就能唯一确定一个子串。这里使用一个全局变量 minLeft 来记录最终结果子串的起始位置。

**边界条件**

1. t 长度可能为 0

```cpp
// 2020-07-17 submission
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.length() < t.length()) return "";

        int freq[256] = {0};
        for (char c : t) {
            ++freq[c];
        }

        int left = 0, cnt = 0;
        int minLeft = -1, minLen = s.length() + 1;
        for (int pivot = 0; pivot < s.length(); ++pivot) {
            if (--freq[s[i]] >= 0) ++cnt;
            while (cnt == t.length()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if (++freq[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};
```

## 129. Sum Root to Leaf Numbers

每条从根节点到叶节点的路径都代表一个数字：比如路径 1 -> 2 -> 3 就表示数字 123。计算从根节点到叶节点生成的所有数字之和。

1. DFS
2. 栈：首先将根结点压入栈，然后进行while循环，取出栈顶元素，如果是叶结点，那么将其值加入结果res。如果其右子结点存在，那么其结点值加上当前结点值的 10 倍，再将右子结点压入栈。同理，若左子结点存在，那么其结点值加上当前结点值的 10 倍，再将左子结点压入栈。

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};
```

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        stack<TreeNode*> st{{root}};
        while (!st.empty()) {
            TreeNode *t = st.top(); st.pop();
            if (!t->left && !t->right) {
                res += t->val;
            }
            if (t->right) {
                t->right->val += t->val * 10;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val * 10;
                st.push(t->left);
            }
        }
        return res;
    }
};
```

## 230. Kth Smallest Element in a BST

二叉搜索树中第 K 最小值。

1. 中序遍历
2. 分治法
   - 利用 BST 的性质可以快速定位出第 k 小的元素是在左子树还是右子树。
   - 首先计算出左子树的结点个数总和 cnt，如果 k 小于等于左子树结点总和 cnt，说明第 k 小的元素在左子树中，直接对左子结点调用递归即可。如果 k 大于 cnt+1，说明目标值在右子树中，对右子结点调用递归函数。

**Follow up**

1. BST 被修改得很频繁，而且查找第 k 小元素的操作也很频繁。
   - 修改原树结点的结构，使其保存包括当前结点和其左右子树所有结点的个数，这样就可以快速得到任何左子树结点总数。

```cpp
// 2021-03-18 submission
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }

    int helper(TreeNode* root, int& k) {
        if (!root) return -1;
        int val = helper(root->left, k);
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return helper(root->right, k);
    }
};
```

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};
```

```cpp
// Follow up
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };

    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }

    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }

    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        } else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};
```

## 239. Sliding Window Maximum

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。

1. multiset: multiset是一种基于红黑树的数据结构，可以自动对元素进行排序，允许有重复值。
   - 首先遍历每个数字，即窗口右移，若超过了 k，则需要把左边界值删除，这里不能直接删除 nums[i-k]，因为集合中可能有重复数字，而 erase 默认是将所有和目标值相同的元素都删掉，所以只能提供一个 iterator 代表一个确定的删除位置，先通过 find() 函数找到左边界 nums[i-k] 在集合中的位置再删除。
   - 然后将当前数字插入到集合中，此时看若 i >= k-1，说明窗口大小正好是 k，就需要将最大值加入结果 res 中，而由于 multiset 是按升序排列的，最大值在最后一个元素，可以通过 rbegin() 来取出。
2. 优先队列/最大堆
   - 堆元素为由数字和其所在位置组成的 pair。
   - 在遍历每个数字时，进行 while 循环，假如优先队列中最大的数字此时不在窗口中了，就要移除，判断方法就是将队首元素的 pair 对儿中的 second（位置坐标）跟 i-k 对比，小于等于就移除。然后将当前数字和其位置组成 pair 对儿加入优先队列中。此时看若 i >= k-1，说明窗口大小正好是k，就将最大值加入结果 res 中即可。
3. deque
   - 用双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是 i-k，表示此时窗口向右移了一步，则移除队首元素。
   - 然后比较队尾元素和将要进来的值，如果小的话就都移除，这样可以确保队列中为近似降序排列。

```cpp
// 2020-11-24 submission (multiset)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if (i + 1 >= k) res.push_back(*st.rbegin());
        }
        return res;
    }
};
```

```cpp
//  (priority queue)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) q.pop();
            q.push({nums[i], i});
            if (i >= k - 1) res.push_back(q.top().first);
        }
        return res;
    }
};
```

```cpp
// 2020-11-24 submission (deque)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i + 1 >= k) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```

## 240. Search a 2D Matrix II

搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：每行的元素从左到右升序排列，每列的元素从上到下升序排列。

1. i 指向 0，j 指向列数，这样第一个被验证的数就是二维数组右上角的数字，假如这个数字等于 target，直接返回 true；若大于 target，说明要减小数字，则列数 j 自减 1；若小于 target，说明要增加数字，行数 i 自增 1。

```cpp
// 2021-03-10 submission
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int x = 0, y = cols - 1;
        while (x < rows && y >= 0) {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) ++x;
            else if (matrix[x][y] > target) --y;
        }
        return false;
    }
};
```

## 287. Find the Duplicate Number

给定一个包含 n + 1 个整数的数组，其中每一个整数均介于 [1, n] 之间，其中至少有一个重复元素存在（鸽巢原理）。假设只有一个数字出现重复，找出这个重复的数字。要求不能改动原数组（排序），O(1) extra space，less than O(n2) runtime complexity。

1. 位操作：遍历每一位，然后对于 32 位中的每一个位 bit，都遍历一遍从 0 到 n-1，将 0 到 n-1 中的每一个数都跟 bit 相与，若大于0，则计数器 cnt1 自增1。同时 0 到 n-1 也可以当作 nums 数组的下标，从而让 nums 数组中的每个数字也跟 bit 相与，若大于0，则计数器 cnt2 自增1。最后比较若 cnt2 大于 cnt1，则将 bit 加入结果 res 中。因为对于每一位，0 到 n-1 中所有数字中该位上的 1 的个数应该是固定的，如果 nums 数组中所有数字中该位上 1 的个数多了，说明重复数字在该位上一定是 1，这样我们把重复数字的所有为 1 的位都累加起来，就可以还原出这个重复数字。
2. 快慢指针：限定了区间 [1,n]，所以可以利用坐标和数值之间相互转换，而由于重复数字的存在，那么一定会形成环，用快慢指针可以找到环并确定环的起始位置。

```cpp
// 2020-10-28 submission (位操作)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k) {
                if ((k & bit) > 0) ++cnt1;
                if ((nums[k] & bit) > 0) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};
```

```cpp
// 2020-10-28 submission (快慢指针)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                while (true) {
                    slow = nums[slow];
                    t = nums[t];
                    if (slow == t) return slow;
                }
            }
        }
        return -1;
    }
};
```
