select
    title,
    rating
from
    movies mv
join
    ratings rt
on
    mv.id = rt.movie_id
where
    year = 2010
order by
    rating desc,
    title asc