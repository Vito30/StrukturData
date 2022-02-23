#include <iostream>
#include <iomanip>

using namespace std;

struct Klasemens {

  string nama_klub;
  int main, menang, kalah, seri,
      memasukkan, kemasukkan, nilai;

};

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

void tampilKlasemen(Klasemens Klasemen[]){

	cout << "┌───────────────────────────────────────────────────┐" << endl;
  cout << "│ No │ Nama Klub │ Ma │ Me │ Ka │ Se │ Me │ Ke │ Ni │" << endl;
	cout << "└───────────────────────────────────────────────────┘" << endl;

	for (int i = 0; i < 16; i++) {

    if ( i < 9 ) {

	    cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << setiosflags(ios::left) << "0" << setw(2) << i + 1;

    } else {

      cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << setiosflags(ios::left) << setw(3) << i + 1;

    }

	  cout << COLOR_RESET << "│ " << setiosflags(ios::left) << setw(10) << Klasemen[i].nama_klub;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDBLUE << setiosflags(ios::left) << setw(3) << Klasemen[i].main;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDCYAN << setiosflags(ios::left) << setw(3) << Klasemen[i].menang;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDRED << setiosflags(ios::left) << setw(3) << Klasemen[i].kalah;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDYELLOW << setiosflags(ios::left) << setw(3) << Klasemen[i].seri;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDBLUE << setiosflags(ios::left) << setw(3) << Klasemen[i].memasukkan;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDRED << setiosflags(ios::left) << setw(3) << Klasemen[i].kemasukkan;
	  cout << COLOR_RESET << "│ " << COLOR_BOLDCYAN << setiosflags(ios::left) << setw(3) << Klasemen[i].nilai;
	  cout << COLOR_RESET << "│ "  << endl;

	}

  cout << "└───────────────────────────────────────────────────┘" << endl;

}

void initKlasemen(Klasemens Klasemen[]) {

  for ( int i = 0; i < 16; i++ ) {

    Klasemen[i].nama_klub = 'A' + i;
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

void mulaiPertandingan(Klasemens Klasemen[]) {
  string nama_klub1, nama_klub2;
  int gol_klub1, gol_klub2, index_klub1, index_klub2;

  cout << endl;

  cout << "Masukan Nama Klub Pertama : ";
  cin >> nama_klub1;
  cout << "Masukan Gol Klub Pertama : ";
  cin >> gol_klub1;
  index_klub1 = sequentialSearchIndexKlub(Klasemen, nama_klub1);

  cout << "Masukan Nama Klub Kedua : ";
  cin >> nama_klub2;
  cout << "Masukan Gol Klub Kedua : ";
  cin >> gol_klub2;
  index_klub2 = sequentialSearchIndexKlub(Klasemen, nama_klub2);

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
}

void swapPointer(Klasemens *x_position, Klasemens *y_position) {
  Klasemen temporary_pointer = *x_position;
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
  cout << endl;
  cout << "Pemberitahuan: Data Berhasil di Urutkan berasarkan Point Nilai!" << endl;
  tampilKlasemen(Klasemen);
}

int main() {

  Klasemens Klasemen[16];

  initKlasemen(Klasemen);
  tampilKlasemen(Klasemen);


  return 0;
}	
