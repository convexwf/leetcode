
# 702

在未知大小数组里搜索数字

二分搜索: 假设数组就有整型最大值个数字，在多余的位置上相当于都填上了整型最大值，那么这也是一个有序的数组

```
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int x = reader.get(mid);
            if (x == target) return mid;
            else if (x < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
```

# 700

搜索二叉搜索树

1. 递归
2. 迭代

```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
```

```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};
```

# 701

插入二叉搜索树

1. 检索到空节点时候新建一个节点返回

```
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```

!# 710

生成一个 N 以内的数字，且该数字不能在黑名单中


```
class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        unordered_set<int> st;
        len = N - blacklist.size();
        for (int i = len; i < N; ++i) {st.insert(i);}
        for (int num : blacklist) {st.erase(num);}
        auto it = st.begin();
        for (int num : blacklist) {
            if (num < len) m[num] = *it++;
        }
    }

    int pick() {
        int k = rand() % len;
        return m.count(k) ? m[k] : k;
    }

private:
    unordered_map<int, int> m;
    int len;
};
```

# 470

通过 rand7(1～7) 构造 rand10(1～10)

拒绝采样 Rejection Sampling: 随机到需要的数字就接受，不是需要的就拒绝，并重新采样。

1. 通过 rand7(1～7) 生成 rand49(1～49)，大于 40 的直接拒绝并重新采样
2. 上述方法的递归形式
3. 进一步优化: 在 [1, 49] 的范围内随机到 [41, 49] 内的数字概率还是很高
   - 将采样到的数字减去 40 得到 rand9()
   - (rand9() - 1) * 7 + rand7() 获得 rand63()
   - rand63() 拒绝采样得到 rand3()
   - (rand3() - 1) * 7 + rand7() 得到 rand21()
   - rand21() 拒绝采样得到 rand20()，进而得到 rand10()

```
class Solution {
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num % 10 + 1;
        }
    }
};
```

```
class Solution {
public:
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        return (num <= 40) ? (num % 10 + 1) : rand10();
    }
};
```

```
class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7(), b = rand7();
            int num = (a - 1) * 7 + b;
            if (num <= 40) return num % 10 + 1;
            a = num - 40, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 60) return num % 10 + 1;
            a = num - 60, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 20) return num % 10 + 1;
        }
    }
};
```

# 478

给定一个圆的中心和半径，随机生成圆中的一个点

1. 拒绝采样: 在一个正方形中有均匀分布的点，随机出其内切圆中的一个点，就是随机出x和y之后算平方和，如果小于等于 r 平方，说明其在圆内，可以返回其坐标，记得加上圆心偏移，否则重新进行采样。
2. 极坐标: 随机出角度 theta 和一个小于半径的长度 r。注意取 r 时需要取个平方根。

```
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius; centerX = x_center; centerY = y_center;
    }

    vector<double> randPoint() {
        while (true) {
            // number = (maxVal - minVal) * rand() / (RAND_MAX) + minVal
            // 生成 [-r, r] 范围内的小数
            double x = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double y = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            if (x * x + y * y <= r * r) return {centerX + x, centerY + y};
        }
    }

private:
    double r, centerX, centerY;
};
```

```
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius; centerX = x_center; centerY = y_center;
    }

    vector<double> randPoint() {
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
        double len = sqrt((double)rand() / RAND_MAX) * r;
        return {centerX + len * cos(theta), centerY + len * sin(theta)};
    }

private:
    double r, centerX, centerY;
};
```

# 605

给定一个 01 数组，其中 1 表示已经放了花，0 表示可以放花的位置，不能有相邻的花，求是否还能放下额外 n 盆花

1. 如果有 3 个连续的零，可以放下 1 盆花，如果左右是边界的话，可以放 2 盆花。必须要对边界进行处理，如果首位置是0，那么前面再加上个0，如果末位置是0，就在最后面再加上个0。这样处理之后我们就默认连续0的左右两边都是1了，这样如果有k个连续0，那么就可以通过(k-1)/2来快速计算出能放的花的数量。
2. 为了不特殊处理首末位置，直接先在首尾各加了一个0，然后就三个三个的来遍历，如果找到了三个连续的0，那么n自减1，i自增1，这样相当于i一下向后跨了两步。

```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) return false;
        if (flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if (flowerbed.back() == 0) flowerbed.push_back(0);
        int len = flowerbed.size(), cnt = 0, sum = 0;
        for (int i = 0; i <= len; ++i) {
            if (i < len && flowerbed[i] == 0) ++cnt;
            else {
                sum += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        return sum >= n;
    }
};
```

```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (n == 0) return true;
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};
```

# 594

找出最长的和谐子序列，和谐子序列就是序列中数组的最大最小差值均为 1

1. treemap(红黑树): 建立一个数字和其出现次数之间的映射，从第二个映射对开始遍历，每次跟其前面的映射对比较，如果二者的数字刚好差1，那么就把二个数字的出现的次数相加并更新结果 res 即可
2. 哈希表: 建立每个数字跟其出现次数之间的映射，然后再遍历每个数字的时候，只需在 HashMap 中查找该数字加1是否存在，存在就更新结果 res。
3. 方法2的进一步优化到在一个循环内。
4. 排序+滑动窗口

```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto it = next(m.begin()); it != m.end(); ++it) {
            auto pre = prev(it);
            if (it->first == pre->first + 1) {
                res = max(res, it->second + pre->second);
            }
        }
        return res;
    }
};
```

```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            if (m.count(a.first + 1)) {
                res = max(res, m[a.first] + m[a.first + 1]);
            }
        }
        return res;
    }
};
```

```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            ++m[num];
            if (m.count(num + 1)) {
                res = max(res, m[num] + m[num + 1]);
            }
            if (m.count(num - 1)) {
                res = max(res, m[num] + m[num - 1]);
            }
        }
        return res;
    }
};
```

```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        for (int r = 1; r < nums.size(); ++r) {
            if (nums[r] - nums[l] == 1) {
                res = max(res, r - l + 1);
            }
            else if (nums[r] - nums[l] > 1) {
                while (nums[r] - nums[l] > 1) ++l;
            }
        }
        return res;
    }
};
```

# 398

给定一个存在重复数字的数组，返回给定值在数组中的下标，如果有多个需要随机返回 1 个，要求 O(1) 空间复杂度

1. 水塘抽样: 遍历整个数组，如果数组的值不等于target，直接跳过；如果等于target，计数器加1，然后在[0, cnt)范围内随机生成一个数字，如果这个数字是 0，将 res 赋值为 i 即可。

```
class Solution {
public:
    Solution(vector<int> nums): v(nums) {}

    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
private:
    vector<int> v;
};
```

# 382

随机返回一个链表节点，链表可能会很长，即只允许一次遍历。

1. 水塘抽样: 维护一个大小为1的水塘

```
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int res = 0, cnt = 1;
        ListNode *cur = head;
        while (cur) {
            int j = rand() % cnt;
            if (j == 0) res = cur->val;
            ++cnt;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};
```

# 380

在常数时间范围内实现插入删除和获得随机数操作，*不允许*有重复数字

1. 维护一个一维数组和一个 HashMap，其中数组用来保存数字，HashMap 用来建立每个数字和其在数组中的位置之间的映射
   - 对于插入操作，先看这个数字是否已经在 HashMap 中存在，如果存在的话直接返回 false，不存在的话，将其插入到数组的末尾，然后建立数字和其位置的映射。
   - 对于删除操作，先判断其是否在 HashMap 里，如果没有直接返回 false。了使数组删除也能常数级，将要删除的数字和数组的最后一个数字调换个位置，然后修改对应的 HashMap 中的值，这样只需要删除数组的最后一个元素即可
   - 针对返回随机数操作，只要随机生成一个位置，返回该位置上的数字

```
class RandomizedSet {
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};
```

# 381

在常数时间范围内实现插入删除和获得随机数操作，*允许*有重复数字

1. 参见 <380> 的做法，只不过需要用哈希set存储多个同样值的数组下标。
2. 进一步节约空间，nums改成 `vector<pair<int,int>>`, 第二个int记录这个值在 map 对应的 vector 中的 index。

```
class RandomizedCollection {
public:
    RandomizedCollection() {}
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        // 题目要求: 如果插入时有重复值，返回 false
        return m[val].size() == 1;
    }
    bool remove(int val) {
        if (m[val].empty()) return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if (nums.size() - 1 != idx) { // 仅当不是末位置才需要替换
            nums[idx] = nums.back();
            m[nums.back()].erase(nums.size()-1);
            m[nums.back()].insert(idx);
        }
        nums.pop_back();
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
};
```

```
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();

        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return result;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};
```

# 653

两数之和: BST

1. 前序遍历 + HashSet

```
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return helper(root, k, st);
    }
    bool traverse(TreeNode* node, int k, unordered_set<int>& st) {
        if (!node) return false;
        if (st.count(k - node->val)) return true;
        st.insert(node->val);
        return traverse(node->left, k, st) || traverse(node->right, k, st);
    }
};
```

# 384

数组随机打乱

1. 洗牌算法 Knuth-Durstenfeld Shuffle

```
class Solution {
public:
    Solution(vector<int> nums): v(nums) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = v;
        for (int n = res.size(); n > 0; --n) {
            int randIdx = rand() % n;
            swap(res[randIdx], res[n - 1]);
        }
        return res;
    }

private:
    vector<int> v;
};
```
