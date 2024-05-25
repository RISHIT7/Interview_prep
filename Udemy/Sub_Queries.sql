-- students above the average grade
SELECT student, grade
FROM test_scores
WHERE grade > (
  SELECT AVG(grade) 
  FROM test_scores
);

-- subquery to operate on a seperate table
SELECT student, grade
FROM test_scores
WHERE student IN (
  SELECT student
  FROM honor_roll_table
);

-- Use EXTRACT()
SELECT column_name
FROM table_name
WHERE EXISTS (
  SELECT column_name 
  FROM table_name
  WHERE condition
);
