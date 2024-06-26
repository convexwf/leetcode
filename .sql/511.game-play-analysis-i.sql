--
-- @lc app=leetcode id=511 lang=mysql
--
-- [511] Game Play Analysis I
--
-- https://leetcode.com/problems/game-play-analysis-i/description/
--
-- database
-- Easy (78.20%)
-- Likes:    453
-- Dislikes: 17
-- Total Accepted:    133.7K
-- Total Submissions: 171K
-- Testcase Example:  '{"headers":{"Activity":["player_id","device_id","event_date","games_played"]},"rows":{"Activity":[[1,2,"2016-03-01",5],[1,2,"2016-05-02",6],[2,3,"2017-06-25",1],[3,1,"2016-03-02",0],[3,4,"2018-07-03",5]]}}'
--
-- Table: Activity
--
--
-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | player_id    | int     |
-- | device_id    | int     |
-- | event_date   | date    |
-- | games_played | int     |
-- +--------------+---------+
-- (player_id, event_date) is the primary key of this table.
-- This table shows the activity of players of some games.
-- Each row is a record of a player who logged in and played a number of games
-- (possibly 0) before logging out on someday using some device.
--
--
--
--
-- Write an SQL query to report the first login date for each player.
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
-- Activity table:
-- +-----------+-----------+------------+--------------+
-- | player_id | device_id | event_date | games_played |
-- +-----------+-----------+------------+--------------+
-- | 1         | 2         | 2016-03-01 | 5            |
-- | 1         | 2         | 2016-05-02 | 6            |
-- | 2         | 3         | 2017-06-25 | 1            |
-- | 3         | 1         | 2016-03-02 | 0            |
-- | 3         | 4         | 2018-07-03 | 5            |
-- +-----------+-----------+------------+--------------+
-- Output:
-- +-----------+-------------+
-- | player_id | first_login |
-- +-----------+-------------+
-- | 1         | 2016-03-01  |
-- | 2         | 2017-06-25  |
-- | 3         | 2016-03-02  |
-- +-----------+-------------+
--
--
--

-- @lc code=start
-- 2022-11-29 submission
-- 12/12 cases passed
-- Runtime: 646 ms, faster than 94.75% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id
ORDER BY player_id;
-- @lc code=end
