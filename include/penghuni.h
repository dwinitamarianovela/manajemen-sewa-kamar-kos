#ifndef PENGHUNI_H
#define PENGHUNI_H

#include "model.h" // Menyertakan definisi struct Penguhuni dan kamar

// Menampilkan seluruh daftar penghuni kos yang aktif
void tampilkanPenghuni(Penghuni list[], int jumlah);

// Menampilkan penghuni baru (check-in) dan mengubah status kamar menjadi terisi
void tambahPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK);

// Menghapus data penghuni (check-out) dan mengembalikan status kamar menjadi kosong
void hapusPenghuni(Penghuni listP[], int *jmlP, Kamar listK[], int jmlK);

#endif