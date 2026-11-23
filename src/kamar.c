#include <stdio.h>
#include "kamar.h"

/*
 * Fungsi untuk mencari posisi/index kamar berdasarkan nomor kamar.
 * Mengembalikan index jika kamar ditemukan, atau -1 jika tidak ditemukan.
 */
int cariIndeksKamar(Kamar list[], int jumlah, int nomorKamar)
{
    // Periksa setiap kamar dari index 0 sampai jumlah data - 1.
    for (int i = 0; i < jumlah; i++)
    {
        // Jika nomor kamar pada data sama dengan nomor yang dicari,
        // kembalikan posisi data tersebut.
        if (list[i].nomor == nomorKamar)
            return i;
    }

    // Nilai -1 menandakan nomor kamar tidak ada di dalam daftar.
    return -1;
}

/*
 * Prosedur untuk menampilkan seluruh data kamar.
 * Parameter list berisi array kamar, sedangkan jumlah adalah banyaknya kamar.
 */
void tampilkanKamar(Kamar list[], int jumlah)
{
    printf("\n--- DAFTAR KAMAR ---\n");

    // Ulangi sebanyak jumlah kamar yang tersimpan di dalam array.
    for (int i = 0; i < jumlah; i++)
    {
        // Tampilkan nomor, tipe, harga, dan status kamar.
        // Operator ?: mengubah status 0 menjadi "Kosong" dan selain 0 menjadi "Terisi".
        printf("Kamar %d | %s | Rp%d | %s\n",
               list[i].nomor, list[i].tipe, list[i].harga,
               list[i].status == 0 ? "Kosong" : "Terisi");
    }
}

/*
 * Prosedur untuk menambahkan satu data kamar baru ke dalam array.
 * Parameter jumlah menggunakan pointer agar jumlah data asli di main ikut berubah.
 */
void tambahKamar(Kamar list[], int *jumlah)
{
    // Minta pengguna memasukkan nomor kamar baru ke posisi array berikutnya.
    printf("Nomor Kamar : ");
    scanf("%d", &list[*jumlah].nomor);

    // Baca tipe kamar, termasuk spasi, sampai pengguna menekan Enter.
    printf("Tipe Kamar   : ");
    scanf(" %49[^\n]", list[*jumlah].tipe);

    // Minta harga sewa kamar.
    printf("Harga Sewa  : ");
    scanf("%d", &list[*jumlah].harga);

    // Kamar baru otomatis diberi status 0, artinya masih kosong.
    list[*jumlah].status = 0;

    // Tambahkan jumlah kamar karena satu data baru sudah dimasukkan.
    (*jumlah)++;

    printf("[+] Kamar berhasil ditambah!\n");
}
