# Bit Manipulation

## 基本操作

| 操作 | 含义 |  |
| - | - | - |
| & | 按位与 | 两个位都为1时，结果才为1|
| \|| 按位或 | 两个位都为0时，结果才为0|
| ^ | 按位异或 | 两个位相同为0，相异为1|
| ~ | 按位取反 | 0变1，1变0，包括最高位|
| <<| 左移 | 左移若干位，高位丢弃，低位补0|
| >>| 右移 | 各二进位全部右移若干位，对无符号数，高位补0；有符号数，各编译器处理方法不一样，有的补符号位（算术右移），有的补0（逻辑右移）|

* 注意事项
  1. 位操作只能用于整型数据，对float和double类型进行位操作会被编译器报错。
  2. 位操作符的运算优先级比较低，尽量使用括号来确保运算顺序。

## 常用技巧

1. 判断奇偶
    根据最未位是0还是1来决定，为0就是偶数，为1就是奇数。

    ```C++
    // 判断是否为偶数
    (a & 1) == 0 or (a % 2) == 0
    ```

2. 交换两数
    第一步  a^=b 即a=(a^b)
    第二步  b^=a 即b=b^( a^b ), 由于 ^ 运算满足交换律，b^( a^b ) = b^b^a=0^a=a
    第三步  a=( a^b ) = ( a^ b)^a = b

    ```C++
    a ^= b;
    b ^= a;
    a ^= b;
    ```

3. 变换符号 (有符号整型)

    ```C++
    a = ~a + 1;
    ```

4. 求绝对值

    ```C++
    ```

5. 判断是不是 2 的整数次方

    ```C++
    a & (a - 1)
    ```

6. 从右往左的第一个1变为0

    ```C++
    a = a & (a - 1)
    ```

7. 获取最右边的1

    ```C++
    x = a & (-a)
    ```

## 78. Subsets

解题思路

1. 题目描述：找出给定集合的所有子集
2. 递归：DFS深度优先搜索
3. 位操作：数组中所有的数分配一个状态，true 表示这个数在子集中出现，false 表示在子集中不出现，那么对于一个长度为n的数组，每个数字都有出现与不出现两种情况，所以共有 $2^n$ 中情况
   ![子集的二进制表示](res/Bit_manipulation-子集的二进制表示.png)

```C++
// 2019-05-06 submission (DFS)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.5 MB, less than 7.29% of C++ online submissions for Subsets.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
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
// Runtime: 4 ms, faster than 67.90% of C++ online submissions for Subsets.
// Memory Usage: 7.5 MB, less than 7.29% of C++ online submissions for Subsets.
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

解题思路

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

## 169. Majority Element

解题思路

1. 排序，取中位数即可
2. 多数投票算法(Boyer-Moore Algorithm)：扫描两次数组，第一趟记录 candidate (初值可以为任何数)和 count (初值为0)，之后，对于数组中每一个元素，首先判断 count 是否为0，若为0，则把 candidate 设置为当前元素。之后判断 candidate 是否与当前元素相等，若相等则count+=1，否则count-=1。第二趟扫描来统计 candidate 出现的次数来判断其是否为多数元素。该算法无法找到一个序列的众数，除非众数出现的次数大于 ⌊n/2⌋ 次
3. 位操作：检查每一个二进制位是否为1，如果是就累加 count， 如果count>n/2就置为1。

```C++
// 2020-10-26 submission (多数投票算法)
// Runtime: 32 ms, faster than 97.99% of C++ online submissions for Majority Element.
// Memory Usage: 20 MB, less than 99.97% of C++ online submissions for Majority Element.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) candidate = nums[i];
            if (candidate == nums[i]) count++;
            else count--;
        }
        return candidate;
    }
};
```

```C++
// 2020-10-26 submission (位操作)
// Runtime: 56 ms, faster than 34.92% of C++ online submissions for Majority Element.
// Memory Usage: 20.1 MB, less than 99.97% of C++ online submissions for Majority Element.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j]>>i) & 1);
            }
            if (count > nums.size() / 2) res |= (1 << i);
        }
        return res;
    }
};
```

## 187. Repeated DNA Sequences

解题思路

1. 基本做法：hash，将连续的十个字符映射为唯一，出现重复时就加入到结果
2. 同时，为了减少内存使用，可考虑位操作。用两位来表示一个字符，00 表示A，01 表示C，10 表示G，11 表示T，那么总共需要 20 位就可以表示十个字符流。

边界条件

1. 可能会出现多次重复（要去重）

```C++
// 2020-09-18 submission
// Runtime: 68 ms, faster than 93.74% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 14.9 MB, less than 97.44% of C++ online submissions for Repeated DNA Sequences.
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

## 190. Reverse Bits

解题思路

1. 位操作：反转

```C++
// 2018-07-25 submission
// Runtime: 4 ms, faster than 58.67% of C++ online submissions for Reverse Bits.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Reverse Bits.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0u;
        for(int i = 0; i < 32; i++) {
            ret = ret << 1;
            if(n & 1 == 1) ret += 1;
            n = n >> 1;
        }
        return ret;
    }
};
```

```C++
// forum
// https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C++-solution-(8ms)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
// for 8 bit binary number abcdefgh, the process is as follow:
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
```

## 191

## 318. Maximum Product of Word Lengths

解题思路

1. 题目描述：给定单词列表，求没有重叠字母的两个单词的最大长度之积
2. 位操作：小写字母只有 26 个，而 int 类型有 32 个 bit，恰好能够描述每个单词中字母的分布。如果两个单词对应的二进制 bit 表示取与后为0，即表示没有重叠字母。

```C++
// 2020-10-27 submission
// Runtime: 60 ms, faster than 84.10% of C++ online submissions for Maximum Product of Word Lengths.
// Memory Usage: 16.3 MB, less than 5.09% of C++ online submissions for Maximum Product of Word Lengths.
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> word_bits(words.size(), 0);
        for (int i = 0 ; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                word_bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int max_val = 0;
        for (int i = 0; i < word_bits.size(); i++) {
            for (int j = i + 1; j < word_bits.size(); j++) {
                if ((word_bits[i] & word_bits[j]) == 0)
                    max_val = max(max_val, int(words[i].length() * words[j].length()));
            }
        }
        return max_val;
    }
};
```

## 338. Counting Bits

解题思路

1. 问题描述：给定 n，返回 0 到 n 所有数字中含 1 的个数。
2. 位操作：通过 a = a & (a - 1) 将 a 的最右边 1 改为 0，从而可以通过已有的子问题求解

```C++
// 2020-10-27 submission (位操作)
// Runtime: 4 ms, faster than 98.71% of C++ online submissions for Counting Bits.
// Memory Usage: 8.1 MB, less than 35.37% of C++ online submissions for Counting Bits.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
};
```

```C++
#include<bitset>
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for(int i = 1; i < num + 1; ++i){
            result[i] = bitset<32>(i).count();
        }
        return result;
    }
};
```

## 389. Find the Difference

解题思路

1. 问题描述：往字符串中随机位置加入一个随机字母
2. 位操作：将前后字符串的字母合并，问题转化为 **136. Single Number**

```C++
// 2020-10-27 submission
// Runtime: 4 ms, faster than 93.43% of C++ online submissions for Find the Difference.
// Memory Usage: 7 MB, less than 99.53% of C++ online submissions for Find the Difference.
class Solution {
public:
    char findTheDifference(string s, string t) {
        char mask = 0;
        for (char c : s)
            mask ^= c;
        for (char c : t)
            mask ^= c;
        return mask;
    }
};
```

## 461. Hamming Distance

解题思路

1. 位操作：异或后求 1 的个数

```C++
// 2020-10-26 submission
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Hamming Distance.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int merge = x ^ y;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (merge>>i & 1);
        }
        return res;
    }
};
```

## 477. Total Hamming Distance

解题思路

1. 位操作：找到每一位上 1 的个数和 0 的个数，然后两个相乘即这一位的总 Hamming Distance

```C++
// 2020-10-26 submission
// Runtime: 68 ms, faster than 95.49% of C++ online submissions for Total Hamming Distance.
// Memory Usage: 19.4 MB, less than 100.00% of C++ online submissions for Total Hamming Distance.
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j]>>i) & 1);
            }
            res += ((nums.size()-count) * count);
        }
        return res;
    }
};
```
