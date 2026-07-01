 #include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =========================================================================
// BAGIAN MARSHA OLIVIA: Struktur Data & Array Global (Jadwal & Kuota)
// =========================================================================
struct Konser {
    int id;
    string namaKonser;
    string tanggal; // Ditambahkan sesuai unsur "Jadwal" di soal
    string waktu;   // Ditambahkan sesuai unsur "Jadwal" di soal
    double harga;
    int kuota;
};

const int MAX_KONSER = 3; 
Konser daftarKonser[MAX_KONSER];

void inisialisasiDummyData() {
    daftarKonser[0] = {1, "Coldplay Live in Jakarta", "15 November 2026", "20:00 WIB", 1500000, 50};
    daftarKonser[1] = {2, "NIKI Buzz World Tour", "05 Desember 2026", "19:00 WIB", 850000, 30};
    daftarKonser[2] = {3, "Tulus Tur Manusia", "18 Januari 2027", "19:30 WIB", 500000, 5};
}

void lihatKonser() {
    cout << "\n======================================================================\n";
    cout << "                         DAFTAR JADWAL KONSER                         \n";
    cout << "======================================================================\n";
    cout << left << setw(4) << "ID" << setw(28) << "Nama Konser" << setw(18) << "Jadwal" << setw(14) << "Harga" << "Sisa Kuota" << endl;
    cout << "----------------------------------------------------------------------\n";
    
    for (int i = 0; i < MAX_KONSER; i++) {
        cout << left << setw(4) << daftarKonser[i].id 
             << setw(28) << daftarKonser[i].namaKonser 
             << setw(18) << daftarKonser[i].tanggal
             << "Rp " << setw(11) << fixed << setprecision(0) << daftarKonser[i].harga 
             << daftarKonser[i].kuota << " kursi" << endl;
    }
    cout << "======================================================================\n";
}


// =========================================================================
// BAGIAN NIZFA SALATRI: Struktur Data Queue (Antrean Pembelian)
// =========================================================================
struct ElemenQueue {
    string namaPembeli;
    int idKonserDiincar;
    int jumlahTiket;
    ElemenQueue* next;
};

struct Queue {
    ElemenQueue* front = nullptr;
    ElemenQueue* rear = nullptr;
} antreanSistem;

// Penanda apakah antrean kosong
bool isQueueEmpty() {
    return antreanSistem.front == nullptr;
}

void masukAntrean() {
    cout << "\n=========================================\n";
    cout << "         MASUK ANTREAN PEMBELIAN         \n";
    cout << "=========================================\n";
    
    string nama;
    int idKonser, jumlah;

    cout << "Masukkan Nama Pembeli   : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan ID Konser (1-3): ";
    cin >> idKonser;
    cout << "Masukkan Jumlah Tiket   : ";
    cin >> jumlah;

    ElemenQueue* nodeBaru = new ElemenQueue;
    nodeBaru->namaPembeli = nama;
    nodeBaru->idKonserDiincar = idKonser;
    nodeBaru->jumlahTiket = jumlah;
    nodeBaru->next = nullptr;

    if (isQueueEmpty()) {
        antreanSistem.front = nodeBaru;
        antreanSistem.rear = nodeBaru;
    } else {
        antreanSistem.rear = nodeBaru;
        antreanSistem.rear = nodeBaru; 
    }
    cout << "\n[Sukses] Sdr/i " << nama << " telah masuk ke dalam antrean!\n";
}

// =========================================================================
// BAGIAN FAIZ: Struktur Data Linked List (Riwayat Transaksi)
// =========================================================================
struct Transaksi {
    int idTransaksi; // Penting untuk pencarian Arsyika
    string namaPembeli;
    string namaKonser;
    int jumlahTiket;
    double totalBayar;
    Transaksi* next;
};

Transaksi* headRiwayat = nullptr; // Pointer utama riwayat transaksi
int globalIdTransaksi = 1001;     // ID Transaksi otomatis mulai dari 1001

// Fungsi tambahan untuk menyimpan transaksi sukses (Insert Last)
void tambahRiwayat(string nama, string konser, int jumlah, double total) {
    Transaksi* nodeBaru = new Transaksi;
    nodeBaru->idTransaksi = globalIdTransaksi++;
    nodeBaru->namaPembeli = nama;
    nodeBaru->namaKonser = konser;
    nodeBaru->jumlahTiket = jumlah;
    nodeBaru->totalBayar = total;
    nodeBaru->next = nullptr;

    if (headRiwayat == nullptr) {
        headRiwayat = nodeBaru;
    } else {
        Transaksi* temp = headRiwayat;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

void lihatRiwayat() {
    cout << "\n======================================================================\n";
    cout << "                        RIWAYAT TRANSAKSI SUKSES                      \n";
    cout << "======================================================================\n";
    
    if (headRiwayat == nullptr) {
        cout << "Belum ada riwayat transaksi yang sukses.\n";
    } else {
        Transaksi* temp = headRiwayat;
        cout << left << setw(10) << "ID" << setw(20) << "Nama Pembeli" << setw(30) << "Konser" << setw(10) << "Jumlah" << "Total Bayar\n";
        cout << "----------------------------------------------------------------------\n";
        while (temp != nullptr) {
            cout << left << setw(10) << temp->idTransaksi
                 << setw(20) << temp->namaPembeli
                 << setw(30) << temp->namaKonser
                 << setw(10) << temp->jumlahTiket
                 << "Rp " << fixed << setprecision(0) << temp->totalBayar << endl;
            temp = temp->next;
        }
    }
}

// =========================================================================
// BAGIAN RAIHAN SUTAN: Validasi & Sistem Pembayaran (Kasir)
// =========================================================================
 void prosesKasir() {
    cout << "\n=========================================\n";
    cout << "              PROSES KASIR               \n";
    cout << "=========================================\n";
    
    if (isQueueEmpty()) {
        cout << "Antrean kosong! Tidak ada pembeli yang bisa diproses.\n";
        return;
    }

    // Intip data terdepan dari antrean
    ElemenQueue* prosesNode = antreanSistem.front;
    int idxKonser = prosesNode->idKonserDiincar - 1; // Index array adalah ID dikurang 1

    // 1. Validasi: Apakah ID Konser ada?
    if (idxKonser < 0 || idxKonser >= MAX_KONSER) {
        cout << "[Gagal] ID Konser tidak valid. Pembeli dibatalkan.\n";
    }
    // 2. Validasi: Apakah kuota cukup?
    else if (daftarKonser[idxKonser].kuota < prosesNode->jumlahTiket) {
        cout << "[Gagal] Kuota tidak cukup untuk pesanan Sdr/i " << prosesNode->namaPembeli 
             << ". Sisa kuota: " << daftarKonser[idxKonser].kuota << " kursi.\n";
    } 
    // 3. Eksekusi Pembayaran Sukses
    else {
        double pajak = 0.10; // Pajak 10%
        double hargaTiket = daftarKonser[idxKonser].harga * prosesNode->jumlahTiket;
        double totalAkhir = hargaTiket + (hargaTiket * pajak);

        // Kurangi kuota di array
        daftarKonser[idxKonser].kuota -= prosesNode->jumlahTiket;

        // Simpan ke Linked List (memanggil fungsi buatan Faiz)
        tambahRiwayat(prosesNode->namaPembeli, daftarKonser[idxKonser].namaKonser, prosesNode->jumlahTiket, totalAkhir);

        cout << "[Sukses] Pembayaran atas nama " << prosesNode->namaPembeli << " berhasil diproses!\n";
        cout << "Total Bayar (termasuk pajak 10%): Rp " << fixed << setprecision(0) << totalAkhir << endl;
    }

    // Dequeue: Keluarkan pembeli yang sudah diproses dari antrean
    antreanSistem.front = antreanSistem.front->next;
    if (antreanSistem.front == nullptr) {
        antreanSistem.rear = nullptr; // Reset rear jika antrean jadi kosong
    }
    delete prosesNode; // Bersihkan memori
}

// =========================================================================
// BAGIAN ARSYIKA FADLIKA: Searching & Sorting
// =========================================================================
void menuSearchingSorting() {
    int subPilihan;
    cout << "\n=========================================\n";
    cout << "         MENU SEARCHING & SORTING        \n";
    cout << "=========================================\n";
    cout << "1. Cari Transaksi Berdasarkan ID (Linear Search)\n";
    cout << "2. Urutkan Konser Berdasarkan Harga (Sorting Array)\n";
    cout << "3. Kembali ke Menu Utama\n";
    cout << "-----------------------------------------\n";
    cout << "Pilih sub-menu (1-3): ";
    cin >> subPilihan;
    
    switch(subPilihan) {
        case 1:
            cout << "\n[Fitur Cari Transaksi - Bagian Arsyika]\n";
            // NOTE: Cari ID Transaksi dengan menelusuri Linked List 'headRiwayat'.
            break;
        case 2:
            cout << "\n[Fitur Urutkan Konser - Bagian Arsyika]\n";
            // NOTE: Urutkan array 'daftarKonser' (misal: ascending/descending harga).
            // Setelah di-sort, panggil fungsi lihatKonser() untuk melihat hasilnya.
            break;
        case 3:
            return;
        default:
            cout << "Pilihan tidak valid!\n";
    }
}


// =========================================================================
// BAGIAN MARSHA OLIVIA: Main System & UI Console (Menu Navigasi Utama)
// =========================================================================
int main() {
    inisialisasiDummyData();
    int pilihan;
    
    do {
        cout << "\n=========================================\n";
        cout << "    SISTEM PEMESANAN TIKET KONSER CLI   \n";
        cout << "=========================================\n";
        cout << "1. Lihat Jadwal Konser (Array)\n";
        cout << "2. Masuk Antrean Pembelian (Queue)\n";
        cout << "3. Proses Kasir / Pembayaran (Validasi)\n";
        cout << "4. Lihat Riwayat Transaksi (Linked List)\n";
        cout << "5. Fitur Pencarian & Pengurutan (Search/Sort)\n"; // Ditambahkan agar pengerjaan Arsyika bisa diakses
        cout << "6. Keluar\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih menu (1-6): ";
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
                menuSearchingSorting();
                break;
            case 6:
                cout << "\nProgram SELESAI. Terima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 1-6.\n";
        }
        
        if (pilihan != 6) {
            cout << "\nTekan Enter untuk kembali ke MENU UTAMA...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 6);
    
    return 0;
}
