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

#include "Anasayfa.h"
#include "Urun.h"
#include "Proje.h"
#include "Hakkedis.h"

void Anasayfa::calistir()
{
	system("cls");

	// ilgili sýnýflardan yeni nesneler oluþturuyoruz.
	Urun *urunIslemleri = new Urun;
	Proje *projeIslemleri = new Proje;
	Hakkedis *hakkedisIslemleri = new Hakkedis;

	int secim;
	cout << "1-) Ürün Ýþlemleri " << endl;
	cout << "2-) Proje Ýþlemleri " << endl;
	cout << "3-) Hekkediþ Ýþlemleri " << endl;
	cout << "9-) ÇIKIÞ " << endl;
	cout << "SEÇÝMÝNÝZ.....:";
	cin >> secim;

	
	switch (secim)
	{
	case 1:
		urunIslemleri->UrunIslemleri();
		break;

	case 2:
		projeIslemleri->ProjeIslemleri();
		break;

	case 3:
		hakkedisIslemleri->HakkedisIslemleri();
		break;

	case 9:exit(0); break;

	default: cout << "Yanlýþ Seçim Yaptýnýz"; system("pause"); system("cls"); calistir(); break;

	}
}