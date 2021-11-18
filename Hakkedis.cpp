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

#include "Hakkedis.h"
#include "Proje.h"
#include "Urun.h"
#include "Anasayfa.h"


bool Hakkedis::ProjeVarmi(int aranacakProjeNo)
{
	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		if (projeNo == aranacakProjeNo)
		{
			hakkedisDosya.close();
			return true;
		}
	}
	hakkedisDosya.close();
	return false;
}

void Hakkedis::HakkedisListele()
{
	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	cout << setw(11) << " Proje No " << setw(10) << " Hakkedis D�nemi " << setw(15) << " Urun No " << setw(15) << " Urun Adet " << setw(10) << " Fiyat" << endl;
	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		cout << setw(11) << projeNo << setw(10) << hakedisDonemi << setw(15) << urunNo
			<< setw(15)
			<< urunAdet << setw(10) << fiyat << endl;
	}
	hakkedisDosya.close();
}

void Hakkedis::UrunleriListele()
{
	Urun *urun = new Urun();
	HakkedisListele();
	cout << "Hangi hakkedi�i kullanmak istiyorsunuz : "; cin >> kullanilacakProjeNo;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Ad� " << setw(15) << " Urun Markas� " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyas�ndaki projeNo ile kullanaca��m�z projenin no sunu kar��la�t�r�p e�er ayn�larsa urunleri listeliyoruz
		if (kullanilacakProjeNo == projeNo)
		{
			urun->UrunBul(urunNo);
			urun->UrunYazdir();
		}

	}
	hakkedisDosya.close();
}

void Hakkedis::UrunSil()
{
	int silinecekUrunNo;
	UrunleriListele();
	cout << "Silmek istedi�iniz �r�n No: "; cin >> silinecekUrunNo;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	fstream  hakkedisDosyaUpdate;
	hakkedisDosyaUpdate.open("Hakkedis1.txt", ios::in | ios::app);
	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyas�ndaki urunNo ve projeNo ile silinecek �r�n�n no su ve hangi projeden silinece�ini kontrol ediyoruz.
		if (silinecekUrunNo != urunNo && kullanilacakProjeNo == projeNo)
		{
			hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << fiyat << "\n";
		}
	}

	hakkedisDosya.close();
	hakkedisDosyaUpdate.close();
	remove("Hakkedis.txt");
	rename("Hakkedis1.txt", "Hakkedis.txt");

}

void Hakkedis::UrunGuncelle()
{
	Urun *urun = new Urun();
	int guncellenecekUrunNo;
	int yeniUrunNo;
	UrunleriListele();
	cout << "G�ncellemek istedi�iniz �r�n No: "; cin >> guncellenecekUrunNo;

	fstream hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in);

	fstream hakkedisDosyaUpdate;
	hakkedisDosyaUpdate.open("Hakkedis1.txt", ios::app);
	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyas�ndaki g�ncellenecek olan �r�n�n yerini tespit ediyoruz
		if (guncellenecekUrunNo == urunNo && kullanilacakProjeNo == projeNo)
		{
			urun->UrunListele();
			cout << "Eklemek istedi�iniz �r�n� se�in"; cin >> yeniUrunNo;
			// Yeni ekleyece�imiz �r�n var m� diye kontrol ediyoruz
			if (urun->UrunBul(yeniUrunNo))
			{
				cout << "Urun Adet :"; cin >> urunAdet;
				hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << yeniUrunNo << " " << urunAdet << " " << urun->birimFiyat * urunAdet << "\n";
			}
			// E�er yeni �r�n yoksa eski �r�n� tekrar geri yazd�r�yoruz.
			else
			{
				cout << "B�yle bir �r�n yok!!";
				hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << fiyat << "\n";
			}
		}
		// E�er g�ncellenecek �r�n�n nosu de�ilse aynen di�er dosyam�za yazd�r�yoruz.
		else
		{
			hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << fiyat << "\n";
		}
	}

	hakkedisDosya.close();
	hakkedisDosyaUpdate.close();
	remove("Hakkedis.txt");
	rename("Hakkedis1.txt", "Hakkedis.txt");
}

void Hakkedis::UrunArama()
{
	Urun *urun = new Urun();
	HakkedisListele();
	cout << "Hangi hakkedi�i kullanmak istiyorsunuz : "; cin >> kullanilacakProjeNo;

	int bulunacakUrun;
	cout << "Bulmak istedi�iniz �r�n no: "; cin >> bulunacakUrun;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Ad� " << setw(15) << " Urun Markas� " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Hakkedis.txt dosyas�ndaki sat�rlar� al�yoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Aranacak �r�n�n nosunu ald�ktan sonra burada kontrol ediyoruz.
		if (kullanilacakProjeNo == projeNo && bulunacakUrun == urunNo)
		{
			urun->UrunBul(bulunacakUrun);
			urun->UrunYazdir();
		}
	}
	hakkedisDosya.close();
}

void Hakkedis::HakkedisEkle()
{
	Proje *proje = new Proje();
	Urun *urun = new Urun();

	proje->ProjeListele();

	cout << "Hakkedi� eklemek istedi�iniz Proje No : "; cin >> projeNo;
	// Hakkedi� eklerken se�ilen projenin var olup olmad���n� kontrol ediyoruz.
	if (proje->ProjeBul(projeNo))
	{
		urun->UrunListele();
		cout << "Eklemek istedi�iniz �r�n� se�in"; cin >> urunNo;
		// Se�ti�imiz �r�n�n varl���n� kontrol ediyoruz.
		if (urun->UrunBul(urunNo))
		{
			fstream  hakkedisDosya;
			hakkedisDosya.open("Hakkedis.txt", ios::app);
			cout << "\n Hakkedis D�nemi: "; cin >> hakedisDonemi;
			cout << "Urun Adet :"; cin >> urunAdet;

			hakkedisDosya << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << urun->birimFiyat * urunAdet << "\n";

			hakkedisDosya.close();
		}
		// e�er �r�n yoksa eklemiyoruz
		else
		{
			cout << "B�yle bir �r�n yok!!";
		}
	}
	else
	{
		cout << "B�yle bir proje yok!!";
	}
}

void Hakkedis::ToplamTutar()
{
	Proje *proje = new Proje();
	Urun *urun = new Urun();

	int secilecekHakkedisDonemi, secilecekProjeNo, toplamTutar = 0;
	proje->ProjeListele();
	cout << "Hangi Projeyi bulmak istiyorsunuz"; cin >> secilecekProjeNo;
	cout << "Hangi D�nemde bulmak istiyorsunuz"; cin >> secilecekHakkedisDonemi;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	cout << setw(11) << " UrunNo " << setw(10) << " Urun Ad� " << setw(15) << " Urun Markas� " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		if (hakedisDonemi == secilecekHakkedisDonemi && projeNo == secilecekProjeNo)
		{
			urun->UrunBul(urunNo);
			urun->UrunYazdir();
			toplamTutar += fiyat;
		}
	}
	cout << "Toplam Tutar : " << toplamTutar << endl;
}

void Hakkedis::DonemeGoreTutar()
{
	Proje *proje = new Proje;
	int toplamTutar;
	int secilenDonem;
	cout << "Bir D�nem Se�iniz: "; cin >> secilenDonem;

	fstream  hakkedisDosya;
	fstream  projeDosya;
	projeDosya.open("Proje.txt", ios::in | ios::app);

	cout << setw(11) << "ProjeNo" << setw(15) << "Toplam Tutar" << endl;
	// T�m var olan projelerimizi getiriyoruz.
	while (projeDosya >> proje->projeNo >> proje->projeAdi >> proje->projeYurutucuFirma >> proje->projeSorumlusu >> proje->projeKontroloru)
	{
		hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
		toplamTutar = 0;
		// s�rayla gelen projelerin hakkedi� dosyas�nda kar��la�t�r�p fiyatlar�n� topluyoruz.
		while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
		{
			if (projeNo == proje->projeNo)
			{
				toplamTutar += fiyat;
			}
		}
		hakkedisDosya.close();
		cout << setw(11) << proje->projeNo << setw(15) << toplamTutar << endl;
	}
}

void Hakkedis::HakkedisIslemleri()
{
	system("cls");

	int secim;
	cout << "1-) Hakkedi� Ekle " << endl;
	cout << "2-) Hakkedi� �r�nlerini Listele " << endl;
	cout << "3-) Hakkedi� �zerinde �r�n Sil" << endl;
	cout << "4-) Hakkedi� �zerinde �r�n G�ncelle" << endl;
	cout << "5-) Hakkedi� �zerinde �r�n Arama" << endl;
	cout << "6-) ProjeNo ve Hakkedi� D�nemine G�re Toplam Tutar" << endl;
	cout << "7-) Kay�tl� Projelerin Belirtilen D�neme G�re Tutarlar�" << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) �IKI� " << endl;
	cout << "SE��M�N�Z.....:";
	cin >> secim;


	// Hakkedi� Ekleme
	if (secim == 1)
	{
		HakkedisEkle();
		HakkedisIslemleri();
	}
	// Hakkedi�e ba�l� �r�nleri listele
	else if (secim == 2)
	{
		UrunleriListele();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkedi�e ba�l� �r�nleri silme
	else if (secim == 3)
	{
		UrunSil();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkedi�e ba�l� �r�nleri g�ncelleme
	else if (secim == 4)
	{
		UrunGuncelle();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkedi�e ba�l� �r�nleri arama
	else if (secim == 5)
	{
		UrunArama();
		system("pause");
		HakkedisIslemleri();
	}
	// ProjeNo ve Hakkedi� D�nemine G�re Toplam tutar
	else if (secim == 6)
	{
		ToplamTutar();
		system("pause");
		HakkedisIslemleri();
	}
	// Kay�tl� Projelerin Belirtilen D�neme G�re Tutarlar�
	else if (secim == 7)
	{
		DonemeGoreTutar();
		system("pause");
		HakkedisIslemleri();
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
		cout << "Yanl�� Se�im Yapt�n�z"; system("cls"); system("pause"); HakkedisIslemleri();
	}

}