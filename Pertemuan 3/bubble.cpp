#include <iostream>
using namespace std;

int main() {
    int n;
    // Meminta pengguna untuk memasukkan banyaknya data yang akan diurutkan
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    // Meminta pengguna memasukkan setiap elemen data
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Proses pengurutan data menggunakan metode Bubble Sort (ascending)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisinya
            if(data[j] > data[j + 1]) {
                int temp = data [j];
                data [j] = data[j + 1];
                data [j + 1] = temp;
            }
        }
    }

    // Menampilkan hasil akhir data setelah diurutkan
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}