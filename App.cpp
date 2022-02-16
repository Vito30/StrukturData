#include <iostream>
#include <iomanip>

using namespace std;

struct Klasemens {

  string nama_klub;
  int main, menang, kalah, seri,
      memasukkan, kemasukkan, nilai;

};

void tampilKlasemen(Klasemens Klasemen[]){
	cout<<"____________________________________________________"<<endl;
	cout<<"|    |           |    |    |    |    |    |   |    |"<<endl;
	cout<<"| NO | NAMA KLUB | Ma | Me | Ka | Se | Me | Ke| Ni |"<<endl;
	cout<<"|____|___________|____|____|____|____|____|___|____|"<<endl;
	for (int i = 0; i < 16; i++) {
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<i+1;
	cout<<"| "<<setiosflags(ios::left)<<setw(10)<<Klasemen[i].nama_klub;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].main;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].menang;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].kalah;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].seri;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].memasukkan;
	cout<<"| "<<setiosflags(ios::left)<<setw(2)<<Klasemen[i].kemasukkan;
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].nilai;
	cout<<"|"<<endl;
	}
	cout<<"===================================================="<<endl;
}

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
  //dummyKlasemen(Klasemen);
  tampilKlasemen(Klasemen);

  return 0;
}
