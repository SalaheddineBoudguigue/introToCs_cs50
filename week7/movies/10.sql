SELECT DISTINCT P.name FROM directors AS D, ratings AS R, people AS P
WHERE P.id = D.person_id
AND D.movie_id = R.movie_id
AND R.rating >= 9.0;