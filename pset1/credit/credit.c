#include <stdio.h>
#include <cs50.h>
#include <math.h>

int even_odd(int n);                                    // Check if is Even or Odd
int get_int_len(long value);                            // Get the card number lenght

int main()
{

    long credit;

    int even_sum = 0;
    int odd_sum = 0;
    int aux, nmb_lenght, card, card_1, card_2;

    do
    {
        credit = get_long("Number: ");              // This is where we get the interlocutor card number
    }
    while (credit < 1);                             // Do while we get a positive number

    nmb_lenght = get_int_len(credit);

    for (int i = 0; i < nmb_lenght; i++)            // Starting at the end of the number
    {
        if (i == nmb_lenght - 1)
        {
            card_1 = credit;
        }

        if (i == nmb_lenght - 2)
        {
            card_2 = credit % 10;
        }

        if (even_odd(i))                            // Add the sum to the sum of the digits that weren’t multiplied by 2
        {
            aux = credit % 10;
            credit = credit - aux;
            credit = credit / 10;
            even_sum = even_sum + aux;
        }
        else                                        // Multiply every other digit by 2,
        {
            aux = credit % 10;
            credit = credit - aux;
            credit = credit / 10;
            aux = aux * 2;

            if (aux > 9)                            // Sum each digit
            {
                odd_sum = odd_sum + aux % 10;
                aux = (aux - (aux % 10)) / 10;
                odd_sum = odd_sum + aux;
            }
            else
            {
                odd_sum = odd_sum + aux;
            }
        }

    }

    card = card_1 * 10 + card_2;

    if ((even_sum + odd_sum) % 10 == 0)             // If the total’s last digit is 0 the number is valid
    {
        if ((card == 34 || card == 37) && nmb_lenght == 15)         // Starting with 3
        {
            printf("AMEX\n");
        }
        else if (card_1 == 4 && (nmb_lenght > 12 && nmb_lenght < 17))    // Starting with 4
        {
            printf("VISA\n");
        }
        else if ((card == 51 || card == 52 || card == 53 || card == 54 || card == 55) && nmb_lenght == 16)  // Starting with 5_
        {
            printf("MASTERCARD\n");
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



int even_odd(int n)     // Check if is Even or Odd
{
    if (n % 2 == 0)
    {
        return 1;       // Even
    }
    else
    {
        return 0;       // Odd
    }
}

int get_int_len(long value)
{
    int l = 1;

    while (value > 9)
    {
        l++;
        value /= 10;
    }

    return l;
}