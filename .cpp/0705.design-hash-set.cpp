/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
// 1. 一维数组
// 2023-06-21 submission
// 33/33 cases passed
// Runtime: 75 ms, faster than 98.36% of cpp online submissions.
// Memory Usage: 43.7 MB, less than 48.63% of cpp online submissions.
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = vector<bool>(1000001, false);
    }

    void add(int key) {
        data[key] = true;
    }

    void remove(int key) {
        data[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key];
    }

private:
    vector<bool> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

// @lc code=start
// 2. 数组+链表
// 2023-06-21 submission
// 33/33 cases passed
// Runtime: 92 ms, faster than 76.87% of cpp online submissions.
// Memory Usage: 41.8 MB, less than 73.08% of cpp online submissions.
class MyHashSet {
private:
    vector<list<int>> data;
    static const int base = 1009; // 取一个素数
    static int hash(int key) {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(base);
    }

    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if (*it == key) {
                return;
            }
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if (*it == key) {
                data[h].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 3. bitmap
// 2023-06-21 submission
// 33/33 cases passed
// Runtime: 79 ms, faster than 96.27% of cpp online submissions.
// Memory Usage: 43.5 MB, less than 66.43% of cpp online submissions.
class MyHashSet {
private:
    bitset<1000001> bits;

public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }

    void add(int key) {
        bits.set(key);
    }

    void remove(int key) {
        bits.reset(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bits.test(key);
    }
};
// @lc code=end