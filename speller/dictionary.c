// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Keeps track of hash table word count
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Determine hash value
    int index = hash(word);
    // Access hash table
    node *ptr = table[index];
    // Search through linked lists for word
    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        else
        {
            // Move to next node
            ptr = ptr->next;
        }
    }
    // If word not found in linked list
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Create a hash function that uses the sum of the first two letters to index into hash table
    int sum = 0;
    // Get alphabetical index of first letter
    sum = toupper(word[0]) - 'A';
    // Multiply first letter index by 26
    sum *= 26;
    // Add the alphabetical index of the second letter
    if (word[1] != '\0')
    {
        sum += toupper(word[1]) - 'A';
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return false;
    }
    // Create buffer to store dictionary word
    char word[LENGTH + 1];
    // Read word from dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for the node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Cannot allocate memory.\n");
            return false;
        }
        // Copy word into the node
        strcpy(n->word, word);
        // Hash word to assign spot in hash table
        int hash_index = hash(word);
        // Insert into hash table
        n->next = table[hash_index];
        table[hash_index] = n;
        // Update word count
        word_count++;
    }
    // Close dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Loop through hash table
    for (int i = 0; i < N; i++)
    {
        // Set cursor to head of linked list
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            // Move to next node
            cursor = cursor->next;
            // Free previous node
            free(tmp);
        }
        // Check all nodes have been freed
        if (cursor == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
