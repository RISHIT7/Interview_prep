if exists 
(
    select top 1 num
    from MyNumbers
    group by num
    having count(*) = 1
    order by num desc
)
    select top 1 num
    from MyNumbers
    group by num
    having count(*) = 1
    order by num desc
else 
    select null as num
