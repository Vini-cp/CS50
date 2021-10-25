select
    count(title)
from
    movies mv
join
    ratings rt
on
    mv.id = rt.movie_id
where
    rating = 10