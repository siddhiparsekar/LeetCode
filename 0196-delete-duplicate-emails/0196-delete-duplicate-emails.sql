# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
Delete b
FROM person a, person b
WHERE a.email = b.email and a.id < b.id;