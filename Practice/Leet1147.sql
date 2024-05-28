select round((
    select cast(count(*) as float)
    from (
        select customer_id
        from Delivery
        group by customer_id
        having min(order_date) = min(customer_pref_delivery_date)
    ) as T
)*100 / count(distinct customer_id), 2) as immediate_percentage
from Delivery
