#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    int n2;

    do
    {
        n = get_int("Altura: ");
    }
    while(n < 1 || n > 8);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}