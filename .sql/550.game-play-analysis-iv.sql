--
-- @lc app=leetcode id=550 lang=mysql
--
-- [550] Game Play Analysis IV
--

-- @lc code=start
-- 2023-06-28 submission
-- 14/14 cases passed
-- Runtime: 985 ms, faster than 76.61% of mysql online submissions.
-- Memory Usage: 0 MB, less than 100% of mysql online submissions.
# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from Activity),2) as fraction
from (select player_id,min(event_date) as first_login
        from Activity
        group by player_id) t1,
    (select player_id,event_date
    from (
    select player_id,dense_rank() over(partition by player_id order by event_date) as my_rank,event_date
    from Activity
    ) t
    where t.my_rank = 2
        ) t2
where t1.player_id = t2.player_id and DATEDIFF(t2.event_date,t1.first_login)=1
-- @lc code=end

