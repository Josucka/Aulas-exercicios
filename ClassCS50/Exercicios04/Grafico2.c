#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    // Garanta o uso adequado
    if (argc != 3)
    {
        fprintf(stderr, "Use: copy SOURCE DESTINATION\n");
        return 1;
    }
    // Abrir o arquivo de entrada
    FILE* source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("N�o foi poss�vel abrir %s.\n", argv[1]);
        return 1;
    }
    // Abrir o arquivo de sa�da
    FILE* destination = fopen(argv[2], "w");
    if (destination == NULL)
    {
        fclose(source);
        printf("N�o foi poss�vel criar %s.\n", argv[2]);
        return 1;
    }
    // Copiar um byte de cada vez do arquivo origem(source) para o arquivo destino(destination)
    BYTE buffer;
    while (fread(&buffer, sizeof(BYTE), 1, source))
    {
        fwrite(&buffer, sizeof(BYTE), 1, destination);
    }
    // Fechar os arquivos
    fclose(source);
    fclose(destination);
    return 0;
}