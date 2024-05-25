## Data Types
- Boolean -> `true`, `false`
- Character -> `char`, `varchar`, and `text`
- Numeric -> `integer` and `floating-point`
- Temporal -> `date`, `time`, `timestamp`, and `interval`
- UUID -> `Universally Unique Identifiers`
- Arrays
- JSON
- Hstore key-value pairs
- Special types, like network address and geometric data

> Usually, when creating a table, we must carefully consider the data type, and look at their limitations
> We may review this at [Postgre Datatype Documentation](postgresql.org/docs/current/datatype.html)
> For example for phone numbers, we may choose `varchar`! As leading zeros may cause issues, when dealing with country code

## Primary and Foreign Keys
- __Primary key__ is a column or a group of columns used to identify a row uniquely in a table.
- __Foreign key__ is a field or group of fields in a table that uniquely identifies a row in another table.
- When creating tables and defining columns, we can use contraints to define columns as being a primary key, or attaching a foreign key realtionship to another table.

## Constraints
- __Contraints__ are rules enforced on data columns on table.
- __Column Constarints__
  - NOT NULL
  - UNIQUE
  - PRIMARY KEY
  - FOREIGN KEY
  - CHECK
  - EXCLUSION
- __Table Constarints__
  - CHECK(condition)
  - REFERENCES
  - UNIQUE(column_list)
  - PRIMARY KEY(column_list)
