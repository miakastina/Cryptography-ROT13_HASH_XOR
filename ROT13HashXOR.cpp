//Created by Mia Kastina
//   NIM 2015-81-178
#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
using namespace std;
void dec(unsigned char y)
{
	cout<<" :  "<<y<<"\t: "<<(int)y<<"\t\t"<<": ";
}
void binary(unsigned char x)
{
	for (int i=7; i>=0; i--)
    {
		if(x >= pow(2,i))
		{
			cout<<"1";
			x = x - pow(2,i);
		}
		else
		cout<<"0";
	}
} 
void garis()
{
	cout <<" ****************************************\n";	  
}
void headerAwal()
{
	cout<<" ........................................ \n";
	cout<<" :    PROGRAM ENKRIPSI DAN DESKRIPSI    : \n";
	cout<<" :         MENGGUNAKAN METODE           : \n";
	cout<<" :       ROT13, HASHING dan XOR         : \n";
	cout<<" ........................................ \n\n";
}
void headerAscii()
{
	cout<<" Tampilan Kode ASCII\n";
	garis();
	cout<<" : Char"<<"\t"<<":"<<" Decimal "<<"\t"<<":"<<" Binary "<<"\t"<<":\n";
	garis();
}
void headerProsesXOR()
{
	cout<<" ============== PROSES XOR ==============\n"; 
	cout<<" ==============  ENKRIPSI  ==============\n\n";
}
void headerStlhEnkripsi()
{
	cout<<"        Pesan Setelah di Enkripsi        \n";
	cout<<" ========================================\n";
	cout<<"\n"<<" ";
}
void headerProsesDeskripsi()
{
	cout<<" ============Proses Deskripsi============\n"; 
	cout<<" ========================================\n";
}
void headerPD()
{	
	cout<<" Kode ASCII\n";
	cout<<" Binary"<<"\t"<<"  => "<<"Decimal"<<"\t"<<" => "<<"\t"<<"Char\n";
	garis();
}
void headerStlhDeskripsi()
{
	cout <<"        Pesan Setelah di Deskripsi       \n";
	cout <<" ========================================\n";
	cout <<"\n"<<" ";
}
void CreatedBy()
{
	char n[20]= {78,97,109,97,32,58,32,77,105,97,32,75,97,115,116,105,110,97};
	char m[20]= {78,73,77,32,32,58,32,50,48,49,53,45,56,49,45,49,55,56};
	int i;
	cout <<" ========================================\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
	 	cout<<n[i];
	}	
	cout<<"\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
		cout<<m[i];
	}
	cout<<"\n"<<" ========================================\n";
}
template <typename Iter>
void rot13(Iter begin, const Iter& end) 
{
    while (begin != end) {
        unsigned char& c = *begin;
        if (c >= 'a' && c <= 'm') {
            c += 13;
        } else if (c >= 'n' && c <= 'z') {
            c -= 13;
        } else if (c >= 'A' && c <= 'M') {
            c += 13;
        } else if (c >= 'N' && c <= 'Z') {
            c -= 13;
        }
        ++begin;
    }
}
int main()
{
unsigned char pesan [100],kunci[100],enkripsi [100],deskripsi [100];
int panjang_data,panjang_data_kunci,i,j=0;
unsigned int ascii[100],ascii_kunci [100],ascii_enkripsi [100],ascii_deskripsi [100];
headerAwal();
cout<<" SILAHKAN MASUKKAN PESAN\n";
cin.sync();
cout <<" Pesan = ";
cin.get((char*)pesan,100);
panjang_data = strlen ((char*)pesan); 
cout<<" Panjang Data Pesan = "<<panjang_data<<"\n\n"; 
	headerAscii();
	for (i=0; i<=panjang_data-1; i++)
			{
				ascii[i] = int (pesan[i]); 
				dec(pesan[i]);
				binary(pesan[i]);
				cout<<"\t"<<":\n";
			}
	garis();
cout<<endl;
cout <<" SILAHKAN MASUKKAN KUNCI \n"; 
cin.sync();
cout <<" Kunci : ";
cin.get((char*)kunci,100);
panjang_data_kunci = strlen ((char*)kunci);
cout<<" Panjang Data Kunci = "<<panjang_data_kunci<<"\n\n";
headerAscii();
	for (i=0; i<=panjang_data_kunci-1; i++)
	{
		ascii_kunci[i] = kunci[i];
		dec(kunci[i]);
		binary(kunci[i]);
		cout<<"\t"<<":\n";
	}
	garis();
cout<<endl;
cout<<" Hasil ROT13 = ";
rot13(kunci, kunci + strlen((char*)kunci));
std::cout << kunci << std::endl;
int hash = 1;
    for (int i = 0; i <=panjang_data_kunci-1; i++) 
	{
        hash = 31 * hash + kunci[i];
    }
	headerAscii();
	for (i=0; i<=panjang_data_kunci-1; i++)
	{
		ascii_kunci[i] = hash;
		dec(kunci[i]);
		binary(kunci[i]);
		cout<<"\t"<<":\n";
	}
	garis();
cout<<endl;
cout<<" Kunci yang telah dihash : "<<hash<<endl<< " karakter \t: "<<char(hash)<<endl;
cout<<" Binary \t: ";
binary(int(hash));
cout<<"\n\n"; 
headerProsesXOR();
	for (i=0; i<=panjang_data-1; i++)
	{
		cout<<" ";
		binary(pesan[i]);
		cout<<"  "<<" XOR "<<"  ";
		binary(int (hash));
		cout<<"   =   ";
		ascii_enkripsi[i] = ascii[i] ^ ascii_kunci[j]; 
		j = j + 1;		
			if (j == panjang_data_kunci)
			{
				j = 0;
			}
		enkripsi [i] = int (ascii_enkripsi[i]);
		binary(enkripsi[i]);
		cout<<endl;
		cout<<"\t\t  Decimal "<<"   =   "<<int(enkripsi[i])<<"\n"
			<<"\t\t  Char "<<"\t     =   "<<enkripsi[i]<<endl;
	}
cout<<endl;
	headerStlhEnkripsi();
	for (i=0; i<=panjang_data-1; i++)
	{
		cout<<enkripsi[i]<<" ";
	}
cout<<"\n\n\n";
	headerProsesDeskripsi();
	cout<<"             *Pesan Enkripsi*            \n";
	headerPD();
	for (i=0; i<=panjang_data-1; i++)
	{
		ascii_deskripsi[i] = enkripsi[i] ;
		cout <<" ";
		binary(enkripsi[i]);
		cout<<" => "<<int (enkripsi[i])<<" "<<"\t"<<" => " <<"\t"<<enkripsi [i]<< endl;
	}
cout<<"\n\n";
	cout<<" HASIL\n\n";
	cout<<"            *Pesan Deskripsi*            \n";
	headerPD();
	for (i=0; i<=panjang_data_kunci-1; i++)
	{
		ascii_kunci[i] = hash;
	}
	garis();
	for (i=0; i<=panjang_data-1; i++)
	{	
		ascii_deskripsi[i] = ascii [i];
		ascii_deskripsi[i] = enkripsi[i] ^ ascii_kunci[j]; 
		j = j + 1;
			if (j == panjang_data_kunci)
			{
				j = 0;
			}	
	deskripsi[i]= int(ascii_deskripsi[i]);
	cout<<" ";
	binary(deskripsi[i]);
	cout<<" => "<<int(deskripsi[i])<<" "<<"\t"<<" =>"<<"\t"<<deskripsi[i]<<endl;
	}
cout <<endl;
	headerStlhDeskripsi();
	for (i=0; i<=panjang_data-1; i++)
	{
		cout <<deskripsi[i]<<" " ;
	}
cout<<endl<<endl;
	CreatedBy();
return 0;
}

