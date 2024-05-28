select distinct (P.product_id), 
(
    case 
        when P1.new_price is null then 10
        else P1.new_price
    end
) as price
from Products P
left join 
(
    select T.product_id, T.new_price
    from Products as T
    left join 
    (
        select product_id, max(change_date) as change_date
        from Products
        where change_date <= '2019-08-16'
        group by product_id
    ) as T1
    on T.product_id = T1.product_id
    where T.change_date = T1.change_date
) as P1
on P.product_id = P1.product_id
