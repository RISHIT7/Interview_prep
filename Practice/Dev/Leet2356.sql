select teacher_id, count(*) as cnt
from (
    select teacher_id, subject_id
    from Teacher
    group by teacher_id, subject_id
) as t
group by teacher_id
