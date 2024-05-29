select user_id, upper(substring(name, 1, 1)) + lower(substring(name, 2, len(name))) as name
from Users
order by user_id
