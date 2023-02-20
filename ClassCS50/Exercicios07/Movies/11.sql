--escreva uma consulta SQL para listar os t�tulos dos cinco filmes com melhor classifica��o (em ordem) que Chadwick Boseman estrelou, come�ando com os de maior classifica��o.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o t�tulo de cada filme.
    --Voc� pode presumir que h� apenas uma pessoa no banco de dados com o nome Chadwick Boseman.

SELECT title FROM movies JOIN ratings ON ratings.movie_id = movies.id
                         JOIN stars ON stars.movie_id = movies.id
                         JOIN people ON stars.person_id = people.id
                         WHERE people.name = "Chadwick Boseman" ORDER BY ratings.rating DESC
                         LIMIT 5;