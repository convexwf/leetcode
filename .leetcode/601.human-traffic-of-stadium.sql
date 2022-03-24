--
-- @lc app=leetcode id=601 lang=mysql
--
-- [601] Human Traffic of Stadium
--
-- https://leetcode.com/problems/human-traffic-of-stadium/description/
--
-- database
-- Hard (48.43%)
-- Likes:    304
-- Dislikes: 463
-- Total Accepted:    54.7K
-- Total Submissions: 112.2K
-- Testcase Example:  '{"headers": {"Stadium": ["id", "visit_date", "people"]}, "rows": {"Stadium": [[1, "2017-01-01", 10], [2, "2017-01-02", 109], [3, "2017-01-03", 150], [4, "2017-01-04", 99], [5, "2017-01-05", 145], [6, "2017-01-06", 1455], [7, "2017-01-07", 199], [8, "2017-01-09", 188]]}}'
--
-- Table: Stadium
-- 
-- 
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | visit_date    | date    |
-- | people        | int     |
-- +---------------+---------+
-- visit_date is the primary key for this table.
-- Each row of this table contains the visit date and visit id to the stadium
-- with the number of people during the visit.
-- No two rows will have the same visit_date, and as the id increases, the
-- dates increase as well.
-- 
-- 
-- 
-- 
-- Write an SQL query to display the records with three or more rows with
-- consecutive id's, and the number of people is greater than or equal to 100
-- for each.
-- 
-- Return the result table ordered by visit_date in ascending order.
-- 
-- The query result format is in the following example.
-- 
-- 
-- Example 1:
-- 
-- 
-- Input: 
-- Stadium table:
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 1    | 2017-01-01 | 10        |
-- | 2    | 2017-01-02 | 109       |
-- | 3    | 2017-01-03 | 150       |
-- | 4    | 2017-01-04 | 99        |
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- Output: 
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- Explanation: 
-- The four rows with ids 5, 6, 7, and 8 have consecutive ids and each of them
-- has >= 100 people attended. Note that row 8 was included even though the
-- visit_date was not the next day after row 7.
-- The rows with ids 2 and 3 are not included because we need at least three
-- consecutive ids.
-- 
-- 
--

-- @lc solution=start
题目描述：查询每个子组中连续满足条件的条目
-- @lc solution=end

-- @lc code=start
-- 2022-01-09 submission
-- 14/14 cases passed
-- Runtime: 348 ms, faster than 42.30% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT
    DISTINCT t1.*
FROM
    stadium t1,
    stadium t2,
    stadium t3
WHERE
    t1.people >= 100
AND t2.people >= 100
AND t3.people >= 100
AND (
    (
        t1.id - t2.id = 1
        AND t1.id - t3.id = 2
        AND t2.id - t3.id = 1
    )
    OR (
        t2.id - t1.id = 1
        AND t2.id - t3.id = 2
        AND t1.id - t3.id = 1
    )
    OR (
        t3.id - t2.id = 1
        AND t2.id - t1.id = 1
        AND t3.id - t1.id = 2
    )
)
ORDER BY
    t1.id
-- @lc code=end

