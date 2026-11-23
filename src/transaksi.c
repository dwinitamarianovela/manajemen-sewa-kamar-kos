//Implementasi fitur riwayat transaksi, hitung diskon sewa dan cetak struk
//Dikerjakan oleh: Nadira Syafiyah Hasibuan

#include <stdio.h>
#include "transaksi.h"

//menampilkan semua data transaksi yang sudah masuk
void tampilkanTransaksi(Transaksi list[], int jumlah)
{
    printf("\n--- RIWAYAT TRANSAKSI ---\n");
    for (int i = 0; i < jumlah; i++)
    {
        //mengecek status, kalau 1 berarti lunas, selain itu belum lunas
        printf("%s | Penghuni: %s | Kamar %d | %d Bulan | Total: Rp%d | Status: %s\n",
               list[i].id, list[i].idPenghuni, list[i].nomorKamar,
               list[i].bulan, list[i].jumlah,
               list[i].status == 1 ? "Lunas" : "Belum Lunas");
    }
}

//input transaksi baru kemudian menghitung diskon berdasar lama nya sewa
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

//cek syarat diskon, apabila >= 12 bulan diskon 10% dan >=6 bulan diskon 5%
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

    // menyimpan data ke array transaksi dan set status jadi 1=lunas
    listT[*jmlT].bulan = bulan;
    listT[*jmlT].jumlah = total;
    listT[*jmlT].status = 1; // Lunas
    (*jmlT)++;
    printf("[+] Total bayar: Rp%d\n", total);
    //cetak struk dari data yang baru saja diinput
    cetakStruk(listT[*jmlT - 1]); 
}
   // cetak tampilan struk pembayaran ke layar
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
