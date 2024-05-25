#include "header.h"

//Menampilkan tampilan utama
void display_cover(){
    Beep(0,0);//Inisiasi suara supaya nanti tidak loading dulu
    printf("     +==============================================================+\n");
    printf("     ||   __          __  _                            _______     ||\n");
    printf("     ||   \\ \\        / / | |                          |__   __|    ||\n");
    printf("     ||    \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___   ||\n");
    printf("     ||     \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\  ||\n");
    printf("     ||      \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) | ||\n");
    printf("     ||       \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  ||\n");
    printf("     ||                                                            ||\n");
    printf("     ||    _____                 _ _   __  __                      ||\n");
    printf("     ||   / ____|               | (_) |  \\/  |                     ||\n");
    printf("     ||  | (___   __ _ _ __   __| |_  | \\  / | ___  _ __ ___  ___  ||\n");
    printf("     ||   \\___ \\ / _` | '_ \\ / _` | | | |\\/| |/ _ \\| '__/ __|/ _ \\ ||\n");
    printf("     ||   ____) | (_| | | | | (_| | | | |  | | (_) | |  \\__ \\  __/ ||\n");
    printf("     ||  |_____/ \\__,_|_| |_|\\__,_|_| |_|  |_|\\___/|_|  |___/\\___| ||\n");
    printf("     ||                                                            ||\n");
    printf("     +==============================================================+\n\n");
    printf("                         Klik Enter Untuk Lanjut\n\n");
    char c;
    scanf("%c",&c);
    display_menu();
}

// Menampilkan menu utama
void display_menu() {
    int choice;
    Node* root = NULL;
    initializeMorseTree(&root);

    while (1) {
        printf("                      +==============================+\n");
        printf("                      ||   __  __                   ||\n");
        printf("                      ||  |  \\/  |                  ||\n");
        printf("                      ||  | \\  / | ___ _ __  _   _  ||\n");
        printf("                      ||  | |\\/| |/ _ \\ '_ \\| | | | ||\n");
        printf("                      ||  | |  | |  __/ | | | |_| | ||\n");
        printf("                      ||  |_|  |_|\\___|_| |_|\\__,_| ||\n");
        printf("                      ||                            ||\n");
        printf("                      +==============================+\n");
        printf("\n");
        printf("                         +========================+\n");
        printf("                         ||     1. Show Node     ||\n");
        printf("                         ||     2. Translator    ||\n");
        printf("                         ||     3. File          ||\n");
        printf("                         ||     4. Info          ||\n");
        printf("                         ||     5. Exit          ||\n");
        printf("                         +========================+\n");
        printf("\n");
        printf("Pilih Menu : ");
        scanf("%d", &choice);
        getchar();  

        switch(choice) {
            case 1:
                printf("      +==========================================================+\n");
                printf("      ||    _____ _                     _   _           _       ||\n");
                printf("      ||   / ____| |                   | \\ | |         | |      ||\n");
                printf("      ||  | (___ | |__   _____      __ |  \\| | ___   __| | ___  ||\n");
                printf("      ||   \\___ \\| '_ \\ / _ \\ \\ /\\ / / | . ` |/ _ \\ / _` |/ _ \\ ||\n");
                printf("      ||   ____) | | | | (_) \\ V  V /  | |\\  | (_) | (_| |  __/ ||\n");
                printf("      ||  |_____/|_| |_|\\___/ \\_/\\_/   |_| \\_|\\___/ \\__,_|\\___| ||\n");
                printf("      +==========================================================+\n\n\n");
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n\n");
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n\n");
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n\n");
                printf("Tekan enter untuk kembali ke menu utama...");
                getchar(); 
                break;
            case 2:
                {
                    int sub_choice;
                    do {
                    printf("                         +========================+\n");
                    printf("                         ||     1. Encode        ||\n");
                    printf("                         ||     2. Decode        ||\n");
                    printf("                         ||     3. Back          ||\n");
                    printf("                         +========================+\n");
                    printf("\n");
                    printf("Pilih Menu Translator: ");
                    scanf("%d", &sub_choice);
                    getchar();  

                    switch(sub_choice) {
                        case 1:
                            {
                            char text[50];
                            printf("        +====================================================+\n");
                            printf("        ||  _______                  _       _              ||\n");
                            printf("        || |__   __|                | |     | |             ||\n");
                            printf("        ||    | |_ __ __ _ _ __  ___| | __ _| |_ ___  _ __  ||\n");
                            printf("        ||    | | '__/ _` | '_ \\/ __| |/ _` | __/ _ \\| '__| ||\n");
                            printf("        ||    | | | | (_| | | | \\__ \\ | (_| | || (_) | |    ||\n");
                            printf("        ||    |_|_|  \\__,_|_| |_|___/_|\\__,_|\\__\\___/|_|    ||\n");
                            printf("        +====================================================+\n\n\n");
                            printf("Masukkan teks: ");
                            fgets(text, sizeof(text), stdin);
                            // Remove newline character from input if present
                            text[strcspn(text, "\n")] = 0;
                            printf("Morse code: ");
                            textToMorse(root, text);
                            printf("\n");
                            printf("Apakah Anda ingin menerjemahkan lagi? (1 untuk ya, 0 untuk tidak): ");
                            scanf("%d", &sub_choice);
                            getchar();  
                            break;
                            }
                        case 2:
                            {
                            char morseText[100];
                            printf("        +====================================================+\n");
                            printf("        ||  _______                  _       _              ||\n");
                            printf("        || |__   __|                | |     | |             ||\n");
                            printf("        ||    | |_ __ __ _ _ __  ___| | __ _| |_ ___  _ __  ||\n");
                            printf("        ||    | | '__/ _` | '_ \\/ __| |/ _` | __/ _ \\| '__| ||\n");
                            printf("        ||    | | | | (_| | | | \\__ \\ | (_| | || (_) | |    ||\n");
                            printf("        ||    |_|_|  \\__,_|_| |_|___/_|\\__,_|\\__\\___/|_|    ||\n");
                            printf("        +====================================================+\n\n\n");
                            printf("Masukkan sandi Morse: ");
                            fgets(morseText, sizeof(morseText), stdin);
                            printf("Hasil: ");
                            morseTextToChar(root, morseText);
                            printf("\n");
                            printf("Apakah Anda ingin menerjemahkan lagi? (1 untuk ya, 0 untuk tidak): ");
                            scanf("%d", &sub_choice);
                            getchar();  
                            break;
                            }
                        case 3:
                            break;  // Back to the main menu
                        default:
                            printf("Opsi tidak valid. Silakan coba lagi.\n");
                        }
                    
                    } while (sub_choice == 1);
                }
                break;
            case 3:
                {
                    int sub_choice;
                    do {
                    printf("                          +======================+\n");
                    printf("                          ||   ______ _ _       ||\n");
                    printf("                          ||  |  ____(_) |      ||\n");
                    printf("                          ||  | |__   _| | ___  ||\n");
                    printf("                          ||  |  __| | | |/ _ \\ ||\n");
                    printf("                          ||  | |    | | |  __/ ||\n");
                    printf("                          ||  |_|    |_|_|\\___| ||\n");
                    printf("                          +======================+\n\n");
                    printf("                         +========================+\n");
                    printf("                         ||     1. Write File    ||\n");
                    printf("                         ||     2. Read File     ||\n");
                    printf("                         ||     3. Back          ||\n");
                    printf("                         +========================+\n");
                    printf("\n");
                    printf("Pilih Menu Translator: ");
                    scanf("%d", &sub_choice);
                    getchar();  

                    switch(sub_choice) {
                        case 1:
                            {
                            printf("          +==================================================+\n");
                            printf("          ||  __          __   _ _         ______ _ _       ||\n");
                            printf("          ||  \\ \\        / /  (_) |       |  ____(_) |      ||\n");
                            printf("          ||   \\ \\  /\\  / / __ _| |_ ___  | |__   _| | ___  ||\n");
                            printf("          ||    \\ \\/  \\/ / '__| | __/ _ \\ |  __| | | |/ _ \\ ||\n");
                            printf("          ||     \\  /\\  /| |  | | ||  __/ | |    | | |  __/ ||\n");
                            printf("          ||      \\/  \\/ |_|  |_|\\__\\___| |_|    |_|_|\\___| ||\n");
                            printf("          +==================================================+\n\n");
                            writeTextToFile();
                            break;
                            }
                        case 2:
                            {
                            printf("          +===============================================+\n");
                            printf("          ||   _____                _   ______ _ _       ||\n");
                            printf("          ||  |  __ \\              | | |  ____(_) |      ||\n");
                            printf("          ||  | |__) |___  __ _  __| | | |__   _| | ___  ||\n");
                            printf("          ||  |  _  // _ \\/ _` |/ _` | |  __| | | |/ _ \\ ||\n");
                            printf("          ||  | | \\ \\  __/ (_| | (_| | | |    | | |  __/ ||\n");
                            printf("          ||  |_|  \\_\\___|\\__,_|\\__,_| |_|    |_|_|\\___| ||\n");
                            printf("          +===============================================+\n\n");
                            readFile(root);
                            break;
                            }
                        case 3:
                            break;  // Back to the main menu
                        default:
                            printf("Opsi tidak valid. Silakan coba lagi.\n");
                        }
                    } while (sub_choice == 1);
                }
                break;
            case 4:
                display_info();
                break;
            case 5:
                printf("        +========================================================+\n");
                printf("        ||   _______ _                 _     __     __          ||\n");
                printf("        ||  |__   __| |               | |    \\ \\   / /          ||\n");
                printf("        ||     | |  | |__   __ _ _ __ | | __  \\ \\_/ /__  _   _  ||\n");
                printf("        ||     | |  | '_ \\ / _` | '_ \\| |/ /   \\   / _ \\| | | | ||\n");
                printf("        ||     | |  | | | | (_| | | | |   <     | | (_) | |_| | ||\n");
                printf("        ||     |_|  |_| |_|\\__,_|_| |_|_|\\_\\    |_|\\___/ \\__,_| ||\n");
                printf("        +========================================================+\n\n\n");
                printf("                                  Creator :                     \n");
                printf("                                  Team B3                       \n");
                printf("                       - Mohammad Amadeus Andika Fadhil         \n");
                printf("                       - Muhammad Adhyaksa Fadillah             \n");
                printf("                       - Muhammad Gianluigi Julian              \n\n");
                return;  // Exit the function to stop the loop
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    }
}

// Menampilkan menu info
void display_info() {
    printf("        +==================================================+\n");
    printf("        |                   INFO MORSE CODE                |\n");
    printf("        +==================================================+\n");
    printf("        |  Huruf/Symbol  |          Morse Code             |\n");
    printf("        +----------------+---------------------------------+\n");
    printf("        |       A        |              .-                 |\n");
    printf("        |       B        |              -...               |\n");
    printf("        |       C        |              -.-.               |\n");
    printf("        |       D        |              -..                |\n");
    printf("        |       E        |              .                  |\n");
    printf("        |       F        |              ..-.               |\n");
    printf("        |       G        |              --.                |\n");
    printf("        |       H        |              ....               |\n");
    printf("        |       I        |              ..                 |\n");
    printf("        |       J        |              .---               |\n");
    printf("        |       K        |              -.-                |\n");
    printf("        |       L        |              .-..               |\n");
    printf("        |       M        |              --                 |\n");
    printf("        |       N        |              -.                 |\n");
    printf("        |       O        |              ---                |\n");
    printf("        |       P        |              .--.               |\n");
    printf("        |       Q        |              --.-               |\n");
    printf("        |       R        |              .-.                |\n");
    printf("        |       S        |              ...                |\n");
    printf("        |       T        |              -                  |\n");
    printf("        |       U        |              ..-                |\n");
    printf("        |       V        |              ...-               |\n");
    printf("        |       W        |              .--                |\n");
    printf("        |       X        |              -..-               |\n");
    printf("        |       Y        |              -.--               |\n");
    printf("        |       Z        |              --..               |\n");
    printf("        +----------------+---------------------------------+\n");
    printf("        |       0        |              -----              |\n");
    printf("        |       1        |              .----              |\n");
    printf("        |       2        |              ..---              |\n");
    printf("        |       3        |              ...--              |\n");
    printf("        |       4        |              ....-              |\n");
    printf("        |       5        |              .....              |\n");
    printf("        |       6        |              -....              |\n");
    printf("        |       7        |              --...              |\n");
    printf("        |       8        |              ---..              |\n");
    printf("        |       9        |              ----.              |\n");
    printf("        +----------------+---------------------------------+\n");
    printf("        |       .        |              .-.-.-             |\n");
    printf("        |       ,        |              --..--             |\n");
    printf("        |       ?        |              ..--..             |\n");
    printf("        |       !        |              -.-.--             |\n");
    printf("        |       \\        |              .----.             |\n");
    printf("        |       -        |              -....-             |\n");
    printf("        |       /        |              -..-.              |\n");
    printf("        |       (        |              -.--.              |\n");
    printf("        |       )        |              -.--.-             |\n");
    printf("        |       &        |              .-...              |\n");
    printf("        |       :        |              ---...             |\n");
    printf("        |       ;        |              -.-.-.             |\n");
    printf("        |       =        |              -...-              |\n");
    printf("        |       +        |              .-.-.              |\n");
    printf("        |       _        |              ..--.-             |\n");
    printf("        |   (petik dua)  |              .-..-.             |\n");
    printf("        |       @        |              .--.-.             |\n");
    printf("        |     (space)    |              .-..-.             |\n");
    printf("        +==================================================+\n\n\n");
    printf("Tekan enter untuk kembali ke menu utama...");
    getchar(); 
}

// Membuat node baru untuk pohon Morse Code.
Node* createNode(char letter) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->letter = letter;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Memasukkan huruf ke dalam pohon Morse Code berdasarkan kode Morse yang diberikan.
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

// Melakukan traversal in-order pada pohon Morse Code dan mencetak huruf-hurufnya.
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf(" '%c' ", root->letter); // Tidak perlu spasi di sini
        inOrderTraversal(root->right);
    }
}

// Fungsi untuk melakukan traversal preorder pada pohon morse code
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf(" '%c' ", root->letter);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" '%c' ", root->letter);
    }
}

// Mencari kode Morse untuk huruf yang diberikan dan mencetaknya.
void charToMorse(Node* root, char letter, char* path, int pathLen, int* found) {
    if (root == NULL) {
        return;
    }

    if (root->letter == letter) {
        *found = 1;
        for (int i = 0; i < pathLen; i++) {
            printf("%c", path[i]);
            playMorseSound(path[i]);
        }
        printf(" ");
    }

    path[pathLen] = '.';
    charToMorse(root->left, letter, path, pathLen + 1, found);

    path[pathLen] = '-';
    charToMorse(root->right, letter, path, pathLen + 1, found);
}

// Menerjemahkan teks ke kode Morse dan mencetaknya.
void textToMorse(Node* root, const char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            printf("/ ");
        } else {
            const char* morseCode = getMorseCode(root, text[i]);
            if (morseCode) {
                printf("%s ", morseCode);
            }
        }
    }
    printf("\n");
}

// Menerjemahkan kode Morse ke huruf dan mencetaknya.
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

// Menerjemahkan kata dalam kode Morse ke huruf dan mencetaknya.
void morseWordToChar(Node* root, char* morseWord) {
    morseToChar(root, morseWord);
    printf(" ");
}

// Menerjemahkan teks dalam kode Morse ke huruf dan mencetaknya.
void morseTextToChar(Node* root, char* morseText) {
    char* token = strtok(morseText, " ");
    while (token != NULL) {
        morseWordToChar(root, token);
        token = strtok(NULL, " ");
    }
}

// Menginisialisasi pohon Morse Code dengan memasukkan semua huruf, angka, dan simbol.
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
    insert(root, "---.", '0');
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
    insert(root, "..--", '"');
    insert(root, ".--.-.", '@');
    insert(root, ".-..-.", ' '); // Spasi
}

// Fungsi untuk membaca isi file
void readFile(Node* root) {
    char filename[100];
    printf("Masukkan nama file: ");
    fgets(filename, sizeof(filename), stdin);
    // Menghapus newline character yang tersisa
    filename[strcspn(filename, "\n")] = 0;

    // Debug: Print nama file yang dimasukkan
    printf("Membuka file: %s\n", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Tidak bisa membuka file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Menghapus newline character yang tersisa
        line[strcspn(line, "\n")] = 0;

        // Debug: Print setiap baris yang dibaca
        printf("Membaca baris: %s\n", line);

        // Cek apakah ini teks biasa atau sandi Morse
        if (strchr(line, '.') != NULL || strchr(line, '-') != NULL) {
            // Ini adalah sandi Morse
            printf("Teks asli dari sandi Morse: ");
            morseTextToChar(root, line);
        } else {
            // Ini adalah teks biasa
            printf("Sandi Morse dari teks: ");
            textToMorse(root, line);
        }
        printf("\n");
    }

    fclose(file);

    printf("Tekan enter untuk kembali ke menu utama...");
    getchar(); // Menunggu sampai pengguna menekan tombol enter
}

// Sound effect untuk setiap karakter Morse.
void playMorseSound(char morseChar) {
    if (morseChar == '.') {
        Beep(800, 50); // Play a short beep for dot
        Sleep(100); // Pause for dot duration
    } else if (morseChar == '-') {
        Beep(800, 150); // Play a long beep for dash
        Sleep(200); // Pause for dash duration
    }
}

// Fungsi untuk menuliskan teks dari terminal ke dalam file
void writeTextToFile() {
    char input[256]; // Buffer untuk menyimpan input dari terminal
    printf("Masukkan teks yang ingin dituliskan ke file: ");
    fgets(input, sizeof(input), stdin); // Membaca input dari terminal
    // Menghapus newline character yang tersisa
    input[strcspn(input, "\n")] = 0;

    FILE *file = fopen("output.txt", "a"); // Membuka file dengan mode append
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return; // Mengembalikan kode error
    }

    fputs(input, file); // Menulis input ke dalam file
    fclose(file); // Menutup file

    printf("Teks berhasil ditulis ke dalam file 'output.txt'.\n");
}