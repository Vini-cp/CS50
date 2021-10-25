select
    name
from
    people pp
join
    directors dt
on
    pp.id = dt.person_id
join
    movies mv
on
    dt.movie_id = mv.id
join
    ratings rt
on
    mv.id = rt.movie_id
where
    rating >= 9