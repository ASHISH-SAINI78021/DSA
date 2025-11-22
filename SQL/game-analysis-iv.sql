# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity), 2) as fraction
from activity a
inner join
(select player_id, min(event_date) as day
from activity
group by player_id) as t
on a.player_id = t.player_id
and t.day = subdate(a.event_date, interval 1 day);