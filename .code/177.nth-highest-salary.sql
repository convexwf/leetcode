--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
-- https://leetcode.com/problems/nth-highest-salary/description/
--
-- database
-- Medium (36.65%)
-- Likes:    1162
-- Dislikes: 683
-- Total Accepted:    252.4K
-- Total Submissions: 688.6K
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

-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      
  );
END
-- @lc code=end

