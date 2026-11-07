#include <stdio.h>
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
        return 1;
    }

    new_node->name = name;
    new_node->value = value;

    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}
