# Write your MySQL query statement below
select t.*, s.quantity, s.price
from sales s
inner join
(select product_id, min(year) as first_year
from sales
group by product_id) as t
on s.product_id = t.product_id
where s.year = t.first_year;