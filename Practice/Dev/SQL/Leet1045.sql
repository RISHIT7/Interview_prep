select customer_id
from Customer
group by customer_id
having cast(count(distinct product_key) as float)/
(
    select count(*)
    from Product
) = 1
