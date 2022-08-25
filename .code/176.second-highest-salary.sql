--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--
-- https://leetcode.com/problems/second-highest-salary/description/
--
-- database
-- Medium (35.81%)
-- Likes:    2037
-- Dislikes: 752
-- Total Accepted:    509.7K
-- Total Submissions: 1.4M
-- Testcase Example:  '{"headers":{"Employee":["id","salary"]},"rows":{"Employee":[[1,100],[2,200],[3,300]]}}'
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
-- Write an SQL query to report the second highest salary from the Employee
-- table. If there is no second highest salary, the query should report null.
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
-- Output: 
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | 200                 |
-- +---------------------+
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
-- Output: 
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | null                |
-- +---------------------+
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below

-- @lc code=end
