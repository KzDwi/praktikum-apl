#include <iostream>
using namespace std;
// using std::cout; biar ga bentrok sama namespace lainnya

// g++ namefile.cpp
// ./a.exe
// g++ namefile.cpp


int main(int argc, char const *argv) {
//     int number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
//     int totalByte = sizeof(number);
//     int singleByte = sizeof(number[4]);
//     int panjangArray = sizeof(number) / sizeof(number[0]);
//     // int panjangArray2 = size(number);
    
// for (int i : number) {
//     cout << "Nilai Array : " << i << endl;
// }
// int number11[9] = {1, 2, 4};
// for(int i = 1; i < 3; i++){
//     number11[i] = number11[i+1];
// }

//     int number1[9] = {1, 2};
//     number1[1] = 5;
//     number1[2] = 10;
//     for(int i : number1){
//         cout << "Nilai Array : " << i << endl;
//     }
int arr[3][3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };
    
    cout << arr[0][2][1] << endl;
    // for (int i = 0; i < panjangArray; i++){

    //     cout << "Nilai array :" << number[i] << endl;
    
    // }
    // iostream untuk I/O seeperti cin, cout, cerr<error>,





    return 0;
}