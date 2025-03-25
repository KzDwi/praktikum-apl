#include <iostream>
using namespace std;

#define MAX_Y 5 // Jumlah baris parkiran untuk mobil dan motor (Perumpamaan Y karen bergerak ke atas dan bawah)
#define MAX_X 5 // Jumlah kolom parkiran untuk mobil dan motor (Perumpamaan X karena bergerak ke kanan dan kiri)
// Menggunakan Perumpamaan X dan Y karena saya kadang suka lupa mana yang baris dan kolom TwT
#define MAX_USERS 10 // Jumlah maksimal pengguna yang dapat dibuat

struct Kendaraan {
    string platNomor;
    string pemilik;
};

struct User {
    string username;
    string password;
};

User users[MAX_USERS] = { {"dwi", "028"} } ;
Kendaraan parkiranMobil[MAX_Y][MAX_X];
Kendaraan parkiranMotor[MAX_Y][MAX_X];
int jumlahUser = 1;

int main() {
    int coba, pilihan;
    string username, password;
    bool loggedIn = false;
    
    while (!loggedIn) {
        cout << "====== MENU ======" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "==================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            if (jumlahUser < MAX_USERS) {
                cout << "====== DAFTAR ======" << endl;
                cout << "Masukkan Nama: ";
                cin >> users[jumlahUser].username;
                cout << "Masukkan Password (3 Angka belakang NIM): ";
                cin >> users[jumlahUser].password;
                jumlahUser++;
                cout << "Registrasi berhasil! Silakan login.\n";
            } else {
                cout << "Pendaftaran penuh!\n";
            }
        } else if (pilihan == 2) {
            coba = 3;
            while (coba > 0) {
                cout << "====== LOGIN ======" << endl;
                cout << "Masukkan Nama: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
                
                for (int i = 0; i < jumlahUser; i++) { //Pengecekan akun yang telah terdaftar
                    if (users[i].username == username && users[i].password == password) {
                        loggedIn = true;
                        cout << "\nLogin Berhasil! Selamat datang, " << username << "!\n";
                        break;
                    }
                }
                
                if (!loggedIn) {
                    coba--;
                    cout << "\nLogin Gagal! Nama atau password salah." << endl;
                    cout << "Percobaan tersisa: " << coba << endl << endl;
                } else {
                    break;
                }
            }
            if (coba == 0) {
                cout << "=========================================================" << endl;
                cout << "| Terlalu banyak percobaan, Keluar dari program . . .   |" << endl;
                cout << "=========================================================" << endl;
                return 0;
            }
        } else if (pilihan == 3) {
            cout << "| Terima kasih telah menggunakan program ini! |" << endl;
            return 0;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
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
        
        if (pilihan == 1) {
            string jenis;
            int Y, X;
            cout << "Masukkan jenis kendaraan (mobil/motor): ";
            cin >> jenis;
            cout << "Masukkan baris parkiran (1-" << MAX_Y << "): ";
            cin >> Y;
            cout << "Masukkan kolom parkiran (1-" << MAX_X << "): ";
            cin >> X;
            
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
        } else if (pilihan == 2) {
            cout << "\nTampilan Parkiran Mobil:\n";
            for (int i = 0; i < MAX_Y; i++) {
                for (int j = 0; j < MAX_X; j++) {
                    if (parkiranMobil[i][j].platNomor == "") {
                    cout << "[Kosong] ";
                    } else {
                        cout << "[" << parkiranMobil[i][j].platNomor << " - " << parkiranMobil[i][j].pemilik << "] ";
                    }
                }
                cout << endl;
            }
            for (int i = 0; i < MAX_Y; i++) {
                for (int j = 0; j < MAX_X; j++) {
                    if (parkiranMotor[i][j].platNomor == "") {
                    cout << "[Kosong] ";
                    } else {
                        cout << "[" << parkiranMotor[i][j].platNomor << " - " << parkiranMotor[i][j].pemilik << "] ";
                    }
                }
                cout << endl;
            }
        } else if (pilihan == 3) {
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
                if (jenis == "mobil") {
                    if (parkiranMobil[asal_Y - 1][asal_X - 1].platNomor != "" && 
                        parkiranMobil[tujuan_Y - 1][tujuan_X - 1].platNomor == "") {
                        parkiranMobil[tujuan_Y - 1][tujuan_X - 1] = parkiranMobil[asal_Y - 1][asal_X - 1]; //pemindahan posisi parkir
                        parkiranMobil[asal_Y - 1][asal_X - 1] = {}; //mengosongkan posisi awal
                        cout << "Kendaraan berhasil dipindahkan.\n";
                    } else {
                        cout << "Slot asal kosong atau slot tujuan sudah terisi!\n";
                    }
                } else if (jenis == "motor") {
                    if (parkiranMotor[asal_Y - 1][asal_X - 1].platNomor != "" && 
                        parkiranMotor[tujuan_Y - 1][tujuan_X - 1].platNomor == "") {
                        parkiranMotor[tujuan_Y - 1][tujuan_X - 1] = parkiranMotor[asal_Y - 1][asal_X - 1]; //pemindahan posisi parkir
                        parkiranMotor[asal_Y - 1][asal_X - 1] = {}; //mengosongkan posisi awal
                        cout << "Kendaraan berhasil dipindahkan.\n";
                    } else {
                        cout << "Slot asal kosong atau slot tujuan sudah terisi!\n";
                    }
                } else {
                    cout << "Jenis kendaraan tidak valid!\n";
                }
            } else {
                cout << "Nomor slot tidak valid!\n";
            }
        } else if (pilihan == 4) {
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
                    parkiranMobil[Y - 1][X - 1].platNomor = "";
                    parkiranMobil[Y - 1][X - 1].pemilik = "";
                } else if (jenis == "motor" && parkiranMotor[Y - 1][X - 1].platNomor != "") {
                    parkiranMotor[Y - 1][X - 1].platNomor = "";
                    parkiranMotor[Y - 1][X - 1].pemilik = "";
                } else {
                    cout << "Slot kosong atau jenis kendaraan tidak valid!\n";
                }
            } else {
                cout << "Nomor slot tidak valid!\n";
            }
        } else if (pilihan == 5) {
            cout << "| Terima kasih telah menggunakan program ini! |" << endl;
            loggedIn = false;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
}