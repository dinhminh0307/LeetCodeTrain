# Write your MySQL query statement below
select distinct author_id as id  from Views -- distinct keyword to avoid duplicate querry
where author_id = viewer_id 
order by author_id asc