-- Alias is imp
SELECT tableA.col, tableB.col
FROM table AS tableA
JOIN table AS tableB 
ON tableA.some_col = tableB.some_col

-- Employee send report to other employee
SELECT employeeA.name, employeeB.name
FROM exployee AS employeeA
JOIN employee AS employeeB 
ON employeeA.emp_id = employeeB.report_id
