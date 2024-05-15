#ifndef node_h
#define node_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char letter;
    struct node* left;
    struct node* right;
} Node;

#endif