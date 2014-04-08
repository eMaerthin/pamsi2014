#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Kopiec
{
public:
	vector<int> * v;
	
	void wypelnijLosowo(int ile)
	{
		v = new vector<int>();
		srand((unsigned)time(NULL));
		for (int i = 0; i < ile; i++)
		{
			v->push_back(rand()%100);
		}
	}
	
	void przywrocKopiec()
	{	
		if(v!=NULL)
		{
			make_heap(v->begin(), v->end());
		}
	}
	
	void usunKorzen()
	{	
		if(v!=NULL)
		{
			pop_heap(v->begin(), v->end());  //pierwszy na ostatni i usuwa
			v->pop_back();
		}
	}
	
	void wyswietl(string sp, string sn, int vk)
	{
		string cr,cl,cp;
		cr = cl = cp = "  ";
		cr[0] = 218; cr[1] = 196;	//znaki do rysowania w prawo
		cl[0] = 192; cl[1] = 196;	//znaki do rysowania w lewo
		cp[0] = 179;				//znak '|'
		string s;
		
		
		//wywolania rekurencyjne odpowiednio rozbudowuja string do czytelnego wyswietlania
		if(v!=NULL) 
		{
		
			if(vk < v->size())
			{
				s = sp;
		   		if(sn == cr) s[s.length() - 2] = ' ';
		   		wyswietl(s + cp, cr, 2 * vk + 2);	//wywolanie rekurencyjne funkcji dla prawego wezla kopca
		
		    	s = s.substr(0,sp.length()-2);
		
		    	cout << s << sn << v->at(vk) << endl;	//wyswietlenie wartosci wezla
		
		    	s = sp;
		    	if(sn == cl) s[s.length() - 2] = ' ';
		    	wyswietl(s + cp, cl, 2 * vk + 1);	//wywolanie rekurencyjne funkcji dla lewego wezla kopca
			}
		}
		
	}
};

int main()
{
	Kopiec * k = new Kopiec();
	int opcja;
	do
	{
		cout << "Menu" << endl;
		cout << "1. Stworz tablice losowych liczb" << endl;
		cout << "2. Wyswietl kopiec" << endl;
		cout << "3. Przywroc wlasnosci kopca" << endl;
		cout << "4. Usun korzen z kopca" << endl;
		cout << "0. Wyjdz" << endl;
		cout << " "<< endl;
		cout << "Wybierz co chcesz zrobic" << endl;
		cout << " " << endl;
		cin >> opcja;
	
		switch (opcja)
		{
			case 1:
			{
				cout<<"Podaj ile liczb ma zawierac tablica: ";
				int ile;
				cin >> ile;
				k->wypelnijLosowo(ile);
				break;
			}
		
			case 2:
				k->wyswietl("","",0);
				break;
		
			case 3:
				k->przywrocKopiec();
				break;
			case 4:
				k->usunKorzen();
				break;
		}
	} while(opcja != 0);
	
	return 0;
}
