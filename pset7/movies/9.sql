select
    name
from
    people pp
join
    stars st
on
    pp.id = st.person_id
join
    movies mv
on
    st.movie_id = mv.id
where
    year = 2004
order by
    birth asc