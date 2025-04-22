#include <iostream>
using namespace std;

#define MAX_Y 5 // Jumlah baris parkiran untuk mobil dan motor
#define MAX_X 5 // Jumlah kolom parkiran untuk mobil dan motor
#define MAX_USERS 10 // Jumlah maksimal pengguna yang dapat dibuat

struct Kendaraan {
    string platNomor;
    string pemilik;
};

struct User {
    string username;
    string password;
};

User  users[MAX_USERS] = { {"dwi", "028"} };
Kendaraan parkiranMobil[MAX_Y][MAX_X];
Kendaraan parkiranMotor[MAX_Y][MAX_X];
int jumlahUser  = 1;
bool ulang = true;

void daftarUser ();
void loginUser ();
void addKendaraan(string jenis, int Y, int X);
void addKendaraan();
string lihatParkir();
void pindahKendaraan();
void hapusKendaraan(Kendaraan *kendaraan);
void menuParkir();
void mainMenu();

void daftarUser () {
    if (jumlahUser  < MAX_USERS) {
        cout << "====== DAFTAR ======" << endl;
        cout << "Masukkan Nama: ";
        cin >> users[jumlahUser ].username;
        cout << "Masukkan Password (3 Angka belakang NIM): ";
        cin >> users[jumlahUser ].password;
        jumlahUser ++;
        cout << "Registrasi berhasil! Silakan login.\n";
    } else {
        cout << "Pendaftaran penuh!\n";
    }
}

void loginUser () {
    int coba = 3;
    string username, password;
    bool loggedIn = false;

    while (coba > 0 && !loggedIn) {
        cout << "====== LOGIN ======" << endl;
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        for (int i = 0; i < jumlahUser ; i++) {
            if (users[i].username == username && users[i].password == password) {
                loggedIn = true;
                cout << "\nLogin Berhasil! Selamat datang, " << username << "!\n";
                menuParkir();
                break;
            }
        }

        if (!loggedIn) {
            coba--;
            cout << "\nLogin Gagal! Nama atau password salah." << endl;
            cout << "Percobaan tersisa: " << coba << endl << endl;
        }
    }
    if (coba == 0) {
        cout << "Terlalu banyak percobaan, Keluar dari program . . .\n";
        ulang = false;
        return;
    }
}

void addKendaraan(string jenis, int Y, int X) {
    if (Y > 0 && Y <= MAX_Y && X > 0 && X <= MAX_X) {
        if (jenis == "mobil" && parkiranMobil[Y - 1][X - 1].platNomor == "") {
            cout << "Masukkan Plat Nomor: ";
            cin >> parkiranMobil[Y - 1][X - 1].platNomor;
            cout << "Masukkan Nama Pemilik: ";
            cin >> parkiranMobil[Y - 1][X - 1].pemilik;
        } else if (jenis == "motor" && parkiranMotor[Y - 1][X - 1].platNomor == "") {
            cout << "Masukkan Plat Nomor: ";
            cin >> parkiranMotor[Y - 1][X - 1].platNomor;
            cout << "Masukkan Nama Pemilik: ";
            cin >> parkiranMotor[Y - 1][X - 1].pemilik;
        } else {
            cout << "Slot sudah terisi atau jenis kendaraan tidak valid!\n";
        }
    } else {
        cout << "Nomor slot tidak valid!\n";
    }
}

void addKendaraan() {
    string jenis;
    int Y, X;
    cout << "Masukkan jenis kendaraan (mobil/motor): ";
    cin >> jenis;
    cout << "Masukkan baris parkiran (1-" << MAX_Y << "): ";
    cin >> Y;
    cout << "Masukkan kolom parkiran (1-" << MAX_X << "): ";
    cin >> X;

    addKendaraan(jenis, Y, X);
}

string lihatParkir() {
    string parkiran;

    parkiran += "\nTampilan Parkiran Mobil:\n";
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (parkiranMobil[i][j].platNomor == "") {
                parkiran += "[Kosong] ";
            } else {
                parkiran += "[" + parkiranMobil[i][j].platNomor + " - " + parkiranMobil[i][j].pemilik + "] ";
            }
        }
        parkiran += "\n";
    }

    parkiran += "\nTampilan Parkiran Motor:\n";
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (parkiranMotor[i][j].platNomor == "") {
                parkiran += "[Kosong] ";
            } else {
                parkiran += "[" + parkiranMotor[i][j].platNomor + " - " + parkiranMotor[i][j].pemilik + "] ";
            }
        }
        parkiran += "\n";
    }

    return parkiran;
}

void pindahKendaraan() {
    int asal_Y, asal_X, tujuan_Y, tujuan_X;
    string jenis;
    cout << "Masukkan jenis kendaraan yang ingin dipindahkan (mobil/motor): ";
    cin >> jenis;
    cout << "Masukkan baris asal parkiran: ";
    cin >> asal_Y;
    cout << "Masukkan kolom asal parkiran: ";
    cin >> asal_X;
    cout << "Masukkan baris tujuan parkiran: ";
    cin >> tujuan_Y;
    cout << "Masukkan kolom tujuan parkiran: ";
    cin >> tujuan_X;

    if (asal_Y > 0 && asal_Y <= MAX_Y && asal_X > 0 && asal_X <= MAX_X &&
        tujuan_Y > 0 && tujuan_Y <= MAX_Y && tujuan_X > 0 && tujuan_X <= MAX_X) {
        
        // Pointer untuk slot asal dan tujuan
        Kendaraan* asalKendaraan = &parkiranMobil[asal_Y - 1][asal_X - 1];
        Kendaraan* tujuanKendaraan = &parkiranMobil[tujuan_Y - 1][tujuan_X - 1];

        if (jenis == "mobil") {
            asalKendaraan = &parkiranMobil[asal_Y - 1][asal_X - 1];
            tujuanKendaraan = &parkiranMobil[tujuan_Y - 1][tujuan_X - 1];
        } else if (jenis == "motor") {
            asalKendaraan = &parkiranMotor[asal_Y - 1][asal_X - 1];
            tujuanKendaraan = &parkiranMotor[tujuan_Y - 1][tujuan_X - 1];
        } else {
            cout << "Jenis kendaraan tidak valid!\n";
            return;
        }
        // Periksa ketersediaan slot
        if (asalKendaraan->platNomor != "" && tujuanKendaraan->platNomor == "") 
            {
            // Pemindahan posisi parkir
            *tujuanKendaraan = *asalKendaraan; // Salin data dengan pointer
            asalKendaraan->platNomor = ""; // Kosongkan posisi awal
            asalKendaraan->pemilik = ""; // Kosongkan pemilik
            cout << "Kendaraan berhasil dipindahkan.\n";
        } else {
            cout << "Slot asal kosong atau slot tujuan sudah terisi!\n";
        }
    } else {
        cout << "Nomor slot tidak valid!\n";
    }
}

void hapusKendaraan(Kendaraan* kendaraan) 
{ // parameter dereference
    if (kendaraan != nullptr) {
        kendaraan->platNomor = "";
        kendaraan->pemilik = "";
        cout << "Kendaraan berhasil dihapus.\n";
    } else {
        cout << "Kendaraan tidak ditemukan!\n";
    }
}

void hapusKendaraan() {
    int Y, X;
    string jenis;
    cout << "Masukkan jenis kendaraan (mobil/motor): ";
    cin >> jenis;
    cout << "Masukkan baris parkiran: ";
    cin >> Y;
    cout << "Masukkan kolom parkiran: ";
    cin >> X;

    if (Y > 0 && Y <= MAX_Y && X > 0 && X <= MAX_X) {
        if (jenis == "mobil" && parkiranMobil[Y - 1][X - 1].platNomor != "") {
            hapusKendaraan(&parkiranMobil[Y - 1][X - 1]); // Menggunakan address-of
        } else if (jenis == "motor" && parkiranMotor[Y - 1][X - 1].platNomor != "") {
            hapusKendaraan(&parkiranMotor[Y - 1][X - 1]); // Menggunakan address-of
        } else {
            cout << "Slot kosong atau jenis kendaraan tidak valid!\n";
        }
    } else {
        cout << "Nomor slot tidak valid!\n";
    }
}

void menuParkir() {
    int pilihan;
    do {
        cout << "\n==================================" << endl;
        cout << "| Menu Manajemen Parkir Mall" << endl;
        cout << "| 1. Tambah Kendaraan ke Slot" << endl;
        cout << "| 2. Tampilkan Slot Parkir" << endl;
        cout << "| 3. Ubah Kendaraan di Slot" << endl;
        cout << "| 4. Hapus Kendaraan dari Slot" << endl;
        cout << "| 5. Keluar" << endl;
        cout << "==================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                addKendaraan(); break;
            case 2: 
                cout << lihatParkir(); break;
            case 3: 
                pindahKendaraan(); break;
            case 4: 
                hapusKendaraan(); break;
            case 5: 
                cout << "| Terima kasih telah menggunakan program ini! |" << endl; break;
            default: 
                cout << "Pilihan tidak valid!\n"; break;
        }
    } while (pilihan != 5);
}

void mainMenu() {
    int pilihan;
    while (ulang) {
        cout << "====== MENU ======" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "==================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: daftarUser (); break;
            case 2: loginUser (); break;
            case 3: cout << "| Terima kasih telah menggunakan program ini! |" << endl; return;
            default: cout << "Pilihan tidak valid!\n"; break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}