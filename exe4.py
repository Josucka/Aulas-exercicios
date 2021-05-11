def funcionario(hr,salario):
    hr = salario / 40
    adicional = hr * 1.5
    salTotal = adicional + salario
    if hr < 40:
        print(f'salario com acrecimo é: R$ {salTotal:.2f}')
    else:
        hr > 40
        print('Salario sem acrecimo')


salario = float(input('Qual valor do salario do funcionario: '))
hr = float(input('Quantas horas trabalhadas: '))
funcionario(hr,salario)
