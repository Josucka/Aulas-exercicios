--escreva uma consulta SQL para determinar o ano de nascimento de Emma Stone.
    --Sua consulta deve gerar uma tabela com uma �nica coluna e uma �nica linha (sem incluir o cabe�alho) contendo o ano de nascimento de Emma Stone.
    --Voc� pode presumir que h� apenas uma pessoa no banco de dados com o nome Emma Stone.
SELECT birth FROM people WHERE name = 'Emma Stone';