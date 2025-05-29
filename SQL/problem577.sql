# Write your MySQL query statement below
## The CASE statement should be used within the SELECT clause to conditionally select values. Here is the corrected query
select e.name, 
       b.bonus
from Employee e
left join Bonus b on e.empId = b.empId
where b.bonus < 1000 or b.bonus is null


