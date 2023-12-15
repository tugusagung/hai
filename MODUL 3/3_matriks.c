#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int input(), input_value();
void clear();
bool again();

int r1, c1, r2, c2, op, sc, s2;
char s[10];

int main(){
    system("cls");
    printf("\t,_________________________,\n");
    printf("\t|                         |\n");
    printf("\t|     Program Matriks     |\n");
    printf("\t|_________________________|\n\n");
    printf(",_________________________________________,\n");
    printf("|                                         |\n");
    printf("|  1. Perkalian Matriks dengan Skalar     |\n");
    printf("|  2. Perkalian antar Matriks             |\n");
    printf("|  3. Pertambahan antar Matriks           |\n");
    printf("|  4. Transpose Matriks                   |\n");
    printf("|  5. Exit                                |\n");
    printf("|_________________________________________|\n\n");
    
    printf("Masukkan pilihan : ");
    op = input();

    system("cls");
    if (op == 1){
        printf(",_______________________________________,\n");
        printf("|                                       |\n");
        printf("|   Perkalian Matriks dengan Skalar     |\n");
        printf("|_______________________________________|\n\n");
    }
    else if (op == 2){
        printf(",_______________________________,\n");
        printf("|                               |\n");
        printf("|   Perkalian antar Matriks     |\n");
        printf("|_______________________________|\n\n");
    }
    else if (op == 3){
        printf(",_________________________________,\n");
        printf("|                                 |\n");
        printf("|   Pertambahan antar Matriks     |\n");
        printf("|_________________________________|\n\n");
    }
    else if (op == 4){
        printf(",_________________________,\n");
        printf("|                         |\n");
        printf("|   Transpose Matriks     |\n");
        printf("|_________________________|\n\n");
    }

    if (op != 2){
        printf("Masukkan jumlah baris matriks : ");
        r1 = input();
        printf("Masukkan jumlah kolom matriks : ");
        c1 = input();
    }
    else if(op == 2){
        printf("Masukkan jumlah baris matriks pertama : ");
        r1 = input();
        printf("Masukkan jumlah kolom matriks pertama : ");
        c1 = input();

        printf("\nMasukkan jumlah baris matriks kedua : ");
        r2 = input();
        printf("Masukkan jumlah kolom matriks kedua : ");
        c2 = input();
    }

    int matriks1[r1][c1];
    int matriks2[r1][c1];
    int matriks_hasil[r1][c1];
    int valid = 1;
    switch (op){
    case 1:
        // Perkalian skalar
        printf("\nMasukkan nilai matriks\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                matriks1[i][j] = input_value();
            }
        }
        
        printf("\nMasukkan nilai skalar : ");
        sc = input_value();
        for (int i = 0; i < r1; i++){
            for(int j = 0; j < c1; j++){
                matriks_hasil[i][j] = matriks1[i][j]*sc;
            }
        }
        break;
    case 2:
        // Perkalian antar matriks
        if (r1 == c2){
            printf("\nMasukkan nilai matriks pertama\n");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                    matriks1[i][j] = input_value();
                }
            }
            matriks2[r2][c2];
            printf("\nMasukkan nilai matriks kedua\n");
            for (int i = 0; i < r2; i++) {
                for (int j = 0; j < c2; j++) {
                    printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                    matriks2[i][j] = input_value();
                }
            }

            matriks_hasil[r1][c2];
            for (int i = 0; i < r1; i++){
                for (int j = 0; j < c2; j++){
                    matriks_hasil[i][j] = 0;
                    for (int k = 0; k < c2; k++){
                    matriks_hasil[i][j] += matriks1[i][k] * matriks2[k][j];
                    }
                }
            }
        }
        else{
            printf("\nInvalid, syarat perkalian antar matriks adalah baris matriks pertama harus sama dengan kolom baris kedua!\n");
            valid = 0;
        }
        break;
    case 3:
        // Pertambahan matriks
        printf("\nMasukkan nilai matriks pertama\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                matriks1[i][j] = input_value();
            }
        }

        printf("\nMasukkan nilai matriks kedua\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                matriks2[i][j] = input_value();
            }
        }
        for (int i = 0; i < r1; i++){
                for (int j = 0; j < c1; j++){
                    matriks_hasil[i][j] = matriks1[i][j] + matriks2[i][j];
                }
        }
        break;
    case 4:
        // Transpose matriks
        printf("\nMasukkan nilai matriks pertama\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("Masukkan nilai baris %i kolom %i: ", i + 1, j + 1);
                matriks1[i][j] = input_value();
            }
        }
        for (int i = 0; i < r1; i++){
            for (int j = 0; j < c1; j++){
                matriks_hasil[j][i] = matriks1[i][j];
            }
        }
        break;
    case 5:
        return 0;
        break;
    default:
        clear();
        main();
        return 0;
    }

    if (valid == 1){
        printf("\nHasil : \n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("%i ", matriks_hasil[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nApakah Anda ingin mengulang kembali program? (y/n)\n");
    if (again())
    {
        clear();
        main();
        return 0;
    }
    return 0;
}

bool again(){
    scanf("%s", s);
    if (strlen(s) == 1)
    {
        if (s[0] == 'y' || s[0] == 'Y')
        {
            return 1;
        }
        else if (s[0] == 'n' || s[0] == 'N')
        {
            return 0;
        }
    }
    clear();
    printf("Pilihan tidak valid, mohon masukkan kembali pilihan : ");
    s2 = again();
    return s2;
}

int input(){
    char buff[10];
    fgets(buff, 10, stdin);

    for (int i = 0; i < 10; i++){
        if (isdigit(buff[i]) == 1 && buff[i+1] == '\n') {
            break;
        }
        else if (isdigit(buff[i]) != 1 && buff[i] != ' '|| buff[i] == '\n' || buff [i] == '+' || buff [i] == '-' || buff [i] == ' ' && isdigit(buff [i+1]) == 1){
            fflush(stdin);
            printf("Input tidak valid, mohon masukkan input yang valid : ");
            return input();
        }
    }

    int value = atoi(buff);
    return value;
}

int input_value(){
    int i = 0;
    char buff[10];
    fgets(buff, 10, stdin);

    if (buff[0] == '-'){
        i = 1;
    }
    while (i < 10){
        if (isdigit(buff[i]) == 1 && buff[i+1] == '\n') {
            break;
        }
        else if (isdigit(buff[i]) != 1 && buff[i] != ' '|| buff[i] == '\n' || buff[i] == '+' || buff[i] == ' ' && isdigit(buff [i+1]) == 1){
            fflush(stdin);
            printf("Input tidak valid, mohon masukkan input yang valid : ");
            return input();
        }
        i++;
    }

    int value = atoi(buff);
    return value;
}

void clear(){
    while (getchar() != '\n');    
}