select 
    a.sell_date, 
    count(distinct a.product) as num_sold,
    stuff(
        replace (
            replace(
                (SELECT distinct b.product
                FROM Activities b
                WHERE a.sell_date = b.sell_date
                order by b.product
                FOR XML PATH ('')),
                '</product>', ''
            ),
            '<product>', ','
        ),
    1, 1, '') as products
from Activities a
group by a.sell_date
