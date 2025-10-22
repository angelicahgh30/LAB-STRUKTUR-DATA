#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  // Jumlah elemen pada subarray kiri
    int n2 = right - mid;     // Jumlah elemen pada subarray kanan

    vector<int> L(n1), R(n2); // Membuat dua vektor sementara untuk menampung data kiri dan kanan

    // Menyalin data ke subarray kiri dan kanan
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;   // Indeks awal subarray kiri
    int j = 0;   // Indeks awal subarray kanan
    int k = left; // Indeks awal gabungan di array utama

    // Menggabungkan kedua subarray dengan membandingkan elemen satu per satu
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen yang belum diproses dari subarray kiri (jika ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Menyalin sisa elemen yang belum diproses dari subarray kanan (jika ada)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama untuk melakukan Merge Sort secara rekursif
void mergeSort(vector<int>& arr, int left, int right) {
   
    // Kondisi dasar: jika indeks kiri >= kanan, berarti hanya ada satu elemen (sudah terurut)
    if (left >= right)
        return;

    // Menentukan titik tengah untuk membagi array
    int mid = left + (right - left) / 2;

    // Memanggil mergeSort secara rekursif pada bagian kiri dan kanan
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
   
    // Menggabungkan kedua bagian yang sudah terurut
    merge(arr, left, mid, right);
}

// Fungsi untuk menampilkan elemen array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    // Meminta pengguna memasukkan jumlah elemen yang akan diurutkan
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    // Meminta pengguna memasukkan setiap elemen data
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    // Menampilkan data sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    // Melakukan pengurutan menggunakan algoritma Merge Sort
    mergeSort(data, 0, n - 1);
   
    // Menampilkan hasil setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0; 
}