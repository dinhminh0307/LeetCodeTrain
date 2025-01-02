# Write your MySQL query statement below
select Product.product_name, Sales.year, Sales.price
from Product
inner join Sales on Sales.product_id = Product.product_id # inner join the 2 tables with the common value