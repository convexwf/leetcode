# Lock

## 157. Read N Characters Given Read4

解题思路

1. 题目描述：给定一个 Read4 函数，每次可以从一个文件中最多读出 4 个字符，如果文件中的字符不足 4 个字符时，返回准确的当前剩余的字符数。要求实现一个最多能读取n个字符的函数。
2. 迭代：思路是每4个读一次，然后把读出的结果判断一下，如果为0的话，说明此时的 buf 已经被读完，跳出循环，直接返回 res 和n之中的较小值。否则一直读入，直到读完n个字符，循环结束，最后再返回 res 和n之中的较小值

```C++
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + res);
            if (cur == 0) break;
            res += cur;
        }
        return min(res, n);
    }
};
```

## 161. One Edit Distance

解题思路

1. 题目描述：判断两个字符串的编辑距离是否为1
2. 需要对比两个字符串对应位置上的字符，如果遇到不同的时候，这时看两个字符串的长度关系，如果相等，则比较当前位置后的字串是否相同，如果 s 的长度大，那么比较 s 的下一个位置开始的子串，和 t 的当前位置开始的子串是否相同，反之如果 t 的长度大，则比较 t 的下一个位置开始的子串，和 s 的当前位置开始的子串是否相同。如果循环结束，都没有找到不同的字符，那么此时看两个字符串的长度是否相差1。

```C++
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
                if (s.size() < t.size()) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
            }
        }
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};
```

## 163. Missing Ranges

解题思路

1. 题目描述：求缺失区间。给了一个空间的范围 [lower upper]，缺失的区间的范围需要在给定的区间范围内。
2. 遍历 nums 数组，假如当前数字 num 大于 lower，说明此时已经有缺失区间，至少缺失一个 lower 数字，此时若 num-1 大于 lower，说明缺失的是一个区间 [lower, num-1]，否则就只加入一个数字即可。由于 OJ 之后加入了许多 tricky 的 test cases，使得论坛上很多解法都 fail 了。其实很多是跪在了整型溢出，当数组中有整型最大值时，此时 lower 更新为 num+1 时就会溢出，所以在更新之前要先判断一下，若 num 已经是整型最大值了，直接返回结果 res 即可；否则才更新 lower 继续循环。for 循环退出后，此时可能还存在缺失区间，就是此时 lower 还小于等于 upper 时，可以会缺失 lower 这个数字，或者 [lower, upper] 区间。

```C++
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (int num : nums) {
            if (num > lower) res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
            if (num == upper) return res;
            lower = num + 1;
        }
        if (lower <= upper) res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
        return res;
    }
};
```

## 186. Reverse Words in a String II

解题思路

1. 题目描述：翻转一个字符串中的单词
2. 使用 C++ STL 中自带的 reverse 函数来做，先把整个字符串翻转一下，然后再来扫描每个字符，用两个指针，一个指向开头，另一个开始遍历，遇到空格停止，这样两个指针之间就确定了一个单词的范围，直接调用 reverse 函数翻转，然后移动头指针到下一个位置，在用另一个指针继续扫描，重复上述步骤即可

```C++
class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        for (int i = 0, j = 0; i < str.size(); i = j + 1) {
            for (j = i; j < str.size(); ++j) {
                if (str[j] == ' ') break;
            }
            reverse(str.begin() + i, str.begin() + j);
        }
    }
};
```

## 243. Shortest Word Distance

解题思路

1. 题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，限定了两个单词不同，而且都在数组中。
2. 用一个辅助变量 idx，初始化为 -1，然后遍历数组，如果遇到等于两个单词中的任意一个单词，再看 idx 是否为 -1，若不为 -1，且指向的单词和当前遍历到的单词不同，更新结果

```C++
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[idx] != words[i]) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
```

## 244. Shortest Word Distance II

解题思路

1. 题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，限定了两个单词不同，而且都在数组中。函数需要多次调用。
2. 用 HashMap 来建立每个单词和其所有出现的位置的映射，然后在找最短单词距离时，只需要取出该单词在 HashMap 中映射的位置数组进行两两比较即可。进一步优化：用两个指针i和j来指向位置数组中的某个位置，开始初始化都为0，然后比较位置数组中的数字，将较小的一个的指针向后移动一位，直至其中一个数组遍历完成即可。

```C++
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? ++i : ++j;
        }
        return res;
    }

private:
    unordered_map<string, vector<int> > m;
};
```

## 245. Shortest Word Distance III

解题思路

1. 题目描述：给定一个单词数组，又给定两个单词，求这两个单词之间的最小距离，两个单词可能相同。
2. 用一个变量 idx，这个 idx 的作用是记录上一次的位置，当前 idx 不等于 -1 时，说明当前 i 和 idx 不同，然后在 word1 和 word2 相同或者 words[i] 和 words[idx] 相同的情况下更新结果，最后将 idx 赋为 i。

```C++
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && (word1 == word2 || words[i] != words[idx])) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};
```

## 246. Strobogrammatic Number

解题思路

1. 题目描述：判断给定数字是否为对称数，即一个数字旋转 180 度和原来一样，也就是倒过来看一样，比如 609，倒过来还是 609。
2. 满足这种条件的数字其实没有几个，只有 0,1,8,6,9。这道题其实可以看做求回文数的一种特殊情况，还是用双指针来检测，首尾两个数字如果相等的话，只有它们是 0,1,8 中间的一个才行，如果它们不相等的话，必须一个是 6 一个是 9，或者一个是 9 一个是 6。

```C++
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};
```

## 247. Strobogrammatic Number II

解题思路

1. 题目描述：找出长度为n的所有的对称数
2. 递归：每个数字都在之前数字的左右增加了 [0 0]，[1 1], [6 9], [8 8], [9 6]。需要注意当加到了n层的时候，左右两边不能加 [0 0]，因为0不能出现在两位数及多位数的开头。
3. 迭代：思路一样，加入了奇偶考虑。

```C++
// 递归
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n), res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> one{"0", "1", "8"}, two{""}, res = two;
        if (n % 2 == 1) res = one;
        for (int i = (n % 2) + 2; i <= n; i += 2) {
            vector<string> t;
            for (auto a : res) {
                if (i != n) t.push_back("0" + a + "0");
                t.push_back("1" + a + "1");
                t.push_back("6" + a + "9");
                t.push_back("8" + a + "8");
                t.push_back("9" + a + "6");
            }
            res = t;
        }
        return res;
    }
};
```