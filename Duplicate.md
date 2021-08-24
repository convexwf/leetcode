# Duplicate

## 136. Single Number

解题思路

1. 题目描述：非空数组，除了 X 只出现一次其他所有元素都出现了两次，找出 X。
2. 位操作：两个相同的数取异或(^)结果为0，所以对所有数取异或，结果即为 X

```C++
// 2018-09-19 submission
// Runtime: 20 ms, faster than 92.90% of C++ online submissions for Single Number.
// Memory Usage: 12 MB, less than 65.67% of C++ online submissions for Single Number.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
```

## 137. Single Number II

1. 题目描述：非空数组，除了 X 只出现一次其他所有元素都出现了三次，找出 X。
2. 位操作：建立一个 32 位的数字，来统计每一位上 1 出现的个数，如果该整数某一位出现了三次，对3取余为0，这样把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。

```C++
// 2020-09-27 submission
// Runtime: 16 ms, faster than 80.35% of C++ online submissions for Single Number II.
// Memory Usage: 9.7 MB, less than 33.57% of C++ online submissions for Single Number II.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int idx = 0; idx < nums.size(); idx++) {
                sum += (nums[idx] >> i) & 1;
            }
            res += (sum % 3) << i; // |= or +=
        }
        return res;
    }
};
```

## 260. Single Number III

## 217. Contains Duplicate

解题思路

1. 题目描述：对于数组(array)，判断是否存在重复值
2. hashset

```C++
// 2019-09-17 submission
// Runtime: 64 ms, faster than 79.78% of C++ online submissions for Contains Duplicate.
// Memory Usage: 20 MB, less than 69.02% of C++ online submissions for Contains Duplicate.
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

## 219. Contains Duplicate II

解题思路

1. 对于数组(array)，判断是否出现重复值，且重复值之间下标距离不大于 k
2. hashmap，存储值到下标的映射。从左到右遍历数组，如果当前值的当前下标距离当前值的前下标不大于 k, 则认为出现重复。

```C++
// 2019-09-17 submission
// Runtime: 52 ms, faster than 71.61% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 16.4 MB, less than 74.38% of C++ online submissions for Contains Duplicate II.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) && i-m[nums[i]]<=k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
```

## 220. Contains Duplicate III

## 287. Find the Duplicate Number

解题思路

1. 题目描述：给定一个包含 n + 1 个整数的数组，其中每一个整数均介于 [1, n] 之间，其中至少有一个重复元素存在（鸽巢原理）。假设只有一个数字出现重复，找出这个重复的数字。要求不能改动原数组（排序），O(1) extra space，less than O(n2) runtime complexity
2. 位操作：遍历每一位，然后对于 32 位中的每一个位 bit，都遍历一遍从 0 到 n-1，将 0 到 n-1 中的每一个数都跟 bit 相 与，若大于0，则计数器 cnt1 自增1。同时 0 到 n-1 也可以当作 nums 数组的下标，从而让 nums 数组中的每个数字也跟 bit 相与，若大于0，则计数器 cnt2 自增1。最后比较若 cnt2 大于 cnt1，则将 bit 加入结果 res 中。因为对于每一位，0 到 n-1 中所有数字中该位上的 1 的个数应该是固定的，如果 nums 数组中所有数字中该位上 1 的个数多了，说明重复数字在该位上一定是 1，这样我们把重复数字的所有为 1 的位都累加起来，就可以还原出这个重复数字。
3. 快慢指针：

```C++
// 2020-10-28 submission (位操作)
// Runtime: 16 ms, faster than 70.60% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 11.4 MB, less than 18.91% of C++ online submissions for Find the Duplicate Number.
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

```C++
// 2020-10-28 submission (快慢指针)
// Runtime: 8 ms, faster than 99.60% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 11.3 MB, less than 18.91% of C++ online submissions for Find the Duplicate Number.
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

## 442. Find All Duplicates in an Array

## 316. Remove Duplicate Letters