// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <stdint.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 1000000 //const unsigned int N = 1000;

// Hash table
node *table[N];

// word counter
int wordCount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

   char lowerWord[LENGTH + 1]; // Declare a char array to store the lowercase version of the word

    // Convert the input word to lowercase and store it in lowerWord
    int i = 0; // Declare a counter variable
    for (i = 0; word[i] != '\0'; i++) // Loop until the null terminator is reached
    {
        lowerWord[i] = tolower(word[i]); // Convert each letter to lowercase
    }
    lowerWord[i] = '\0'; // Add the null terminator to the end of the lowercase word
    //This is necessary because lowerWord is a character array that stores a string,
    //and strings in C are terminated by a null character. Without the null terminator,
    //functions that operate on strings (such as strcmp()) would not know where the
    //end of the string is and could produce incorrect results or undefined behavior.

    // if strcpy was used there was no need to add the null terminator because strcpy does it automatically.



    // Now you can work with the lowercase version of the word (lowerWord) as needed

    node *cursor = table[hash(lowerWord)]; //set the cursor to point to the first element in the list

    while(cursor != NULL) //loop through the list
    {
        if(strcmp(lowerWord, (*cursor).word) == 0) //if the word is found, return true
        {
            return true;
        }
        cursor = (*cursor).next; //otherwise, move the cursor to the next element in the list
    }
    return false; // if not found, return false.
}

// Hashes word to a number
unsigned int hash(const char *word)
    {
    // TODO
    // we are doing the djb2 hash, more here: https://theartincode.stanis.me/008-djb2/ we start with a hash variable set to 5381
    unsigned long hash = 5381;
    //in c we save the ASCII code of each letter
    int c = 0;
    //first we get the size of each word
    int sizeOfWord = strlen(word);
    //and we loop through the letters
    for (int i = 0; i < sizeOfWord; i++)
        {
        //we might need to convert all the letters to lowercase because we
        //want them to be stored in the same place in the array
        c = tolower(word[i]);
        // then multiply with 33 (No idea why)

        hash = hash * 33 + c;
    }
    // N represents the size of the hash table.
    //it's the number of avaible spaces where data can be stored.
    //when hash % N iam ensuring that the hash value is a valid index into the hashtable.
    return hash % N; // With N = 1, this essentially means hash % 1, which is always 0.
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    //open dictioanary file. r stands for reading.
    FILE *dict_pointer = fopen(dictionary, "r");
    if(dict_pointer == NULL)
        {
             printf("Can't open");
             return false;
        }
    char word[LENGTH + 1];
    // creating a character array WORD to hold a word from the dictionary.
    //read string one at a time from. EOF = End of file.
    while(fscanf(dict_pointer, "%s", word) != EOF)
    {
        // Compute the hash value to determine the bucket
         unsigned int index = hash(word);
        // Create a new node for each word
        node* n = malloc(sizeof(node));


        // We want to make sure malloc succeeded in getting memory for us:
        if(n != NULL)
        {
            strcpy((*n).word, word); //copy the word into our "node".

            (*n).next = table[index]; //set the next pointer to point to the first element in the list
            table[index] = n; //set the head of the list to point to the new node
            wordCount++; //increment the word count
        }
    }

    fclose(dict_pointer); // close the dictionary file

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount; //return the word count
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
for(int i = 0; i < N; i++) //loop through the table
{
    node* cursor = table[i]; //set the cursor to point to the first element in the list
    while(cursor != NULL) //loop through the list
    {
        node* tmpCursor = cursor; //create a temporary cursor to point to the same element as the cursor
        cursor = (*cursor).next; //move the cursor to the next element in the list
        free(tmpCursor); //free the temporary cursor
    }
}
    return true;
}
