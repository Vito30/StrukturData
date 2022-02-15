#include <iostream>
#include <iomanip>

using namespace std;

struct Klasemens {
  string nama_klub;
  int main,
      menang,
      kalah,
      seri,
      memasukan,
      kemasukan,
      nilai;
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
	cout<<"| "<<setiosflags(ios::left)<<setw(3)<<Klasemen[i].memasukan;
	cout<<"| "<<setiosflags(ios::left)<<setw(2)<<Klasemen[i].kemasukan;
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
    cout << "Memasukan: " << Klasemen[i].memasukan << endl;
    cout << "Kemasukan: " << Klasemen[i].kemasukan << endl;
    cout << "Nilai: " << Klasemen[i].nilai << endl;
    cout << "\n";
  }
}

void initKlasemen(Klasemens Klasemen[]) {
  Klasemen[0].nama_klub = "A"; Klasemen[1].nama_klub = "B"; Klasemen[2].nama_klub = "C";
  Klasemen[3].nama_klub = "D"; Klasemen[4].nama_klub = "E"; Klasemen[5].nama_klub = "F";
  Klasemen[6].nama_klub = "G"; Klasemen[7].nama_klub = "H"; Klasemen[8].nama_klub = "I";
  Klasemen[9].nama_klub = "J"; Klasemen[10].nama_klub = "K"; Klasemen[11].nama_klub = "L";
  Klasemen[12].nama_klub = "M"; Klasemen[13].nama_klub = "N"; Klasemen[14].nama_klub = "O";
  Klasemen[15].nama_klub = "P";

  for ( int i = 0; i < 16; i++ ) {
    Klasemen[i].main = 0;
    Klasemen[i].menang = 0;
    Klasemen[i].kalah = 0;
    Klasemen[i].seri = 0;
    Klasemen[i].memasukan = 0;
    Klasemen[i].kemasukan = 0;
    Klasemen[i].nilai = 0;
  }
}

int main() {

  Klasemens Klasemen[16];

  initKlasemen(Klasemen);
  dummyKlasemen(Klasemen);
  tampilKlasemen(Klasemen);

  return 0;
}
