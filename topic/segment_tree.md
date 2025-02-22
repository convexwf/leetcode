# 树状数组


树状数组能解决

1. 单点修改，单点查询
2. 区间修改，单点查询
3. 区间修改，区间查询

线段树能解决的问题，树状数组大部分都能解决，但不一定都能解决，因为线段树的扩展性更强。

## lowbit 运算

`lowbit(x)` 表示非负整数 `x` 在二进制表示下的最低位的 `1` 后面的 `0` 组成的数的值。

例如，$44 = (101100)_2$ ，则 $lowbit(44) = 4 = (100)_2$ 。

`lowbit(x)` 的计算公式为 `lowbit(x) = x & -x` 。

## Fenwick Tree (树状数组, Binary Indexed Tree)

给定一个长度为 $n$ 的数组 $a$，现在构建一个树状数组 $t$ ，其结构如下：

![树状数组](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-树状数组.png)

`t[x]` 保存以 `x` 为根的子树中所有叶子节点的和。

注意，原数组的长度为 $n$ ，下标从 $1$ 开始，树状数组的长度为 $n+1$ ，下标从 $1$ 开始。这是为了方便计算。

```txt
t[1] = a[1]
t[2] = t[1] + a[2] = a[1] + a[2]
t[3] = a[3]
t[4] = t[2] + t[3] + a[4] = a[1] + a[2] + a[3] + a[4]
……
```

可以发现，树状数组中节点 `x` 的父节点是 `x + lowbit(x)` ，比如节点 `4` 的父节点是 `4 + 4 = 8` ，节点 `3` 的父节点是 `3 + 1 = 4` 。

**单点修改**

既然如此，我们可以通过修改叶子节点的值，然后更新其父节点的值，来实现单点修改。

比如现在需要对 `a[1]` 进行修改，即 `a[1] = a[1] + k` ，那么需要更新其所有的祖先节点：t[1]、t[2]、t[4]、t[8]、……。

```cpp
void update(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += lowbit(x);
    }
}
```

根据以上性质也能够通过原数组 `a` 来构造树状数组 `t` 。

```cpp
vector<int> t(n + 1, 0);
for (int i = 1; i <= n; ++i) {
    update(i, a[i]);
}
```

**区间查询**

比如需要查询 `sum[7]` ，从图中可以看出，`sum[7] = t[7] + t[6] + t[4]` 。

```txt
6 = 7 - lowbit(7) = 7 - 1 = 6
4 = 5 - lowbit(5) = 5 - 1 = 4
```

也就是说，查询 `sum[x]` 的时候，可以通过 `x - lowbit(x)` 找到下一个需要加的节点。

```cpp
int query_sum(int x) {
    int res = 0;
    while (x) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}
```

上面是求解 `[1, x]` 的区间和，如果需要求解 `[l, r]` 的区间和，可以通过 `query_sum(r) - query_sum(l - 1)` 来实现。

```cpp
int query_range(int l, int r) {
    return query_sum(r) - query_sum(l - 1);
}
// or
int query_range(int l, int r) {
    int res = 0;
    while (r) {
        res += t[r];
        r -= lowbit(r);
    }
    while (l) {
        res -= t[l];
        l -= lowbit(l);
    }
    return res;
}
```

**区间修改，单点查询**

这一类操作需要构造原数组 `a` 的差分数组 `c` ，然后在差分数组 `c` 上构造树状数组 `t` 。

```cpp
// a already has n elements
for (int i = 1; i <= n; ++i) {
    c[i] = a[i] - a[i - 1];
}
for (int i = 1; i <= n; ++i) {
    t[i] = c[i];
    int j = i + lowbit(i);
    if (j <= n) {
        t[j] += t[i];
    }
}
```

区间修改操作只需要修改差分数组的两个端点，然后针对这两个端点的单点修改对树状数组进行更新即可。

## Segment Tree (线段树)

给定一个长度为 $n$ 的数组 $A$，支持以下操作：

- `query(l, r)`：查询区间 $[l, r]$ 的和，其中 $0 \leq l \leq r \leq n-1$
- `update(i, v)`：将 $A[i]$ 的值更新为 $v$，其中 $0 \leq i \leq n-1$

树状数组主要用于单点更新和区间查询，而线段树可以支持区间更新和区间查询。

线段树的 `query` 和 `update` 操作的时间复杂度均为 $O(\log n)$ 。

对于大小为 $n$ 的数组

- 如果 $n$ 是 $2$ 的幂次方，表示线段树最后一层的叶子结点存储的是数组元素本身，最后一层的叶子结点的个数为 $n$ ，由于线段树是完全二叉树，所以总结点数为 $2n-1$ 。
- 如果 $n$ 不是 $2$ 的幂次方，那么线段树最后一层的叶子节点有一部分是空的，最坏情况下就是 $n = 2^k + 1$ ，最后一层只有一个非空节点，倒数第二层一共有 $n-1$ 个节点，总结点数为 $4n-5$ 。

如果线段树基于数组实现，那么数组的大小应该是 $4n$ 。

```cpp
class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    void merge(int node) {
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = data[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);
        merge(node);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) {
            return tree[node];
        }
        if (r < ql || l > qr) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        return query(node * 2 + 1, l, mid, ql, qr) + query(node * 2 + 2, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) {
            tree[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (index <= mid) {
            update(node * 2 + 1, l, mid, index, value);
        } else {
            update(node * 2 + 2, mid + 1, r, index, value);
        }
        merge(node);
    }

public:

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        data = nums;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }

    int query(int i, int j) {
        return query(0, 0, n - 1, i, j);
    }
};
```

基于动态开点的实现方式：

```cpp
class SegmentTree {
private:
    struct Node {
        int l, r;
        int sum;
        Node *left, *right;
        Node(int l, int r) : l(l), r(r), sum(0), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        Node* node = new Node(l, r);
        if (l == r) {
            return node;
        }
        int mid = l + (r - l) / 2;
        node->left = build(l, mid);
        node->right = build(mid + 1, r);
        return node;
    }

    int query(Node* node, int l, int r) {
        if (node == nullptr || node->r < l || node->l > r) {
            return 0;
        }
        if (node->l >= l && node->r <= r) {
            return node->sum;
        }
        return query(node->left, l, r) + query(node->right, l, r);
    }

    void update(Node* node, int index, int value) {
        if (node == nullptr || node->l > index || node->r < index) {
            return;
        }
        if (node->l == index && node->r == index) {
            node->sum = value;
            return;
        }
        update(node->left, index, value);
        update(node->right, index, value);
        node->sum = node->left->sum + node->right->sum;
    }

public:
    SegmentTree(vector<int>& nums) {
        root = build(0, nums.size() - 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(root, i, nums[i]);
        }
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int query(int i, int j) {
        return query(root, i, j);
    }
};
```

基于动态开点的实现方式可以支持区间修改操作。

```cpp
class SegmentTree {
private:
    struct Node {
        int l, r;
        int sum, lazy;
        Node *left, *right;
        Node(int l, int r) : l(l), r(r), sum(0), lazy(0), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        Node* node = new Node(l, r);
        if (l == r) {
            return node;
        }
        int mid = l + (r - l) / 2;
        node->left = build(l, mid);
        node->right = build(mid + 1, r);
        return node;
    }

    void push_down(Node* node) {
        if (node->lazy) {
            node->sum += (node->r - node->l + 1) * node->lazy;
            if (node->l < node->r) {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }
    }

    int query(Node* node, int l, int r) {
        if (node == nullptr || node->r < l || node->l > r) {
            return 0;
        }
        push_down(node);
        if (node->l >= l && node->r <= r) {
            return node->sum;
        }
        return query(node->left, l, r) + query(node->right, l, r);
    }

    void update(Node* node, int l, int r, int value) {
        if (node == nullptr || node->r < l || node->l > r) {
            return;
        }
        if (node->l >= l && node->r <= r) {
            node->lazy += value;
            return;
        }
        push_down(node);
        update(node->left, l, r, value);
        update(node->right, l, r, value);
        node->sum = node->left->sum + node->right->sum;
    }

public:
    SegmentTree(vector<int>& nums) {
        root = build(0, nums.size() - 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(root, i, i, nums[i]);
        }
    }

    void update(int i, int val) {
        update(root, i, i, val);
    }

    void update(int l, int r, int val) {
        update(root, l, r, val);
    }

    int query(int i, int j) {
        return query(root, i, j);
    }
};
```


## Reference

- [线段树详解与实现 - 知乎](https://zhuanlan.zhihu.com/p/174810030)
- [线段树 - OI Wiki](https://oi-wiki.org/ds/seg/)
- [线段树（segment tree)，看这一篇就够了_线段树min-CSDN博客](https://blog.csdn.net/Yaokai_AssultMaster/article/details/79599809)
- [一文读懂扫描线算法 - 知乎](https://zhuanlan.zhihu.com/p/103616664)
- [树状数组(详细分析+应用)，看不懂打死我!-CSDN博客](https://blog.csdn.net/TheWayForDream/article/details/118436732)
