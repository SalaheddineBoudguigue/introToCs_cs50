// Implements a dictionary's functionality

#include <ctype.h> // To use toupper
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //To use malloc and free
#include <strings.h>
#include <string.h>

#include "dictionary.h"

unsigned int loaded_word = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp -> next)
    {
        if (strcasecmp(tmp -> word, word) == 0)
            return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    //I found this hash algo on youtube

    unsigned int total = 0;
    for (int k = 0; k < strlen(word); k++)
    {
        total += toupper(word[k]); // for the hashing to be case sensitive
    }
    return total % N; // between 0 and N-1


    // my own hash algo. This idea is simple, we sort up to the second character
    // meaning, the table should have 26*26 buckets. This algo is N independent

    /*if (word[1] == '\0') // If this word has only one letter
        return toupper(word[0]) - 'A';
    else
        {
        int x = toupper(word[0]) - 'A';
        int y = toupper(word[1]) - 'A';
        return 26*x + y; // 0 to 675
        }*/
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *fileDic = fopen(dictionary, "r");

    if (fileDic == NULL)
        return false;

    char term[LENGTH+1];
    while (fscanf(fileDic, "%s", term) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
            return false;

        loaded_word ++;
        strcpy(n -> word, term);
        n -> next = table[hash(term)];
        table[hash(term)] = n;
    }
    fclose(fileDic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return loaded_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    if (loaded_word == 0)
        return false;

    for (int k = 0; k < N; k++)
        {
            while(table[k] != NULL)
            {
                node *tmp = table[k] -> next;
                free(table[k]);
                table[k] = tmp;
            }
        }
    return true;
}
