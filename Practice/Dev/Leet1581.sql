select customer_id, count(*) as count_no_trans
from Visits V
left join Transactions T
on V.visit_id = T.visit_id
where transaction_id is null
group by customer_id
order by count_no_trans
