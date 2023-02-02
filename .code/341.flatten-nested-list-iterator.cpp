/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (61.71%)
 * Likes:    4108
 * Dislikes: 1420
 * Total Accepted:    355.2K
 * Total Submissions: 575.6K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * You are given a nested list of integers nestedList. Each element is either
 * an integer or a list whose elements may also be integers or other lists.
 * Implement an iterator to flatten it.
 * 
 * Implement the NestedIterator class:
 * 
 * 
 * NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with
 * the nested list nestedList.
 * int next() Returns the next integer in the nested list.
 * boolean hasNext() Returns true if there are still some integers in the
 * nested list and false otherwise.
 * 
 * 
 * Your code will be tested with the following pseudocode:
 * 
 * 
 * initialize iterator with nestedList
 * res = []
 * while iterator.hasNext()
 * ⁠   append iterator.next() to the end of res
 * return res
 * 
 * 
 * If res matches the expected flattened list, then your code will be judged as
 * correct.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nestedList = [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns false, the
 * order of elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nestedList = [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns false, the
 * order of elements returned by next should be: [1,4,6].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nestedList.length <= 500
 * The values of the integers in the nested list is in the range [-10^6,
 * 10^6].
 * 
 * 
 */

// @lc code=start
// 2023-01-31 submission
// 43/43 cases passed
// Runtime: 28 ms, faster than 27.47% of C++ online submissions.
// Memory Usage: 14.4 MB, less than 26.88% of C++ online submissions.
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
        NestedInteger t = s.top(); s.pop();
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
// 2023-01-31 submission
// 43/43 cases passed
// Runtime: 45 ms, faster than 15.96% of C++ online submissions.
// Memory Usage: 15.2 MB, less than 14.51% of C++ online submissions.
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            d.push_back(a);
        }
    }

    int next() {
        NestedInteger t = d.front(); d.pop_front();
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