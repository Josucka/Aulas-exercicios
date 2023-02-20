text = input("Text: ")

counter_letter = 0
counter_words = 0
counter_sentence = 0

text = text.lower()

counter_letter = len(text.replace(' ', '').replace('?', '').replace("'", "").replace('.', '').replace(',', ''))
counter_words = len(text.split(' '))
counter_sentence = len(text.replace('!', '.').replace('?', '.').split('.')) - 1

L = float(counter_letter) * 100 / float(counter_words)
S = float(counter_sentence) * 100 / float(counter_words)
index = 0.0588 * L - 0.296 * S - 15.8

if(index >= 16):
    print("Grade 16+\n")
else:
    if (index <= 1):
        print("Before grade 1\n")
    else:
        print(f"Grade {int(index + 0.5)}\n")