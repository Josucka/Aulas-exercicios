def corpo(peso, altura):
    imc = peso / altura
    print(f'O IMC corporeo dessa pessoa é: {imc:.2f}')

peso = float(input('Qual seu peso: '))
altura = float(input('Qual sua altura: '))
corpo(peso, altura)
