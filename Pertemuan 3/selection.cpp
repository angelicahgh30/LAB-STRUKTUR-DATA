// Program Selection Sort
#include <iostream>
using namespace std;

int main() {
    system("cls"); 
    int n;
    // Meminta pengguna untuk memasukkan jumlah elemen data
    cout << "Masukkan jumlah elemen data: "; 
    cin >> n;

    int data[n];
    // Input setiap elemen data dari pengguna
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen-elemen data: " << i + 1 << " : "; 
        cin >> data[i];
    }

    // Proses pengurutan menggunakan algoritma Selection Sort (dari terbesar ke terkecil)
    for (int i = 0; i < n - 1; i++){
        int max_indeks = i; // Asumsikan elemen pertama sebagai nilai maksimum sementara

        // Mencari elemen terbesar di antara elemen yang tersisa
        for (int j = i + 1; j < n; j++){
            if(data[j] > data[max_indeks]){
                max_indeks = j; // Simpan indeks elemen terbesar yang ditemukan
            }
        }
        
        // Menukar elemen terbesar dengan elemen pada posisi saat ini
        int temp = data[i];
        data[i] = data[max_indeks];
        data[max_indeks] = temp;
    }
    
    // Menampilkan hasil akhir setelah data diurutkan dari terbesar ke terkecil
    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0; 
}