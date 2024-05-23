-- Intro
SELECT * FROM Customers
WHERE City = 'Berlin';

SELECT * FROM Customers
WHERE NOT City = 'Berlin';

SELECT * FROM Customers
WHERE City = 'Berlin'
AND PostalCode = 32;

SELECT *
FROM HumanResoures.Employee
WHERE BirthDate < '1/1/1980';

-- Using IN Keywords, to reduce th repetitions
SELECT *
FROM HumanResources.vEmployee
WHERE FirstName IN ('Chris', 'Steve', 'Michael', 'Thomas');

-- Using BETWEEN Keyword
SELECT *
FROM Sales.vStoreWitDemographics
WHERE AnuualSales BETWEEN 1000000 AND 2000000

-- wildcard opertors
-- LIKE says, expect a wildcard char, such that all first_name starts with Mi and then maybe any char 
-- in RegEx this would be "Mi" + * -> "Mi%"
SELECT *
FROM HumanResources.vEmployee
WHERE FirstName LIKE 'Mi%';
-- WHERE FirstName LIKE 'Mi_'; -> "Mi" + alphanumeric
