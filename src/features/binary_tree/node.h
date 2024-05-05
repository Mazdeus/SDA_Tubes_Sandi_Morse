#ifndef node_h
#define node_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node untuk pohon biner
struct Node {
    char data;
    struct Node* dot;
    struct Node* dash;
};

// Fungsi untuk membuat node baru
struct Node* createNode(char data);

// Fungsi untuk membangun pohon biner Morse
struct Node* buildMorseTree();

#endif