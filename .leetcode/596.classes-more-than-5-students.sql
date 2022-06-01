--
-- @lc app=leetcode id=596 lang=mysql
--
-- [596] Classes More Than 5 Students
--
-- https://leetcode.com/problems/classes-more-than-5-students/description/
--
-- database
-- Easy (39.86%)
-- Likes:    373
-- Dislikes: 887
-- Total Accepted:    137.9K
-- Total Submissions: 342.9K
-- Testcase Example:  '{"headers": {"Courses": ["student", "class"]}, "rows": {"Courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Computer"], ["G", "Math"], ["H", "Math"], ["I", "Math"]]}}'
--
-- Table: Courses
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | student     | varchar |
-- | class       | varchar |
-- +-------------+---------+
-- (student, class) is the primary key column for this table.
-- Each row of this table indicates the name of a student and the class in
-- which they are enrolled.
-- 
-- 
-- 
-- 
-- Write an SQL query to report all the classes that have at least five
-- students.
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
-- Courses table:
-- +---------+----------+
-- | student | class    |
-- +---------+----------+
-- | A       | Math     |
-- | B       | English  |
-- | C       | Math     |
-- | D       | Biology  |
-- | E       | Math     |
-- | F       | Computer |
-- | G       | Math     |
-- | H       | Math     |
-- | I       | Math     |
-- +---------+----------+
-- Output: 
-- +---------+
-- | class   |
-- +---------+
-- | Math    |
-- +---------+
-- Explanation: 
-- - Math has 6 students, so we include it.
-- - English has 1 student, so we do not include it.
-- - Biology has 1 student, so we do not include it.
-- - Computer has 1 student, so we do not include it.
-- 
-- 
--

-- @lc code=start
-- 2022-01-09 submission
-- 9/9 cases passed
-- Runtime: 280 ms, faster than 54.63% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select class
from Courses
group by class
having count(*) >= 3;
-- @lc code=end
