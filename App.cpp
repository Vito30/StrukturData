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

int searchIndexKlub(Klasemens Klasemen[], string nama_klub) {

  int index_klub;

  for ( int i = 0; i < 16; i++ ) {

    if ( nama_klub == Klasemen[i].nama_klub ) {

      index_klub = i;

    }

  }

  return index_klub;
}

int main() {

  Klasemens Klasemen[16];

  initKlasemen(Klasemen);
  tampilKlasemen(Klasemen);

  return 0;
}	
