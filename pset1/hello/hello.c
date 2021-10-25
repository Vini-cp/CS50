#include <stdio.h>
#include <cs50.h>

int main(void) // Introducing the main function
{
    string name = get_string("What is your name?\n"); // This is where we get the interlocutor name

    printf("hello, %s\n", name); // This is where we print it
}