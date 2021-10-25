#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

int key_value();
int all_chars(string number);

int main(int argc, char **argv)
{
    char key[26];
    char key_m[26];
    int test = key_value(argc, argv);

    if (test == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            key[i] = toupper(argv[1][i]);   // Change upper array
            key_m[i] = tolower(argv[1][i]); // Change lower array
        }
    }
    else
    {
        return 1;   //break the programm
    }

    string text = get_string("plaintext:  ");             // User's text input

    int i = 0;
    char c;

    do
    {
        c = text[i];

        if (c > 64 && c < 91)  // Only letters
        {
            text[i] = key[c - 65];
        }

        if (c > 96 && c < 123) // Only letters
        {
            text[i] = key_m[c - 97];
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
        test = all_chars(args[1]);

        if (test == 0)  //not only chars or not all chars
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            return 0;   //All chars
        }
    }
    else
    {
        printf("Usage: ./caesar key\n"); //more than on argument
        return 1;
    }

}


int all_chars(string letters)
{
    int i = 0;
    char c = toupper(letters[i]);   // Minimize the problem (uppercase all letters)
    char v[26] = {0};

    do
    {
        if (c > 64 && c < 91)  // If is a digit
        {
            v[c - 65] = 1;
        }

        i++;
        c = toupper(letters[i]);
    }
    while (c != '\0');

    for (int j = 0; j < 26; j++)    // Check if there are all letters in the array
    {
        if (v[j] == 0)
        {
            return 0;
        }
    }

    return 1;
}