#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int nst; //Variavel para valor da populacao inicial
    int ned; //Variavel para valor da populacao final
    int yrs; //Variavel para valor de ano(s)
    int n; //Variavel de suporte para imprimir sem alterar

    // TODO: Solicite o valor inicial ao usuário
    do
    {
        n = get_int("start size of popul.: ");
    }
    while (n < 9);
    nst = n;
    // TODO: Solicite o valor final ao usuário
    do
    {
        ned = get_int("end size of popul.: ");
    }
    while (ned < nst);
    // TODO: Calcule o número de anos até o limite
    for (yrs = 0; nst < ned; yrs++)
    {
        nst = nst + (nst / 3) - (nst / 4);
    }
    // TODO: Imprima o número de anos
//    printf("%i years for a population to go from %i to %i.\n", yrs, n, ned);
    printf("Years: %i\n", yrs);
}
