select contest_id, round(cast(count(*) as float)/ (
    select count(user_id)
    from Users
) *100, 2) as percentage
from Register
group by contest_id
order by percentage desc
