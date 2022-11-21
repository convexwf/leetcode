# HOT

## 1. Two Sum

解题思路

1. 题目描述：给定无序数组和指定值 target, 返回和为 target 的两个数的下标。
2. HashMap：建立值到下标的映射。复杂度为 O(n)

关联专题

1. **Target Sum**

```C++
// 2020-12-14 submission
// Runtime: 8 ms, faster than 95.31% of C++ online submissions for Two Sum.
// Memory Usage: 9.4 MB, less than 77.01% of C++ online submissions for Two Sum.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]))
                return vector<int>{m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};
```
