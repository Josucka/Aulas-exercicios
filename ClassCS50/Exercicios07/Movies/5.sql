--escreva uma consulta SQL para listar os t�tulos e anos de lan�amento de todos os filmes de Harry Potter, em ordem cronol�gica.
    --Sua consulta deve gerar uma tabela com duas colunas, uma para o t�tulo de cada filme e outra para o ano de lan�amento de cada filme.
    --Voc� pode presumir que o t�tulo de todos os filmes de Harry Potter come�ar� com as palavras �Harry Potter� e que se o t�tulo de um filme come�ar com as palavras �Harry Potter�, � um filme de Harry Potter.

SELECT year, title FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year ASC;