// Header guard untuk mencegah inklusi ganda file model.h saat kompilasi
#ifndef MODEL_H
#define MODEL_H

// Kapasitas maksimal array untuk tiap entitas data (kamar, penghuni, transaksi)
#define MAX_DATA 100

// Fondasi data entitas Kamar: menyimpan nomor, tipe, harga sewa, dan status ketersediaan
typedef struct
{
    int nomor;
    char tipe[50];
    int harga;
    int status; // 0 = Kosong, 1 = Terisi
} Kamar;

// Fondasi data entitas Penghuni: menyimpan identitas, kontak, kamar yang ditempati, dan tanggal masuk
typedef struct
{
    char id[15];
    char nama[60];
    char noHp[20];
    int nomorKamar;
    char tglMasuk[20];
} Penghuni;

// Fondasi data entitas Transaksi: menyimpan detail pembayaran sewa kos per bulan dan statusnya
typedef struct
{
    char id[15];
    char idPenghuni[15];
    int nomorKamar;
    int bulan; // [PERBAIKAN] Tambah variabel bulan
    int jumlah;
    int status; // 1 = Lunas
} Transaksi;

#endif