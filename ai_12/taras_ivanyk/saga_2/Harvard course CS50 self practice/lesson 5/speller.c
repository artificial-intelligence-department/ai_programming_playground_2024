// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

int count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

unsigned int hash(const char *word)
{
   unsigned int hash_value = toupper(word[0]) - 'A';

    if(strlen(word) > 1){
        hash_value = hash_value * 26 + (toupper(word[1]) - 'A');
    }
    return hash_value % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *cursor = table[index];

    while(cursor != NULL){
        if(strcasecmp(cursor -> word, word) == 0){
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if(source == NULL){
        return false;
    }
    char word[LENGTH + 1];

    while(fscanf(source, "%s", word) == 1){
        count++;

        node *n = malloc(sizeof(node));

        if(n == NULL){
            fclose(source);
            return false;
        } else{
            strcpy(n -> word, word);
            n -> next = NULL;
        }

        unsigned int index = hash(word);

        if(table[index] == NULL){
            table[index] = n;
        } else{
            n -> next = table[index];
            table[index] = n;
        }
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(unsigned int i = 0; i < N; i++){
        node *cursor = table[i];

        while(cursor != NULL){
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }
    }
    return true;
}
