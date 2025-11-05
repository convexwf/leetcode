--
-- @lc app=leetcode id=1070 lang=mysql
--
-- [1070] Product Sales Analysis III
--

-- @lc code=start
-- 2023-06-29 submission
-- 10/10 cases passed
-- Runtime: 1645 ms, faster than 95.28% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select
	sales.product_id,
	first_year,
	quantity,
	price
from (
	select product_id, min(year) first_year from sales group by product_id
) as temp 
left join sales on temp.product_id = sales.product_id 
and temp.first_year = sales.year;
-- @lc code=end

