#include <stdio.h>

void displayMenu() {
    printf("====================================\n");
    printf("=   SELAMAT DATANG DI SANDI MORSE  =\n");
    printf("====================================\n");
    printf("1. Encode Text to Morse Code\n");
    printf("2. Decode Morse Code to Text\n");
    printf("3. Exit\n");
    printf("====================================\n");
    printf("Pilih opsi: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Encode Text to Morse Code\n");
                break;
            case 2:
                printf("Decode Morse Code to Text\n");
                break;
            case 3:
                printf("Terima kasih telah menggunakan program kami!\n");
                break;
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while(choice != 3);

    return 0;
}