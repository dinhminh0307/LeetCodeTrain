# Write your MySQL query statement below
select Visits.customer_id, COUNT(Visits.visit_id) AS count_no_trans 
from Visits
where Visits.visit_id not in (select Transactions.visit_id from Transactions)
GROUP BY Visits.customer_id;