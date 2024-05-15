#include "node.h"
#include "../../main.h"
#include "../menu/menu.h"

Node* createNode(char letter) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->letter = letter;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, char* code, char letter) {
    if (*root == NULL) {
        *root = createNode(letter);
    }
    Node* temp = *root;
    while (*code) {
        if (*code == '.') {
            if (temp->left == NULL) {
                temp->left = createNode(0);
            }
            temp = temp->left;
        } else if (*code == '-') {
            if (temp->right == NULL) {
                temp->right = createNode(0);
            }
            temp = temp->right;
        }
        code++;
    }
    temp->letter = letter;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c", root->letter); // Tidak perlu spasi di sini
        inOrderTraversal(root->right);
    }
}

void charToMorse(Node* root, char letter, char* path, int pathLen) {
    if (root == NULL) {
        return;
    }

    if (root->letter == letter) {
        for (int i = 0; i < pathLen; i++) {
            printf("%c", path[i]);
        }
        printf(" ");
    }

    path[pathLen] = '.';
    charToMorse(root->left, letter, path, pathLen + 1);

    path[pathLen] = '-';
    charToMorse(root->right, letter, path, pathLen + 1);
}

void textToMorse(Node* root, char* text) {
    char path[100];
    for (int i = 0; text[i] != '\0'; i++) {
        charToMorse(root, toupper(text[i]), path, 0);
    }
    printf("\n");
}

void morseToChar(Node* root, char* morse) {
    Node* temp = root;
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            temp = temp->left;
        } else if (morse[i] == '-') {
            temp = temp->right;
        } else if (morse[i] == ' ') {
            printf("%c", temp->letter);
            temp = root;
        }
    }
    printf("%c", temp->letter); // Cetak karakter terakhir
}

void morseWordToChar(Node* root, char* morseWord) {
    morseToChar(root, morseWord);
    printf(" ");
}

void morseTextToChar(Node* root, char* morseText) {
    char* token = strtok(morseText, " ");
    while (token != NULL) {
        morseWordToChar(root, token);
        token = strtok(NULL, " ");
    }
}

void initializeMorseTree(Node** root) {
    insert(root, ".-", 'A');
    insert(root, "-...", 'B');
    insert(root, "-.-.", 'C');
    insert(root, "-..", 'D');
    insert(root, ".", 'E');
    insert(root, "..-.", 'F');
    insert(root, "--.", 'G');
    insert(root, "....", 'H');
    insert(root, "..", 'I');
    insert(root, ".---", 'J');
    insert(root, "-.-", 'K');
    insert(root, ".-..", 'L');
    insert(root, "--", 'M');
    insert(root, "-.", 'N');
    insert(root, "---", 'O');
    insert(root, ".--.", 'P');
    insert(root, "--.-", 'Q');
    insert(root, ".-.", 'R');
    insert(root, "...", 'S');
    insert(root, "-", 'T');
    insert(root, "..-", 'U');
    insert(root, "...-", 'V');
    insert(root, ".--", 'W');
    insert(root, "-..-", 'X');
    insert(root, "-.--", 'Y');
    insert(root, "--..", 'Z');
    insert(root, "-----", '0');
    insert(root, ".----", '1');
    insert(root, "..---", '2');
    insert(root, "...--", '3');
    insert(root, "....-", '4');
    insert(root, ".....", '5');
    insert(root, "-....", '6');
    insert(root, "--...", '7');
    insert(root, "---..", '8');
    insert(root, "----.", '9');
    insert(root, ".-.-.-", '.');
    insert(root, "--..--", ',');
    insert(root, "..--..", '?');
    insert(root, "-.-.--", '!');
    insert(root, ".----.", '\'');
    insert(root, "-....-", '-');
    insert(root, "-..-.", '/');
    insert(root, "-.--.", '(');
    insert(root, "-.--.-", ')');
    insert(root, ".-...", '&');
    insert(root, "---...", ':');
    insert(root, "-.-.-.", ';');
    insert(root, "-...-", '=');
    insert(root, ".-.-.", '+');
    insert(root, "-....-", '-');
    insert(root, "..--.-", '_');
    insert(root, ".-..-.", '"');
    insert(root, ".--.-.", '@');
    insert(root, ".-..-.", ' '); // Spasi
}
