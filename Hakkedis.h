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
#include <iostream>
#include<fstream> //Dosyalama i�lemleri i�in kullan�ld�.
#include<string>
#include <sstream> //String t�r�ndeki de�i�keni int'e �evirmek i�in kullan�ld�.
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

