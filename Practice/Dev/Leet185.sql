-- select e.name as Employee, e.salary as Salary, d.name as Department, dense_rank() over(partition by d.name order by e.salary desc) as rank
-- from Employee as e
-- join Department as d
-- on e.departmentId = d.id

select Department, Employee, Salary
from 
(
    select e.name as Employee, e.salary as Salary, d.name as Department, dense_rank() over(partition by d.name order by e.salary desc) as rank
    from Employee as e
    join Department as d
    on e.departmentId = d.id
) as temp
where rank <= 3
order by Department asc, Salary desc
