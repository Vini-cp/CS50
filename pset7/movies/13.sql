with kevin_movies as (
    select
        distinct mv.id as id,
        title
    from
        movies mv
    join
        stars st
    on
        mv.id = st.movie_id
    join
        people pp
    on
        st.person_id = pp.id
    where
        name = 'Kevin Bacon'
        and birth = 1958
)

select
    distinct name
from
    people pp
join
    stars st
on
    pp.id = st.person_id
join
    kevin_movies kmv
on
    st.movie_id = kmv.id
where
    name <> 'Kevin Bacon'