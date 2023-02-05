// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int h = 0;

// Number of buckets in hash table
const unsigned int N = 52650;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int i = hash(word);
    node *x;
    x = table[i];
    while (x != NULL)
    {
        if (strcasecmp(x->word, word) == 0)
        {
            return true;
        }
        x = x->next;
    }
    return false;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int f = 0, k, z;
    for (int i = 0, n = strlen(word); i < n; i++)
    {

        if (islower(word[i]))
        {
            k = word[i] - 97;
        }
        else if (isupper(word[i]))
        {
            k = word[i] - 65;
        }
        else
        {
            k = 26;
        }
        f += k;
    }
    z = f * strlen(word);
    return z;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    int q[N];
    for (int i = 0; i < N; i++)
    {
        q[i] = 0;
    }
    FILE *a = fopen(dictionary, "r");
    if (a == NULL)
    {
        return false;
    }

    char w[LENGTH + 1];
    while (fscanf(a, "%s", w) != EOF)
    {
        h++;
        node *b = malloc(sizeof(node));
        if (b == NULL)
        {
            return false;
        }
        strcpy(b->word, w);
        b->next = NULL;
        int j = hash(b->word);
        if (q[j] == 0)
        {
            table[j] = b;
            q[j]++;
        }
        else
        {
            b->next = table[j];
            table[j] = b;
        }
    }
    fclose(a);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return h;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *j = table[i];
        node *k = NULL;
        while (j != NULL)
        {
            k = j->next;
            free(j);
            j = k;
        }
    }
    return true;
}
