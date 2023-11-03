#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    int cents;
    int coins;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    do
    {
        n = get_float("Troco: ");
    }
    while (n <= 0);
    cents = round(n * 100);
    for (coins = 0; cents > 0; coins++)
    {
        if (cents >= 25)
        {
           cents -= 25;
           w++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            x++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            y++;
        }
        else
        {
            cents -= 1;
            z++;
        }
    }
    if (w != 0)
        printf("coins of 25c: %i\n", w);
    if (x != 0)
        printf("coins of 10c: %i\n", x);
    if (y != 0)
        printf("coins of 5c: %i\n", y);
    if (z != 0)
        printf("coins of 1c: %i\n", z);
    printf("total of coins: %i\n", coins);
}