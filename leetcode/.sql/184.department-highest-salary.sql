--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--
-- https://leetcode.com/problems/department-highest-salary/description/
--
-- database
-- Medium (44.38%)
-- Likes:    945
-- Dislikes: 157
-- Total Accepted:    194.6K
-- Total Submissions: 432.9K
-- Testcase Example:  '{"headers": {"Employee": ["id", "name", "salary", "departmentId"], "Department": ["id", "name"]}, "rows": {"Employee": [[1, "Joe", 70000, 1], [2, "Jim", 90000, 1], [3, "Henry", 80000, 2], [4, "Sam", 60000, 2], [5, "Max", 90000, 1]], "Department": [[1, "IT"], [2, "Sales"]]}}'
--
-- Table: Employee
-- 
-- 
-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | id           | int     |
-- | name         | varchar |
-- | salary       | int     |
-- | departmentId | int     |
-- +--------------+---------+
-- id is the primary key column for this table.
-- departmentId is a foreign key of the ID from the Department table.
-- Each row of this table indicates the ID, name, and salary of an employee. It
-- also contains the ID of their department.
-- 
-- 
-- 
-- 
-- Table: Department
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table indicates the ID of a department and its name.
-- 
-- 
-- 
-- 
-- Write an SQL query to find employees who have the highest salary in each of
-- the departments.
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
-- Employee table:
-- +----+-------+--------+--------------+
-- | id | name  | salary | departmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Jim   | 90000  | 1            |
-- | 3  | Henry | 80000  | 2            |
-- | 4  | Sam   | 60000  | 2            |
-- | 5  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+
-- Department table:
-- +----+-------+
-- | id | name  |
-- +----+-------+
-- | 1  | IT    |
-- | 2  | Sales |
-- +----+-------+
-- Output: 
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Jim      | 90000  |
-- | Sales      | Henry    | 80000  |
-- | IT         | Max      | 90000  |
-- +------------+----------+--------+
-- Explanation: Max and Jim both have the highest salary in the IT department
-- and Henry has the highest salary in the Sales department.
-- 
-- 
--

-- @lc solution=start
题目描述：查询每个子组中特定属性最大的条目
-- @lc solution=end

-- @lc code=start
-- 2022-01-09 submission
-- 14/14 cases passed
-- Runtime: 1029 ms, faster than 7.76% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT d.Name as Department, e1.Name as Employee, e1.Salary as Salary
FROM Employee e1 JOIN Department d
ON e1.DepartmentId = d.Id
WHERE e1.Salary =
(SELECT MAX(Salary) FROM Employee e2 WHERE e1.DepartmentId = e2.DepartmentId);
-- @lc code=end

-- @lc code=start
-- 2022-01-09 submission
-- 14/14 cases passed
-- Runtime: 674 ms, faster than 30.49% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT d.name as Department, e.name as Employee, e.salary as Salary
FROM Employee e 
JOIN Department d
ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN 

(SELECT DepartmentId, MAX(salary) 
FROM Employee 
GROUP BY DepartmentId) 
-- @lc code=end