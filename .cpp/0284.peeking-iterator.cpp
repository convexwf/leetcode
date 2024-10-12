/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
// 1. 局部变量
// 2023-01-30 submission
// 14/14 cases passed
// Runtime: 4 ms, faster than 56.29% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 10.44% of cpp online submissions.
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return Iterator(*this).next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};
// @lc code=end

// @lc code=start
// 2. 私有变量
// 2023-01-30 submission
// 14/14 cases passed
// Runtime: 3 ms, faster than 78.53% of cpp online submissions.
// Memory Usage: 7.4 MB, less than 87.43% of cpp online submissions.
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
    }

    int peek() {
        if (!hasPeeked) {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    int next() {
        if (!hasPeeked) {
            return Iterator::next();
        }
        hasPeeked = false;
        return peekedElement;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }

private:
    bool hasPeeked;
    int peekedElement;
};
// @lc code=end
