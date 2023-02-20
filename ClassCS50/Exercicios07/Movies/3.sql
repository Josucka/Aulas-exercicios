--escreva uma consulta SQL para listar os t�tulos de todos os filmes com data de lan�amento igual ou posterior a 2018, em ordem alfab�tica.
    --Sua consulta deve gerar uma tabela com uma �nica coluna para o t�tulo de cada filme.
    --Os filmes lan�ados em 2018 devem ser inclu�dos, assim como os filmes com datas de lan�amento no futuro.

SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC;