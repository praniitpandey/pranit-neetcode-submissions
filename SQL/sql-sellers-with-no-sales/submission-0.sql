-- Write your query below
select seller_name from seller
where seller_id not in 
    (select distinct seller_id from orders 
    where sale_date >= '2020-01-01' and sale_date < '2021-01-01')
order by seller_name;