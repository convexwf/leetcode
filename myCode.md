## 646. Maximum Length of Pair Chain

给定一些链对，规定了如果后面链对的首元素大于前链对的末元素，那么这两个链对就可以链起来，问最大能链多少个。

1. 排序 + 贪心算法
   - 按链对的尾元素进行排序，小的放前面。
   - 用一个变量 end 来记录当前比较到的尾元素的值，初始化为最小值，然后遍历的时候，如果当前链对的首元素大于 end，那么结果 res 自增 1，end 更新为当前链对的尾元素

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};
```

## 785. Is Graph Bipartite?

存在一个无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给定一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。

该无向图同时具有以下属性：
(1) 不存在自环（graph[u] 不包含 u）。
(2) 不存在平行边（graph[u] 不包含重复值）。
(3) 如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）。
(4) 这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。

二分图：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

1. 并查集
   - 连接的两个节点不能在同一集合中
   - 同一节点的邻接节点必须在同一集合中
2. DFS 染色
   - 使用两种颜色，分别用 1 和 -1 来表示
   - 初始时每个顶点用 0 表示未染色，然后遍历每一个顶点，如果该顶点未被访问过，则调用递归函数
   - 在递归函数中，如果当前顶点已经染色，如果该顶点的颜色和将要染的颜色相同，则返回 true，否则返回 false。如果没被染色，则将当前顶点染色，然后再遍历与该顶点相连的所有的顶点
3. BFS 染色
   - 遍历所有顶点，如果未被染色，则先染色为 1，然后使用 BFS 进行遍历，将当前顶点放入队列 queue 中
   - while 循环：queue 不为空，取出队首元素，遍历其所有相邻的顶点，如果相邻顶点未被染色，则染成和当前顶点相反的颜色，然后把相邻顶点加入 queue 中，否则如果当前顶点和相邻顶点颜色相同，直接返回 false，循环退出后返回 true

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for (int i = 0; i < graph.size(); ++i) root[i] = i;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }
    int find(vector<int>& root, int i) {
        return root[i] == i ? i : find(root, root[i]);
    }
};
```

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0 && !valid(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<int>>& graph, int color, int cur, vector<int>& colors) {
        if (colors[cur] != 0) return colors[cur] == color;
        colors[cur] = color;
        for (int i : graph[cur]) {
            if (!valid(graph, -1 * color, i, colors)) {
                return false;
            }
        }
        return true;
    }
};
```

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while (!q.empty()) {
                int t = q.front(); q.pop();
                for (auto a : graph[t]) {
                    if (colors[a] == colors[t]) return false;
                    if (colors[a] == 0) {
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
};
```
