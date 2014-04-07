#include "funkcje.h"

using namespace std;

char wpisz_ele_menu()
{
	cout << "\nWypelnic tablice liczbami losowymi czy z pliku?" << endl
		<< "1. Liczby losowe" << endl
		<< "2. Z pliku" << endl
		<< "3. Wyjscie" << endl;

	char wybor;
	do{
		wybor = _getch();
	} while (wybor < '1' || wybor > '3');

	return wybor;
}
///////////////////////////////////////////////////////////
void menu_sortowania()
{
	char wybor;
	int liczba_elementow;

	cout << "\n\nIle elementow ma byc wylosowanych i posortowanych?\t";
	cin >> liczba_elementow;

	Tablica<int> tab;
	tab.wlosuj_elementy(liczba_elementow);

	cout << "Wybierz, ktory typ sortowania chcesz wykonac?" << endl
		<< "1. Sortowanie przez KOPCOWANIE." << endl
		<< "2. Sortowanie przez SCALANIE." << endl
		<< "3. Sortowanie metoda SHELLA." << endl
		<< "4. Wyjscie z programu." << endl
		<< "Twoj wybor:";

	do{
		wybor = _getch();
	} while (wybor < '1' || wybor > '4');

	cout << endl << "Tablica przed sorotwaniem:" << endl;
	tab.wyswietl_tab();

	switch (wybor){
		case '1': { tab.posortuj_przez_kopcowanie();
			break; }

		case '2': { tab.posortuj_przez_scalanie(); 
			break; }

		case '3': { tab.posortuj_Shella();
			break; }

		case '4': exit(0);
	}
	cout << endl << "Tablica po sortowaniu:" << endl;
	tab.wyswietl_tab();

	cout << "\nCzas sorotwania wyniosl:\t" << tab.czas_sort() << endl;
}
///////////////////////////////////////////////////////////
void eksperyment()
{
	const int ile_tablic = 100;
	int ile_elementow, wstepnie_posort;
	Tablica<int> wek_tablic[ile_tablic];
	//vector<Tablica<int> > wek_tablic(ile_tablic);
	
	cout << "\nDla ilu elementow tablicy wykonac test efektywnosci?\t ";
	cin >> ile_elementow;
	cout << "\nIle procent elementow ma byc wstepnie posortowanych?\t";
	cin >> wstepnie_posort;

	if (wstepnie_posort > 100 || wstepnie_posort < 0){
		cout << "Procent nie moze byc wiekszy od 100!" << endl;
		return;
	}

	//Wlosowanie liczb z rozkladu jednostajnego****************************************
	cout << "\n\nSortowanie tablic z elementami z rozkladu jednostajnego." << endl
		<< "Procent wstepnie posortowanych elementow: " << wstepnie_posort << endl;
	for (int i = 0; i < ile_tablic; ++i){
		wek_tablic[i].wlosuj_rozkladem_jednostajnym(ile_elementow);
		wek_tablic[i].posortuj_wstepnie(wstepnie_posort);
	}

	//Test efektywnosci sortowania przez kopcowanie
	cout << "\n*****Sredni czas kopcowania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_kopcowania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania przez scalanie
	cout << "\n*****Sredni czas scalania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_scalania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania metoda Shella
	cout << "\n*****Sredni czas shella " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_Shella(wek_tablic, ile_tablic) << "ms" << endl;

	//Wlosowanie liczb z rozkladu normalnego********************************************
	cout << "\n\nSortowanie tablic z elementami z rozkladu normalnego." << endl
		<< "Procent wstepnie posortowanych elementow: " << wstepnie_posort << endl;
	for (int i = 0; i < ile_tablic; ++i){
		wek_tablic[i].wlosuj_rozkladem_jednostajnym(ile_elementow);
		wek_tablic[i].posortuj_wstepnie(wstepnie_posort);
	}

	//Test efektywnosci sortowania przez kopcowanie
	cout << "\n*****Sredni czas kopcowania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_kopcowania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania przez scalanie
	cout << "\n*****Sredni czas scalania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_scalania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania metoda Shella
	cout << "\n*****Sredni czas shella " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_Shella(wek_tablic, ile_tablic) << "ms" << endl;

	//Wlosowanie liczb z rozkladu Poissona********************************************
	cout << "\n\nSortowanie tablic z elementami z rozkladu Poissona." << endl
		<< "Procent wstepnie posortowanych elementow: " << wstepnie_posort << endl;
	for (int i = 0; i < ile_tablic; ++i){
		wek_tablic[i].wlosuj_rozkladem_jednostajnym(ile_elementow);
		wek_tablic[i].posortuj_wstepnie(wstepnie_posort);
	}

	//Test efektywnosci sortowania przez kopcowanie
	cout << "\n*****Sredni czas kopcowania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_kopcowania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania przez scalanie
	cout << "\n*****Sredni czas scalania " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_scalania(wek_tablic, ile_tablic) << "ms" << endl;
	//Test efektywnosci sortowania metoda Shella
	cout << "\n*****Sredni czas shella " << ile_tablic << " tablic " << ile_elementow << " elementowych: "
		<< test_efektywnosci_Shella(wek_tablic, ile_tablic) << "ms" << endl;
}
///////////////////////////////////////////////////////////
double test_efektywnosci_kopcowania(Tablica<int> wek[], int ile_ele)
{
	double suma = 0;
	Tablica<int> schowek;

	for (int i = 0; i < ile_ele; ++i){
		schowek = wek[i];
		schowek.posortuj_przez_kopcowanie();
		suma += schowek.czas_sort();
		if (i % 10 == 0) cout << " k-" << i;
	}cout << endl;

	return suma / ile_ele;
}
///////////////////////////////////////////////////////////
double test_efektywnosci_scalania(Tablica<int> wek[], int ile_ele)
{
	double suma = 0;
	Tablica<int> schowek;

	for (int i = 0; i < ile_ele; ++i){
		schowek = wek[i];
		schowek.posortuj_przez_scalanie();
		suma += schowek.czas_sort();
		if (i % 10 == 0) cout << " sc-" << i;
	}cout << endl;

	return suma / ile_ele;
}
///////////////////////////////////////////////////////////
double test_efektywnosci_Shella(Tablica<int> wek[], int ile_ele)
{
	double suma = 0;
	Tablica<int> schowek;

	for (int i = 0; i < ile_ele; ++i){
		schowek = wek[i];
		schowek.posortuj_Shella();
		suma += schowek.czas_sort();
		if (i % 10 == 0) cout << " sh-" << i;
	}cout << endl;

	return suma / ile_ele;
}