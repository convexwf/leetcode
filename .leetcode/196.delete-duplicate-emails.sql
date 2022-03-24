--
-- @lc app=leetcode id=196 lang=mysql
--
-- [196] Delete Duplicate Emails
--
-- https://leetcode.com/problems/delete-duplicate-emails/description/
--
-- database
-- Easy (49.70%)
-- Likes:    720
-- Dislikes: 1147
-- Total Accepted:    190.7K
-- Total Submissions: 380.4K
-- Testcase Example:  '{"headers": {"Person": ["id", "email"]}, "rows": {"Person": [[1, "john@example.com"], [2, "bob@example.com"], [3, "john@example.com"]]}}'
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
-- Write an SQL query to delete all the duplicate emails, keeping only one
-- unique email with the smallest id.
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
-- +----+------------------+
-- | id | email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- | 3  | john@example.com |
-- +----+------------------+
-- Output: 
-- +----+------------------+
-- | id | email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- +----+------------------+
-- Explanation: john@example.com is repeated two times. We keep the row with
-- the smallest Id = 1.
-- 
-- 
--

-- @lc solution=start
题目描述：删除重复条目
-- @lc solution=end

-- @lc code=start
-- 2019-09-20 submission
-- 22/22 cases passed
-- Runtime: 708 ms, faster than 65.07% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
DELETE p2
FROM Person p1, Person p2
WHERE p2.Id>p1.Id and p1.Email=p2.Email
-- @lc code=end

-- @lc code=start
-- 2022-01-09 submission
-- 22/22 cases passed
-- Runtime: 476 ms, faster than 88.32% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
delete from person 
where id in (select id from (select p1.id from person p1 join person p2 on p1.email= p2.email and p1.id > p2.id) as derived);
-- @lc code=end