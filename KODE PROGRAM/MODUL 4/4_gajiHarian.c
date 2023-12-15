#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct gajiHarian{

    double perjam;
    double lembur;
    double lemburJam;
    double totalJam;
    double total;

}gaji;

double b = 8.00;
char buff[10];

double input();
double restart(double y);
void details(gaji a);


int main(){
    gaji a;
    a.perjam = 10625;
    a.lemburJam = 0;
    a.lembur = 0;
    a.total = 0;
    double y;
    

    printf("<-------------------------------------------------------->\n");
    printf("|          Selamat Datang di Program Perhitungan         |\n");
    printf("|                       Gaji Harian                      |\n");
    printf("<-------------------------------------------------------->\n"); 
    
    printf("\nInput Jumlah Jam Kerja (Satuan Jam)!");
    printf("\n> ");

    a.totalJam = input();

    if (a.totalJam > 8){
        
        a.lemburJam = a.totalJam - b;
        a.lembur = a.lemburJam * ( b * a.perjam );
        a.total = (a.perjam * (a.totalJam - a.lemburJam)) + a.lembur;
        details(a);
    }
    else {
        a.total = a.perjam * (a.totalJam - a.lemburJam);
        details(a);
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

    return 0;
}

double restart(double y){
    
    printf("\n> ");
    y = input();

    if (y == 1){
        system("cls");
        main();
    }
    else if (y == 2){
        return 0;
    }
    else {
        printf("[!] Opsi ----- Invalid Input : Coba lagi");
        restart(y);
    }
}

void details(gaji a){

    printf("\n---------- Detail Gaji Harian ----------\n");
    
    printf("\nTotal Jam Kerja        : %.2lf\n", a.totalJam);
    printf("\nTotal Jam Lembur       : %.2lf\n", a.lemburJam);
    printf("\n");
    printf("\nTotal Gaji Dasar       : Jam Kerja Dasar (%.2lf) x Gaji Per Jam (%.2lf) = %.2lf\n", (a.totalJam-a.lemburJam), a.perjam, (a.total - a.lembur));
    printf("\nTotal Pemasukan Lembur : Jam Kerja Lembur (%.2lf) x Gaji Lembur (%.2lf) = %.2lf\n", a.lemburJam, ( b * a.perjam ), a.lembur );
    printf("\nTotal Gaji             : Gaji Dasar (%.2lf) + Gaji Lembur (%.2lf) = %.2lf\n", (a.total - a.lembur), a.lembur, a.total);
    printf("\n");
    printf("\n--------------------------------------");
    printf("\nTotal Gaji             : %.2lf", a.total);
    printf("\n--------------------------------------");
}

double input(){
    double x;
    bool valid;
    // for (int z=0; z<sizeof(buff); z++){
    //     buff[z] = '\0';
    // }

    fgets (buff, 10, stdin);
    // printf("Press Enter to Continue > ");       // HOW TO NOT HAVE clear() ASK FOR INPUT???? 
    // clear(stdin);                               // THIS WAS MY MAKESHIFT GO AROUND

    for (int i=0; i<sizeof(buff); i++){
        
        // [IGNORE] funny debug code

        // printf("\nChecking Iteration [i = %d]\n", i);
        // for (int j=0; j<10; j++){                            
        //     printf("input[%d] : %c\n", j, buff[j]);
        //     }

        if (buff[i] == '+' || buff[i] == '-' ){
            valid = 0;
            printf("\n[!] Buffer ----  Invalid Input! [input[%d], char: %c] Coba lagi!", i, buff[i]);
            break;
        }
        else if (isdigit(buff[i]) == 1 && buff[i+1] == '\n' || isdigit(buff[i]) == 1 && buff[i+1] == '\0'){
            valid = 1;
            break;
        }
        else if (isdigit(buff[i]) == 1 || isdigit(buff[i]) == 1 && buff[i+1] == '.' || buff[i] == '.' && isdigit(buff[i+1]) == 1 ){
            continue;
        }
        else{
            valid = 0;
            printf("\n[!] Buffer ----  Invalid Input! [input[%d], char: %c] Coba lagi!", i, buff[i]);
            break;
        }
    }

    if (valid == 0){
        printf("\n> ");
        input();
    }
    else if (valid == 1){
    x = strtod(buff, NULL);
    // printf ("\n x : %.2lf", x);
    return x;
    }
}