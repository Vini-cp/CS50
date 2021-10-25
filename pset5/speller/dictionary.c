// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Total words in Hash Table
int total_words;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // printf("1. %s has %li chars\n", word, strlen(word));

    if (strlen(word) < 1 || strlen(word) > LENGTH)
    {
        return false;
    }

    // Get the hash number of the word;
    int hash_nmb;

    // Case insensitive - lower all chars
    char word_dic[strlen(word)+1];

    memcpy (word_dic, word, strlen(word)+1);

    for (int i = 0; i < strlen(word_dic); i++)
    {
        word_dic[i] = tolower(word_dic[i]);
    }

    // printf("2. %s has %li chars\n", word_dic, strlen(word_dic));

    hash_nmb = hash(word_dic);

    // printf("%s : %d hash\n", word, hash_nmb);

    node* n_pred = table[hash_nmb];

   if (n_pred == NULL)
    {
        return false;
    }

    if (strcmp(n_pred->word, word_dic) == 0)
    {
        return true;
    }
    else
    {
        while (n_pred->next != NULL)
        {
            // Check if the word is in dictionary
            if (strcmp(n_pred->word, word_dic) == 0)
            {
                return true;
            }

            // update pointer
            n_pred = n_pred->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int size = strlen(word);
    int hash_nmb = 1;

    for (int i = 0; i < size; i++)
    {
        hash_nmb = hash_nmb * (word[i] - 'a' + 1);
    }

    return hash_nmb % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    total_words = 0;

    char word_dic[LENGTH + 1];
    int hash_nmb;
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");

    // Check if it is not empty
    if (file == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", word_dic) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word_dic);

        //Hash word to obtain a hash value
        hash_nmb = hash(n->word);

        // check for empty list
        if (table[hash_nmb] == NULL)
        {
           table[hash_nmb] = n;
        }
        // check for insertion at tail
        else
        {
            node* n_pred = table[hash_nmb];
            while (true)
            {
                // insert at tail
                if (n_pred->next == NULL)
                {
                    n_pred->next = n;
                    break;
                }

                // update pointer
                n_pred = n_pred->next;
            }
        }

        total_words++;
    }

    // Close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Total number of words
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* tmp;
    node* n;

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            // If only 1 node free it
            n = table[i];
            while (n != NULL)
            {
                tmp = n->next;
                free(n);
                n = tmp;
            }
            // free last node in list
            tmp = n;
            free(tmp);
        }
    }
    return true;
}
