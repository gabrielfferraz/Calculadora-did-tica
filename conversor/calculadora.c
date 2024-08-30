//GABRIEL FERREIRA FERRAZ 
//gff@cesar.school
#include <stdio.h>
#include <stdlib.h>


void decimalParaBinario(int decimal) {
    int binario[32];
    int i = 0;

    printf("Conversão de %d para binário:\n", decimal);
    while (decimal > 0) {
        binario[i] = decimal % 2;
        printf("%d / 2 = %d, resto = %d\n", decimal, decimal / 2, binario[i]);
        decimal = decimal / 2;
        i++;
    }

    printf("Resultado em binário: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binario[j]);
    printf("\n\n");
}

void decimalParaOctal(int decimal) {
    int octal[32];
    int i = 0;

    printf("Conversão de %d para octal:\n", decimal);
    while (decimal > 0) {
        octal[i] = decimal % 8;
        printf("%d / 8 = %d, resto = %d\n", decimal, decimal / 8, octal[i]);
        decimal = decimal / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octal[j]);
    printf("\n\n");
}

void decimalParaHexadecimal(int decimal) {
    char hexadecimal[32];
    int i = 0;

    printf("Conversão de %d para hexadecimal:\n", decimal);
    while (decimal > 0) {
        int resto = decimal % 16;
        if (resto < 10) {
            hexadecimal[i] = 48 + resto;  
        } else {
            hexadecimal[i] = 55 + resto;  
        }
        printf("%d / 16 = %d, resto = %c\n", decimal, decimal / 16, hexadecimal[i]);
        decimal = decimal / 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
    printf("\n\n");
}
void decimalParaBCD(int decimal) {
    int bcd[32];
    int i = 0;

    printf("Conversão de %d para código BCD:\n", decimal);
    while (decimal > 0) {
        int digito = decimal % 10;
        printf("Dígito: %d\n", digito);
        for (int j = 0; j < 4; j++) {
            bcd[i + j] = digito % 2;
            printf("%d / 2 = %d, resto = %d\n", digito, digito / 2, bcd[i + j]);
            digito = digito / 2;
        }
        decimal = decimal / 10;
        i += 4;
    }

    printf("Resultado em código BCD: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bcd[j]);
    printf("\n\n");
}

int main() {
    int escolha;
    int decimal;

    printf("Calculadora de Conversão Didática\n");
    printf("Escolha a conversão desejada:\n");
    printf("1 - Base 10 para Base 2\n");
    printf("2 - Base 10 para Base 8\n");
    printf("3 - Base 10 para Base 16\n");
    printf("4 - Base 10 para Código BCD\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    printf("Digite o numero em base 10: ");
    scanf("%d", &decimal);

    switch (escolha) {
        case 1:
            decimalParaBinario(decimal);
            break;
        case 2:
            decimalParaOctal(decimal);
            break;
        case 3:
            decimalParaHexadecimal(decimal);
            break;
        case 4:
            decimalParaBCD(decimal);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
