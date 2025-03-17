#include <iostream>
using namespace std;

int main() {
cout << "Hello, World! ";
cout << "Belajar C++ sangat seru😀";

string nama = "Dwi";
int umur = 19;
cout << "Halo, nama saya " << nama << " dan umur saya " << umur << "tahun";

//Tipe data Primitif
int sumbuY = -45;
float berat_badan = 48;
double tinggi_badan = 165.5;
char jenis_kelamin = 'L';
bool is_menikah = false;

cout << "Size of char: " << sizeof(char) << endl;
cout << "Size of int: " << sizeof(int) << endl;
cout << "Size of float: " << sizeof(float) << endl;
cout << "Size of double: " << sizeof(double) << endl;
cout << "Size of long: " << sizeof(long);

// Kolektif
int angka[5] = {1, 2, 3, 4, 5};

// abstrak
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
    };

Mahasiswa mhs = {"Raana", 20, 3.5};

// operasi
int a, b;
cout << "Masukkan nilai a: ";
cin >> a;
cout << "Masukkan nilai b: ";
cin >> b;
// Penjumlahan
a += b;
cout << "Hasil penjumlahan: " << a << endl;
// Pengurangan
a -= b;
cout << "Hasil pengurangan: " << a << endl;
// Perkalian
a *= b;
cout << "Hasil perkalian: " << a << endl;
// Pembagian
a /= b;
cout << "Hasil pembagian: " << a << endl;
// Modulus
a %= b;
cout << "Hasil modulus: " << a << endl;
cout << "Apakah a sama dengan b? " << (a == b) << endl;
// Tidak sama dengan
cout << "Apakah a tidak sama dengan b? " << (a != b) << endl;
// Lebih besar dari
cout << "Apakah a lebih besar dari b? " << (a > b) << endl;
// Lebih kecil dari
cout << "Apakah a lebih kecil dari b? " << (a < b) << endl;
// Lebih besar sama dengan
cout << "Apakah a lebih besar sama dengan b? " << (a >= b) << endl;
// Lebih kecil sama dengan
cout << "Apakah a lebih kecil sama dengan b? " << (a <= b) << endl;
// Dan
cout << "Apakah a lebih besar dari 0 dan b lebih kecil dari 10? " <<
(a > 0 && b < 10) << endl;
// Atau
cout << "Apakah a lebih besar dari 0 atau b lebih kecil dari 10? " <<
(a > 0 || b < 10) << endl;
// Tidak
cout << "Apakah a lebih besar dari 0? " << !a << endl;

// tenary
bool sudahMenikah = true;
string status = sudahMenikah ? "Sudah menikah" : "Belum menikah";
cout << status << endl;

// increment dan decrement
int z = 1;
cout << "Sebelum increment " << z << endl;
cout << "Increment di depan " << ++z << ", sudah bertambah" << endl;
cout << "Increment di belakang " << z++ << ", belum bertambah" << endl;
cout << "Hasil akhir " << z << endl;

// percabangan
bool malas = false;
bool lapar = true;
if (malas) {
cout << "Saya scroll fesbuk";
} else if (lapar) {
cout << "Saya makan";
} else {
cout << "Saya belajar";
}
return 0;

//switch casae
int nilaiUjian;
cout << "Masukkan nilai: ";
cin >> nilaiUjian;
switch(nilaiUjian) {
case 100:
cout << "Nilai sempurna";
break;
case 90:
cout << "Nilai sangat baik";
break;
case 80:
cout << "Nilai baik";
break;
case 70:
cout << "Nilai cukup";
break;
case 60:
cout << "Nilai kurang";
break;
default:
cout << "Nilai tidak";
}

//nested if
if (malas) {
    if (lapar) {
    cout << "Saya makan";
    }
    } else {
    cout << "Gak ngapa-ngapain";
    }

// tenary operator
string aktivitas = (malas) ? "Scroll fesbuk" : "Belajar";
cout << aktivitas;

//for
for (int i = 0; i < 5; i++) {
    cout << i << endl;
    }

//while
int i = 0;
while (i < 5) {
cout << i << endl;
i++;
}

//do while
do {
    cout << i << endl;
    i++;
    } while (i < 5);

//perulangan for each
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
cout << x << endl;
}
return 0;
}