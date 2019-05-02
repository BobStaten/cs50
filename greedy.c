#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* This program calculates the fewest number
 of coins (quarters, dimes, nickels, pennies)
 needed to make change. */

int main(void)
{
    double round(double);

    float j;
    float i;
    float n;
    int k;

    /* Prompts user input and validates */

    do
    {
        printf("Oh Hai!  How much change is owed?\n");
        n = get_float();
        }
    while (n < 0);


    /* Converts input to cents and rounds to nearest
   penny. */

    i = round (n * 100);

    /* Counts coins using consecutive loops;
    one each for quarters, dimes, nickels
    and pennies. */

    k = 0;

    for (j = 0; i >= 25; i -= 25)
    {
        (k = k + 1);
    }

    for (j = 0; i >= 10; i -= 10)
    {
        (k = k + 1);
    }

    for(j = 0; i >= 5; i -= 5)
    {
        (k = k + 1);
    }

    for (j = 0; i >= 1; i--)
    {
        (k = k + 1);
    }

    /* Outputs total number of coins used. */

    printf("%i\n", k);
}

