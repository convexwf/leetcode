--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
-- https://leetcode.com/problems/nth-highest-salary/description/
--
-- database
-- Medium (35.22%)
-- Likes:    896
-- Dislikes: 589
-- Total Accepted:    208.8K
-- Total Submissions: 590.4K
-- Testcase Example:  '{"headers": {"Employee": ["id", "salary"]}, "argument": 2, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
--
-- Table: Employee
-- 
-- 
-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | salary      | int  |
-- +-------------+------+
-- id is the primary key column for this table.
-- Each row of this table contains information about the salary of an
-- employee.
-- 
-- 
-- 
-- 
-- Write an SQL query to report the n^th highest salary from the Employee
-- table. If there is no n^th highest salary, the query should report null.
-- 
-- The query result format is in the following example.
-- 
-- 
-- Example 1:
-- 
-- 
-- Input: 
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- n = 2
-- Output: 
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
-- 
-- 
-- Example 2:
-- 
-- 
-- Input: 
-- Employee table:
-- +----+--------+
-- | id | salary |
-- +----+--------+
-- | 1  | 100    |
-- +----+--------+
-- n = 2
-- Output: 
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | null                   |
-- +------------------------+
-- 
-- 
--

-- @lc solution=start
题目描述：查询第 n 大记录
-- @lc solution=end

-- @lc code=start
-- 2022-01-03 submission
-- 14/14 cases passed
-- Runtime: 273 ms, faster than 93.86% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
    RETURN (
        SELECT DISTINCT Salary FROM Employee GROUP BY Salary
        ORDER BY Salary DESC LIMIT 1 OFFSET N
    );
END
-- @lc code=end

