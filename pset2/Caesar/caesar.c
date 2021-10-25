#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int key_value();
int is_number(string number);
int sum(int lim_inf, int lim_sup, int value, int k);

int main(int argc, char **argv)
{
    int key;
    int test = key_value(argc, argv);

    if (test == 0)
    {
        key = atoi(argv[1]);
    }
    else
    {
        return 1;   //break the programm
    }

    string text = get_string("plaintext:  ");             // User's text input

    char c;
    int i = 0;

    do
    {
        c = text[i];

        if (c > 64 && c < 91)  // Only letters
        {
            text[i] = sum(65, 90, text[i], key % 26);
        }

        if (c > 96 && c < 123) // Only letters
        {
            text[i] = sum(97, 122, text[i], key % 26);
        }

        i++;
    }
    while (c != '\0');

    printf("ciphertext: %s\n", text);

    return 0;

}


int key_value(int size, char **args)
{
    int test;

    if (size == 2)
    {
        test = is_number(args[1]);

        if (test == 0)  //not only numbers
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            return 0;   //It's a number
        }
    }
    else
    {
        printf("Usage: ./caesar key\n"); //more than on argument
        return 1;
    }

}


int is_number(string number)
{
    int i = 0;
    char c = number[i];

    do
    {
        if (c < 48 || c > 57)  // If is a digit
        {
            return 0;
        }

        i++;
        c = number[i];
    }
    while (c != '\0');

    return 1;
}

int sum(int lim_inf, int lim_sup, int value, int k)
{
    if (value + k > lim_sup)
    {
        return (value + k - lim_sup + lim_inf - 1); // sum only in the range
    }
    else
    {
        return value + k; // normal sum
    }
}