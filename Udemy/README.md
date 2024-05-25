This is a folder containing codes that I learned from udemy courses, on SQL

```SQL
SELECT cd.facilities.name AS "Facility Name", TO_CHAR(starttime, 'hh24:mm:ss') AS "Start Time"
FROM cd.bookings
INNER JOIN cd.facilities
ON cd.facilities.facid = cd.bookings.facid
WHERE TO_CHAR(starttime, 'yyyy-mm-dd') = '2012-09-21' AND cd.facilities.name LIKE 'Tennis Court%'
ORDER BY starttime
```
