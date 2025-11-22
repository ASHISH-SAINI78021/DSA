# Write your MySQL query statement below

select e.name, b.bonus
from employee e
left join bonus b
on e.empId = b.empId
where ifnull(b.bonus , 0) < 1000;