// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word); //prototype for check function
unsigned int hash(const char *word); //prototype for hash function
bool load(const char *dictionary); //prototype for load function
unsigned int size(void); //prototype for size function
bool unload(void); //prototype for unload function

#endif // DICTIONARY_H
