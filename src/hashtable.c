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