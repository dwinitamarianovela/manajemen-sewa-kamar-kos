#include <stdio.h>
#include "kamar.h"

// FUNGSI (return value): Mencari kamar pakai perulangan FOR
int cariIndeksKamar(Kamar list[], int jumlah, int nomorKamar)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (list[i].nomor == nomorKamar)
            return i;
    }
    return -1;
}

// PROSEDUR: Menampilkan semua kamar pakai perulangan FOR
void tampilkanKamar(Kamar list[], int jumlah)
{
    printf("\n--- DAFTAR KAMAR ---\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("Kamar %d | %s | Rp%d | %s\n",
               list[i].nomor, list[i].tipe, list[i].harga,
               list[i].status == 0 ? "Kosong" : "Terisi");
    }
}

void tambahKamar(Kamar list[], int *jumlah)
{
    printf("Nomor Kamar : ");
    scanf("%d", &list[*jumlah].nomor);
    printf("Tipe Kamar   : ");
    scanf(" %49[^\n]", list[*jumlah].tipe);
    printf("Harga Sewa  : ");
    scanf("%d", &list[*jumlah].harga);
    list[*jumlah].status = 0;
    (*jumlah)++;
    printf("[+] Kamar berhasil ditambah!\n");
}