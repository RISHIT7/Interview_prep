CREATE DATABASE testDB;

DROP DATABASE testDB;

CREATE TABLE Persons (
  PersonID int,
  LastName varchar(255),
  FirstName varchar(255),
  Address varchar(255),
  City varchar(255) 
);

-- To Delete the TABLE itself
DROP TABLE Persons;

-- Use the TRUNCATE statement to delete all data inside a table.
TRUNCATE TABLE Person;

ALTER TABLE Persons
ADD Birthday DATE;

ALTER TABLE Persons
DROP COLUMN Birthday;
