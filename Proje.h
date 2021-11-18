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

