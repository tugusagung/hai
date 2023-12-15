#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

void towers(int, char, char, char);
void clear();
void again();
int integer();

int num, tmp, repeat;
char YesorNo, inputChar;

int main(){
    system("cls");
    printf("--------------------------------------------\n");
    printf("  >Selamat Datang Di Program Menara Hanoi<\n");
    printf("--------------------------------------------\n");
    printf("\nMasukkan Jumlah Disk : ");
    integer();
    
    system("cls");
    printf("\n----> Langkah - Langkah Untuk Memindahkan Disk <----\n");
    towers(num, 'A', 'B', 'C');
    again();

    return 0;
}
  
int integer(){
    int firstChar = getchar();
    if (firstChar == '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        repeat = integer();
        return repeat;
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n'){
        clear();
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        repeat = integer();
        return repeat;
    }
    ungetc (firstChar, stdin);
    if (scanf("%d", &num) != 1 || getchar() != '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        clear();
        repeat = integer();
        return repeat;
    }
    if (num == 0){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        repeat = integer();
        return repeat;
    }
    return repeat;
    }

void again(){
    printf("\n---->Apakah Anda Mau Mengulang Program<----\n");
    printf("Masukkan Y atau N : ");

    int firstChar = getchar();
    if (firstChar == '\n'){
        printf ("<Input Yang Anda Masukkan Tidak Valid>\n");
        again();
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n' || isdigit(firstChar)){
        clear();
        printf("<Input Yang Anda Masukkan Tidak Valid>\n");
        again();
    }
    ungetc (firstChar, stdin);
    scanf("%c", &YesorNo);
    if (YesorNo != 'Y' && YesorNo != 'y' && YesorNo != 'N' && YesorNo != 'n' || getchar() != '\n'){
        printf("<Input Yang  Masukkan Tidak Valid>\n");
        clear();
        again();
    }
    if((YesorNo == 'Y' || YesorNo == 'y' || YesorNo == 'N' || YesorNo == 'n')){
        if(YesorNo == 'Y' || YesorNo == 'y'){
            main();
        }
        else{
            exit(0);
        }
    }
    else{
        printf("<Input Yang Anda Masukkan Tidak Valid>\n");
        clear();
        again();
    }
}

void clear(){
    do{
        tmp = getchar();
    }
    while (tmp != '\n');
}

void towers(int num, char towerA, char towerB, char towerC){
    if (num == 1){
        printf("Pindah Disk 1 Dari Tower %c Ke Tower %c\n", towerA, towerC);
        return;
    }

    towers(num -1, towerA, towerC, towerB);
    printf("Pindah Disk %d dari Tower %c ke Tower %c\n", num, towerA, towerC);
    towers(num -1, towerB, towerA, towerC);
}
