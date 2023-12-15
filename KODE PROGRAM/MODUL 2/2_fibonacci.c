#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

char buff1[10];

int input1(int x);
int validasi_menu();
int restart(int y);
int rekursif(int n);
void iteratif();
void menu();

int main() {
    int karakter;
    do {
        char pilihan;

        menu();
        pilihan = validasi_menu();

        if (pilihan == 1) {
            int i, n, hasil;
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\t                     BILANGAN FIBONACCI METODE REKURSIF                    \n");
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\tMasukan jumlah deret bilangan fibonacci: ");
            n = input1(n);
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\tHasil bilangan fibonacci berderet %d adalah:\n", n);

            printf("\t\t\t");
            for (i = 0; i < n; i++) {
                hasil = rekursif(i);
                printf("%d ", hasil);
            }
            printf("\n");

            printf("\n\t\t\tApakah Anda ingin menjalankan kembali program?");
            printf("\n\t\t\tTekan 1 Jika Ingin Kembali Ke Menu Awal\n");
            printf("\t\t\tTekan 0 Jika Ingin Keluar dari Program\n");
            printf("\t\t\tSilahkan Masukan Pilihan [0/1]: ");
            karakter = restart(karakter);
        } else if (pilihan == 2) {
            iteratif();
            
            printf("\n\t\t\tApakah Anda ingin menjalankan kembali program?");
            printf("\n\t\t\tTekan 1 Jika Ingin Kembali Ke Menu Awal\n");
            printf("\t\t\tTekan 0 Jika Ingin Keluar dari Program\n");
            printf("\t\t\tSilahkan Masukan Pilihan [0/1]: ");
            karakter = restart(karakter);
        } else if (pilihan == 3) {
            printf("\t\t\t                  TERIMA KASIH TELAH MENCOBA PROGRAM INI               \n");
            return 0;
        } else {
            printf("\t\t\tMasukan bilangan bulat yang sesuai (1/2/3): ");
        }
    } while (karakter == 1);
    printf("\t\t\t                  TERIMA KASIH TELAH MENCOBA PROGRAM INI               \n");
    return 0;
}

int input1(int x){
    bool valid;
    fgets (buff1, 10, stdin);
    for (int i=0; i<sizeof(buff1); i++){
        if (isdigit(buff1[i]) == 1 && buff1[i+1] == '\n' || isdigit(buff1[i]) == 1 && buff1[i+1] == '\0'){
            valid = 1;
            break;
        }
        else if (buff1[i] == '0' && buff1[i+1] == '0' || buff1[i] == '0' && isdigit(buff1[i]) == 1){
            valid = 0;
            printf("\n\t\t\t[!] ERROR ----  Invalid Input! [input[%d], char: %c] Coba lagi!", i, buff1[i]);
            break;
        }
        else if (isdigit(buff1[i]) == 1){
            continue;
        }
        else{
            valid = 0;
            printf("\n\t\t\t[!] ERROR ----  Invalid Input! [input[%d], char: %c] Coba lagi!", i, buff1[i]);
            break;
        }
    }
    if(valid == 0){
        printf("\n\t\t\t> ");
        input1(x);
    }
    else if (valid == 1){
        x = atoi(buff1);
        return x;
    }
}

int validasi_menu() {
    int bilangan;
    bilangan = input1(bilangan);
    if (bilangan == 1 || bilangan == 2 || bilangan == 3 ) {
        return bilangan;
    } else {
        printf("\t\t\tMasukan pilihan yang sesuai (1/2/3): ");
        return validasi_menu();
    }
}

int rekursif(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return rekursif(n - 1) + rekursif(n - 2);
    }
}

void iteratif() {
    int n, i, hasil;
    int s0 = 0, s1 = 1;
    printf("\t\t\t===========================================================================\n");
    printf("\t\t\t                      BILANGAN FIBONACCI METODE ITERATIF                   \n");
    printf("\t\t\t===========================================================================\n");
    printf("\t\t\tMasukan jumlah deret bilangan fibonacci: ");
    n = input1(n);
    printf("\t\t\t===========================================================================\n");
    printf("\t\t\tHasil bilangan fibonacci berderet %d adalah:\n", n);
    printf("\t\t\t%d %d ", s0, s1);
    for (i = 0; i < n - 2; i++) {
        hasil = s1 + s0;
        printf("%d ", hasil);
        s0 = s1;
        s1 = hasil;
    }
    printf("\n") ;
}

void menu() {
    printf("\t\t\t=======================================================================\n");
    printf("\t\t\t=                    Program Deret Bilangan Fibonacci                 =\n");
    printf("\t\t\t=                      Metode Rekursif dan Iteratif                   =\n");
    printf("\t\t\t=======================================================================\n");
    printf("\t\t\t=                     MENU PILIHAN PENGGUNAAN METODE                  =\n");
    printf("\t\t\t= =================================================================== =\n");
    printf("\t\t\t= 1. Metode Rekursif                                                  =\n");
    printf("\t\t\t= 2. Metode Iteratif                                                  =\n");
    printf("\t\t\t= 3. Keluar dari program                                              =\n");
    printf("\t\t\t=======================================================================\n");
    printf("\t\t\tMasukan Pilihan (1/2/3): ");
}

int restart(int y){
    printf("\n\t\t\t> ");
    y = input1(y);
    switch(y){
        case 1:
        system ("cls");
        main();
        case 0:
        return 0;

        default:
        printf("\n\t\t\t[!] ERROR ----- Invalid Input : Coba lagi");
        restart(y);
    }
}