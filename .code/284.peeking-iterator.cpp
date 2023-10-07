/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
// 2023-01-30 submission
// 14/14 cases passed
// Runtime: 4 ms, faster than 56.29% of C++ online submissions.
// Memory Usage: 7.8 MB, less than 10.44% of C++ online submissions.
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
// 2023-01-30 submission
// 14/14 cases passed
// Runtime: 3 ms, faster than 78.53% of C++ online submissions.
// Memory Usage: 7.4 MB, less than 87.43% of C++ online submissions.
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _flag = false;
    }

    int peek() {
        if (!_flag) _value = Iterator::next();
        _flag = true;
        return _value;
    }

    int next() {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }

    bool hasNext() const {
        return _flag || Iterator::hasNext();
    }

private:
    int _value;
    bool _flag;
};
// @lc code=end
