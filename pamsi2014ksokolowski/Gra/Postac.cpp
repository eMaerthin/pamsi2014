#include "Postac.h"

using namespace std;

PoleGry mapa;

Postac::Postac(const string& nazwa, const Wspolrzedne& glowa, unsigned int dlugosc_ogona, Kierunki ktory, GLfloat czer, GLfloat ziel, GLfloat nieb, bool czyBot, const Postac *adr) 
: nazwa_postaci(nazwa), akt_kierunek(ktory), czerwony(czer), zielony(ziel), niebieski(nieb), przedluz(0), kolizja(false), _bot(czyBot), przeciwnik(adr), po_skrecie(false)
{
	ogon.push_back(glowa);
	
	for (int i = 1; i <= (int)dlugosc_ogona; ++i){
		ogon.push_back(Wspolrzedne(glowa.X, glowa.Y + akt_kierunek*i));
		mapa.zmienWsp(glowa.X, glowa.Y + akt_kierunek*i, 1);
	}
}
/////////////////////////////////////////////////////////////////////////////
void Postac::wykonaj_ruch()
{
	if (_bot){
		Kierunki kier = wKtoraRuch();
		kolizja = sprKolizje(kier);

		if (kolizja && czyWolnyJakisRuch()){ //Gdy podejzewana jest kolizja upewniamy sie czy aby napewno
			kolizja = false;
			kier = podajWolnyKierunek();
		}
		else if (kolizja) {//Gdy nie da sie uniknac kolizji
			cout << "KOLIZJA" << endl;
			return;
		}
		if (kier + akt_kierunek == 0)
			kier = podajWolnyKierunek();

		przesun_cialo(kier);
		akt_kierunek = kier;
	}
	else
		przesun_cialo(akt_kierunek);
}
/////////////////////////////////////////////////////////////////////////////
void Postac::skrec_w(Kierunki kierunek)
{
	if (kierunek + akt_kierunek == 0 || kierunek == akt_kierunek || po_skrecie) {
		po_skrecie = false;
		return; //zabezpieczenie przed skretem w przeciwna strone (w siebie)
	}

	przesun_cialo(kierunek);
	po_skrecie = true;

	akt_kierunek = kierunek;
}
/////////////////////////////////////////////////////////////////////////////
void Postac::wyswietlPostac() const
{
	GLfloat XX, YY, wymiar = jeden_piksel*5;
	size_t rozmiar = ogon.size();

	for (size_t i = 0; i < rozmiar; ++i){
		//Glowe kolorujemy na troche ciemniejszy kolor
		if (i <= 1) glColor3f(czerwony/2, zielony/2, niebieski/2);
		else glColor3f(czerwony, zielony, niebieski);

		//Tworzenie kolejnego segmentu ogona (kwadratu)
		glBegin(GL_POLYGON);

		XX = (ogon[i].X * wymiar)*2;
		YY = (ogon[i].Y * wymiar)*2;
		glVertex3f(-wymiar + XX, wymiar + YY, 0.0);
		glVertex3f(wymiar + XX, wymiar + YY, 0.0);
		glVertex3f(wymiar + XX, -wymiar + YY, 0.0);
		glVertex3f(-wymiar + XX, -wymiar + YY, 0.0);

		glEnd();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Postac::przesun_cialo(Kierunki kierunek)
{
	//sprawdzenie czy zostal wykonany przed chwila skret
	if (po_skrecie){
		po_skrecie = false;
		return;
	}

	//skret glowy
	if (przedluz == 0){
		mapa.zmienWsp(ogon.back(), 0);
		ogon.pop_back(); //usuwamy ostatnij element ogona ("wskoczy" zmieniony za glowe)
	}
	else 
		--przedluz;

	Wspolrzedne do_skretu = ogon[0], do_kolizji;

	switch (kierunek){
	case GORA: 
		do_skretu.zmien_Y();
		do_kolizji = do_skretu + Wspolrzedne(0, 1);
		break;

	case DOL:
		do_skretu.zmien_Y(-1);
		do_kolizji = do_skretu + Wspolrzedne(0, -1);
		break;

	case PRAWO:
		do_skretu.zmien_X();
		do_kolizji = do_skretu + Wspolrzedne(1, 0);
		break;

	case LEWO:
		do_skretu.zmien_X(-1);
		do_kolizji = do_skretu + Wspolrzedne(-1, 0);
		break;
	}

	kolizja = sprKolizje(do_skretu);

	mapa.zmienWsp(do_skretu, 1);
	ogon.insert(ogon.begin(), do_skretu);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Postac::wydluz_ogon(int o_ile)
{
	przedluz = o_ile;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Postac::sprKolizje(const Wspolrzedne& kords) const
{
	return !(find(ogon.begin() + 2, ogon.end(), kords) == ogon.end() &&
		find(przeciwnik->ogon.begin(), przeciwnik->ogon.end(), kords) == przeciwnik->ogon.end() &&
		kords.X < 40 && kords.X > -40 && kords.Y < 40 && kords.Y > -40);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Postac::sprKolizje(Kierunki kierunek) const
{
	switch (kierunek){
	case GORA:
		return sprKolizje(ogon[0] + Wspolrzedne(0, 1));

	case DOL:
		return sprKolizje(ogon[0] + Wspolrzedne(0, -1));

	case PRAWO:
		return sprKolizje(ogon[0] + Wspolrzedne(1, 0));

	case LEWO:
		return sprKolizje(ogon[0] + Wspolrzedne(-1, 0));

	default:
		return true;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Kierunki Postac::wKtoraRuch() const
{
	/////////////////////////////////////////////////////////////////////////
	//plansza bedzie skladala sie z 20x20 duzych kafelkow, kazdy z tych kafelkow sklada sie z mniejszych (20x20) po 5 pikseli
	Graf<int> plansza;

	//Uzupelnienie planszy o aktualna sytuacjie na mapie
	for (int i = 0; i < _rozm; ++i){
		for (int j = 0; j < _rozm; ++j){
			if (i > 0){
				plansza.dodaj_polaczenie(i*_rozm + j, (i - 1)*_rozm + j, mapa.wagaPolaczenia(i*_rozm + j, (i - 1)*_rozm + j));
			}
			if (i < _rozm - 1) {
				plansza.dodaj_polaczenie(i*_rozm + j, (i + 1)*_rozm + j, mapa.wagaPolaczenia(i*_rozm + j, (i + 1)*_rozm + j));
			}

			if (j > 0){
				plansza.dodaj_polaczenie(i*_rozm + j, i*_rozm + j - 1, mapa.wagaPolaczenia(i*_rozm + j, i*_rozm + j - 1));
			}
			if (j < _rozm - 1){
				plansza.dodaj_polaczenie(i*_rozm + j, i*_rozm + j + 1, mapa.wagaPolaczenia(i*_rozm + j, i*_rozm + j + 1));
			}
		}
	}

	int kafelek_pocz = (ogon[0].X + 39) / 4 * _rozm + (ogon[0].Y + 39) / 4, 
		kafelek_kon = (przeciwnik->ogon[0].X + 39) / 4 * _rozm + (przeciwnik->ogon[0].Y + 39) / 4;
	Kierunki znaleziony;

	if (kafelek_pocz != kafelek_kon){ //gdy weze sa w roznych kafelkach
		plansza.alg_Dijkstry(kafelek_pocz, kafelek_kon);
		znaleziony = wybierzKierunek(kafelek_pocz, plansza.podajWektorDrogi(kafelek_kon).at(1)); //pobieramy kolejny kafelek do ktorego nalezy przejsc

	}
	else{ //gdy sa w tych samych kafelkach
		boost::this_thread::sleep(boost::posix_time::milliseconds(100)); //spowalniamy, gdyz nie ma spowolnienia spowodowanego algorymem Dijkstry
		znaleziony = wybierzKierunek(kafelek_pocz);
	}

	if (sprKolizje(znaleziony)){
		znaleziony = wolnyKierunek(znaleziony);
	}

	return znaleziony;
}
/////////////////////////////////////////////////////////////////////////
Kierunki Postac::wybierzKierunek(int z_kafelek, int do_kafelek) const
{
	static Kierunki glowny_kierunek;
	z_kafelek = 400 - z_kafelek;
	do_kafelek = 400 - do_kafelek;
	switch (z_kafelek - do_kafelek){

	case _rozm: 
		glowny_kierunek = PRAWO;
		break;

	case -_rozm:
		glowny_kierunek = LEWO;
		break;

	case 1:
		glowny_kierunek = GORA;
		break;

	case -1:
		glowny_kierunek = DOL;

		break;
	}

	if (sprKolizje(glowny_kierunek))
		return wolnyKierunek(glowny_kierunek);

	cout << "Glowny: " << glowny_kierunek << endl;
	return glowny_kierunek;
}
/////////////////////////////////////////////////////////////////////////
Kierunki Postac::wybierzKierunek(int nr_kafelka) const
{
	Kafelek kaf = mapa.podajKafelek(nr_kafelka);
	Kierunki kier = przeciwnik->akt_kierunek;

	//spr czy juz poruszamy sie w tym samym kierunku. Jak tak to mozemy probuwac zablokowac przeciwnika
	if (akt_kierunek == kier){
		if (kier == GORA || kier == DOL){
			if (this->ogon[0].Y*kier < przeciwnik->ogon[0].Y*kier){ // jezeli wyprzedzamy przeciwnika mozemy sprobowac go zablokowac. Mnozenie razy -1 (akt_kierunek) pozwala zmienic nam znak nierownosci na <
				if (this->ogon[0].X > przeciwnik->ogon[0].X && !sprKolizje(LEWO))
					return LEWO;
				else if (!sprKolizje(PRAWO))
					return PRAWO;
			}
		}
		else{
			if (this->ogon[0].X*kier / 3 < przeciwnik->ogon[0].X*kier / 3){ // jezeli wyprzedzamy przeciwnika mozemy sprobowac go zablokowac. Dzielimy pierwszy fragment przez dwa poniewaz LEWO i PRAWO dziela sie przez 2 dajac 1 lub -1
				if (this->ogon[0].Y > przeciwnik->ogon[0].Y && !sprKolizje(DOL))
					return DOL;
				else if (!sprKolizje(GORA))
					return GORA;
			}
		}

		return akt_kierunek;
	}
	if (!sprKolizje(kier)){ //gdy nie ma kolizji poruszajac sie w tym samym kierunku co przeciwnik...
		return kier; //jezeli nie wyprzedzamy z zadnej strony to podazamy w tym samym kierunku
	}

	//tutaj dojdziemy jezeli nie mozemy sie poruszyc w tym samym kierunku co przeciwnik
	//sprawdzamy z ktorej strony mozna obejsc
	if (kier == GORA || kier == DOL){
		return (!sprKolizje(PRAWO) && !sprKolizje(Wspolrzedne(ogon[0].X + 1, ogon[0].Y + kier))) ? PRAWO : LEWO;
	}
	else{ //lewo i prawo
		return (!sprKolizje(GORA) && !sprKolizje(Wspolrzedne(ogon[0].X + kier/3, ogon[0].Y + 1))) ? GORA : DOL;
	}

}
/////////////////////////////////////////////////////////////////////////
Kierunki Postac::wolnyKierunek(Kierunki glowny) const
{
	if (glowny == GORA || glowny == DOL){
		if (abs(przeciwnik->ogon[0].X - this->ogon[0].X - 1) < abs(przeciwnik->ogon[0].X - this->ogon[0].X + 1) && !sprKolizje(LEWO)){
			return LEWO;
		}
		else{
			if (!sprKolizje(LEWO))
				return LEWO;
			if (!sprKolizje(PRAWO))
				return PRAWO;
			if (!sprKolizje(glowny*(-1)))
				return (Kierunki)((-1)*glowny);
		}
	}
	else{ //dla kierunkow lewo i prawo
		if (abs(przeciwnik->ogon[0].Y - this->ogon[0].Y - 1) < abs(przeciwnik->ogon[0].Y - this->ogon[0].Y + 1) && !sprKolizje(DOL)){
			return DOL;
		}
		else{
			if (!sprKolizje(DOL))
				return DOL;
			if (!sprKolizje(GORA))
				return GORA;
			if (!sprKolizje(glowny*(-1)))
				return (Kierunki)((-1)*glowny);
		}
	}
	return glowny;
}