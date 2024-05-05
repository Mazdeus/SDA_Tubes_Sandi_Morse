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
    root->dot->dash->dot->dot = createNode('L');
    root->dot->dash->dash->dot = createNode('P');
    root->dot->dash->dash->dash = createNode('J');
    root->dash->dot->dot->dot = createNode('B');
    root->dash->dot->dot->dash = createNode('X');
    root->dash->dot->dash->dot = createNode('C');
    root->dash->dot->dash->dash = createNode('Y');
    root->dash->dash->dot->dot = createNode('Z');
    root->dash->dash->dot->dash = createNode('Q');
    root->dash->dash->dash->dot = createNode('0');

    root->dot->dot->dot->dot->dot = createNode('5');
    root->dot->dot->dot->dot->dash = createNode('4');
    root->dot->dot->dot->dash->dash = createNode('3');
    root->dot->dash->dot->dash->dot = createNode('Spasi');
    root->dot->dash->dash->dash->dash = createNode('1');
    root->dash->dot->dot->dot->dot = createNode('6');
    root->dash->dash->dot->dot->dot = createNode('7');
    root->dash->dash->dash->dot->dot = createNode('8');
    root->dash->dash->dash->dash->dot = createNode('9');

    return root;
}
