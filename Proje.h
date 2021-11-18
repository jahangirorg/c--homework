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
class Proje
{
public:
	int projeNo;
	string projeAdi, projeYurutucuFirma, projeSorumlusu, projeKontroloru;
	void ProjeIslemleri();
	int SonProjeNoGet();

	void ProjeEkle();
	void ProjeGuncelle();
	void ProjeSil();
	void ProjeListele();
	bool ProjeBul(int aranacakProjeNo);
	void ProjeYazdir();
};

