--escreva uma consulta SQL para listar os t�tulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o t�tulo de cada filme.
    --Voc� pode presumir que h� apenas uma pessoa no banco de dados com o nome Johnny Depp.
    --Voc� pode presumir que h� apenas uma pessoa no banco de dados com o nome Helena Bonham Carter.

SELECT title FROM movies JOIN stars ON stars.movie_id = movies.id
                         JOIN people ON people.id = stars.person_id WHERE people.name = "Johnny Depp"
                         AND title IN (
                            SELECT title FROM movies JOIN stars ON stars.movie_id = movies.id
                                                     JOIN people ON people.id = stars.person_id WHERE people.name = "Helena Bonham Carter"
                         );