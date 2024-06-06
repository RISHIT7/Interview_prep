SELECT 
    query_name, 
    ROUND(AVG(CAST(rating AS FLOAT) / position), 2) AS quality, 
    ROUND(CAST(SUM(CASE 
                 WHEN rating < 3 THEN 1
                 ELSE 0
             END) AS FLOAT) * 100 / COUNT(*), 2) AS poor_query_percentage
FROM Queries
WHERE query_name is not null
GROUP BY query_name
ORDER BY quality desc
