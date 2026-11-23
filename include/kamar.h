#ifndef KAMAR_H
#define KAMAR_H

#include "model.h" // Menggunakan definisi struct Kamar dari model.h.

/*
 * Mencari index kamar berdasarkan nomor kamar.
 * Mengembalikan index jika ditemukan dan -1 jika tidak ditemukan.
 */
int cariIndeksKamar(Kamar list[], int jumlah, int nomorKamar);

/*
 * Menampilkan seluruh kamar yang tersimpan di dalam array.
 */
void tampilkanKamar(Kamar list[], int jumlah);

/*
 * Menambahkan data kamar baru ke array dan memperbarui jumlah data.
 */
void tambahKamar(Kamar list[], int *jumlah);

#endif // KAMAR_H
