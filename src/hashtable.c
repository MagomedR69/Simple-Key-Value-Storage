#include <stdio.h>
#include <string.h>
#include "hashtable.h"

unsigned int hash(char *name)
{
    unsigned int hash_value = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        hash_value += name[i];
    }

    return hash_value % TABLE_SIZE;
}

void insert(HashTable *table, char *name, char *value)
{
    unsigned int index = hash(name);

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        return;
    }

    new_node->name = name;
    new_node->value = value;

    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

char *find(HashTable *table, char *name)
{
    unsigned int index = hash(name);
    Node *current = table->buckets[index];

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->value;
        }
        else
        {
            current = current->next;
        }
    }

    return NULL;
}