#include "header.h"

void display_cover(){
    //Menampilkan Tulisa TIC TAC TOE untuk cover
    printf("     +============================================================+\n");
    printf("     |   __          __  _                            _______     |\n");
    printf("     |   \\ \\        / / | |                          |__   __|    |\n");
    printf("     |    \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___   |\n");
    printf("     |     \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\  |\n");
    printf("     |      \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) | |\n");
    printf("     |       \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  |\n");
    printf("     |                                                            |\n");
    printf("     |    _____                 _ _   __  __                      |\n");
    printf("     |   / ____|               | (_) |  \\/  |                     |\n");
    printf("     |  | (___   __ _ _ __   __| |_  | \\  / | ___  _ __ ___  ___  |\n");
    printf("     |   \\___ \\ / _` | '_ \\ / _` | | | |\\/| |/ _ \\| '__/ __|/ _ \\ |\n");
    printf("     |   ____) | (_| | | | | (_| | | | |  | | (_) | |  \\__ \\  __/ |\n");
    printf("     |  |_____/ \\__,_|_| |_|\\__,_|_| |_|  |_|\\___/|_|  |___/\\___| |\n");
    printf("     |                                                            |\n");
    printf("     +============================================================+\n");

    //Klik enter untuk lanjut 
    printf("                         Klik Enter Untuk Lanjut\n\n");
    char c;
    scanf("%c",&c);
    display_menu();
}

void display_menu() {
    int choice;
    Node* root = NULL;
    initializeMorseTree(&root);

    while (1) {
        printf("                      +============================+\n");
        printf("                      |   __  __                   |\n");
        printf("                      |  |  \\/  |                  |\n");
        printf("                      |  | \\  / | ___ _ __  _   _  |\n");
        printf("                      |  | |\\/| |/ _ \\ '_ \\| | | | |\n");
        printf("                      |  | |  | |  __/ | | | |_| | |\n");
        printf("                      |  |_|  |_|\\___|_| |_|\\__,_| |\n");
        printf("                      |                            |\n");
        printf("                      +============================+\n");
        printf("\n");
        printf("                         +======================+\n");
        printf("                         |     1. Show Node     |\n");
        printf("                         |     2. Translator    |\n");
        printf("                         |     3. Read File     |\n");
        printf("                         |     4. Info          |\n");
        printf("                         |     5. Exit          |\n");
        printf("                         +======================+\n");
        printf("\n");
        printf("Pilih Menu : ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch(choice) {
            case 1:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 2:
                {
                    int sub_choice;
                    printf("                         +======================+\n");
                    printf("                         |     2. Decode        |\n");
                    printf("                         |     3. Back          |\n");
                    printf("                         +======================+\n");
                    printf("\n");
                    printf("Pilih Menu Translator: ");
                    scanf("%d", &sub_choice);
                    getchar();  // Consume newline character left by scanf

                    switch(sub_choice) {
                        case 1:
                            char text[50];
                            printf("Masukkan teks: ");
                            fgets(text, sizeof(text), stdin);
                            // Remove newline character from input if present
                            text[strcspn(text, "\n")] = 0;
                            printf("Morse code: ");
                            textToMorse(root, text);
                            printf("\n");
                            break;
                        case 2:
                            char morseText[100];
                            printf("Masukkan sandi Morse: ");
                            fgets(morseText, sizeof(morseText), stdin);
                            printf("Hasil: ");
                            morseTextToChar(root, morseText);
                            printf("\n");
                            break;
                        case 3:
                            break;  // Back to the main menu
                        default:
                            printf("Opsi tidak valid. Silakan coba lagi.\n");
                    }
                }
                break;
            case 3:
                printf("Masih dalam perkembangan\n");
                break;
            case 4:
                printf("Masih dalam perkembangan\n");
                break;
            case 5:
                printf("Keluar dari program.\n");
                return;  // Exit the function to stop the loop
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    }
}

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