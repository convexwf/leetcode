/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
// 1. 哈希表+优先队列
// 2023-12-25 submission
// 38/38 cases passed
// Runtime: 187 ms, faster than 61.04% of cpp online submissions.
// Memory Usage: 90.9 MB, less than 96.77% of cpp online submissions.
class FreqStack {
public:
    FreqStack() {
    }

    void push(int val) {
        ++freq[val];
        pq.push({freq[val], ++index, val});
    }

    int pop() {
        auto [f, i, v] = pq.top();
        pq.pop();
        --freq[v];
        return v;
    }

private:
    unordered_map<int, int> freq;
    priority_queue<tuple<int, int, int>> pq;
    int index = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

// @lc code=start
// 2. 双哈希表
// 2023-12-25 submission
// 38/38 cases passed
// Runtime: 182 ms, faster than 75.39% of cpp online submissions.
// Memory Usage: 91.8 MB, less than 77.92% of cpp online submissions.
class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        ++freq[val];
        if (freq[val] > maxFreq) {
            maxFreq = freq[val];
        }
        freqList[freq[val]].push_back(val);
    }

    int pop() {
        int val = freqList[maxFreq].back();
        freqList[maxFreq].pop_back();
        --freq[val];
        if (freqList[maxFreq].empty()) {
            --maxFreq;
        }
        return val;
    }

private:
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> freqList;
    int maxFreq;
};
// @lc code=end
