select P.product_id, isnull((round(cast(sum(price*units) as float)/sum(units), 2)), 0)as average_price
-- select *
from Prices P
left join UnitsSold Un
on Un.product_id = P.product_id
where (purchase_date between start_date and end_date) or purchase_date is null
group by P.product_id
