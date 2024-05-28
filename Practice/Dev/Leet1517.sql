SELECT user_id, name, mail FROM Users
WHERE mail LIKE '[a-zA-Z]%@leetcode.com' AND LEFT(mail, LEN(mail) - 13) NOT LIKE '%[^0-9a-zA-Z_.-]%'
