def aluno(F = 0, D = 0, C = 0, B = 0, A = 0):
    if nota >= 0 and nota <= 10:
        if nota < 6:
            print('Nota F')
        elif nota < 7:
            print('Nota D')
        elif nota < 8:
            print('Nota C')
        elif nota < 9:
            print('Nota B')
        elif nota <= 10:
            print('Nota A')
        else:
            print('Nota inválida!')  
    return nota

nota = float(input('Nota do aluno: '))
aluno(F = 0, D = 0, C = 0, B = 0, A = 0)
