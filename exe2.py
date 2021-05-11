def tipagem(num):
    if num == 0:
        print("0")
    elif num < 0:
        print('N')
    else:
        print('P')


num = float(input('digite um numero: '))
tipagem(num)