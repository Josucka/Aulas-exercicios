--escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon tamb�m estrelou.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada pessoa.
    --Pode haver v�rias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas Kevin Bacon nascido em 1958.
    --O pr�prio Kevin Bacon n�o deve ser inclu�do na lista resultante.

SELECT DISTINCT name FROM people JOIN stars ON stars.person_id = people.id
                                 JOIN movies ON movies.id = stars.movie_id
                                 WHERE movies.id IN (
                                    SELECT movies.id FROM movies JOIN stars ON stars.movie_id = movies.id
                                                                 JOIN people ON people.id = stars.person_id
                                                                 WHERE people.name = "Kevin Bacon" AND people.birth = "1958"
                                 ) AND people.name != "Kevin Bacon" ORDER BY name;