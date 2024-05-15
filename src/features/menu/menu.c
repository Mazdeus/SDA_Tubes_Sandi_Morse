#include "../../main.h"
#include "menu.h"
#include "../binary_tree/node.h"
#include "../binary_tree/node.c"

void display_menu() {
    int choice;
    Node* root = NULL;
    initializeMorseTree(&root);

    while (1) {
        printf("                      ╔════════════════════════════╗\n");
        printf("                      ║   __  __                   ║\n");
        printf("                      ║  |  \\/  |                  ║\n");
        printf("                      ║  | \\  / | ___ _ __  _   _  ║\n");
        printf("                      ║  | |\\/| |/ _ \\ '_ \\| | | | ║\n");
        printf("                      ║  | |  | |  __/ | | | |_| | ║\n");
        printf("                      ║  |_|  |_|\\___|_| |_|\\__,_| ║\n");
        printf("                      ║                            ║\n");
        printf("                      ╚════════════════════════════╝\n");
        printf("\n");
        printf("                         ╔══════════════════════╗\n");
        printf("                         ║     1. Show Node     ║\n");
        printf("                         ║     2. Translator    ║\n");
        printf("                         ║     3. Read File     ║\n");
        printf("                         ║     4. Info          ║\n");
        printf("                         ║     5. Exit          ║\n");
        printf("                         ╚══════════════════════╝\n");
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
                    printf("                         ╔══════════════════════╗\n");
                    printf("                         ║     1. Encode        ║\n");
                    printf("                         ║     2. Decode        ║\n");
                    printf("                         ║     3. Back          ║\n");
                    printf("                         ╚══════════════════════╝\n");
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
