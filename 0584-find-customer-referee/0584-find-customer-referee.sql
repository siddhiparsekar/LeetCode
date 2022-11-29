# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE  referee_id is null or referee_id <>2;


# null is never considered while doing comparison only the values from 0 are 
# So when u dont specially declare "referee_id is null" all the names with referee_id!=2 are considered but referee_id=null is as if it doesnt exist i.e it is ignored!