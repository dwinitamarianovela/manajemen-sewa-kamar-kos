// Header Guard: Mencegah error kompilasi akibat definisi ganda jikaa file ini di include berkali kali
#ifndef LOGIN_H
#define LOGIN_H

// Mendefinisikan konstanta batas maksimal jumlah akun pengguna/admin yang bisa didaftarkan
#define MAX_USER 10

// Struct 'User': Cetak biru (tipe data bentukan) untuk menampung data akun
typedef struct
{
    char username[30];
    char password[30];
} User;

// Prototipe Fungsi Utama Login
// Fungsi gerbang login yang akan dipanggil pertama kali sebelum masuk menu utama
// Fungsi gerbang login: mengembalikan 1 jika berhasil masuk, 0 jika batal/gagal
int prosesLogin();

#endif // Penutup dari blok Header Guard LOGIN_H