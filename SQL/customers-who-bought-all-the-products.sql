# Write your MySQL query statement below
select t.customer_id
from
(select if(count(distinct product_key) = (select count(product_key) from product), customer_id, 0) as customer_id
from customer
group by customer_id) as t
where t.customer_id <> 0;