SELECT *
FROM movies, ratings
WHERE ratings.movie_id = movies.id
AND rating > 9
AND votes > 100000;