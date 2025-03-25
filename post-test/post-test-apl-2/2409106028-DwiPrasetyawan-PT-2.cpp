#include <iostream>
using namespace std;

#define MAX_Y 5 // Jumlah baris parkiran untuk mobil dan motor (Perumpamaan Y karen bergerak ke atas dan bawah)
#define MAX_X 5 // Jumlah kolom parkiran untuk mobil dan motor (Perumpamaan X karena bergerak ke kanan dan kiri)
// Menggunakan Perumpamaan X dan Y karena saya kadang suka lupa mana yang baris dan kolom TwT

int main() {
    string username, password;
    int coba = 3;
    
    while (coba != 0) {
        cout << "====== LOGIN ======" << endl;
        cout << "Masukkan Nama : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;

        if (username == "dwi" && password == "028") {
            cout << "\nLogin Berhasil! Selamat datang, " << username << "!\n" << endl;
            break;
        } else {
            coba--;
            cout << "\nLogin Gagal! Nama atau password salah." << endl;
            cout << "Percobaan tersisa: " << coba << endl << endl;
        }
    }
    
    if (coba == 0) {
        cout << "=========================================================" << endl;
        cout << "| Terlalu banyak percobaan, Keluar dari program . . .   |" << endl;
        cout << "=========================================================" << endl;
        return 0;
    }
    
    string parkiran_mobil[MAX_Y][MAX_X] = {};
    string parkiran_motor[MAX_Y][MAX_X] = {};
    string owner_mobil[MAX_Y][MAX_X] = {};
    string owner_motor[MAX_Y][MAX_X] = {};
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
        if (pilihan == 1) {
            int Y, X;
            string jenis;
            cout << "Masukkan jenis kendaraan (mobil/motor): ";
            cin >> jenis;
            cout << "Masukkan baris parkiran (1-" << MAX_Y << "): ";
            cin >> Y;
            cout << "Masukkan kolom parkiran (1-" << MAX_X << "): ";
            cin >> X;
            
            if (Y > 0 && Y <= MAX_Y && X > 0 && X <= MAX_X) {
                if (jenis == "mobil" && parkiran_mobil[Y - 1][X - 1] == "") {
                    cout << "Masukkan Plat Nomor Kendaraan : ";
                    cin >> parkiran_mobil[Y - 1][X - 1];
                    cout << "Masukkan Nama Pemilik : ";
                    cin >> owner_mobil[Y - 1][X - 1];
                    cout << "Mobil berhasil ditambahkan ke slot parkiran.\n";
                } else if (jenis == "motor" && parkiran_motor[Y - 1][X - 1] == "") {
                    cout << "Masukkan Plat Nomor Kendaraan : ";
                    cin >> parkiran_motor[Y - 1][X - 1];
                    cout << "Masukkan Nama Pemilik : ";
                    cin >> owner_motor[Y - 1][X - 1];
                    cout << "Motor berhasil ditambahkan ke slot parkiran.\n";
                } else {
                    cout << "Slot parkiran sudah terisi atau jenis kendaraan tidak valid!\n";
                }
            } else {
                cout << "Nomor slot tidak valid!\n";
            }
        } else if (pilihan == 2) {
            cout << "\n=========================================================" << endl;
            cout << "\nTampilan Parkiran Mobil:\n";
            for (int i = 0; i < MAX_Y; i++) {
                cout << "| ";
                for (int j = 0; j < MAX_X; j++) {
                    if (parkiran_mobil[i][j] == "") {
                        cout << "[Kosong] ";
                    } else {
                        cout << "[" << parkiran_mobil[i][j] << " - " << owner_mobil[i][j] << "] ";
                    }
                }
                cout << endl;
            }
            cout << "\n=========================================================" << endl;
            cout << "\nTampilkan Parkiran Motor:\n";
            for (int i = 0; i < MAX_Y; i++) {
                cout << "| ";
                for (int j = 0; j < MAX_X; j++) {
                    if (parkiran_motor[i][j] == "") {
                        cout << "[Kosong] ";
                    } else {
                        cout << "[" << parkiran_motor[i][j] << " - " << owner_motor[i][j] << "] ";
                    }
                }
                cout << endl;
            }
            cout << "=========================================================" << endl;
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
                    if (parkiran_mobil[asal_Y - 1][asal_X - 1] != "" && parkiran_mobil[tujuan_Y - 1][tujuan_X - 1] == "") {
                        parkiran_mobil[tujuan_Y - 1][tujuan_X - 1] = parkiran_mobil[asal_Y - 1][asal_X - 1];
                        owner_mobil[tujuan_Y - 1][tujuan_X - 1] = owner_mobil[asal_Y - 1][asal_X - 1];
                        parkiran_mobil[asal_Y - 1][asal_X - 1] = "";
                        owner_mobil[asal_Y - 1][asal_X - 1] = "";
                        cout << "Kendaraan berhasil dipindahkan.\n";
                    } else {
                        cout << "Slot asal kosong atau slot tujuan sudah terisi!\n";
                    }
                } else if (jenis == "motor") {
                    if (parkiran_motor[asal_Y - 1][asal_X - 1] != "" && parkiran_motor[tujuan_Y - 1][tujuan_X - 1] == "") {
                        parkiran_motor[tujuan_Y - 1][tujuan_X - 1] = parkiran_motor[asal_Y - 1][asal_X - 1];
                        owner_motor[tujuan_Y - 1][tujuan_X - 1] = owner_motor[asal_Y - 1][asal_X - 1];
                        parkiran_motor[asal_Y - 1][asal_X - 1] = "";
                        owner_motor[asal_Y - 1][asal_X - 1] = "";
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
            cout << "Masukkan jenis kendaraan yang ingin dihapus (mobil/motor): ";
            cin >> jenis;
            cout << "Masukkan baris parkiran: ";
            cin >> Y;
            cout << "Masukkan kolom parkiran: ";
            cin >> X;

            if (Y > 0 && Y <= MAX_Y && X > 0 && X <= MAX_X) {
                if (jenis == "mobil" && parkiran_mobil[Y - 1][X - 1] != "") {
                    parkiran_mobil[Y - 1][X - 1] = "";
                    owner_mobil[Y - 1][X - 1] = "";
                    cout << "Data kendaraan mobil berhasil dihapus.\n";
                } else if (jenis == "motor" && parkiran_motor[Y - 1][X - 1] != "") {
                    parkiran_motor[Y - 1][X - 1] = "";
                    owner_motor[Y - 1][X - 1] = "";
                    cout << "Data kendaraan motor berhasil dihapus.\n";
                } else {
                    cout << "Slot parkiran sudah kosong atau jenis kendaraan tidak valid!\n";
                }
            } else {
                cout << "Nomor slot tidak valid!\n";
            }
        } else if (pilihan == 5) {
            cout << "| Terima kasih telah menggunakan program ini! |" << endl;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
