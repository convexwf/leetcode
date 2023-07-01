--
-- @lc app=leetcode id=585 lang=mysql
--
-- [585] Investments in 2016
--

-- @lc code=start
-- 2023-06-28 submission
-- 19/19 cases passed
-- Runtime: 889 ms, faster than 91.56% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
SELECT
    round(sum(TIV_2016),2) as 'TIV_2016'
FROM
    insurance
WHERE
    insurance.TIV_2015 IN
    (
      SELECT
        TIV_2015
      FROM
        insurance
      GROUP BY TIV_2015
      HAVING COUNT(*) > 1
    )
    AND CONCAT(LAT, LON) IN
    (
      SELECT
        CONCAT(LAT, LON)
      FROM
        insurance
      GROUP BY LAT , LON
      HAVING COUNT(*) = 1
    )
;
-- @lc code=end

