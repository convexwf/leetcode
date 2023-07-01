--
-- @lc app=leetcode id=1068 lang=mysql
--
-- [1068] Product Sales Analysis I
--

-- @lc code=start
-- 2023-06-29 submission
-- 10/10 cases passed
-- Runtime: 2311 ms, faster than 31.56% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select p.product_name, s.year, s.price
from Sales s, Product p
where s.product_id = p.product_id;
-- @lc code=end

