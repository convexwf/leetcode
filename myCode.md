## 98. Validate Binary Search Tree

验证是否为二叉搜索树。

1. 中序递归遍历：针对每一颗子树逐步收缩区间，该方法只能解决严格不等于情况的二叉搜索树，无法处理 左<=根<=右 的情况。
2. 中序遍历 + 排序：通过中序遍历将所有的节点值存到一个数组里，再来判断这个数组是不是有序。
3. 中序遍历：每当遍历到一个新节点时和其上一个节点比较。
4. 迭代中序遍历：Morris 遍历。

**边界条件**

1. 根节点中出现 INT_MAX 和 INT_MIN

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return helper(root->left, mn, root->val) && helper(root->right, root->val, mx);
    }
};
```

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i = 0; i < vals.size() - 1; ++i) {
            if (vals[i] >= vals[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};
```

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* node, TreeNode*& pre) { // pre 表示当前节点的前缀节点
        if (!node) return true;
        bool res = inorder(node->left, pre);
        if (!res) return false;
        if (pre) {
            if (node->val <= pre->val) return false;
        }
        pre = node;
        return inorder(node->right, pre);
    }
};
```

```cpp
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        TreeNode *cur = root, *pre, *parent = NULL;
        bool res = true;
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val >= cur->val) res = false;
                parent = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if (parent->val >= cur->val) res = false;
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
```

## 94. Binary Tree Inorder Traversal

实现二叉树的中序遍历。

1. 递归
2. 迭代+栈+辅助节点
3. Morris 遍历：O(1) 空间复杂度。构建一个线索二叉树，需要将所有为空的右子节点指向中序遍历的下一个节点，这样中序遍历完左子结点后，就能顺利的回到其根节点继续遍历了。具体算法如下：
   - (1) 初始化指针 cur 指向 root
   - (2) 当 cur 不为空时，如果 cur 没有左子结点，打印出 cur 的值，将 cur 指针指向其右子节点
   - (3) 如果 cur 有左子结点，将 pre 指针指向 cur 的左子树中的最右子节点。
     - 若 pre 不存在右子节点，将其右子节点指回 cur，cur 指向其左子节点。
     - 若 pre 存在右子节点，将 pre 的右子节点置空，打印 cur 的值，将 cur 指针指向其右子节点

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root->left) inorder(root->left, res);
        res.push_back(root->val);
        if (root->right) inorder(root->right, res);
    }
};
```

```cpp
// Non-recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *cur, *pre;
        cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
```

## 79. Word Search

给定一个 m x n 二维字符网格 board 和一个字符串单词 word。如果 word 存在于网格中，返回 true；否则，返回 false。

1. DFS：以二维数组中每一个数都作为起点和给定字符串做匹配，并且需要一个 visited 数组用来记录当前位置是否已经被访问过。如果二维数组 board 的当前字符和目标字符串 word 对应的字符相等，则对其上下左右四个邻字符分别调用 DFS 的递归函数，只要有一个返回 true，那么就表示可以找到对应的字符串，否则就不能找到。

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = search(board, word, idx + 1, i - 1, j, visited)
                 || search(board, word, idx + 1, i + 1, j, visited)
                 || search(board, word, idx + 1, i, j - 1, visited)
                 || search(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};
```

## 212. Word Search II

给定一个二维网格 board 和一个字典中的单词列表words，找出所有同时在二维网格和字典中出现的单词。

1. 前缀树 + DFS

TODO

<https://leetcode.com/problems/word-search-ii/discuss/59780/Java-15ms-Easiest-Solution-(100.00>

```cpp
// 2020-12-13 submission
class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            word = "";
            for (TrieNode*& ptr : child) {
                ptr = NULL;
            }
        }
    };

    struct TrieTree {
        TrieNode* root;
        TrieTree() : root(new TrieNode()) {}
        void insert(string word) {
            TrieNode* cur = root;
            for (char c : word) {
                if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }
            cur->word = word;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return vector<string>{};
        vector<string> res;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        TrieTree* tree = new TrieTree();
        for (string word : words)
            tree->insert(word);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                DFS(board, visited, res, i, j, tree->root);
            }
        }
        return res;
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& res, int x, int y, TrieNode* cur) {
        if (0 > x || x >= board.size() || 0 > y || y >= board[0].size() || visited[x][y]) return;
        visited[x][y] = true;
        char c = board[x][y];
        if (cur->child[c-'a']) {
            cur = cur->child[c-'a'];
            if (cur->word != "") {
                res.push_back(cur->word);
                cur->word.clear();
            }
            DFS(board, visited, res, x-1, y, cur);
            DFS(board, visited, res, x+1, y, cur);
            DFS(board, visited, res, x, y-1, cur);
            DFS(board, visited, res, x, y+1, cur);
        }
        visited[x][y] = false;
    }
};
```

##!! 65. Valid Number

验证数字有效性。

1. 状态转移。注意要在字符串后面加一个空格表示结束符，从而使得终结符号只有 1 个。

**边界条件**

1. 数字字符串中间不能被空格打断；不能出现两个以上数字字符串；
2. “1.”是合法的；“.1”合法；“.”不合法；
3. “+.5”合法；
4. “0000.1e-0000.00”合法；

```cpp
// 2020-07-14 submission
class Solution {
public:
    bool isNumber(string s) {
        int trans[][4] = {
            {2, -1, 1, 3}, // 0
            {2, -1, -1, 3},// 1
            {2, 5, -1, 4}, // 2
            {4, -1, -1, -1},// 3
            {4, 5, -1, -1},// 4
            {7, -1, 6, -1},// 5
            {7, -1, -1, -1},// 6
            {7, -1, -1, -1},//7
            {-1, -1, -1, -1}};//8
        int accepted[] = {2, 4, 7};

        s.append(1, ' ');
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (cur == 0 || cur == 8) continue;
                else if (cur == 2 || cur ==4 || cur == 7) cur = 8;
                else cur = -1;;
            }
            else if (s[i] >= '0' && s[i] <= '9') cur = trans[cur][0];
            else if (s[i] == 'e') cur = trans[cur][1];
            else if (s[i] == '+' || s[i] == '-') cur = trans[cur][2];
            else if (s[i] == '.') cur = trans[cur][3];
            else cur = -1;
            if (cur == -1) return false;
        }
        return cur == 8;
    }
};
```

## 144. Binary Tree Preorder Traversal

实现二叉树的前序遍历。

1. 递归
2. 非递归+栈：把根节点 push 到栈中，然后循环检测栈是否为空，若不空，则取出栈顶元素，保存其值，然后看其右子节点是否存在，若存在则 push 到栈中。再看其左子节点，若存在，则 push 到栈中。
3. Morris 遍历

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
    }

    void helper(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};
```

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = st.top(); st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data = {};
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur)
        {
            if (cur->left == NULL)
            {
                data.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // 寻找前驱结点
                pre = cur->left;
                while (pre->right != cur && pre->right)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    data.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                    pre->right = NULL;
                }
            }
        }
        return data;
    }
};
```

## 145. Binary Tree Postorder Traversal

实现二叉树的后序遍历。

1. 递归
2. 迭代+栈+辅助节点
3. Morris 遍历

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root->left) helper(root->left, res);
        if (root->right) helper(root->right, res);
        res.push_back(root->val);
    }
};
```

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->left;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    // addPath
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.push_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p1 = root, *p2 = nullptr;
        // p2的设定是p1的左孩子

        // p1非空就继续循环
        while (p1 != nullptr) {
            p2 = p1->left;
            // 若p1有左孩子
            if (p2 != nullptr) {
                // p2是p1左子树的最右节点
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                // p2->right == nullptr 确定了该节点是第一次访问
                // 先把p1加入结果，再把p1左子树的最右节点指向p1，p1继续往左走
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                // // p2->right == p1 说明该节点已经访问过，此时再访问到就置为空
                } else {
                    p2->right = nullptr;
                    // 打印p1->left而非p1，就保证根节点一定是最后打印的
                    addPath(res, p1->left);
                }
            }
            // 1、其左孩子已经访问完毕，因此把p1的右孩子赋给p1
            // 要么就是在回溯的路上，要么就是到了一个全新的未被访问过的节点
            p1 = p1->right;
        }
        // 最后打印root及其右孩子（若右孩子是叶子节点）
        addPath(res, root);
        return res;
    }
};
```
