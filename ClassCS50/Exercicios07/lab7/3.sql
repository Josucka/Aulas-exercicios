--No 3.sql, escreva uma consulta SQL para listar os nomes das 5 m�sicas mais longas, em ordem decrescente de dura��o.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada m�sica.
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;