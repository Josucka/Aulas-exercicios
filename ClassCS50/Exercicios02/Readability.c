#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    string textUser = get_string("digite uma frase: ");
    //string textUser = "As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.";
    int N = strlen(textUser);
    int letter = 0, space = 0;
    double words = 0, sentence = 0;
    double L = 0, S = 0, indice = 0;

    for (int i = 0; i < N; i++) {
        if (isalpha(textUser[i])) {
            letter++;
        }
        else if (isspace(textUser[i])) {
            space++;
        }
        else if (textUser[i] == '.' || textUser[i] == '!' || textUser[i] == '?') {
            sentence++;
        }
    }

    words = space + 1;
    L = letter * 100 / words;
    S = sentence * 100 / words;
    indice = round((0.0588 * L) - (0.286 * S) - 15.8);

    if (indice < 1) {
        printf("Before Grade 1.\n");
    }
    else if (indice > 1 && indice <= 15) {
        printf("Grade %i\n", (int)indice);
    }
    else if (indice >= 16) {
        printf("Grade 16+\n");
    }
}
