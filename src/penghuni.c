#include <stdio.h>
#include <string.h>
#include "penghuni.h"
#include "kamar.h" // Dibutuhkan untuk memanggil fungsi cariIndeksKamar

// Menampilkan seluruh daftar penghuni yang tersimpan di dalam array
void tampilkanPenghuni(Penghuni list[], int jumlah) {
    printf("\n--- DAFTAR PENGHUNI ---\n");
    for (int i = 0; i < jumlah; i++) {
        printf("[%s] %s | HP: %s | Kamar: %d\n",
               list[i].id, list[i].nama, list[i].noHp, list[i].nomorKamar);
    }
}

// Proses chech-in: memvalidasi ketersediaan kamar, mengisi data penghuni, dan update status kamar
void tambahPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK) {
    int noKamar;
    printf("Pilih Nomor Kamar: "); scanf("%d", &noKamar);

    // Cari indeks kamar berdasarkan nomor kamar yang diinput
    int idxK = cariIndeksKamar(listK, jmlK, noKamar);
    
    // Validasi jika kamar tidak ditemukan (-1) atau sudah terisi (status == 1)
    if (idxK == -1 || listK[idxK].status == 1) {
        printf("[!] Kamar tidak tersedia!\n");
        return;
    }

    // Input biodata penghuni baru ke indeks array terakhir 
    printf("ID Penghuni   : "); scanf("%s", listP[*jmlP].id);
    printf("Nama Lengkap  : "); scanf(" %[^\n]", listP[*jmlP].nama); // Membaca input string dengan spasi
    printf("No HP         : "); scanf("%s", listP[*jmlP].noHp);
    printf("Tanggal Masuk : "); scanf(" %[^\n]", listP[*jmlP].tglMasuk);
    listP[*jmlP].nomorKamar = noKamar;

    // perbarui status kamar dan jumlah total penghuni 
    listK[idxK].status = 1; // Kamar otomatis jadi Terisi
    (*jmlP)++;              //Tambah jumlah penghuni aktif
    printf("[+] Check-in berhasil!\n");
}

// Proses check-out: mencari ID penghuni, mengosongkan kamar, dan menghapus data dari array  
void hapusPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK) {
    char idCari[15];
    printf("Masukkan ID Penghuni Check-Out: "); scanf("%s", idCari);

    // Telusuri array penghuni untuk mencari ID yang cocok 
    for (int i = 0; i < *jmlP; i++) {
        if (strcmp(listP[i].id, idCari) == 0) {
           // Cari kamar yang ditempati penghuni tersebut dan ubah statusnya menjadi kosong
            int idxK = cariIndeksKamar(listK, jmlK, listP[i].nomorKamar);
            if (idxK != -1) listK[idxK].status = 0; // Kamar kembali Kosong

            // Geser elemen array ke kiri untuk menimpa data penghuni yang dihapus
            for (int j = i; j < *jmlP - 1; j++) {
                listP[j] = listP[j + 1];
            }
            (*jmlP)--; // Kurangi jumlah total penghuni 
            printf("[+] Check-out berhasil!\n");
            return;
        }
    }

    // Pesan jika ID tidak ditemukan setelah seluruh array diperiksa
    printf("[!] ID tidak ditemukan!\n");
}