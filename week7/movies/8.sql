--SELECT name FROM people
--JOIN stars ON people.id = stars.person_id
--JOIN movies ON movies.id = stars.movie_id
--WHERE movies.title = "Toy Story";

SELECT people.name FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND movies.title = "Toy Story";
