select customer_id, customer_name from customers
where 1 = 1
    and customer_id in 
        (select distinct customer_id from orders where product_name = 'A')
    and customer_id in 
        (select distinct customer_id from orders where product_name = 'B')
    and customer_id not in 
        (select distinct customer_id from orders where product_name = 'C')
order by customer_name
;