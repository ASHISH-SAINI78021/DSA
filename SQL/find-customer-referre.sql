# Write your MySQL query statement below
select name
from customer
where ifnull(referee_id, 0) <> 2;