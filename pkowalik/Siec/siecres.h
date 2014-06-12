#include<iostream>
#include<vector>
#include<map>
#include<limits>
#include<algorithm>
#include"elem.h"
#include"siec.h"
using namespace std;

template<class typ>
class siecres: public siec<typ>{
//	typ** _tabres;
public:
	siecres();
	siecres(const siecres<typ> & S);
	siecres<typ> & operator=(const siec<typ> & S);
	void update1(unsigned int i, unsigned int j, typ przeplyw);
	void dixtosciezka(vector<unsigned int> dix, typ & przeplyw);
	void update(vector<unsigned int> sciezka, typ przeplyw);
	bool znajdzSciezke(typ & przeplyw);
	typ siecres<typ>::maxPrzeplyw();
	void wypisz();
};

template<class typ>
siecres<typ>::siecres(){
	siec();
}

template<class typ>
siecres<typ>::siecres(const siecres<typ> & S){
	_v=S._v;
	_e=S._e;
	_s=S._s;
	_u=S._u;
	delete _tab;
	_tab=new typ*[_v];
	for(i=0; i<_v; i++){
		_tab[i]=new typ[_v];
		for(j=0; j<_v; j++){
			_tab[i][j]=S._tab[i][j];
		}
	}
}

/*
template<class typ>
siecres<typ>::siecres(const siecres<typ>& S){
	_v=S._v;
	_e=S._e;
	_s=S._s;
	_u=S._u;
	delete _tab;
	delete _tabres;
	_tab=new typ*[_v];
	_tabres=new typ*[_v];
	for(i=0; i<_v; i++){
		_tab[i]=new typ[_v];
		_tabres[i]=new typ[_v];
		for(j=0; j<_v; j++){
			_tab[i][j]=S._tab[i][j];
			_tabres[i][j]=S._tabres[i][j];
		}
	}
}
*/
template<class typ>
siecres<typ> & siecres<typ>::operator=(const siec<typ> & S){
	unsigned int i, j;
	_v=S.v();
	_e=S.e();
	_s=S.s();
	_u=S.u();
	delete _tab;
	_tab=new typ*[_v];
	for(i=0; i<_v; i++){
		_tab[i]=new typ[_v];
		for(j=0; j<_v; j++){
			_tab[i][j]=-1;
		}
	}
	for(i=0; i<_v; i++){
		for(j=0; j<_v; j++){
			if(S.tab(i, j)>0){			//jezeli element != -1 to przypisujemy mu wartosc polaczenia a w polaczeniu odwrotnym wstawiamy 0
				_tab[i][j]=S.tab(i, j);
				_tab[j][i]=0;
			}
		}
	}
	return *this;
}

/*
template<class typ>
siecres<typ> & siecres<typ>::operator=(const siec<typ> & S){
	unsigned int i, j;
	_v=S._v;
	_e=S._e;
	_s=S._s;
	_u=S._u;
	delete _tab;
	delete _tabres;
	_tab=new typ*[_v];
	_tabres=new typ*[_v];
	for(i=0; i<_v; i++){
		_tab[i]=new typ[_v];
		_tabres[i]=new typ[_v];
	}
	for(i=0; i<_v; i++){
		for(j=0; j<_v; j++){
			_tab[i][j]=S._tab[i][j];
			_tab[j][i]=S._tab[i][j];
			if(S._tab[i][j]!=-1){			//jezeli element != -1 to przypisujemy mu wartosc polaczenia a w polaczeniu odwrotnym wstawiamy 0
				_tabres[i][j]=S._tab[i][j];
				_tabres[j][i]=0;
			} else{							//w przeciwnym wypadku poprostu przepisujemy -1
				_tabres[i][j]=-1;
			}
		}
	}
	return *this;
}
*/

template<class typ>
void siecres<typ>::update(vector<unsigned int> sciezka, typ przeplyw){
	for(unsigned int i=0; i<sciezka.size()-1; i++){																			//jako ze z mapy latwiej czytac sciezke w odwrotnej kolejnosci
		_tab[sciezka[i+1]][sciezka[i]]-=przeplyw;
		_tab[sciezka[i]][sciezka[i+1]]+=przeplyw/*_tab[sciezka[i]][sciezka[i+1]]-_tabres[sciezka[i]][sciezka[i+1]]*/;
	}
}

template<class typ>
void siecres<typ>::update1(unsigned int i, unsigned int j, typ przeplyw){
	_tab[i][j]-=przeplyw;
	_tab[j][i]+=przeplyw;
}

template<class typ>
void siecres<typ>::dixtosciezka(vector<unsigned int> dix, typ & przeplyw){
	unsigned int poprzednik=_u;
//	vector<unsigned int> rec;
	while(dix[poprzednik]!=numeric_limits<unsigned int>::max()){						//do czasu napotkania fail wierzcholka wyt³umaczone w znajdzSciezke()
//		rec.push_back(poprzednik);												//rec zbiera wierzcholki w porzadku terminal->Ÿrodlo
		update1(dix[poprzednik], poprzednik, przeplyw);
		poprzednik=dix[poprzednik];										//nowy poprzednik
	}
}

template<class typ>
bool siecres<typ>::znajdzSciezke(typ & przeplyw){
	vector<typ> max;
	vector<unsigned int> vt, poprzednik;
	elem<typ> El;
	typ zamiana;

	max.clear();
	poprzednik.clear();
	for(unsigned int i=0; i<_v; i++){
		max.push_back(0);	//uzupelnienie mapy na starcie gdzie get(nie ma wczesniejszego, wszystko bedzie wieksze od tego)
		poprzednik.push_back(numeric_limits<unsigned int>::max());
	}

	max[_s]=numeric_limits<typ>::max();  //przypisanie na mape wierzcholka startowego. gdzie w get(nie ma wczesniejszego, wszystko bedzie mniejsze od tego)
	vt.clear();
	vt.push_back(_s);

	/*
	*	dziala az nie skonczy sie wektor vt co bêdzie oznacza³o ¿e nie ma sciezki od ¿ród³a do terminala. wektor vt wci¹z jest powiêkszany o kolejne wierzcholki do których
	*	jest mozliwosc dotarcia od zród³a. wierzcholki nie sa dodawane je¿eli istnieje polaczenie  o wadze 0
	*/
	for(unsigned int i=0; i<vt.size(); i++){
		if(vt[i]==_u){							//je¿eli napotkany zostanie terminal konczymy szukanie
			przeplyw=max[_u];				//maksymalny przeplyw jest max() elementu pod indeksem terminala na mapie
			dixtosciezka(poprzednik, przeplyw);					//scie¿ka jest wyznaczana w drug¹ strone czyli od terminala az do zrodla
			return true;
		}
		for(unsigned int j=0; j<_v; j++){
			if(_tab[vt[i]][j]>0){									//warunek zakazuje brania pod uwage polaczenia o wadze 0 oraz calkowitego brku polaczenia czyli -1
				zamiana=min(_tab[vt[i]][j], max[vt[i]]);		//zamiana pobiera najmniejszy z pary wag: min(waga nowego polaczenia, waga maksymalnego przeplywu uzyskanego do tej pory)
				if(zamiana>max[j]){							//dziêki temu warunkowi na mape dodawane si¹ tylko wiêksze przeplywy jak równiez apobiega cyklom na wektorze odnalezionych wierzcholkow vt
					max[j]=zamiana;					//jezeli powyzszy warunek jest spelniony pod indeksem wierzcholka zapisujemy nowy element
					poprzednik[j]=vt[i];
					vt.push_back(j);								//dodajemy nowy odnaleziony wierzcholek

				}
			}
		}
	}
	return false;													//nie ma juz mozliwej sciezki
}

template<class typ>
typ siecres<typ>::maxPrzeplyw(){
	typ max=0;
//	vector<unsigned int> sciezka;
	typ przeplyw;

	while(znajdzSciezke(przeplyw)){						//dodaje maksymalne rzeplywy do czasu az funkcja znajdzSciezke() nie da znaku ze nie ma ju¿ wiêcej mozliwych œciezek miedzy Ÿród³em a terminalem
//		update(sciezka, przeplyw);									//powoduje zmniejszenie wagi polaczen z odszukanej sciezki o wartosc przeplywu jak i zwieksza wagi o przeplyw na polaczeniach odwrotnych
		max+=przeplyw;												//sumuje maksymalne przeplywy z kolejnych sciezek. Ostatecznie po wykonaniu wszystkich okra¿eñ zawiera maksymalny przeplyw sieci
	}
	return max;
}

template<class typ>
void siecres<typ>::wypisz(){
	for(unsigned int j=0; j<_v; j++){
		for(unsigned int i=0; i<_v; i++){
			cout<<_tab[i][j]<<" ";
		}
		cout<<endl;
	}
}