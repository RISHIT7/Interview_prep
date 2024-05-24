-- INNER JOIN -> INTERSECTION
SELECT P.Name, P.ProductNumber, Name
FROM Prodution.Product P
INNER JOIN Production.ProductSubcategory PS
ON P.ProductSubcategoryID = PS.ProductSubcategoryID

SELECT 
  PS.Name AS ProductSubCategoryName
  PC.Name AS ProductCategoryName
FROM Production.ProductSubcategory PS
INNER JOIN Production.ProductCategory PC
ON PS.ProductCategoryID = PC.ProductCategoryID

-- LEFT AND RIGHT OUTER JOINS -> A INTERSECTION B + A -> A OR A INTERSECTION B + B -> B
SELECT P.Name, P.PRoductNumber, PS.Name AS ProductSubCategoryName
FROM Production.Product.P
LEFT OUTER JOIN Production.ProductSubcategory PS
ON PS.ProductSubcategoryID = P.ProductSubcategoryID
-- MORE ROWS FROM LEFT TABLE, RIGHT LEFT NULL

-- Doing it all together
SELECT 
  P.FirstName, P.LastName,
  SOH.SalesOrderNumber,
  SOH.TotalDue AS SalesAmount,
  T.Name AS TerritoryName
FROM Sales.SalesOrderHeader SOH
LEFT OUTER JOIN Sales.SalesPerson SP
ON SP.BusinessEntityID = SOH.SalesPersonID
LEFT OUTER JOIN HumanResources.Exployee E
ON E.BusinessEntityID = SP.BusinessEntityID
LEFT OUTER JOIN Person.Person P
ON P.BusinessEntityID = E.BusinessEntityID
LEFT OUTER JOIN Sales.SalesTerritory T
ON T.TerritoryID = SOH.TerritoryID
WHERE T.Name = 'Northwest'
ORDER BY SOH.TotalDue DESC

-- Symmetric difference
SELECT * FROM TableA
FULL OUTER JOIN TableB
ON TableA.col_match - TableB.col_match
WHERE TableA.id IS NULL OR TableB.id IS NULL
