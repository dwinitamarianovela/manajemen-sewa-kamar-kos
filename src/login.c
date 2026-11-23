#include <stdio.h>  // Untuk menampilkan teks dan membaca input keyboard
#include <string.h> // Untuk mencocokkan teks username dan password
#include "login.h"  // Menghubungkan file ini dengan deklarasi di login.h

// Fungsi untuk mengecek login sebelum masuk ke menu utama
int prosesLogin()
{
    // Username dan password tetap yang dipakai bersama oleh Kelompok 2
    char usernameBenar[] = "admin kelompok dua";
    char passwordBenar[] = "kelompok dua hebat";

    char inputUser[30], inputPass[30]; // Menyimpan ketikan dari user
    int percobaan = 0;                 // Menghitung berapa kali salah ketik

    printf("\n=== SELAMAT DATANG DI SISTEM KOS ===\n");

    // User diberi maksimal 3 kali kesempatan untuk login
    while (percobaan < 3)
    {
        printf("\n--- Login Pengelola Kos ---\n");

        // Membaca input sampai tombol Enter ditekan (jadi spasi tetap terbaca)
        printf("Username : ");
        scanf(" %29[^\n]", inputUser);

        printf("Password : ");
        scanf(" %29[^\n]", inputPass);

        // Cek apakah username dan password yang diketik sudah cocok
        if (strcmp(inputUser, usernameBenar) == 0 && strcmp(inputPass, passwordBenar) == 0)
        {
            printf("\n[+] Login berhasil! Selamat datang, %s.\n", inputUser);
            return 1; // Berhasil masuk, lanjut buka menu utama
        }

        // Kalau salah, kurangi sisa kesempatan
        percobaan++;
        printf("[!] Username atau password salah! (Sisa percobaan: %d)\n", 3 - percobaan);
    }

    // Kalau sudah 3 kali salah, program otomatis keluar
    printf("\n[!] Gagal login 3 kali. Program ditutup demi keamanan.\n");
    return 0;
}