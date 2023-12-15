#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Fungsi untuk mengurutkan data
void sortData(int *data, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                // Tukar data jika data ke-j lebih besar dari data ke-(j+1)
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk menghitung nilai median
float calculateMedian(int *data, int n)
{
    // Jika jumlah data ganjil, median adalah nilai di tengah
    if (n % 2 != 0)
    {
        return (float)data[n / 2];
    }
    // Jika jumlah data genap, median adalah rata-rata dua nilai di tengah
    else
    {
        return (float)(data[(n - 1) / 2] + data[n / 2]) / 2.0;
    }
}

// Fungsi untuk menghitung nilai modus
int calculateMode(int *data, int n)
{
    int mode = data[0]; // Inisialisasi mode dengan nilai pertama
    int count = 1;      // Inisialisasi hitungan dengan 1

    int currentMode = data[0];
    int currentCount = 1;

    for (int i = 1; i < n; i++)
    {
        if (data[i] == data[i - 1])
        {
            // Jika nilai sama dengan nilai sebelumnya, tambahkan hitungan
            currentCount++;
        }
        else
        {
            // Jika nilai berbeda, reset hitungan
            currentCount = 1;
            currentMode = data[i];
        }

        // Jika hitungan saat ini lebih besar dari hitungan mode sebelumnya, update nilai mode dan hitungan
        if (currentCount > count)
        {
            count = currentCount;
            mode = currentMode;
        }
    }

    return mode;
}

// Fungsi untuk menghitung nilai mean
float calculateMean(int *data, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    return (float)sum / n;
}

int isAllDigit(const char *str)
{
    // Memeriksa apakah semua karakter dalam string adalah digit
    // dan jika karakter pertama adalah '-' maka karakter selanjutnya harus digit
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(isdigit(str[i]) || (i == 0 && str[i] == '-')))
        {
            return 0; // Tidak semua karakter adalah digit
        }
    }
    return 1; // Semua karakter adalah digit
}

// Fungsi untuk membersihkan newline dari buffer
void clear()
{
    while (getchar() != '\n')
        ;
}

// Fungsi untuk mengulang program
int again()
{
    char s[10];
    int s2;
    printf("\n\n+=============================================+");
    printf("\n|       APAKAH INGIN MENGULANG PROGRAM?       |");
    printf("\n|     y(Ya)                       t(Tidak)    |");
    printf("\n+=============================================+\n");
    printf("Pilihan anda: ");
    scanf("%s", s);
    if (strlen(s) == 1)
    {
        if (s[0] == 'y' || s[0] == 'Y')
        {
            return 1;
        }
        else if (s[0] == 't' || s[0] == 'T')
        {
            return 0;
        }
    }
    clear();
    printf("Pilihan tidak valid, mohon masukkan kembali pilihan : ");
    s2 = again();
    return s2;
}

int main()
{
    int n;
    char repeat;

    do
    {
        system("cls");
        printf("\n+===========================================+");
        printf("\n|                                           |");
        printf("\n|            PROGRAM STATISTIKA             |");
        printf("\n|      MENGHITUNG MEDIAN, MODUS, MEAN       |");
        printf("\n|                                           |");
        printf("\n+===========================================+\n");

        // Validasi input untuk jumlah data
        while (1)
        {
            char input[10]; // Anggap panjang maksimal input adalah 10 karakter
            printf("\nMasukkan jumlah data (minimal 1): ");
            scanf("%s", input);

            if (isAllDigit(input))
            {
                n = atoi(input);
                if (n >= 1)
                {
                    break;
                }
                else
                {
                    printf("Input tidak valid. Harap masukkan angka yang lebih besar atau sama dengan 1.\n");
                }
            }
            else
            {
                printf("Input tidak valid. Harap masukkan angka yang lebih besar atau sama dengan 1.\n");
            }
        }

        int *data = (int *)malloc(n * sizeof(int));

        if (data == NULL)
        {
            printf("Alokasi memori gagal. Program berhenti.\n");
            return 1;
        }

        // Validasi input untuk setiap data
        printf("Masukkan data:\n");
        for (int i = 0; i < n; i++)
        {
            char input[10]; // Anggap panjang maksimal input adalah 10 karakter
            while (1)
            {
                printf("Data ke-%d: ", i + 1);
                scanf("%s", input);

                if (isAllDigit(input))
                {
                    data[i] = atoi(input);
                    break;
                }
                else
                {
                    printf("Input tidak valid. Harap masukkan angka.\n");
                }
            }
        }

        // Mengurutkan data
        sortData(data, n);

        // Menampilkan jumlah data yang telah diurut
        printf("\n+===================================+");
        printf("\n\t%d Data Telah Terurut:\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");

        // Menghitung dan menampilkan nilai median, modus, dan mean
        printf("+===================================+\n");
        printf("|Hasil Statistik:                   |\n");
        printf("+===================================+\n");
        printf("|Median: %.2f                       |\n", calculateMedian(data, n));
        printf("+===================================+\n");
        printf("|Modus: %d                           |\n", calculateMode(data, n));
        printf("+===================================+\n");
        printf("|Mean: %.2f                         |\n", calculateMean(data, n));
        printf("+===================================+");

        free(data); // Membebaskan memori yang dialokasikan untuk data

        repeat = again();

    } while (repeat);

    // Pesan terima kasih dan keluar dari program
    system("cls");
    printf("\n+==============================================+");
    printf("\n|                TERIMA KASIH                  |");
    printf("\n|        TELAH MENGGUNAKAN PROGRAM INI         |");
    printf("\n|==============================================|");
    printf("\n|     SAMPAI JUMPA LAGI DI LAIN KESEMPATAN     |");
    printf("\n+==============================================+\n");

    return 0;
}