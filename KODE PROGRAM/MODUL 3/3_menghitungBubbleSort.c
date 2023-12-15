#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int integer();
void array1000();
void array16000();
void array64000();
void fillRandom(int array[], int n);
void bubbleSort(int array[], int n);
void bubbleSortPointer(int *array, int n);
void repeat();
void clear();

int tmp;
char YesorNo, choice;
clock_t start, end;
double timeDefault, timePointer;

int main(){
    system("cls");
    printf("------------------------------------------------------------------\n");
    printf("  >Selamat Datang Di Program Membuat Dan Mengurutkan Data Acak<   \n");
    printf("------------------------------------------------------------------\n");
    printf("|   1. Data Sebanyak (1000)                                      |\n");
    printf("|   2. Data Sebanyak (16000)                                     |\n");
    printf("|   3. Data Sebanyak (64000)                                     |\n");
    printf("------------------------------------------------------------------\n");
    printf("Masukkan Pilihan : ");
    integer();
    printf("\n");
    
    switch(choice){
        case '1':
        array1000();
        break;

        case '2':
        array16000();
        break;

        case '3':
        array64000();
        break;

        default:
        integer();
        break; 
    }
    return 0;
}

int integer(){
    int repeat;
    int firstChar = getchar();
    if (firstChar == '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Pilih Antara 1 Atau 2 Atau 3 : ");
        repeat = integer();
        return repeat;
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n'){
        clear();
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Pilih Antara 1 Atau 2 Atau 3 : ");
        repeat = integer();
        return repeat;
    }
    ungetc (firstChar, stdin);
    if (scanf("%c", &choice) != 1 || getchar() != '\n'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Pilih Antara 1 Atau 2 Atau 3 : ");
        clear();
        repeat = integer();
        return repeat;
    }
    if (choice > '3' || choice < '1'){
        printf("\n<Input Yang Anda Masukkan Tidak Valid>\n");
        printf("Pilih Antara 1 Atau 2 Atau 3 : ");
        repeat = integer();
        return repeat;
    }
    return repeat;
    }

void array1000(){
    int x = 1000;
    int dataArray[x];

    fillRandom(dataArray, x);
    
    printf("Data Sebelum Diurutkan : \n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");

    start = clock();
    bubbleSort(dataArray, x);
    end = clock();
    timeDefault = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSortPointer(dataArray, x);
    end = clock();
    timePointer = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    
    printf("\nData Sesudah Diurutkan:\n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");

    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Biasa : %f detik<\n", timeDefault);
    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Pointer : %f detik<\n", timePointer);
    printf("------------------------------------------------------------------\n");
    repeat();
}

void array16000(){
    int x = 16000;
    int dataArray[x];

    fillRandom(dataArray, x);

    printf("Data Sebelum Diurutkan : \n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");

    start = clock();
    bubbleSort(dataArray, x);
    end = clock();
    timeDefault = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSortPointer(dataArray, x);
    end = clock();
    timePointer = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Data Sesudah Diurutkan:\n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");
    
    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Biasa : %f detik<\n", timeDefault);
    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Pointer : %f detik<\n", timePointer);
    printf("------------------------------------------------------------------\n");
    repeat();
}

void array64000(){
    int x = 64000;
    int dataArray[x];

    fillRandom(dataArray, x);

    printf("Data Sebelum Diurutkan : \n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");

    start = clock();
    bubbleSort(dataArray, x);
    end = clock();
    timeDefault = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSortPointer(dataArray, x);
    end = clock();
    timePointer = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Data Sesudah Diurutkan:\n");
    for (int i = 0; i < x; i++) {
        printf("Data ke-%d : %d\n", i+1, dataArray[i]);
    }
    printf("\n");

    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Biasa : %f detik<\n", timeDefault);
    printf("------------------------------------------------------------------\n");
    printf("             >Waktu Bubble Sort Pointer : %f detik<\n", timePointer);
    printf("------------------------------------------------------------------\n");
    repeat();

}

void fillRandom(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand();
    }
}

void bubbleSort(int array[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void bubbleSortPointer(int *array, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(array + j) > *(array + j + 1)) {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

void repeat(){
    printf("\n---->Apakah Anda Mau Mengulang Program<----\n");
    printf("Masukkan Y atau N : ");

    int firstChar = getchar();
    if (firstChar == '\n'){
        printf ("<Input Yang Anda Masukkan Tidak Valid>\n");
        repeat();
    }
    if (firstChar == ' ' || firstChar == '+' || firstChar == '-' || firstChar == '\n' || isdigit(firstChar)){
        clear();
        printf("<Input Yang Anda Masukkan Tidak Valid>\n");
        repeat();
    }
    ungetc (firstChar, stdin);
    scanf("%c", &YesorNo);
    if (YesorNo != 'Y' && YesorNo != 'y' && YesorNo != 'N' && YesorNo != 'n' || getchar() != '\n'){
        printf("<Input Yang Anda Masukkan Tidak Valid>\n");
        clear();
        repeat();
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
        repeat();
    }
}

void clear(){
    do{
        tmp = getchar();
    }
    while (tmp != '\n');
}