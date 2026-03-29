-- Write your query below
select name from customers
where 1 = 1
and id not in
    (select distinct customer_id 
    from orders)
;