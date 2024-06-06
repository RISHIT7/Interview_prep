select visited_on, sum(amount) over (order by visited_on rows between 6 preceding and current row) as amount,
round(avg(amount*1.00) over (order by visited_on rows between 6 preceding and current row), 2) as average_amount
from 
(
    select visited_on, sum(amount) as amount
    from Customer
    group by visited_on
) as temp
order by visited_on
offset 6 rows;
