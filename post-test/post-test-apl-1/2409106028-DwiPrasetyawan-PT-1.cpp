#include <iostream> 
using namespace std;

int main() {
    string username = "dwi", password = "028";
    int coba = 3, pilihan;
    float suhu;

    cout << "=======================================" << endl;
    cout << "|            KONVERSI SUHU            |" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    while (coba != 0) {
        cout << "====== LOGIN ======" << endl;
        cout << "Masukkan Nama : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;

        if (username == "dwi" && password == "028") {
            cout << "\nLogin Berhasil! Selamat datang, " << username << "!\n" << endl;
            break; // Keluar dari loop jika login berhasil
        } else {
            coba--;
            cout << "\nLogin Gagal! Nama atau password salah." << endl;
            cout << "Percobaan tersisa: " << coba << endl << endl; // double endl karena tidak berakhiran string
        }
    }
    if (coba == 0) {
        cout << "=========================================================" << endl;
        cout << "| Terlalu banyak percobaan, Keluar dari program . . .   |" << endl;
        cout << "=========================================================" << endl;
        return 0; // Force Exit Program
    }

    // Do-While Looping untuk perulangan terus menerus
    do {
        cout << "=============================================" << endl;
        cout << "|             MENU KONVERSI SUHU            |" << endl;
        cout << "=============================================" << endl;
        cout << "| 1. Celcius ke Reamur, Fahrenheit, Kelvin  |" << endl;
        cout << "| 2. Reamur ke Celcius, Fahrenheit, Kelvin  |" << endl;
        cout << "| 3. Fahrenheit ke Celcius, Reamur, Kelvin  |" << endl;
        cout << "| 4. Kelvin ke Celcius, Reamur, Fahrenheit  |" << endl;
        cout << "| 5. Keluar Program                         |" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> pilihan;
        
        cout << endl;
        // niat hati mau pakai switch-case tapi ternyata gagal '._.)
        if (pilihan == 1) {
            cout << "Masukkan suhu dalam Celcius: ";
            cin >> suhu;
            cout << endl;
            cout << "===============================================" << endl;
            cout << "| Reamur     : " << suhu * 4 / 5 << endl;
            cout << "| Fahrenheit : " << (suhu * 9 / 5) + 32 << endl;
            cout << "| Kelvin     : " << suhu + 273.15 << endl;
            cout << "===============================================" << endl;}
        else if (pilihan == 2) {
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> suhu;
            cout << endl;
            cout << "===============================================" << endl;
            cout << "| Celcius    : " << suhu * 5 / 4 << endl;
            cout << "| Fahrenheit : " << (suhu * 9 / 4) + 32 << endl;
            cout << "| Kelvin     : " << (suhu * 5 / 4) + 273.15 << endl;
            cout << "===============================================" << endl;}
        else if (pilihan == 3) {
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> suhu;
            cout << endl;
            cout << "===============================================" << endl;
            cout << "| Celcius    : " << (suhu - 32) * 5 / 9 << endl;
            cout << "| Reamur     : " << (suhu - 32) * 4 / 9 << endl;
            cout << "| Kelvin     : " << (suhu - 32) * 5 / 9 + 273.15 << endl;
            cout << "===============================================" << endl;}
        else if (pilihan == 4) {
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> suhu;
            cout << endl;
            cout << "===============================================" << endl;
            cout << "| Celcius    : " << suhu - 273.15 << endl;
            cout << "| Reamur     : " << (suhu - 273.15) * 4 / 5 << endl;
            cout << "| Fahrenheit : " << (suhu - 273.15) * 9 / 5 + 32 << endl;
            cout << "===============================================" << endl;}
        else if (pilihan == 5) {//sifat Do-While masih berjalan tapi perulangannya telah nonaktif
            cout << endl;
            cout << "==============================================" << endl;
            cout << "|  Terima kasih telah menggunakan program!   |" << endl;
            cout << "==============================================" << endl;}
        else {
            cout << "Pilihan tidak valid, coba lagi.\n";}
        cout << endl; 
    } while (pilihan != 5);

    return 0;
}
