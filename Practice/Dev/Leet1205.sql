select top 1 person_name from (
    select person_name, turn, sum(weight) over (order by turn) cumulative from Queue
) a where cumulative <= 1000 order by turn desc
