SELECT * FROM Customers
ORDER BY City;

SELECT * FROM Customers
ORDER BY City DESC;

SELECT * FROM Customers
ORDER BY City, Country;

-- IN GENERAL
-- SELECT Column1, Column2 AS [Some Alias]
-- FROM SchemaName.TableName 
-- WHERE ColumnName {Comaprison Op} [Filtering Criteria]
-- ORDER BY ColumnName, [ColumnOrdinal], [ColumnAlias] [ASC/DISC]

-- This columnAlias, and COlumn Ordinal can only be used on ORDER BY notin WHERE
-- As during compiletime, SELECT is evaluated secon to last, just before ORDER BY
