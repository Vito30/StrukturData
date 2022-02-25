#include <iostream>
#include <string>
#include <iomanip>

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

int index_klub1 = -1, index_klub2 = -1;

void colorName() {

  #define COLOR_RESET       "\033[0m"              /* Defaut */
  #define COLOR_BLACK       "\033[30m"             /* Black */
  #define COLOR_RED         "\033[31m"             /* Red */
  #define COLOR_GREEN       "\033[32m"             /* Green */
  #define COLOR_YELLOW      "\033[33m"             /* Yellow */
  #define COLOR_BLUE        "\033[34m"             /* Blue */
  #define COLOR_MAGENTA     "\033[35m"             /* Magenta */
  #define COLOR_CYAN        "\033[36m"             /* Cyan */
  #define COLOR_WHITE       "\033[37m"             /* White */
  #define COLOR_BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
  #define COLOR_BOLDRED     "\033[1m\033[31m"      /* Bold Red */
  #define COLOR_BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
  #define COLOR_BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
  #define COLOR_BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
  #define COLOR_BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
  #define COLOR_BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
  #define COLOR_BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

}

void tampilKlasemen(Klasemens Klasemen[], string color_mode){

  cout << endl;

  cout << "┌─────────────────────────────────────────────────────────┐" << endl;
  cout << "│ No │    Nama Klub    │ Ma │ Me │ Ka │ Se │ Me │ Ke │ Ni │" << endl;
  cout << "└─────────────────────────────────────────────────────────┘" << endl;

  for (int i = 0; i < 16; i++) {

    if ( color_mode == "color_on" && index_klub1 == i || index_klub2 == i ) {
      if ( i < 9 ) {

        cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << left << "0" << setw(2) << i + 1;

      } else {

        cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << left << setw(3) << i + 1;

      }

      cout << COLOR_RESET << "│ " << left << setw(16) << Klasemen[i].nama_klub;
      cout << COLOR_RESET << "│ " << COLOR_BOLDBLUE << left << setw(3) << Klasemen[i].main;
      cout << COLOR_RESET << "│ " << COLOR_BOLDCYAN << left << setw(3) << Klasemen[i].menang;
      cout << COLOR_RESET << "│ " << COLOR_BOLDRED << left << setw(3) << Klasemen[i].kalah;
      cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << left << setw(3) << Klasemen[i].seri;
      cout << COLOR_RESET << "│ " << COLOR_BOLDBLUE << left << setw(3) << Klasemen[i].memasukkan;
      cout << COLOR_RESET << "│ " << COLOR_BOLDRED << left << setw(3) << Klasemen[i].kemasukkan;
      cout << COLOR_RESET << "│ " << COLOR_BOLDCYAN << left << setw(3) << Klasemen[i].nilai;
      cout << COLOR_RESET << "│ " << endl;
    } else {
      if ( i < 9 ) {
        cout << "│ " << left << "0" << setw(2) << i + 1;
      } else {
        cout << "│ " << left << setw(3) << i + 1;
      }

      cout << "│ " << left << setw(16) << Klasemen[i].nama_klub;
      cout << "│ " << left << setw(3) << Klasemen[i].main;
      cout << "│ " << left << setw(3) << Klasemen[i].menang;
      cout << "│ " << left << setw(3) << Klasemen[i].kalah;
      cout << "│ " << left << setw(3) << Klasemen[i].seri;
      cout << "│ " << left << setw(3) << Klasemen[i].memasukkan;
      cout << "│ " << left << setw(3) << Klasemen[i].kemasukkan;
      cout << "│ " << left << setw(3) << Klasemen[i].nilai;
      cout << "│ " << endl;      
    }

    // if ( color_mode == "color_off" ) {
    //   if ( i < 9 ) {
    //     cout << "│ " << left << "0" << setw(2) << i + 1;
    //   } else {
    //     cout << "│ " << left << setw(3) << i + 1;
    //   }

    //   cout << "│ " << left << setw(16) << Klasemen[i].nama_klub;
    //   cout << "│ " << left << setw(3) << Klasemen[i].main;
    //   cout << "│ " << left << setw(3) << Klasemen[i].menang;
    //   cout << "│ " << left << setw(3) << Klasemen[i].kalah;
    //   cout << "│ " << left << setw(3) << Klasemen[i].seri;
    //   cout << "│ " << left << setw(3) << Klasemen[i].memasukkan;
    //   cout << "│ " << left << setw(3) << Klasemen[i].kemasukkan;
    //   cout << "│ " << left << setw(3) << Klasemen[i].nilai;
    //   cout << "│ " << endl;
    // }

  }

  cout << "└─────────────────────────────────────────────────────────┘" << endl;

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

  int index_klub = -1;

  for ( int i = 0; i < 16; i++ ) {

    if ( nama_klub == Klasemen[i].nama_klub ) {

      index_klub = i;

    }

  }

  if ( index_klub == -1 ) {
    cout << COLOR_YELLOW << "  Peringantan: nama klub tidak ditemukan" << COLOR_RESET << endl;
  }

  return index_klub;

}

void mulaiPertandingan(Klasemens Klasemen[]) {
  string nama_klub1, nama_klub2;
  char confirm;
  int gol_klub1, gol_klub2;

  cout << "┌────────────────────┐" << endl;
  cout << "│ " << COLOR_RED << "Input-an Klub Home" << COLOR_RESET << " │" << endl;
  cout << "└────────────────────┘" << endl;
  cout << endl;

  cout << COLOR_RED << "Masukan Nama Klub" << COLOR_RESET << " > ";
  cin.ignore();
  getline(cin, nama_klub1);
  cout << COLOR_RED << "Masukan Gol      " << COLOR_RESET << " > ";
  cin >> gol_klub1;
  index_klub1 = sequentialSearchIndexKlub(Klasemen, nama_klub1);

  cout << endl;
  cout << "┌────────────────────┐" << endl;
  cout << "│ " << COLOR_CYAN << "Input-an Klub Away" << COLOR_RESET << " │" << endl;
  cout << "└────────────────────┘" << endl;
  cout << endl;

  cout << COLOR_CYAN << "Masukan Nama Klub" << COLOR_RESET << " > ";
  cin.ignore();
  getline(cin, nama_klub2);
  cout << COLOR_CYAN << "Masukan Gol      " << COLOR_RESET << " > ";
  cin >> gol_klub2;
  index_klub2 = sequentialSearchIndexKlub(Klasemen, nama_klub2);

  cout << endl;
  cout << "┌─────────────────────────────────────────────────┐" << endl;
  cout << "│     " << COLOR_RED << "Nama Klub Home" << COLOR_RESET "    V S     " << COLOR_CYAN << "Nama Klub Away" << COLOR_RESET "    │" << endl;
  cout << "└─────────────────────────────────────────────────┘" << endl;
  cout << "│     " << COLOR_RED << setw(15) << nama_klub1 << COLOR_RESET << "   " << gol_klub1 << "-" << gol_klub2 << "     " << COLOR_CYAN << setw(15) << nama_klub2 << COLOR_RESET << "   │" << endl;
  cout << "└─────────────────────────────────────────────────┘" << endl;

  cout << endl;
  cout << "Apakah sudah benar? [y/n] > ";
  cin >> confirm;

  switch (confirm) {

    case 'y':
    case 'Y':

      Klasemen[index_klub1].main += 1;
      Klasemen[index_klub2].main += 1;

      // Rule atau Peraturan Pertandingan:

      if (gol_klub1 == gol_klub2) {

        Klasemen[index_klub1].seri += 1;
        Klasemen[index_klub1].nilai += 1;

        Klasemen[index_klub2].seri += 1;
        Klasemen[index_klub2].nilai += 1;

      } else if (gol_klub1 > gol_klub2) {

        Klasemen[index_klub1].menang += 1;
        Klasemen[index_klub1].nilai += 3;

        Klasemen[index_klub2].kalah += 1;

      } else if (gol_klub2 > gol_klub1) {

        Klasemen[index_klub2].menang += 1;
        Klasemen[index_klub2].nilai += 3;

        Klasemen[index_klub1].kalah += 1;

      }

      Klasemen[index_klub1].memasukkan += gol_klub1;
      Klasemen[index_klub1].kemasukkan += gol_klub2;

      Klasemen[index_klub2].memasukkan += gol_klub2;
      Klasemen[index_klub2].kemasukkan += gol_klub1;

      tampilKlasemen(Klasemen, "color_on");
      break;

    case 'n':
    case 'N':
      break;
  }
}

void swapPointer(Klasemens *x_position, Klasemens *y_position) {
  Klasemens temporary_pointer = *x_position;
  *x_position = *y_position;
  *y_position = temporary_pointer;
}

void urutBerdasarkanPointNilai(Klasemens Klasemen[]) {

  for ( int i = 0; i < 16 - 1; i++ ) {

    int pos = i;

    for ( int j = i + 1; j < 16; j++ ) {

      if ( Klasemen[j].nilai > Klasemen[pos].nilai ) {

        pos = j;

      }

    }

    swapPointer(&Klasemen[pos], &Klasemen[i]);

  }

  cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
  cout << "│ " << COLOR_YELLOW << "Pemberitahuan: " << COLOR_GREEN << "Data Berhasil di Urutkan berasarkan Point Nilai!" << COLOR_RESET << " │" << endl;
  cout << "└─────────────────────────────────────────────────────────────────┘" << endl;
  tampilKlasemen(Klasemen, "color_on");

}

void tampilkanSistemPoint() {
  cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
  cout << "│                                                                 │" << endl;
  cout << "│                     SISTEM PENILAIAN POINT!                     │" << endl;
  cout << "│                                                                 │" << endl;
  cout << "│      1. Jika salah satu team menang, point nilai +3             │" << endl;
  cout << "│      2. Jika kedua team seri, point nilai +1                    │" << endl;
  cout << "│                                                                 │" << endl;
  cout << "└─────────────────────────────────────────────────────────────────┘" << endl;
}

void mainMenu() {

  cout << endl;
  cout << "[" << COLOR_YELLOW << "1" << COLOR_RESET "] Update Tabel Data Klasemen" << endl;
  cout << "[" << COLOR_YELLOW << "2" << COLOR_RESET "] Mulai Pertandingan Klub" << endl;
  cout << "[" << COLOR_YELLOW << "3" << COLOR_RESET "] Urutkan Tabel Data Klasemen Berdasarkan Point Nilai" << endl;
  cout << "[" << COLOR_YELLOW << "4" << COLOR_RESET "] Lihat Sistem Penilaian Point" << endl;
}

int main() {

  Klasemens Klasemen[16];
  int pilih_menu;

  initKlasemen(Klasemen);
  tampilKlasemen(Klasemen, "color_off");

  while ( true ) {

    mainMenu();
    cout << endl;
    cout << COLOR_GREEN << "Pilih Menu" << COLOR_RESET << " > ";
    cin >> pilih_menu;
    cout << endl;

    switch ( pilih_menu ) {

      case 1:
        tampilKlasemen(Klasemen, "color_off");
        break;
      case 2:
        mulaiPertandingan(Klasemen);
        break;
      case 3:
        urutBerdasarkanPointNilai(Klasemen);
        break;
      case 4:
        tampilkanSistemPoint();
        break;

    }

  }

  return 0;
}	
