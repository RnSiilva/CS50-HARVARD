#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; //Variavel que guarda o valor inserido pelo usuario
    int n2 = 1; //Variavel que garante ate onde sera inserido espaco
    int j; //Variavel de suporte

    //Loop que exige um inteiro de 1 a 8
    do
    {
        n = get_int("Altura: ");
    }
    while (n < 1 || n > 8);
    //Loop principal da torre, corre ate que o numero de linhas seja igual a altura solicitada pelo usuario
    for (int i = 0; i < n; i++)
    {
        //Loop responsavel por colocar os espacos
        for (j = 0; j < n - n2; j++)
        {
            printf(" ");
        }
        //Loop que coloca os blocos
        while (j < n)
        {
            printf("#");
            j++;
        }
        //Adiciona 1 a n2 para que a proxima linha tenha 1 espaço a menos, e dessa forma tambem tenha um bloco a mais
        n2++;
        printf("\n");
    }
}
