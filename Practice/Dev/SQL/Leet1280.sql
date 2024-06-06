select 
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    count(Examinations.subject_name) as attended_exams
from 
    students join subjects left join Examinations
on 
    Students.student_id = Examinations.student_id
    and
    subjects.subject_name = Examinations.subject_name
group by 
    Students.student_id, 
    Students.student_name,
    Subjects.subject_name
order by  
    Students.student_id,
    Subjects.subject_name;

-- CROSS JOINS
SELECT 
    s.student_id,
    s.student_name,
    sj.subject_name,
    COUNT(e.student_id) as 'attended_exams'
FROM Students s CROSS JOIN Subjects sj

LEFT JOIN Examinations e
ON      s.student_id = e.student_id 
and sj.subject_name =e.subject_name 

GROUP BY s.student_id,s.student_name, sj.subject_name
ORDER BY s.student_id, sj.subject_name;
