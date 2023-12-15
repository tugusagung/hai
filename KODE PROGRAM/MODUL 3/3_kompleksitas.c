#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define false 0
#define true 1

const int small = 1000;
const int medium = 16000;
const int big = 64000;

int input();
bool again();
void UIfirsttime();
void clear();
void swap(long long *a, long long *b);
int partition(long long array[], int low, int high);
void quickSort(long long array[], int low, int high);
void printArray(long long array[], int size);
void bubbleSort(long long arr[], int n);
void insertionSort(long long arr[], int n);
int linearSearch(long long arr[], int N, int x);
int binarySearch(long long arr[], int l, int r, int x);
long long getCurrentTimeMicroseconds();
   

int main(){
    int s, option, tosearch;
    srand(time(0));

    char buff[10];
    bool valid;

    for (int i=0; i<10; i++){
        buff [i] = ' ';
    }

    UIfirsttime();
    
    printf("Input nilai untuk dicari: ");
    fgets(buff, 10, stdin);

    for (int i = 0; i < 10; i++){
        if (isdigit(buff[i]) == 1 && buff[i+1] == ' '|| isdigit(buff[i]) == 1 && buff[i+1] == '\n') {
            break;
        }
        else if (isdigit(buff[i]) != 1 && buff[i] != ' '|| buff[i] == '\n' || buff [i] == '+' || buff [i] == '-' || buff [i] == ' ' && isdigit(buff [i+1]) == 1){
            system ("cls");
            printf("\n*** PROGRAM : [!] ERROR Input Invalid! [Char %d] *** \n\n", i);
            fflush(stdin);
            main();
            return 0;
        }
        else{continue;}
    }

    tosearch = atoi(buff);

    valid = 0;
    printf("<-------------------------------------------------------->\n");
    printf("|               Berikan Input Jumlah Data!               |\n");
    printf("|               [1] 1k   [2] 16k   [3] 64k               |\n");
    printf("<-------------------------------------------------------->\n");
    
    printf("Jumlah data : ");

    while (valid == 0){
        
        option = input();

        if (option == 1){
            s = small;
            valid = 1;
        }
        else if (option == 2){
            s = medium;
            valid = 1;
        }
        else if (option == 3){
            s = big;
            valid = 1;
        }
        else{
            printf("\n[!] ERROR Input Invalid! Coba Lagi: ");
            valid = 0;
        }
    }

    long long random[s], random1[s], random2[s], random3[s];
    for (int i = 0; i < s; i++){
        random[i] = rand() % s + 1;
    }

    random[rand() % s +1] = tosearch;

    for (int i = 0; i < s; i++){
        random1[i] = random[i];
        random2[i] = random[i];
        random3[i] = random[i];
    }

    int n = sizeof(random) / sizeof(random[0]);
    printArray(random, n);
    system("pause");
    system("cls");

    printf("\n[1/5] Insertion Sort is Sorting!\n");
    long long insert_start = getCurrentTimeMicroseconds();
    insertionSort(random, n);
    long long insert_end = getCurrentTimeMicroseconds();
    printf("[+] Insertion Sort Done!\n");
    double insert = (insert_end - insert_start) / 1e6;

    printf("\n[2/5] Bubble Sort is Sorting!\n");
    long long bubble_start = getCurrentTimeMicroseconds();
    bubbleSort(random1, n);
    long long bubble_end = getCurrentTimeMicroseconds();
    printf("[+] Bubble Sort Done!\n");
    double bubble = (bubble_end - bubble_start) / 1e6;

    printf("\n[3/5] Quick Sort is Sorting!\n");
    long long quick_start = getCurrentTimeMicroseconds();
    quickSort(random2, 0, n);
    long long quick_end = getCurrentTimeMicroseconds();
    printf("[+] Quick Sort Done!\n");
    double quick = (quick_end - quick_start) / 1e6;

    printf("\n[4/5] Linear Search is Searching!\n");
    long long linearS_start = getCurrentTimeMicroseconds();
    int statusL = linearSearch(random3, n, tosearch);
    long long linearS_end = getCurrentTimeMicroseconds();
    printf("[+] Linear Search Done!\n");
    double linearS = (linearS_end - linearS_start) / 1e6;

    printf("\n[5/5] Binary Search is Searching!\n");
    long long binary_start = getCurrentTimeMicroseconds();
    int statusB = binarySearch(random, 0, n, tosearch);
    long long binary_end = getCurrentTimeMicroseconds();
    printf("[+] Binary Search Done!\n");
    double binaryS = (binary_end - binary_start) / 1e6;

    char sort[][20] = {"Selection Sort", "Bubble Sort", "Quick Sort"};
    char search[][20] = {"Linear Search", "Binary Search"};

    double sort_speed[3] = {insert, bubble, quick};
    double search_speed[2] = {linearS, binaryS};
    int sort_placeholder = 0;
    int search_placeholder = 0;
    int sort_same = 0;
    int search_same = 0;

    for (int i = 1; i < 3; i++){
        if (sort_speed[sort_placeholder] == sort_speed[i]){
            sort_same++;
        }
        else if (sort_speed[sort_placeholder] > sort_speed[i]){
            sort_placeholder = i;
        }
    }
    for (int i = 1; i < 2; i++){
        if (search_speed[search_placeholder] == search_speed[i]){
            search_same++;
        }
        else if (search_speed[search_placeholder] > search_speed[i]){
            search_placeholder = i;
        }
    }
    char *sort_tercepat = sort[sort_placeholder];
    char *search_tercepat = search[search_placeholder];

    printf("\n");
    system("pause");
    system("cls");
    printArray(random2, n);

    printf("<-------------------------------------------------------->\n");
    printf("|               Hasil Searching (Pencarian)              |\n");
    printf("<-------------------------------------------------------->\n");

    if (statusL == -1){
        printf ("[!] Linear search didn't find the value!\n");
    }
    else {
        printf ("[+] Linear search found the value at random[%d]\n", statusL);
    }

    if (statusB == -1){
        printf ("[!] Binary search didn't find the value!\n");
    }
    else {
        printf ("[+] Binary search found the value at random[%d]\n", statusB);
    }

    
    printf("\n<-------------------------------------------------------->\n");
    printf("|             Hasil Perhitungan Waktu (detik)            |\n");
    printf("<-------------------------------------------------------->\n");

    printf("Insertion Sort      : %lf\n", insert);
    printf("Bubble Sort         : %lf\n", bubble);
    printf("Quick Sort          : %lf\n", quick);
    printf("Insertion Search    : %lf\n", linearS);
    printf("Binary Search       : %lf\n", binaryS);

    printf("\n<-------------------------------------------------------->\n");
    printf("|             Hasil Perbandingan Waktu (detik)            |\n");
    printf("<-------------------------------------------------------->\n");
    
    if (search_same == 1){
        printf("Search : Kedua Jenis Search Setara\n");
    }
    else{
        printf("Search Tercepat : %s\n", search_tercepat);
    }
    if (sort_same == 2){
        printf("Sort : Ketiga Jenis Sort Setara");
    }
    else{
        printf("Sort Tercepat : %s", sort_tercepat);
    }

    printf("\n<-------------------------------------------------------->\n");
    printf("|   Apakah Anda ingin mengulang kembali program? (y/n)   |\n");
    printf("<-------------------------------------------------------->\n"); 
    printf("> ");

    if (again())
    {
        clear();
        system ("cls");
        main();
        return 0;
    }
}

bool again(){
    char s[10];
    int s2;
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

void UIfirsttime(){
    printf("<-------------------------------------------------------->\n");
    printf("|        Selamat Datang di Program Kalkulasi Waktu       |\n");
    printf("|              Algoritma Searching & Sorting             |\n");
    printf("<-------------------------------------------------------->\n");
}

long long getCurrentTimeMicroseconds() {
    struct timeval currentTime;
    mingw_gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int input(){
    int value;
    if (scanf("%i", &value) == 0){
        printf("[!] ERROR Input Integer Valid : ");
        clear();
        value = input();
        return value;
    }
    else{
        if (getchar() != '\n'){
            clear();
            printf("[!] ERROR Input Integer Valid : ");
            value = input();
            return value;
        }
        return value;
    }
}

void clear(){
    while (getchar() != '\n');    
}

void swap(long long *a, long long *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(long long array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

void quickSort(long long array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void bubbleSort(long long arr[], int n)
{
	int i, j;
    bool swapped;

	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void insertionSort(long long arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(long long array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("No. %i : %d\n", i+1, array[i]);
  }
  printf("\n");
}

int linearSearch (long long arr[], int N, int x){
    for (int i = 0; i < N; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
}

int binarySearch(long long arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}