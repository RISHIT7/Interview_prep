CREATE DATABASE testDB;

DROP DATABASE testDB;

CREATE TABLE Syntax (
  column_name TYPE column_constraint,
  column_name TYPE column_constraint,
  table_constraint table_constraint
) INHERITS existing_table_name;

-- SERIAL, In PostgreSQL, a squence is a speical kind of database object that generates a squence integers
CREATE TABLE players (
  player_id SERIAL PRIMARY KEY,
  age SMALLINT NOT NULL
);

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
