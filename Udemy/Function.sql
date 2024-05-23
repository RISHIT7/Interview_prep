-- MIN
SELECT MIN(Price)
FROM Products;

-- MAX
SELECT MAX(Price)
FROM Products;

-- COUNT
-- count the number or entries from Product where Price = 18
SELECT COUNT(*)
FROM Products 
WHERE Price = 18;

SELECT COUNT(DISTINCT FirstName)
FROM Person.Person;

-- AVG
SELECT AVG(Price)
FROM Products;

-- SUM
SELECT SUM(Price)
FROM Products;
