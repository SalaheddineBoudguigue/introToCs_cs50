--SELECT Count(people.name) FROM people
--JOIN stars ON people.id = stars.person_id
--JOIN movies ON movies.id = stars.movie_id
--WHERE movies.year = 2004
--ORDER BY people.birth;

SELECT DISTINCT p.name FROM people AS p, stars AS s, movies AS m
WHERE m.id = s.movie_id
AND s.person_id = p.id
AND m.year = 2004
ORDER BY p.birth;
