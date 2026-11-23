#include <stdio.h>
#include "transaksi.h"

void tampilkanTransaksi(Transaksi list[], int jumlah)
{
    printf("\n--- RIWAYAT TRANSAKSI ---\n");
    for (int i = 0; i < jumlah; i++)
    {
        // [PERBAIKAN] Argumen list[i].bulan disesuaikan dengan posisi %d Bulan
        printf("%s | Penghuni: %s | Kamar %d | %d Bulan | Total: Rp%d | Status: %s\n",
               list[i].id, list[i].idPenghuni, list[i].nomorKamar,
               list[i].bulan, list[i].jumlah,
               list[i].status == 1 ? "Lunas" : "Belum Lunas");
    }
}

void tambahTransaksi(Transaksi listT[], int *jmlT)
{
    int harga, bulan;
    printf("ID Transaksi    : ");
    scanf("%14s", listT[*jmlT].id);
    printf("ID Penghuni     : ");
    scanf("%14s", listT[*jmlT].idPenghuni);
    printf("Nomor Kamar     : ");
    scanf("%d", &listT[*jmlT].nomorKamar);
    printf("Harga/Bulan     : ");
    scanf("%d", &harga);
    printf("Lama Sewa (bln) : ");
    scanf("%d", &bulan);

    int total = harga * bulan;

    if (bulan >= 12)
    {
        total = total * 90 / 100; // Diskon 10%
        printf("[i] Dapat diskon 10%%!\n");
    }
    else if (bulan >= 6)
    {
        total = total * 95 / 100; // Diskon 5%
        printf("[i] Dapat diskon 5%%!\n");
    }
    else
    {
        printf("[i] Harga normal.\n");
    }

    // [PERBAIKAN] Simpan jumlah bulan ke dalam struct
    listT[*jmlT].bulan = bulan;
    listT[*jmlT].jumlah = total;
    listT[*jmlT].status = 1; // Lunas
    (*jmlT)++;
    printf("[+] Total bayar: Rp%d\n", total);
    cetakStruk(listT[*jmlT - 1]); 
}
    void cetakStruk(Transaksi t)
    {

    printf("\n==========================================\n");
    printf("         KWITANSI PEMBAYARAN KOS          \n");
    printf("==========================================\n");
    printf("ID Transaksi   : %s\n", t.id);
    printf("ID Penghuni    : %s\n", t.idPenghuni);
    printf("Nomor Kamar    : %d\n", t.nomorKamar);
    printf("Durasi Sewa    : %d Bulan\n", t.bulan);
    printf("------------------------------------------\n");
    printf("Total Bayar    : Rp %d\n", t.jumlah);
    printf("Status         : %s\n", t.status == 1 ? "LUNAS" : "BELUM LUNAS");
    printf("==========================================\n");
    printf("  Terima kasih telah melakukan pembayaran \n");
    printf("==========================================\n\n");
}
