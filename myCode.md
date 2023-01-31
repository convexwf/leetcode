## 103. Binary Tree Zigzag Level Order Traversal

二叉树的之字形层序遍历。

1. 先序遍历：用一个变量 level 记录当前的深度，由于 level 是从 0 开始的，假如结果 res 的大小等于 level，就需要在结果 res 中新加一个空集，这样可以保证 res[level] 不会越界。取出 res[level] 之后，判断 level 的奇偶，若其为偶数，则将 node->val 加入 oneLevel 的末尾，若为奇数，则加在 oneLevel 的开头，然后分别对 node 的左右子结点调用递归函数。
2. 层序遍历+队列

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back({});
        }
        vector<int> &oneLevel = res[level];
        if (level % 2 == 0) oneLevel.push_back(node->val);
        else oneLevel.insert(oneLevel.begin(), node->val);
        helper(node->left, level + 1, res);
        helper(node->right, level + 1, res);
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> oneLevel(size);
            for (int i = 0; i < size; ++i) {
                TreeNode *t = q.front(); q.pop();
                int idx = leftToRight ? i : (size - 1 - i);
                oneLevel[idx] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            leftToRight = !leftToRight;
            res.push_back(oneLevel);
        }
        return res;
    }
};
```

## 220. Contains Duplicate III

数组中是否存在一个大小不超过 k 的子数组，该子数组内的最大值和最小值的差不超过 t。

1. 双指针 + map
   - 两个指针 i 和 j 刚开始都指向0，然后 i 开始向右走遍历数组，如果 i 和 j 之差大于 k，且 m 中有 nums[j]，则删除并 j 加一，这样保证了 m 中所有的数的下标之差都不大于 k。
   - 使用 lower_bound() 函数来查找大于或等于 nums[i] - t 的位置，然后检测后面的所有的数字，如果两数的差的绝对值小于等于 t，则返回true。
   - 最后遍历完整个数组返回 false。

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
```

## 123. Best Time to Buy and Sell Stock III

股票交易，买进前必须卖出手头已有的，允许最多两次交易。

1. 在数组中间画条线，在左边进行第一次交易，在右边进行第二次交易，来计算两次交易的最大收益和。这样，就将问题简化为只进行一次交易的问题了。维护两个数组，分别存储截止到第 x 日交易的最大利润和第 x 日之后交易的最大利润。

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

## 560. Subarray Sum Equals K

让求和为 k 的连续子数组的个数。

1. HashMap：建立连续子数组之和跟其出现次数之间的映射，初始化要加入 {0,1} 这对映射。建立哈希表的目的是为了快速查找 sum-k 是否存在，即是否有连续子数组的和为 sum-k，如果存在的话，那么和为 k 的子数组一定也存在。

```cpp
// 2021-03-17 submission
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dp{{0 ,1}};
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            res += dp[sum - k];
            ++dp[sum];
        }
        return res;
    }
};
```

## 501. Find Mode in Binary Search Tree

求二分搜索树中的众数。

1. 先序遍历+哈希表计数
2. 递归中序遍历:不用除了递归中的隐含栈之外的额外空间。二分搜索树的中序遍历结果是有序的。
3. 迭代中序遍历。

```cpp
// 2021-12-21 submission
// 23/23 cases passed
// Runtime: 20 ms, faster than 64.74% of C++ online submissions.
// Memory Usage: 29.3 MB, less than 5.03% of C++ online submissions.
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        int max_val = DFS(root, m);

        vector<int> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == max_val)
                res.push_back(it->first);
        }
        return res;
    }

    int DFS(TreeNode* root, unordered_map<int, int>& m) {
        if (!root) return 0;
        ++m[root->val];
        return max(max(DFS(root->left, m), DFS(root->right, m)), m[root->val]);
    }
};
```

```cpp
// 2021-12-21 submission
// 23/23 cases passed
// Runtime: 24 ms, faster than 43.63% of C++ online submissions.
// Memory Usage: 29.2 MB, less than 5.03% of C++ online submissions.
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = nullptr;
        vector<int> res;
        int cur = 1, int mx = 0;
        inorder(root, pre, res, cur, mx);
        return res;
    }

    void inorder(TreeNode* root, TreeNode* &pre, vector<int>& candidates, int& cur, int& mx) {
        if (!root) return;
        inorder(root->left, pre, candidates, cur, mx);
        if (pre) cur = pre->val == root->val ? cur+1 : 1;
        if (cur >= mx) {
            if (cur > mx) candidates.clear();
            mx = cur;
            candidates.push_back(root->val);
        }
        pre = root;
        inorder(root->right, pre, candidates, cur, mx);
    }
};
```

```cpp
// 2021-12-21 submission
// 23/23 cases passed
// Runtime: 28 ms, faster than 25.09% of C++ online submissions.
// Memory Usage: 29.1 MB, less than 6.61% of C++ online submissions.
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        TreeNode* cur = root, *pre = nullptr;
        int cnt = 0, mx = 0;
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
            if (pre) cnt = (pre->val == cur->val) ? cnt+1 : 1;
            if (cnt >= mx) {
                if (cnt > mx) res.clear();
                mx = cnt;
                res.push_back(cur->val);
            }
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
```

## 520. Detect Capital

检测单词的大写格式是否正确，规定了三种正确方式，要么都是大写或小写，要么首字母大写，其他情况都不正确。

1. 状态机：![520. 状态机](res/myCode-520._状态机.png)
2. 统计出单词中所有大写字母的个数 cnt，再来判断是否属于这三种情况。

```cpp
// 2021-12-21 submission
class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<vector<int> > trans{
            {1, 2},
            {1, 5},
            {3, 4},
            {3, 5},
            {5, 4},
            {5, 5}
        };
        int state = 0;
        for (char c : word) {
            int next = isupper(c) ? 1 : 0;
            state = trans[state][next];
            if (state == 5) break;
        }
        return state != 5;
    }
};
```

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0, n = word.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] <= 'Z') ++cnt;
        }
        return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
    }
};
```

## 606. Construct String from Binary Tree

创建二叉树对应的字符串。如果左子结点为空，右子结点不为空时，需要在父结点后加上个空括号，而右子结点如果不存在，或者左右子结点都不存在就不需要这么做。

1. 递归
   - 如果左右结果串均为空，则直接返回当前结点值
   - 如果左子结果串为空，那么返回当前结果 res，加上一个空括号，再加上放在括号中的右子结果串
   - 如果右子结果串为空，那么发返回当前结果res，加上放在括号中的左子结果串
   - 如果左右子结果串都存在，那么返回当前结果，加上分别放在括号中的左右子结果串

```cpp
// 2021-12-23 submission
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string res = to_string(root->val);
        if (!root->left && !root->right) return res;
        res += "(" + tree2str(root->left) + ")";
        if (root->right) res += "(" + tree2str(root->right) + ")";
        return res;
    }
};
```

## 637. Average of Levels in Binary Tree

求一个二叉树每层的平均值。

1. 层序遍历
2. 先序遍历

```cpp
// 2021-12-21 submission
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (root) q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            double level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                level_sum += q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level_sum / q_size);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res, cnt;
        helper(root, 0, cnt, res);
        for (int i = 0; i < res.size(); ++i) {
            res[i] /= cnt[i];
        }
        return res;
    }

    void helper(TreeNode* node, int level, vector<double>& cnt, vector<double>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back(0);
            cnt.push_back(0);
        }
        res[level] += node->val;
        ++cnt[level];
        helper(node->left, level + 1, cnt, res);
        helper(node->right, level + 1, cnt, res);
    }
};
```

## 438. Find All Anagrams in a String

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

1. 滑动窗口 + HashMap：两个变量 left 和 right 表示滑动窗口的左右边界，HashMap 用于存储 p 中字符的出现频率。

```cpp
// 2021-03-18 submission
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        char m[256];
        int len = p.length();
        for (char c : p)
            ++m[c];

        int l = 0;
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            --m[s[i]];
            while (m[s[i]] < 0) ++m[s[l++]];
            if (i - l + 1 == len) res.push_back(l);
        }
        return res;
    }
};
```

## 349. Intersection of Two Arrays

找两个数组交集的部分（不包含重复数字）。

1. HashSet：把 nums1 都放进 HashSet，然后遍历 nums2 的元素，如果在 HashSet 中存在，说明是交集的部分。
2. 排序+双指针：先给两个数组排序，然后用两个指针分别指向两个数组的开头，然后比较两个数组的大小，把小的数字的指针向后移，如果两个指针指的数字相等，那么看结果 res 是否为空，如果为空或者是最后一个数字和当前数字不等的话，将该数字加入结果 res 中。
3. 排序+二分查找：将一个数组排序，然后遍历另一个数组，把遍历到的每个数字在排序号的数组中用二分查找法搜索，如果能找到则放入结果 set 中。
4. STL的 set_intersection 函数。

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (st.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};
```

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
```

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
```

## 350. Intersection of Two Arrays II

以数组形式返回两数组的交集，返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致。

1. HashMap：建立 nums1 中字符和其出现个数之间的映射，然后遍历 nums2 数组，如果当前字符在 HashMap 中的个数大于0，则将此字符加入结果 res 中，然后 HashMap 的对应值自减 1。
2. 排序+双指针：先给两个数组排序，然后用两个指针分别指向两个数组的起始位置，如果两个指针指的数字相等，则存入结果中，两个指针均自增 1，如果第一个指针指的数字大，则第二个指针自增 1，反之亦然。

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int a : nums1) ++m[a];
        for (int a : nums2) {
            if (m[a]-- > 0) res.push_back(a);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
```

## 341. Flatten Nested List Iterator

给定一个嵌套的整数列表 nestedList，每个元素要么是一个整数，要么是一个列表，该列表的元素也可能是整数或者是其他列表。实现一个迭代器将其扁平化，使之能够遍历这个列表中的所有整数。

1. 栈：从后往前把对象压入栈中，那么第一个对象最后压入栈就会第一个取出来处理。hasNext() 函数需要遍历栈，并进行处理，如果栈顶元素是整数，直接返回 true，如果不是，移除栈顶元素，并开始遍历这个取出的 list，还是从后往前压入栈，循环停止条件是栈为空，返回 false。
2. 双向队列：思路同上。

```cpp
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger t = s.top(); s.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!s.empty()) {
            NestedInteger t = s.top();
            if (t.isInteger()) return true;
            s.pop();
            for (int i = t.getList().size() - 1; i >= 0; --i) {
                s.push(t.getList()[i]);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> s;
};
```

```cpp
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            d.push_back(a);
        }
    }

    int next() {
        NestedInteger t = d.front(); d.pop_front();
        return t.getInteger();
    }

    bool hasNext() {
        while (!d.empty()) {
            NestedInteger t = d.front();
            if (t.isInteger()) return true;
            d.pop_front();
            for (int i = 0; i < t.getList().size(); ++i) {
                d.insert(d.begin() + i, t.getList()[i]);
            }
        }
        return false;
    }

private:
    deque<NestedInteger> d;
};
```
