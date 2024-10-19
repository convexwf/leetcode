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

如果使用一维数组实现


树状数组主要用于单点更新和区间查询，而线段树可以支持区间更新和区间查询。


## Reference

- [线段树详解与实现 - 知乎](https://zhuanlan.zhihu.com/p/174810030)
- [线段树 - OI Wiki](https://oi-wiki.org/ds/seg/)
- [线段树（segment tree)，看这一篇就够了_线段树min-CSDN博客](https://blog.csdn.net/Yaokai_AssultMaster/article/details/79599809)
- [一文读懂扫描线算法 - 知乎](https://zhuanlan.zhihu.com/p/103616664)
- [树状数组(详细分析+应用)，看不懂打死我!-CSDN博客](https://blog.csdn.net/TheWayForDream/article/details/118436732)
