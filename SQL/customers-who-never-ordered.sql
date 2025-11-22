# Write your MySQL query statement below
with cte as (
    select c.*, o.id as i, 
    count(o.id) over(partition by o.id) as Customers
    from customers c
    left join orders o
    on c.id = o.customerId
) 

select name as Customers from cted
where Customers = 0;