-- This code shows all the consequtive logins, we only want the first, thus
select round(cast((
    select distinct count(A1.player_id)
    from Activity A1
    join Activity A2
    on A1.player_id = A2.player_id
    where A1.event_date = DATEADD(day, -1, A2.event_date)
) as float) / (
    select count(distinct player_id)
    from Activity
), 2) as fraction

-- this is the correct solution
select round((count( distinct a1.player_id)*1.0) / (
    select count(distinct player_id)
    from Activity
), 2) as fraction
from (
    select player_id, min(event_date) as event_date
    from Activity
    group by player_id
) as a1
inner join Activity a2 on a1.player_id = a2.player_id
where datediff(day, a1.event_Date, a2.event_date) = 1
