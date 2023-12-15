#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int is_number(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '.') {
            return false;
        }
    }
    return true;
}

int is_positive(char *input) {
    double value = atof(input);
    if (value > 0.0) {
        return true;
    }
    return false;
}

int is_empty(char *input) {
    input[strcspn(input, "\n")] = '\0';
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            return false;
        }
    }
    return true;
}

#define PI 3.14

int is_number(char *input);
int is_positive(char *input);
int is_empty(char *input);

int main() {
    double jariJariTabung, tinggiTabung, volumeTabung, LuasPermukaanTabung;
    double jariJariBola, LuasPermukaanBola, volumeBola;
    double sisiAlasLimas, tinggiLimas, luasPermukaanLimas, volumeLimas;
    double sisiPertama, sisiKedua, tinggiSegitiga, luasAlas, kelilingAlas , tinggiPrisma, luasPermukaanPrisma, volumePrisma;
    double garisPelukis, jariJariKerucut, tinggiKerucut, luasPermukaanKerucut, volumeKerucut;

    char input[20];
    int valid;
    int pilihan;
    char jawaban;

        printf("+===============================================+\n");
        printf("| Program Menghitung Luas Permukaan dan Volume  |\n");
    do {
        printf("+===============================================+\n");
        printf("|         Silakan pilih bangun ruang            |\n");
        printf("+===============================================+\n");
        printf("| 1. Tabung                                     |\n");                            
        printf("| 2. Bola                                       |\n");
        printf("| 3. Limas Segiempat                            |\n");
        printf("| 4. Prisma segitiga                            |\n");
        printf("| 5. Kerucut                                    |\n");
        printf("+===============================================+\n");

       do {
            printf("Masukkan pilihan Anda: ");
            if (fgets(input, sizeof(input), stdin) == NULL) {
            }
            if (is_empty(input)) {
                printf("Input tidak boleh kosong!\n");
                valid = false;
            } else {
            if (is_number(input)) {
                if (sscanf(input, "%d", &pilihan) == 1) {
                    if (pilihan >= 1 && pilihan <= 5) {
                        valid = true;
                    } else {
                        printf("Pilihan tidak valid!\n");
                        valid = false;
                    }
                } else {
                    printf("Error converting input!\n");
                    valid = false;
                }
            } else {
                printf("Input harus angka!\n");
                valid = false;
            }
        }
    } while (!valid);
        switch (pilihan) {
            case 1: 
                do {
                    printf("+===============================================+\n");
                    printf("| Masukkan jari-jari tabung: "); 
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            jariJariTabung = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);
                do {
                    printf("| Masukkan tinggi tabung: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            tinggiTabung = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid); 

                LuasPermukaanTabung = 2 * PI * jariJariTabung * (jariJariTabung + tinggiTabung);
                volumeTabung = PI * jariJariTabung * jariJariTabung * tinggiTabung;

                printf("| Luas permukaan tabung = %.2f \n", LuasPermukaanTabung);
                printf("| Volume tabung = %.2f \n", volumeTabung);
                printf("+===============================================+\n");
                break;
            case 2: 
                do {
                    printf("+===============================================+\n");
                    printf("| Masukkan jari-jari bola: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            jariJariBola = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);

                LuasPermukaanBola = 4 * PI * jariJariBola * jariJariBola;
                volumeBola = (4.0 / 3.0) * PI * jariJariBola * jariJariBola * jariJariBola;

                printf("| Luas permukaan bola = %.2f\n", LuasPermukaanBola);
                printf("| Volume bola = %.2f\n", volumeBola);
                printf("+===============================================+\n");
                break;
            case 3: 
                do {
                    printf("+===============================================+\n");
                    printf("| Masukkan panjang sisi alas limas segiempat: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            sisiAlasLimas = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);
                do {
                    printf("| Masukkan tinggi limas segiempat: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            tinggiLimas = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid); 

                luasPermukaanLimas = sisiAlasLimas * sisiAlasLimas + 2 * sisiAlasLimas * sqrt((sisiAlasLimas / 2) * (sisiAlasLimas / 2) + tinggiLimas * tinggiLimas);
                volumeLimas = (1.0 / 3.0) * sisiAlasLimas * sisiAlasLimas * tinggiLimas;

                printf("| Luas permukaan limas segiempat = %.2f\n", luasPermukaanLimas);
                printf("| Volume limas segiempat = %.2f\n", volumeLimas);
                printf("+===============================================+\n");
                break;
            case 4:
                do {
                    printf("+===============================================+\n");
                    printf("| Masukkkan sisi pertama: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            sisiPertama = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);
                do {
                    printf("| Masukkan sisi kedua: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            sisiKedua = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);
                do {
                    printf("| Masukkan tinggi segitiga: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            tinggiSegitiga = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                }   while (!valid);
                do {
                    printf("| Masukkan tinggi prisma segitiga: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            tinggiPrisma = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                }   while (!valid);

                luasAlas = 0.5 * sisiPertama * tinggiSegitiga;
                kelilingAlas = sisiPertama + sisiKedua + tinggiSegitiga;

                luasPermukaanPrisma = (2 * luasAlas) + (kelilingAlas * tinggiPrisma);
                volumePrisma = 0.5 * sisiPertama * sisiKedua * tinggiPrisma;

                printf("| Luas permukaan prisma segitiga = %.2f\n", luasPermukaanPrisma);
                printf("| Volume prisma segitiga = %.2f\n", volumePrisma);
                printf("+===============================================+\n");
                break;
            case 5:
                do {
                    printf("+===============================================+\n");
                    printf("| Masukkan jari-jari kerucut: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {                       
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            jariJariKerucut = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);
                do {
                    printf("| Masukkan tinggi kerucut: ");
                    if (fgets(input, sizeof(input), stdin) == NULL) {                      
                    }
                    if (is_empty(input)) {
                        printf("| Input tidak boleh kosong!\n");
                        valid = false;
                    } else {
                        if (is_number(input) && is_positive(input)) {
                            tinggiKerucut = atof(input);
                            valid = true;
                        } else {
                            printf("| Input harus angka positif!\n");
                            valid = false;
                        }
                    }
                } while (!valid);

                garisPelukis = sqrt(jariJariKerucut * jariJariKerucut + tinggiKerucut * tinggiKerucut); // Menggunakan variabel yang telah diinisialisasi
                luasPermukaanKerucut = 3.14 * jariJariKerucut * (jariJariKerucut + garisPelukis);
                volumeKerucut = (1.0 / 3.0) * 3.14 * jariJariKerucut * jariJariKerucut * tinggiKerucut;

                printf("| Luas permukaan kerucut = %.2f\n", luasPermukaanKerucut);
                printf("| Volume kerucut = %.2f\n", volumeKerucut);
                printf("+===============================================+\n");
                break;
                default: 
                printf("Pilihan tidak valid!\n");
        }
        do {
            printf("| Apakah Anda ingin menghitung lagi? (y/n): ");
            if (fgets(input, sizeof(input), stdin) == NULL) {
            }
            if (is_empty(input)) {
                printf("| Input tidak boleh kosong!\n");
                valid = false;
            } else {
                jawaban = input[0];
                if (jawaban == 'y' || jawaban == 'Y' || jawaban == 'n' || jawaban == 'N') {
                    valid = true;
                } else {
                    printf("| jawaban tidak valid!\n");
                    valid = false;
                }
            }
        } while (!valid);
    } while (jawaban == 'y' || jawaban == 'Y');
    printf("+===============================================+\n");
    printf("|  Terimakasih Telah Menggunakkan Program ini   | \n");
    printf("+===============================================+\n");
   return 0;
}