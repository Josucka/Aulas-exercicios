--escreva uma consulta SQL para determinar a avalia��o m�dia de todos os filmes lan�ados em 2012.
    --Sua consulta deve gerar uma tabela com uma �nica coluna e uma �nica linha (sem incluir o cabe�alho) contendo a classifica��o m�dia.

SELECT AVG(rating) FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2012;