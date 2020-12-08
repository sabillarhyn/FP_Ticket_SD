#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#define MAX 50

using namespace std;
#define delay Sleep

struct tipedata
{
    string nama;
    int jumlah, harga, total, notlp, zona;
} td;

struct tiket
{
    string tipe[3][4]=
    {
        {"|            1","Green Zone","Standing","Rp 2.000.000"},
        {"|            2","Blue Zone","Free Seating","Rp 1.500.000"},
        {"|            3","Yellow Zone","Free Seating","Rp 800.000"},
    };
} tk;

struct queue
{
    int data [MAX];
    int head,tail;
} antrian;

void init ()
{
    antrian.head= -1;
    antrian.tail= -1;
}

bool full ()
{
    if(antrian.tail == MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool empty ()
{
    if(antrian.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tampilData ()
{
    int i;
    if (!empty())
    {
        for(i=antrian.head; i<antrian.tail; i++)
        {
            cout<<endl;
            cout<<"Pembelian Tiket atas nama "<<td.nama<<endl;
            cout<<"Dengan Jumlah Tiket "<<td.jumlah<<endl;
            cout<<"Total Pembelian Tiket Rp."<<td.total<<",-"<<endl;
        }
    }
    cout<<"\n";
}

void inQueue ()
{

    if (!full())
    {
        cout<<"Nama : ";
        cin>>td.nama;
        cout<<"Nomor Telepon : ";
        cin>>td.notlp;
        cout <<"Jumlah Tiket yang ingin di beli : ";
        cin >> td.jumlah;
        cout<<"Zona tiket : ";
        cin>>td.zona;
            switch(td.zona)
            {
            case 1 :
                td.harga = 2000000;
                break;
            case 2:
                td.harga = 1500000;
                break;
            case 3 :
                td.harga = 800000;
                break;
            default :
                cout << "TIDAK ADA ZONA!";
                break;

            }
            td.total = td.harga * td.jumlah;

        antrian.data[antrian.tail] = td.jumlah, td.nama, td.notlp, td.total;
        antrian.tail++;
    }
    else
    {
        cout<<"Queue penuh\n";
    }
    getchar();
}

void deQueue ()
{
    int i;
    tampilData();

    if (!empty())
    {
        cout<<"\nMembatalkan Pemesanan\" "<<antrian.data[antrian.head]<<" \"..."<<endl;
        for(i=antrian.head; i<antrian.tail; i++)
        {
            antrian.data [i]= antrian.data[i+1];
        }
        antrian.tail--;
    }
    else
    {
        cout<<"Pesanan Kosong";
    }
    getchar();
}

void Search()
{
    int i,ketemu=0;
    cout<<"Nama yang ingin di Cek : ";
    cin>>td.nama;
    for(i=-1; i<td.nama; i++)
    {
        if(antrian.data[i]==td.nama)
        {
            ketemu =1;
            cout<<endl;
            cout<<"Pembelian Tiket atas nama "<<td.nama<<" dengan jumlah "<<td.jumlah<<" tiket \ndan total pembelian Tiket yang harus dibayar adalah Rp."<<td.total<<"\ntelah berhasil dilakukan!"<<endl;
            cout<<endl;
        }
    }
    if(ketemu==0)
    {
        cout<<"Data tidak ketemu";
    }
}

string t(int width, char* s)
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

int main()
{
    int menu;
    do
    {
        system ("cls");
        cout<<endl;
        cout <<t(80, "==========================================================")<<endl;
        Sleep(500);
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
        cout <<t(80, "|                  [6] Batalkan Pemesanan                 |")<<endl;
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
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<4; j++)
                {
                    cout<<tk.tipe[i][j]<<"\t\t|";
                }
                cout<<endl;
            }
            break;
        case 3 :
            system ("cls");
            cout << "Zona dan Harga Tiket\n";
            cout << "[1] Green Zone | Standing | Rp 2.000.000\n";
            cout << "[2] Blue Zone | Free Seating | Rp 1.500.000\n";
            cout << "[3] Yellow Zone | Free Seating | Rp 800.000\n";
            cout<<endl;
            inQueue();
            break;
        case 4 :
            system ("cls");
            cout <<"Daftar Pembelian Tiket Konser Ex Melodiae"<<endl;
            tampilData();
            break;
        case 5 :
            system ("cls");
            cout <<"Cek Status Pemesanan";
            Search();
            break;
        default :
            system ("cls");
            cout <<t(80, "TIDAK ADA MENU ")<<menu<<"!\n";
        }
        cout <<endl;
        cout <<t (80, "Tekan ENTER untuk kembali ke Menu Utama");
        getch();

    }
    while (menu!=6);
    return 0;
}
