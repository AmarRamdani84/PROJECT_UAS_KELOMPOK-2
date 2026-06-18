# 🎓 Project UAS Kelas D | Kelompok II

[![Status](https://img.shields.io/badge/Status-Proses-inProgres)](#)
[![Course](https://img.shields.io/badge/Mata_Kuliah-Teknik_Informatika-blue)](#)
[![University](https://img.shields.io/badge/Universitas-UNPER_Tasikmalaya-orange)](#)

Selamat datang di repositori **Project Ujian Akhir Semester (UAS) Kelas D**. Repositori ini berisi seluruh susunan kode, dokumentasi, dan aset yang digunakan untuk menyelesaikan tugas akhir semester kami.

---

## 📂 Struktur Direktori & Fungsinya

Repositori ini disusun dengan rapi agar mudah dipahami dan dinavigasi. Berikut adalah kegunaan dari masing-masing folder:

| Folder | Ikon | Fungsi & Kegunaan |
| :--- | :---: | :--- |
| `assets/` | 🖼️ | **Penyimpanan Media:** Berisi file statis pendukung seperti gambar, diagram alur (flowchart), logo, dan aset visual lainnya yang digunakan dalam proyek atau laporan. |
| `code/` | 💻 | **Source Code Utama:** Tempat penyimpanan seluruh file program/kode sumber (misalnya file C++). Semua logika program dan algoritma diletakkan di dalam folder ini. |
| `document/` | 📄 | **Pusat Dokumentasi:** Digunakan untuk menyimpan file laporan resmi, makalah, catatan desain sistem, referensi, dan dokumen penunjang lainnya (format PDF/Word/Markdown). |
| `soal/` | 📝 | **Referensi Tugas:** Berisi lampiran soal UAS asli, deskripsi tugas, atau panduan proyek yang diberikan oleh dosen sebagai acuan penyelesaian tugas. |

---

## 👥 Susunan Anggota Tim & Pembagian Tugas

Proyek ini dikembangkan oleh tim yang solid dengan pembagian peran sebagai berikut:

* 👑 **Ketua: Amar Ramdani**
    * **Peran:** Project Manager, GitHub Master & Code Reviewer
    * **Fungsi:** Mengelola *repository*, mengatur perizinan *branch* utama (`main`), melakukan ulasan kode (*Code Review*) pada setiap *Pull Request* anggota, dan menggabungkan kode untuk memastikan tidak ada *error* atau *merge conflict*.
* 👤 **Anggota 01: Marsha Olivia**
    * **Peran:** Main System, UI Console & Array
    * **Fungsi:** Membuat kerangka utama program (`main.cpp`) dan menu navigasi. Mengelola *Array of Structs* untuk menampilkan daftar konser, harga, dan memotong sisa kursi.
* 👤 **Anggota 02: Faiz**
    * **Peran:** Struktur Data Linked List (Riwayat Transaksi)
    * **Fungsi:** Menyimpan data setiap tiket yang berhasil dibayar ke dalam *Linked List*. Membuat fitur untuk menampilkan seluruh riwayat pembelian tiket yang telah sukses.
* 👤 **Anggota 03: Raihan Sutan**
    * **Peran:** Validasi & Sistem Pembayaran
    * **Fungsi:** Membuat fungsi untuk menghitung total harga tiket, mengonfirmasi pembayaran, dan mengatur pesan validasi (*error handling*) jika kuota tiket habis saat diproses.
* 👤 **Anggota 04: Nizfa Salatri**
    * **Peran:** Struktur Data Queue (Antrean Pembelian)
    * **Fungsi:** Membangun logika antrean menggunakan *Queue*. Mengelola fungsi `Enqueue` (pembeli masuk ke antrean pemesanan) dan `Dequeue` (memproses pembeli di antrean terdepan ke tahap pembayaran).
* 👤 **Anggota 05: Arsyika Fadlika**
    * **Peran:** Searching, Sorting & Dokumentasi
    * **Fungsi:** Membuat algoritma pencarian (*Search*) ID Transaksi dan pengurutan (*Sort*) daftar konser. Bertanggung jawab menyusun laporan akhir dan mengelola aset presentasi proyek.

---

## 🚀 Cara Menjalankan Proyek (Opsional)

1. *Clone* repositori ini ke komputer lokal Anda:
```bash
   git clone [https://github.com/AmarRamdani84/nama-repositori.git](https://github.com/AmarRamdani84/nama-repositori.git)
