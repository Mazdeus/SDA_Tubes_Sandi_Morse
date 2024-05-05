#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char letter;
    struct node* left;
    struct node* right;
} Node;

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

char* Encode(Node* root, char* code) {
    Node* temp = root;
    char* result = (char*) malloc(sizeof(char) * strlen(code));
    char* resPtr = result;
    while (*code) {
        if (*code == ' ') { // space indicates end of a letter in Morse code
            *resPtr++ = temp->letter;
            temp = root;
        } else {
            temp = *code == '.' ? temp->left : temp->right;
            if (temp->letter != 0 && (*(code + 1) == ' ' || *(code + 1) == '\0')) {
                *resPtr++ = temp->letter;
                temp = root;
            }
        }
        code++;
    }
    *resPtr = '\0'; // null-terminate the result string
    return result;
}
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->letter);
        inOrderTraversal(root->right);
    }
}



void initializeMorseTree(Node** root) {
    insert(root, ".", 'E');
    insert(root, "-", 'T');
    insert(root, "..", 'I');
    insert(root, ".-", 'A');
    insert(root, "-.", 'N');
    insert(root, "--", 'M');
    insert(root, "...", 'S');
    insert(root, "..-", 'U');
    insert(root, ".-.", 'R');
    insert(root, ".--", 'W');
    insert(root, "-..", 'D');
    insert(root, "-.-", 'K');
    insert(root, "--.", 'G');
    insert(root, "---", 'O');
    insert(root, "----.", '9');
    insert(root, "---.", '0');
    insert(root, "---..", '8');
    insert(root, "....", 'H');
    insert(root, ".....", '5');
    insert(root, "...-", 'V');
    insert(root, "...--", '3');
    insert(root, "..-.", 'F');
    insert(root, "..---", '2');
    insert(root, ".-..", 'L');
    insert(root, ".-.-.", ' ');
    insert(root, ".--.", 'P');
    insert(root, ".---", 'J');
    insert(root, ".----", '1');
    insert(root, "-...", 'B');
    insert(root, "-....", '6');
    insert(root, "-..-", 'X');
    insert(root, "-.-.", 'C');
    insert(root, "-.--", 'Y');
    insert(root, "--..", 'Z');
    insert(root, "--...", '7');
    insert(root, "--.-", 'Q');
}
int main() {
    Node* root = NULL;
    initializeMorseTree(&root);
    /* printf("Masukkan Code Morse yang Ingin di Encode : ");
     char morseCode[100];
     scanf("%s", morseCode);
     printf("%s\n", Encode(root, morseCode)); */
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");
    return 0;

}