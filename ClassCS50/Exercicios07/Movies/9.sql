--escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lan�ado em 2004, ordenado por ano de nascimento.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o nome de cada pessoa.
    --Pessoas com o mesmo ano de nascimento podem ser listadas em qualquer ordem.
    --N�o precisa se preocupar com pessoas que n�o t�m ano de nascimento listado, desde que aqueles que t�m ano de nascimento estejam listados em ordem.
    --Se uma pessoa apareceu em mais de um filme em 2004, ela s� deve aparecer uma vez nos resultados.

SELECT DISTINCT name FROM people JOIN stars ON stars.person_id = people.id
                        JOIN movies ON movies.id = stars.movie_id WHERE movies.year = 2004
                        ORDER BY people.birth ASC;