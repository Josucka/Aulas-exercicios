--escreva uma consulta SQL para listar todos os filmes lan�ados em 2010 e suas classifica��es, em ordem decrescente por classifica��o. Para filmes com a mesma classifica��o, ordene-os em ordem alfab�tica por t�tulo.
    --Sua consulta deve gerar uma tabela com duas colunas, uma para o t�tulo de cada filme e outra para a classifica��o de cada filme.
    --Filmes sem classifica��o n�o devem ser inclu�dos no resultado.

SELECT title, rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title ASC;