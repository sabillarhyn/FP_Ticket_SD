#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <iomanip>


using namespace std;
#define delay Sleep // mendefinisikan nilai jeda (sleep) munculnya teks
#define maxData 3 //mendefinisikan maksimak data yang dapat di input

string data[10][3]; //array kosong
int head = -1, tail = -1, a,x;

struct tipedata // kumpulan deklarasi data
{
    string namdep, nambel, notlp;
    int jumlah, total, num;
    string email;
} td;

struct tiket // mengelompkkan harga tiket
{
    string tipe[3][4]= //array tiket
    {
        {"|            1","Green Zone","Standing","Rp 2.000.000"},
        {"|            2","Blue Zone","Free Seating","Rp 1.500.000"},
        {"|            3","Yellow Zone","Free Seating","Rp 800.000"},
    };
} tk;

string t(int width, char* s) //fungsi untuk membuat tulisan ditengah
{
    stringstream ss;
    int l = strlen(s);
    int pos = (int)((width - l) / 2);
    for (int i = 0; i < pos; i++)
    {
        ss << " ";
    }
    ss << s;
    return ss.str();
}
struct queue //fungsi queue
{
    int data [maxData];//inputan data di batasi oleh jumlah yang sudah di tentukan di define maxData
    int head,tail;
} antrian;

void init ()
{
    antrian.head= -1;
    antrian.tail= -1;
}

bool isEmpty(){ // memastikan queue dalam keadaan kosong
	if(head == -1){
	    return true;
	} else {
		return false;
	}
}

bool IsFull(){ // mrnyatakan queue telah penuh / mencapai batas maxData
	if(head ==  maxData - 1)
	    return true;
	else
	    return false;
}

void Enqueue(){ //memasukan data ke queue
	string num,nama,nzone;
	char zona;
	int harga,juml, bayar;
	int menu;

	if (IsFull()){
        int nomor = a + 1;
	    cout <<t(80, " Mohon maaf tiket sudah habis ^_^")<<endl;
	}
	else{
	    	head++;
	        cout <<t(80, "Masukan data lengkap dibawah ini : ")<< endl; //input data (masuk dalam array)
	        cout <<t(80, "Nama       : "); cin >> nama;
	        cout <<t(80, "No.Telfon  : (+62) "); cin >>num;
	        cout <<t(80, "Pilih Zona : ")<< endl;
	        cout <<t(80, "-----------------------------------------------------------")<<endl;
	        Sleep(500);
	        cout <<t(80, "|                                                         |")<<endl;
	        cout <<t(80, "|                   ZONA TERSEDIA                         |")<<endl;
	    	cout <<t(80, "|                                                         |")<<endl;
	        cout <<t(80, "|                  [1] Yellow Zone                        |")<<endl;
	        cout <<t(80, "|                  [2] Blue Zone                          |")<<endl;
	        cout <<t(80, "|                  [3] Green Zone                         |")<<endl;
	        cout <<t(80, "|                                                         |")<<endl;
	        cout <<t(80, "-----------------------------------------------------------")<<endl;

	        cout <<t(80, "\n")<<endl;
	        Sleep(500);
	        cout <<t(80, "Memilih Zona : ");
	        cin >> menu;
	        cout << "\n";

	        if(menu == 1) {
	            harga=2000000;
	            nzone="Yellow Zone";
	        }
	        else if (menu == 2){
	            harga=1500000;
	            nzone="Blue Zone";
	        }
	        else if (menu == 3){
	            harga=800000;
	            nzone="Green Zone";
	        }

	        cout <<t(80, "Zona yang telah dipilih adalah : ")<< nzone <<endl; //mencetak isi dari yang diinputkan(array)
 	        cout <<t(80, "Dengan harga RP: ")<< harga <<endl;
	        cout <<t(80, "Beli berapa tiket : "); cin >> juml;

			bayar=harga*juml;

	        cout<<endl;
	        cout<<"Nama                 : "<<nama<<endl;
	        cout<<"Nomer Telfon         : (+62)"<<num<<endl;
	        cout<<"Zona yang anda pilih : "<<nzone<<endl;
	        cout<<"Jumlah pembelian     : "<<juml<<endl;
	        cout<<"Total pemmbayaran    : RP."<<bayar<<endl;
	        cout<<"TIKET YANG SUDAH DIPESAN TIDAK DAPAT DIBATALKAN!"<<endl;

	        std::ostringstream ss;
	        std::ostringstream totalBayarSTR;

	        ss << num;
	        totalBayarSTR << bayar;

	        data[head][0] = nama;
	        data[head][1] = ss.str();
	        data[head][2] = totalBayarSTR.str();

	        getch();

	}
}

void view(){ // menampilkan data yang sudah dimasukkan ke queue
	if (!isEmpty()){

  		for(int a=head;a>=0;a--){
  		    int nomor = a+1;
  			cout<<" No. "<<std::setfill('0')<< std::setw(3) <<nomor<< endl;
  			cout<<" Nama Pembeli    : " <<data[a][0]<< endl;
  			cout<<" No.Telfon       : (+62)" << data[a][1] << endl;
  			cout<<" Total Bayar     : " << data[a][2] << endl;
  			cout<<endl;
  		}
 	} else
  		cout<<"- BELUM ADA PEMESANAN TIKET -";
  		cout<<endl;

}

void cari(){
    string bil_cari;
    cout<< "Input Nama : "; cin >> bil_cari; //input data yang akan dicari (searching)
    int ketemu = 0;
    int i = 0;

    while((i<10) && (ketemu==0))
    {
        if(data[i][0]==bil_cari || data[i][1]==bil_cari){
            ketemu = 1;
            cout<<" Nama                   : "<<data[i][0] << endl;
            cout<<" No. Telfon             : (+62)"<<data[i][1] << endl;
            cout<<" Total pembayaran       : "<<data[i][2] << endl;
        }
        else{
            i=i+1;
        }
    }
    if(ketemu == 1){
        cout<< "\n Telah berhasil melakukan pemesanan!"<<endl;

    }
    else{
        cout<<"\n Data tidak tersedia!"<<endl;
    }
}

int main()
{
    //proses pemilihan (searching)
    int menu;
    do
    {
awal:
        system ("cls");
        cout<<endl;
        cout <<t(80, "==========================================================")<<endl;
        Sleep(500); //jeda 500sec
        cout <<t(80, "|                                                         |")<<endl;
        cout <<t(80, "|         HALO! INI APLIKASI PENJUALAN TIKET KONSER       |")<<endl;
        cout <<t(80, "|                                                         |")<<endl;
        cout <<t(80, "-----------------------------------------------------------")<<endl;
        Sleep(500);
        cout <<t(80, "|                         MENU                            |")<<endl;
        cout <<t(80, "|                                                         |")<<endl;
        cout <<t(80, "|                  [1] Info Konser                        |")<<endl;
        cout <<t(80, "|                  [2] Daftar Harga Tiket                 |")<<endl;
        cout <<t(80, "|                  [3] Pembelian Tiket                    |")<<endl;
        cout <<t(80, "|                  [4] Data Pembelian                     |")<<endl;
        cout <<t(80, "|                  [5] Cek Status Pemesanan               |")<<endl;
        cout <<t(80, "|                  [0] Keluar                             |")<<endl;
        cout <<t(80, "|                                                         |")<<endl;
        cout <<t(80, "===========================================================")<<endl;

        cout <<t(80, "\n")<<endl;
        Sleep(500);
        cout <<t(80, "Masuk ke Menu : ");
        cin >>menu;

        cout <<t(80, "Mengarahkan ke menu ")<<menu;
        Sleep(700);
        cout <<".";
        Sleep(700);
        cout <<".";
        Sleep(700);
        cout <<".";

        cout <<t(80, " ")<<endl;

        switch (menu)
        {
        case 0 :
            system ("cls");
            cout <<endl;
            cout <<t(80, "SELAMAT TINGGAL !")<<endl;
            cout <<t(80, "TERIMAKASIH SUDAH MENGGUNAKAN APLIKASI PENJUALAN TIKET KAMI ! ^^")<<endl;
            Sleep(3000);
            exit(0);

        case 1 :
            system ("cls");
            Sleep(500);
            cout <<t(80, "KONSER Ex MELODIAE")<<endl;
            cout <<t(80, "SATURDAY, JULY 18th 2020\n")<<endl;
            Sleep(500);
            cout <<t(80, "LINE UP\n")<<endl;
            Sleep(500);
            cout <<t(80, "Raisa")<<endl;
            Sleep(500);
            cout <<t(80, "Isyana")<<endl;
            Sleep(500);
            cout <<t(80, "Agnes Mo")<<endl;
            Sleep(500);
            cout <<t(80, "Afgan")<<endl;
            Sleep(500);
            cout <<t(80, "Aldi M")<<endl;
            Sleep(500);
            cout <<t(80, "Maheen")<<endl;
            Sleep(500);
            cout <<t(80, "Tulus")<<endl;
            Sleep(500);
            cout <<t(80, "Mawar De Jongh")<<endl;
            Sleep(500);
            cout <<t(80, "Rossa")<<endl;
            Sleep(500);
            cout <<t(80, "Jazz")<<endl;
            break;
        case 2 :
            system ("cls");
            cout<<"|\t     no\t\t"<<"|\t   Zone\t\t|"<<"\t   Tipe\t\t"<<"|\t Harga\t\t|"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            for(int i=0; i<3; i++) //proses pengambilan data tiket (searching)
            {
                for(int j=0; j<4; j++)
                {
                    cout<<tk.tipe[i][j]<<"\t\t|";
                }
                cout<<endl;
            }
            break;
       	case 3 :
       		system("cls");
			Enqueue(); //memanggil fungsi input queue
       		break;
        case 4 :
            system ("cls");
            view(); // memanggil fungsi tampil queue
            break;
        case 5 :
            system ("cls");
            cari(); //memanggil fungs cari queue
            break;
        default : //jika pilihan selain 1-5
            system ("cls");
            cout <<t(80, "TIDAK ADA MENU ")<<menu<<"!\n";
        }
        cout <<endl;
        cout <<t (80, "Tekan ENTER untuk kembali ke Menu Utama");
        getch();

    }
    while (menu!=10);
    return 0;
}
