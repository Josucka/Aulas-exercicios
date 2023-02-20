#include <stdio.h>
#include <cs50.h>

int main(void){
    int n;
    do{
        n = get_int("Tamanho da piramedi: ");
    }while(n > 0 && n < 10);
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            if(j + i < n - 1){
                printf(" ");
            }
            else{
                printf("#");
            }

        }
        printf("   #");
        for(int h = 0; h < n; h++){
            if(i + h > n - 1){
                printf("#");
            }
        }
        printf("\n");
    }
}