--
-- @lc app=leetcode id=570 lang=mysql
--
-- [570] Managers with at Least 5 Direct Reports
--

-- @lc code=start
-- 2023-06-28 submission
-- 8/8 cases passed
-- Runtime: 835 ms, faster than 7.31% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT
    Name
FROM
    Employee AS t1 JOIN
    (SELECT
        ManagerId
    FROM
        Employee
    GROUP BY ManagerId
    HAVING COUNT(ManagerId) >= 5) AS t2
    ON t1.Id = t2.ManagerId
;
-- @lc code=end

