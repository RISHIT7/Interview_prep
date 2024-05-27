select name
from Employee
where id IN (
    select E1.id
    from Employee E1
    left join Employee E2
    on E1.id = E2.managerId
    where E2.id is not null
    group by E1.id
    having count(*) >= 5
)
