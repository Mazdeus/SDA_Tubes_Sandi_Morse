#ifndef header_h
#define header_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char letter;
    struct node* left;
    struct node* right;
} Node;

int main();

void display_cover();

void display_menu();

Node* createNode(char letter);

void insert(Node** root, char* code, char letter);

void inOrderTraversal(Node* root, int depth);

void charToMorse(Node* root, char letter, char* path, int pathLen);

void textToMorse(Node* root, char* text);

void morseToChar(Node* root, char* morse);

void morseWordToChar(Node* root, char* morseWord);

void morseTextToChar(Node* root, char* morseText);

void initializeMorseTree(Node** root);

void readFile(Node* root);


#endif