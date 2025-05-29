# Write your MySQL query statement below
## join the do the querrt
select EmployeeUNI.unique_id, Employees.name
from Employees
left join EmployeeUNI on Employees.id = EmployeeUNI.id; # left join the left table (Empolyees to employee uni)
 