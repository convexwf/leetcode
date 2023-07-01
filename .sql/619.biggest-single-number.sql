--
-- @lc app=leetcode id=619 lang=mysql
--
-- [619] Biggest Single Number
--

-- @lc code=start
-- 2023-06-28 submission
-- 17/17 cases passed
-- Runtime: 1252 ms, faster than 5.71% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT IF(COUNT(num)=1, num, NULL) AS num
FROM MyNumbers
GROUP BY num
ORDER BY COUNT(num), num DESC
LIMIT 1
-- @lc code=end
