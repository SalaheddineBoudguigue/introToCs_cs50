/*SELECT * FROM songs, artists
WHERE songs.artist_id = artists.id
ORDER BY songs.energy DESC
LIMIT 10;*/

SELECT name
FROM songs
WHERE name LIKE "%feat%";