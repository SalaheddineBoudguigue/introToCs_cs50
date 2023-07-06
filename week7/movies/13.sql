--SELECT name FROM people
--WHERE name = 'Kevin Bacon'
--We should select the movies where 'kevin' starred

SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
WHERE name <> 'Kevin Bacon'
AND stars.movie_id IN (
SELECT stars.movie_id FROM stars
JOIN people ON stars.person_id = people.id
WHERE name = 'Kevin Bacon')
ORDER BY name;