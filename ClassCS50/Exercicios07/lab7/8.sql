--No 8.sql, escreva uma consulta SQL que lista os nomes das m�sicas que apresentam �feat.� (participa��o) de outros artistas.
    --M�sicas que apresentam outros artistas incluir�o �feat.� no nome da m�sica.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada m�sica.
SELECT name FROM songs WHERE name LIKE "%feat%";