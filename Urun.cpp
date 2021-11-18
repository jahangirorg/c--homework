/****************************************************************************
**									SAKARYA ÜNÝVERSÝTESÝ
**							BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**								BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**								PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**							ÖDEV NUMARASI.............: 1
**							ÖÐRENCÝ ADI...............: Jahangir Khalilbayli
**							ÖÐRENCÝ NUMARASI..........: b151210572
**							DERS GRUBU................: 1A
****************************************************************************/

#include "Urun.h"
#include "Anasayfa.h"
#include <iostream>
#include<fstream> //Dosyalama iþlemleri için kullanýldý.
#include<string>
#include <sstream> //String türündeki deðiþkeni int'e çevirmek için kullanýldý.
#include <stdio.h>
#include <iomanip>

using namespace std;

int Urun::sonUrunNoGet()
{
	ifstream urunDosya;
	urunDosya.open("Urun.txt");

	int urunNo = 0;
	// Urun.txt dosyasýndaki satýrlarý alýyoruz
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

	cout << "\n Urün Adý: "; cin >> urunAdi;
	cout << "\n Urün Markasý: "; cin >> marka;
	cout << "\n Urün Birimi: "; cin >> birim;
	cout << "\n Urün Birim Fiyatý: "; cin >> birimFiyat;
	urunDosya << urunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";

	urunDosya.close();
}

void Urun::UrunGuncelle()
{
	UrunListele();

	int duzenlenecekUrunNo;
	cout << "Düzenlemek istediðiniz ürün No: "; cin >> duzenlenecekUrunNo;

	fstream  urunDosya;
	fstream  urunDosyaUpdate;
	urunDosyaUpdate.open("Urun1.txt", ios::app | ios::in);
	urunDosya.open("Urun.txt", ios::in);
	// Urun.txt dosyasýndaki satýrlarý alýyoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// Urun.txt dosyasýndaki güncellenecek ürünü arýyoruz
		if (urunNo == duzenlenecekUrunNo)
		{
			cout << "\n Urün Adý: "; cin >> urunAdi;
			cout << "\n Urün Markasý: "; cin >> marka;
			cout << "\n Urün Birimi: "; cin >> birim;
			cout << "\n Urün Birim Fiyatý: "; cin >> birimFiyat;
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

	cout << "Ürün deðiþtirme baþarýlý \n";
}

void Urun::UrunSil()
{
	UrunListele();

	int silinecekUrunNo;
	cout << "Silmek istediðiniz ürün No: "; cin >> silinecekUrunNo;

	fstream  urunDosya;
	fstream  urunDosyaUpdate;
	urunDosyaUpdate.open("Urun1.txt", ios::app | ios::in);
	urunDosya.open("Urun.txt", ios::in);
	// Urun.txt dosyasýndaki satýrlarý alýyoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// Urun.txt dosyasýndaki silinecek ürünü arýyoruz. Eðer yoksa yeni dosyaya ekliyoruz.
		if (urunNo != silinecekUrunNo)
		{
			urunDosyaUpdate << urunNo << " " << urunAdi << " " << marka << " " << birim << " " << birimFiyat << "\n";
		}
	}

	urunDosya.close();
	urunDosyaUpdate.close();
	remove("Urun.txt");
	rename("Urun1.txt", "Urun.txt");

	cout << "Ürün Silme baþarýlý \n";
}

void Urun::UrunListele()
{
	fstream  urunDosya;
	urunDosya.open("Urun.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Adý " << setw(15) << " Urun Markasý " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Urun.txt dosyasýndaki satýrlarý alýyoruz
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
	// Urun.txt dosyasýndaki satýrlarý alýyoruz
	while (urunDosya >> urunNo >> urunAdi >> marka >> birim >> birimFiyat)
	{
		// // Urun.txt dosyasýndaki ürünü arýyoruz. Eðer bulunursa geriye true olarak dönecek
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
	cout << "1-) Ürün Ekle " << endl;
	cout << "2-) Ürün Güncelle " << endl;
	cout << "3-) Ürün Sil " << endl;
	cout << "4-) Ürün Listele " << endl;
	cout << "5-) Ürün Arama " << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) ÇIKIÞ " << endl;
	cout << "SEÇÝMÝNÝZ.....:";
	cin >> secim;


	// Ürün Ekleme
	if (secim == 1)
	{
		UrunEkle();
		UrunIslemleri();
	}
	// Ürün Güncelleme
	else if (secim == 2)
	{
		UrunGuncelle();
		system("pause");
		UrunIslemleri();
	}
	// Ürün Silme
	else if (secim == 3)
	{
		UrunSil();
		system("pause");
		UrunIslemleri();
	}
	// Ürün Listeleme
	else if (secim == 4)
	{
		UrunListele();
		system("pause");
		UrunIslemleri();
	}
	// Ürün Arama
	else if (secim == 5)
	{
		int bulunacakUrunNo;
		cout << "Bulmak istediðiniz ürün No: "; cin >> bulunacakUrunNo;
		UrunBul(bulunacakUrunNo);
		cout << setw(11) << " UrunNo " << setw(10) << " Urun Adý " << setw(15) << " Urun Markasý " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
		UrunYazdir();
		system("pause");
		UrunIslemleri();
	}
	// Anasayfaya yönlendir
	else if (secim == 8)
	{
		Anasayfa *anasayfa = new Anasayfa;
		anasayfa->calistir();
	}
	// Çýkýþ
	else if (secim == 9)
	{
		exit(0);
	}
	// Yanlýþ Seçim
	else
	{
		cout << "Yanlýþ Seçim Yaptýnýz"; system("pause"); system("cls"); UrunIslemleri();
	}
}