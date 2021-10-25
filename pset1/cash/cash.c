#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main() // main function
{

    float cents;
    int n;
    int i, j, nmb;

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    do
    {
        cents = get_float("Change owed: ");             // This is where we get the interlocutor change
    }
    while (cents < 0);                                  // Do while we get a number between 1 and 8

    n = round(cents * 100);

    i = n % quarter;
    j = n / quarter;
    nmb = j;                                            // Get the number of quarters

    if (i == 0)
    {
        printf("%d \n", nmb);
    }
    else
    {

        j = i / dime ;                                  // Get the number of dimes
        i = i % dime;
        nmb = nmb + j;                                  // Get the number of dimes + quarters

        if (i == 0)
        {
            printf("%d \n", nmb);
        }
        else
        {

            j = i / nickel ;                            // Get the number of nickels
            i = i % nickel;
            nmb = nmb + j;                              // Get the number of nickels + dimes + quarters

            if (i == 0)
            {
                printf("%d \n", nmb);
            }
            else
            {
                nmb = nmb + i;                          // Get the number of pennies + nickels + dimes + quarters
                printf("%d \n", nmb);
            }
        }
    }
}