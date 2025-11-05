--
-- @lc app=leetcode id=602 lang=mysql
--
-- [602] Friend Requests II: Who Has the Most Friends
--

-- @lc code=start
-- 2023-06-28 submission
-- 11/11 cases passed
-- Runtime: 651 ms, faster than 30.19% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
select id, count(*) num
from (
  select requester_id id from RequestAccepted
  union all
  select accepter_id id from RequestAccepted
) t1
group by id
order by num desc
limit 1;
-- @lc code=end

