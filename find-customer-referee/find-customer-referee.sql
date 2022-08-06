# Write your MySQL query statement below
select name from Customer 
where id not in(select c.id from Customer c 
where
referee_id = 2);