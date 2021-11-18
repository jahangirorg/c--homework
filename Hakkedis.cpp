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

#include "Hakkedis.h"
#include "Proje.h"
#include "Urun.h"
#include "Anasayfa.h"


bool Hakkedis::ProjeVarmi(int aranacakProjeNo)
{
	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
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

	cout << setw(11) << " Proje No " << setw(10) << " Hakkedis Dönemi " << setw(15) << " Urun No " << setw(15) << " Urun Adet " << setw(10) << " Fiyat" << endl;
	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
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
	cout << "Hangi hakkediþi kullanmak istiyorsunuz : "; cin >> kullanilacakProjeNo;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Adý " << setw(15) << " Urun Markasý " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyasýndaki projeNo ile kullanacaðýmýz projenin no sunu karþýlaþtýrýp eðer aynýlarsa urunleri listeliyoruz
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
	cout << "Silmek istediðiniz ürün No: "; cin >> silinecekUrunNo;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	fstream  hakkedisDosyaUpdate;
	hakkedisDosyaUpdate.open("Hakkedis1.txt", ios::in | ios::app);
	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyasýndaki urunNo ve projeNo ile silinecek ürünün no su ve hangi projeden silineceðini kontrol ediyoruz.
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
	cout << "Güncellemek istediðiniz ürün No: "; cin >> guncellenecekUrunNo;

	fstream hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in);

	fstream hakkedisDosyaUpdate;
	hakkedisDosyaUpdate.open("Hakkedis1.txt", ios::app);
	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Hakkedis.txt dosyasýndaki güncellenecek olan ürünün yerini tespit ediyoruz
		if (guncellenecekUrunNo == urunNo && kullanilacakProjeNo == projeNo)
		{
			urun->UrunListele();
			cout << "Eklemek istediðiniz ürünü seçin"; cin >> yeniUrunNo;
			// Yeni ekleyeceðimiz ürün var mý diye kontrol ediyoruz
			if (urun->UrunBul(yeniUrunNo))
			{
				cout << "Urun Adet :"; cin >> urunAdet;
				hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << yeniUrunNo << " " << urunAdet << " " << urun->birimFiyat * urunAdet << "\n";
			}
			// Eðer yeni ürün yoksa eski ürünü tekrar geri yazdýrýyoruz.
			else
			{
				cout << "Böyle bir ürün yok!!";
				hakkedisDosyaUpdate << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << fiyat << "\n";
			}
		}
		// Eðer güncellenecek ürünün nosu deðilse aynen diðer dosyamýza yazdýrýyoruz.
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
	cout << "Hangi hakkediþi kullanmak istiyorsunuz : "; cin >> kullanilacakProjeNo;

	int bulunacakUrun;
	cout << "Bulmak istediðiniz ürün no: "; cin >> bulunacakUrun;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
	cout << setw(11) << " UrunNo " << setw(10) << " Urun Adý " << setw(15) << " Urun Markasý " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
	// Hakkedis.txt dosyasýndaki satýrlarý alýyoruz
	while (hakkedisDosya >> projeNo >> hakedisDonemi >> urunNo >> urunAdet >> fiyat)
	{
		// Aranacak ürünün nosunu aldýktan sonra burada kontrol ediyoruz.
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

	cout << "Hakkediþ eklemek istediðiniz Proje No : "; cin >> projeNo;
	// Hakkediþ eklerken seçilen projenin var olup olmadýðýný kontrol ediyoruz.
	if (proje->ProjeBul(projeNo))
	{
		urun->UrunListele();
		cout << "Eklemek istediðiniz ürünü seçin"; cin >> urunNo;
		// Seçtiðimiz ürünün varlýðýný kontrol ediyoruz.
		if (urun->UrunBul(urunNo))
		{
			fstream  hakkedisDosya;
			hakkedisDosya.open("Hakkedis.txt", ios::app);
			cout << "\n Hakkedis Dönemi: "; cin >> hakedisDonemi;
			cout << "Urun Adet :"; cin >> urunAdet;

			hakkedisDosya << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdet << " " << urun->birimFiyat * urunAdet << "\n";

			hakkedisDosya.close();
		}
		// eðer ürün yoksa eklemiyoruz
		else
		{
			cout << "Böyle bir ürün yok!!";
		}
	}
	else
	{
		cout << "Böyle bir proje yok!!";
	}
}

void Hakkedis::ToplamTutar()
{
	Proje *proje = new Proje();
	Urun *urun = new Urun();

	int secilecekHakkedisDonemi, secilecekProjeNo, toplamTutar = 0;
	proje->ProjeListele();
	cout << "Hangi Projeyi bulmak istiyorsunuz"; cin >> secilecekProjeNo;
	cout << "Hangi Dönemde bulmak istiyorsunuz"; cin >> secilecekHakkedisDonemi;

	fstream  hakkedisDosya;
	hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);

	cout << setw(11) << " UrunNo " << setw(10) << " Urun Adý " << setw(15) << " Urun Markasý " << setw(15) << " Birim " << setw(10) << " Birim Fiyat" << endl;
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
	cout << "Bir Dönem Seçiniz: "; cin >> secilenDonem;

	fstream  hakkedisDosya;
	fstream  projeDosya;
	projeDosya.open("Proje.txt", ios::in | ios::app);

	cout << setw(11) << "ProjeNo" << setw(15) << "Toplam Tutar" << endl;
	// Tüm var olan projelerimizi getiriyoruz.
	while (projeDosya >> proje->projeNo >> proje->projeAdi >> proje->projeYurutucuFirma >> proje->projeSorumlusu >> proje->projeKontroloru)
	{
		hakkedisDosya.open("Hakkedis.txt", ios::in | ios::app);
		toplamTutar = 0;
		// sýrayla gelen projelerin hakkediþ dosyasýnda karþýlaþtýrýp fiyatlarýný topluyoruz.
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
	cout << "1-) Hakkediþ Ekle " << endl;
	cout << "2-) Hakkediþ Ürünlerini Listele " << endl;
	cout << "3-) Hakkediþ Üzerinde Ürün Sil" << endl;
	cout << "4-) Hakkediþ Üzerinde Ürün Güncelle" << endl;
	cout << "5-) Hakkediþ Üzerinde Ürün Arama" << endl;
	cout << "6-) ProjeNo ve Hakkediþ Dönemine Göre Toplam Tutar" << endl;
	cout << "7-) Kayýtlý Projelerin Belirtilen Döneme Göre Tutarlarý" << endl;
	cout << "8-) AnaSayfa " << endl;
	cout << "9-) ÇIKIÞ " << endl;
	cout << "SEÇÝMÝNÝZ.....:";
	cin >> secim;


	// Hakkediþ Ekleme
	if (secim == 1)
	{
		HakkedisEkle();
		HakkedisIslemleri();
	}
	// Hakkediþe baðlý ürünleri listele
	else if (secim == 2)
	{
		UrunleriListele();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkediþe baðlý ürünleri silme
	else if (secim == 3)
	{
		UrunSil();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkediþe baðlý ürünleri güncelleme
	else if (secim == 4)
	{
		UrunGuncelle();
		system("pause");
		HakkedisIslemleri();
	}
	// Hakkediþe baðlý ürünleri arama
	else if (secim == 5)
	{
		UrunArama();
		system("pause");
		HakkedisIslemleri();
	}
	// ProjeNo ve Hakkediþ Dönemine Göre Toplam tutar
	else if (secim == 6)
	{
		ToplamTutar();
		system("pause");
		HakkedisIslemleri();
	}
	// Kayýtlý Projelerin Belirtilen Döneme Göre Tutarlarý
	else if (secim == 7)
	{
		DonemeGoreTutar();
		system("pause");
		HakkedisIslemleri();
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
		cout << "Yanlýþ Seçim Yaptýnýz"; system("cls"); system("pause"); HakkedisIslemleri();
	}

}