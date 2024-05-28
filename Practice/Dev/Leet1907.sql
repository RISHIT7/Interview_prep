SELECT 
    categories.category AS category,
    COUNT(Accounts.income) AS accounts_count
FROM 
    (
        SELECT 'Low Salary' AS category
        UNION ALL
        SELECT 'Average Salary' AS category
        UNION ALL
        SELECT 'High Salary' AS category
    ) AS categories
LEFT JOIN Accounts ON 
    CASE
        WHEN Accounts.income < 20000 THEN 'Low Salary'
        WHEN Accounts.income > 50000 THEN 'High Salary'
        ELSE 'Average Salary'
    END = categories.category
GROUP BY
    categories.category;
