# Write your MySQL query statement below
select cat.category, count(t.account_id) as accounts_count
from 
(select "Low Salary" as category union select "Average Salary" union select "High Salary") as cat
left join 
(select *, 
case when income < 20000 then "Low Salary" 
when income between 20000 and 50000 then "Average Salary"
else "High Salary"
end as category
from accounts) t
on cat.category = t.category
group by cat.category;