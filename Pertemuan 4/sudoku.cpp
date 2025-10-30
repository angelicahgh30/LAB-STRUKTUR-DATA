/*
Nama: Angelica Happy Grace Harianja
NIM: 241401130
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan papan Sudoku ke layar
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " "; // spasi tambahan setiap 3 kolom
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl; // baris kosong setiap 3 baris
        }
    }
}

// Fungsi untuk memeriksa apakah angka 'num' valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa apakah angka sudah ada di baris atau kolom
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3 tempat posisi tersebut berada
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true; // valid jika tidak ditemukan angka yang sama
}

// Fungsi utama untuk menyelesaikan Sudoku (menggunakan rekursi dan backtracking)
bool solveSudoku(vector<vector<int>>& board) { 
   
    // Mencari sel kosong di papan
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            // Jika ditemukan sel kosong
            if (board[row][col] == 0) {

                // Coba isi angka dari 1 sampai 9
                for (int num = 1; num <= 9; num++) {

                    // Periksa apakah angka valid menggunakan fungsi isValid()
                    if (isValid(board, row, col, num)) {

                        // Isi sel dengan angka yang valid
                        board[row][col] = num;

                        // Lanjutkan rekursi untuk sel berikutnya
                        if (solveSudoku(board)) return true;

                        // Jika gagal, hapus angka (kembali kosong) → backtracking
                        board[row][col] = 0;
                    }
                }

                // Jika semua angka 1–9 tidak cocok, kembali ke langkah sebelumnya
                return false;
            }
        }
    }

    // Jika tidak ada sel kosong lagi, berarti Sudoku sudah terselesaikan
    return true;
}

int main() {
    // Inisialisasi papan Sudoku (0 menandakan sel kosong)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    // Jalankan fungsi pemecah Sudoku
    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}
