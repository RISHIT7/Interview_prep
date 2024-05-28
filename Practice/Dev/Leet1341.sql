-- -- user
-- select top 1 name
-- from MovieRating
-- join Users
-- on Users.user_id = MovieRating.user_id
-- group by name
-- order by count(rating) desc, name

-- -- avg rating
-- select title, avg(rating)
-- from MovieRating
-- join Movies
-- on MovieRating.movie_id = Movies.movie_id
-- where created_at between '2020-02-1' and '2020-02-28'
-- group by title
-- order by avg(cast(rating as float)) desc, title

select T1.name as results
from(
select top 1 name
from MovieRating
join Users
on Users.user_id = MovieRating.user_id
group by name
order by count(rating) desc, name
) as T1 union all
select T2.title as results
from(
select top 1 title
from MovieRating
join Movies
on MovieRating.movie_id = Movies.movie_id
where created_at between '2020-02-1' and '2020-02-28'
group by title
order by avg(cast(rating as float)) desc, title
) as T2
