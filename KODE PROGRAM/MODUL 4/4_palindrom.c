#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *input_string();
char *reverse(char *str, int n);
void breakdown(FILE *file, char *string, int n, char *answer);
void clear();
bool again();

char *str, *rvs, *exs, *answer;
char str_cmp[1024], line[1024];
int n, cmp;
int invalid_input = 0;
FILE *file;

int main(){
    file = fopen("kamuskata.txt", "a+");
    if (file == NULL){
        file = fopen("kamuskata.txt", "w+");
        if (file == NULL){
            printf("Error.");
        }
    }

    system("cls");
    if (invalid_input != 1){
        printf("<-------------------------------------------------------->\n");
        printf("|          Selamat Datang di Program Palindrom           |\n");
        printf("|                Modul 4 Praktikum Alprog                |\n");
        printf("<-------------------------------------------------------->\n");
    }

    else {
        printf("<-------------------------------------------------------->\n");
        printf("|        [Error!] : Input Invalid! Coba Lagi!            |\n");
        printf("<-------------------------------------------------------->\n");
        system("pause");
        system("cls");
        invalid_input = 0;
        main();
        return 0;
    };

    printf("Input kata : ");
    str = input_string();
    if(str == NULL){
        invalid_input = 1;
        clear();
        main();
        return 0;
    }
    n = strlen(str);
    rvs = reverse(str, n);
    printf("\n[+] Hasil Input\n");
    printf("String : %s\n", str);
    printf("Reverse : %s\n", rvs);
    
    if (strcmp(str, rvs) == 0){
        answer = "Palindrom";
        printf("%s\n", answer);
    }
    else{
        answer = "Bukan palindrom";
        printf("%s\n", answer);
    }

    cmp = 1;
    while(fgets(str_cmp, n+1, file) != NULL){
        fgets(line, sizeof(line), file);
        size_t len = strlen(str_cmp);
        if (strcmp(str_cmp, str) == 0){
            cmp = 0;
            break;
        }
    }
    if (cmp){
        breakdown(file, str, n, answer);
    }

    free(str);
    free(rvs);
    fclose(file);

    printf("\n[+] Success : Berhasil menulis ke dalam kamuskata.txt !\n");

    printf("\n<-------------------------------------------------------->\n");
    printf("|   Apakah Anda ingin mengulang kembali program? (y/n)   |\n");
    printf("<-------------------------------------------------------->\n"); 
    printf("> ");
    if (again())
    {
        invalid_input = 0;
        clear();
        main();
        return 0;
    }
    system("pause");
    return 0;
}

char *input_string(){
    char string[100];
    if (string == NULL) {
        perror("Alokasi Memory Gagal");
        exit(EXIT_FAILURE);
    }

    scanf("%[^\n]", string);
    int n = strlen(string);
    for (int i = 0; i < n; i++){
        if (isspace(string[i]) != 0 || n == 0){
            return NULL;
        }
    }
    char *pstring = malloc(sizeof(char)*(n+1));
    if (pstring == NULL) {
        perror("Alokasi Memory Gagal");
        exit(EXIT_FAILURE);
    }

    strcpy(pstring, string);
    return pstring;
}

char *reverse(char *str, int n){
    int index = 0;
    char *rvs = malloc(sizeof(char)*(n + 1));
    if (rvs == NULL) {
        perror("Alokasi Memory Gagal");
        exit(EXIT_FAILURE);
    }
    for (int i = n; i > 0; i--){
        rvs[index] = str[i-1];
        index++;
    }
    rvs[n] = '\0';
    return rvs;
}

void breakdown(FILE *file, char *string, int n, char *answer){
    int count[93] = {0};
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= '!' && string[i] <= '~') {
            count[string[i] - '!']++;
        }
    }

    fprintf(file, "%s(%i) : ", string, n);
    for (int i = 0; i < 93; i++) {
        if (count[i] > 0) {
            fprintf(file, "%c=%d ", i + '!', count[i]);
        }
    }
    fprintf(file, ": %s\n", answer);
}

void clear(){
    while (getchar() != '\n');
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