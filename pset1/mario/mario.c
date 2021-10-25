#include <stdio.h>
#include <cs50.h>

int main() // main function
{

    int n, i, j;

    do
    {
        n = get_int("Height: ");            // This is where we get the interlocutor name
    }
    while (n < 1 || n > 8);                 // Do while we get a number between 1 and 8

    for (i = 1; i < n + 1; i++)             // In this section we're going to print the "#"
    {
        for (j = n; j > 0; j--)
        {
            if (j > i)
            {
                printf(" ");                // This is where we print the space symbol
            }
            else if (j <= i)
            {
                printf("#");                // This is where we print the "#" symbol
            }
        }
        printf("\n");                       // This is where we jump to the next line
    }
}