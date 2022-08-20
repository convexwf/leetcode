/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 *
 * https://leetcode.com/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (59.29%)
 * Likes:    1810
 * Dislikes: 451
 * Total Accepted:    157K
 * Total Submissions: 264.8K
 * Testcase Example:  '["Solution","getRandom","getRandom","getRandom","getRandom","getRandom"]\n' +
  '[[[1,2,3]],[],[],[],[],[]]'
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 *
 * Implement the Solution class:
 *
 *
 * Solution(ListNode head) Initializes the object with the head of the
 * singly-linked list head.
 * int getRandom() Chooses a node randomly from the list and returns its value.
 * All the nodes of the list should be equally likely to be chosen.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "getRandom", "getRandom", "getRandom", "getRandom",
 * "getRandom"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * Output
 * [null, 1, 3, 2, 2, 3]
 *
 * Explanation
 * Solution solution = new Solution([1, 2, 3]);
 * solution.getRandom(); // return 1
 * solution.getRandom(); // return 3
 * solution.getRandom(); // return 2
 * solution.getRandom(); // return 2
 * solution.getRandom(); // return 3
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should
 * have equal probability of returning.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list will be in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * At most 10^4 calls will be made to getRandom.
 *
 *
 *
 * Follow up:
 *
 *
 * What if the linked list is extremely large and its length is unknown to
 * you?
 * Could you solve this efficiently without using extra space?
 *
 *
 */

// @lc code=start
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 46 ms, faster than 22.4% of C++ online submissions.
// Memory Usage: 16.7 MB, less than 51.7% of C++ online submissions.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int res = 0, cnt = 1;
        ListNode *cur = head;
        while (cur) {
            int j = rand() % cnt;
            if (j == 0) res = cur->val;
            ++cnt;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
