/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

// @lc code=start
// 2025-10-16 submission
// 1569/1569 cases passed
// Runtime: 4 ms, faster than 11.56% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 57.95% of cpp online submissions.
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummyHead := &ListNode{}
    current := dummyHead
    carry := 0
    for l1 != nil || l2 != nil || carry != 0 {
        var x, y int
        if l1 != nil {
            x = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            y = l2.Val
            l2 = l2.Next
        }
        sum := x + y + carry
        carry = sum / 10
        current.Next = &ListNode{Val: sum % 10}
        current = current.Next
    }
    return dummyHead.Next
}
// @lc code=end

