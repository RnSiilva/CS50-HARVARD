#include <stdio.h>
#include <cs50.h>

//Funcao que conta o tamanho do num. fornecido (recebe ja como string)
long ft_len(char *str)
{
    long i;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

//Funcao para validacao de cartao American Express
int amex(char *str)
{
    if ((str[0] - 48 == 3 && str[1] - 48 == 4)
        || (str[0] - 48 == 3 && str[1] - 48 == 7))
    {
        return (1);
    }
    return (0);
}

//Funcao para validacao de cartao MasterCard
int mast(char *str)
{
    if (str[0] - 48 == 5)
    {
        if (str[1] - 48 == 1 || str[1] - 48 == 2
            || str[1] - 48 == 3 || str[1] - 48 == 5)
        {
            return (1);
        }
    }
    return (0);
}

//Funcao para validacao de cartao Visa
int visa(char *str)
{
    if (str[0] - 48 == 4)
    {
        return (1);
    }
    return (0);
}

//Funcao para validacao do algoritmo de luhn (algoritmo utilizado nos numeros de cartoes de credito)
int valid_test(char *str, int len)
{
    int x = 0; //Guarda o valor do digito desejado * 2
    int y = 0; //Guarda o valor que será utilizado para
    int z = 0; //Guarda o valor das somas dos digitos de um numero caso seja maior que 9

    //Loop inicial que faz a matematica de a cada 2, desde o penultimo, multiplicar por 2 e somar os resultados
    for (int i = len - 2; i >= 0; i -= 2)
    {
        printf("%i ", i);
        x = (str[i] - 48) * 2;
        if (x > 9)
        {
            z = (x / 10) + (x % 10);
        }
        else
        {
            z = x;
        }
        y = y + z;
    }
    //Se o cartao ter 16 nums, soma, a cada dois, desde o ultimo digito, com o valor da conta anterior, ate o seg. dig.
    if (len == 16)
    {
        for (int i = len - 1; i >= 1; i -= 2)
        {
            y += str[i] - 48;
        }
    }
    //Se o cartao ter 13 ou 15 nums, faz a mesma soma que o if a cima, porem ate o primeiro digito
    if (len == 13 || len == 15)
    {
        for (int i = len - 1; i >= 0; i -= 2)
        {
            y += str[i] - 48;
        }
    }
    //Validar se a conta total e valida. E sera caso o ultimo digito for 0
    if (y % 10 == 0)
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    long n;
    int len;
    char str[20];

    n = get_long("Nº do cartao: ");
    sprintf(str, "%li", n);
    len = ft_len(str);
    //   printf("len: %i\n", len);
    //Condicoes para caso o num do cartao tenha os tamanhos de 13, 15 ou 16 (Caso contrario e invalido)
    if (len == 13 || len == 15 || len == 16)
    {
        if (valid_test(str, len) == 1)
        {
            printf("Valido\n");
            if (amex(str) == 1 && len == 15)
            {
                printf("AMEX\n");
            }
            else if (mast(str) == 1 && len == 16)
            {
                printf("MASTERCARD\n");
            }
            else if (visa(str) == 1)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}