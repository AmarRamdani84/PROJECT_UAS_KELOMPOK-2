#include <iostream>
#include <string>

using namespace std;

struct Konser {
    int id;
    string namaKonser;
    double harga;
    int kuota;
};

const int MAX_KONSER = 3; 
Konser daftarKonser[MAX_KONSER];

void inisialisasiDummyData() {
    daftar_konser[0] = {1, "Coldplay Live in Jakarta", 1500000, 50};
    daftarKonser[1] = {2, "NIKI Buzz World Tour", 850000, 30};
    daftarKonser[2] = {3, "Tulus Tur Manusia", 500000, 5};
}

void lihatKonser() {
    cout << "\n=== DAFTAR KONSER ===\n";
    for (i = 0; i < MAX_KONSER; i++) {
        cout << daftarKonser[i].namaKonser << " - Rp" << daftarKonser[i].harga << endl;
    }
}

int main() {
    inisialisasiDummyData();
   
    cout << "1. Lihat Konser\nPilih: ";
    int p;
    cin >> p;
    if(p == 1) {
        lihatKonser();
    }
    return 0;
}
