with all_movies as (
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
        name = 'Chadwick Boseman'
)

select
    title
from
    all_movies am
join
    ratings rt
on
    am.id = rt.movie_id
order by
    rating desc
limit
    5