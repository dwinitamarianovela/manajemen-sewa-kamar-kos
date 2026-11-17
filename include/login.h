#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USER 10

typedef struct
{
    char username[30];
    char password[30];
} User;

// Fungsi gerbang login: mengembalikan 1 jika berhasil masuk, 0 jika batal/gagal
int prosesLogin();

#endif