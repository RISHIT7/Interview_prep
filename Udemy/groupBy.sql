SELECT SalesPersonID, SUM(TotalDues) AS  [Total Sales]
FROM Sales.SalesOrderHeader
GROUP BY SalesPersonID
-- gives Total Sales, vs ID

SELECT 
  ProductID, 
  SUM(Quantity) AS [Total In Stock],
  COUNT(*) AS [Total Locations]
FROM Production.ProductInventory
GROUP BY ProductID

-- GROUP BY + WHERE Clause
SELECT 
  ST.Name AS [Territory Name],
  P.FirstName + ' ' +  P.LastName AS SalesPersonName,
  SUM(TotalDues) AS [Total Sales]
FROM Sales.SalesOrderHeader SOH
INNER JOIN Sales.SalesPerson SP
ON SP.BusinessEntityID = SOH.SalesPersonID
INNER JOIN Person.Person P
ON P.BusinessEntityID = SP.BusinessEntityID
INNER JOIN Sales.SalesTerritory ST
ON ST.TerritoryID = SOH.TerritoryID
WHERE OrderDate BETWEEN '1/1/2006' AND '12/31/2006'
GROUP BY ST.Name, P.FirstName + ' ' + P.LastName
ORDER BY 1, 2
