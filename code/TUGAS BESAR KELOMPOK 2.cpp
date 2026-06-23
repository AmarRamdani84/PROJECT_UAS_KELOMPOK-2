#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// BAGIAN MARSHA OLIVIA: Struktur Data & Array Global

struct Konser {
    int id;
    string namaKonser;
    double harga;
    int kuota;
};

const int MAX_KONSER = 3; 
Konser daftarKonser[MAX_KONSER];

void inisialisasiDummyData() {
    daftarKonser[0] = {1, "Coldplay Live in Jakarta", 1500000, 50};
    daftarKonser[1] = {2, "NIKI Buzz World Tour", 850000, 30};
    daftarKonser[2] = {3, "Tulus Tur Manusia", 500000, 5};
}

void lihatKonser() {
    cout << "\n========================================= \n";
    cout << "             DAFTAR KONSER                \n";
    cout << "========================================= \n";
    cout << left << setw(5) << "ID" << setw(30) << "Nama Konser" << setw(15) << "Harga" << "Sisa Kuota" << endl;
    cout << "----------------------------------------- \n";
    
    for (int i = 0; i < MAX_KONSER; i++) {
        cout << left << setw(5) << daftarKonser[i].id 
             << setw(30) << daftarKonser[i].namaKonser 
             << "Rp " << setw(12) << fixed << setprecision(0) << daftarKonser[i].harga 
             << daftarKonser[i].kuota << " kursi" << endl;
    }
    cout << "========================================= \n";
}

// PLACEHOLDER & KETERANGAN UNTUK ANGGOTA TIM LAIN (SESUAI README GITHUB)

// Bagian Anggota 04: Nizfa Salatri (Struktur Data Queue - Antrean Pembelian)
void masukAntrean() {
    cout << "\n[Fungsi Masuk Antrean - Bagian Nizfa Salatri]\n";
    // NOTE UNTUK NIZFA: 
    // - Bangun logika antrean menggunakan Queue.
    // - Kelola fungsi Enqueue agar pembeli bisa masuk ke antrean pemesanan.
    // - Kelola fungsi Dequeue untuk memproses pembeli di antrean terdepan ke tahap pembayaran.
}

// Bagian Anggota 03: Raihan Sutan (Validasi & Sistem Pembayaran)
void prosesKasir() {
    cout << "\n[Fungsi Proses Kasir - Bagian Raihan Sutan]\n";
    // NOTE UNTUK RAIHAN SUTAN:
    // - Membuat fungsi untuk menghitung total harga tiket + pajak.
    // - Mengonfirmasi pembayaran.
    // - Mengatur pesan validasi (error handling) jika kuota tiket habis saat diproses.
    // - Jika sukses, kurangi sisa kursi di Array 'daftarKonser' milik Marsha.
}

// Bagian Anggota 02: Faiz (Struktur Data Linked List - Riwayat Transaksi)
void lihatRiwayat() {
    cout << "\n[Fungsi Lihat Riwayat - Bagian Faiz]\n";
    // NOTE UNTUK FAIZ:
    // - Menyimpan data setiap tiket yang berhasil dibayar (dari Raihan) ke dalam Linked List.
    // - Membuat fitur ini untuk membaca dan menampilkan seluruh riwayat pembelian tiket yang sukses.
}

// Bagian Anggota 05: Arsyika Fadlika (Searching, Sorting & Dokumentasi)
void menuSearchingSorting() {
    cout << "\n[Fungsi Searching & Sorting - Bagian Arsyika Fadlika]\n";
    // NOTE UNTUK ARSYIKA FADLIKA:
    // - Membuat algoritma pencarian (Search) berdasarkan ID Transaksi.
    // - Membuat algoritma pengurutan (Sort) untuk daftar konser.
}


// =========================================================================
// BAGIAN MARSHA OLIVIA: Main System & UI Console (Menu Navigasi)
// =========================================================================
int main() {
    inisialisasiDummyData();
    int pilihan;
    
    do {
        cout << "\n=========================================\n";
        cout << "   SISTEM PEMESANAN TIKET KONSER CLI    \n";
        cout << "=========================================\n";
        cout << "1. Lihat Konser (Array)\n";
        cout << "2. Masuk Antrean (Queue)\n";
        cout << "3. Proses Kasir (Validasi & Bayar)\n";
        cout << "4. Lihat Riwayat (Linked List)\n";
        cout << "5. Keluar\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                lihatKonser();
                break;
            case 2:
                masukAntrean();
                break;
            case 3:
                prosesKasir();
                break;
            case 4:
                lihatRiwayat();
                break;
            case 5:
                cout << "\nProgram SELESAI. Terima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 1-5.\n";
        }
        
        if (pilihan != 5) {
            cout << "\n( KEMBALI KE MENU UTAMA )";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 5);
    
    return 0;
}
