#include <stdio.h>
#include <cs50.h>
#include <math.h>

float troco;
int m25, m10, m5, m1;
int cent, count;

int main(void) {
    do {
        troco = get_float("Qual valor de troco? ");
    } while (troco <= 0);
    cent = troco * 100;
    printf("Valor de troco é: %i\n", cent);

    m25 = 25;
    m10 = 10;
    m5 = 5;
    m1 = 1;
    count = 0;
    while (cent >= 25) {
        count++;
        cent = cent - m25;
    }
    while (cent >= 10) {
        count++;
        cent = cent - m10;
    }
    while (cent >= 5) {
        count++;
        cent = cent - m5;
    }
    while (cent >= 1) {
        count++;
        cent = cent - m1;
    }
    printf("Quantidade de moedas: %i\n", count);
}