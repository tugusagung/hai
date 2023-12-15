#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

int jumlah, tmp;
int i;
char YesorNo;

void clear();
void validateName();
int validateValue();
int validateAmount();
int compare(const void *a, const void *b);

struct data{
    char nama[100];
    int nilai;
};
struct data mahasiswa[100];

int main(){
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("  >Selamat Datang Di Program Membuat File Ranking<   \n");
    printf("-----------------------------------------------------\n");
    printf("Masukkan Jumlah Mahasiswa : ");
    
    validateAmount();
    for(i ; i < jumlah ; i++){
        printf("\nMasukkan Nama : ");
        validateName();
        
        printf("Masukkan Nilai : ");
        validateValue();
    }

    FILE *inputFile;
    inputFile = fopen("asistenin.txt", "a");
    fprintf(inputFile, "-----------------------------------------------------------\n");
    for (i = 0; i < jumlah; i++){
        fprintf(inputFile, ">> Nama : %s", mahasiswa[i].nama);
        fprintf(inputFile, "   Nilai : %d\n", mahasiswa[i].nilai);
    }
    fprintf(inputFile, "-----------------------------------------------------------\n");
    fclose(inputFile);
    printf("\n-----------------------------------------------------------\n");
    printf("  >Data Berhasil Di Inputkan Di Dalam File asistenin.txt<  \n");
    printf("-----------------------------------------------------------\n\n");

    FILE *outputFile;
    outputFile = fopen("asistensiout.txt", "a");

    qsort(mahasiswa, jumlah, sizeof(struct data), compare);
    fprintf(outputFile, "-----------------------------------------------------------\n");
    for(i = 0; i < jumlah; i++ ){
        fprintf(outputFile, "%d.\tNama : %s", i+1, mahasiswa[i].nama);
        fprintf(outputFile, "\tNilai : %d\n", mahasiswa[i].nilai);
    }
    fprintf(outputFile, "-----------------------------------------------------------\n");
    fclose(outputFile);
    printf("-----------------------------------------------------------\n");
    printf("  >Data Berhasil Di Urutkan Di Dalam File asistensiout.txt<   \n");
    printf("-----------------------------------------------------------\n");


    return 0;
}

int compare(const void *a, const void *b) {
    return ((struct data*)b)->nilai - ((struct data*)a)->nilai;
}

int validateValue(){
    int repeat;
    int firstChar = getchar();
    if (firstChar == '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Nilai : ");
        repeat = validateValue();
        return repeat;
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n'){
        clear();
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Nilai : ");
        repeat = validateValue();
        return repeat;
    }
    ungetc (firstChar, stdin);
    if(scanf("%d", &mahasiswa[i].nilai) != 1 || getchar() != '\n' ){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Nilai : ");
        clear();
        repeat = validateValue();
        return repeat;
    }
    return repeat;
}

void validateName() {
    int firstChar = getchar();

    if (firstChar == '\n') {
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Nama : ");
        return validateName();
    }

    if (firstChar == '+' || firstChar == '-' || ispunct(firstChar) || isdigit(firstChar) || isspace(firstChar)) {
        clear();
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Nama : ");
        return validateName();
    }

    ungetc(firstChar, stdin);
    fgets(mahasiswa[i].nama, sizeof(mahasiswa[i].nama), stdin);
    mahasiswa[i].nama[strcspn(mahasiswa[i].nama, "\n")];

    for (int j = 1; j < strlen(mahasiswa[i].nama); j++) {
        if (isdigit(mahasiswa[i].nama[j]) || ispunct(mahasiswa[i].nama[j])) {
            printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
            printf("Masukkan Nama : ");
            return validateName();
        }
    }
}

int validateAmount(){
    int repeat;
    int firstChar = getchar();
    if (firstChar == '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        repeat = validateAmount();
        return repeat;
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n'){
        clear();
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        repeat = validateAmount();
        return repeat;
    }
    ungetc (firstChar, stdin);
    if(scanf("%d", &jumlah) != 1 || getchar() != '\n' ){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        clear();
        repeat = validateAmount();
        return repeat;
    }
    if(jumlah == 0){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Masukkan Bilangan Integer Mulai Dari 1 : ");
        clear();
        repeat = validateAmount();
        return repeat;
    }
    
    return repeat;
}

void clear(){
    do{
        tmp = getchar();
    }
    while (tmp != '\n');
}