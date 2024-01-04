#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until a winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if the election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min(); // Find the minimum number of votes
        bool tie = is_tie(min); // Check if there is a tie

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with the minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if the vote is valid
bool vote(int voter, int rank, string name) 
{
    // Iterate through the candidates to find the candidate with the given name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; // This line of code means that the voter prefers the ith candidate as their rankth choice
            return true;
        }
    }
    return false; // Invalid vote
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate through the voters and their preferences
    for (int i = 0; i < voter_count; i++) // Iterate through the voters
    {
        for (int j = 0; j < candidate_count; j++) // Iterate through the preferences
        {
            // Check if the candidate at this preference rank is not eliminated
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes++;    // Add a vote to the candidate
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = voter_count / 2; // The majority of votes is half of the total number of voters
    for (int i = 0; i < candidate_count; i++) // Iterate through the candidates
    {
        if (candidates[i].votes > majority) // Check if the candidate has more than the majority of votes
        {
            printf("%s\n", candidates[i].name); // Print the winner
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = INT_MAX; // Initialize to a large value
    for (int i = 0; i < candidate_count; i++) // Iterate through the candidates
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes) // Check if the candidate is not eliminated and has less votes than the current minimum
        {
            min_votes = candidates[i].votes; // Update the minimum number of votes
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++) // Iterate through the candidates
    {
        if (!candidates[i].eliminated && candidates[i].votes != min) // Check if the candidate is not eliminated and has a different number of votes than the minimum
        {
            return false; // At least one candidate has a different number of votes
        }
    }
    return true; // All remaining candidates have the same number of votes
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++) // Iterate through the candidates
    {
        if (candidates[i].votes == min) // Check if the candidate has the minimum number of votes
        {
            candidates[i].eliminated = true; // Eliminate the candidate
        }
    }
}
