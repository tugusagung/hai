#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char buff1[10];             

char* encrypt(char *text, int key);
char* decrypt(char *text, int key);
int input0(int x);          
int input1(int x);          
int restart(int y);         
void clear(FILE* stream);   
void cls();                 

int main() {
    int x, y, key;
    bool valid;
    char textIn[500];
    for (int i = 0; i < 500; ++i){
        textIn[i] = ' ';
    }
    printf("<-------------------------------------------------------->\n");
    printf("|          Selamat Datang di Program Pergeseran          |\n");
    printf("|                Enkripsi-Deskripsi Teks                 |\n");
    printf("<-------------------------------------------------------->\n"); 
    
    printf("\nMasukkan teks: ");
    fgets (textIn, sizeof(textIn), stdin);
    fflush(stdin);

    printf("Masukkan pergeseran enkripsi : ");
    key = input1(key);

    printf("\nInput: %s", textIn);
    printf("Pergeseran: %d\n", key);

    printf("\nPilihan operasi: (1) Enkripsi || (2) Dekripsi || (3) Enkripsi-Dekripsi");
    printf("\n> ");
    x = input0(x);

    switch(x){
        case 1:
        encrypt(textIn, key);
        printf("\nHasil enkripsi : %s", textIn);
        break;

        case 2:
        decrypt(textIn, key);
        printf("\nHasil dekripsi : %s", textIn);
        break;

        case 3:
        encrypt(textIn, key);
        printf("\nHasil enkripsi : %s", textIn);
        decrypt(textIn, key);
        printf("\nHasil dekripsi : %s", textIn);
        break;

        default:
        printf("[!] Pilihan ---- Invalid Input : Coba lagi");
        printf("\n> ");
        x = input0(x);
    }

    printf("\nApakah Anda Ingin Mengulang Program?: (1) Ulang Program || (2) Keluar ");
    y = restart(y);

    while (y != 0){
        if (y == 0){
            return 0;
        }
        else {
            y = restart(y);
        }
    }
}

void cls(){
     system("cls");
}

int input0(int x){
    char input[10];
    fgets (input, 10, stdin);
    
    if (input[0] == '1' && input[1] == '\n' || input[0] == '2' && input[1] == '\n' || input[0] == '3' && input[1] == '\n' ){
        x = atoi(input);
        return x;
    }
    else{
        printf("\n[!] Pilihan ----- Invalid Input! : Coba lagi");
        printf("\n> ");
        input0(x);
    }
}

int input1(int x){
    bool valid;
    fgets (buff1, 10, stdin);

    for (int i=0; i<sizeof(buff1); i++){

        

        if (isdigit(buff1[i]) == 1 && buff1[i+1] == '\n' || isdigit(buff1[i]) == 1 && buff1[i+1] == '\0'){
            valid = 1;
            break;
        }
        else if (isdigit(buff1[i]) == 1){
            continue;
        }
        else{
            valid = 0;
            printf("\n[!] Pergeseran ----  Invalid Input! [input[%d], char: %c] Coba lagi!", i, buff1[i]);
            break;
        }
    }

    if(valid == 0){
        printf("\n> ");
        input1(x);
    }
    else if (valid == 1){
        x = atoi(buff1);
        return x;
    }
}

void clear(FILE* stream){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int restart(int y){
    
    printf("\n> ");
    y = input0(y);

    switch(y){
        case 1:
        cls();
        main();

        case 2:
        return 0;

        default:
        printf("[!] Opsi ----- Invalid Input : Coba lagi");
        restart(y);
    }


}

char* decrypt(char *text, int key) {
    int i;
    char ch;
   for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalnum(ch)) {

            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }

            if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }


            if (isdigit(ch)) {
                ch = (ch - '0' - key + 10) % 10 + '0';
            }
        }
        else if (ch == ' '){
                ch = ' ';
            }

        else if (ch == '\n'){
                ch = '\n';
            }

        else {
            cls();
            printf("[!] Dekripsi ---- Partly Decrypted Input : %s", text);
            printf("[!] Dekripsi ---- Invalid Character! [Error at input[%d] --> ch : '%c']\n", i, ch);
            printf("[!] Dekripsi ---- Character is not Alphanumeric! [!]");
            main();
        }
        text[i] =ch;
    }
    return text;
}

char* encrypt(char *text, int key) {
    int i;
    char ch;

    for (i=0; text[i] != '\0'; ++i){
        ch = text[i];
        if (isalnum (ch)){

            if(islower(ch)){
                ch = (ch - 'a' + key) % 26 + 'a';
            }

            if (isupper(ch)){
                ch = (ch - 'A' + key) % 26 + 'A';
            }

            if (isdigit(ch)){
                ch = (ch - '0' + key) % 10 + '0';
            }
        }

        else if (ch == ' '){
                ch = ' ';
            }

        else if (ch == '\n'){
                ch = '\n';
            }

        else {
            cls();
            printf("\n[!] Enkripsi ---- Partly Encrypted Input : %s", text);
            printf("[!] Enkripsi ---- Invalid Character! [Error at input[%d] --> ch : '%c']\n", i, ch);
            printf("[!] Enkripsi ---- Character is not Alphanumeric! [!]\n");
            main();
        }
        
        text[i] = ch;
    }
    return text;
}