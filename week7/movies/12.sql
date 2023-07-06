SELECT title FROM movies, stars, people
WHERE  movies.id = stars.movie_id
AND people.id = stars.person_id

AND people.name = 'Johnny Depp'

AND stars.movie_id IN (SELECT stars.movie_id FROM stars
    JOIN people ON people.id = stars.person_id
    WHERE name = 'Helena Bonham Carter');

