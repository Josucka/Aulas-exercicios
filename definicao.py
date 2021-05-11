#Faça um programa que tenha uma função chamada área(), que receba as dimensões de um terreno retangular (largura e comprimento) e mostre a área do terreno:
#ESCOPO = Espaço

def area(largura, comprimento):

    ''' 
    -> serve pra documentar a funcao.
    ex help(area)

    '''
    area = largura * comprimento
    print(f'area do terreno {area}m²')

lar = float(input('digite a largura do terreno: '))
comp = float(input('digite o comprimento do terreno: '))
area(lar,comp)
