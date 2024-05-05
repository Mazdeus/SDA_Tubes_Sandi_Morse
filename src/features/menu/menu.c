#include "../../main.h"
#include "menu.h"


void display_menu(){
    int choice;
    do {
        printf("╔════════════════════════════╗\n");
        printf("║   __  __                   ║\n");
        printf("║  |  \\/  |                  ║\n");
        printf("║  | \\  / | ___ _ __  _   _  ║\n");
        printf("║  | |\\/| |/ _ \\ '_ \\| | | | ║\n");
        printf("║  | |  | |  __/ | | | |_| | ║\n");
        printf("║  |_|  |_|\\___|_| |_|\\__,_| ║\n");
        printf("╚════════════════════════════╝\n");
        printf("\n");
        printf("  ╔══════════════════════╗\n");
        printf("  ║     1. Show Node     ║\n");
        printf("  ║     2. Translator    ║\n");
        printf("  ║     3. Read File     ║\n");
        printf("  ║     4. Info          ║\n");
        printf("  ║     5. Exit          ║\n");
        printf("  ╚══════════════════════╝\n");
        printf("\n");
        
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Masih dalam perkembangan\n");
                break;
            case 2:
                printf("Masih dalam perkembangan\n");
                break;
            case 3:
                printf("Masih dalam perkembangan\n");
                break;
            case 4:
                printf("Masih dalam perkembangan\n");
                break;
            case 5:
                printf("Masih dalam perkembangan");
                break;
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while(choice != 3);

    return 0;
}