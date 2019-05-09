/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
 // define struct
typedef struct node
{
     char word[LENGTH+ 1];
     struct node *next;
}
node;

node *hashtable[26];

node *head;

// hash function definition
int hash_function (const char *word)
{
    int hash = tolower(word[0]) - 'a';
    return hash % 26;
}

bool load(const char *dictionary)
{

    // open dictionary
    char word[LENGTH + 1];
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    // initialize head pointer
    head = calloc(1, sizeof(node));
    // initialize hashtable
    for (int i = 0; i <= 26; i++)
        {
            hashtable[i] = NULL;
        }

        while (fscanf(fp, "%s", word) != EOF)
        {
            // printf ("%s\n", word);

            // create new node
            node* new_node = malloc(sizeof(node));
                if (new_node == NULL)
                {
                    unload ();
                    return false;
                }
            // copy word into node
            strcpy (new_node->word, word);

            // printf("%s\n", new_node->word);

            //***hash word here***//
            int index = hash_function(new_node -> word);
            printf("%i\n", index);


            // insert node into linked list
            new_node ->next = hashtable[index];
            hashtable[index] = new_node;
        }



    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
