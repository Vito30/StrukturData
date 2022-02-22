#include <iostream>
#include <iomanip>

using namespace std;

struct Klasemens {

  string nama_klub;
  int main, menang, kalah, seri,
      memasukkan, kemasukkan, nilai;

};

void tampilKlasemen(Klasemens Klasemen[]){

	cout << "_____________________________________________________" << endl;
	cout << "|    |           |    |    |    |    |    |    |    |" << endl;
	cout << "| NO | NAMA KLUB | Ma | Me | Ka | Se | Me | Ke | Ni |" << endl;
	cout << "|____|___________|____|____|____|____|____|____|____|" << endl;

	for (int i = 0; i < 16; i++) {

          if ( i < 9 ) {

	    cout << "| " << setiosflags(ios::left) << "0" << setw(2) << i + 1;

          } else {

            cout << "| " << setiosflags(ios::left) << setw(3) << i + 1;

          }
	  cout << "| " << setiosflags(ios::left) << setw(10) << Klasemen[i].nama_klub;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].main;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].menang;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].kalah;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].seri;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].memasukkan;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].kemasukkan;
	  cout << "| " << setiosflags(ios::left) << setw(3)  << Klasemen[i].nilai;
	  cout << "|"  << endl;

	}

	cout << "=====================================================" << endl;

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

void KlasemenSementara(Klasemens Klasemen[]){
	int temmp = 0;
	string tempchar;
	for (int i = 0 ; i < 16-1; i++){
		for (int j = 0; j < 16 - i-1; j++){
			if(Klasemen[j].nilai < Klasemen[j+1].nilai){
				temmp = Klasemen[j].nilai;
				Klasemen[j].nilai = Klasemen[j+1].nilai;
				Klasemen[j+1].nilai = temmp;
				
				tempchar = Klasemen[j].nama_klub;
				Klasemen[j].nama_klub = Klasemen[j+1].nama_klub;
				Klasemen[j+1].nama_klub = tempchar;
				
				temmp = Klasemen[j].kalah;
				Klasemen[j].kalah = Klasemen[j+1].kalah;
				Klasemen[j+1].kalah = temmp;
				
				temmp = Klasemen[j].menang;
				Klasemen[j].menang = Klasemen[j+1].menang;
				Klasemen[j+1].menang = temmp;
				
				temmp = Klasemen[j].seri;
				Klasemen[j].seri = Klasemen[j+1].seri;
				Klasemen[j+1].seri = temmp;
			}
		}
	}
}

void mulaiPertandingan(Klasemens Klasemen[]){
	string nama_klub1,nama_klub2;
	int gol_klub1,gol_klub2,index_klub1,index_klub2;
	
	cout<<"Masukan Tim Pertama : ";
    cin>>nama_klub1;
 
    cout<<"Masukan Gol : ";
    cin>>gol_klub1;
    index_klub1 = sequentialSearchIndexKlub(Klasemen,nama_klub1);
 
    cout<<"Masukan Tim Kedua : ";
    cin>>nama_klub2;
 	
    cout<<"Masukan Gol : ";
    cin>>gol_klub2;
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
    
}

int main() {

  Klasemens Klasemen[16];

  initKlasemen(Klasemen);
  tampilKlasemen(Klasemen);
  mulaiPertandingan(Klasemen);
  tampilKlasemen(Klasemen);

  return 0;
}
