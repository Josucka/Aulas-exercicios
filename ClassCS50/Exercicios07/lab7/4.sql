--No 4.sql, escreva uma consulta SQL que liste os nomes de quaisquer m�sicas que tenham dan�abilidade, energia e val�ncia maior que 0,75.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada m�sica.
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75
                                                 AND valence > 0.75;