--No 6.sql, escreva uma consulta SQL que lista os nomes das m�sicas de Post Malone.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada m�sica.
    --Voc� n�o deve fazer suposi��es sobre qual � o artist_id de Post Malone.
SELECT name FROM songs WHERE artist_id = (
    SELECT id FROM artists WHERE name = "Post Malone"
);