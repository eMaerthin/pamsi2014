#ifndef SCALANIE_HH
#define SCALANIE_HH

void scal_rosn(TYP * tablica, int poczatek, int srodek, int koniec) {
	TYP * temp = new TYP[(koniec+1)];
	for (int i = poczatek; i <= koniec; i++) temp[i] = tablica[i];  //skopiowanie danych do tymczasowej tablicy pomocniczej

	int p = poczatek;
	int s = srodek + 1;
	int k = poczatek;                 //ustawienie wskaŸników miejsc w tablicy do sortowania
	while (p <= srodek && s <= koniec) {         //przenoszenie danych z sortowaniem ze zbiorów pomocniczych tablicy tymczasowej do tablicy g³ównej
		if (temp[p]<temp[s]) tablica[k++] = temp[p++]; //w momencie gdy dane sa nieprawidlowo posortowane
		else tablica[k++] = temp[s++];
	}
	while (p <= srodek)	tablica[k++] = temp[p++]; //przeniesienie nie skopiowanych danych z tablicy pomocniczej, gdy skoñczono sprawdzanie jej elementów
	free(temp);		//zwolnienie pamieci, przydatne w przypadku duzych rozmiarow danych, np dla typu int powyzej 20 000
}					//(wystepuje przekroczenie limitu pamieci 2gb przydzielonej dla programu)

void sort_scalanie_rosn(TYP * tablica, int poczatek, int koniec) {
	if (poczatek<koniec) {
		int srodek = (poczatek + koniec) / 2;
		sort_scalanie_rosn(tablica, poczatek, srodek);    //dzielenie lewej czêœci
		sort_scalanie_rosn(tablica, srodek + 1, koniec);   //dzielenie prawej czêœci
		scal_rosn(tablica, poczatek, srodek, koniec);   //scalanie obu czêœci, lewej i prawej
	}
}

void scal_malej(TYP * tablica, int poczatek, int srodek, int koniec) {
	TYP * temp = new TYP[(koniec+1)];
	for (int i = poczatek; i <= koniec; i++) temp[i] = tablica[i];  //skopiowanie danych do tymczasowej tablicy pomocniczej

	int p = poczatek;
	int s = srodek + 1;
	int k = poczatek;                 //ustawienie wskaŸników miejsc w tablicy do sortowania
	while (p < srodek && s < koniec) {         //przenoszenie danych z sortowaniem ze zbiorów pomocniczych tablicy tymczasowej do tablicy g³ównej
		if (temp[p]>temp[s]) tablica[k++] = temp[p++];	//w momencie gdy dane sa nieprawidlowo posortowane
		else tablica[k++] = temp[s++];
	}
	while (p <= srodek)	tablica[k++] = temp[p++]; //przeniesienie nie skopiowanych danych z tablicy pomocniczej, gdy skoñczono sprawdzanie jej elementów
	free(temp);		//zwolnienie pamieci, przydatne w przypadku duzych rozmiarow danych, np dla typu int powyzej 20 000
}					//(wystepuje przekroczenie limitu pamieci 2gb przydzielonej dla programu)

void sort_scalanie_malej(TYP * tablica, int poczatek, int koniec) {
	if (poczatek<koniec) {
		int srodek = (poczatek + koniec) / 2;
		sort_scalanie_malej(tablica, poczatek, srodek);    //dzielenie lewej czêœci
		sort_scalanie_malej(tablica, srodek + 1, koniec);   //dzielenie prawej czêœci
		scal_malej(tablica, poczatek, srodek, koniec);  } //scalanie obu czêœci, lewej i prawej
}
#endif