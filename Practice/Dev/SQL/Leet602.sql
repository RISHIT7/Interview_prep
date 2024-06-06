-- -- friends except "sent"
-- select accepter_id as id, count(*) as num
-- from RequestAccepted
-- group by accepter_id

-- -- friends due to "sent"
-- select count(*)
-- from RequestAccepted
-- group by requester_id

select top 1 id, sum(num) as num
from(
select id, num
from 
(
    select accepter_id as id, count(*) as num
    from RequestAccepted
    group by accepter_id
) as T1
union all
select id, num
from 
(
    select count(*) as num, requester_id as id
    from RequestAccepted
    group by requester_id
) as T2) as TF
group by TF.id
order by num desc
