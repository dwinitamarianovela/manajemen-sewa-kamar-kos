#include <stdio.h>
#include "transaksi.h"

void tampilkanTransaksi(Transaksi list[], int jumlah) {
    printf("\n--- RIWAYAT TRANSAKSI ---\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%s | Penghuni: %s | Kamar %d | %d Bulan | Total: Rp%d\n",
               list[i].id, list[i].idPenghuni, list[i].nomorKamar,
               list[i].status, list[i].jumlah);
    }
}

void tambahTransaksi(Transaksi listT[], int *jmlT) {
    int harga, bulan;
    printf("ID Transaksi  : "); scanf("%s", listT[*jmlT].id);
    printf("ID Penghuni   : "); scanf("%s", listT[*jmlT].idPenghuni);
    printf("Nomor Kamar   : "); scanf("%d", &listT[*jmlT].nomorKamar);
    printf("Harga/Bulan   : "); scanf("%d", &harga);
    printf("Lama Sewa(bln): "); scanf("%d", &bulan);

    int total = harga * bulan;

    // MATERI UTAMA: Percabangan if - else if - else
    if (bulan >= 12) {
        total = total * 90 / 100; // Diskon 10%
        printf("[i] Dapat diskon 10%%!\n");
    } else if (bulan >= 6) {
        total = total * 95 / 100; // Diskon 5%
        printf("[i] Dapat diskon 5%%!\n");
    } else {
        printf("[i] Harga normal.\n");
    }

    listT[*jmlT].jumlah = total;
    listT[*jmlT].status = 1; // Lunas
    (*jmlT)++;
    printf("[+] Total bayar: Rp%d\n", total);
}