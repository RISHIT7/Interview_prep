-- Use the editor to create new tables, insert data and all other SQL operations.

-- Literal SELECT statements
-- SQL uses apostrophe, not doubleinv commas
SELECT 'Rishit';
-- SQL uses CSV, so comma can beused to create two columns
SELECT 'Rishit', 'Jakharia';
SELECT (5*5) - (5*3);

-- Basic SELECT statements
-- SELECT [Column 1], [Column 2]
-- FROM [Database Name].[Scema Name].[Table Name]

-- SELECT first_name, last_name
SELECT TOP 3
FROM Customers;
SELECT TOP 10 PERCENT first_name, last_name
FROM Customers;

-- what if we want to see all columns 
SELECT *
FROM Customers

SELECT TOP 100 first_name, last_name
FROM Customers
  
-- To select distinct values
SELECT DISTINCT first_name, last_name
FROM Customers

SELECT TOP 100 *
FROM Customers

SELECT first_name AS [Customer First Name], last_name AS "Customer Last Name"
FROM Customers
