#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isInteger(char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    return 1;
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
    clear(); // Membersihkan newline dari buffer

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

    printf("Pilihan tidak valid, mohon masukkan kembali pilihan : ");
    s2 = again();
    return s2;
}

int main()
{
    char continueInput; // Variable for 'y' or 'n' input

    do
    {
        system("cls");
        printf("+=====================================================================+\n");
        printf("|                                                                     |\n");
        printf("|                  PROGRAM PENGHITUNG ANGSURAN                        |\n");
        printf("|   (BERDASARKAN POKOK PINJAMAN, BESAR BUNGA, DAN LAMA PINJAMAN)      |\n");
        printf("|                                                                     |\n");
        printf("+=====================================================================+\n");

        double principalLoan, interestRate, interest, monthlyPrincipalPayment, monthlyPayment;
        int loanDurationMonths;
        char input[20];

        // Input Principal Loan
        do
        {
            printf("Silahkan Masukan Pokok Pinjaman Anda (Dalam Bilangan Bulat): ");
            fgets(input, sizeof(input), stdin);

            // Remove newline if present
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n')
            {
                input[len - 1] = '\0';
            }

            if (isInteger(input) && strlen(input) > 0)
            {
                principalLoan = atof(input);
                printf("Pokok Pinjaman Anda: %.0lf\n\n", principalLoan);
                break;
            }
            else
            {
                printf("Masukan tidak valid atau kosong. Harap masukkan bilangan bulat (Tanpa titik atau koma).\n");
            }
        } while (1);

        // Input Interest Rate
        do
        {
            printf("Masukkan Besar Bunga (dalam persen (%%)): ");
            fgets(input, sizeof(input), stdin);

            // Remove newline if present
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n')
            {
                input[len - 1] = '\0';
            }

            int isValid = 1;
            for (size_t i = 0; i < len - 1; i++)
            {
                if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
                {
                    isValid = 0;
                    break;
                }
            }

            if (isValid && sscanf(input, "%lf", &interestRate) == 1)
            {
                // Conversion successful
                printf("Besar bunga yang dimasukkan: %.2lf%%\n\n", interestRate);
                break;
            }
            else
            {
                printf("Masukan tidak valid atau kosong. Harap masukkan bilangan desimal.\n");
            }
        } while (1);

        // Input Loan Duration
        do
        {
            printf("Masukkan Lama Pinjaman (Dalam Bulan dan Bilangan Bulat): ");
            fgets(input, sizeof(input), stdin);

            // Remove newline if present
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n')
            {
                input[len - 1] = '\0';
            }

            if (isInteger(input) && strlen(input) > 0)
            {
                loanDurationMonths = atoi(input);
                printf("Lama Pinjaman yang dimasukkan: %d bulan\n\n", loanDurationMonths);
                break;
            }
            else
            {
                printf("Masukan tidak valid atau kosong. Harap masukkan bilangan bulat.\n");
            }
        } while (1);

        // Calculate monthly interest rate in decimal
        double monthlyInterestRate = (interestRate / 12) / 100;

        // Calculate monthly principal payment
        monthlyPrincipalPayment = principalLoan / loanDurationMonths;

        // Initialize total interest and total payment
        double totalInterest = 0;
        double totalPayment = 0;

        // Create a detailed payment schedule table
        printf("+==============================+\n");
        printf("|Tabel Angsuran Anda:          |\n");
        printf("+==============================+\n");
        printf("Bulan\t\tBunga\t\tAngsuran Pokok\t\tAngsuran Perbulan\n");

        for (int month = 1; month <= loanDurationMonths; month++)
        {
            interest = (principalLoan - (month - 1) * monthlyPrincipalPayment) * monthlyInterestRate;
            monthlyPayment = monthlyPrincipalPayment + interest;
            totalInterest += interest;
            totalPayment += monthlyPayment;

            printf("%d\t\tRp. %.0lf\t\tRp. %.0lf\t\tRp. %.0lf\n", month, interest, monthlyPrincipalPayment, monthlyPayment);
        }

        // Output total interest and total payment
        printf("+==============================+\n");
        printf("Total Bunga = Rp. %.0lf           \n", totalInterest);
        printf("Total Angsuran = Rp. %.0lf        \n", totalPayment);
        printf("+==============================+\n\n");

    } while (again());

    printf("\n+==============================================+");
    printf("\n|                TERIMA KASIH                  |");
    printf("\n|        TELAH MENGGUNAKAN PROGRAM INI         |");
    printf("\n|==============================================|");
    printf("\n|     SAMPAI JUMPA LAGI DI LAIN KESEMPATAN     |");
    printf("\n+==============================================+\n");

    return 0;
}
