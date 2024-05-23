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

-- AVG
SELECT AVG(Price)
FROM Products;

-- SUM
SELECT SUM(Price)
FROM Products;
