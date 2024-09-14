/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
// 1. 大数组
// 2023-06-21 submission
// 36/36 cases passed
// Runtime: 159 ms, faster than 56.02% of cpp online submissions.
// Memory Usage: 208.1 MB, less than 42.83% of cpp online submissions.
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data = vector<int>(1000001, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        data[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no
     * mapping for the key */
    int get(int key) {
        return data[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data[key] = -1;
    }

private:
    vector<int> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

// @lc code=start
// 2. 数组+链表(链地址法)
// 2023-06-21 submission
// 36/36 cases passed
// Runtime: 282 ms, faster than 11.76% of cpp online submissions.
// Memory Usage: 54.5 MB, less than 62.45% of cpp online submissions.
class MyHashMap {
private:
    struct Node
    {
        int key, val;
        Node *next;
        Node(int key, int val) : key(key), val(val), next(nullptr) {
        }
    };
    vector<Node *> data;
    int hash(int key) {
        return key % data.size();
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data = vector<Node *>(10000, new Node(-1, -1));
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        Node *p = data[h];
        while (p->next) {
            if (p->next->key == key) {
                p->next->val = value;
                return;
            }
            p = p->next;
        }
        p->next = new Node(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no
     * mapping for the key */
    int get(int key) {
        int h = hash(key);
        Node *p = data[h];
        while (p->next) {
            if (p->next->key == key) {
                return p->next->val;
            }
            p = p->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        Node *p = data[h];
        while (p->next) {
            if (p->next->key == key) {
                Node *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                return;
            }
            p = p->next;
        }
    }
};
// @lc code=end

// @lc code=start
// 3. 开放寻址法
// 2023-06-21 submission
// 36/36 cases passed
// Runtime: 285 ms, faster than 11.53% of cpp online submissions.
// Memory Usage: 312.2 MB, less than 6.52% of cpp online submissions.
class MyHashMap {
private:
    vector<pair<int, int>> table;
    const int size = 1000001; // 设置数组的大小为 1000001，可根据实际情况调整

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        table.resize(size, {-1, -1});
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % size;
        while (table[index].first != -1 && table[index].first != key) {
            index = (index + 1) % size; // 使用线性探测法解决哈希冲突
        }
        table[index] = {key, value};
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no
     * mapping for the key */
    int get(int key) {
        int index = key % size;
        while (table[index].first != -1) {
            if (table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % size;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % size;
        while (table[index].first != -1) {
            if (table[index].first == key) {
                table[index] = {-1, -1}; // 标记为删除状态
                return;
            }
            index = (index + 1) % size;
        }
    }
};
// @lc code=end
