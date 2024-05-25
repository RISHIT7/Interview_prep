CASE 
  WHEN condition1 THEN result1
  WHEN condition2 THEN result2
  ELSE some_other_result
END

-- EXAMPLE
SELECT a,
CASE 
  WHEN a = 1 THEN 'one'
  WHEN a = 2 THEN 'two'
  ELSE 'other' AS label
END 
FROM test;

-- CASE EXPRESSION
SELECT a,
CASE a
  WHEN 1 THEN 'one'
  WHEN 2 THEN 'two'
  ELSE 'other'
END
FROM test;
