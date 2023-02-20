// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define NUMERO_TABLE 100000

#include "dictionary.h"
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Number of buckets in hash table
//hash table size = 2^16
const unsigned int N = NUMERO_TABLE;

// Hash table
node** table; //[N];

unsigned int word_count = 0;


// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    int word_length = strlen(word);
    char lowercase[word_length + 1];

    for (int i = 0; i < word_length; i++) {
        lowercase[i] = tolower(word[i]);
    }
    lowercase[word_length] = '\0';

    node* cursor = table[hash(lowercase)];

    if (word_length == 1) {
        return true;
    }
    while (cursor != NULL) {
        if (strcasecmp(word, cursor->word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char* word)
{
    // TODO
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char* dictionary)
{
    // TODO
    table = malloc(N * sizeof(node*));

    char word[LENGTH + 1];
    FILE* file = fopen(dictionary, "r");

    while (fscanf(file, "%s", word) != EOF) {

        node* new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            unload();
            return false;
        }
        else {
            strcpy(new_node->word, word);
            int n = hash(new_node->word);
            new_node->next = table[n];
            table[n] = new_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        node* cursor = table[i];

        while (cursor != NULL) {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    free(table);
    return true;
}
