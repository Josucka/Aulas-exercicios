--No 7.sql, escreva uma consulta SQL que retorne a energia m�dia das m�sicas de Drake.
    --Sua consulta deve gerar uma tabela com uma �nica coluna e uma �nica linha contendo a energia m�dia.
    --Voc� n�o deve fazer suposi��es sobre qual � o artist_id de Drake.
SELECT AVG(energy) FROM songs WHERE artist_id = (
    SELECT id FROM artists WHERE name = "Drake"
);