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
#include <iostream>
#include<fstream> //Dosyalama iþlemleri için kullanýldý.
#include<string>
#include <sstream> //String türündeki deðiþkeni int'e çevirmek için kullanýldý.
#include <stdio.h>
#include <iomanip>
using namespace std;

class Hakkedis
{
public:
	int hakedisDonemi, projeNo, urunNo, urunAdet, fiyat;
	int kullanilacakProjeNo;
	void HakkedisIslemleri();
	void HakkedisEkle();
	void UrunleriListele();
	void UrunSil();
	void UrunGuncelle();
	void UrunArama();
	void HakkedisListele();
	void ToplamTutar();
	void DonemeGoreTutar();
	bool ProjeVarmi(int aranacakProjeNo);


};

