# Write your MySQL query statement below
select Department, Employee, Salary from
(select d.name as Department, e.name as Employee, e.salary as Salary,
dense_rank() over(partition by d.name order by e.salary desc) as drn
from employee e
inner join department d
on e.departmentId = d.id) t
where drn <= 3;