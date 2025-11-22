# Write your MySQL query statement below
select st.student_id, st.student_name, sb.subject_name, count(e.subject_name) as attended_exams
from students st
cross join subjects sb
left join examinations e
on st.student_id = e.student_id
and sb.subject_name = e.subject_name
group by st.student_name, st.student_id, sb.subject_name
order by st.student_id, sb.subject_name;