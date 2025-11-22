select person_name
from
(select *,
sum(weight) over(order by turn) as running_wt
from queue) x
where running_wt <= 1000
order by running_wt desc
limit 1;