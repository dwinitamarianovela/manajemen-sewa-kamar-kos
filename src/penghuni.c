#include <stdio.h>
#include <string.h>
#include "penghuni.h"
#include "kamar.h"

void tampilkanPenghuni(Penghuni list[], int jumlah)
{
    printf("\n--- DAFTAR PENGHUNI ---\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("[%s] %s | HP: %s | Kamar: %d\n",
               list[i].id, list[i].nama, list[i].noHp, list[i].nomorKamar);
    }
}

void tambahPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK)
{
    int noKamar;
    printf("Pilih Nomor Kamar: ");
    scanf("%d", &noKamar);

    int idxK = cariIndeksKamar(listK, jmlK, noKamar);
    if (idxK == -1 || listK[idxK].status == 1)
    {
        printf("[!] Kamar tidak tersedia!\n");
        return;
    }

    printf("ID Penghuni   : ");
    scanf("%s", listP[*jmlP].id);
    printf("Nama Lengkap : ");
    scanf(" %59[^\n]", listP[*jmlP].nama);
    printf("No HP         : ");
    scanf("%s", listP[*jmlP].noHp);
    printf("Tanggal Masuk : ");
    scanf(" %[^\n]", listP[*jmlP].tglMasuk);
    listP[*jmlP].nomorKamar = noKamar;

    listK[idxK].status = 1; // Kamar otomatis jadi Terisi
    (*jmlP)++;
    printf("[+] Check-in berhasil!\n");
}

void hapusPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK)
{
    char idCari[15];
    printf("Masukkan ID Penghuni Check-Out: ");
    scanf("%s", idCari);

    for (int i = 0; i < *jmlP; i++)
    {
        if (strcmp(listP[i].id, idCari) == 0)
        {
            int idxK = cariIndeksKamar(listK, jmlK, listP[i].nomorKamar);
            if (idxK != -1)
                listK[idxK].status = 0; // Kamar kembali Kosong

            for (int j = i; j < *jmlP - 1; j++)
            {
                listP[j] = listP[j + 1];
            }
            (*jmlP)--;
            printf("[+] Check-out berhasil!\n");
            return;
        }
    }
    printf("[!] ID tidak ditemukan!\n");
}