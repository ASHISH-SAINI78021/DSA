select *
from 
(SELECT 
    e.employee_id, 
    CASE 
        WHEN t.num_dept = 1 THEN e.department_id
        WHEN t.num_dept > 1 AND e.primary_flag = 'Y' THEN e.department_id
    END department_id
FROM employee e
LEFT JOIN (
    SELECT employee_id, COUNT(*) AS num_dept
    FROM employee
    GROUP BY employee_id
) t
ON e.employee_id = t.employee_id) x
where x.department_id is not null;