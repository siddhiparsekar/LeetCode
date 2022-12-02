# Write your MySQL query statement below

# Almost immediately detected, the only serious challange of this problem is how to aggregate the product names in one cell. In MySql, this can be done using GROUP_CONCAT, in which you can also specify the sorting mechanism for the group concatenation (aggregation). The rest is simple.


SELECT 
    sell_date, 
    COUNT(DISTINCT product) AS num_sold, 
    GROUP_CONCAT(DISTINCT product order by product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;