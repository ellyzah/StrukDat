#include <iostream>
using namespace std;

// Membuat login sederhana

// Hash Table
struct HashTable
{
    //Data
    string username, password;
} dataAkun[26];

// Function Hash
int hashFunction (string key){
    return tolower(key[0])-97;
}

// Cek Daftar
bool CekDaftar (string username, string password)
{
    int index = hashFunction (password);

    // Cek Isi Index
    if (dataAkun[index].username != "" && dataAkun[index].password != ""){
        // Cek Sel Index di HashTable Tidak Kosong
        cout << "User sudah ada!!" << endl;
        return false;
    }else {
        // Cek Sel Index di HashTable Kosong
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        return true;
    }
}

// Cek Login
bool CekLogin(string username, string password){
    // Hashing Dulu
    int index = hashFunction(password);

    // Cek username & password benar tidak
    if (dataAkun[index].username == username && dataAkun[index].password == password){
        // Kalau Benar
        return true;
    }else {
        return false;
    }
}

// Cek Hapus Akun
bool CekHapusAkun (int index){
     // Cek Isi Index
    if (dataAkun[index].username != "" && dataAkun[index].password != ""){
        // Sel Kosong
        cout << "\nData akun tidak ada!!" << endl;
        return false;
    }else{
        // Sel Ada Isinya
        dataAkun[index].username = "";
        dataAkun[index].password ="";
        return true;
    }
}

//Print Data Akun
void PrintDataAkun(){
    cout << "\nData Akun : " << endl;
    cout << "| Index\t - Username - Password |" << endl;
    for (int i=0; i<26; i++){
        cout << "| " << i << "\t - ";
        if (dataAkun[i].username == ""){
            cout << "(kosong) - ";
        }else{
            cout << dataAkun[i].username << " - ";
        }if (dataAkun[i].password == ""){
            cout << "(kosong) |" << endl;
        }else{
            cout << dataAkun[i].password << " |" << endl;
        }
    }
}

// Lihat Daftar
void LihatDaftar(){
    string username, password;
    cout << "\n=== Menu Daftar ===" << endl;
    cout << "Masukkan username & password" << endl;
    cout << "Isi Username anda : ";
    cin >> username;
    cout << "Isi Password anda : ";
    cin >> password;

    cout << "Username : " << username << " & password : " << password << endl;

    if (CekDaftar(username, password)){
        cout << "Akun berhasil terdaftar!!" << endl;
    }else{
        cout << "Akun gagal terdaftar!!" << endl;
    }
}

// Lihat Tambah Akun
void LihatTambahAkun() {
    string username, password;
    cout << "\n=== Menu Tambah Akun ===" << endl;
    cout << "Masukkan username & password" << endl;
    cout << "Isi Username akun : ";
    cin >> username;
    cout << "Isi Password akun : ";
    cin >> password;
    
    if (CekDaftar(username, password)){
        cout << "Akun berhasil terdaftar!!" << endl;
        }else{
            cout << "Akun gagal terdaftar!!" << endl;
        }
}

// Lihat Hapus Akun
void LihatHapusAkun(){
  int index;
  cout << "\n== Menu Hapus Akun ==" << endl;
  cout << "Isi index : ";
  cin >> index;

  if (CekHapusAkun(index)){
    cout << "Data akun berhasil dihapus!!" << endl;
  }else{
    cout << "Data akun gagal dihapus!!" << endl;
  }
}

// Lihat Menu Login
void LihatMenuLogin(){
  while (true){
    string pilihan;
    cout << "\n== Menu Admin ==" << endl;
    cout << "Menu Pilihan :" << endl;
    cout << "1. Tambah Akun" << endl;
    cout << "2. Hapus Akun" << endl;
    cout << "3. Lihat Data Akun" << endl;
    cout << "4. Logout" << endl;
    cout << "Pilih menu [1/2/3] : ";
    cin >> pilihan;
    if (pilihan == "1"){
      LihatTambahAkun();
    }else if (pilihan == "2"){
      LihatHapusAkun();
    }else if (pilihan == "3"){
      PrintDataAkun();
    }else if (pilihan == "4"){
      cout << "Anda berhasil logout" << endl;
      break;
    }else{
      cout << "Pilihan tidak tersedia!!" << endl;
    }
  }
}

// Lihat Login
void LihatLogin(){
  string username, password;
  cout << "== Lihat Login ==" << endl;
  cout << "Masukkan username & password" << endl;
  cout << "Isi username anda : ";
  cin >> username;
  cout << "Isi password anda : ";
  cin >> password;

  if (CekLogin(username, password)){
    cout << "\nLogin berhasil!!" << endl;
    LihatMenuLogin();
  }else{
    cout << "\nLogin Gagal!!" << endl;
  } 
}

// Tampilan Utama
void welcome(){
    while (true){
        string pilihan;
    cout << "\n\n=== Login Sederhana Dengan Hashing ===" << endl;
    cout << "Menu Pilihan :" << endl;
    cout << "1. Daftar" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih Menu [1/2/3] : ";
    cin >> pilihan;

    if (pilihan == "1"){
        LihatDaftar();
            }else if (pilihan == "2"){
                cout << "\n Anda berada dimenu Login" << endl;
            }else if (pilihan == "3"){
                cout << "\nTerima kasih sudah menggunakan aplikasi Login Sederhana" << endl;
                break;
            }else {
                cout << "Pilihan tidak tersedia!!" << endl;
            }
        }

    }

int main(){
    welcome();
}