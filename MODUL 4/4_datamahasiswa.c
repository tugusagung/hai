#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NIM_LENGTH 20
#define MAX_NAMA_LENGTH 50

// Struktur data untuk merepresentasikan mahasiswa
struct Mahasiswa
{
    char NIM[MAX_NIM_LENGTH];
    char Nama[MAX_NAMA_LENGTH];
};

// Fungsi untuk membersihkan newline dari buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Fungsi untuk menambahkan data mahasiswa ke dalam file
void tambahDataMahasiswa(FILE *file, struct Mahasiswa *mahasiswa)
{
    fprintf(file, "%s %s\n", mahasiswa->NIM, mahasiswa->Nama);
    fflush(file); // Memastikan data segera disimpan ke file
}

// Fungsi untuk memeriksa apakah data dengan NIM tertentu sudah ada di file
int cekDuplikatNIM(FILE *file, const char *NIM)
{
    struct Mahasiswa mahasiswa;
    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s", mahasiswa.NIM, mahasiswa.Nama) != EOF)
    {
        if (strcmp(mahasiswa.NIM, NIM) == 0)
        {
            printf("Data dengan NIM %s sudah ada atas nama %s.\n", NIM, mahasiswa.Nama);
            return 1;
        }
    }

    return 0;
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
int cariDataMahasiswa(FILE *file, const char *NIM)
{
    struct Mahasiswa mahasiswa;
    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%19s", mahasiswa.NIM) == 1)
    {
        fgets(mahasiswa.Nama, MAX_NAMA_LENGTH, file);
        // Menghapus karakter newline yang ditangkap oleh fgets
        mahasiswa.Nama[strcspn(mahasiswa.Nama, "\n")] = '\0';

        if (strcmp(mahasiswa.NIM, NIM) == 0)
        {
            system("cls");
            printf("Data Mahasiswa ditemukan:\n");
            printf("NIM: %s\n", mahasiswa.NIM);
            printf("Nama: %s\n", mahasiswa.Nama);
            return 1;
        }
    }

    printf("Data Mahasiswa tidak ditemukan.\n");
    return 0;
}

// Fungsi untuk memperbarui data mahasiswa berdasarkan NIM
void updateDataMahasiswa(FILE *file, const char *NIM)
{
    fseek(file, 0, SEEK_SET);

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile)
    {
        perror("Gagal membuka file sementara");
        return;
    }

    struct Mahasiswa mahasiswa;
    bool found = false;

    while (fscanf(file, "%19s %[^\n]", mahasiswa.NIM, mahasiswa.Nama) == 2)
    {
        if (strcmp(mahasiswa.NIM, NIM) == 0)
        {
            found = true;

            system("cls");
            printf("Data Mahasiswa ditemukan:\n");
            printf("NIM: %s\n", mahasiswa.NIM);
            printf("Nama sebelumnya: %s\n", mahasiswa.Nama);

            clearInputBuffer();

            int isValidName;
            do
            {
                isValidName = 1;
                printf("Masukkan Nama baru mahasiswa dengan NIM %s: ", NIM);
                fgets(mahasiswa.Nama, MAX_NAMA_LENGTH, stdin);
                mahasiswa.Nama[strcspn(mahasiswa.Nama, "\n")] = '\0';

                for (int i = 0; mahasiswa.Nama[i] != '\0'; i++)
                {
                    if (!isalpha(mahasiswa.Nama[i]) && mahasiswa.Nama[i] != ' ')
                    {
                        isValidName = 0;
                        break;
                    }
                }

                if (!isValidName)
                {
                    printf("Nama mahasiswa hanya boleh terdiri dari huruf. ");
                }
            } while (!isValidName);

            fprintf(tempFile, "%s %s\n", mahasiswa.NIM, mahasiswa.Nama);
            printf("Data Mahasiswa berhasil diperbarui.\n");
        }
        else
        {
            fprintf(tempFile, "%s %s\n", mahasiswa.NIM, mahasiswa.Nama);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        if (remove("data_mahasiswa.txt") != 0)
        {
            perror("Gagal menghapus file asli");
            return;
        }

        if (rename("temp.txt", "data_mahasiswa.txt") != 0)
        {
            perror("Gagal mengganti nama file sementara");
            return;
        }
    }
    else
    {
        remove("temp.txt");
        printf("Data Mahasiswa dengan NIM %s tidak ditemukan.\n", NIM);
    }
}

// Fungsi untuk mengulang program
int again()
{
    char s[10];
    printf("\n\n+=============================================+");
    printf("\n|       APAKAH INGIN MENGULANG PROGRAM?       |");
    printf("\n|     y(Ya)                       t(Tidak)    |");
    printf("\n+=============================================+\n");
    printf("Pilihan anda: ");
    scanf("%s", s);
    clearInputBuffer();

    if (strlen(s) == 1)
    {
        return (s[0] == 'y' || s[0] == 'Y');
    }

    printf("Pilihan tidak valid, mohon masukkan kembali pilihan.\n");
    return again(); // Rekursi jika pilihan tidak valid
}

int getInputOption()
{
    int pilihan;
    int inputStatus;

    do
    {
        printf("Pilihan: ");
        inputStatus = scanf("%d", &pilihan);

        if (inputStatus != 1 || pilihan < 1 || pilihan > 3)
        {
            printf("Pilihan tidak valid. Harap masukkan angka antara 1 sampai 3.\n");

            while (getchar() != '\n')
                ;
        }

        // Memeriksa apakah setiap karakter adalah angka
        for (int c; (c = getchar()) != '\n' && c != EOF;)
        {
            if (!isdigit(c))
            {
                printf("Pilihan tidak valid. Harap masukkan angka antara 1 dan 3.\n");

                // Membersihkan newline dari buffer masukan
                while (getchar() != '\n')
                    ;

                inputStatus = 0; // Set inputStatus agar loop terus berlanjut
                break;
            }
        }

    } while (inputStatus != 1);

    return pilihan;
}

// Fungsi untuk memeriksa apakah string hanya terdiri dari angka
bool isAllDigit(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    do
    {
        FILE *file = fopen("data_mahasiswa.txt", "a+");

        if (!file)
        {
            perror("Gagal membuka file");
            return 1;
        }

        int pilihan;
        printf("+==============================+\n");
        printf("|        Data Mahasiswa        |\n");
        printf("+==============================+\n");
        printf("|Pilih opsi:                   |\n");
        printf("|1. Tambah Data Mahasiswa      |\n");
        printf("|2. Cari Data Mahasiswa        |\n");
        printf("|3. Update Data Mahasiswa      |\n");
        printf("+==============================+\n");

        pilihan = getInputOption();

        struct Mahasiswa mahasiswa;

        if (pilihan == 1)
        {
            printf("+=========================+\n");
            printf("|  Tambah Data Mahasiswa  |\n");
            printf("+=========================+\n");

            // Memasukkan NIM
            while (1)
            {
                printf("Masukkan NIM mahasiswa: ");
                scanf("%19s", mahasiswa.NIM); // Menggunakan %19s untuk membatasi jumlah karakter yang dibaca

                if (isAllDigit(mahasiswa.NIM))
                {
                    // Data NIM hanya diterima jika semua karakter adalah angka
                    break;
                }
                else
                {
                    printf("Input tidak valid. NIM hanya boleh berupa angka.\n");
                    clearInputBuffer(); // Membersihkan buffer agar tidak terjadi loop tak terbatas
                }
            }

            clearInputBuffer(); // Membersihkan buffer setelah scanf

            if (!cekDuplikatNIM(file, mahasiswa.NIM))
            {
                // Memasukkan Nama
                printf("Masukkan Nama mahasiswa: ");
                fgets(mahasiswa.Nama, MAX_NAMA_LENGTH, stdin);

                // Menghapus karakter newline yang ditangkap oleh fgets
                mahasiswa.Nama[strcspn(mahasiswa.Nama, "\n")] = '\0';

                int isValidName = 1;
                int hasDigit = 0;

                // Memeriksa validitas Nama
                for (int i = 0; mahasiswa.Nama[i] != '\0'; i++)
                {
                    if (!isalpha(mahasiswa.Nama[i]) && mahasiswa.Nama[i] != ' ')
                    {
                        isValidName = 0;
                        break;
                    }

                    if (isdigit(mahasiswa.Nama[i]))
                    {
                        hasDigit = 1;
                        break;
                    }
                }

                // Validasi Nama
                if (isValidName && !hasDigit)
                {
                    tambahDataMahasiswa(file, &mahasiswa);
                    printf("Data berhasil disimpan.\n");
                }
                else
                {
                    do
                    {
                        if (hasDigit)
                        {
                            printf("Nama mahasiswa tidak boleh mengandung angka. ");
                        }
                        else
                        {
                            printf("Nama mahasiswa hanya boleh terdiri dari huruf. ");
                        }

                        printf("Harap masukkan nama kembali: ");
                        fgets(mahasiswa.Nama, MAX_NAMA_LENGTH, stdin);

                        // Menghapus karakter newline yang ditangkap oleh fgets
                        mahasiswa.Nama[strcspn(mahasiswa.Nama, "\n")] = '\0';

                        // Memeriksa kembali apakah nama baru valid
                        isValidName = 1;
                        hasDigit = 0;

                        for (int i = 0; mahasiswa.Nama[i] != '\0'; i++)
                        {
                            if (!isalpha(mahasiswa.Nama[i]) && mahasiswa.Nama[i] != ' ')
                            {
                                isValidName = 0;
                                break;
                            }

                            if (isdigit(mahasiswa.Nama[i]))
                            {
                                hasDigit = 1;
                                break;
                            }
                        }
                    } while (!isValidName || hasDigit);

                    tambahDataMahasiswa(file, &mahasiswa);
                    printf("Data berhasil disimpan.\n");
                }
            }
        }

        else if (pilihan == 2)
        {
            printf("+=======================+\n");
            printf("|  Cari Data Mahasiswa  |\n");
            printf("+=======================+\n");

            // Memasukkan NIM untuk mencari data mahasiswa
            char searchNIM[MAX_NIM_LENGTH];
            while (1)
            {
                printf("Masukkan NIM untuk mencari data mahasiswa: ");
                scanf("%s", searchNIM);

                if (isAllDigit(searchNIM))
                {
                    // Data NIM hanya diterima jika semua karakter adalah angka
                    break;
                }
                else
                {
                    printf("Input tidak valid. NIM hanya boleh berupa angka.\n");
                    clearInputBuffer(); // Membersihkan buffer agar tidak terjadi loop tak terbatas
                }
            }

            // Cari dan cetak data mahasiswa
            cariDataMahasiswa(file, searchNIM);
        }

        else if (pilihan == 3)
        {
            printf("+=========================+\n");
            printf("|  Update Data Mahasiswa  |\n");
            printf("+=========================+\n");

            // Memasukkan NIM untuk mencari data mahasiswa yang akan diperbarui
            char updateNIM[MAX_NIM_LENGTH];
            while (1)
            {
                printf("Masukkan NIM untuk memperbarui data mahasiswa: ");
                scanf("%s", updateNIM);

                if (isAllDigit(updateNIM))
                {
                    // Data NIM hanya diterima jika semua karakter adalah angka
                    break;
                }
                else
                {
                    printf("Input tidak valid. NIM hanya boleh berupa angka.\n");
                    clearInputBuffer(); // Membersihkan buffer agar tidak terjadi loop tak terbatas
                }
            }

            // Memanggil fungsi untuk memperbarui data mahasiswa
            updateDataMahasiswa(file, updateNIM);
        }
        else
        {
            printf("Pilihan tidak valid.\n");
        }

        fclose(file);
    } while (again());

    printf("\n+==============================================+");
    printf("\n|                TERIMA KASIH                  |");
    printf("\n|        TELAH MENGGUNAKAN PROGRAM INI         |");
    printf("\n|==============================================|");
    printf("\n|     SAMPAI JUMPA LAGI DI LAIN KESEMPATAN     |");
    printf("\n+==============================================+\n");

    return 0;
}