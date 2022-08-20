
## 710

随机生成一个 N 以内的数字，且该数字不能在黑名单中

1. 首先将超过N - blacklist.size()的数字放入一个HashSet；然后遍历blacklist中的数字，如果在HashSet中的话，就将其删除；遍历黑名单中的数字，如果小于N - blacklist.size()的话，就和和HashSet中的数字建立映射。

```cpp
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

## 345

翻转字符串中的元音字母

1. 双指针法

**边界条件**

1. 注意大写字母

```cpp
// 2021-12-16 submission
// 480/480 cases passed
// Runtime: 8 ms, faster than 70.15% of C++ online submissions.
// Memory Usage: 8 MB, less than 38.59% of C++ online submissions.
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> m{'a', 'i', 'u', 'e', 'o'};
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !m.count(tolower(s[l]))) ++l;
            while (r >= 0 && !m.count(tolower(s[r]))) --r;
            if (l < r) {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};
```

## 482

对注册码进行格式化，正确的注册码的格式是每四个字符后面跟一个短杠，每一部分的长度为K，第一部分长度可以小于K，另外，字母必须是大写的。

1. 首先计算出有效字符的个数。

**边界条件**

1. k 正好可以整除 n
2. 小写字母需要转为大写字母

```cpp
// 2021-12-17 submission
// 38/38 cases passed
// Runtime: 8 ms, faster than 80.96% of C++ online submissions.
// Memory Usage: 8.3 MB, less than 67.18% of C++ online submissions.
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for (char c : s) {
            if (isalnum(c)) ++cnt;
        }

        string res;
        for (char c : s) {
            if (isalnum(c)) {
                cnt--;
                res.append(1, toupper(c));
                if (cnt % k == 0 && cnt != 0) {
                    res.append(1, '-');
                }
            }
        }
        return res;
    }
};
```

## 434

统计字符串中的单词数量，单词以空格进行分隔

1. 遍历字符串，遇到空格直接跳过，如果不是空格，则计数器加1，然后用个while循环找到下一个空格的位置。
2. 统计单词开头的第一个字符，因为每个单词的第一个字符前面一个字符一定是空格。
3. 利用 C++ 的 getline 函数取出每两个空格符之间的字符串，由于多个空格符可能连在一起，所以有可能取出空字符串，只有取出的是非空字符串才累加计数器。

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            ++res;
            while (i < n && s[i] != ' ') ++i;
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++res;
            }
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream is(s);
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            ++res;
        }
        return res;
    }
};
```

## 292

Nim 游戏，给定一堆石子，每次可以拿 1~3 个，两个人轮流拿，拿到最后一个石子的人获胜，问先取者是否有必胜法。

1. 尼姆博弈，只有石子数能被 4 整除即可。

```cpp
// 2019-09-15 submission
// 60/60 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 62.65% of C++ online submissions.
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

## 709

将单词转为小写

1. 小写字母比其对应的大写字母的 ASCII 码大 'a'-'A

```cpp
// 2021-12-16 submission
// 114/114 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 51.19% of C++ online submissions.
class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (char c : s) {
            if ('A' <= c && c <= 'Z') res.append(1, c + ('a' - 'A'));
            else res.append(1, c);
        }
        return res;
    }
};
```

## 628

数组中最大的三个数乘积

1. 排序+分类讨论
   - (1) 全正数：最大的三个数之乘积
   - (2) 全负数：最大的三个数之乘积
   - (3) 正负混合：最大的数和最小两个数的乘积或者最大的三个数之乘积。
2. 在方法 1 的基础上，因为只需要求最大和最小的几个数，可将时间复杂度降低为 O(n)。

```cpp
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 61 ms, faster than 16.89% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val1 = nums[n-1] * nums[n-2] * nums[n-3];
        int val2 = nums[n-1] * nums[0] * nums[1];
        return max(val1, val2);
    }
};
```

```cpp
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 44 ms, faster than 62.61% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int A = INT_MIN, B = INT_MIN, C = INT_MIN;
        int a = INT_MAX, b = INT_MAX;
        for (int num : nums) {
            // max three numbers
            if (num > A) {
                C = B; B = A; A = num;
            }
            else if (A > num && num > B) {
                C = B; B = num;
            }
            else if (B > num && num > C) {
                C = num;
            }
            // min two numbers
            if (num < a) {
                b = a; a = num
            }
            else if (a < num && num < b) {
                b = num;
            }
        }
        return max(A * B * C, a * b * A);
    }
};
```

## 697

数组的度定义为出现最多次数的数字的出现次数，求和原数组度相同的长度最小的子数组。

1. HashMap
   - 统计数组元素的出现次数，以及数组元素的右边界，用 HashMap 进行统计存储
   - 得到最大出现次数后，从左往右遍历，依次计算元素是否符合最大出现次数，如果符合就计算区间长度，并将出现次数减一，防止后续重复计算。
2. 方法 1 的改进，统计数组元素的出现次数，以及数组元素的左边界，这样只需要遍历一次数组，遍历到的当前位置视为尾位置。

```cpp
// 2021-12-15 submission
// 89/89 cases passed
// Runtime: 44 ms, faster than 56.21% of C++ online submissions.
// Memory Usage: 25.5 MB, less than 67.47% of C++ online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;      // 出现次数的映射
        unordered_map<int, int> right;  // 右边界的映射
        int max_val = 0;                // 数组的度, 最多出现次数
        for (int i = 0; i < nums.size(); i++) {
            ++m[nums[i]];
            right[nums[i]] = i;
            max_val = max(max_val, m[nums[i]]);
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == max_val) {
                res = min(res, right[nums[i]] - i + 1);
                --m[nums[i]];
            }
        }
        return res;
    }
};
```

```cpp
// 2022-08-20 submission
// 89/89 cases passed
// Runtime: 51 ms, faster than 81.98% of C++ online submissions.
// Memory Usage: 25.5 MB, less than 68.97% of C++ online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;      // 出现次数的映射
        unordered_map<int, int> left;   // 左边界的映射
        int max_val = 0;                // 数组的度, 最多出现次数
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (!left.count(nums[i])) {
                left[nums[i]] = i;
            }
            ++m[nums[i]];
            if (m[nums[i]] > max_val) { // 更新数组度，需要重新计算 res
                max_val = m[nums[i]];
                res = nums.size();
            }
            if (m[nums[i]] == max_val) {
                res = min(res, i - left[nums[i]] + 1);
            }
        }
        return res;
    }
};
```

## 690

定义了一种员工类，有id，重要度和直接下属，计算某个员工的重要度，注意下属的重要度会向上累积到上级的重要度。

1. 建图+DFS: 首先为需要建立一个id和员工类的映射，从而能够快速通过id来定位到员工类。
2. 建图+BFS

```cpp
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        return DFS(id, m);
    }
    int DFS(int id, unordered_map<int, Employee*>& m) {
        int res = m[id]->importance;
        for (int num : m[id]->subordinates) {
            res += DFS(num, m);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        queue<int> q{{id}};
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            res += m[t]->importance;
            for (int num : m[t]->subordinates) {
                q.push(num);
            }
        }
        return res;
    }
};
```

## 682

棒球比赛计分

1. 按照题意处理即可。

```cpp
// 2022-08-20 submission
// 39/39 cases passed
// Runtime: 8 ms, faster than 44.66% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 99.8% of C++ online submissions.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vec;
        int sum = 0;
        for (string op : ops) {
            int n = vec.size();
            if (op == "+") {
                vec.push_back(vec[n - 1] + vec[n - 2]);
                sum += vec.back();
            }
            else if (op == "D") {
                vec.push_back(vec[n - 1] * 2);
                sum += vec.back();
            }
            else if (op == "C") {
                sum -= vec.back();
                vec.pop_back();
            }
            else {
                vec.push_back(stoi(op));
                sum += vec.back();
            }
        }
        return sum;
    }
};
```
