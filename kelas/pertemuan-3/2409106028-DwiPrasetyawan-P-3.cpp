#include <iostream>
using namespace std;

// typedef struct {
//     string nama;
//     int nim;
//     string gender;
// }Mahasiswa;

struct tanggal {
    int hari,bulan,tahun;
};

struct Mahasiswa{
    string nama;
    int nim;
    string gender;
    tanggal tanggallahir;
};


int main() {
    Mahasiswa mhsbaru, mhslama;
    
    mhsbaru.nama = "Rangga";
    mhsbaru.nim = 43;
    mhsbaru.gender = "Lakik";
    mhsbaru.tanggallahir.hari = 3;
    mhsbaru.tanggallahir.bulan = 3;
    mhsbaru.tanggallahir.tahun = 2006;

    cout << mhsbaru.nama << endl;
    cout << mhsbaru.nim << endl;
    cout << mhsbaru.gender << endl;
    cout << "Tanggal Lahir : " << mhsbaru.tanggallahir.hari << "/" << mhsbaru.tanggallahir.bulan << "/" << mhsbaru.tanggallahir.tahun << endl;
    
    // cout << mhslama.nama << endl;
    // cout << mhslama.nim << endl;
    // cout << mhslama.gender << endl;

    string buah[5];
    Mahasiswa mhsAbadi[5];
    mhsAbadi[0].nama = "Ifnu";
    mhsAbadi[1].nama = "Amad";
    mhsAbadi[2].nama = "Washrul";
    mhsAbadi[3].nama = "Rava";
    
    for (int i = 0; i< sizeof(mhsAbadi); i++){
        cout << mhsAbadi[i].nama << endl;
    }
    return 0;
}