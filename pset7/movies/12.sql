with jonny_movies as (
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
        name = 'Johnny Depp'
)

select
    title
from
    jonny_movies jmv
join
    stars st
on
    jmv.id = st.movie_id
join
    people pp
on
    st.person_id = pp.id
where
    name = 'Helena Bonham Carter'