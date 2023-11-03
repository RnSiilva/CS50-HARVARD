#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; //Variavel para guardar o valor digitado pelo usuario
    int n2 = 1; //Variavel para suporte na implementacao da 1° torre
    int j; //Variavel para suporte em ambas as torres

    //Loop de repeticao para que seja um inteiro entre 1 e 8
    do
    {
        n = get_int("Altura de 1 a 8: ");
    }
    while (n < 1 || n > 8);
    //Loop principal para cada linha da torre final
    for (int i = 0; i < n; i++)
    {
        //Loop para implementação da primeira torre
        for (j = 0; j < n - n2; j++)
        {
            printf(" ");
        }
        for (; j < n; j++)
        {
            printf("#");
        }
        //Implementacao dos dois espacos que separam as torres
        printf("  ");
        //Loop responsavel pela segunda torre
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        //n2 é o inteiro com valor inicial de 1, da suporte para implementacao da primeira torre
        n2++;
        printf("\n");
    }
}
