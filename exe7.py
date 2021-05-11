def num(N1=0,N2=0):
    if N1 == N2:
        print('Os numeros são iguais!')
    elif N1 > N2:
        print(f'Valor menor é: {N2}')
    elif N1 < N2:
        print(f'Valor menor é: {N1}')
    

N1 = float(input('digite um valor: '))
N2 = float(input('digite um valor: '))
num(N1,N2)
