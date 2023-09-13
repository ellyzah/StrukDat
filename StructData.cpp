#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 10;

// Data-Data Mahasiswa
struct Mahasiswa {
    string nama;
    string nrp;
    string departemen;
};

// Untuk Menampilkan Data
void tampilkanData(const Mahasiswa data[], int jumlahMahasiswa) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Nama: " << data[i].nama << endl;
        cout << "NRP: " << data[i].nrp << endl;
        cout << "Departemen: " << data[i].departemen << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {
    Mahasiswa dataMahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0; 

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data Baru" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cout << "Pilih operasi (1/2/3/4/5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampilkanData(dataMahasiswa, jumlahMahasiswa);
        } else if (pilihan == 2) {
            if (jumlahMahasiswa < MAX_MAHASISWA) {
                Mahasiswa mhs;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, mhs.nama);
                cout << "Masukkan NRP: ";
                cin >> mhs.nrp;
                cout << "Masukkan Departemen: ";
                cin.ignore();
                getline(cin, mhs.departemen);
                dataMahasiswa[jumlahMahasiswa++] = mhs;
                cout << "Data mahasiswa berhasil ditambahkan." << endl;
            } else {
                cout << "Kapasitas data mahasiswa telah mencapai batas maksimum." << endl;
            }
        } else if (pilihan == 3) {
            int index;
            cout << "Masukkan indeks data yang ingin dihapus: ";
            cin >> index;
            if (index >= 0 && index < jumlahMahasiswa) {
                for (int i = index; i < jumlahMahasiswa - 1; ++i) {
                    dataMahasiswa[i] = dataMahasiswa[i + 1];
                }
                --jumlahMahasiswa;
                cout << "Data mahasiswa berhasil dihapus." << endl;
            } else {
                cout << "Indeks tidak valid." << endl;
            }
        } else if (pilihan == 4) {
            int index;
            cout << "Masukkan indeks data yang ingin diubah: ";
            cin >> index;
            if (index >= 0 && index < jumlahMahasiswa) {
                Mahasiswa mhs;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, mhs.nama);
                cout << "Masukkan NRP: ";
                cin >> mhs.nrp;
                cout << "Masukkan Departemen: ";
                cin.ignore();
                getline(cin, mhs.departemen);
                dataMahasiswa[index] = mhs;
                cout << "Data mahasiswa berhasil diubah." << endl;
            } else {
                cout << "Indeks tidak valid." << endl;
            }
        } else if (pilihan == 5) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
