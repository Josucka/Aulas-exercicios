#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2 || argv[1] == 0) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int n = 0;
    int key = 0, test = 0;
    n = strlen(argv[1]);

    for (int i = 0; i < n; i++) {
        if (isdigit(argv[1][i]) == 0) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argv[1]);

    string text = get_string("Plaintext: ");

    int t = strlen(text);
    printf("ciphertext: ");

    for (int i = 0; i < t; i++) {
        if (isalpha(text[i]) && islower(text[i])) {
            text[i] = text[i] - 97;
            text[i] = (text[i] + key) % 26;
            printf("%c", text[i] + 97);
        }
        else if (isalpha(text[i]) && isupper(text[i])) {
            text[i] = text[i] - 65;
            text[i] = (text[i] + key) % 26;
            printf("%c", text[i] + 65);
        }
        else {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}