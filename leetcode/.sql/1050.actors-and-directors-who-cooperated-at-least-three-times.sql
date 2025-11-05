--
-- @lc app=leetcode id=1050 lang=mysql
--
-- [1050] Actors and Directors Who Cooperated At Least Three Times
--

-- @lc code=start
-- 2023-06-29 submission
-- 12/12 cases passed
-- Runtime: 782 ms, faster than 46.03% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT 
    actor_id, director_id
FROM 
    actordirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;
-- @lc code=end

