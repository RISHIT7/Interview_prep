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
