--escreva uma consulta SQL para determinar o n�mero de filmes com uma classifica��o IMDb de 10,0.
    --Sua consulta deve gerar uma tabela com uma �nica coluna e uma �nica linha (sem incluir o cabe�alho) contendo o n�mero de filmes com uma classifica��o de 10,0.

SELECT COUNT(rating) FROM ratings WHERE rating = 10;