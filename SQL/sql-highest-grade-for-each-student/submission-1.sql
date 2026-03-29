with cte as 
    (select 
        student_id, 
        exam_id,
        score,
        rank() over (partition by student_id order by score desc, exam_id) personal_score_rank
    from exam_results)
select student_id, exam_id, score from cte
where personal_score_rank = 1
order by student_id
;