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

#pragma once

#include<string>
using namespace std;

class Urun
{
public:
	int urunNo, birim, birimFiyat;
	string urunAdi, marka;
	int sonUrunNoGet();
	void UrunEkle();
	void UrunGuncelle();
	void UrunSil();
	void UrunListele();
	bool UrunBul(int bulunacakUrunNo);
	void UrunIslemleri();
	void UrunYazdir();
};

