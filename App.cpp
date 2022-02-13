#include <iostream>

using namespace std;

struct Klasemens {

  string nama_klub;
  int main, menang, kalah, seri,
      memasukkan, kemasukkan, nilai;

};

void dummyKlasemen(Klasemens Klasemen[]) {
  for ( int i = 0; i < 16; i++ ) {
    cout << "Data ke-" << i + 1 << endl;
    cout << "==========" << endl;
    cout << "Nama Klub: " << Klasemen[i].nama_klub << endl;
    cout << "Main: " << Klasemen[i].main << endl;
    cout << "Menang: " << Klasemen[i].menang << endl;
    cout << "Kalah: " << Klasemen[i].kalah << endl;
    cout << "Seri: " << Klasemen[i].seri << endl;
    cout << "Memasukkan: " << Klasemen[i].memasukkan << endl;
    cout << "Kemasukkan: " << Klasemen[i].kemasukkan << endl;
    cout << "Nilai: " << Klasemen[i].nilai << endl;
    cout << "\n";
  }
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

int main() {

  Klasemens Klasemen[16];

  initKlasemen(Klasemen);
  dummyKlasemen(Klasemen);

  return 0;
}
