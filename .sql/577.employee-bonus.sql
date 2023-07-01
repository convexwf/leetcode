--
-- @lc app=leetcode id=577 lang=mysql
--
-- [577] Employee Bonus
--

-- @lc code=start
-- 2023-06-28 submission
-- 20/20 cases passed
-- Runtime: 2305 ms, faster than 30.28% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select name, bonus
from Employee left join Bonus
on Employee.EmpId = Bonus.EmpId
where bonus is null or bonus < 1000;
-- @lc code=end
