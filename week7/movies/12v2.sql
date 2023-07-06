select movies.title  from movies,stars,people
where movies.id = stars.movie_id and people.id = stars.person_id and name="Johnny Depp";

INTERSECT

select movies.title from movies,stars,people
where movies.id = stars.movie_id and people.id = stars.person_id and name="Helena Bonham Carter";
