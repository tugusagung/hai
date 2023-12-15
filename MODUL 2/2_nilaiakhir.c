#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int a;
double n1, n2, n3, q, uts, uas, res;
int main();

//error message
int invalid() 
{
    printf("\n----------------------------------------");
    printf("\n| [!] Input yang diberikan tidak valid! |");  
    printf("\n----------------------------------------\n");
    exit(1);
}

//fungsi input nilai
double input(double x)
{
    int i; char input[50];
    fgets(input,50,stdin);


    for (i=0; i<5; i++){
        if(input[i] == '\n' || input[i] == '+' || input[i] == '-'){
            invalid();
        }
    }
    
    if (input[0] == '1' && input[1] == '0' && input [2] == '0' && input[3] == ',' && input[4] == '0' && input[5] == '0' && input[6] == '\n'){
        x = strtod(input, NULL);
        return x;
    }
    else if (isdigit(input[0]) == 0 || isdigit(input[1]) == 0  || input[2] != ',' || isdigit(input[3]) == 0 || isdigit(input[4]) == 0 || input[5] != '\n')
    {
        invalid();
    }
    else 
    {
    x = strtod(input, NULL);
    return x;
    }
}


//fungsi input absensi
int absensi ()
{
    printf ("Input jumlah absensi: ");
    char input[10]; int a;
    fgets(input,10,stdin);

    printf ("\n");

    int i;
    for (i=0; i<= 10; i++){
        if (input[i] == '+' || input[i] == '-'){

            invalid();
        }
    }
    
    if (isdigit(input[0])== 1 && input[1] == '\n'){
        a = atoi(input);
    }
    else if (isdigit(input[0]) == 0 || isdigit(input[1]) == 0 || input[2] != '\n'){
        invalid();
    }
    else if (isdigit(input[0]) == 0 && input[1] != '\n'){
        invalid();
    }

    a = atoi(input);
    
    if (a>0 && a<=15){
        return a;
    }
    else {
        invalid();
    }
}


//fungsi utama nilai
double nilai()
{
    printf("<-------------------------------------------------------->\n");
    printf("|       Berikan Input Nilai hingga 2 Angka Desimal        |\n");
    printf("|                  |  Contoh: 25,00   |                   |\n");
    printf("<-------------------------------------------------------->\n"); 

    
    printf ("Input nilai tugas pertama: ");
    n1 = input(n1);
   
    if ( n1 < 0 || n1 > 100)
    {
        invalid();
    }
    else
    {
        
        printf ("Input nilai tugas kedua: ");
        n2 = input (n2);
        if (n2 < 0 || n2 > 100)
        {
            invalid();
        }
        else
        {
            
            printf ("Input nilai tugas ketiga: ");
            n3 = input (n3);
            if ( n3 < 0 || n3 > 100)
            {
            invalid();
            }
            else
            {
                
                printf ("Input nilai quiz: ");
                q = input(q);
                if (q < 0 || q > 100)
                {
                    invalid();
                }
                else
                {
                    
                    printf ("Input nilai UTS: ");
                    uts = input(uts);
                    if (uts < 0 || uts > 100)
                    {
                        invalid();
                    }
                    else
                    {
                        
                        printf ("Input nilai UAS: ");
                        uas = input(uas);
                        if (uas < 0 || uas > 100)
                        {
                            invalid();
                        }
                        else
                        {
                            return uas, n1, n2, n3, q, uts;
                        }
                    }
                }
            }
        }
    }  
}


//fungsi utama
int main ()
{
    system("cls");
    printf("<-------------------------------------------------------->\n");
    printf("|         Selamat Datang di Program Perhitungan          |\n");
    printf("|                Nilai Akhir Mata Kuliah                 |\n");
    printf("<-------------------------------------------------------->\n"); 

    a = absensi();
    uas, n1, n2, n3, q, uts = nilai();

    res = (a * 6.66666 * 5/100) + ((n1+n2+n3)/3 * 20/100) + (q * 15/100) + (uts *30/100) + (uas * 30/100);

    printf("----------------------------------------------------------\n");

    if (res >= 0 && res <45){
        printf ("Nilai akhir yang diperoleh adalah E\n");
    }
    else if (res >= 45 && res < 50){
        printf ("Nilai akhir yang diperoleh adalah D\n");
    }
    else if (res >= 50 && res < 55){
        printf ("Nilai akhir yang diperoleh adalah D+\n");
    }
    else if (res >= 55 && res < 60){
        printf ("Nilai akhir yang diperoleh adalah C\n");
    }
    else if (res >= 60 && res < 65){
        printf ("Nilai akhir yang diperoleh adalah C+\n");
    }
    else if (res >= 65 && res < 75){
        printf ("Nilai akhir yang diperoleh adalah B\n");
    }
    else if (res >= 75 && res < 80){
        printf ("Nilai akhir yang diperoleh adalah B+\n");
    }
    else if (res >= 80 && res <= 100){
        printf ("Nilai akhir yang diperoleh adalah A\n");
    }
    else
    {
        invalid();
    }
    system ("pause");
    return 0;
}