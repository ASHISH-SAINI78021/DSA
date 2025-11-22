# Write your MySQL query statement below
select distinct l1.num as consecutiveNums
from logs l1
left join logs l2
on l1.id + 1 = l2.id
left join logs l3
on l2.id + 1 = l3.id
where l1.num = l2.num and l2.num = l3.num;