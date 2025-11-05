--
-- @lc app=leetcode id=1045 lang=mysql
--
-- [1045] Customers Who Bought All Products
--

-- @lc code=start
-- 2023-06-29 submission
-- 8/8 cases passed
-- Runtime: 1252 ms, faster than 25.98% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT customer_id FROM (
  -- 应该是右连接，因为要确保顾客买的产品在产品表
SELECT distinct customer_id,c.product_key FROM Customer c
RIGHT JOIN Product p ON c.product_key=p.product_key
) T
GROUP BY customer_id having COUNT(*)=(SELECT COUNT(*) FROM Product)
-- @lc code=end

