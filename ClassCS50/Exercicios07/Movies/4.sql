--escreva uma consulta SQL para determinar o número de filmes com uma classificação IMDb de 10,0.
    --Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o número de filmes com uma classificação de 10,0.

SELECT COUNT(rating) FROM ratings WHERE rating = 10;