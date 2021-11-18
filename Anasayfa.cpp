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

#include "Anasayfa.h"
#include "Urun.h"
#include "Proje.h"
#include "Hakkedis.h"

void Anasayfa::calistir()
{
	system("cls");

	// ilgili s�n�flardan yeni nesneler olu�turuyoruz.
	Urun *urunIslemleri = new Urun;
	Proje *projeIslemleri = new Proje;
	Hakkedis *hakkedisIslemleri = new Hakkedis;

	int secim;
	cout << "1-) �r�n ��lemleri " << endl;
	cout << "2-) Proje ��lemleri " << endl;
	cout << "3-) Hekkedi� ��lemleri " << endl;
	cout << "9-) �IKI� " << endl;
	cout << "SE��M�N�Z.....:";
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

	default: cout << "Yanl�� Se�im Yapt�n�z"; system("pause"); system("cls"); calistir(); break;

	}
}