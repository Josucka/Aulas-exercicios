from reportlab.pdfgen import canvas

def GeneratePDF(list):
    try:
        nome_pdf = input('Informe o nome do PDF: ')
        pdf = canvas.Canvas('{}.pdf'.format(nome_pdf))
        x = 720
        for nome, idade in list.items():
            x -= 20
            pdf.drawString(247, x, '{} : {}'.format(nome, idade))
        pdf.setTitle(nome_pdf)
        pdf.setFont("Helvetica-Oblique", 14)
        pdf.drawString(245, 750, 'Lista de clientes')
        pdf.setFont("Helvetica-Bold", 12)
        pdf.drawString(245, 724, 'Nome e idade')
        pdf.save()
        print('{}.pdf criado com sucesso!'.format(nome_pdf))
    except:
        print('Erro ao gerar {}.pdf'.fotmat(nome_pdf))


lista = {'felipe' : '24', 'jose': '42', 'maria': '22', 'eduardo': '31'}

GeneratePDF(lista)