select max(salary) as SecondHighestSalary
from Employee
where salary not in (
    select salary
    from Employee
    where salary = (
        select max(salary)
        from Employee
)
)
