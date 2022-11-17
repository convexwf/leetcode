
## 241. Different Ways to Add Parentheses

给了一个可能含有加减乘的表达式，在任意位置添加括号，求出所有可能表达式的不同值。

1. 分治法
   - 先建立一个结果 res 数组，然后遍历 input 中的字符，在每个运算符的地方，将 input 分成左右两部分，从而扔到递归中去计算，从而可以得到两个整型数组 left 和 right，分别表示作用两部分各自添加不同的括号所能得到的所有不同的值，再分别从两个数组中取数字进行当前的运算符计算，然后把结果存到 res 中即可。当然，若最终结果 res 中还是空的，那么只有一种情况，input 本身就是一个数字，直接转为整型存入结果 res 中即可
2. 分治法+HashMap：使用 HashMap 来保存已经计算过的情况，这样可以减少重复计算，从而提升运算速度，以空间换时间
3. 动态规划
   - 三维 dp，其中 `dp[i][j]` 表示在第i个数字到第j个数字之间范围内的子串添加不同括号所能得到的不同值的整型数组
   - 对 input 字符串进行预处理，将数字跟操作分开，加到一个字符串数组 ops 中，并统计数字的个数 cnt，用这个 cnt 来初始化 dp 数组的大小，并同时要把 `dp[i][j]` 的数组中都加上第 i 个数字，通过 `ops[i*2]` 取得，当然还需要转为整型数。
   - 更新顺序是从小区间往大区间更新

```C++
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};
```

```cpp
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string input) {
        if (memo.count(input)) return memo[input];
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        memo[input] = res;
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        vector<string> ops;
        int n = input.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && isdigit(input[j])) ++j;
            ops.push_back(input.substr(i, j - i));
            if (j < n) ops.push_back(input.substr(j, 1));
            i = j;
        }
        int cnt = (ops.size() + 1) / 2;
        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(cnt, vector<int>()));
        for (int i = 0; i < cnt; ++i) dp[i][i].push_back(stoi(ops[i * 2]));
        for (int len = 0; len < cnt; ++len) {
            for (int i = 0; i < cnt - len; ++i) {
                for (int j = i; j < i + len; ++j) {
                    vector<int> left = dp[i][j], right = dp[j + 1][i + len];
                    string op = ops[j * 2 + 1];
                    for (int num1 : left) {
                        for (int num2 : right) {
                            if (op == "+") dp[i][i + len].push_back(num1 + num2);
                            else if (op == "-") dp[i][i + len].push_back(num1 - num2);
                            else dp[i][i + len].push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        return dp[0][cnt - 1];
    }
};
```

## 105. Construct Binary Tree from Preorder and Inorder Traversal

前序遍历+中序遍历，构建二叉树

1. 分治法
   - 先序遍历的第一个元素是根，结合中序遍历可以对左右子树分别处理

```C++
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};
```

## 106. Construct Binary Tree from Inorder and Postorder Traversal

中序遍历+后序遍历，构建二叉树

1. 分治法
   - 后序遍历的最后一个元素是根，结合中序遍历可以对左右子树分别处理

```cpp
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode *cur = new TreeNode(postorder[pRight]);
        int i = 0;
        for (i = iLeft; i < inorder.size(); ++i) {
            if (inorder[i] == cur->val) break;
        }
        cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
        cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
        return cur;
    }
};
```

## 114. Flatten Binary Tree to Linked List

把二叉树展开成链表

1. 递归：利用 DFS 的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。
2. 迭代：从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，将左子结点及其后面所有结构一起连到原右子节点的位置，把原右子节点连到原左子结点最后面的右子节点之后。

```C++
// 2020-09-16 submission
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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = right;
    }
};
```

```cpp
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
```

## 116. Populating Next Right Pointers in Each Node

连接完美二叉树中的相邻节点

1. 递归前序遍历
   - 每个节点都要负责解决左子节点和右子节点的 next 指针指向。
   - 因为是完全二叉树，所以左节点可以直接指向右节点；
   - 右子节点的处理方法是，判断其父节点的 next 是否为空，若不为空，则指向其 next 指针指向的节点的左子结点，若为空则指向 NULL
2. 非递归层序遍历：用两个指针 start 和 cur，其中 start 标记每一层的起始节点，cur 用来遍历该层的节点

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        // if (root->right) root->right->next = root->next? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
```

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node *start = root, *cur = NULL;
        while (start->left) {
            cur = start;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};
```

## 117. Populating Next Right Pointers in Each Node II

普通二叉树连接相邻节点，要求不使用额外空间。

1. 迭代遍历+队列：每层的节点都按顺序加入 queue 中，而每当从 queue 中取出一个元素时，将其 next 指针指向 queue 中下一个节点，对于每层的开头元素开始遍历之前，先统计一下该层的总个数，当 for 循环结束的时候，该层就已经被遍历完了。空间复杂度不为 O(1)！
2. 递归：由于子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点。
3. 迭代，O(1)空间复杂度
   - 建立一个 dummy 结点来指向每层的首结点的前一个结点，然后指针cur用来遍历这一层
   - 首先cur指向dummy，然后cur再连上root下一层的首结点，这样dummy也就连上了。然后当root层遍历完了之后，root需要往下移动一层，这样dummy结点之后连接的位置就正好赋值给root，然后cur再指向dummy，dummy之后断开，这样又回到了初始状态，以此往复就可以都连上了。

```C++
// 2020-11-09 submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            Node* cur = NULL;
            for (int i = 0; i < q_size; i++) {
                cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                cur->next = (i == q_size-1 ? NULL : q.front());
                cur = cur->next;
            }
        }
        return root;
    }
};
```

```C++
// 2020-11-09 submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node *root)
    {
        if(!root) return NULL;

        if(root->left) root->left->next = (root->right != nullptr ? root->right : findNext(root->next));
        if(root->right) root->right->next = findNext(root->next);

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* findNext(Node* curr)
    {
        if(!curr) return NULL;
        if(curr->left) return curr->left;
        if(curr->right) return curr->right;
        return findNext(curr->next);
    }
};
```

```cpp
// Non-recursion, constant space
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL; // 必须清空，否则会死循环
            }
        }
        return head;
    }
};
```

## 130. Surrounded Regions

二维棋盘上，将被包围的 'O' 都改为 'X'，注意的是边缘的 'O' 不算被包围。

题目关键在于找到所有与边缘 'O' 接壤的 'O' 位置。

1. DFS: 维护一个 mask 数组，保存所有与边缘 'O' 接壤的 'O' 位置，最后把除了这些位置以外的更新为 'X' 即可。
2. DFS：不使用 mask 数组，直接改变原数组，将边缘的 'O' 及其相连接的 'O' 改为 '$'，这样剩下的 'O' 都是被包围的，然后将这些 'O' 变成 'X'，把 '$' 变回 'O' 就行。
3. BFS：在找到边界上的 'O' 后，然后利用队列 queue 进行 BFS 查找和其相连的所有 'O'，然后都标记上美元号。最后的处理还是先把所有的 'O'变成 'X'，然后再把美元号变回 'O' 即可。

```C++
// 2020-09-20 submission
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int res = 0;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool> > mask(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows-1 || j == 0 || j == cols - 1) {
                    DFS(board, mask, i, j);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!mask[i][j]) board[i][j] = 'X';
            }
        }
    }

    void DFS(vector<vector<char>>& board, vector<vector<bool>>& mask, int i, int j) {
        if (board[i][j] != 'O' || mask[i][j]) return;
        mask[i][j] = true;
        if (i > 0) DFS(board, mask, i-1, j);
        if (i < board.size()-1) DFS(board, mask, i+1, j);
        if (j > 0) DFS(board, mask, i, j-1);
        if (j < board[0].size()-1) DFS(board, mask, i, j+1);
    }
};
```

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') dfs(board, i , j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
        board[x][y] = '$';
        for (int i = 0; i < dir.size(); ++i) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < m && dy > 0 && dy < n && board[dx][dy] == 'O') {
                dfs(board, dx, dy);
            }
        }
    }
};
```

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1) continue;
                if (board[i][j] != 'O') continue;
                board[i][j] = '$';
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(), x = t / n, y = t % n; q.pop();
                    if (x >= 1 && board[x - 1][y] == 'O') {board[x - 1][y] = '$'; q.push(t - n);}
                    if (x < m - 1 && board[x + 1][y] == 'O') {board[x + 1][y] = '$'; q.push(t + n);}
                    if (y >= 1 && board[x][y - 1] == 'O') {board[x][y - 1] = '$'; q.push(t - 1);}
                    if (y < n - 1 && board[x][y + 1] == 'O') {board[x][y + 1] = '$'; q.push(t + 1);}
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
```

## 133. Clone Graph

无向图的深拷贝

1. 哈希+DFS：使用 HashMap 来对应原图中的结点和新生成的克隆图中的结点。
   - 在DFS递归函数中，首先判空，然后再看当前的结点是否已经被克隆过了
   - 若在 HashMap 中存在，则直接返回其映射结点，否则就克隆当前结点，并在 HashMap 中建立映射。
   - 然后遍历当前结点的所有 neighbor 结点，调用递归函数并且加到克隆结点的 neighbors 数组中即可。
2. 哈希+BFS：使用队列 queue 进行辅助
   - 先克隆当前结点，然后建立映射，并加入 queue 中，进行 while 循环。
   - 在循环中，取出队首结点，遍历其所有 neighbor 结点，若不在 HashMap 中，根据 neigbor 结点值克隆一个新 neighbor 结点，建立映射，并且排入 queue 中。
   - 然后将 neighbor 结点在 HashMap 中的映射结点加入到克隆结点的 neighbors 数组中即可

```C++
// 2020-11-11 submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return helper(node, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return node;
        if (m.count(node)) return m[node];
        Node* res = new Node(node->val);
        m[node] = res;
        for (Node* neighbor: node->neighbors) {
            res->neighbors.push_back(helper(neighbor, m));
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> m;
        queue<Node*> q{{node}};
        Node *clone = new Node(node->val);
        m[node] = clone;
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            for (Node *neighbor : t->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[t]->neighbors.push_back(m[neighbor]);
            }
        }
        return clone;
    }
};
```

## 134. Gas Station

一个环上有 N 个加油站，给定每个加油站的油量 gas[i]，车子从节点 i 驶向下一个节点 i+1 所要消耗的油量为 cost[i]。油箱为空的车子从某个节点出发，问是否能够绕环一圈回到原处。

1. 基本定理：如果一个数组的总和非负，那么一定可以找到一个起始位置，从他开始绕数组一圈，累加和一直都是非负的
2. 题目可转化为求最大连续和。
3. $O(n)$ 做法：从位置 i 开始，i+1, i+2 ...，一路开过来一路油箱都没有空。说明从 i 到 i+1, i+2, ...一直是正积累。如果在位置 j 卡住走不下去，没必要从位置 i+1 重新走一遍，因为少了位置 i 的积累从 i+1 肯定走不到 j，所以可以直接从 j+1重新尝试，同时要把从 i 到 j 的负积累（debt）记录下来以便最后查看题目是否有解（详细看 1.定理）

```C++
// 2018-09-19 submission
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int debt = 0;
        int profit = 0;
        int res_idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            profit += (gas[i] - cost[i]);
            if (profit < 0) {
                debt += profit;
                profit = 0;
                res_idx = i + 1;
            }
        }
        return profit + debt >= 0 ? res_idx : -1;
    }
};
```

## 138. Copy List with Random Pointer

链表（具有随机指针）的深拷贝

1. 哈希+递归：建立一个 HashMap 来建立原链表结点和拷贝链表结点之间的映射。在递归函数中，首先判空，若为空，则返回空指针。然后去 HashMap 中查找是否已经在拷贝链表中存在了该结点，是的话直接返回。否则新建一个拷贝结点 res，然后建立原结点和该拷贝结点之间的映射，然后给拷贝结点的 next 和 random 指针赋值。
2. 迭代：不占用额外的空间
   1. 在原链表的每个节点后面拷贝出一个新的节点（新节点随机指针设为空）。e.g. 7(null)->13(0)->11(4)->10(2)->1(0) 变成  7(null)->7(null)->13(0)->13(null)->11(4)->11(null)->10(2)->10(null)->1(0)->1(null)
   2. 依次给新的节点的随机指针赋值 cur->next->random = cur->random->next
   3. 断开链表可得到深度拷贝后的新链表。

```C++
// 2020-11-11 submission (哈希+递归)submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val);
        m[node] = res;
        res->next = helper(node->next, m);
        res->random = helper(node->random, m);
        return res;
    }
};
```

```C++
// 2020-11-11 submission (迭代)submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* cur = head;
        while(cur) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = cur->next->next;
        }

        cur = head;
        while(cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        Node* res = head->next;
        while(cur) {
            Node *t = cur->next;
            cur->next = t->next;
            if (t->next) t->next = t->next->next;
            cur = cur->next;
        }
        return res;
    }
};
```

## 693. Binary Number with Alternating Bits

判断一个二进制数的 1 和 0 是否是交替出现的

1. 可以通过 异或 1 的方式来将 0 和 1 互换
   - while 循环的条件是最低位等于 d，而 d 不停的在 0 和 1 之间切换，n 每次也向右平移一位，这样能交替检测 0 和 1
   - 循环退出后，如果 n 为 0，则返回 true，反之则返回 false。
2. 错位相加
   - 比如 n 是10101，那么 n>>1 就是1010，二者相加就是 11111，再加 1 就是 100000，二者相与就是0
3. 先将 n 右移两位，再和原来的 n 异或，得到的结果其实就是除了最高位，其余都是 0 的数，然后再和自身减 1 的数相与，如果是 0 就返回 true，反之 false。
   - 比如 n 是 10101，那么 n/4 是 101，二者相异或，得到 10000，此时再减 1，为 1111，二者相与得 0

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n & 1;
        while ((n & 1) == d) {
            d ^= 1;
            n >>= 1;
        }
        return n == 0;
    }
};
```

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n + (n >> 1) + 1) & (n + (n >> 1))) == 0;
    }
};
```

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^= n / 4) & (n - 1)) == 0;
    }
};
```

## 42. Trapping Rain Water

接雨水问题。

1. 每个位置能接的雨水量是：当前位置左边最高的数与右边最高的数的最小值减去当前位置的数（注意不能为负数）。所以需要遍历两遍数组，第一遍在 dp[i] 中存入i位置左边的最大值，然后开始第二遍遍历数组，第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值。
2. 只遍历一次数组
   - left 和 right 两个指针分别指向数组的首尾位置，从两边向中间扫描
   - 在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是 left 指向的值，则从左向右扫描，如果较小值是 right 指向的值，则从右向左扫描
   - 若遇到的值比当较小值小，则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至 left 和 right 指针重合
3. 栈
   - 遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈
   - 当遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过
   - 如果多于一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量

**边界条件**

1. 高度列表长度小于3

```cpp
// 2020-07-14 submission
// 320/320 cases passed
// Runtime: 4 ms, faster than 88.40% of C++ online submissions.
// Memory Usage: 14.1 MB, less than 71.67% of C++ online submissions.
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> vec(height.size(), 0);
        long long res = 0;

        int maxVal = 0;
        for (int i = 0; i < (int)height.size(); i++) {
            maxVal = max(maxVal, height[i]);
            vec[i] = maxVal;
        }

        maxVal = 0;
        for (int i = (int)vec.size()-1; i >= 0; i--) {
            maxVal = max(maxVal, height[i]);
            res += (min(maxVal, vec[i]) - height[i]);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};
```

## 300. Longest Increasing Subsequence

最长递增子串

1. 动态规划 O(n^2)：dp[i] 表示以 nums[i] 为结尾的最长递增子串的长度，对于每一个 nums[i]，从第一个数再搜索到 i，如果发现某个数小于 nums[i]，更新 dp[i]。$dp[i] = max(dp[i], dp[j] + 1)$。
2. 二分查找 O(nlogn)：先建立一个数组 ends，把首元素放进去，然后比较之后的元素
   - 如果遍历到的新元素比 ends 数组中的首元素小的话，替换首元素为此新元素
   - 如果遍历到的新元素比 ends 数组中的末尾元素还大的话，将此新元素添加到 ends 数组末尾(注意不覆盖原末尾元素)。
   - 如果遍历到的新元素比 ends 数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字。
   - ends 不是一个原数组的 LIS，只是长度相等而已
3. 二分查找+动态规划
   - 二分查找法在 dp 数组找第一个不小于它的数字
   - 如果这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字
   - 如果存在，则将这个数字更新为当前遍历到的数字，最后返回 dp 数组的长度即可。
   - dp 数组的值可能不是一个真实的 LIS

**Follow Up**

1. 如果 LIS 不是严格递增
[[LintCode] Longest Increasing Subsequence 最长递增子序列 - Grandyang - 博客园](https://www.cnblogs.com/grandyang/p/4891500.html)
2. 如果要求出所有符合条件的子序列

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int firstGreaterEuqalTarget(int l, int r, int &target) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ends[mid] < target) l = mid + 1;
            else right = mid;
        }
        return r;
    }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) ends[0] = a;
            else if (a > ends.back()) ends.push_back(a);
            else ends[firstGreaterEuqalTarget(l, r, a)] = a;
        }
        return ends.size();
    }
};
```

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(nums[i]);
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};
```

## 33. Search in Rotated Sorted Array

在旋转数组中搜索一个给定值，返回坐标，若不存在返回 -1，数组中*无*重复值。

1. 二分搜索
   - 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
   - 在有序的半段里用首尾两个数来判断目标值是否在这一区域内，这样就可以确定保留哪半边。
   - 为什么一定要用中间的数字跟最右边的比较？能不能和最左边进行比较？
    二分搜索中，nums[mid] 和 nums[left] 有可能相等，比如数组中只有两个元素。由于只有两个数字且 nums[mid] 不等于 target，target 只有可能在右半边出现，最好的方法就是让其无法进入左半段，就需要左半段是有序的，而且由于一定无法同时满足 nums[left] <= target && nums[mid] > target，因为 nums[left] 和 nums[mid] 相等，同一个数不可能同时大于等于 target，又小于 target。由于这个条件不满足，则直接进入右半段继续搜索即可，所以等于的情况要加到 nums[mid] > nums[left] 的情况中，变成大于等于。

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
```

## 81. Search in Rotated Sorted Array II

在旋转数组中搜索一个给定值，返回坐标，若不存在返回 -1，数组中*有*重复值。

1. 二分搜索，参见 <33. Search in Rotated Sorted Array>
   - 如果出现重复值，把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else if (nums[mid] > nums[right]){
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else --right;
        }
        return false;
    }
};
```

## 153. Find Minimum in Rotated Sorted Array

找出旋转数组的最小值，数组中*无*重复值。

1. 二分搜索
   - 用中间的值 nums[mid] 和右边界值 nums[right] 进行比较，若数组没有旋转或者旋转点在左半段的时候，中间值是一定小于右边界值的，所以要去左半边继续搜索，反之则去右半段查找，最终返回 nums[right] 即可
2. 分治：每次将区间 [start, end] 从中间 mid 位置分为两段，分别调用递归函数，并比较返回值，每次取返回值较小的那个即可

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};
```

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (nums[start] <= nums[end]) return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
```

## 154. Find Minimum in Rotated Sorted Array II

找出旋转数组的最小值，数组中*有*重复值，如果有多个最小值返回坐标最小的。

1. 二分搜索，参见 <153. Find Minimum in Rotated Sorted Array>
   - 将右指针左移一位（或者将左指针右移一位），略过一个相同数字
2. 分治：只有在 nums[start] < nums[end] 的时候，才能返回 nums[start]，等于的时候不能返回。

```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else --right;
        }
        return nums[right];
    }
};
```

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (nums[start] < nums[end]) return nums[start];
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};
```

## 210. Course Schedule II

每个课程都有先修课程，求修课程的顺序，如果有多种可能只返回一种即可。

1. 拓扑排序
   - 从 queue 中每取出一个数组就将其存在结果中，最终若有向图中有环，则结果中元素的个数不等于总课程数，将结果清空即可。

```C++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto &a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            res.push_back(t);
            q.pop();
            for (auto &a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        if (res.size() != numCourses) res.clear();
        return res;
    }
};
```

## 278. First Bad Version

在一系列版本中找出第一个坏版本，坏版本后都是坏版本，给了一个 API 函数可以用来判定当前版本是否是坏的，尽可能少调用这个 API。

1. 二分查找

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
```

## 500. Keyboard Row

哪些单词可以由键盘上的一行中的键符打出来。

1. 把键盘的三行字符分别保存到三个set中，然后遍历每个单词中的每个字符，分别看当前字符是否在三个集合中，如果在，对应的标识变量变为1，最后统计三个标识变量之和就知道有几个集合参与其中。

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3{'z','x','c','v','b','n','m'};
        for (string word : words) {
            int one = 0, two = 0, three = 0;
            for (char c : word) {
                c = tolower(c);
                if (row1.count(c)) one = 1;
                if (row2.count(c)) two = 1;
                if (row3.count(c)) three = 1;
                if (one + two + three > 1) break;
            }
            if (one + two + three == 1) res.push_back(word);
        }
        return res;
    }
};
```

## 35. Search Insert Position

搜索给定值在数组的插入位置。

1. 二分搜索，查找不小于目标值的数。

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
```

## 84. Largest Rectangle in Histogram

求直方图中最大的矩形。

1. 遍历数组，每找到一个局部峰值（只要当前的数字大于后面的一个数字，那么当前数字就看作一个局部峰值，跟前面的数字大小无关），然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值。
2. 单调递增栈，原理同样是找局部峰值
   - 当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，就要取出栈顶元素进行处理
   - 为了使得最后一块板子也被处理，在高度数组最后面加上一个0
   - 计算面积时，先取出栈中最高的板子，那么就可以先算出长度为1的矩形面积了，然后再取下一个板子，此时根据矮板子的高度算长度为2的矩形面积，以此类推，知道数字大于栈顶元素为止，再次进栈
   - [LeetCode Monotone Stack Summary 单调栈小结 - Grandyang - 博客园](https://www.cnblogs.com/grandyang/p/8887985.html)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i + 1 < height.size() && height[i] <= height[i + 1]) {
                continue;
            }
            int minH = height[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
```

## 187. Repeated DNA Sequences

检测重复出现的 DNA 序列（10个字符为一个序列）

1. 基本做法：hash，将连续的十个字符映射为唯一，出现重复时就加入到结果。同时，为了减少内存使用，可考虑位操作。用两位来表示一个字符，00 表示A，01 表示C，10 表示G，11 表示T，那么总共需要 20 位就可以表示十个字符流。

**边界条件**

1. 可能会出现多次重复（要去重）

```C++
// 2020-09-18 submission
// ?/? cases passed
// Runtime: 68 ms, faster than 93.74% of C++ online submissions.
// Memory Usage: 14.9 MB, less than 97.44% of C++ online submissions.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res; // 用 set 替代 vector，因为可能出现多次重复
        unordered_set<int> hash_set;
        unordered_map<char, int> dna{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        for (int i = 0; i < 9; i++) {
            cur = cur << 2 | dna[s[i]];
        }
        for (int i = 9; i < s.length(); i++) {
            cur = (cur & 0x0003ffff) << 2 | dna[s[i]]; // 每次只保留 20-2=18 位，再加上后来的2位
            if (hash_set.count(cur)) res.insert(s.substr(i-9, 10));
            else hash_set.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};
```

## 189. Rotate Array

数组旋转，要求空间复杂度为 O(1)

1. cur 初始化为数组第一个数字，idx 表示当前在交换的位置，start 表示最开始启动交换的位置，防止陷入死循环
   - 首先 pre 更新为 cur，然后计算新的 idx 的位置，然后将 nums[idx] 上的值先存到 cur 上，然后把 pre 赋值给 nums[idx]，这相当于把上一轮的 nums[idx] 赋给了新的一轮，完成了数字的交换，然后 if 语句判断是否会变到处理过的数字。
2. 先把前 n-k 个数字翻转一下，再把后 k 个数字翻转一下，最后再把整个数组翻转。
3. 不停交换某两个数字的位置来实现旋转。

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};
// 1 2 3 4 5 6 7
// 1 2 3 1 5 6 7
// 1 2 3 1 5 6 4
// 1 2 7 1 5 6 4
// 1 2 7 1 5 3 4
// 1 6 7 1 5 3 4
// 1 6 7 1 2 3 4
// 5 6 7 1 2 3 4
```

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// 1 2 3 4 5 6 7
// 4 3 2 1 5 6 7
// 4 3 2 1 7 6 5
// 5 6 7 1 2 3 4
```

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};
// 1 2 3 4 5 6 7
// 5 2 3 4 1 6 7
// 5 6 3 4 1 2 7
// 5 6 7 4 1 2 3
// 5 6 7 1 4 2 3
// 5 6 7 1 2 4 3
// 5 6 7 1 2 3 4
```

## 657

机器人可以走上下左右四个方向，给定机器人的路径，判断是否在绕圈，即最后是否回到了原点。

1. U 和 D 的数量必须相等，L 和 R 的数量必须相等。

```cpp
// 2021-12-23 submission
// 75/75 cases passed
// Runtime: 8 ms, faster than 95.23% of C++ online submissions.
// Memory Usage: 8 MB, less than 77.3% of C++ online submissions.
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U') y += 1;
            else if (c == 'D') y -= 1;
            else if (c == 'L') x -= 1;
            else x += 1;
        }
        return x == 0 && y == 0;
    }
};
```

## 455. Assign Cookies

饼干分配问题，给定两个数组，分别表示每个小孩期望的饼干尺寸，和每个饼干实际的尺寸。将饼干分配给这些小孩，但分配的饼干尺寸必须不小于小孩期望的饼干尺寸。求出这些饼干最多可以满足几个小孩。

1. 贪心策略：首先对两个数组进行排序。只有满足了当前的小朋友，才会去满足下一个胃口较大的小朋友。

```C++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) ++j;
        }
        return j;
    }
};
```

## 703

在数据流中求第K大的元素。

1. 最小堆，用来保存最大的 K 个数字，每次要加入数字前，先和堆顶进行比较，如果比堆顶小直接舍去即可，如果比堆顶大，先入堆再把堆顶弹出，始终保持堆顶是第 K 大的数字。

**边界条件**

1. 注意在 add 时候数组可能不满 k 个（这个边界条件确实挺弱智的）

```cpp
// 2021-12-19 submission
// 10/10 cases passed
// Runtime: 27 ms, faster than 94.26% of C++ online submissions.
// Memory Usage: 20 MB, less than 20.01% of C++ online submissions.
class KthLargest {
private:
    // C++ STL默认的 priority_queue 是最大堆(less)
    // greater 是最小堆，less 是最大堆
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() >= k) {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            else q.push(nums[i]);
        }
    }

    int add(int val) {
        if (q.size() >= k) {
            if (val > q.top()) {
                    q.pop();
                    q.push(val);
                }
            }
            else q.push(val);
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

## 717

有两种特殊的字符，一种是两位字符，只能是二进制的 11 和 10，另一种是单个位字符，只能是二进制的 0。现在给定一个只包含 0 和 1 的数组，问能否将其正确分割，使得最后一个字符是个单个位字符。

1. 动态规划：从后往前看，最后一位必然有效，倒数第二位如果为 1 必然无效。从第三位开始，当前位为 1 时，说明其能够与后面一位组成有效字符，为 0 时肯定为有效字符。

```cpp
// 2021-12-16 submission
// 93/93 cases passed
// Runtime: 3 ms, faster than 71.94% of C++ online submissions.
// Memory Usage: 9.7 MB, less than 65.33% of C++ online submissions.
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return true;

        int n = bits.size();
        vector<bool> dp(n, true);
        if (bits[n-2] == 1) dp[n-2] = false;
        for (int i = n-3; i >= 0; i--) {
            if (bits[i] == 1) dp[i] = dp[i+2];
            else dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
```

## 492. Construct the Rectangle

根据面积求出矩形的长和宽，要求长和宽的差距尽量的小，即越接近正方形越好。

1. 开方运算 sqrt: 从 (int)sqrt(area) 遍历到 1作为矩形的高度。

```C++
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int W = (int)sqrt(area); W > 1; W--) {
            if (area % W == 0) {
                return {area / W, W};
            }
        }
        return {area, 1};
    }
};
```

## 507. Perfect Number

完数 = 自身所有因子（不包括数字本身）之和

1. 从 1 计数到 sqrt(n)，然后计数所有 i 和 n/i。

**边界条件**

1. 1 不属于完数。

```C++
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= int(sqrt(num)); i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) sum += (num / i);
            }
        }
        return sum == 2 * num;
    }
};
```

## 693

判断一个二进制数的1和0是否是交替出现的。

1. 位运算：首先通过 `((n >> 1) ^ n)` 可以得到全 1 的数字，加 1 可得到 2 的整数次幂。

**边界条件**

1. n = 1431655765，经过 `((n >> 1) ^ n)` 后得到 INT_MAX，加 1 会溢出。

```cpp
// 2021-12-23 submission
// 204/204 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.97% of C++ online submissions.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = ((n >> 1) ^ n);
        return (x & (x + 1)) == 0;
    }
};
```
