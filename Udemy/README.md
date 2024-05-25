This is a folder containing codes that I learned from udemy courses, on SQL

```SQL
SELECT cd.facilities.name AS "Facility Name", TO_CHAR(starttime, 'hh24:mm:ss') AS "Start Time"
FROM cd.bookings
INNER JOIN cd.facilities
ON cd.facilities.facid = cd.bookings.facid
WHERE TO_CHAR(starttime, 'yyyy-mm-dd') = '2012-09-21' AND cd.facilities.name LIKE 'Tennis Court%'
ORDER BY starttime
```

```SQL
SELECT 
SUM (
	CASE rating
		WHEN 'R' THEN 1
		ELSE 0
	END
) AS r,
SUM (
	CASE rating
		WHEN 'PG' THEN 1
		ELSE 0
	END
) AS pg,
SUM (
	CASE rating
		WHEN 'PG-13' THEN 1
		ELSE 0
	END
) AS pg13
FROM film
```
