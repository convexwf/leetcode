# Leetcode

[Leetcode面试高频题分类刷题总结 - 知乎](https://zhuanlan.zhihu.com/p/349940945)

## 14. Longest Common Prefix

解题思路:

1. 给输入字符串数组排序，有共同字母多的两个字符串会被排到一起，所以只需要找首尾字母串的共同前缀即可。为了防止溢出错误，只遍历而这种较短的那个的长度，找出共同前缀返回即可。

```C++
// Runtime: 4 ms, faster than 72.48% of C++ online submissions.
// Memory Usage: 9.3 MB, less than 43.57% of C++ online submissions.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
```

## 17. Letter Combinations of a Phone Number

```C++
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 6.5 MB, less than 84.70% of C++ online submissions.
class Solution {
public:

    string prefix[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        queue<string> q;
        if (digits.length() > 0) q.push("");
        for (char digit : digits) {
            for (int q_size = q.size(); q_size > 0; q_size--) {
                string cur = q.front(); q.pop();
                for (char c : prefix[digit-'0']) {
                    q.push(cur + string(1, c));
                }
            }
        }

        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
```

## 19. Remove Nth Node From End of List

解题思路

1. BFS

```C++
// 2018-08-05 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 80.26% of C++ online submissions.
// Memory Usage: 10.7 MB, less than 57.60% of C++ online submissions.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n);
    }

    ListNode* helper(ListNode* curr, int& limit) {
        if(!curr) return NULL;
        curr->next = helper(curr->next, limit);
        --limit;
        if(limit != 0) return curr;
        else return curr->next;
    }
};
```

## 21. Merge Two Sorted Lists

```C++
// 2020-06-28 submission
// ?/? cases passed
// Runtime: 12 ms, faster than 29.96% of C++ online submissions.
// Memory Usage: 15 MB, less than 5.72% of C++ online submissions.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        ListNode* dummy = new ListNode(0), *cur = dummy;
        int val1 = 0, val2 = 0;
        while (l1 || l2) {
            val1 = l1 ? l1->val : INT_MAX;
            val2 = l2 ? l2->val : INT_MAX;
            if (val1 <= val2) {
                cur->next = new ListNode(val1);
                l1 = l1->next;
            }
            else {
                cur->next = new ListNode(val2);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

## 23. Merge k Sorted Lists

```C++
// 2020-06-28 submission
// ?/? cases passed
// Runtime: 24 ms, faster than 59.80% of C++ online submissions.
// Memory Usage: 13.9 MB, less than 27.89% of C++ online submissions.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for (auto node : lists) {
            if (node) q.push(node);
        }
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }
};
```

## 24. Swap Nodes in Pairs

```C++
// 2020-06-28 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 7.6 MB, less than 45.58% of C++ online submissions.
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

## 25. Reverse Nodes in k-Group

```C++
// 2020-06-28 submission
// ?/? cases passed
// Runtime: 12 ms, faster than 90.02% of C++ online submissions.
// Memory Usage: 11.5 MB, less than 61.58% of C++ online submissions.
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

## 42. Trapping Rain Water

解题思路

1. 每个位置能接的雨水量是：当前位置左边最高的数与右边最高的数的最小值减去当前位置的数（注意不能为负数）。

边界条件

1. 高度列表长度小于3

```C++
// 2020-07-14 submission
// ?/? cases passed
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

## 44. Wildcard Matching

解题思路

1. 动态规划
- dp[i][j] 表示 p 前 i 个字符 和 s 前 j 个字符是否匹配
- if p[i-1] == s[j-1] or p[i-1] == '?', dp[i][j]=dp[i-1][j-1]
- if p[i-1] == '*', dp[i][j]=dp[i-1][j] or dp[i][j-1]

边界条件：

1. p 和 s 长度均为 0 时，结果为true
2. s 长度为 0，p 为只由 * 组成的字符串，结果为 true

```C++
// 2020-09-14 submission
// ?/? cases passed
// Runtime: 176 ms, faster than 40.96% of C++ online submissions.
// Memory Usage: 6.6 MB, less than 89.86% of C++ online submissions.
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.length()+1, false);

        dp[0] = true;
        for (int i = 1; i <= p.length(); i++) {
            bool last_valid = dp[0];
            dp[0] = (dp[0] && p[i-1] == '*');
            for (int j = 1; j <= s.length(); j++) {
                bool temp = dp[j];
                if (p[i-1] == '*') dp[j] = dp[j-1] || dp[j];
                else if (p[i-1] == '?') dp[j] = last_valid;
                else dp[j] = (last_valid && s[j-1] == p[i-1]);
                last_valid = temp;
                // cout << s[j-1] << " " << p[i-1] << " " << dp[j] << endl;
            }
        }

        return dp[s.length()];
    }
};
```

## 45. Jump Game II

解题思路

1. 贪心算法：cur 是当前能到达的最远位置，last 是上一步能到达的最远位置，遍历数组。判断如果当前位置到达了 last，即上一步能到达的最远位置，说明需要再跳一次。判断如果 cur 到达末尾

```C++
// 2021-03-11 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions.
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = max(cur, i + nums[i]);
            if (i == pre) {
                ++res;
                pre = cur;
                if (cur >= nums.size() - 1) break;
            }
        }
        return res;
    }
};
```


## 56. Merge Intervals

解题思路

1. 首先给区间集排序，需要定义自己的 comparator，才能用 sort 来排序。（其实直接对二维向量调用sort()函数，二维向量就会按第一列元素排序）。按照 start 的值从小到大来排序，排完序开始合并，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的 end 值更新为结果中最后一个区间的 end 和当前 end 值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果

```C++
// 2019-05-09 submission
// ?/? cases passed
// Runtime: 32 ms, faster than 94.27% of C++ online submissions.
// Memory Usage: 14.5 MB, less than 76.55% of C++ online submissions.
class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        // 自写 sort 函数需要 引用参数 防止大量拷贝 影响效率
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        int i_min=intervals[0][0], i_max=intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(i_max >= intervals[i][0]) i_max = max(i_max, intervals[i][1]);
            else {
                result.push_back(vector<int>{i_min, i_max});
                i_min = intervals[i][0];
                i_max = intervals[i][1];
            }
        }
        result.push_back(vector<int>{i_min, i_max});
        return result;
    }
};
```

```C++
// 2020-11-19 submission
// ?/? cases passed
// Runtime: 44 ms, faster than 59.45% of C++ online submissions.
// Memory Usage: 14.7 MB, less than 54.25% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1])
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
```

## 60. Permutation Sequence

全排列中的第 k 个

```C++
// 2019-09-01 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 6 MB, less than 78.79% of C++ online submissions.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> frac(n, 1);
        string nums = "123456789";
        string ret = "";
        for(int i = 1; i < n; i++) {frac[i] = frac[i-1]*i;}
        --k;
        for(int i = n-1; i >= 0; i--) {
            ret += nums[k / frac[i]];
            nums.erase(k / frac[i], 1);
            k %= frac[i];
        }
        return ret;
    }
};
```

## 61. Rotate List

解题思路

1. 旋转链表
2. 遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，在往后走 n - k%n 个节点就到达新链表的头结点前一个点，这时断开链表

```C++
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *cur = head;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }
        cur->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        ListNode *newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
};
```


## 64. Minimum Path Sum

```C++
// 2018-07-26 submission
// ?/? cases passed
// Runtime: 8 ms, faster than 82.85% of C++ online submissions.
// Memory Usage: 10 MB, less than 35.59% of C++ online submissions.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> record(rows+1, vector<int>(cols+1, INT_MAX));

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (i == 1 && j == 1) record[i][j] = grid[i-1][j-1];
                else record[i][j] = min(record[i-1][j], record[i][j-1]) + grid[i-1][j-1];
            }
        }
        return record[rows][cols];

    }
};
```

## 73. Set Matrix Zeroes

解题思路

1. 给定一个矩阵，如果一个元素为 0，则将其整个行和列设置为 0。需求 in-place

```C++
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) colZero = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) rowZero = true;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
```

## 74. Search a 2D Matrix

搜索 2D 矩阵
每行中的整数从左到右排序。每行的第一个整数大于前一行的最后一个整数。

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n, mid = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) l = mid + 1;
            else r = mid;
        }
        return false;
    }
};
```

## 75. Sort Colors

```C++
// Runtime: 4 ms, faster than 47.31% of C++ online submissions.
// Memory Usage: 8.3 MB, less than 63.84% of C++ online submissions.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return;
        int l = 0, r = (int)nums.size()-1;
        int pivot = -1;
        while (l < r) {
            while (l < r && nums[l] == 0) l++;
            while (l < r && nums[r] == 2) r--;
            if (nums[l] == 2) swap(nums[l], nums[r]);
            else if (nums[l] == 1) {
                pivot = l;
                while(pivot <= r && nums[pivot] == 1) ++pivot;
                if (pivot <= r) swap(nums[pivot], nums[l]);
                else l = r;
            }
        }
    }
};
```

## 77. Combinations

```C++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, k, 1, out, res);
        return res;
    }
    void helper(int n, int k, int level, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {res.push_back(out); return;}
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            helper(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};
```

## 78. Subsets

解题思路

1. 题目描述：找出给定集合的所有子集
2. 递归：DFS深度优先搜索
3. 位操作：数组中所有的数分配一个状态，true 表示这个数在子集中出现，false 表示在子集中不出现，那么对于一个长度为n的数组，每个数字都有出现与不出现两种情况，所以共有 $2^n$ 中情况
// 此处删去了图片

```C++
// 2019-05-06 submission (DFS)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 7.5 MB, less than 7.29% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{vector<int>{}};
        vector<int> temp;
        DFS(nums, temp, result, 0);
        return result;
    }

    void DFS(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& result, int pivot) {
        for(int i = pivot; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            result.push_back(curr);
            DFS(candidates, curr, result, i+1);
            curr.pop_back();
        }
    }
};
```

```C++
// 2020-10-26 submission (位操作)
// Runtime: 4 ms, faster than 67.90% of C++ online submissions.
// Memory Usage: 7.5 MB, less than 7.29% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int count = 1 << nums.size();
        for (int i = 0; i < count; i++) {
            vector<int> vec;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) vec.push_back(nums[j]);
            }
            res.push_back(vec);
        }
        return res;
    }
};
```

## 80. Remove Duplicates from Sorted Array II

给定一个排序数组 nums，就地删除重复项使得重复项最多出现两次，并返回新长度

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 1, cnt = 1, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur] && cnt == 0) ++cur;
            else {
                if (nums[pre] == nums[cur]) --cnt;
                else cnt = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : pre + 1;
    }
};
```

## 81. Search in Rotated Sorted Array II

```C++
// 2021-03-18 submission
// ?/? cases passed
// Runtime: 8 ms, faster than 64.87% of C++ online submissions.
// Memory Usage: 13.8 MB, less than 98.98% of C++ online submissions.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            while (l < r && nums[l] == nums[mid]) ++l;
            if (l >= mid) continue;
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid;
                else l = mid + 1;
            }
            else if (nums[l] > nums[mid]){
                if (nums[mid] < target && target <= nums[r - 1]) l = mid + 1;
                else r = mid;
            }
        }
        return false;
    }
};
```

## 84. Largest Rectangle in Histogram

解题思路

1. 矩形面积由宽度和高度决定，于是固定高度，从而最大化宽度即可。一个位置上的高度确定，确定最大左宽度和最大右宽度，最大宽度即附近的大于自身的高度的连续序列长度。注意最左边位置的左宽度和最右边位置的右宽度为1.

```C++
// 2020-07-16 submission
// ?/? cases passed
// Runtime: 28 ms, faster than 64.06% of C++ online submissions
// Memory Usage: 14.3 MB, less than 47.02% of C++ online submissions
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int max_area = 0;
        int width = heights.size();
        vector<int> left_seq(width, 1);
        vector<int> right_seq(width, 1);

        for (int i = width-1; i >= 0; i--) {
            int pivot = i;
            while (pivot < width) {
                if (heights[i] <= heights[pivot]) pivot += right_seq[pivot];
                else break;
            }
            right_seq[i] = pivot - i;
        }

        for (int i = 0; i < width; i++) {
            int pivot = i;
            while (pivot >= 0) {
                if (heights[i] <= heights[pivot]) pivot -= left_seq[pivot];
                else break;
            }
            left_seq[i] = i - pivot;
            // cout << left_seq[i] << endl;
            max_area = max(max_area, (left_seq[i] + right_seq[i]-1)*heights[i]);
        }

        return max_area;
    }
};
```

## 99. Recover Binary Search Tree

解题思路

1. 中序遍历：通过中序遍历拿到BST的升序排列（同时拿到对应的指针），把升序排列重新排序后重新复制。这是O(nlogn)的时间复杂度，但是空间复杂度（O(n)）不满足要求。
2. 中序遍历改进：通过两个指针和两个变量存储左边和右边，然后交换指针和值即可。
3. Morris 遍历：

```C++
// 2020-07-09 submission (中序遍历)
// Runtime: 52 ms, faster than 19.81% of C++ online submissions
// Memory Usage: 54.7 MB, less than 16.38% of C++ online submissions
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> pointers;
        vector<int> vals;
        inorder(root, pointers, vals);

        if(!vals.empty()) sort(vals.begin(), vals.end());
        for(int i =0; i < pointers.size(); i++) {
            pointers[i]->val = vals[i];
        }
    }

    void inorder(TreeNode* root, vector<TreeNode*>& pointers, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, pointers, vals);
        pointers.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, pointers, vals);
    }
};
```

```C++
// 2020-11-01 submission (中序遍历)
// Runtime: 36 ms, faster than 84.19% of C++ online submissions.
// Memory Usage: 58.3 MB, less than 8.04% of C++ online submissions.
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> pointers(2, NULL);
        vector<int> vals(2, 0);
        inorder(root, pointers, vals);
        pointers[0]->val = vals[1];
        pointers[1]->val = vals[0];
    }

    void inorder(TreeNode* root, vector<TreeNode*>& pointers, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, pointers, vals);
        if (pointers[0] && pointers[1] && vals[0] < root->val) return;
        if (!pointers[0] || vals[0] < root->val) {
            pointers[0] = root;
            vals[0] = root->val;
        }
        if (pointers[0] && vals[0] > root->val) {
            pointers[1] = root;
            vals[1] = root->val;
        }
        // cout << root->val << " " << vals[0] << " " << vals[1] << endl;
        inorder(root->right, pointers, vals);
    }
};
```

## 101. Symmetric Tree

对称二叉树

```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return checkLeftRight(root->left, root->right);
    }

    bool checkLeftRight(TreeNode* left, TreeNode* right) {
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL || left->val!=right->val) return false;
        return checkLeftRight(left->left, right->right) &&
            checkLeftRight(left->right, right->left);
    }
};
```

## 112. Path Sum

解题思路

1. 题目描述：是否存在根点路径和等于给定数

```C++
// 2019-04-24 submission
// ?/? cases passed
// Runtime: 8 ms, faster than 93.97% of C++ online submissions.
// Memory Usage: 21.1 MB, less than 98.40% of C++ online submissions.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right)
            return sum == root->val;
        return hasPathSum(root->left, sum-root->val) ||
                hasPathSum(root->right, sum-root->val);
    }
};
```

## 115. Distinct Subsequences

解题思路

1. 动态规划，dp[i][j] 表示 s 中范围是 [0, i] 的子串中能组成 t 中范围是 [0, j] 的子串的子序列的个数。
2. 状态转移方程为 dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0)

边界条件

1. 空串是任意字符串（包括空串）的子串，在本题中空串仅计算1次。
2. 非空串不是空串的子串。
3. 数据类型不能使用 int，因为在运算过程中有可能会出现比最终结果大的数字（比如说rab能够比rabbit匹配更多次）而导致溢出。

```C++
// 2020-09-15 submission
// ?/? cases passed
// Runtime: 12 ms, faster than 71.06% of C++ online submissions.
// Memory Usage: 7 MB, less than 83.59% of C++ online submissions.
class Solution {
public:
    int numDistinct(string s, string t) {
        int c1 = s.length(), c2 = t.length();
        vector<long> dp(c1 + 1, 1); // why long type

        int last_valid = 0;
        for (int i = 1; i <= c2; i++) {
            last_valid = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= c1; j++) {
                int temp = dp[j];
                dp[j] = dp[j-1] + (s[j-1] == t[i-1] ? last_valid : 0);
                last_valid = temp;
            }
        }
        return dp[c1];
    }
};
```

## 118. Pascal's Triangle

杨辉三角生成

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0) return ret;
        ret.push_back(vector<int>{1});
        if(numRows == 1) return ret;

        ret.push_back(vector<int>{1, 1});
        for(int i = numRows - 2; i > 0; i--) {
            ret.push_back(getNext(ret.back()));
        }
        return ret;
    }

    vector<int> getNext(vector<int>& curr) {
        vector<int> ret;
        ret.push_back(1);
        for(size_t i = 0; i < curr.size()-1; i++) {
            ret.push_back(curr[i] + curr[i+1]);
        }
        ret.push_back(1);
        return ret;
    }
};
```

## 119. Pascal's Triangle II

给出第 n 行杨辉三角

```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        for(int num = 1; num < rowIndex + 1; num++) {
            int64_t last = ret.back();
            int64_t to_push = last * (rowIndex+1-num) / num;
            ret.push_back(to_push);
        }
        return ret;
    }
};
```

## 142. Linked List Cycle II

解题思路

1. 先通过双指针法确定是否存在环，并且获取到环上的某点。
2. 找出这个环一共有几个节点(从重合的节点开始遍历一圈得到环中的节点数)
3. 从头开始设置快慢指针，快指针先移动环的节点数步，然后快慢指针一起移动。当快慢指针重合时，指向的节点就表示环的入口节点。（其实就是就是快慢指针都刚好走了一圈）

```C++
// 2020-09-17 submission
// ?/? cases passed
// Runtime: 12 ms, faster than 68.48% of C++ online submissions.
// Memory Usage: 7.9 MB, less than 33.42% of C++ online submissions.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) { // find the loop
                ListNode* new_fast = head->next, *new_slow = head;
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

## 152. Maximum Product Subarray

最大子乘积数组

```C++
// 2018-09-26 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 84.86% of C++ online submissions.
// Memory Usage: 11.9 MB, less than 7.74% of C++ online submissions.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> plus(nums.size(), 0);
        vector<int> minus(nums.size(), 0);
        int maxValue = nums[0];
        nums[0]>=0 ? plus[0]=nums[0] : minus[0]=nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 0) plus[i] = minus[i] = 0;
            else if(nums[i] > 0) {
                minus[i] = minus[i-1] * nums[i];
                plus[i] = plus[i-1]==0 ? nums[i] : (plus[i-1]*nums[i]);
            }
            else {
                plus[i] = minus[i-1] * nums[i];
                minus[i] = plus[i-1]==0 ? nums[i] : (plus[i-1]*nums[i]);
            }
            maxValue = maxValue>plus[i] ? maxValue : plus[i];
        }
        return maxValue;
    }
};
```

## 153. Find Minimum in Rotated Sorted Array

解题思路

1. 这里用中间的值 nums[mid] 和右边界值 nums[right] 进行比较，若数组没有旋转或者旋转点在左半段的时候，中间值是一定小于右边界值的，所以要去左半边继续搜索，反之则去右半段查找，最终返回 nums[right] 即可

```C++
// 2021-03-18 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 10.2 MB, less than 43.53% of C++ online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
```

## 154. Find Minimum in Rotated Sorted Array II

```C++
// 2021-03-18 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 94.90% of C++ online submissions.
// Memory Usage: 12.2 MB, less than 93.44% of C++ online submissions.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r) {
            while (l < r && nums[l] == nums[r]) ++l;
            mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
```

## 188. Best Time to Buy and Sell Stock IV

解题思路

1. 题目描述：买进前必须卖出手头已有的；允许最多$k$次交易
2. 维护两个变量：全局最优 ***global*** 和局部最优 ***local***。定义局部最优$\it{local}[i][j]$为在到达第$i$天时最多可进行$j$次交易并且最后一次交易在最后一天卖出的最大利润,全局最优$\it{global}[i][j]$为在到达第$i$天时最多可进行$j$次交易的最大利润。
3. 递推式为
$$local[i][j] = max(global[i - 1][j - 1] + max(\it{diff}, 0), local[i - 1][j] + \it{diff})$$
$$global[i][j] = max(local[i][j], global[i - 1][j])$$
其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值后相比，两者之中取较大值，而全局最优比较局部最优和前一天的全局最优。
4. 上面的算法中对于天数需要一次扫描，而每次要对交易次数进行递推式求解，所以时间复杂度是$O(n*k)$，如果是最多进行两次交易，那么复杂度还是$O(n)$。空间上只需要维护当天数据皆可以，所以是$O(k)$，当k=2，则是$O(1)$。
5. 为了减少运算次数，当$k$远大于天数时，按照 **122. Best Time to Buy and Sell Stock II** 中无限次数交易的方法求解。
6. 参见
- Best Time to Buy and Sell Stock III -- LeetCode_Code Ganker-CSDN博客_best time to buy and sell stock iii https://blog.csdn.net/linhuanmars/article/details/23236995
- [LeetCode] Best Time to Buy and Sell Stock IV 买卖股票的最佳时间之四 - Grandyang - 博客园 https://www.cnblogs.com/grandyang/p/4295761.html

不明白的事情

1. 为什么要j从k遍历到1，而不是1遍历到k
2. 为什么局部最优第二个加项里面可以直接加diff

```C++
// 2020-07-24 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 99.86% of C++ online submissions.
// Memory Usage: 12 MB, less than 87.45% of C++ online submissions.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k > prices.size()) return maxProfit_largetrades(prices);
        vector<int> local(k+1, 0), global(k+1, 0);
        for (int day = 1; day < prices.size(); day++) {
            int diff = prices[day] - prices[day-1];
            for (int j = k; j >= 1; j--) {
                local[j] = max(global[j-1]+max(diff, 0), local[j]+diff);
                global[j] = max(local[j], global[j]);
                // cout << "day:" << day << " j:" << j << " local:"<<local[j] << " global:" << global[j] << endl;
            }
        }
        return global[k];
    }

    int maxProfit_largetrades(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                maxValue += (prices[i]-prices[i-1]);
        }
        return maxValue;
    }
};
```

## 213. House Robber II

解题思路

1. 动态规划：房子围成环后，可以发现第一家和最后一家不能同时抢，恰好分解为两个子问题：分别计算去掉第一家和最后一家后能抢到的最大值，对两个极大值取最大即为所求。

```C++
// 2020-11-04 submission
// ?/? cases passed
// Runtime: 0 ms, faster than 100.00% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 5.25% of C++ online submissions.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }

    int helper(vector<int>& nums, int s, int e) {
        vector<int> dp;
        if (e - s >= 1) dp.push_back(nums[s]);
        if (e - s >= 2) dp.push_back(nums[s+1]);
        if (e - s >= 3) dp.push_back(nums[s] + nums[s+2]);
        for (int i = 3; i < e - s; i++) {
            dp.push_back(max(dp[i-2], dp[i-3]) + nums[s+i]);
        }
        // cout << *max_element(dp.begin(), dp.end()) << endl;
        return *max_element(dp.begin(), dp.end());
    }
};
```

## 217. Contains Duplicate

解题思路

1. 题目描述：对于数组(array)，判断是否重复值
2. hashset

```C++
// 2019-09-17 submission
// ?/? cases passed
// Runtime: 64 ms, faster than 79.78% of C++ online submissions.
// Memory Usage: 20 MB, less than 69.02% of C++ online submissions.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.count(nums[i])) return true;
            else st.insert(nums[i]);
        }
        return false;
    }
};
```

## 231. Power of Two

```C++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};
```

## 279. Perfect Squares

解题思路

1. 动态规划：i 从 0 循环到 n，j 从 1 循环到 $i + j*j <= n$ 的位置，然后每次更新 dp[i+j*j] 的值，动态更新 dp 数组，其中 dp[i] 表示正整数i能少能由多个完全平方数组成。
2. 四平方和定理：每个正整数均可表示为不超过4个完全平方数的和。 因为任何数加上0²都不变。所以对于不够4个完全平方数的可以用0²补齐，于是四平方和定理等价为：任意一个正整数都可以写成4个完全平方数的和。
    规则1：如果这个数对4取余得0，可以把4除去（易知，这个过程可以不断重复），不影响结果；
    规则2：对4取余结束后，如果这个数对8取余得7，则这个数是四个完全平方数的和；
    根据规则1，先对这个数不断除4，然后根据规则2，如果这个数对8取余得7，则结果是4，否则，结果是1，2，3中的一个。显然，1，2很容易验证，若都不是那么就一定是3了。

```C++
// 2020-12-10 submission
// ?/? cases passed
// Runtime: 220 ms, faster than 59.84% of C++ online submissions.
// Memory Usage: 9.4 MB, less than 58.61% of C++ online submissions.
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i){
            for(int j = 1; i + j * j <= n; ++j){
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
```

```C++
// 2020-12-10 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 97.60% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 87.50% of C++ online submissions.
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};
```

## 295. Find Median from Data Stream

解题思路

1. 最大堆和最小堆：新插入的数据先插入最小堆，然后将堆顶弹出插入最大堆。

```C++
// 2021-03-17 submission
// ?/? cases passed
// Runtime: 112 ms, faster than 39.98% of C++ online submissions.
// Memory Usage: 46.8 MB, less than 33.66% of C++ online submissions.
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if ((small.size() + big.size()) % 2 == 0) {
            small.push(num);
            big.push(small.top());
            small.pop();
        } else {
            big.push(num);
            small.push(big.top());
            big.pop();
        }
    }

    double findMedian() {
        if ((small.size() + big.size()) % 2 == 0) {
            return ((double)small.top() + big.top()) / 2;
        } else {
            return big.top();
        }
    }

    priority_queue<int, vector<int>, less<int> > big;
    priority_queue<int, vector<int>, greater<int> > small;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```


## 322. Coin Change (2020-11-25)

1. 动态规划：维护一个一维动态数组 dp，其中 dp[i] 表示钱数为i时的所需最少找零数。因为最小的硬币是1，所以 amount 最多需要 amount 个硬币，不可以用 INT_MAX 初始化，因为之后 +1 操作会溢出。状态转移方程为 $dp[i] = min(dp[i], dp[i - coins[j]] + 1)$
2. 递归+记忆数组：思路同上
3. 暴力搜索+剪枝：首先排序硬币数组，然后从最大硬币开始，尽可能取到最多，然后对于次一级的硬币进行递归。剪枝策略是若当前硬币数已超过最小值，停止检索并返回。

```C++
// 2020-11-25 submission (动态规划)
// Runtime: 108 ms, faster than 55.71% of C++ online submissions.
// Memory Usage: 14.3 MB, less than 49.21% of C++ online submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // dp[i] 表示amount为i时所需最少找零数，显然dp[i]<=i
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > i) continue;
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

```C++
// 2020-11-25 submission (递归+记忆数组)
// Runtime: 124 ms, faster than 34.31% of C++ online submissions.
// Memory Usage: 15.1 MB, less than 21.50% of C++ online submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        return coinChangeDFS(coins, amount, memo);
    }
    int coinChangeDFS(vector<int>& coins, int target, vector<int>& memo) {
        if (target < 0) return - 1;
        if (memo[target] != INT_MAX) return memo[target];
        for (int i = 0; i < coins.size(); ++i) {
            int tmp = coinChangeDFS(coins, target - coins[i], memo);
            if (tmp >= 0) memo[target] = min(memo[target], tmp + 1);
        }
        return memo[target] = (memo[target] == INT_MAX) ? -1 : memo[target];
    }
};
```

```C++
// 2020-11-25 submission (暴力搜索+剪枝)
// Runtime: 4 ms, faster than 99.91% of C++ online submissions.
// Memory Usage: 10.2 MB, less than 88.97% of C++ online submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX, n = coins.size();
        sort(coins.begin(), coins.end());
        helper(coins, n - 1, amount, 0, res);
        return (res == INT_MAX) ? -1 : res;
    }
    void helper(vector<int>& coins, int start, int target, int cur, int& res) {
        if (start < 0) return;
        if (target % coins[start] == 0) {
            res = min(res, cur + target / coins[start]);
            return;
        }
        for (int i = target / coins[start]; i >= 0; --i) {
            if (cur + i >= res - 1) break;
            helper(coins, start - 1, target - i * coins[start], cur + i, res);
        }
    }
};
```

## 391. Perfect Rectangle

解题思路

1. hash: 可以发现所有顶点除了边缘四个角，剩下的要么出现两次要么出现四次。最后还需要计算所有矩形面积是否等于整体矩形面积（避免重叠）
2. 位操作：对于矩形的四个顶点，按照左下，左上，右上，右下的顺序来给顶点标号为1(0001)，2(0010)，4(0100)，8(1000)。判定条件是，当一个点是某一个矩形的左下顶点时，这个点就不能是其他矩形的左下顶点了，这个条件对于这四种顶点都要成立。
   ![391. 不同类型的点](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-391._不同类型的点.png)
   通过分析，每个点只能是蓝，绿，红三种情况的一种，其中蓝的情况是 mask 的四位中只有一个 1，分别就是 1(0001)，2(0010)，4(0100)，8(1000)，而且蓝点只能有四个；那么对于T型的绿点，mask的四位中有两个1，那么就有六种情况，分别是12(1100), 10(1010), 9(1001), 6(0110), 5(0101), 3(0011)；而对于红点，mask的四位都是1，只有一种情况15(1111)，那么我们可以通过直接找mask是1，2，4，8的个数，也可以间接通过找不是绿点和红点的个数，看是否是四个。最后一个判定条件是每个矩形面积累加和要等于最后的大矩形的面积.。

边缘条件

1. 大矩形中间套两个重叠的小矩形

```C++
// 2020-12-10 submission
// ?/? cases passed
// Runtime: 272 ms, faster than 45.91% of C++ online submissions.
// Memory Usage: 37.5 MB, less than 15.46% of C++ online submissions.
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        unordered_map<string, int> m;
        int min_w = INT_MAX, max_w = 0, min_h = INT_MAX, max_h = 0;
        int res_area = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            min_w = min(min_w, rectangles[i][0]);
            max_w = max(max_w, rectangles[i][2]);
            min_h = min(min_h, rectangles[i][1]);
            max_h = max(max_h, rectangles[i][3]);
            m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][1])]++;
            m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][3])]++;
            m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][1])]++;
            m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][3])]++;
            res_area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }

        unordered_set<string> angle{to_string(min_w) + "_" + to_string(min_h),
                                    to_string(min_w) + "_" + to_string(max_h),
                                    to_string(max_w) + "_" + to_string(min_h),
                                    to_string(max_w) + "_" + to_string(max_h)};
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (angle.count(it->first)) {
                if (it->second != 1) return false;
            }
            else {
                if (!(it->second == 2 || it->second == 4)) return false;
            }
        }
        return res_area == (max_w-min_w)*(max_h-min_h);
    }
};
```

```C++
// 2020-12-10 submission
// ?/? cases passed
// Runtime: 256 ms, faster than 55.00% of C++ online submissions.
// Memory Usage: 38.6 MB, less than 12.27% of C++ online submissions.
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> m;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0, cnt = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[1]), 1)) return false; // bottom-left
            if (!isValid(m, to_string(rect[0]) + "_" + to_string(rect[3]), 2)) return false; // top-left
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[3]), 4)) return false; // top-right
            if (!isValid(m, to_string(rect[2]) + "_" + to_string(rect[1]), 8)) return false; // bottom-right
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            int t = it->second;
            if (t != 15 && t != 12 && t != 10 && t != 9 && t != 6 && t != 5 && t!= 3) {
                ++cnt;
            }
        }
        return cnt == 4 && area == (max_x - min_x) * (max_y - min_y);
    }

    bool isValid(unordered_map<string, int>& m, string corner, int type) {
        int& val = m[corner];
        if (val & type) return false;
        val |= type;
        return true;
    }
};
```


## 743. Network Delay Time

解题思路

1. 题目描述：网络中传播到所有节点所需时间，即求单源最短路径，使用dijkstra算法。注意是带权重的有向图。
2. Dijkstra 算法处理有向权重图时，权重必须为正。

```C++
// 2021-04-18 submission
// ?/? cases passed
// Runtime: 100 ms, faster than 91.40% of C++ online submissions.
// Memory Usage: 37.3 MB, less than 90.33% of C++ online submissions.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > dist(n, vector<int>(n, -1));
        for (vector<int>& edge : times) {
            dist[edge[0]-1][edge[1]-1] = edge[2];
            // dist[edge[1]-1][edge[0]-1] = edge[2];
        }

        // djkstra algorithm
        vector<int> shortest(n, INT_MAX);
        unordered_set<int> added;
        shortest[k-1] = 0;
        int cnt = 0;
        while (cnt < n) {

            int cur_min = INT_MAX, cur_idx = 0;
            for (int i = 0; i < n; i++) {
                if (!added.count(i) && cur_min > shortest[i]) {
                    cur_idx = i;
                    cur_min = shortest[i];
                }
            }
            if (cur_min == INT_MAX) return -1;

            added.insert(cur_idx);
            for (int i = 0; i < n; i++) {
                if (!added.count(i) && dist[cur_idx][i] >= 0 && shortest[i] > shortest[cur_idx] +  dist[cur_idx][i]) {
                    shortest[i] = shortest[cur_idx] +  dist[cur_idx][i];
                }
            }

            ++cnt;
        }
        return *max_element(shortest.begin(), shortest.end());
    }
};
```

## 763. Partition Labels

解题思路

1. 一旦某个字母多次出现了，那么其最后一个出现位置必须要在当前子串中。建立一个 HashMap 来建立字母和其最后出现位置之间的映射

```C++
// 2021-03-17 submission
// ?/? cases passed
// Runtime: 4 ms, faster than 83.01% of C++ online submissions.
// Memory Usage: 6.8 MB, less than 64.91% of C++ online submissions.
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        for (int i = 0; i < S.length(); i++) {
            m[S[i]] = i;
        }

        vector<int> res;
        int last = 0, prev = -1;
        for (int i = 0; i < S.length(); i++) {
            last = max(last, m[S[i]]);
            if (last == i) {
                res.push_back(last - prev);
                prev = last;
            }
        }
        return res;
    }
};
```

1.   Binary Tree Postorder Traversal
解题思路：后续遍历-递归或迭代
（迭代）使用栈实现。最开始将根节点压入栈。迭代开始时每次取出栈顶节点，如果当前节点为叶节点或者子树节点为之前弹出节点head，则认为当前节点需要加入输出集，弹出当前节点并标记为head；如果不是则将当前节点右子树和左子树压入栈（注意栈先入后出的特性）。head初始化可以初始化为root，但是绝对不能为空，因为有可能会出现节点只有左子树或者右子树的情况，这样会直接弹出当前节点，这明显不符合情况。

// 2020-07-17 submission
// ?/? cases passed
(recursive )
Runtime: 4 ms, faster than 51.58% of C++ online submissions
Memory Usage: 8.7 MB, less than 26.67% of C++ online submissions
(iterative)
Runtime: 0 ms, faster than 100.00% of C++ online submissions
Memory Usage: 8.6 MB, less than 51.02% of C++ online submissions
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        iterate(root, res);
        return res;

    }

    void iterate(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        TreeNode* head = root;
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            if ((!cur->left && !cur->right) || cur->left==head || cur->right==head) {
                res.push_back(cur->val);
                stk.pop();
                head = cur;
            }
            else {
                if (cur->right) stk.push(cur->right);
                if (cur->left) stk.push(cur->left);
            }
        }
    }

    void recursive(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        recursive(root->left, res);
        recursive(root->right, res);
        res.push_back(root->val);
    }
};

## 228. Summary Ranges (2020-10-29)

解题思路

1. 用一个 nx2 的数组维护范围，若新数大于范围数组最后一个的右边界，就开辟新范围。

边界条件

1. $b - a <= 1$ 应写成 $a + 1 >= b$，防止溢出

```C++
// 2020-10-29 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Summary Ranges.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        vector<vector<int> > helper{vector<int>{nums[0], nums[0]}};
        for (int i = 1; i < nums.size(); i++) {
            // if (nums[i] - nums[i-1] <= 1) helper[helper.size()-1][1] = nums[i];
            if (nums[i-1] + 1 >= nums[i]) helper[helper.size()-1][1] = nums[i];
            else helper.push_back(vector<int>{nums[i], nums[i]});
        }
        for (int i = 0; i < helper.size(); i++) {
            if(helper[i][0] == helper[i][1]) res.push_back(to_string(helper[i][0]));
            else res.push_back(to_string(helper[i][0]) + "->" + to_string(helper[i][1]));
        }
        return res;
    }
};
```

## 673. Number of Longest Increasing Subsequence (2020-10-31)

解题思路

1. 题目描述：求最长递增序列的个数
2. 动态规划：用两个数组 len[i] 和 nums[i] 分别维护以当前位置为最末端的最长序列长度和最长序列长度的个数，因为一个数的长度为1，所以数组初始化为 1。遍历数组，对于每个遍历到的数字 nums[i]，再遍历其之前的所有数字 nums[j]，当 nums[i] 小于等于 nums[j] 时，不做任何处理，因为不是递增序列；反之，则判断 len[i] 和 len[j] 的关系，如果 len[i] 等于 len[j] + 1，说明 nums[i] 这个数字可以加在以 nums[j] 结尾的递增序列后面，并且以 nums[j] 结尾的递增序列个数可以直接加到以 nums[i] 结尾的递增序列个数上。如果 len[i] 小于 len[j] + 1，说明找到了一条长度更长的递增序列，那么此时将 len[i] 更新为 len[j]+1，并且原本的递增序列都不能用了，直接用 cnt[j] 来代替。在更新完 len[i] 和 cnt[i] 之后，要更新 mx 和结果 res，如果 mx 等于 len[i]，则把 cnt[i] 加到结果 res 之上；如果 mx 小于 len[i]，则更新 mx 为 len[i]，更新结果 res 为 cnt[i]。

边界条件

1. 序列为空
2. 序列只有一个数字

```C++
// 2020-10-31 submission
// Runtime: 132 ms, faster than 17.64% of C++ online submissions for Number of Longest Increasing Subsequence.
// Memory Usage: 13.5 MB, less than 8.09% of C++ online submissions for Number of Longest Increasing Subsequence.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> count(nums.size(), 1);
        vector<int> max_length(nums.size(), 1);
        int res_count = 0;
        int res_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (max_length[j] + 1 > max_length[i]) {
                    max_length[i] = max_length[j] + 1;
                    count[i] = 0;
                }
                if (max_length[j] + 1 == max_length[i]) {
                    count[i] += count[j];
                }
            }
            res_length = max(max_length[i], res_length);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (max_length[i] == res_length)
                res_count += count[i];
        }
        return res_count;
    }
};
```

## 147. Insertion Sort List (2020-11-03)

```C++
// 2020-11-03 submission
// Runtime: 48 ms, faster than 72.31% of C++ online submissions for Insertion Sort List.
// Memory Usage: 10.2 MB, less than 6.04% of C++ online submissions for Insertion Sort List.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

## 1026. Maximum Difference Between Node and Ancestor (2020-11-10)

解题思路

1. 前序遍历：在递归函数中传递两个值，分别存储当前分支的最小值和最大值。

```C++
// 2020-11-10 submission
// Runtime: 4 ms, faster than 96.88% of C++ online submissions for Maximum Difference Between Node and Ancestor.
// Memory Usage: 11.4 MB, less than 5.86% of C++ online submissions for Maximum Difference Between Node and Ancestor.
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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        if(root) maxAncestorDiff(root, root->val, root->val, res);
        return res;
    }

    void maxAncestorDiff(TreeNode* root, int min_val, int max_val, int& res) {
        if (!root) return;
        res = max(max(abs(root->val-min_val), abs(max_val-root->val)), res);
        maxAncestorDiff(root->left, min(min_val, root->val), max(max_val, root->val), res);
        maxAncestorDiff(root->right, min(min_val, root->val), max(max_val, root->val), res);
    }
};
```

## 832. Flipping an Image (2020-11-11)

解题思路

1. 新建一个跟 A 一样长的二维数组，里面的各行是空的。然后我们遍历 A 数组的各行，但在遍历各行上的数字时，我们采用从后往前的遍历顺序，然后对于每个数字取反在加入结果 res 中，这样直接将翻转和取反同时完成。

```C++
// 2020-11-11 submission
// Runtime: 4 ms, faster than 98.93% of C++ online submissions for Flipping an Image.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Flipping an Image.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = (int)A[i].size() - 1; j >= 0; --j) {
                res[i].push_back(!A[i][j]);
            }
        }
        return res;
    }
};
```

## 938. Range Sum of BST (2020-11-16)

```C++
// 2020-11-16 submission
// Runtime: 160 ms, faster than 97.72% of C++ online submissions for Range Sum of BST.
// Memory Usage: 65.3 MB, less than 35.01% of C++ online submissions for Range Sum of BST.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val < low) return rangeSumBST(root->right, low, high);
        if (root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, root->val-1) + rangeSumBST(root->right, root->val+1, high);
    }
};
```

## 858. Mirror Reflection (2020-11-18)

解题思路

1. 题目描述：激光被镜面反射，最终会被哪个接收器接收。
2. 题目必定有解，即令 $nq / p = c $，其中 $n,q,p,c$ 均是大于 0 的正整数。
3. 分类讨论 \(n\) 和 \(c\):
   + \(n\) 为奇数，\(c\) 为奇数：返回 1
   + \(n\) 为奇数，\(c\) 为偶数：返回 0
   + \(n\) 为偶数，\(c\) 为奇数：返回 2
   + \(n\) 为偶数，\(c\) 为偶数：\(n\) 和 \(c\) 都除以 2 直至上面三种情况。
4. 继而讨论 \(p\) 和 \(q\):
   + \(p\) 为奇数，\(q\) 为奇数时: 到达接收器1。
   + \(p\) 为奇数，\(q\) 为偶数时: 到达接收器0。
   + \(p\) 为偶数，\(q\) 为奇数时: 到达接收器2。

```C++
// 2020-11-18 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Mirror Reflection.
// Memory Usage: 6.3 MB, less than 14.95% of C++ online submissions for Mirror Reflection.
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2; q /= 2;
        }
        return 1 - p % 2 + q % 2;
    }
};
```

## 229. Majority Element II (2020-11-19)

解题思路

1. 题目描述：求出现次数大于 n/3 的数字，而且限定空间复杂度为 O(1)。
2. 任意一个数组出现次数大于 n/3 的数最多有两个。证明：如果有超过两个，也就是至少三个数字满足“出现的次数大于 n/3”，那么就意味着数组里总共有超过 3*(n/3) = n 个数字，这与已知的数组大小矛盾
3. 多数投票法：找出两个候选数进行投票，需要两遍遍历，第一遍历找出两个候选数，第二遍遍历重新投票验证这两个候选数是否符合题意

```C++
// 2020-11-19 submission
// Runtime: 28 ms, faster than 76.33% of C++ online submissions for Majority Element II.
// Memory Usage: 16.2 MB, less than 7.61% of C++ online submissions for Majority Element II.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
            else if (cnt1 == 0) { a = num; cnt1 = 1; }
            else if (cnt2 == 0) { b = num; cnt2 = 1; }
            else { --cnt1; --cnt2; }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == a) ++cnt1;
            else if (num == b) ++cnt2;
        }
        if (cnt1 > n / 3) res.push_back(a);
        if (cnt2 > n / 3) res.push_back(b);
        return res;
    }
};
```

## 415. Add Strings (2020-11-21)

解题思路

1. 题目描述：字符串加法

Follow up

1. 字符串减法
2. 字符串中有小数点和负号如何做加法

```C++
// 2020-11-21 submission
// Runtime: 4 ms, faster than 82.85% of C++ online submissions for Add Strings.
// Memory Usage: 6.9 MB, less than 79.86% of C++ online submissions for Add Strings.
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string res = "";
        int max_len = max(num1.length(), num2.length());
        for (int i = 1; i <= max_len; i++) {
            if (i <= num1.length()) carry += (num1[num1.length()-i] - '0');
            if (i <= num2.length()) carry += (num2[num2.length()-i] - '0');
            res.append(1, '0' + carry % 10);
            carry /= 10;
        }
        if (carry) res.append(1, '0' + carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 396. Rotate Function (2020-11-22)

解题思路

1. 找规律：先把具体的数字抽象为A,B,C,D，则有
   F(0) = 0A + 1B + 2C +3D
   F(1) = 0D + 1A + 2B +3C
   F(2) = 0C + 1D + 2A +3B
   F(3) = 0B + 1C + 2D +3A
   对应得到以下规律：
   得出下面的规律：
   sum = 1A + 1B + 1C + 1D
   F(1) = F(0) + sum - 4D
   F(2) = F(1) + sum - 4C
   F(3) = F(2) + sum - 4B
   综上可得 $F(i) = F(i-1) + \text{sum} - n*A[n-i]$

边界条件

1. [2147483647,2147483647]

```C++
// 2020-11-22 submission
// Runtime: 12 ms, faster than 89.46% of C++ online submissions for Rotate Function.
// Memory Usage: 11.2 MB, less than 67.17% of C++ online submissions for Rotate Function.
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 2) return *max_element(A.begin(), A.end());
        int cur = 0, sum = 0;
        for (int i = 0; i < A.size(); i++) {
            cur += (i * A[i]);
            sum += A[i];
        }
        int res = cur;
        for (int i = 1; i < A.size(); i++) {
            cur = cur + sum - A.size() * A[A.size()-i];
            res = max(res, cur);
        }
        return res;
    }
};
```

## 337. House Robber III (2020-11-23)

解题思路

1. 题目描述：抢劫树状房屋，相邻屋子不可以同时抢，求抢劫最大收获
2. 树形dp：dp[i][0]表示不选这个节点子树的最大价值，dp[i][1]表示选这个节点的子树最大价值，不选时儿子节点可以选或者不选，选时儿子节点必须不选。状态转移方程为
   $$
   \begin{aligned}
   dp[x, 0] &=\sum_{s \in \operatorname{Son}(x)} \max (dp[s, 0], d p[s, 1]) \\
   dp[x, 1] &=h[x]+\sum_{s \in \operatorname{Son}(x)} d p[s, 0]
   \end{aligned}
   $$
3. helper 函数返回当前结点为根结点的最大 rob 的钱数，里面的两个参数 l 和 r 表示分别从左子结点和右子结点开始 rob，分别能获得的最大钱数。在递归函数里面，如果当前结点不存在，直接返回0。否则对左右子结点分别调用递归函数，得到l和r。另外还得到四个变量，ll 和 lr 表示左子结点的左右子结点的最大 rob 钱数，rl 和 rr 表示右子结点的最大 rob 钱数。那么最后返回的值其实是两部分的值比较，其中一部分的值是当前的结点值加上 ll, lr, rl, 和 rr 这四个值，因为抢了当前的房屋，则左右两个子结点就不能再抢了，但是再下一层的四个子结点都是可以抢的；另一部分是不抢当前房屋，而是抢其左右两个子结点，即 l+r 的值，返回两个部分的值中的较大值即可

```C++
// 2020-11-23 submission
// Runtime: 24 ms, faster than 57.71% of C++ online submissions for House Robber III.
// Memory Usage: 26.9 MB, less than 25.93% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        vector<vector<int>> dp;
        if (root) helper(root, dp);
        else return 0;
        return max(dp.back()[0], dp.back()[1]);
    }

    void helper(TreeNode* root, vector<vector<int>>& dp) {
        int do_rob = 0, not_rob = 0;
        if (root->left) {
            helper(root->left, dp);
            do_rob += dp.back()[1];
            not_rob +=max(dp.back()[0], dp.back()[1]);
        }
        if (root->right) {
            helper(root->right, dp);
            do_rob += dp.back()[1];
            not_rob += max(dp.back()[0], dp.back()[1]);
        }
        // cout << root->val << " " << do_rob + root->val << " " << not_rob << endl;
        dp.push_back(vector<int>{do_rob + root->val, not_rob});
    }
};
```

```C++
// 2020-11-23 submission
// Runtime: 12 ms, faster than 94.84% of C++ online submissions for House Robber III.
// Memory Usage: 22.7 MB, less than 58.85% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        int x = 0, y = 0;
        helper(root, x, y);
        return max(x, y);
    }

    void helper(TreeNode* root, int& do_rob, int& not_rob) {
        int cur_do_rob = 0, cur_not_rob = 0;
        if (root->left) {
            helper(root->left, do_rob, not_rob);
            cur_do_rob += not_rob;
            cur_not_rob += max(do_rob, not_rob);
        }
        if (root->right) {
            helper(root->right, do_rob, not_rob);
            cur_do_rob += not_rob;
            cur_not_rob += max(do_rob, not_rob);
        }
        do_rob = cur_do_rob + root->val;
        not_rob = cur_not_rob;
    }
};
```

```C++
// 2020-11-23 submission
// Runtime: 12 ms, faster than 94.84% of C++ online submissions for House Robber III.
// Memory Usage: 22.6 MB, less than 84.04% of C++ online submissions for House Robber III.
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
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }
    int helper(TreeNode* node, int& l, int& r) {
        if (!node) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};
```

## 804. Unique Morse Code Words (2020-11-24)

```C++
// 2020-11-24 submission
// Runtime: 4 ms, faster than 91.90% of C++ online submissions for Unique Morse Code Words.
// Memory Usage: 9 MB, less than 37.21% of C++ online submissions for Unique Morse Code Words.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encode_map{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> hash_set;
        int res = 0;
        for (string word : words) {
            string tmp = "";
            for (char c : word) {
                tmp += encode_map[c - 'a'];
            }
            if (!hash_set.count(tmp)) {
                res++;
                hash_set.insert(tmp);
            }
        }
        return res;
    }
};
```

## 1015. Smallest Integer Divisible by K (2020-11-27)

解题思路

1. 题目描述：给定正整数 K，求最小的能整除 K 的正整数 n，n只包含1，形如 1,11,111
2. 枚举：不需要每次都使用 n 位的 1 对 K 取余，只需要取上次运算得到结果*10+1再对K取余。其次，运算截止到 K 次，因为对 K 的余数不包括 0 的话有 K-1 个，根据抽屉原理其中必有两个相等的，即是说到达第K次时一定开始了重复循环。

```C++
// 2020-11-27 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
// Memory Usage: 6.2 MB, less than 54.12% of C++ online submissions for Smallest Integer Divisible by K.
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int last = 0;
        for (int i = 1; i <= K; i++) {
            last = (last * 10 + 1) % K;
            if (last == 0) return i;
        }
        return -1;
    }
};
```

## 211. Design Add and Search Words Data Structure (2020-12-01)

解题思路

1. 前缀树+BFS/DFS：前缀树实现参见 ## 208. Implement Trie (Prefix Tree)。由于加入了 '.'（代替任意字符），就需要查找所有的子树，可以用 DFS 或者 BFS 实现。

Follow up

1. 如果使用 '*'（代替任意多个字符）

```C++
// 2020-12-01 submission (前缀树+BFS)
// Runtime: 132 ms, faster than 53.20% of C++ online submissions for Design Add and Search Words Data Structure.
// Memory Usage: 60.7 MB, less than 32.16% of C++ online submissions for Design Add and Search Words Data Structure.
class Trie_Node{
public:
    Trie_Node* child[26];
    bool is_word;
    Trie_Node() {
        is_word = false;
        for (auto& ptr : child) {
            ptr = NULL;
        }
    }
};

class WordDictionary {
public:
    Trie_Node* root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie_Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie_Node* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if(!cur->child[word[i]-'a']) {
                cur->child[word[i]-'a'] = new Trie_Node();
            }
            cur = cur->child[word[i]-'a'];
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<Trie_Node*> q;
        q.push(root);
        int cur_size = 0;
        for (int i = 0; i < word.length(); i++) {
            if (q.empty()) return false;
            cur_size = q.size();
            for (int j = 0; j < cur_size; j++) {
                Trie_Node* cur = q.front(); q.pop();
                if (word[i] == '.') {
                    for (auto ptr : cur->child) {
                        if (ptr) q.push(ptr);
                    }
                }
                else if (cur->child[word[i]-'a']) q.push(cur->child[word[i]-'a']);
            }
        }
        while (!q.empty()) {
            if (q.front()->is_word) return true;
            q.pop();
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

```C++
// 2020-12-01 submission (前缀树+DFS)
// Runtime: 84 ms, faster than 95.74% of C++ online submissions for Design Add and Search Words Data Structure.
// Memory Usage: 46.6 MB, less than 39.48% of C++ online submissions for Design Add and Search Words Data Structure.
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

### 382. Linked List Random Node (2020-12-03)

解题思路

1. 水塘抽样：首先让返回值等于 head 的值，并记录当前遍历过的节点数量 cnt。每遍历到一个新的节点时，就从 [0, cnt] 中取随机数 k，如果 k 为 0 就让返回值为当前节点值。

```C++
// 2020-12-03 submission
// Runtime: 32 ms, faster than 75.61% of C++ online submissions for Linked List Random Node.
// Memory Usage: 16.9 MB, less than 66.08% of C++ online submissions for Linked List Random Node.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head->next;
        int res = head->val, cnt = 1;
        while(cur) {
            if (rand() % (cnt + 1) == 0) res = cur->val;
            ++cnt;
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

## 897. Increasing Order Search Tree (2020-12-04)

解题思路

1. 当 root 为空时，直接返回空，当 root 没有左右子结点时，也是直接返回 root。当 root 只有一个左子结点时，我们此时要把其左子结点变为根结点，将原来的根结点变成其原来的左子结点的右子结点。但是如果 root 只有一个右子结点，还是保持原来的顺序不变，而若 root 同时具有左右子结点的话，还是要将左子结点变为根结点，然后把之前的根结点连到右子结点上，之前的右子结点还连在之前的根结点上，这个不用改变。我们可以发现，最麻烦的就是左子结点了，需要和其根结点交换位置，所以对于每个结点，我们需要知道其父结点的位置，那么就在递归函数的参数中传入一个 pre 结点，再对左右子结点调用递归函数时，都将其下一个要连接的结点传入，这个 pre 结点可能是当前结点或者当前结点的父结点。
   在递归函数中，首先判空，若当前结点为空的话，直接返回 pre 结点，因为到空结点的时候，说明已经遍历到叶结点的下方了，那么 pre 就是这个叶结点了。由于是中序遍历，所以要先对左子结点调用递归函数，将返回值保存到一个新的结点 res 中，表示的意义是此时 node 的左子树已经全部捋直了，而且根结点就是 res，而且 node 结点本身也被连到了捋直后的左子树下，即此时左子结点和根结点已经完成了交换位子，当然要断开原来的连接，所以将 node->left 赋值为 nullptr。然后再对 node 的右子结点调用递归函数，注意此时的 pre 不能传入 node 本身，而是要传 node 结点的 pre 结点，这是因为右子结点后面要连接的是 node 的父结点，比如兑入下面这例子：

```C++
// 2020-12-04 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Increasing Order Search Tree.
// Memory Usage: 8 MB, less than 67.99% of C++ online submissions for Increasing Order Search Tree.
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
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, nullptr);
    }

    TreeNode* helper(TreeNode* node, TreeNode* pre) {
        if (!node) return pre;
        TreeNode* res = helper(node->left, node);
        node->left = nullptr;
        node->right = helper(node->right, pre);
        return res;
    }
};
```

## 401. Binary Watch (2020-12-05)

解题思路

1. bitset：问题实质求十进制数如果用二进制表示有多少个 ‘1’ 的问题。bitset 类可以将任意进制数转为二进制，而且又用到了count函数，用来统计1的个数。那么时针从0遍历到11，分针从0遍历到59，然后把时针的数组左移6位加上分针的数值，然后统计1的个数，即为亮灯的个数。

```C++
// 2020-12-05 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Watch.
// Memory Usage: 6.8 MB, less than 47.89% of C++ online submissions for Binary Watch.
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};
```

## 605. Can Place Flowers (2020-12-06)

解题思路

1. 长度为 n 的 0 序列最多能放下 (n - 1) / 2 盆花。注意首尾处理。

```C++
// 2020-12-06 submission
// Runtime: 36 ms, faster than 47.15% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.6 MB, less than 67.29% of C++ online submissions for Can Place Flowers.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cur = 1;
        int max_f = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                max_f += (cur - 1) / 2;
                cur = 0;
            }
            else cur++;
        }
        max_f += cur / 2;
        return max_f >= n;
    }
};
```

## 372. Super Pow (2020-12-07)

解题思路

1. 需要自行实现一个求幂函数以防溢出。可以发现 $2^{23} = (2^{2})^{10} * 2^{3}$，所以可以从 b 的最高位开始，算出结果存入res，然后到下一位时，res的十次方再乘以 a 的该位次方再对 1337 取余。
2. 取余规则：
   （1）$ (a \pm b) \% p = (a \% p \pm b \% p) \% p $
   （2）$ (a *b) \% p = (a \% p* b \% p) \% p $
   （3）$ a ^ b \% p = ((a \% p)^b) \% p $
   （4）结合律：$ ((a+b) \% p + c) \% p = (a + (b+c) \% p) \% p $
   （5）$ ((a*b) \% p* c) \% p = (a *(b*c) \% p) \% p $
   （6）交换律：$ (a + b) \% p = (b+a) \% p $
   （7）$ (a *b) \% p = (b* a) \% p $
   （8）分配律：$ ((a +b)\% p *c) \% p = ((a* c) \% p + (b * c) \% p) \% p $

```C++
// 2020-12-07 submission
// Runtime: 32 ms, faster than 15.03% of C++ online submissions for Super Pow.
// Memory Usage: 12 MB, less than 72.73% of C++ online submissions for Super Pow.
class Solution {
public:

    int pow_n(int x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x % 1337;
        return pow_n(x % 1337, y / 2) * pow_n(x % 1337, y - y / 2) % 1337;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); i++) {
            res = (pow_n(res, 10) * pow_n(a % 1337, b[i])) % 1337;
        }
        return res;
    }
};
```

## 393. UTF-8 Validation (2020-12-08)

解题思路

1. 位操作：验证一个数字某几位的方法可以用 !(a & mask ^ target)。用一个指示变量记录当前 UTF-8 所需要记录的字节数，如果指示变量为 0，表示进入了新的一轮识别，需要通过验证判断当前字节数；如果大于0，说明是次字节或次次字节或次次次字节，需要判断是否合法。

```C++
// 2020-12-08 submission
// Runtime: 16 ms, faster than 97.04% of C++ online submissions for UTF-8 Validation.
// Memory Usage: 14.3 MB, less than 80.47% of C++ online submissions for UTF-8 Validation.
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (flag == 0) {
                if (!(data[i] & 0b10000000 ^ 0b00000000)) flag = 0;
                else if (!(data[i] & 0b11100000 ^ 0b11000000)) flag = 1;
                else if (!(data[i] & 0b11110000 ^ 0b11100000)) flag = 2;
                else if (!(data[i] & 0b11111000 ^ 0b11110000)) flag = 3;
                else return false;
            }
            else {
                if (!(data[i] & 0b11000000 ^ 0b10000000)) flag--;
                else return false;
            }
        }
        return flag == 0;
    }
};
```

## 885. Spiral Matrix III (2020-12-09)

解题思路

1. 顺时针走法是按照 [ '→', '↓', '←', '↑', ] 的顺序转向，注意转向时行走步数是按照 $1, 1, 2, 2, 3, 3, 4, 4 ......$ 的规律进行，所以每当遇到 '→' 和 '←' 就需要将行走步数+1。即使走出边缘也无所谓，判断当前位置是否合法，如果不合法继续行走，合法就将当前位置输出，直至走完所有合法位置。

```C++
// 2020-12-09 submission
// Runtime: 20 ms, faster than 97.35% of C++ online submissions for Spiral Matrix III.
// Memory Usage: 12.7 MB, less than 37.30% of C++ online submissions for Spiral Matrix III.
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        int di = 0;

        int cnt = 0, step = 1;
        while (cnt < R * C) {
            for (int j = 0; j < step; j++) {
                if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C) {
                    ++cnt;
                    res.push_back(vector<int>{r0, c0});
                }
                r0 += direction[di][0]; c0 += direction[di][1];
            }
            if (di % 2) ++step;
            di = (di + 1) % 4;
        }
        return res;
    }
};
```

## 941. Valid Mountain Array (2020-12-10)

解题思路

1. 维护一个标志变量表示当前是递增还是递减。如果是递增情况碰到后数大于前数时候，将标志变量设为递减；如果是符合递增（后数大于前数）和递减（后数小于前数）的情况，就继续循环；其他情况都返回错误。

边界条件

1. 递减数列
2. 数组长度小于3

```C++
// 2020-12-10 submission
// Runtime: 52 ms, faster than 71.27% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 22.8 MB, less than 41.97% of C++ online submissions for Valid Mountain Array.
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] >= arr[1]) return false;
        bool up=true;
        for (int i = 1; i < arr.size(); i++) {
            // if (up && arr[i] > arr[i-1]) continue;
            // else if (up && arr[i] < arr[i-1]) up = false;
            // else if (up && arr[i] == arr[i-1]) return false;
            // else if (!up && arr[i] >= arr[i-1]) return false;
            // else if (!up && arr[i] < arr[i-1]) continue;
            // else return false;
            if (up && arr[i] < arr[i-1]) up = false;
            else if (up && arr[i] > arr[i-1] || !up && arr[i] < arr[i-1]) continue;
            else return false;
        }
        return !up;
    }
};
```

## 402. Remove K Digits (2020-12-11)

解题思路

1. 滑动窗口：维护一个滑窗，初始大小为 k。之后右边界每次往右移动1位，在滑窗中寻找最小数并把左边界定位到最小数的下标（如果同时出现多个最小数则取最左边）。可以用双向队列减少重复运算。

```C++
// 2020-12-11 submission
// Runtime: 16 ms, faster than 29.62% of C++ online submissions for Remove K Digits.
// Memory Usage: 7.1 MB, less than 69.56% of C++ online submissions for Remove K Digits.
class Solution {
public:
    string removeKdigits(string num, int k) {
        int s = 0, e = k;
        string res;
        for (; e < num.length(); s++, e++) {
            s = find_d(num, s, e);
            if (!res.empty() || num[s] != '0')
                res.append(1, num[s]);
        }
        return res.empty() ? "0" : res;
    }

    int find_d(string& num, int s, int e) {
        int min_idx = s;
        for (int i = s + 1; i <= e; i++) {
            if (num[min_idx] > num[i]) min_idx = i;
        }
        return min_idx;
    }
};
```

```C++
// 2020-12-11 submission
// Runtime: 4 ms, faster than 87.95% of C++ online submissions for Remove K Digits.
// Memory Usage: 7.6 MB, less than 27.25% of C++ online submissions for Remove K Digits.
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> q;
        string res;
        for (int i = 0; i < num.length(); i++) {
            while (!q.empty() && num[q.back()] > num[i]) q.pop_back();
            q.push_back(i);
            if (i >= k) {
                if (!res.empty() || num[q.front()] != '0')
                    res.append(1, num[q.front()]);
                q.pop_front();
            }
        }
        return res.empty() ? "0" : res;
    }
};
```

## 312. Burst Balloons (2020-12-14)

解题思路

1. 动态规划：定义 $dp[i, j]$ 为将从第 \(i\) 到 \(j\) 个气球全部扎破后得到的最多硬币数，状态转移方程为

   $$
   dp[i, j] = \max_{i \leq k \leq j}(dp[i, k-1] + dp[k+1, j]+nums[i-1]*nums[k]*nums[j+1])
   $$

   其中 \(k\) 表示在区间 $[i, j]$ 中选择气球 \(k\)，先把除了 \(k\) 以外的气球都打破后，最后再打气球 \(k\)。\(k\) 有可能会等于 \(i\) 或者 \(j\)，这种情况下 $dp[i, k-1]$ 和 $dp[k+1, j]$ 无意义，定义为0。
   为了减少运算，在初始数组首尾各插入 1，动态数组也要对应发生变化。

Follow Up

1. 启发式搜索

```C++
// 2020-12-14 submission (动态规划)
// Runtime: 36 ms, faster than 61.75% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.2 MB, less than 26.39% of C++ online submissions for Burst Balloons.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> src{1};
        src.insert(src.end(), nums.begin(), nums.end());
        src.push_back(1);

        int n = nums.size();
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for (int j = 1; j <= n; j++) {
            for (int i = j; i >= 1; i--) {
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + src[i-1]*src[k]*src[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};
```

```C++
// 2020-12-14 submission (启发式搜索)
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Burst Balloons.
// Memory Usage: 8.6 MB, less than 87.47% of C++ online submissions for Burst Balloons.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int base = applyHeuristic(nums);
        return base + applyDP(nums);
    }

    int applyHeuristic(vector<int>& nums) {
        const int n = nums.size() - 2;
        const int maximum = *std::max_element(nums.begin(), nums.end());
        int result = 0;
        int i = 1;
        int j = 2;
        while (j <= n + 1) {
            int a = nums[i - 1];
            int b = nums[i];
            int c = nums[j];
            if (b <= a && b <= c && (a * c * (b + maximum)) >= (b * maximum * (a + c))) {
                result += a * b * c;
                if (i > 1) {
                    --i;
                } else {
                    nums[i] = nums[j];
                    ++j;
                }
            } else {
                ++i;
                nums[i] = nums[j];
                ++j;
            }
        }
        nums.resize(i + 1);
        return result;
    }

    int applyDP(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> dr(n, 0);
        vector<vector<int>> dp(n, dr);
        for (int k = 2; k < n; ++k){
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

## 977. Squares of a Sorted Array (2020-12-16)

解题思路

1. 先找到离 0 最近的数的下标，然后从中间向两边扩散，把小数放入数组开头。
2. 从两边向中间遍历，把大数放入数组末尾。

```C++
// 2020-12-16 submission
// Runtime: 36 ms, faster than 99.83% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 27.1 MB, less than 30.05% of C++ online submissions for Squares of a Sorted Array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.empty()) return vector<int>{};

        int pivot = find_closest(nums, 0);
        vector<int> res{nums[pivot] * nums[pivot]};
        int l = pivot - 1, r = pivot + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (r >= nums.size() || l >= 0 && (nums[l]+nums[r] >= 0)) {
                res.push_back(nums[l] * nums[l]);
                l--;
            }
            else {
                res.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        return res;
    }

    int find_closest(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target && target <= nums[mid+1]) {
                l = r = (abs(target-nums[mid]) <= abs(target-nums[mid+1]) ? mid : mid + 1);
            }
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```

```C++
// 2020-12-16 submission
// Runtime: 52 ms, faster than 79.21% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 26.1 MB, less than 85.41% of C++ online submissions for Squares of a Sorted Array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int l = 0, r = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[l] + nums[r] >= 0) {
                res[i] = nums[r] * nums[r];
                --r;
            }
            else {
                res[i] = nums[l] * nums[l];
                ++l;
            }
        }
        return res;
    }
};
```

## 815. Bus Routes

```C++
// 2021-03-08 submission
// Runtime: 184 ms, faster than 74.13% of C++ online submissions for Bus Routes.
// Memory Usage: 63.2 MB, less than 28.95% of C++ online submissions for Bus Routes.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int> > stop;
        for (int i = 0; i < routes.size(); i++) {
            for (int a : routes[i])
                stop[a].push_back(i);
        }

        queue<int> q;
        q.push(source);
        unordered_set<int> visited_s{source};
        unordered_set<int> visited_r{};
        int cur = 0, res = 1;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                cur = q.front(); q.pop();
                for (int way : stop[cur]) {
                    if (!visited_r.insert(way).second) continue;
                    for (int point : routes[way]) {
                        if (point == target) return res;
                        if (visited_s.insert(point).second) q.push(point);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};
```

## 494. Target Sum

给定一个非负整数数组和一个目标值，给数组中每个数字加上正号或负号，然后求和要和目标值相等。

1. BFS
2. 背包问题
   - `Sum(positive) - Sum(negative) = S`，`Sum(positive)+Sum(negative)=total`，两式相加得 `2 * Sum(positive) = (S+total)`
   - 题目等价于从 nums 里任取若干使其和为（S+total) / 2

```cpp
// 2021-03-21 submission
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> m;
        vector<pair<int, int>> can;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (auto it : m) {
                if (it.second > 0) {
                    can.push_back(make_pair(it.first+nums[i], it.second));
                    can.push_back(make_pair(it.first-nums[i], it.second));
                    m[it.first] = 0;
                }
            }
            for (auto it : can) {
                m[it.first] += it.second;
            }
            can.clear();
        }
        return m[S];
    }
};
```

```cpp
class Solution {
public:
    int findTargetSumWays(vector & nums, int sum)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (sum > total || sum < -total) return 0;
        if ((total + sum) & 1 != 0) return 0; // S, total 奇偶性必须相同
        int target = (total + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int n : nums)
        {
            int k0 = static_cast<int>(dp.size()) - 1 - n;
            for (int k = k0; k >= 0; --k) {
                dp[k + n] += dp[k];
            }
        }
        return dp.back();
    }
};
```

## 912. Sort an Array

数组排序。

1. 归并排序
2. 堆排序
   - 注意从 n/2-1 开始进行 siftdown
   - siftdown 比较值是让最开始的 parent 值和 child 值做比较
3. 快速排序
   - 快排在有序数组排序时，复杂度会退化到 O(n^2)
4.
5. 计数排序

**边界条件**

1. 完全有序的数组
2. 数组中的元素完全相等

## 935. Knight Dialer

![chess knight](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-chess_knight.png)

![phone pad](https://gitlab.com/convexwf/convex-resource/-/raw/master/convex-notes/leetcode-phone_pad.png)

将骑士放在电话拨号盘的任意数字键上，接下来，骑士将会跳 N-1 步。每一步必须是从一个数字键跳到另一个数字键。每当它落在一个键上（包括骑士的初始位置），都会拨出键所对应的数字，总共按下 N 位数字。能用这种方式拨出多少个不同的号码？

```txt
0 -> 4, 6
1 -> 6, 8
2 -> 7, 9
3 -> 4, 8
4 -> 3, 9, 0
5 ->
6 -> 1, 7, 0
7 -> 2, 6
8 -> 1, 3
9 -> 4, 2
```

1. 动态规划
2. 矩阵相乘：[yiduobo的每日leetcode 935.骑士拨号器 - 知乎](https://zhuanlan.zhihu.com/p/357643959)

## 149. Max Points on a Line

给了一堆二维点，求最大的共线点的个数。

判断三点共线的方法：A(ax,ay), B(bx,by), C(cx,cy)

(1) 斜率解法：判断 `(ay-by)/(ax-bx) == (cy-by)/(cx-bx)`
  当 `ax == bx` 或 `cx == bx` 时需要特殊判断，注意使用 gcd 化简分子分母比较，不要使用浮点结果比较，可能会有误差
(2) 周长判断解法：排序周长 `AC > AB > BC`，判断 `AC == AB + BC`
  由于 sqrt 开方运算会导致结果不准确，不稳定，在三角形接近扁平时，结果有误差。
(3) 最优解法：面积判断，判断 `area(ABC) == 0`
  `area(ABC) = 1/2 * ( AC X BC )  = 1/2 *((ax-cx)*(by-cy)-(bx-cx)*(ay-cy))`
  判断 `(ax-cx)*(by-cy) == (bx-cx)*(ay-cy)` 即可

1. 暴力解法 O(n^3)：
2. 斜率计算
   -
   - 通过斜率来判断共线需要用到除法，为了更加精确无误的计算共线，应当避免除法，这里把除数和被除数都保存下来，不做除法，但是要让这两数分别除以它们的最大公约数

**边界条件**

1. 当两个点重合时，无法确定一条直线，但这也是共线的情况
2. 斜率不存在的情况，由于两个点 (x1, y1) 和 (x2, y2) 的斜率k表示为 (y2 - y1) / (x2 - x1)，那么当 x1 = x2 时斜率不存在。


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

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }
    int gcd(int a, int b) { // a == 0 or b == 0, return max(a, b)
        return (b == 0) ? a : gcd(b, a % b);
    }
};
```

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



## 327. Count of Range Sum

求数组中，值位于范围 [lower, upper] (包含lower 和upper) 之内的区间和的个数。

1. multiset
   - 首先计算出一个累计和数组 accum，`accum[i]=accum[i-1]+nums[i]` 那问题可以转化为求解所有的区间 (j, i]，满足 `lower <= accum[i]-accum[j] <= upper`，亦可写成 `accum[i]-upper <= accum[j] <= accum[i]-lower`。
   - lower_bound() 是找数组中第一个不小于给定值的数(包括等于情况)，而 upper_bound() 是找数组中第一个大于给定值的数，distance() 方法返回两个迭代器之间的距离。
2. 归并排序(TODO)

**边界条件**

1. 出现 INT_MIN 和 INT_MAX

```cpp
// 2020-11-26 submission
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        multiset<long long> st{0};
        long long cur_sum = 0; // 后续有减法操作避免溢出
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            res += distance(st.lower_bound(cur_sum-upper), st.upper_bound(cur_sum-lower));
            st.insert(cur_sum); // why this expression after
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countAndMergeSort(sums, 0, sums.size(), lower, upper);
    }
    int countAndMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int cnt = countAndMergeSort(sums, start, mid, lower, upper) + countAndMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<int> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            cnt += j - k;
        }
        copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return cnt;
    }
};
```


## 307. Range Sum Query - Mutable

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size());
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - data[i];
        for (int j = i + 1; j < bit.size(); j += (j & -j)) {
            bit[j] += diff;
        }
        data[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> data, bit;
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

## 321. Create Maximum Number

给定两个无序数组，从两个数组中共挑出 k 个数，数字之间的相对顺序不变，求能组成的最大的数字。

由于k的大小不定，所以有三种可能：

第一种是当k为0时，两个数组中都不取数。

第二种是当k不大于其中任意一个数组的长度时，这种情况下，有可能只从一个数组中取数，或者两个都取一些。

第三种情况是k大于其中任意一个数组的长度，则需要从两个数组中分别取数，至于每个数组中取几个，每种情况都要考虑到，然后每次更结果即可。

为了同时能处理这三种情况，这里假设从数组 nums1 中取i个数，那么就需要从 nums2 中取 k-i 个数。那么i的范围如何确定呢？从情况二中知道，假如k不大于任意一个数组的长度，那么有可能只从其中一个数组中取k个，就是说可以不从 nums1 中取数，所以 i 最小可以取到0。如果是第三种情况，假设k大于 nums2 的长度，就算把 nums2 中所有的数字都取出来，都无法凑个k个，多余的 k-n2 个数字要从 nums1 中来取。所以只要比较 0 和 k-n2 的大小，取较大的为i的起始范围。那么i最大能到多大呢，还是要看 k 和 n1 的大小，如果 k 小于等于 n1，那么只需要取k个就行了，如果k大于 n1，那么只能在 nums1 中取 n1 个，多余的要到 nums2 中取。

好，现在知道了分别要从两个数组中取数字的情况，这里希望从 nums1 中取出的i个数字是最大的组合，同理，从 nums2 中取出的 k-i 个也是最大的数字组合。如何才能取出最大的组合呢？比如当前数组长度为n，需要取出k个数字，定义一个变量 drop = n - k，表示需要丢弃的数字的个数，遍历数组中的数字，进行下列循环，如果此时 drop 为整数，且结果数组长度不为0，结果数组的尾元素小于当前遍历的元素，则去掉结果数组的尾元素，此时 drop 自减1，重复循环直至上述任意条件不满足为止，然后把当前元素加入结果数组中，最后返回结果数组中的前k个元素。

现在分别从 nums1 中取出了i个最大组合的数字，从 nums2 中取出了 k-i 个最大组合的数字，最后一步就是需要将两个取出的数组混合排序成一个数组，小数组中各自的数字之间的相对顺序不变。对于两个数组的混合，要比较了两个数组的大小（按元素比较），然后从当前比较大的数组里取头一个元素，然后删除头元素到下次再接着比较，直到两个数组都为空停止。

```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
        }
        return res;
    }

    vector<int> maxVector(vector<int>& nums, int k) {
        int drop = (int)nums.size() - k;
        vector<int> res;
        for (int num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while (!nums1.empty() || !nums2.empty()) {
            vector<int> &tmp = (nums1 > nums2) ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
```

## 332. Reconstruct Itinerary

给定飞机票建立一个行程单，如果有多种方法，取其中字母顺序小的那种方法。本质是有向图的边遍历。

1. 邻接链表+multiset：建图，从节点 JFK 开始遍历，只要当前节点映射的 multiset 里有节点，取出这个节点，将其在 multiset 里删掉，然后继续递归遍历这个节点，由于题目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯回去，将当前节点都存入结果，那么最后我们结果中存的顺序和我们需要的相反的，我们最后再翻转一下即可，参见代码如下：

## 315. Count of Smaller Numbers After Self

返回数组中每个元素右边比他小的元素个数。

1. 二分搜索法：将给定数组从最后一个开始，用二分法插入到一个新的数组，该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数。时间复杂度 O(nlogn)，空间复杂度 O(n)。
2. 二分搜索树：加一个变量 smaller 来记录比当前结点值小的所有结点的个数，每插入一个结点，会判断其和根结点的大小，如果新的结点值小于根结点值，则其会插入到左子树中，此时要增加根结点的 smaller，并继续递归调用左子结点的 insert。如果结点值大于根结点值，则需要递归调用右子结点的 insert 并加上根结点的 smaller，并加 1。

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node*& root, int val) {
        if (!root) return (root = new Node(val, 0)), 0;
        if (root->val > val) return root->smaller++, insert(root->left, val);
        return insert(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};
```
