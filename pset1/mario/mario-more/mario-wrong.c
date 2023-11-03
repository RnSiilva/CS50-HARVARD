#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    int n2 = 1;
    int tmp;
    int tmp2 = 0;
    int j;

    do
    {
        n = get_int("Altura: ");
    }
    while (n <= 0 || n > 8);
    tmp = n;
    n *= 2;
    for(int i = 0; i < tmp; i++)
    {
        for (j = 0; j < tmp - n2; j++)
        {
            printf(" ");
        }
        while (j < n + 1)
        {
            if(n / 2 == j)
            {
                printf("  ");
            }
            else if(j < n + 1)
            {
                    printf("#");
            }
            j++;
        }
        printf("\n");
        n2++;
    }
}