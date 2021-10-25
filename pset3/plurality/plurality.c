#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Compare two strings
        if (strcmp(candidates[i].name, name) == 0)
        {
            //add a vote to the candidate if he or she was voted
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int i = 0;
    int v[candidate_count];
    memset(v, 0, sizeof(v));

    v[0] = 1;
    int aux = candidates[0].votes;

    for (i = 1; i < candidate_count; i++)
    {
        // search the most voted candidate
        if (candidates[i].votes > aux)
        {
            memset(v, 0, sizeof(v));
            v[i] = 1;
            aux = candidates[i].votes;
        }
        else if (candidates[i].votes == aux)
        {
            v[i] = 1;
        }
    }

    // Show the most voted candidate(s)
    for (i = 0; i < candidate_count; i++)
    {
        if (v[i] == 1)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

