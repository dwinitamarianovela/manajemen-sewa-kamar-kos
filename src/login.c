#include <stdio.h>
#include <string.h>
#include "login.h" // <-- Sesuaikan menjadi login.h

int prosesLogin()
{
    User daftarUser[MAX_USER] = {
        {"admin", "admin123"}};
    int jmlUser = 1;
    int pilihan;

    while (1)
    {
        printf("\n=== SELAMAT DATANG DI SISTEM KOS ===\n");
        printf("1. Login\n");
        printf("2. Daftar Akun Baru\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 0)
        {
            return 0;
        }
        else if (pilihan == 2)
        {
            if (jmlUser >= MAX_USER)
            {
                printf("Kapasitas akun penuh!\n");
                continue;
            }
            printf("\n--- Daftar Akun Baru ---\n");
            printf("Buat Username : ");
            scanf("%s", daftarUser[jmlUser].username);
            printf("Buat Password : ");
            scanf("%s", daftarUser[jmlUser].password);
            jmlUser++;
            printf("Akun berhasil didaftarkan! Silakan login.\n");
        }
        else if (pilihan == 1)
        {
            char inputUser[30], inputPass[30];
            int percobaan = 0;

            while (percobaan < 3)
            {
                printf("\n--- Login Pengelola Kos ---\n");
                printf("Username : ");
                scanf("%s", inputUser);
                printf("Password : ");
                scanf("%s", inputPass);

                for (int i = 0; i < jmlUser; i++)
                {
                    if (strcmp(inputUser, daftarUser[i].username) == 0 &&
                        strcmp(inputPass, daftarUser[i].password) == 0)
                    {
                        printf("\nLogin berhasil! Selamat datang, %s.\n", inputUser);
                        return 1;
                    }
                }

                percobaan++;
                printf("Username atau password salah! (Sisa percobaan: %d)\n", 3 - percobaan);
            }

            printf("\nGagal login 3 kali. Program ditutup demi keamanan.\n");
            return 0;
        }
        else
        {
            printf("Pilihan tidak valid!\n");
        }
    }
}