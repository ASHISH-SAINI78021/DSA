# Write your MySQL query statement below
select *
from cinema 
where description not like '%boring%'
and id % 2 <> 0
order by rating desc;