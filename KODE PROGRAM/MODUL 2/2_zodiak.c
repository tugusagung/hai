#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

bool again();
void clear(), header();

int date, counter, mon, tmp, start2;
char month[10], start[10];
char list[12][10] = {"januari", "februari", "maret", "april", "mei", "juni", "juli", "agustus", "september", "oktober", "november", "desember"};

int main()
{
    system("cls");
    header();
    printf("Masukan tanggal lahir : ");
    if (scanf("%i", &date) == 0)
    {
        clear();
        main();
        return 0;
    }
    if (getchar() != '\n')
    {
        clear();
        main();
        return 0;
    }
    if (date > 31 || date < 1)
    {
        main();
        return 0;
    }

    counter = 0;
    while (counter == 0)
    {
        system("cls");
        header();
        printf("Tanggal lahir : %i\n", date);
        printf("Masukan bulan lahir : ");
        scanf("%s", month);

        for (int i = 0; i < strlen(month); i++)
        {
            month[i] = tolower(month[i]);
        }
        mon = atoi(month);
        for (int i = 1; i <= 12; i++)
        {
            tmp = strcmp(month, list[i-1]);
            if (tmp == 0)
            {
                mon = i;
            }
        }

        list[mon-1][0] = toupper(list[mon-1][0]);
        system("cls");
        header();
        printf("Tanggal lahir : %i\n", date);
        printf("Bulan lahir : %s\n", list[mon-1]);
        list[mon-1][0] = tolower(list[mon-1][0]);

        switch (mon)
        {
        case 3:
            if (date >= 21 && date <= 31)
            {
                printf("Zodiak : Aries\n");
            }
            else
            {
                printf("Zodiak : Pisces\n");
            }
            counter++;
            break;
        case 4:
            if (date >= 20 && date <= 30)
            {
                printf("Zodiak : Taurus\n");
            }
            else if (date >= 1 && date <= 19)
            {
                printf("Zodiak : Aries\n");
            }
            else
            {
                printf("Invalid!");
            }
            counter++;
            break;
        case 5:
            if (date >= 21 && date <= 31)
            {
                printf("Zodiak : Gemini\n");
            }
            else
            {
                printf("Zodiak : Taurus\n");
            }
            counter++;
            break;
        case 6:
            if (date >= 21 && date <= 30)
            {
                printf("Zodiak : Cancer\n");
            }
            else if (date >= 1 && date <= 22)
            {
                printf("Zodiak : Gemini\n");
            }
            else
            {
                printf("Invalid!");
            }
            counter++;
            break;
        case 7:
            if (date >= 23 && date <= 31)
            {
                printf("Zodiak : Leo\n");
            }
            else
            {
                printf("Zodiak : Cancer\n");
            }
            counter++;
            break;
        case 8:
            if (date >= 23 && date <= 31)
            {
                printf("Zodiak : Virgo\n");
            }
            else
            {
                printf("Zodiak : Leo\n");
            }
            counter++;
            break;
        case 9:
            if (date >= 23 && date <= 30)
            {
                printf("Zodiak : Libra\n");
            }
            else if (date >= 1 && date <= 22)
            {
                printf("Zodiak : Virgo\n");
            }
            else
            {
                printf("Invalid!");
            }
            counter++;
            break;
        case 10:
            if (date >= 23 && date <= 31)
            {
                printf("Zodiak : Scorpio\n");
            }
            else
            {
                printf("Zodiak : Libra\n");
            }
            counter++;
            break;
        case 11:
            if (date >= 22 && date <= 30)
            {
                printf("Zodiak : Sagitarius\n");
            }
            else if (date >= 1 && date <= 21)
            {
                printf("Zodiak : Scorpio\n");
            }
            else
            {
                printf("Invalid!");
            }
            counter++;
            break;
        case 12:
            if (date >= 22 && date <= 31)
            {
                printf("Zodiak : Capricorn\n");
            }
            else
            {
                printf("Zodiak : Sagitarius\n");
            }
            counter++;
            break;
        case 1:
            if (date >= 20 && date <= 31)
            {
                printf("Zodiak : Aquarius\n");
            }
            else
            {
                printf("Zodiak : Capricorn\n");
            }
            counter++;
            break;
        case 2:
            if (date >= 19 && date <= 29)
            {
                printf("Zodiak : Pisces\n");
            }
            else if (date >= 1 && date <= 18)
            {
                printf("Zodiak : Aquarius\n");
            }
            else
            {
                printf("Invalid!");
            }
            counter++;
            break;
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

bool again()
{
    scanf("%s", start);
    if (strlen(start) == 1)
    {
        if (start[0] == 'y' || start[0] == 'Y')
        {
            return 1;
        }
        else if (start[0] == 'n' || start[0] == 'N')
        {
            return 0;
        }
    }
    clear();
    printf("Pilihan tidak valid, mohon masukkan kembali pilihan : ");
    start2 = again();
    return start2;
}

void clear()
{
    while (getchar() != '\n'){}
}

void header(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|           Zodiak           |\n");
    printf("|____________________________|\n\n");
}