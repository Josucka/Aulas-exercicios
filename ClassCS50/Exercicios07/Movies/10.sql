--escreva uma consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0.
    --Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
    --Se uma pessoa dirigiu mais de um filme que recebeu uma classificação de pelo menos 9,0, eles só devem aparecer em seus resultados uma vez.

SELECT DISTINCT name FROM people JOIN directors ON directors.person_id = people.id
                                 JOIN movies ON movies.id = directors.movie_id
                                 JOIN ratings ON ratings.movie_id = movies.id WHERE rating >= 9.0;