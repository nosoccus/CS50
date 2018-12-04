#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dictionary.h"
#define SIZE 1000000

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;
node* hashtable[SIZE] = { NULL };

int hash(const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
            n = word[i] - 'a' + 1;
        else
            n = 27;
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}

int dictionarySize = 0;
bool load(const char* dictionary)
{
    // TODO
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    char word[LENGTH + 1];
    while (fscanf(file, "%s\n", word) != EOF)
    {
        dictionarySize++;
        node* newWord = malloc(sizeof(node));
        strcpy(newWord->word, word);
        
        int index = hash(word);
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
    }
    fclose(file);
    return true;
}

bool check(const char* word)
{
    // TODO
    char temp[LENGTH + 1];
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    temp[i] = tolower(word[i]);
    temp[len] = '\0';
    int index = hash(temp);
    if (hashtable[index] == NULL)
    {
        return false;
    }
    node* cursor = hashtable[index];
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;

    }
    return false;
}

unsigned int size(void)
{
    // TODO
    if (dictionarySize > 0)
    {
        return dictionarySize;
    }
    else
        return 0;
}

bool unload(void)
{
    // TODO
    int index = 0;
    while (index < SIZE)
    {
        if (hashtable[index] == NULL)
        {
            index++;
        }
        else
        {
            while (hashtable[index] != NULL)
            {
                node* cursor = hashtable[index];
                hashtable[index] = cursor->next;
                free(cursor);
            }
            index++;
        }
    }
    return true;
}
