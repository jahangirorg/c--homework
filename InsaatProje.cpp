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

#include<locale.h>
#include "Anasayfa.h"


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Turkish");
	Anasayfa *anasayfa = new Anasayfa;
	anasayfa->calistir();
}
