## 1032. Stream of Characters

设计一个算法：接收一个字符流，并检查这些字符的后缀是否是字符串数组 words 中的一个字符串。

例如，words = ["abc", "xyz"] 且字符流中逐个依次加入 4 个字符 'a'、'x'、'y' 和 'z' ，算法应当可以检测到 "axyz" 的后缀 "xyz" 与 words 中的字符串 "xyz" 匹配。

按下述要求实现 StreamChecker 类：

- `StreamChecker(String[] words)` ：构造函数，用字符串数组 words 初始化数据结构。
- `boolean query(char letter)`：从字符流中接收一个新字符，如果字符流中的任一非空后缀能匹配 words 中的某一字符串，返回 true ；否则，返回 false。

1. Trie 树
   - 声明前缀树的根结点 root，定义字符串 queryStr。
   - 构造函数中，遍历每个单词，从最后的字符开始处理，若当前结点的 next 数组中对应位置不包含该字符，则新建出 Trie 结点，然后当前结点移到新建的结点继续循环，完成之后标记 isWord 为 true。
   - 实现 query 函数时进行类似的操作，先把字符加入 queryStr，然后从其末尾往前遍历，取出 next 数组中对应位置的结点，若存在且 isWord 为 true，则说明找到了某个单词，直接返回 true，否则继续遍历。最终没找到的话返回 false 即可。

```cpp
struct TrieNode {
    bool isWord;
    TrieNode *next[26];
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            TrieNode *node = root;
            for (int i = (int)word.size() - 1; i >= 0; --i) {
                if (!node->next[word[i] - 'a']) {
                    node->next[word[i] - 'a'] = new TrieNode();
                }
                node = node->next[word[i] - 'a'];
            }
            node->isWord = true;
        }
    }

    bool query(char letter) {
        queryStr.push_back(letter);
        TrieNode *node = root;
        for (int i = (int)queryStr.size() - 1; i >= 0 && node; --i) {
            node = node->next[queryStr[i] - 'a'];
            if (node && node->isWord) return true;
        }
        return false;
    }

private:

    TrieNode *root;
    string queryStr;
};
```

## 609. Find Duplicate File in System

一个目录信息列表 paths ，包括目录路径，以及该目录中的所有文件及其内容，按路径返回文件系统中的所有重复文件。

1. 哈希表
   - 键（key）是文件内容，值（value）是存储路径和文件名的列表。
   - 遍历每一个文件，并把它加入哈希映射中。
   - 在这之后遍历哈希映射，如果一个键对应的值列表的长度大于 1，说明找到了重复文件，可以把这个列表加入到答案中。
