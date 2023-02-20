--escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.
    --Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
    --Você pode presumir que há apenas um filme no banco de dados com o título Toy Story.

SELECT name FROM people JOIN stars on stars.person_id = people.id
                        JOIN movies ON movies.id = stars.movie_id WHERE movies.title = "Toy Story";