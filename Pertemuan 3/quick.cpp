#include <iostream>
using namespace std;

// Fungsi untuk menukar posisi dua elemen dalam array
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk melakukan pembagian (partition) dalam Quick Sort
int partition(int arr[], int low, int high){
    int pivot = arr[low];  // Menetapkan elemen pertama sebagai pivot
    int i = low;
    int j = high;

    while(true){
        // Mencari elemen di sebelah kiri yang lebih besar dari pivot
        while (i <= high && arr[i] <= pivot){
            i++;
        }
        // Mencari elemen di sebelah kanan yang lebih kecil dari pivot
        while (i >= low && arr[j] > pivot){
            j--;
        }
        
        // Jika indeks i melewati j, hentikan proses pertukaran
        if(i > j){
            break;
        }
        // Tukar posisi elemen yang tidak sesuai
        swap(arr[i], arr[j]);
    }

    // Tempatkan pivot pada posisi yang benar
    swap(arr[low], arr[j]);
    return j; // Mengembalikan indeks posisi akhir pivot
}

// Fungsi rekursif untuk menerapkan Quick Sort pada setiap bagian array
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high); // Mendapatkan posisi pivot

        // Melakukan Quick Sort pada bagian kiri dan kanan pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    // Meminta pengguna memasukkan jumlah data
    cout << "Masukkan jumlah elemen data: "; 
    cin >> n;

    int data[n];
    // Input elemen-elemen data dari pengguna
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Memanggil fungsi Quick Sort untuk mengurutkan data secara ascending
    quickSort(data, 0, n - 1);

    // Menampilkan hasil akhir setelah data diurutkan
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0; 
}