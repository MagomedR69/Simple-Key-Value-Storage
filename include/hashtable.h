#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 5;

#include <stdio.h>

typedef struct Node
{
    char *name;
    char *value;
    struct Node *next;
} Node;

unsigned int hash(char *name);

#endif