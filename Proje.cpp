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

#include "Proje.h"
#include "Hakkedis.h"
#include "Anasayfa.h"

int Proje::SonProjeNoGet()
{
	ifstream projeDosya;
	projeDosya.open("Proje.txt");

	projeNo = 0;
	// Proje.txt dosyas�ndaki sat�rlar� al�yoruz
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

	cout << "\n Proje Ad�: "; cin >> projeAdi;
	cout << "\n Proje Y�r�t�c� Firma: "; cin >> projeYurutucuFirma;
	cout << "\n Proje Sorumlusu: "; cin >> projeSorumlusu;
	cout << "\n Proje Kontrol�r�: "; cin >> projeKontroloru;

	projeDosya << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";

	projeDosya.close();
}

void Proje::ProjeGuncelle()
{
	int duzenlenecekProjeNo;
	ProjeListele();
	cout << "D�zenlemek istedi�iniz Proje No: "; cin >> duzenlenecekProjeNo;

	fstream  projeDosya;
	fstream  projeDosyaUpdate;
	projeDosyaUpdate.open("Proje1.txt", ios::app | ios::in);
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyas�ndaki sat�rlar� al�yoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyas�ndaki proje ile elimizdeki projeNo yu kar��la�t�r�yoruz.
		if (projeNo == duzenlenecekProjeNo)
		{
			cout << "\n Proje Ad�: "; cin >> projeAdi;
			cout << "\n Proje Y�r�t�c� Firma: "; cin >> projeYurutucuFirma;
			cout << "\n Proje Sorumlusu: "; cin >> projeSorumlusu;
			cout << "\n Proje Kontrol�r�: "; cin >> projeKontroloru;
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

	cout << "Proje de�i�tirme ba�ar�l� \n";
}

bool Proje::ProjeBul(int aranacakProjeNo)
{

	fstream projeDosya;
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyas�ndaki sat�rlar� al�yoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyas�nda parametre olarak gelen proje no ile arama yap�yoruz
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

	cout << setw(11) << " projeNo " << setw(15) << " Proje Ad� " << setw(20) << " Proje Y�r�t�c� Firma " << setw(20) << " Proje Sorumlusu " << setw(20) << " Proje Kontroloru" << endl;
	// Proje.txt dosyas�ndaki sat�rlar� al�yoruz
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
	cout << "Silmek istedi�iniz Proje No: "; cin >> silinecekProjeNo;

	// Silece�imiz projenin hakkedi�i var m� diye kontrol ediyoruz. Varsa anasayfam�za y�nlendiriyoruz.
	if (hakkedis->ProjeVarmi(silinecekProjeNo))
	{
		cout << "Proje Hakkedi�i Mevcuttur!!" << endl;
		system("pause");
		ProjeIslemleri();
	}

	fstream projeDosya;
	fstream  projeDosyaUpdate;
	projeDosyaUpdate.open("Proje1.txt", ios::app | ios::in);
	projeDosya.open("Proje.txt", ios::in);
	// Proje.txt dosyas�ndaki sat�rlar� al�yoruz
	while (projeDosya >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru)
	{
		// Proje.txt dosyas�nda silece�imiz projeNo yu ar�yoruz
		if (projeNo != silinecekProjeNo)
		{
			projeDosyaUpdate << projeNo << " " << projeAdi << " " << projeYurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru << "\n";
		}
	}

	projeDosya.close();
	projeDosyaUpdate.close();
	remove("Proje.txt");
	rename("Proje1.txt", "Proje.txt");

	cout << "Proje Silme ba�ar�l� \n";
}

void Proje::ProjeYazdir()
{
	cout << setw(11) << " projeNo " << setw(15) << " Proje Ad� " << setw(20) << " Proje Y�r�t�c� Firma " << setw(20) << " Proje Sorumlusu " << setw(20) << " Proje Kontroloru" << endl;
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
	cout << "2-) Proje G�ncelle " << endl;
	cout << "3-) Proje Sil " << endl;
	cout << "4-) Proje Listele " << endl;
	cout << "5-) Proje Arama " << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) �IKI� " << endl;
	cout << "SE��M�N�Z.....:";
	cin >> secim;


	// Proje Ekleme
	if (secim == 1)
	{
		ProjeEkle();
		ProjeIslemleri();
	}
	// Proje G�ncelleme
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
	// �r�n Listeleme
	else if (secim == 4)
	{
		ProjeListele();
		system("pause");
		ProjeIslemleri();
	}
	else if (secim == 5)
	{
		int aranacakProjeNo;
		cout << "Aramak istedi�iniz Proje No: "; cin >> aranacakProjeNo;
		ProjeBul(aranacakProjeNo);
		ProjeYazdir();
		system("pause");
		ProjeIslemleri();
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
		cout << "Yanl�� Se�im Yapt�n�z"; system("pause"); system("cls"); ProjeIslemleri();
	}
}