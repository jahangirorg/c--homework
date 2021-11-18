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

#include "Proje.h"
#include "Hakkedis.h"
#include "Anasayfa.h"

int Proje::SonProjeNoGet()
{
	ifstream projeDosya;
	projeDosya.open("Proje.txt");

	projeNo = 0;
	// Proje.txt dosyasýndaki satýrlarý alýyoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		continue;
	}
	projeDosya.close();

	return projeNo + 1;
}

void Proje::ProjeEkle()
{
	fstream projeDosya;
	projeDosya.open("Proje.txt", ios::app);
	projeNo = SonProjeNoGet();

	cout << "\n Proje Adý: "; cin >> projeAdi;
	cout << "\n Proje Yürütücü Firma: "; cin >> projeYurutucuFirma;
	cout << "\n Proje Sorumlusu: "; cin >> projeSorumlusu;
	cout << "\n Proje Kontrolörü: "; cin >> projeKontroloru;

	projeDosya << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";

	projeDosya.close();
}

void Proje::ProjeGuncelle()
{
	int duzenlenecekProjeNo;
	ProjeListele();
	cout << "Düzenlemek istediðiniz Proje No: "; cin >> duzenlenecekProjeNo;

	fstream  projeDosya;
	fstream  projeDosyaUpdate;
	projeDosyaUpdate.open("Proje1.txt", ios::app | ios::in);
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyasýndaki satýrlarý alýyoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyasýndaki proje ile elimizdeki projeNo yu karþýlaþtýrýyoruz.
		if (projeNo == duzenlenecekProjeNo)
		{
			cout << "\n Proje Adý: "; cin >> projeAdi;
			cout << "\n Proje Yürütücü Firma: "; cin >> projeYurutucuFirma;
			cout << "\n Proje Sorumlusu: "; cin >> projeSorumlusu;
			cout << "\n Proje Kontrolörü: "; cin >> projeKontroloru;
			projeDosyaUpdate << duzenlenecekProjeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";
		}
		else
		{
			projeDosyaUpdate << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";
		}
	}

	projeDosya.close();
	projeDosyaUpdate.close();
	remove("Proje.txt");
	rename("Proje1.txt", "Proje.txt");

	cout << "Proje deðiþtirme baþarýlý \n";
}

bool Proje::ProjeBul(int aranacakProjeNo)
{

	fstream projeDosya;
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyasýndaki satýrlarý alýyoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyasýnda parametre olarak gelen proje no ile arama yapýyoruz
		if (projeNo == aranacakProjeNo)
		{
			projeDosya.close();
			return true;
		}
	}
	return false;
}

void Proje::ProjeListele()
{
	fstream projeDosya;
	projeDosya.open("Proje.txt", ios::in);

	cout << setw(11) << " projeNo " << setw(15) << " Proje Adý " << setw(20) << " Proje Yürütücü Firma " << setw(20) << " Proje Sorumlusu " << setw(20) << " Proje Kontroloru" << endl;
	// Proje.txt dosyasýndaki satýrlarý alýyoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		cout << setw(11) << projeNo << setw(15) << projeAdi << setw(20) << projeYurutucuFirma
			<< setw(20)
			<< projeSorumlusu << setw(20) << projeKontroloru << endl;
	}
	projeDosya.close();
}

void Proje::ProjeSil()
{

	ProjeListele();
	Hakkedis *hakkedis = new Hakkedis;

	int silinecekProjeNo;
	cout << "Silmek istediðiniz Proje No: "; cin >> silinecekProjeNo;

	// Sileceðimiz projenin hakkediþi var mý diye kontrol ediyoruz. Varsa anasayfamýza yönlendiriyoruz.
	if (hakkedis->ProjeVarmi(silinecekProjeNo))
	{
		cout << "Proje Hakkediþi Mevcuttur!!" << endl;
		system("pause");
		ProjeIslemleri();
	}

	fstream projeDosya;
	fstream  projeDosyaUpdate;
	projeDosyaUpdate.open("Proje1.txt", ios::app | ios::in);
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyasýndaki satýrlarý alýyoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyasýnda sileceðimiz projeNo yu arýyoruz
		if (projeNo != silinecekProjeNo)
		{
			projeDosyaUpdate << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";
		}
	}

	projeDosya.close();
	projeDosyaUpdate.close();
	remove("Proje.txt");
	rename("Proje1.txt", "Proje.txt");

	cout << "Proje Silme baþarýlý \n";
}

void Proje::ProjeYazdir()
{
	cout << setw(11) << " projeNo " << setw(15) << " Proje Adý " << setw(20) << " Proje Yürütücü Firma " << setw(20) << " Proje Sorumlusu " << setw(20) << " Proje Kontroloru" << endl;
	cout << setw(11) << projeNo << setw(15) << projeAdi << setw(20) << projeYurutucuFirma
		<< setw(20)
		<< projeSorumlusu << setw(20) << projeKontroloru << endl;
}



void Proje::ProjeIslemleri()
{
	system("cls");

	int projeNo;
	string projeAdi, projeYurutucuFirma, projeSorumlusu, projeKontroloru;

	int secim;
	cout << "1-) Proje Ekle " << endl;
	cout << "2-) Proje Güncelle " << endl;
	cout << "3-) Proje Sil " << endl;
	cout << "4-) Proje Listele " << endl;
	cout << "5-) Proje Arama " << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) ÇIKIÞ " << endl;
	cout << "SEÇÝMÝNÝZ.....:";
	cin >> secim;


	// Proje Ekleme
	if (secim == 1)
	{
		ProjeEkle();
		ProjeIslemleri();
	}
	// Proje Güncelleme
	else if (secim == 2)
	{
		ProjeGuncelle();
		system("pause");
		ProjeIslemleri();
	}
	// Proje Silme
	else if (secim == 3)
	{
		ProjeSil();
		system("pause");
		ProjeIslemleri();
	}
	// Ürün Listeleme
	else if (secim == 4)
	{
		ProjeListele();
		system("pause");
		ProjeIslemleri();
	}
	else if (secim == 5)
	{
		int aranacakProjeNo;
		cout << "Aramak istediðiniz Proje No: "; cin >> aranacakProjeNo;
		ProjeBul(aranacakProjeNo);
		ProjeYazdir();
		system("pause");
		ProjeIslemleri();
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
		cout << "Yanlýþ Seçim Yaptýnýz"; system("pause"); system("cls"); ProjeIslemleri();
	}
}