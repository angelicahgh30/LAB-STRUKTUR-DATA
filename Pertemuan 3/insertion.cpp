// Program Insertion Sort
#include <iostream>
using namespace std;

int main() {
    int n;
    // Meminta pengguna untuk memasukkan jumlah elemen yang akan diurutkan
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    // Meminta pengguna memasukkan nilai setiap elemen data
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Proses pengurutan data menggunakan metode Insertion Sort (ascending)
    for(int i = 1; i < n; i++){
        int key = data[i];     // Menyimpan elemen saat ini sebagai kunci
        int j = i - 1;         // Indeks elemen sebelumnya

        // Memindahkan elemen yang lebih besar dari kunci ke posisi berikutnya
        while(j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;     // Menempatkan kunci pada posisi yang tepat
    }

    // Menampilkan hasil data setelah diurutkan dari terkecil hingga terbesar
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0; 
}