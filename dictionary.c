// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

void makeStartOfLists();
void printList(int index);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 25;

// Number of words added to dictionary
unsigned int wordCount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {

            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char firstLetter = tolower(word[0]);
    //printf("%c\n", firstLetter);

    switch(firstLetter) {
      case 'a' :
         return 0;
      case 'b' :
         return 1;
      case 'c' :
         return 2;
      case 'd' :
         return 3;
      case 'e' :
         return 4;
      case 'f' :
         return 5;
      case 'g' :
         return 6;
      case 'h' :
         return 7;
      case 'i' :
         return 8;
      case 'j' :
         return 9;
      case 'k' :
         return 10;
      case 'l' :
         return 11;
      case 'm' :
         return 12;
      case 'n' :
         return 13;
      case 'o' :
         return 14;
      case 'p' :
         return 15;
      case 'q' :
         return 16;
      case 'r' :
         return 17;
      case 's' :
         return 18;
      case 't' :
         return 19;
      case 'u' :
         return 20;
      case 'v' :
         return 21;
      case 'w' :
         return 22;
      case 'x' :
         return 23;
      case 'y' :
         return 24;
      case 'z' :
         return 25;
      default :
         printf("invalid starting letter\n" );
         return 0;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // populate hash table with start of lists
    makeStartOfLists();

    // Open dictionary
    FILE* file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // Read strings from dictionary one word at a time
    char* word = malloc(45 * sizeof(char));


    while(fscanf(file, "%s", word) != EOF)
    {
        //printf("%s\n", word);

        node* n = malloc(sizeof(node));
        strcpy(n->word, word);
        n->next = NULL;

        int index = hash(word);
        // printf("%i\n", index);

        // point new node to start of list
        n->next = table[index];

        // pont start of list to new node
        table[index] = n;

        wordCount++;
    }

    //free(word);
    //printList(2);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // printf("word count is: %int\n", wordCount);
    return wordCount;

    // return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (unsigned int i = 0; i <= LENGTH; i++)
    {
        for (node *tmp = table[i], *cursor = table[i]; cursor != NULL; cursor = cursor->next )
        {
           if (tmp != NULL)
            {
                //free(tmp);
                tmp = cursor;
            }
            // printf("%s\n", tmp->word);
        }
    }
    return true;
    //return false;
}

void makeStartOfLists()
{
    for (int i = 0; i < LENGTH; i++)
    {
        // start of list, put into has table
        node* n = NULL;
        table[i] = n;
    }
}

// For testing print list at index
void printList(int index)
{
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        printf("%s\n", tmp->word);
    }
}