select round(cast((
    select count(A1.player_id)
    from Activity A1
    join Activity A2
    on A1.player_id = A2.player_id
    where A1.event_date = DATEADD(day, -1, A2.event_date)
) as float) / (
    select count(distinct player_id)
    from Activity
), 2) as fraction
