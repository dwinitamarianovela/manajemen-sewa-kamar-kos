#ifndef MODEL_H
#define MODEL_H

#define MAX_DATA 100

typedef struct {
    int nomor;
    char tipe[50];
    int harga;
    int status; // 0 = Kosong, 1 = Terisi
} Kamar;

typedef struct {
    char id[15];
    char nama[60];
    char noHp[20];
    int nomorKamar;
    char tglMasuk[20];
} Penghuni;

typedef struct {
    char id[15];
    char idPenghuni[15];
    int nomorKamar;
    int jumlah;
    int status; // 1 = Lunas
} Transaksi;

#endif