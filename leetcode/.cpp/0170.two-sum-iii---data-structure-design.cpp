/*
 * @lc app=leetcode id=170 lang=cpp
 *
 * [170] Two Sum III - Data structure design
 */

// @lc code=start
// 1. 哈希表
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto& [num, cnt] : m) {
            if (num == value - num && cnt > 1) return true;
            if (num != value - num && m.count(value - num)) return true;
        }
        return false;
    }

private:
    unordered_map<int, int> m;
};
// @lc code=end

// @lc code=start
// 2. 双哈希表
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        for (auto& [num, count] : num_count) {
            sum_count[num + number]++;
        }
        num_count[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        return sum_count.count(value);
    }

private:
    unordered_map<int, int> num_count;
    unordered_map<int, int> sum_count;
};
// @lc code=end
