SELECT AVG(rating) AS "Average rating of 2012 movies" FROM ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE movies.year = 2012;