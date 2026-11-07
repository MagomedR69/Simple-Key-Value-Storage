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

typedef struct HashTable
{

    Node **buckets;
    int capacity;
} HashTable;

unsigned int hash(char *name);

void insert(HashTable *table, char *name, char *value);

#endif