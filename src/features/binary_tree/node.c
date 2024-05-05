#include "node.h"

// Fungsi untuk membuat node baru
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->dot = NULL;
    newNode->dash = NULL;
    return newNode;
}

// Fungsi untuk membangun pohon biner Morse
struct Node* buildMorseTree() {
    struct Node* root = createNode(' ');
    root->dot = createNode('E');
    root->dash = createNode('T');

    root->dot->dot = createNode('I');
    root->dot->dash = createNode('A');
    root->dash->dot = createNode('N');
    root->dash->dash = createNode('M');

    root->dot->dot->dot = createNode('S');
    root->dot->dot->dash = createNode('U');
    root->dot->dash->dot = createNode('R');
    root->dot->dash->dash = createNode('W');
    root->dash->dot->dot = createNode('D');
    root->dash->dot->dash = createNode('K');
    root->dash->dash->dot = createNode('G');
    root->dash->dash->dash = createNode('O');

    root->dot->dot->dot->dot = createNode('H');
    root->dot->dot->dot->dash = createNode('V');
    root->dot->dot->dash->dot = createNode('F');
    root->dot->dash->dash->dot = createNode('L');
    root->dash->dot->dot->dot = createNode('P');
    root->dash->dot->dot->dash = createNode('J');
    root->dash->dot->dash->dash = createNode('B');
    root->dash->dash->dash->dot = createNode('X');
    root->dash->dash->dash->dash = createNode('C');
    root->dash->dash->dot->dot = createNode('Y');
    root->dash->dash->dot->dash = createNode('Z');

    return root;
}
