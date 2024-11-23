/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
// 1. 递归
// 2024-11-21 submission
// 43/43 cases passed
// Runtime: 7 ms, faster than 53.9% of cpp online submissions.
// Memory Usage: 16.1 MB, less than 89.08% of cpp online submissions.
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        it = flattenList.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != flattenList.end();
    }

private:
    vector<int> flattenList;
    vector<int>::iterator it;

    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto &nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                flattenList.push_back(nestedInteger.getInteger());
            }
            else {
                flatten(nestedInteger.getList());
            }
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 栈
// 2023-01-31 submission
// 43/43 cases passed
// Runtime: 28 ms, faster than 27.47% of cpp online submissions.
// Memory Usage: 14.4 MB, less than 26.88% of cpp online submissions.
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger t = s.top();
        s.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!s.empty()) {
            NestedInteger t = s.top();
            if (t.isInteger()) return true;
            s.pop();
            for (int i = t.getList().size() - 1; i >= 0; --i) {
                s.push(t.getList()[i]);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

// @lc code=start
// 3. 双向队列
// 2023-01-31 submission
// 43/43 cases passed
// Runtime: 45 ms, faster than 15.96% of cpp online submissions.
// Memory Usage: 15.2 MB, less than 14.51% of cpp online submissions.
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            d.push_back(a);
        }
    }

    int next() {
        NestedInteger t = d.front();
        d.pop_front();
        return t.getInteger();
    }

    bool hasNext() {
        while (!d.empty()) {
            NestedInteger t = d.front();
            if (t.isInteger()) return true;
            d.pop_front();
            for (int i = 0; i < t.getList().size(); ++i) {
                d.insert(d.begin() + i, t.getList()[i]);
            }
        }
        return false;
    }

private:
    deque<NestedInteger> d;
};
// @lc code=end
