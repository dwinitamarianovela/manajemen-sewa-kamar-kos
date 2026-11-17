#include <stdio.h>
#include "model.h"
#include "kamar.h"
#include "penghuni.h"
#include "transaksi.h"

int main() {
    Kamar daftarKamar[MAX_DATA];
    Penghuni daftarPenghuni[MAX_DATA];
    Transaksi daftarTransaksi[MAX_DATA];

    int jmlKamar = 0;
    int jmlPenghuni = 0;
    int jmlTransaksi = 0;
    int pilihan;

    // MATERI UTAMA: Perulangan do-while
    do {
        printf("\n=== SISTEM MANAJEMEN KOS ===\n");
        printf("1. Lihat Kamar\n");
        printf("2. Tambah Kamar\n");
        printf("3. Lihat Penghuni\n");
        printf("4. Check-In Penghuni\n");
        printf("5. Check-Out Penghuni\n");
        printf("6. Lihat Transaksi\n");
        printf("7. Bayar Sewa (Diskon)\n");
        printf("0. Simpan & Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) tampilkanKamar(daftarKamar, jmlKamar);
        else if (pilihan == 2) tambahKamar(daftarKamar, &jmlKamar);
        else if (pilihan == 3) tampilkanPenghuni(daftarPenghuni, jmlPenghuni);
        else if (pilihan == 4) tambahPenghuni(daftarPenghuni, &jmlPenghuni, daftarKamar, jmlKamar);
        else if (pilihan == 5) hapusPenghuni(daftarPenghuni, &jmlPenghuni, daftarKamar, jmlKamar);
        else if (pilihan == 6) tampilkanTransaksi(daftarTransaksi, jmlTransaksi);
        else if (pilihan == 7) tambahTransaksi(daftarTransaksi, &jmlTransaksi);
        else if (pilihan == 0) {
            printf("Terima kasih. Sampai jumpa!\n");
        }
    } while (pilihan != 0);

    return 0;
}