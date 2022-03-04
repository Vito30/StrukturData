#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Klasemens {

  string nama_klub;
  int main, menang, kalah, seri,
      memasukkan, kemasukkan, nilai;

};

string nama_klub[] = {
  "Man City", "Liverpool", "Chealse", "Man United", "Arsenal",
  "West Ham", "Wolves", "Tottenham", "Brighton", "Southampton",
  "Crystal Palace", "Leicester City", "Aston Villa", "Brentford",
  "Leeds United", "Everton"
};

void tampilKlasemen(Klasemens Klasemen[]){
  cout << "__________________________________________________________" << endl;
  cout << "|    |                |    |    |    |    |    |    |    |" << endl;
  cout << "| NO |    NAMA KLUB   | Ma | Me | Ka | Se | Me | Ke | Ni |" << endl;
  cout << "|____|________________|____|____|____|____|____|____|____|" << endl;

  for (int i = 0; i < 16; i++) {
    if ( i < 9 ) {
      cout << "| " << setiosflags(ios::left) << "0" << setw(2) << i + 1;
    } else {
      cout << "| " << setiosflags(ios::left) << setw(3) << i + 1;
    }

   cout << "| " << setiosflags(ios::left) << setw(15) << Klasemen[i].nama_klub;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].main;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].menang;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].kalah;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].seri;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].memasukkan;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].kemasukkan;
   cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].nilai;
   cout << "|"  << endl;
 } 
 cout << "==========================================================" << endl;
}

void initKlasemen(Klasemens Klasemen[]) {
  for ( int i = 0; i < 16; i++ ) {
    Klasemen[i].nama_klub = nama_klub[i];
    Klasemen[i].main = 0;
    Klasemen[i].menang = 0;
    Klasemen[i].kalah = 0;
    Klasemen[i].seri = 0;
    Klasemen[i].memasukkan = 0;
    Klasemen[i].kemasukkan = 0;
    Klasemen[i].nilai = 0;
  }
}

int sequentialSearchIndexKlub(Klasemens Klasemen[], string nama_klub) {
  int index_klub;
  for ( int i = 0; i < 16; i++ ) {
    if ( nama_klub == Klasemen[i].nama_klub ) {
      index_klub = i;
    }
  }
  return index_klub;
}

void swapPointer(Klasemens *x_position, Klasemens *y_position) {
  Klasemens temporary_pointer = *x_position;
  *x_position = *y_position;
  *y_position = temporary_pointer;
}

void urutBerdasarkanPointNilai(Klasemens Klasemen[]) {
  for (int i = 0; i < 16 - 1; ++i)
  {
    int pos = i;
    for (int j = i + 1; j < 16; j++) {
      if (Klasemen[j].nilai > Klasemen[pos].nilai) {
        pos = j;
      }
    }
    swapPointer(&Klasemen[pos], &Klasemen[i]);
  }
  cout << "Pemberitahuan: Data Berhasil di Urutkan berdasarkan Point Nilai!";
  cout << endl;
  cout << endl;
  tampilKlasemen(Klasemen);
}

void urutBerdasarkanPointMain(Klasemens Klasemen[]) {
  for (int i = 0; i < 16 - 1; ++i)
  {
    int pos = i;
    for (int j = i + 1; j < 16; j++) {
      if (Klasemen[j].main > Klasemen[pos].main) {
        pos = j;
      }
    }
    swapPointer(&Klasemen[pos], &Klasemen[i]);
  }
  cout << "Pemberitahuan: Data Berhasil di Urutkan berdasarkan Point Main!";
  cout << endl;
  cout << endl;
  tampilKlasemen(Klasemen);
}

void urutBerdasarkanPointMenang(Klasemens Klasemen[]) {
  for (int i = 0; i < 16 - 1; ++i)
  {
    int pos = i;
    for (int j = i + 1; j < 16; j++) {
      if (Klasemen[j].menang > Klasemen[pos].menang) {
        pos = j;
      }
    }
    swapPointer(&Klasemen[pos], &Klasemen[i]);
  }
  cout << "Pemberitahuan: Data Berhasil di Urutkan berdasarkan Point Menang!";
  cout << endl;
  cout << endl;
  tampilKlasemen(Klasemen);
}

void urutBerdasarkanPointKalah(Klasemens Klasemen[]) {
  for (int i = 0; i < 16 - 1; ++i)
  {
    int pos = i;
    for (int j = i + 1; j < 16; j++) {
      if (Klasemen[j].kalah > Klasemen[pos].kalah) {
        pos = j;
      }
    }
    swapPointer(&Klasemen[pos], &Klasemen[i]);
  }
  cout << "Pemberitahuan: Data Berhasil di Urutkan berdasarkan Point Kalah!";
  cout << endl;
  cout << endl;
  tampilKlasemen(Klasemen);
}

void mulaiPertandingan(Klasemens Klasemen[]){
  string nama_klub1, nama_klub2;
  int gol_klub1, gol_klub2, index_klub1, index_klub2;
	
  cout << "Masukan Tim Pertama : ";
  cin.ignore();
  getline(cin, nama_klub1);
 
  cout << "Masukan Gol : ";
  cin >> gol_klub1;
  index_klub1 = sequentialSearchIndexKlub(Klasemen,nama_klub1);
 
  cout << "Masukan Tim Kedua : ";
  cin.ignore();
  getline(cin, nama_klub2);
 	
  cout << "Masukan Gol : ";
  cin >> gol_klub2;
  index_klub2 = sequentialSearchIndexKlub(Klasemen,nama_klub2);
    
  Klasemen[index_klub1].main += 1;
  Klasemen[index_klub2].main += 1;
 
  if (gol_klub1 == gol_klub2) {
    Klasemen[index_klub1].seri += 1;
    Klasemen[index_klub1].nilai += 1;
    Klasemen[index_klub2].seri += 1;
    Klasemen[index_klub2].nilai += 1;
  }
  else if (gol_klub1 > gol_klub2) {
    Klasemen[index_klub1].menang += 1;
    Klasemen[index_klub1].nilai += 3;
    Klasemen[index_klub2].kalah += 1;
  }
  else {
    Klasemen[index_klub2].menang += 1;
    Klasemen[index_klub2].nilai += 3;
    Klasemen[index_klub1].kalah += 1;
  }

  Klasemen[index_klub1].memasukkan += gol_klub1;
  Klasemen[index_klub1].kemasukkan += gol_klub2;

  Klasemen[index_klub2].memasukkan += gol_klub2;
  Klasemen[index_klub2].kemasukkan += gol_klub1;

  cout << endl;
  tampilKlasemen(Klasemen);
}

void tampilkanSistemPoint() {
  cout << "===================================================================" << endl;
  cout << "|                                                                 |" << endl;
  cout << "|                     SISTEM PENILAIAN POINT!                     |" << endl;
  cout << "|                                                                 |" << endl;
  cout << "|      1. Jika salah satu team menang, point nilai +3             |" << endl;
  cout << "|      2. Jika kedua team seri, point nilai +1                    |" << endl;
  cout << "|                                                                 |" << endl;
  cout << "===================================================================" << endl;
}

void mainMenu() {
  cout << endl;
  cout << "[0] Tampilkan Sistem Penilaian Point" << endl;
  cout << "[1] Update Tabel Data Klasemen" << endl;
  cout << "[2] Mulai Pertandingan Klub" << endl;
  cout << "[3] Urutkan Tabel Data Klasemen Berdasarkan Point Nilai" << endl;
  cout << "[4] Urutkan Tabel Data Klasemen Berdasarkan Point Main" << endl;
  cout << "[5] Urutkan Tabel Data Klasemen Berdasarkan Point Menang" << endl;
  cout << "[6] Urutkan Tabel Data Klasemen Berdasarkan Point Kalah" << endl;
}

int main() {

  Klasemens Klasemen[16];
  int pilih_menu;

  initKlasemen(Klasemen);
  tampilKlasemen(Klasemen);

  while (true) {
    mainMenu();
    cout << endl;
    cout << "Pilih Menu : ";
    cin >> pilih_menu;
    cout << endl;

    switch (pilih_menu) {
      case 0:
        tampilkanSistemPoint();
        break;
      case 1:
        tampilKlasemen(Klasemen);
        break;
      case 2:
        mulaiPertandingan(Klasemen);
        break;
      case 3:
        urutBerdasarkanPointNilai(Klasemen);
        break;
      case 4:
        urutBerdasarkanPointMain(Klasemen);
        break;
      case 5:
        urutBerdasarkanPointMenang(Klasemen);
        break;
      case 6:
        urutBerdasarkanPointKalah(Klasemen);
        break;
    }
  }

  return 0;
}
