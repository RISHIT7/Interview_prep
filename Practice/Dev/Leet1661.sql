select W1.machine_id, round(avg(W2.timestamp - W1.timestamp), 3) as processing_time
from Activity W1
join Activity W2
ON W1.machine_id = W2.machine_id and W1.process_id = W2.process_id and (W1.activity_type = 'start' and W2.activity_type = 'end')
group by W1.machine_id
order by processing_time
