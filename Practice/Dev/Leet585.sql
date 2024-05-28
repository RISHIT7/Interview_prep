select round(sum(tiv_2016), 2) tiv_2016 from 
(
    select *,
        count(concat(lat, lon)) over (partition by lat, lon order by lat, lon) numb,
        count(tiv_2015) over (partition by tiv_2015 order by tiv_2015) tf
    from Insurance
) as a
where tf > 1 and numb = 1
