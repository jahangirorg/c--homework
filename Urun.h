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

