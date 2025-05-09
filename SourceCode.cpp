#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Data {
    string nama;
    int usia;
    string kota;
};

void printHorizontalLine(int colWidths[], int colCount, string leftCorner, string midCorner, string rightCorner) {
    cout << leftCorner;
    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < colWidths[i] + 2; j++) { // +2 untuk spasi padding
            cout << "?";
        }
        if (i < colCount - 1) cout << midCorner;
    }
    cout << rightCorner << endl;
}

int main() {
    vector<Data> data = {
        {"Andi", 25, "Jakarta"},
        {"Budi", 30, "Bandung"},
        {"Citra", 22, "Surabaya"},
        {"Dewi", 28, "Yogyakarta"}
    };

    int colWidths[] = { 15, 8, 15 };
    int colCount = 3;

    // Header Atas
    printHorizontalLine(colWidths, colCount, "?", "?", "?");

    // Judul Kolom
    cout << "? " << left << setw(colWidths[0]) << "Nama"
        << " ? " << left << setw(colWidths[1]) << "Usia"
        << " ? " << left << setw(colWidths[2]) << "Kota" << " ?" << endl;

    // Pemisah Header-Data
    printHorizontalLine(colWidths, colCount, "?", "?", "?");

    // Isi Data
    for (const auto& row : data) {
        cout << "? " << left << setw(colWidths[0]) << row.nama
            << " ? " << left << setw(colWidths[1]) << row.usia
            << " ? " << left << setw(colWidths[2]) << row.kota << " ?" << endl;

        // Garis pemisah antar baris (opsional, hapus jika tidak perlu)
        if (&row != &data.back()) {
            printHorizontalLine(colWidths, colCount, "?", "?", "?");
        }
    }

    // Footer Bawah
    printHorizontalLine(colWidths, colCount, "?", "?", "?");

    return 0;
}