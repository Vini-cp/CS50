select
    avg(rating)
from
    ratings rt
join
    movies mv
on
    rt.movie_id = mv.id
where
    year = 2012