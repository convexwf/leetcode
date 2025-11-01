/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
// 3. 哈希表
// 2025-10-16 submission
// 63/63 cases passed
// Runtime: 0 ms, faster than 100% of golang online submissions.
// Memory Usage: 9.6 MB, less than 40.46% of golang online submissions.
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, num := range nums {
		complement := target - num
		if j, ok := m[complement]; ok {
			return []int{j, i}
		}
		m[num] = i
	}
	return nil
}
// @lc code=end

