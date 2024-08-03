/*
 * @lc app=leetcode id=379 lang=cpp
 *
 * [379] Design Phone Directory
 */

// @lc code=start
// 1. 哈希表
class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.insert(i);
        }
    }

    int get() {
        if (available.empty()) {
            return -1;
        }
        int number = *available.begin();
        available.erase(number);
        return number;
    }

    bool check(int number) {
        return available.count(number);
    }

    void release(int number) {
        available.insert(number);
    }

private:
    unordered_set<int> available;
};
// @lc code=end
