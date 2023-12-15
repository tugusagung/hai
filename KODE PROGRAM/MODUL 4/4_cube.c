#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void clear();
bool again();

typedef struct struct_cube{
    int sisi;
    int luas_permukaan;
    int volume;
} sCube;

typedef union union_cube{
    int sisi;
    int luas_permukaan;
    int volume;
} uCube;

int main(){
    sCube scube;
    uCube ucube;
    size_t scube_size = sizeof(scube.sisi) + sizeof(scube.luas_permukaan) + sizeof(scube.volume);

    system("cls");
    char buff[10];

    for (int i = 0; i < 10; i++){
        buff [i] = ' ';
    }

    printf("<-------------------------------------------------------->\n");
    printf("|             Program Kubus Struct dan Union             |\n");
    printf("<-------------------------------------------------------->\n");
    printf("Input sisi kubus : ");
    fgets(buff, 10, stdin);

    for (int i = 0; i < 10; i++){
        if (isdigit(buff[i]) == 1 && buff[i+1] == '\n') {
            break;
        }
        else if (isdigit(buff[i]) != 1 && buff[i] != ' '|| buff[i] == '\n' || buff [i] == '+' || buff [i] == '-' || buff [i] == ' ' && isdigit(buff [i+1]) == 1){
            fflush(stdin);
            main();
            return 0;
        }
    }

    scube.sisi = atoi(buff);
    scube.luas_permukaan = pow(scube.sisi, 3);
    scube.volume = scube.luas_permukaan;

    printf("\nKubus dengan Struct\n");
    printf("Sisi : %i\n", scube.sisi);
    printf("Luas Permukaan : %i\n", scube.luas_permukaan);
    printf("Volume : %i\n", scube.volume);

    printf("\nKubus dengan Union\n");
    ucube.sisi = scube.sisi;
    printf("Sisi : %i\n", scube.sisi);
    ucube.luas_permukaan = scube.luas_permukaan;
    printf("Luas Permukaan : %i\n", scube.luas_permukaan);
    ucube.volume = scube.volume;
    printf("Volume : %i\n", scube.volume);

    printf("\nUkuran memory pada kubus struct : %i\n", scube_size);
    printf("Ukuran memory pada kubus union : %i\n", sizeof(union union_cube));

    printf("\n<-------------------------------------------------------->\n");
    printf("|   Apakah Anda ingin mengulang kembali program? (y/n)   |\n");
    printf("<-------------------------------------------------------->\n"); 
    printf("> ");
    if (again())
    {
        clear();
        main();
        return 0;
    }

    return 0;
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