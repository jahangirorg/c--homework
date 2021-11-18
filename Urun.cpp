/****************************************************************************
**									SAKARYA �N�VERS�TES�
**							B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**								B�LG�SAYAR M�HEND�SL��� B�L�M�
**								PROGRAMLAMAYA G�R��� DERS�
**
**							�DEV NUMARASI.............: 1
**							��RENC� ADI...............: Jahangir Khalilbayli
**							��RENC� NUMARASI..........: b151210572
**							DERS GRUBU................: 1A
****************************************************************************/

#include "Urun.h"
#include "Anasayfa.h"
#include <iostream>
#include<fstream> //Dosyalama i�lemleri i�in kullan�ld�.
#include<string>
#include <sstream> //String t�r�ndeki de�i�keni int'e �evirmek i�in kullan�ld�.
#include <stdio.h>
#include <iomanip>

using namespace std;

int Urun::sonUrunNoGet()
{
	ifstream urunDosya;
	urunDosya.open("Urun.txt");

	int urunNo = 0;
	// Urun.txt dosyas�ndaki sat�rlar� al�yoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		continue;
	}
	urunDosya.close();

	return urunNo + 1;
}

void Urun::UrunEkle()
{
	urunNo = sonUrunNoGet();

	fstream  urunDosya;
	urunDosya.open("Urun.txt", ios::app);

	cout << "\n Ur�n Ad�: "; cin >> urunAdi;
	cout << "\n Ur�n Markas�: "; cin >> marka;
	cout << "\n Ur�n Birimi: "; cin >> birim;
	cout << "\n Ur�n Birim Fiyat�: "; cin >> birimFiyat;
	urunDosya << urunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";

	urunDosya.close();
}

void Urun::UrunGuncelle()
{
	UrunListele();

	int duzenlenecekUrunNo;
	cout << "D�zenlemek istedi�iniz �r�n No: "; cin >> duzenlenecekUrunNo;

	fstream  urunDosya;
	fstream  urunDosyaUpdate;
	urunDosyaUpdate.open("Urun1.txt", ios::app | ios::in);
	urunDosya.open("Urun.txt", ios::in);
	// Urun.txt dosyas�ndaki sat�rlar� al�yoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// Urun.txt dosyas�ndaki g�ncellenecek �r�n� ar�yoruz
		if (urunNo == duzenlenecekUrunNo)
		{
			cout << "\n Ur�n Ad�: "; cin >> urunAdi;
			cout << "\n Ur�n Markas�: "; cin >> marka;
			cout << "\n Ur�n Birimi: "; cin >> birim;
			cout << "\n Ur�n Birim Fiyat�: "; cin >> birimFiyat;
			urunDosyaUpdate << duzenlenecekUrunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";
		}
		else
		{
			urunDosyaUpdate << urunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";
		}
	}

	urunDosya.close();
	urunDosyaUpdate.close();
	remove("Urun.txt");
	rename("Urun1.txt", "Urun.txt");

	cout << "�r�n de�i�tirme ba�ar�l� \n";
}

void Urun::UrunSil()
{
	UrunListele();

	int silinecekUrunNo;
	cout << "Silmek istedi�iniz �r�n No: "; cin >> silinecekUrunNo;

	fstream  urunDosya;
	fstream  urunDosyaUpdate;
	urunDosyaUpdate.open("Urun1.txt", ios::app | ios::in);
	urunDosya.open("Urun.txt", ios::in);
	// Urun.txt dosyas�ndaki sat�rlar� al�yoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// Urun.txt dosyas�ndaki silinecek �r�n� ar�yoruz. E�er yoksa yeni dosyaya ekliyoruz.
		if (urunNo != silinecekUrunNo)
		{
			urunDosyaUpdate << urunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";
		}
	}

	urunDosya.close();
	urunDosyaUpdate.close();
	remove("Urun.txt");
	rename("Urun1.txt", "Urun.txt");

	cout << "�r�n Silme ba�ar�l� \n";
}

void Urun::UrunListele()
{
	fstream  urunDosya;
	urunDosya.open("Urun.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Ad� " << setw(15) << " Urun Markas� " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Urun.txt dosyas�ndaki sat�rlar� al�yoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		cout << setw(11) << urunNo << setw(10) << urunAdi << setw(15) << marka
			<< setw(10)
			<< birim << setw(10) << birimFiyat << endl;
	}
	urunDosya.close();
}

void Urun::UrunYazdir()
{
	cout << setw(11) << urunNo << setw(10) << urunAdi << setw(15) << marka
		<< setw(10)
		<< birim << setw(10) << birimFiyat << endl;
}

bool Urun::UrunBul(int bulunacakUrunNo)
{
	fstream urunDosya;
	urunDosya.open("Urun.txt", ios::in | ios::app);
	// Urun.txt dosyas�ndaki sat�rlar� al�yoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// // Urun.txt dosyas�ndaki �r�n� ar�yoruz. E�er bulunursa geriye true olarak d�necek
		if (bulunacakUrunNo == urunNo)
		{
			urunDosya.close();
			return true;
		}
	}
	return false;

}

void Urun::UrunIslemleri()
{
	system("cls");

	int urunNo, birim, birimFiyat;
	string urunAdi, marka;

	int secim;
	cout << "1-) �r�n Ekle " << endl;
	cout << "2-) �r�n G�ncelle " << endl;
	cout << "3-) �r�n Sil " << endl;
	cout << "4-) �r�n Listele " << endl;
	cout << "5-) �r�n Arama " << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) �IKI� " << endl;
	cout << "SE��M�N�Z.....:";
	cin >> secim;


	// �r�n Ekleme
	if (secim == 1)
	{
		UrunEkle();
		UrunIslemleri();
	}
	// �r�n G�ncelleme
	else if (secim == 2)
	{
		UrunGuncelle();
		system("pause");
		UrunIslemleri();
	}
	// �r�n Silme
	else if (secim == 3)
	{
		UrunSil();
		system("pause");
		UrunIslemleri();
	}
	// �r�n Listeleme
	else if (secim == 4)
	{
		UrunListele();
		system("pause");
		UrunIslemleri();
	}
	// �r�n Arama
	else if (secim == 5)
	{
		int bulunacakUrunNo;
		cout << "Bulmak istedi�iniz �r�n No: "; cin >> bulunacakUrunNo;
		UrunBul(bulunacakUrunNo);
		cout << setw(11) << " UrunNo " << setw(10) << " Urun Ad� " << setw(15) << " Urun Markas� " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
		UrunYazdir();
		system("pause");
		UrunIslemleri();
	}
	// Anasayfaya y�nlendir
	else if (secim == 8)
	{
		Anasayfa *anasayfa = new Anasayfa;
		anasayfa->calistir();
	}
	// ��k��
	else if (secim == 9)
	{
		exit(0);
	}
	// Yanl�� Se�im
	else
	{
		cout << "Yanl�� Se�im Yapt�n�z"; system("pause"); system("cls"); UrunIslemleri();
	}
}