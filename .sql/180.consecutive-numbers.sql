--
-- @lc app=leetcode id=180 lang=mysql
--
-- [180] Consecutive Numbers
--
-- https://leetcode.com/problems/consecutive-numbers/description/
--
-- database
-- Medium (44.63%)
-- Likes:    840
-- Dislikes: 171
-- Total Accepted:    165.6K
-- Total Submissions: 369K
-- Testcase Example:  '{"headers": {"Logs": ["id", "num"]}, "rows": {"Logs": [[1, 1], [2, 1], [3, 1], [4, 2], [5, 1], [6, 2], [7, 2]]}}'
--
-- Table: Logs
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- id is the primary key for this table.
-- 
-- 
-- 
-- 
-- Write an SQL query to find all numbers that appear at least three times
-- consecutively.
-- 
-- Return the result table in any order.
-- 
-- The query result format is in the following example.
-- 
-- 
-- Example 1:
-- 
-- 
-- Input: 
-- Logs table:
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
-- Output: 
-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
-- Explanation: 1 is the only number that appears consecutively for at least
-- three times.
-- 
-- 
--

-- @lc solution=start
题目描述：查询连续出现记录（三次以上）
-- @lc solution=end

-- @lc code=start
-- 2020-09-17 submission
-- 21/21 cases passed
-- Runtime: 405 ms, faster than 84.15% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select distinct(l1.num) as `ConsecutiveNums`
from Logs l1 join Logs l2 join Logs l3
where l1.id = l2.id+1 and l1.num = l2.num 
and l2.id = l3.id+1 and l2.num = l3.num ;
-- @lc code=end

