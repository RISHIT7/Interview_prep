select format(trans_date, 'yyyy-MM') as month,
    country,
    count(*) as trans_count,
    sum(
        case state
            when 'approved' then 1
            else 0
        end
    ) as approved_count,
    sum(amount) as trans_total_amount,
    sum(
        case state
            when 'approved' then amount
            else 0
        end
    ) as approved_total_amount
from Transactions
group by format(trans_date, 'yyyy-MM'), country
