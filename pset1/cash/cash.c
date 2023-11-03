#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    int cents;
    int coins;

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
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
    }
    printf("%i\n", coins);
}