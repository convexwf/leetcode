/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 */

// @lc code=start
// 2. 哈希表
// 2023-05-15 submission
// 57/57 cases passed
// Runtime: 2 ms, faster than 80.15% of rust online submissions.
// Memory Usage: 2.3 MB, less than 43.68% of rust online submissions.
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: std::collections::HashMap<i32, i32> = std::collections::HashMap::new();
        for (i, num) in nums.iter().enumerate() {
            let complement = target - num;
            if map.contains_key(&complement) {
                return vec![*map.get(&complement).unwrap(), i as i32];
            }
            map.insert(*num, i as i32);
        }
        vec![]
    }
}
// @lc code=end

