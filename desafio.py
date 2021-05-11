def data(dia,mes,ano):
    mes[(1,2,3,4,5,6,7,8,9,10,11,12),('janeiro','feverreiro',
    'março','abril','maio','junho','julho','agosto',
    'setembro','outubro','novembro','dezembro')]
    if dia < 31:
        print() 
    if mes > 1 and mes < 12:
        print(mes())
    if ano < 1988: 
        print()
    else: 
        ano > 2050
    return null
    print('data invalida')

dia = int(input('Informe o dia de hoje: '))
mes = int(input('Informe o mês: '))
ano = int(input('Informe o ano: '))
print(f'Data: {dia}/{mes}/{ano}')  
data(dia,mes,ano)
