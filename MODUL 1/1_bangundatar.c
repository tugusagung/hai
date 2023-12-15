#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct variabel {
        double n1;
        double n2;
        double n3;
        double n4;
        double res;
} variabel;
void checkPositif ()
{
        printf("\n----------------------------------------");
        printf("\n| [!] Input yang diberikan tidak valid! |");  
        printf("\n----------------------------------------\n");
        exit(0);
}

void triangleCircumference (double a, double b, double c, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang sisi pertama: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }
    printf("\nInput panjang sisi kedua: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    printf("\nInput panjang sisi ketiga: ");
    if (scanf ("%lf", &c) == 0 || c < 0 ){
      checkPositif();
    }

    if (a+b < c || a+c < b || b+c < a){
        printf("\n----------------------------------------");
        printf("\n|  [!] Segitiga tersebut tidak valid!  |");  
        printf("\n----------------------------------------\n");
        exit(0);
    }

    res = a+b+c;
    printf ("\nNilai dari keliling segitiga adalah: %g\n", res);
}

void triangleArea (double a, double b, double c, double s, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang sisi pertama: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    printf("\nInput panjang sisi kedua: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    printf("\nInput panjang sisi ketiga: ");
    if (scanf ("%lf", &c) == 0 || c < 0 ){
      checkPositif();
    }

    if (a+b < c || a+c < b || b+c < a){
        printf("\n----------------------------------------");
        printf("\n|  [!] Segitiga tersebut tidak valid!  |");  
        printf("\n----------------------------------------\n");
        exit(0);
    }

    s = (a+b+c)/2;
    res = sqrt(s*(s-a)*(s-b)*(s-c));
            
    printf("\nNilai dari luas segitiga tersebut adalah: %g", res); 
}

void diamondCircumference (double a, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang sisi belah ketupat: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    res = 4*a;

    printf("\nNilai dari keliling belah ketupat tersebut adalah: %g", res); 
}

void diamondArea (double a, double b, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang diagonal pertama belah ketupat: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    printf("\nInput panjang diagonal kedua belah ketupat: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    res = (a*b)/2;
    printf("\nNilai dari luas belah ketupat tersebut adalah: %g", res);    
}

void parallellogramCircumference (double a, double b, double c, double d, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang sisi pertama: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    printf("\nInput panjang sisi kedua: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    printf("\nInput panjang sisi ketiga: ");
    if (scanf ("%lf", &c) == 0 || c < 0 ){
      checkPositif();
    }

    printf("\nInput panjang sisi keempat: ");
    if (scanf ("%lf", &d) == 0 || d < 0 ){
      checkPositif();
    }
    res = a+b+c+d;
    printf("\nNilai dari keliling segi empat tersebut adalah: %g", res); 
}

void parallellogramArea (double a, double b, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang alas: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    printf("\nInput nilai tinggi: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    res=a*b;
    printf("\nNilai dari luas jajar genjang tersebut adalah: %g", res); 
}

void trapezoidArea (double a, double b, double c, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang sisi alas: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    printf("\nInput panjang sisi atas: ");
    if (scanf ("%lf", &b) == 0 || b < 0){
      checkPositif();
    }

    printf("\nInput nilai tinggi: ");
    if (scanf ("%lf", &c) == 0 || c < 0 ){
      checkPositif();
    }
    res = (a+b)/2*c;
    printf("\nNilai dari luas trapesium tersebut adalah: %g", res); 
}

void circleCircumference (double a, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang jari-jari: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }
    res=2*3.14*a;
    printf("\nNilai dari keliling lingkaran tersebut adalah: %g", res); 
}

void circleArea (double a, double res)
{
    printf("\n[!] Input Nilai [!]\n");

    printf("\nInput panjang jari-jari: ");
    if (scanf ("%lf", &a) == 0 || a < 0){
        checkPositif();
    }

    res=3.14*a*a;
    printf("\nNilai dari keliling lingkaran tersebut adalah: %g", res);   
}

int main(){

    char bangun, input, nextchar;

    //Opening Interface
    printf("<-------------------------------------------------------->\n");
    printf("|         Selamat Datang di Program Perhitungan          |\n");
    printf("|               Luas dan Keliling Bangun                 |\n");
    printf("<-------------------------------------------------------->\n");

    printf("\n[!] Silahkan pilih operasi yang diinginkan!\n");
    printf("[1] Segitiga\n");
    printf("[2] Belah Ketupat\n");
    printf("[3] Jajar Genjang\n");
    printf("[4] Trapesium\n");
    printf("[5] Lingkaran\n");

    printf("\n[!] Pilihan Operasi: ");
    bangun = getchar();
    nextchar= getchar();

    if (nextchar!='\n'){
        checkPositif();
    }

    
    if (bangun == '0' || bangun ==  '1' || bangun == '2' || bangun == '3' ||bangun == '4' || bangun == '5'){

        printf("\n[!] Silahkan pilih operasi yang diinginkan!\n");
        printf("[1] Keliling\n");
        printf("[2] Luas\n");

        printf("\n[!] Pilihan Operasi: ");
        input = getchar();
        while (getchar() != '\n');

        switch (bangun)
        {
        // Segitiga
        case '1':
        switch (input)
        {
            variabel sembarang; 
            case '1':
            triangleCircumference (sembarang.n1, sembarang.n2, sembarang.n3, sembarang.res);
            break;

            case '2':
            triangleArea (sembarang.n1, sembarang.n2, sembarang.n3, sembarang.n4, sembarang.res);
            break;

            default:
            printf("\n----------------------------------------");
            printf("\n| [!] Input yang diberikan tidak valid! |");  
            printf("\n----------------------------------------\n");
            break;
        }
        break;

        // Belah Ketupat
        case '2':
        switch (input)
        {
            variabel belahKetupat;

            case '1':
            diamondCircumference (belahKetupat.n1, belahKetupat.res);
            break;

            case '2':
            diamondArea (belahKetupat.n1, belahKetupat.n2, belahKetupat.res);
            break;

            default:
            printf("\n----------------------------------------");
            printf("\n| [!] Input yang diberikan tidak valid! |");  
            printf("\n----------------------------------------\n");
            break;
        }
        break;
          // Jajar Genjang
          case '3':
        switch(input)
        {
            variabel jajarGenjang;
            case '1':
            parallellogramCircumference (jajarGenjang.n1, jajarGenjang.n2,jajarGenjang.n3,jajarGenjang.n4,jajarGenjang.res);
            break;

            case '2':
            parallellogramArea (jajarGenjang.n1, jajarGenjang.n2, jajarGenjang.res);
            break;

            default:
            printf("\n----------------------------------------");
            printf("\n| [!] Input yang diberikan tidak valid! |");  
            printf("\n----------------------------------------\n");
            break;
        }
        break;
           // Trapesium
           case '4':
        switch (input)
        {
            variabel trapesium;
            case '1':
            parallellogramCircumference (trapesium.n1, trapesium.n2, trapesium.n3, trapesium.n4, trapesium.res);
            break;

            case '2':
            trapezoidArea (trapesium.n1, trapesium.n2, trapesium.n3, trapesium.res);
            break;

            default:
             printf("\n----------------------------------------");
            printf("\n| [!] Input yang diberikan tidak valid! |");  
             printf("\n----------------------------------------\n");
            break;
        }
        break;
        // Lingkaran
        case '5':
        switch (input)
        {
            variabel lingkaran;
            case '1':
            circleCircumference (lingkaran.n1, lingkaran.res);
            break;

            case '2':
            circleArea(lingkaran.n1, lingkaran.res);
            break;

            default:
            printf("\n----------------------------------------");
            printf("\n| [!] Input yang diberikan tidak valid! |");  
            printf("\n----------------------------------------\n");
            break;
        }
        break;
        // Error Input
    default:
        printf("\n----------------------------------------");
        printf("\n| [!] Input yang diberikan tidak valid! |");  
        printf("\n----------------------------------------\n");
    break;
        } 
    }

    else 
    {
        printf("\n----------------------------------------");
        printf("\n| [!] Input yang diberikan tidak valid! |");  
        printf("\n----------------------------------------\n");
        exit(1);
    }

   system ("pause");
   return 0;
}