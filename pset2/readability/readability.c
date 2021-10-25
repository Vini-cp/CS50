#include <stdio.h>
#include <cs50.h>

int main(void)
{

    string text = get_string("Text: ");             // User's text input

    char c;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    float index;

    do
    {
        c = text[i];
        i++;

        if ((c > 64 && c < 91) || (c > 96 && c < 123))  // Count the letters
        {
            k++;
        }

        if (c == ' ' || c == '\0')                      // Count the words
        {
            j++;
        }

        if (c == '!' || c == '.' || c == '?')           // Count the sentences
        {
            l++;
        }
    }
    while (c != '\0');

    index = 0.0588 * (float) k / j * 100 - 0.296 * (float) l / j * 100 - 15.8;      // Coleman-Liau index

    if (index < 1)
    {
        printf("Before Grade 1\n");         // Grades smaller than 1
    }
    else if (index > 15)                    // Grades bigger than 16
    {
        printf("Grade 16+\n");              // The rest
    }
    else
    {
        printf("Grade %0.f\n", index);
    }

}