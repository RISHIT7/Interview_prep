-- Stored Procedures
CREATE PROCEDURE SelectAllpersonAddressWithParams @city nvarchar(30)
AS
-- BEGIN 
SET NOCOUNT ON
SELECT * FROM PERSON.ADDRESS WHERE CITY = @CITY;
-- END
EXEC SelectAllpersonAddressWithParams @city = 'New York'

-- with encryption
CREATE PROCEDURE SelectAllpersonAddressWithParams @city nvarchar(30)
  WITH ENCRYPTION
AS
-- BEGIN 
SET NOCOUNT ON
SELECT * FROM PERSON.ADDRESS WHERE CITY = @CITY;
-- END
EXEC SelectAllpersonAddressWithParams @city = 'New York'
