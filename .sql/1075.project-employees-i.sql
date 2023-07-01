--
-- @lc app=leetcode id=1075 lang=mysql
--
-- [1075] Project Employees I
--

-- @lc code=start
-- 2023-06-29 submission
-- 12/12 cases passed
-- Runtime: 1552 ms, faster than 71.21% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select p.project_id, ROUND(AVG(e.experience_years), 2) as average_years 
from Project p, Employee e 
where p.employee_id = e.employee_id 
group by p.project_id;
-- @lc code=end

