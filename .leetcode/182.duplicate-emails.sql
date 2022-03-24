--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--
-- https://leetcode.com/problems/duplicate-emails/description/
--
-- database
-- Easy (67.58%)
-- Likes:    913
-- Dislikes: 45
-- Total Accepted:    309.6K
-- Total Submissions: 455.9K
-- Testcase Example:  '{"headers": {"Person": ["id", "email"]}, "rows": {"Person": [[1, "a@b.com"], [2, "c@d.com"], [3, "a@b.com"]]}}'
--
-- Table: Person
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | email       | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table contains an email. The emails will not contain
-- uppercase letters.
-- 
-- 
-- 
-- 
-- Write an SQL query to report all the duplicate emails.
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
-- Person table:
-- +----+---------+
-- | id | email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- Output: 
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
-- Explanation: a@b.com is repeated two times.
-- 
-- 
--

-- @lc solution=start
题目描述：查询重复条目
-- @lc solution=end

-- @lc code=start
-- 2022-01-08 submission
-- 15/15 cases passed
-- Runtime: 284 ms, faster than 91.19% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT Email 
FROM Person 
GROUP BY Email
HAVING COUNT(*) > 1;
-- @lc code=end

