#include "../../main.h"
#include "cover.h"
#include "../menu/menu.h"

void display_cover(){
    //Menampilkan Tulisa TIC TAC TOE untuk cover
    printf("     ╔════════════════════════════════════════════════════════════╗\n");
    printf("     ║   __          __  _                            _______     ║\n");
    printf("     ║   \\ \\        / / | |                          |__   __|    ║\n");
    printf("     ║    \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___   ║\n");
    printf("     ║     \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\  ║\n");
    printf("     ║      \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) | ║\n");
    printf("     ║       \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  ║\n");
    printf("     ║                                                            ║\n");
    printf("     ║    _____                 _ _   __  __                      ║\n");
    printf("     ║   / ____|               | (_) |  \\/  |                     ║\n");
    printf("     ║  | (___   __ _ _ __   __| |_  | \\  / | ___  _ __ ___  ___  ║\n");
    printf("     ║   \\___ \\ / _` | '_ \\ / _` | | | |\\/| |/ _ \\| '__/ __|/ _ \\ ║\n");
    printf("     ║   ____) | (_| | | | | (_| | | | |  | | (_) | |  \\__ \\  __/ ║\n");
    printf("     ║  |_____/ \\__,_|_| |_|\\__,_|_| |_|  |_|\\___/|_|  |___/\\___| ║\n");
    printf("     ║                                                            ║\n");
    printf("     ╚════════════════════════════════════════════════════════════╝\n");

    //Klik enter untuk lanjut 
    printf("                         Klik Enter Untuk Lanjut\n\n");
    char c;
    scanf("%c",&c);
    display_menu();
}
