# Write your MySQL query statement below
select distinct email as Email
from (
    select email, count(*) over(partition by email) as rn
    from person 
) t
where rn > 1;