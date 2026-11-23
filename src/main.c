#include <stdio.h>
#include "model.h"
#include "login.h"
#include "kamar.h"
#include "penghuni.h"
#include "transaksi.h"

// Membaca data dari file .txt (kamar, penghuni, transaksi) ke array di memori saat program dimulai
void muatData(Kamar k[], int *jk, Penghuni p[], int *jp, Transaksi t[], int *jt)
{
    // Buka file data/kamar.txt dalam mode baca ("r") dan parse tiap baris berformat dipisah ';'
    FILE *fk = fopen("data/kamar.txt", "r");
    if (fk)
    {
        while (fscanf(fk, "%d;%49[^;];%d;%d\n", &k[*jk].nomor, k[*jk].tipe, &k[*jk].harga, &k[*jk].status) == 4)
        {
            (*jk)++; // Tambah jumlah data kamar yang berhasil dimuat
        }
        fclose(fk);
    }

    // Buka file data/penghuni.txt dalam mode baca ("r") dan muat data penghuni ke array
    FILE *fp = fopen("data/penghuni.txt", "r");
    if (fp)
    {
        while (fscanf(fp, "%14[^;];%59[^;];%19[^;];%d;%19[^\n]\n", p[*jp].id, p[*jp].nama, p[*jp].noHp, &p[*jp].nomorKamar, p[*jp].tglMasuk) == 5)
        {
            (*jp)++; // Tambah jumlah data penghuni yang berhasil dimuat
        }
        fclose(fp);
    }

    // Buka file data/transaksi.txt dalam mode baca ("r") dan muat data transaksi ke array
    FILE *ft = fopen("data/transaksi.txt", "r");
    if (ft)
    {
        while (fscanf(ft, "%14[^;];%14[^;];%d;%d;%d;%d\n", t[*jt].id, t[*jt].idPenghuni, &t[*jt].nomorKamar, &t[*jt].bulan, &t[*jt].jumlah, &t[*jt].status) == 6)
        {
            (*jt)++; // Tambah jumlah data transaksi yang berhasil dimuat
        }
        fclose(ft);
    }
}

// Menulis ulang seluruh data dari memori ke file .txt agar perubahan tersimpan permanen
void simpanData(Kamar k[], int jk, Penghuni p[], int jp, Transaksi t[], int jt)
{
    // Timpa/tulis ulang data kamar ke data/kamar.txt dengan pemisah ';'
    FILE *fk = fopen("data/kamar.txt", "w");
    if (fk)
    {
        for (int i = 0; i < jk; i++)
            fprintf(fk, "%d;%s;%d;%d\n", k[i].nomor, k[i].tipe, k[i].harga, k[i].status);
        fclose(fk);
    }

    // Timpa/tulis ulang data penghuni ke data/penghuni.txt dengan pemisah ';'
    FILE *fp = fopen("data/penghuni.txt", "w");
    if (fp)
    {
        for (int i = 0; i < jp; i++)
            fprintf(fp, "%s;%s;%s;%d;%s\n", p[i].id, p[i].nama, p[i].noHp, p[i].nomorKamar, p[i].tglMasuk);
        fclose(fp);
    }

    // Timpa/tulis ulang data transaksi ke data/transaksi.txt dengan pemisah ';'
    FILE *ft = fopen("data/transaksi.txt", "w");
    if (ft)
    {
        for (int i = 0; i < jt; i++)
            fprintf(ft, "%s;%s;%d;%d;%d;%d\n", t[i].id, t[i].idPenghuni, t[i].nomorKamar, t[i].bulan, t[i].jumlah, t[i].status);
        fclose(ft);
    }
}

int main()
{
    // 1. Panggil gerbang login sebelum masuk menu
    if (prosesLogin() == 0)
    {
        return 0; // Berhenti jika gagal login 3x
    }

    // Inisialisasi array penampung data dan penghitung jumlah data aktif
    Kamar daftarKamar[MAX_DATA];
    Penghuni daftarPenghuni[MAX_DATA];
    Transaksi daftarTransaksi[MAX_DATA];

    int jmlKamar = 0, jmlPenghuni = 0, jmlTransaksi = 0;
    int pilihan;

    // 2. Muat data dari file .txt saat program baru mulai
    muatData(daftarKamar, &jmlKamar, daftarPenghuni, &jmlPenghuni, daftarTransaksi, &jmlTransaksi);

    // Loop utama menu aplikasi; terus berjalan sampai pengguna memilih 0 (Simpan & Keluar)
    do
    {
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

        // Arahkan pilihan pengguna ke fungsi modul terkait
        if (pilihan == 1)
            tampilkanKamar(daftarKamar, jmlKamar);
        else if (pilihan == 2)
            tambahKamar(daftarKamar, &jmlKamar);
        else if (pilihan == 3)
            tampilkanPenghuni(daftarPenghuni, jmlPenghuni);
        else if (pilihan == 4)
            tambahPenghuni(daftarPenghuni, &jmlPenghuni, daftarKamar, jmlKamar);
        else if (pilihan == 5)
            hapusPenghuni(daftarPenghuni, &jmlPenghuni, daftarKamar, jmlKamar);
        else if (pilihan == 6)
            tampilkanTransaksi(daftarTransaksi, jmlTransaksi);
        else if (pilihan == 7)
            tambahTransaksi(daftarTransaksi, &jmlTransaksi);
        else if (pilihan == 0)
        {
            // 3. Simpan data kembali ke .txt saat keluar
            simpanData(daftarKamar, jmlKamar, daftarPenghuni, jmlPenghuni, daftarTransaksi, jmlTransaksi);
            printf("[+] Data berhasil disimpan. Terima kasih, sampai jumpa!\n");
        }
        else
        {
            printf("[!] Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}