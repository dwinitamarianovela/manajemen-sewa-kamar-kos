# 🏠 Sistem Manajemen Sewa Kamar Kos (Berbasis Konsol)

Aplikasi berbasis konsol (*Command Line Interface*) yang dibangun menggunakan **Bahasa C** dengan pendekatan **Pemrograman Modular** untuk membantu pengelolaan operasional rumah kos secara efisien, terstruktur, dan tersimpan secara permanen.

## 👥 Anggota Kelompok 2
* **Alfarabi Rasebdriya Citarre        (26071100444)**
* **Dwinita Maria Novela               (26071102777)**
* **Irfan Islami Parsa                 (26071100299)**
* **Nadira Syafiyah Hasibuan           (26071102880)**
* **Rizky Dwi Putra                    (26071103137)**

---

## 🎯 Tujuan & Fitur Utama Aplikasi
1. **Manajemen Data Kamar:** Melihat daftar kamar beserta status ketersediaan (`Kosong` / `Terisi`), harga sewa bulanan, tipe kamar, serta menambah unit kamar baru.
2. **Manajemen Penghuni (*Check-In* & *Check-Out*):** Mendaftarkan penyewa baru ke kamar yang tersedia (status kamar otomatis berubah menjadi `Terisi`) serta memproses penghuni keluar (kamar otomatis kembali menjadi `Kosong`).
3. **Manajemen Transaksi & Keuangan:** Mencatat tagihan sewa bulanan, menerapkan potongan diskon otomatis untuk pembayaran jangka panjang, melunasi tagihan, serta menghitung total pemasukan kos secara akurat.
4. **Penyimpanan Data Permanen (*File Handling*):** Seluruh perubahan data otomatis disimpan ke dalam file teks (`.txt`) sehingga data tetap aman meskipun program ditutup.

---

## 📂 Struktur Folder & File Proyek

```text
manajemen-sewa-kamar-kos/
├── data/                   # Penyimpanan database berbasis file teks (.txt)
│   ├── kamar.txt           # Data kamar (Nomor;Tipe;Harga;Status)
│   ├── penghuni.txt        # Data penyewa (ID;Nama;NoHP;NomorKamar;TglMasuk)
│   └── transaksi.txt       # Data pembayaran (IDTrx;IDPenghuni;Kamar;Bulan;Nominal;Status)
├── include/                # Header files (.h) untuk deklarasi struct & prototipe fungsi
│   ├── model.h             # Definisi struct (Kamar, Penghuni, Transaksi) & konstanta
│   ├── kamar.h             # Deklarasi modul manajemen kamar
│   ├── penghuni.h          # Deklarasi modul manajemen penghuni
│   ├── transaksi.h         # Deklarasi modul transaksi & laporan keuangan
├── src/                    # Source files (.c) berisi implementasi logika program
│   ├── main.c              # Titik masuk program & navigasi menu utama
│   ├── kamar.c             # Implementasi fitur kamar
│   ├── penghuni.c          # Implementasi fitur penghuni
│   ├── transaksi.c         # Implementasi perhitungan tagihan & diskon
├── .gitignore              # Mengabaikan file hasil kompilasi (*.exe, *.o)
└── README.md               # Dokumentasi proyek
```

## ⚙️ Cara Compile dan Menjalankan Program

### 1. Prasyarat
* Compiler **GCC** (MinGW / MSYS2 untuk Windows, atau GCC bawaan di Linux/macOS).
* Pastikan terminal berada di direktori utama proyek (`manajemen-sewa-kamar-kos/`).

### 2. Kompilasi Program
Jalankan perintah berikut di terminal untuk mengompilasi seluruh file sumber secara bersamaan:

```bash
gcc src/main.c src/file_manager.c src/kamar.c src/penghuni.c src/transaksi.c src/utils.c -Iinclude -o kos.exe
```

### 3. Menjalankan Aplikasi
* **Windows (PowerShell / CMD):**
  ```powershell
  .\kos.exe
  ```
* **Linux / macOS:**
  ```bash
  ./kos.exe
  ```
