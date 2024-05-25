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
> For example for phone numbers, we may choose `serial` or `bigserial` or even `varchar`! As leading zeros may cause issues, when dealing with country code

