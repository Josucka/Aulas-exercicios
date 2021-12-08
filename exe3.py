def somaImposto(taxaim, custo):
    taxaImposto = taxaim / 100
    produt = custo - taxaImposto
    print(f'O produto com os devidos impostos custa: R${produt}')
    print(f'O valor do imposto acrecido é: {taxaImposto:.2f}%')


taxaim = float(input('Qual o valor do acrecido: '))
custo = float(input('Quanto custa o prduto: '))

somaImposto(taxaim, custo)
