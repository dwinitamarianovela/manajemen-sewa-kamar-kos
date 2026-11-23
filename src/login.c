#include <stdio.h>
#include <string.h> // Dibutuhkan untuk menggunakanfungsi strcmp() saat mencocokkan teks
#include "login.h"  // Menghubungkan file ini dengan deklarasi struct User di login.h

// Fungsi gerbang utama sebelum masuk ke aplikasi
// Mengembalikan 1 jika login sukses, dan 0 jika gagal/keluar
int prosesLogin()
{
    // Membuat array data user dan langsung mengisi 1 akun default (admin)
    User daftarUser[MAX_USER] = {
        {"admin", "admin123"}};
    int jmlUser = 1; // Menandakan saat ini sudah ada 1 akun yag terdaftar
    int pilihan;

    // Prulangan tak terbatas untuk menampilkan menu login
    // Loop ini hanya akan berhenti jika ada perintah 'return'
    while (1)
    {
        printf("\n=== SELAMAT DATANG DI SISTEM KOS ===\n");
        printf("1. Login\n");
        printf("2. Daftar Akun Baru\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        // Jika user memilih 0, program langsung berhenti (return 0 ke main.c)
        if (pilihan == 0)
        {
            return 0;
        }
        // Logika Pendaftaran Akun Baru
        else if (pilihan == 2)
        {
            // Mencegah pendaftaran jika jumlah akun sudah mencapai batas MAX_USER (10)
            if (jmlUser >= MAX_USER)
            {
                printf("Kapasitas akun penuh!\n");
                continue; // Melewati sisa kode di bawah dan mengulang menu dari awal
            }

            // Memasukkan data ke array daftarUserr pada indeks ke-jmlUser
            printf("\n--- Daftar Akun Baru ---\n");
            printf("Buat Username : ");
            scanf("%s", daftarUser[jmlUser].username);
            printf("Buat Password : ");
            scanf("%s", daftarUser[jmlUser].password);
            jmlUser++; // Menambah penghitung jumlah user agar data berikutnyaa tidak menimpa
            printf("Akun berhasil didaftarkan! Silakan login.\n");
        }
        // Logika Login
        else if (pilihan == 1)
        {
            char inputUser[30], inputPass[30];
            int percobaan = 0; // Variabel untuk menghitung jumlah kegagalan login

            // Memberi batas maksimal 3 kali percobaan login
            while (percobaan < 3)
            {
                printf("\n--- Login Pengelola Kos ---\n");
                printf("Username : ");
                scanf("%s", inputUser);
                printf("Password : ");
                scanf("%s", inputPass);

                // Looping untuk mengecek apakah input cocok dengan data di memori
                for (int i = 0; i < jmlUser; i++)
                {
                    // strcmp() digunakan untuk membandingkan 2 string
                    // Jika hasilnya == 0, berarti teksnya sama persis
                    if (strcmp(inputUser, daftarUser[i].username) == 0 &&
                        strcmp(inputPass, daftarUser[i].password) == 0)
                    {
                        printf("\nLogin berhasil! Selamat datang, %s.\n", inputUser);
                        return 1; // Melempar nilai 1 ke main.c tanda boleh masuk aplikasi
                    }
                }

                // Jika looping for selesai tapi tidak ada yang cocok, percobaan bertambah
                percobaan++;
                printf("Username atau password salah! (Sisa percobaan: %d)\n", 3 - percobaan);
            }

            // Jika perulangan while (percobaan < 3) selesai, berarti sudah gagal 3x
            printf("\nGagal login 3 kali. Program ditutup demi keamanan.\n");
            return 0; // Menghentikan program
        }
        else
        {
            printf("Pilihan tidak valid!\n");
        }
    }
}