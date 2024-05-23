-- INSERT
INSERT INTO Customers (
CustomerName, 
Address, 
City, 
PostalCode,
Country
) VALUES (
'Hekkan Burger',
'Gateveien 15',
'Sandnes',
'4306',
'Norway'
);

-- UPDATE
UPDATE Customers
SET City = 'Oslo';

UPDATE Customers
SET City = 'Oslo',
Country = 'Norway'
WHERE CustomerID = 32;

-- DELETE
DELETE FROM Customers
WHERE Country = 'Norway';
