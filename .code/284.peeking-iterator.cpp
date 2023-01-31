/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 *
 * https://leetcode.com/problems/peeking-iterator/description/
 *
 * algorithms
 * Medium (58.49%)
 * Likes:    1703
 * Dislikes: 981
 * Total Accepted:    203.4K
 * Total Submissions: 347.8K
 * Testcase Example:  '["PeekingIterator","next","peek","next","next","hasNext"]\n' +
  '[[[1,2,3]],[],[],[],[],[]]'
 *
 * Design an iterator that supports the peek operation on an existing iterator
 * in addition to the hasNext and the next operations.
 *
 * Implement the PeekingIterator class:
 *
 *
 * PeekingIterator(Iterator<int> nums) Initializes the object with the given
 * integer iterator iterator.
 * int next() Returns the next element in the array and moves the pointer to
 * the next element.
 * boolean hasNext() Returns true if there are still elements in the array.
 * int peek() Returns the next element in the array without moving the
 * pointer.
 *
 *
 * Note: Each language may have a different implementation of the constructor
 * and Iterator, but they all support the int next() and boolean hasNext()
 * functions.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * Output
 * [null, 1, 2, 2, 3, false]
 *
 * Explanation
 * PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
 * peekingIterator.next();    // return 1, the pointer moves to the next
 * element [1,2,3].
 * peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
 * peekingIterator.next();    // return 2, the pointer moves to the next
 * element [1,2,3]
 * peekingIterator.next();    // return 3, the pointer moves to the next
 * element [1,2,3]
 * peekingIterator.hasNext(); // return False
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 * All the calls to next and peek are valid.
 * At most 1000 calls will be made to next, hasNext, and peek.
 *
 *
 *
 * Follow up: How would you extend your design to be generic and work with all
 * types, not just integer?
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
