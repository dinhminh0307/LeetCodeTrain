# Write your MySQL query statement below
select w1.id
from Weather w1 # left join the table with itself to access to the previous rows
# Compare date add 1 day to the date format sql
left join Weather w2 on w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
where w1.temperature > w2.temperature # querry to get the rows which temperature > previous