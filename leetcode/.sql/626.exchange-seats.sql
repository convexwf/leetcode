--
-- @lc app=leetcode id=626 lang=mysql
--
-- [626] Exchange Seats
--
-- https://leetcode.com/problems/exchange-seats/description/
--
-- database
-- Medium (68.25%)
-- Likes:    595
-- Dislikes: 333
-- Total Accepted:    90.8K
-- Total Submissions: 132.7K
-- Testcase Example:  '{"headers": {"Seat": ["id","student"]}, "rows": {"Seat": [[1,"Abbot"],[2,"Doris"],[3,"Emerson"],[4,"Green"],[5,"Jeames"]]}}'
--
-- Table: Seat
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table indicates the name and the ID of a student.
-- id is a continuous increment.
-- 
-- 
-- 
-- 
-- Write an SQL query to swap the seat id of every two consecutive students. If
-- the number of students is odd, the id of the last student is not swapped.
-- 
-- Return the result table ordered by id in ascending order.
-- 
-- The query result format is in the following example.
-- 
-- 
-- Example 1:
-- 
-- 
-- Input: 
-- Seat table:
-- +----+---------+
-- | id | student |
-- +----+---------+
-- | 1  | Abbot   |
-- | 2  | Doris   |
-- | 3  | Emerson |
-- | 4  | Green   |
-- | 5  | Jeames  |
-- +----+---------+
-- Output: 
-- +----+---------+
-- | id | student |
-- +----+---------+
-- | 1  | Doris   |
-- | 2  | Abbot   |
-- | 3  | Green   |
-- | 4  | Emerson |
-- | 5  | Jeames  |
-- +----+---------+
-- Explanation: 
-- Note that if the number of students is odd, there is no need to change the
-- last one's seat.
-- 
-- 
--

-- @lc code=start
-- 2022-01-08 submission
-- 12/12 cases passed
-- Runtime: 331 ms, faster than 30.27% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select if(id%2=0, id-1, 
if(id = (select count(*) from Seat), id, id+1)) as `id`, student
from Seat
order by id;
-- @lc code=end

-- @lc code=start
-- 2022-01-08 submission
-- 12/12 cases passed
-- Runtime: 438 ms, faster than 11.67% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT ROW_NUMBER() OVER() id, student
FROM seat
ORDER BY IF(MOD(id, 2) = 0, id-1, id+1)
-- @lc code=end