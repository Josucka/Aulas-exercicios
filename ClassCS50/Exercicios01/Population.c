#include <stdio.h>
#include <cs50.h>

int main(void) {
    int quantInit;
    int quantFinal;
    int anos = 0;

    do {
        quantInit = get_int("digite a quantidade inicial da populacao: ");
        if (quantInit >= 9) {
            do {
                quantFinal = get_int("digite a quantidade Final da populacao: ");
            } while (quantFinal < quantInit);
        }
    } while (quantInit < 9);


    printf("\nCalculando o tempo: \n");

    anos = quantInit + (quantFinal / 3) - (quantFinal / 4);

    printf("foram passados %i anos!\n", anos);
}