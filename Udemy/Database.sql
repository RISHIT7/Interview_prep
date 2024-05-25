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

-- ALTER
ALTER TABLE Persons
ADD Birthday DATE;

ALTER TABLE Persons
DROP COLUMN Birthday;

ALTER TABLE table_name
ALTER COLUMN col_name
SET DEFAULT value
-- DROP DEFAULT value
-- SET NOT NULL
-- ADD CONSTRAINT constraint_name

-- INSERT
INSERT INTO table(column1, column2, ...)
VALUES
  (value1, value2, ...)
  (value1, value2, ...);

-- constraint also must match!
INSERT INTO table(column1, column2, ...)
SELECT column1, column2
FROM another_table
WHERE condition;

-- UPDATE
UPDATE account
SET last_login = CURRENT_TIMESTAMP
WHERE last_login IS NULL;

UPDATE account
SET loast_login = tableB.new_col
FROM tableB
WHERE account.id = tableB.id

-- RETURNING
UPDATE account
SET last_login = created_on
RETURNING account_id, last_login

-- DELETE
DELETE FROM tableA
USING tableA
WHERE tableA.id = tableB.id
RETURNING tableA.id

-- CHECK
CREATE TABLE example (
  ex_id SERIAL PRIMARY KEY,
  age SMALLINT CHECK(age > 21),
  parent_age SMALLINT CHECK(
    parent_age > age
  )
);
