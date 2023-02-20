#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./Substitution key\n");
        return 1;
    }

    int n = 0;
    string key = 0;
    n = strlen(argv[1]);

    for (int i = 0; i < n; i++) {
        if (isalpha(argv[1][i]) == 0) {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }
    }

    if (n != 26) {
        printf("Key must contain 26 characters.");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (argv[1][i] == argv[1][j] || toupper(argv[1][i]) == toupper(argv[1][j])) {
                printf("Key must not contain repeat characters.\n");
                return 1;
            }
        }
    }

    int k = 0;
    key = argv[1];
    string text = get_string("plaintext: ");
    int t = strlen(text);

    printf("ciphertext: ");
    for (int i = 0; i < t; i++) {
        if (isalpha(text[i]) && islower(text[i])) {
            k = text[i] - 97;
            printf("%c", tolower(text[1][k]));
        }
        else if (isalpha(text[i]) && toupper(text[i]))
        {
            k = text[i] - 65;
            printf("%c", toupper(argv[1][k]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

//  Erro**
// Exercicios02/ $ make Substitution
// Substitution.c:46:41: error: subscripted value is not an array, pointer, or vector
//             printf("%c", tolower(text[1][k]));
//                                  ~~~~~~~^~
// 1 error generated.
// make: *** [<builtin>: Substitution] Error 1
